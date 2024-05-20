using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace Coursework_WinForms {
	public partial class fm_info : Form {
		Shape curShp;

		public fm_info(Shape currentShape) {
			InitializeComponent();
			this.curShp = currentShape;
		}

		public static float getMaxSquare() {
			if (glob.shapes.Values.Count == 0)
				throw new NoNullAllowedException("Empty shape list");
			return (float)glob.shapes.Values.Max(shp => shp.square());
		}

		public static Shape getMaxSquareShape() {
			if (glob.shapes.Values.Count == 0)
				throw new NoNullAllowedException("Empty shape list");
			return glob.shapes.Values.OrderByDescending(shp => shp.square()).First();
		}

		private void shapePic_Paint(object sender, PaintEventArgs e) {
			float side_w = 1, side_h = 1;

			if (curShp is Rectangle) {
				var cur_shp = curShp as Rectangle;
				side_w = cur_shp.side_w;
				side_h = cur_shp.side_h;
			}
			else if (curShp is Square) {
				var cur_shp = curShp as Square;
				side_w = side_h = cur_shp.side;
			}

			const float totalScale = 0.986f;
			float scale_x = shapePic.ClientSize.Width / side_w;
			float scale_y = shapePic.ClientSize.Height / side_h;
			float scale = totalScale * Math.Min(scale_x, scale_y);
			float margin_x = (1 - totalScale) * shapePic.ClientSize.Width / 2;
			float margin_y = (1 - totalScale) * shapePic.ClientSize.Height / 2;

			const float penSize_hf = 3 / 2f;
			Pen pen = new Pen(curShp.color, penSize_hf * 2);
			side_w *= scale; side_h *= scale;
			e.Graphics.DrawRectangle(pen, margin_x + penSize_hf, margin_y + penSize_hf,
				side_w - margin_x - penSize_hf, side_h - margin_y - penSize_hf);
		}

		private void fm_info_Load(object sender, EventArgs e) {
			name_tb.Text = curShp.name;
			type_tb.Text = curShp.GetType().Name;
			penColor.BackColor = curShp.color;
			penColor.ForeColor = ColorConverter.IdealTextColor(curShp.color);
			penColor.Text = ColorTranslator.ToHtml(penColor.BackColor);

			vertexList.Items.Clear();
			foreach (var elem in curShp.vertices)
				vertexList.Items.Add(elem);

			try {
				switch (curShp.GetType().Name) {
					case "Square":
						sideH_lbl.Visible = sideH_tb.Visible = false;
						sideW_lbl.Text = "Side";
						sideW_tb.Text = (curShp as Square).side.ToString();
						break;

					case "Rectangle":
						sideH_lbl.Visible = sideH_tb.Visible = true;
						sideW_lbl.Text = "Side_w";
						sideW_tb.Text = (curShp as Rectangle).side_w.ToString();
						sideH_tb.Text = (curShp as Rectangle).side_h.ToString();
						break;

					default: throw new InvalidDataException("Invalid shape type");
				}
			}
			catch (Exception ex) { MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
		}
	}
}
