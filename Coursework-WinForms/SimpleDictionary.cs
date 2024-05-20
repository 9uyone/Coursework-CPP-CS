using System;
using System.Collections;
using System.Collections.Generic;

namespace Coursework_WinForms {
	// container
	public class SimpleDictionary<TKey, TValue> : IDictionary<TKey, TValue> {
		private List<KeyValuePair<TKey, TValue>> items;

		public SimpleDictionary() {
			items = new List<KeyValuePair<TKey, TValue>>();
		}

		public bool ContainsKey(TKey key) {
			return items.Exists(pair => pair.Key.Equals(key));
		}

		public void Add(TKey key, TValue value) {
			if (ContainsKey(key))
				throw new ArgumentException("An element with the same key already exists in the dictionary.");

			items.Add(new KeyValuePair<TKey, TValue>(key, value));
		}

		public bool Remove(TKey key) {
			int index = items.FindIndex(pair => pair.Key.Equals(key));
			if (index >= 0) {
				items.RemoveAt(index);
				return true;
			}
			return false;
		}

		public bool TryGetValue(TKey key, out TValue value) {
			foreach (var pair in items) {
				if (pair.Key.Equals(key)) {
					value = pair.Value;
					return true;
				}
			}
			value = default(TValue);
			return false;
		}

		public TValue this[TKey key] {
			get {
				foreach (var pair in items) {
					if (pair.Key.Equals(key))
						return pair.Value;
				}
				throw new KeyNotFoundException("The given key was not present in the dictionary.");
			}
			set {
				for (int i = 0; i < items.Count; i++) {
					if (items[i].Key.Equals(key)) {
						items[i] = new KeyValuePair<TKey, TValue>(key, value);
						return;
					}
				}
				throw new KeyNotFoundException("The given key was not present in the dictionary.");
			}
		}

		public ICollection<TKey> Keys {
			get {
				List<TKey> keys = new List<TKey>();
				foreach (var pair in items) {
					keys.Add(pair.Key);
				}
				return keys;
			}
		}

		public ICollection<TValue> Values {
			get {
				List<TValue> values = new List<TValue>();
				foreach (var pair in items) {
					values.Add(pair.Value);
				}
				return values;
			}
		}

		public void Add(KeyValuePair<TKey, TValue> item) {
			Add(item.Key, item.Value);
		}

		public void Clear() {
			items.Clear();
		}

		public bool Contains(KeyValuePair<TKey, TValue> item) {
			return items.Contains(item);
		}

		public void CopyTo(KeyValuePair<TKey, TValue>[] array, int arrayIndex) {
			items.CopyTo(array, arrayIndex);
		}

		public int Count {
			get => items.Count;
		}
		public bool IsReadOnly {
			get => false;
		}

		public bool Remove(KeyValuePair<TKey, TValue> item) {
			return items.Remove(item);
		}

		public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator() {
			//return items.GetEnumerator();		// using List Enumerator

			return new SimpleDictionaryEnumerator<TKey, TValue>(items);	// using our class of enumerator

			//foreach (var item in items)		// using foreach and yield return
				//yield return item;
		}
		IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
	}

	// enumerator
	public class SimpleDictionaryEnumerator<TKey, TValue> : IEnumerator<KeyValuePair<TKey, TValue>> {
		List<KeyValuePair<TKey, TValue>> items;
		int cur_idx = -1;

		public SimpleDictionaryEnumerator(List<KeyValuePair<TKey, TValue>> items) {
			this.items = items;
			this.cur_idx = -1;
		}

		public KeyValuePair<TKey, TValue> Current => items[cur_idx];
		object IEnumerator.Current => Current;

		public void Dispose() {}

		public bool MoveNext() {
			return ++cur_idx < items.Count;
		}

		public void Reset() {
			cur_idx = -1;
		}
	}
}