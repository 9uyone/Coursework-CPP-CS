using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Coursework_WinForms {
	public partial class fm_new_shape : Form {
		public static Point MAX_PICBOX_PT = new Point(500, 500);

		enum shp {
			SQUARE,
			RECTANGLE
		}
		shp SHAPE_TYPE;

		public fm_new_shape() {
			InitializeComponent();
		}

		private void type_sq_rd_CheckedChanged(object sender, EventArgs e) {
			sideH_lbl.Visible = sideH_tb.Visible = sideH_x_btn.Visible = type_rec_rd.Checked;
			if (type_rec_rd.Checked) { // it's Rectangle
				SHAPE_TYPE = shp.RECTANGLE;
				sideH_lbl.Visible = sideH_tb.Visible = true;
				sideW_lbl.Text = "Side_w";
			}
			else { // it's Square
				SHAPE_TYPE = shp.SQUARE;
				sideH_lbl.Visible = sideH_tb.Visible = false;
				sideW_lbl.Text = "Side";
			}
		}

		private void cancel_btn_Click(object sender, EventArgs e) {
			Close();
		}

		internal Shape CreateNewShape() {
			if (!Regex.IsMatch(name_tb.Text, "^\\w{1,15}$"))
				throw new Exception("No spaces are allowed, only English word letters; max length is 15");

			var textboses = new List<TextBox> { name_tb, lb_vtxX_tb, lb_vtxY_tb, sideW_tb };
			if (SHAPE_TYPE == shp.RECTANGLE)
				textboses.Add(sideH_tb);

			foreach (var tb in textboses)
				if (tb != null && string.IsNullOrWhiteSpace(tb.Text))
					throw new Exception("Please fill all the fields");

			Shape shape;
			try {
				if (!Program.checkFloat(lb_vtxX_tb.Text, lb_vtxY_tb.Text, sideW_tb.Text))
					throw new Exception("Incorrectly filled numeric fields");

				var x = float.Parse(lb_vtxX_tb.Text.Replace('.', ','));
				var y = float.Parse(lb_vtxY_tb.Text.Replace('.', ','));
				var side = float.Parse(sideW_tb.Text.Replace('.', ','));

				switch (SHAPE_TYPE) {
					case shp.SQUARE:
						shape = new Square(name_tb.Text, new Vertex(x, y), side);
						break;
					case shp.RECTANGLE:
						if (!Program.checkFloat(lb_vtxX_tb.Text, lb_vtxY_tb.Text, sideW_tb.Text))
							throw new Exception("Incorrectly filled numeric fields");
						var side_h = float.Parse(sideH_tb.Text.Replace('.', ','));
						shape = new Rectangle(name_tb.Text, new Vertex(x, y), side, side_h);
						break;
					default: throw new NotImplementedException("Unknown shape");
				}

				shape.color = colorDialog.Color;
			}
			catch (ArgumentException) { // if side length <= 0
				throw new Exception("Side length(s) must be > 0");
			}
			catch { throw; }

			return shape;
		}

		private void checkPicBoundsAndWarn(object sender, EventArgs e) {
			try {
				Shape shape = CreateNewShape();
				foreach (Vertex vtx in shape.vertices) {
					if (vtx.x < 0.0f || vtx.y < 0.0f || vtx.x > (float)MAX_PICBOX_PT.X || vtx.y > (float)MAX_PICBOX_PT.Y) {
						statusLabel.Text = "Shape won't be visible";
						return;
					}
				}
				statusLabel.Text = "";
			}
			catch ( Exception ex) { statusLabel.Text = ex.Message; }
		}

		private void ok_btn_Click(object sender, EventArgs e) {
			try {
				Shape shape = CreateNewShape();
				glob.shapes.Add(shape.name, shape);
				glob.main.UpdateShapeList();
			}
			catch (Exception ex) { // other possible exception
				MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return;
			}
			Close();
		}

		private void name_x_btn_Click(object sender, EventArgs e) {
			name_tb.Text = string.Empty;
		}
		private void lb_vtxX_x_btn_Click(object sender, EventArgs e) {
			lb_vtxX_tb.Text = string.Empty;
		}
		private void lb_vtxY_x_btn_Click(object sender, EventArgs e) {
			lb_vtxY_tb.Text = string.Empty;
		}
		private void side1_x_btn_Click(object sender, EventArgs e) {
			sideW_tb.Text = string.Empty;
		}
		private void side2_x_btn_Click(object sender, EventArgs e) {
			sideH_tb.Text = string.Empty;
		}

		private void fm_new_shape_Load(object sender, EventArgs e) {
			statusLabel.Text = string.Empty;
			penColor_lbl.BackColor = colorDialog.Color;
			penColor_lbl.Text = ColorTranslator.ToHtml(penColor_lbl.BackColor);
		}

		private void penColor_lbl_Click(object sender, EventArgs e) {
			if (colorDialog.ShowDialog() == DialogResult.OK) {
				penColor_lbl.BackColor = colorDialog.Color;
				penColor_lbl.ForeColor = ColorConverter.IdealTextColor(colorDialog.Color);
				penColor_lbl.Text = ColorTranslator.ToHtml(penColor_lbl.BackColor);
			}
		}
	}
}
