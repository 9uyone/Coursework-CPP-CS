using System;
using System.Text.Json.Serialization;

namespace Coursework_WinForms {
	public class Vertex : IComparable<Vertex> {
		// properties
		public float x { get; set; }
		public float y { get; set; }

		// ctors
		[JsonConstructor]
		public Vertex(float x = 0, float y = 0) {
			this.x = x;
			this.y = y;
		}

		public Vertex(Vertex other) {
			x = other.x;
			y = other.y;
		}

		// object methods
		public override string ToString() {
			return $"({x}; {y})";
		}

		public override bool Equals(object obj) {
			return obj is Vertex vertex &&
				   x == vertex.x &&
				   y == vertex.y;
		}

		// comparison ops
		public static bool operator==(Vertex a, Vertex b) {
			return a.x == b.x && a.y == b.y;
		}
		public static bool operator !=(Vertex a, Vertex b) {
			return !(a == b);
		}
		public static bool operator <(Vertex a, Vertex b) {
			return a.x < b.x || a.x == b.x && a.y < b.y;
		}
		public static bool operator >(Vertex a, Vertex b) {
			return a.x > b.x || a.x == b.x && a.y > b.y;
		}

		public int CompareTo(Vertex other) {
			if (this < other) return -1;
			if (this > other) return 1;
			return 0;
		}

		// arithmetic ops
		public static Vertex operator+(Vertex a, Vertex b) {
			return new Vertex(a.x + b.x, a.y + b.y);
		}
		public static Vertex operator-(Vertex a, Vertex b) {
			return new Vertex(a.x - b.x, a.y - b.y);
		}
		public static Vertex operator*(Vertex a, Vertex b) {
			return new Vertex(a.x * b.x, a.y * b.y);
		}
		public static Vertex operator/(Vertex a, Vertex b) {
			//if (Math.Round(b.x, 4) == 0.0 || Math.Round(b.y, 4) == 0.0)
			if (b.x == 0.0 || b.y == 0.0)
				throw new ArgumentNullException("Vertex division by zero");
			return new Vertex(a.x / b.x, a.y / b.y);
		}

		// additional ops
		public Vertex abs() {
			return new Vertex(Math.Abs(x), Math.Abs(y));
		}

		public float hypot() {
			return (float)Math.Sqrt(x * x + y * y);
		}
	}
}
