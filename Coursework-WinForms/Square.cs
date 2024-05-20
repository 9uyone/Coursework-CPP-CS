using System;
using System.Collections.Generic;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;

namespace Coursework_WinForms {
	public class Square : Shape {
		// properties
		[JsonIgnore] public float side { get; private set; }

		// ctors
		public Square(string name, Vertex vtx, float side) :
			base(name, vtx,
				new Vertex(vtx.x, vtx.y + side),
				new Vertex(vtx.x + side, vtx.y + side),
				new Vertex(vtx.x + side, vtx.y))
		{
			if (side <= 0)
				throw new ArgumentException("Side length must be > 0");
			this.side = side;
		}

		public Square(string name, List<Vertex> vertices) : base(name, vertices) {
			checkAndSet();
		}
		public Square(string name, params Vertex[] vertices) : base(name, vertices) {
			checkAndSet();
		}

		public Square(Square other) :
			base(other.name, other.vertices) {
				side = other.side;
		}

		// methods
		void checkAndSet() {
			if ((this[1] - this[0]) != (this[2] - this[3]))
				throw new ArgumentException($"{name}: The given points don't form a square");
			side = (this[1] - this[0]).hypot();
		}

		// abstract methods
		public override object Clone() {
			return new Square(name, vertices);
		}

		public override double square() {
			return side * side;
		}

		public override JsonNode makeJson() {
			return JsonSerializer.SerializeToNode(this);
		}

		public override string ToString() {
			return base.ToString() +
				$"Side: {side}\n";
		}

	}
}
