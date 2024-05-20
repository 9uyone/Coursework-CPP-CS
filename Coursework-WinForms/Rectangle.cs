using System;
using System.Collections.Generic;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;

namespace Coursework_WinForms {
	public class Rectangle : Shape {
		//properties
		[JsonIgnore] public float side_w { get; private set; }
		[JsonIgnore] public float side_h { get; private set; }

		// ctors
		public Rectangle(string name, Vertex vtx, float sW, float sH) :
			base(name, vtx,
				new Vertex(vtx.x, vtx.y + sH),
				new Vertex(vtx.x + sW, vtx.y + sH),
				new Vertex(vtx.x + sW, vtx.y))
		{
			if (sH <= 0 || sW <= 0)
				throw new ArgumentException("Side lengths must be > 0");
			side_w = sW;
			side_h = sH;
		}

		public Rectangle(string name, List<Vertex> vertices) : base(name, vertices) {
			checkAndSet();
		}
		public Rectangle(string name, params Vertex[] vertices) : base(name, vertices) {
			checkAndSet();
		}

		public Rectangle(Rectangle other) : base(other.name, other.vertices) {
			checkAndSet();
			side_h = other.side_h;
			side_w = other.side_w;
		}

		// methods
		void checkAndSet() {
			if ((this[2] - this[0]).abs() != (this[3] - this[1]).abs())
				throw new ArgumentException($"{name}: The given points don't form a rectangle");
			
			side_h = (this[1] - this[0]).hypot();
			side_w = (this[2] - this[1]).hypot();
		}

		// abstract methods
		public override object Clone() {
			return new Rectangle(name, vertices);
		}

		public override double square() {
			return side_h * side_w;
		}

		public override JsonNode makeJson() {
			return JsonSerializer.SerializeToNode(this);
		}

		public override string ToString() {
			return base.ToString() +
				$"side_w: {side_w}\n" +
				$"side_h: {side_h}\n";
		}
	}
}
