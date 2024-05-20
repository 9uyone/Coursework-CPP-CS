using System;
using System.CodeDom;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
		bool canSave = false;

		private void onXYchange() {
			//if (string.IsNullOrEmpty(vtxX_tb.Text) || string.IsNullOrEmpty(vtxY_tb.Text)
			if (!float.TryParse(vtxX_tb.Text, out dx) || !float.TryParse(vtxY_tb.Text, out dy)) {
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
			if (canSave)
				glob.shapes[cur_shape_name].move(dx, dy);
			else MessageBox.Show("Please fill x and y fields", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
			glob.main.canvas.Invalidate();
			Close();
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
