using System;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Coursework_WinForms {
	public partial class fm_move : Form {
		public fm_move(string cur_shape_name) {
			InitializeComponent();
			if (string.IsNullOrEmpty(cur_shape_name))
				throw new Exception("Empty `cur_shape_name` field");
			this.cur_shape_name = cur_shape_name;
		}

		private string cur_shape_name;
		private float dx, dy;
		bool canSave = true;

		private void onXYchange() {
			if (!Program.checkFloat(vtxX_tb.Text, vtxY_tb.Text) || !float.TryParse(vtxX_tb.Text.Replace('.', ','), out dx) || !float.TryParse(vtxY_tb.Text.Replace('.', ','), out dy)) {
				canSave = false;
				return;
			}

			Shape shp_copy = (Shape)glob.shapes[cur_shape_name].Clone();
			shp_copy.move(dx, dy);
			newVts_lb.Items.Clear();
			newVts_lb.Items.AddRange(shp_copy.vertices.ToArray());
			canSave = true;
		}

		private void save_btn_Click(object sender, EventArgs e) {
			if (canSave) {
				glob.shapes[cur_shape_name].move(dx, dy);
				Close();
				MessageBox.Show("The shape has been moved", "Move", MessageBoxButtons.OK, MessageBoxIcon.Information);
			}
			else MessageBox.Show("Empty or wrongly filled fields", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
			glob.main.canvas.Invalidate();
		}

		private void vtxX_tb_TextChanged(object sender, EventArgs e) {
			onXYchange();
		}

		private void vtxY_tb_TextChanged(object sender, EventArgs e) {
			onXYchange();
		}

		private void vtxX_x_btn_Click(object sender, EventArgs e) {
			vtxX_tb.Text = string.Empty;
		}

		private void vtxY_x_btn_Click(object sender, EventArgs e) {
			vtxY_tb.Text = string.Empty;
		}

		private void cancel_btn_Click(object sender, EventArgs e) {
			Close();
		}
	}
}
