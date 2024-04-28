#pragma once
#include <algorithm>
#include <stdexcept>
#include <initializer_list>

constexpr const float SV_CAP_INCR_COEF = 1.65;

#pragma region header
template<typename T>
class simpleVector {
	T* arr_{};
	size_t size_;
	size_t capacity_;

public: //ctors and dtor
	using value_type = T;

	simpleVector(size_t initCapacity = 10);
	simpleVector(std::initializer_list<T> ilist);
	simpleVector(simpleVector<T>& other);
	simpleVector<T>& operator=(simpleVector<T>& other);

	~simpleVector() { delete[] arr_; }

private: // iterator
	template<typename Val_type>
	class base_iterator;

public:
	using iterator = base_iterator<T>;
	iterator begin() const { return iterator(arr_); }
	iterator end() const { return iterator(arr_ + size_); }

	using const_iterator = base_iterator<const T>;
	const_iterator cbegin() const { return const_iterator(arr_); }
	const_iterator cend() const { return const_iterator(arr_ + size_); }

public: // capacity
	size_t size() const { return size_; }
	size_t capacity() const { return capacity_; }
	void reserve(size_t newCapacity);
	bool empty() const { return size_ == 0; }

public: // modifiers
	void push_back(const T& val);
	void pop_back();
	void insert(iterator pos, const T& value);
	void append(iterator first, iterator last);
	void erase(iterator it);
	void erase(iterator first, iterator last);
	void clear();
	void resize(size_t newsize);

public: // element access
	T& operator[](size_t index);
	T& front();
	T& back();

};
#pragma endregion


// ctors
template<typename T>
inline simpleVector<T>::simpleVector(size_t initCapacity) : capacity_(initCapacity), size_(0) {
	arr_ = new T[capacity_]{};
}

template<typename T>
inline simpleVector<T>::simpleVector(std::initializer_list<T> ilist) : capacity_(ilist.size()* SV_CAP_INCR_COEF), size_(ilist.size()) {
	arr_ = new T[capacity_]{};
	std::copy(ilist.begin(), ilist.end(), arr_);
}

template<typename T>
inline simpleVector<T>::simpleVector(simpleVector<T>& other) {
	clear();
	reserve(other.capacity() * SV_CAP_INCR_COEF);
	std::copy(other.begin(), other.end(), std::back_inserter(*this));
}

template<typename T>
inline simpleVector<T>& simpleVector<T>::operator=(simpleVector<T>& other) {
	clear();
	reserve(other.capacity() * SV_CAP_INCR_COEF);
	std::copy(other.begin(), other.end(), std::back_inserter(*this));
	return *this;
}


// capacity
template<typename T>
inline void simpleVector<T>::reserve(size_t newCapacity) {
	if (newCapacity <= capacity_)
		return;

	capacity_ = newCapacity;
	T* newArr = new T[capacity_]{};
	std::copy(arr_, arr_ + size_, newArr);
	delete[] arr_;
	arr_ = newArr;
}

// modifiers
template<typename T>
inline void simpleVector<T>::push_back(const T& val) {
	if (size_ >= capacity_)
		reserve(SV_CAP_INCR_COEF * size_);
	arr_[size_++] = val;
}

template<typename T>
inline void simpleVector<T>::pop_back() {
	if (!size_)
		throw std::exception("Nothing to pop");
}

template<typename T>
inline void simpleVector<T>::insert(iterator pos, const T& value) {
	if (std::distance(begin(), pos) > size_)
		throw std::out_of_range("Incorrect insertion position");
	if (size_ >= capacity_)
		reserve(SV_CAP_INCR_COEF * size_);

	arr_[std::distance(begin(), pos)] = value;
}

template<typename T>
inline void simpleVector<T>::append(iterator first, iterator last) {
	std::copy(first, last, std::back_inserter(*this));
}

template<typename T>
inline void simpleVector<T>::erase(iterator it) {
	if (it >= arr_ && it < arr_ + size_) {
		for (auto cur = it; cur != end() - 1; ++cur)
			*cur = *(cur + 1);
		--size_;
	}
}

template<typename T>
inline void simpleVector<T>::erase(iterator first, iterator last) {
	for (iterator it = first; it != last; ++it)
		this->erase(it);
}

template<typename T>
inline void simpleVector<T>::clear() {
	size_ = 0;
}

template<typename T>
inline void simpleVector<T>::resize(size_t newsize) {
	if (newsize > capacity_)
		reserve(SV_CAP_INCR_COEF * newsize);
	size_ = newsize;
}

// element access
template<typename T>
inline T& simpleVector<T>::operator[](size_t index) {
	if (index >= size_)
		throw std::out_of_range("Index out of range");
	return arr_[index];
}

template<typename T>
inline T& simpleVector<T>::front() {
	if (empty())
		throw throw std::out_of_range("Vector is empty");
	return arr_[0];
}

template<typename T>
inline T& simpleVector<T>::back() {
	if (empty())
		throw throw std::out_of_range("Vector is empty");
	return arr_[size_ - 1];
}

// iterator impl
template<typename T>
template<typename Val_type>
class simpleVector<T>::base_iterator {
public:
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = Val_type;
	using pointer = Val_type*;
	using reference = Val_type&;

	base_iterator() = delete;
	base_iterator(pointer ptr) : ptr(ptr) {}
	base_iterator(const base_iterator& other) : ptr(other.ptr) {}

	base_iterator operator=(const base_iterator& other) {
		ptr = other.ptr;
		return *this;
	}

	reference operator*() const {
		return *ptr;
	}
	pointer operator->() const {
		return ptr;
	}

	base_iterator& operator++() {
		++ptr; return *this;
	}
	base_iterator operator++(int) {
		base_iterator tmp = *this; ++(*this); return tmp;
	}
	base_iterator& operator--() {
		--ptr; return *this;
	}
	base_iterator operator--(int) {
		iterator tmp = *this; --(*this); return tmp;
	}

	// random access ops
	base_iterator& operator+=(difference_type n) {
		ptr += n;
		return *this;
	}
	base_iterator operator+(difference_type n) const {
		return iterator(ptr + n);
	}
	base_iterator& operator-=(difference_type n) {
		ptr -= n;
		return *this;
	}
	base_iterator operator-(difference_type n) const {
		return iterator(ptr - n);
	}
	difference_type operator-(const base_iterator& other) const {
		return ptr - other.ptr;
	}

	// comparison ops
	bool operator== (const base_iterator& other) {
		return ptr == other.ptr;
	};
	bool operator!= (const base_iterator& other) {
		return ptr != other.ptr;
	};
	bool operator< (const base_iterator& other) {
		return ptr < other.ptr;
	};
	bool operator> (const base_iterator& other) {
		return ptr > other.ptr;
	};
	bool operator<= (const base_iterator& other) {
		return ptr <= other.ptr;
	};
	bool operator>= (const base_iterator& other) {
		return ptr >= other.ptr;
	};

protected:
	pointer ptr;
};

