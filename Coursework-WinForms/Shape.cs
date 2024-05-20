using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;

namespace Coursework_WinForms {
	public abstract class Shape : ICloneable {
		// properties
		public string name { get; set; }
		public List<Vertex> vertices { get; protected set; }
		[JsonConverter(typeof(ColorConverter))] public Color color { get; set; }

		// indexer
		public Vertex this[int index] {
			get { return vertices.ElementAt(index); }
			protected set { vertices[index] = value; }
		}

		// ctors
		public Shape(string name, List<Vertex> vertices) {
			this.name = name;
			this.vertices = new List<Vertex>(vertices);
			color = Color.Black;
			checkShape();
		}

		public Shape(string name, params Vertex[] vertices) {
			this.name = name;
			color = Color.Black;

			if (vertices == null)
				throw new ArgumentNullException("Empty vertex list");
			this.vertices = new List<Vertex>(vertices);
			checkShape();
		}

		// methods
		bool isClockwise() {
			double sum = 0;
			for (int i = 0; i < vertices.Count; i++) {
				var cur = vertices[i];
				var next = vertices[(i + 1) % vertices.Count];
				sum += (next.x - cur.x) * (next.y + cur.y);
			}
			return sum > 0;
		}

		void checkShape() {
			if (!isClockwise())
				throw new ArgumentException($"{name}: The sequence of vertices is not clockwise");
		}

		virtual public void move(float deltaX, float deltaY) {
			for (int i = 0; i < vertices.Count; i++)
				vertices[i] += new Vertex(deltaX, deltaY);
		}

		// abstact methods
		public abstract object Clone();
		public abstract double square();
		public abstract JsonNode makeJson();

		// object methods
		public override int GetHashCode() {
			return name.GetHashCode();
		}

		public override string ToString() {
			string result = $"Name: {name}\n" +
			$"Type: {GetType().Name}\n" +
			$"Square: {square()}\n" +
			"Vertices:\n";
			foreach (Vertex vtx in vertices)
				result += "\t" + vtx.ToString() + "\n";

			return result;
		}
	}
}
