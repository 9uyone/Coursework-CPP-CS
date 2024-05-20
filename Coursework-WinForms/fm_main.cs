using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Windows.Forms;

namespace Coursework_WinForms {
	public partial class fm_main : Form {
		public fm_main() {
			InitializeComponent();
		}

		public void UpdateShapeList() {
			shapeList.Items.Clear();
			foreach (var item in glob.shapes)
				shapeList.Items.Add(item.Value.name);
			shapes_label.Text = "Shapes (" + glob.shapes.Count + ')';
			canvas.Invalidate();
		}

		private void menu_file_save_json_Click(object sender, EventArgs e) {
			if (glob.shapes.Count == 0) {
				MessageBox.Show("Create at least one shape", "Empty shape list", MessageBoxButtons.OK, MessageBoxIcon.Warning);
				return;
			}

			saveDialog.Filter = "JSON (*.json)|*.json";
			if (saveDialog.ShowDialog() == DialogResult.OK) {
				JsonObject json = new JsonObject();
				json.Add("count", glob.shapes.Count);
				var shp_arr = new JsonArray();
				foreach (var shape in glob.shapes) {
					var node = shape.Value.makeJson();
					node.AsObject().Add("type", shape.Value.GetType().ToString());
					shp_arr.Add(node);
				}
				json.Add("shapes", shp_arr);
				File.WriteAllText(saveDialog.FileName, json.ToString());
			}
		}

		private void shape_list_DoubleClick(object sender, EventArgs e) {
			if (shapeList.SelectedIndex == -1) return;
			fm_info f = new fm_info(glob.shapes[shapeList.Text]);
			f.Show();
		}

		private void crate_sq_btn_Click(object sender, EventArgs e) {
			fm_new_shape f = new fm_new_shape();
			f.type_sq_rd.Checked = true;
			f.ShowDialog();
		}

		private void create_rec_btn_Click(object sender, EventArgs e) {
			fm_new_shape f = new fm_new_shape();
			f.type_rec_rd.Checked = true;
			f.ShowDialog();
		}

		private void shapePics_Paint(object sender, PaintEventArgs e) {
			float scale_x = (float)(canvas.ClientSize.Width) / fm_new_shape.MAX_PICBOX_PT.X;
			//float scale_y = (float)shapePic.ClientSize.Height / fm_new_shape.MAX_PICBOX_PT.Y * ((float)shapePic.ClientSize.Width / shapePic.ClientSize.Height);
			float scale_y = (float)canvas.ClientSize.Height / fm_new_shape.MAX_PICBOX_PT.Y;

			const float totalScale = 0.986f;
			float margin_x = (1 - totalScale) * canvas.ClientSize.Width / 2;
			float margin_y = (1 - totalScale) * canvas.ClientSize.Height / 2;
			e.Graphics.ScaleTransform(totalScale * scale_x, totalScale * scale_y);

			const float penSize_hf = 3 / 2f;

			foreach (Shape cur_shp_ in glob.shapes.Values) {
				Pen pen = new Pen(cur_shp_.color, penSize_hf * 2);
				float width = 0, height = 0;

				if (cur_shp_ is Rectangle) {
					width = (cur_shp_ as Rectangle).side_w;
					height = (cur_shp_ as Rectangle).side_h;
				}
				else if (cur_shp_ is Square) {
					width = height = (cur_shp_ as Square).side;
				}

				Vertex min_vtx = cur_shp_.vertices.Min();
				//e.Graphics.DrawRectangle(pen, cur_shp_.vertices[0].x + margin_x + penSize_hf, cur_shp_.vertices[0].y + margin_y + penSize_hf,
				e.Graphics.DrawRectangle(pen, min_vtx.x + margin_x + penSize_hf, min_vtx.y + margin_y + penSize_hf,
					width - margin_x - penSize_hf, height - margin_y - penSize_hf);
			}
		}

		private void edit_rm_btn_Click(object sender, EventArgs e) {
			if (shapeList.SelectedIndex != -1 && MessageBox.Show($"You really wanna remove {shapeList.Text}", "Delete confirmation", MessageBoxButtons.YesNo) == DialogResult.Yes) {
				glob.shapes.Remove(shapeList.Text);
				shapeList.Items.RemoveAt(shapeList.SelectedIndex);
				UpdateShapeList();
			}
		}

		private void menu_file_load_json_Click(object sender, EventArgs e) {
			if (openDialog.ShowDialog() == DialogResult.OK) {
				var json = JsonNode.Parse(File.ReadAllText(openDialog.FileName));
				foreach (var json_shp in json["shapes"].AsArray()) {
					try {
						var type = Type.GetType(json_shp["type"].ToString());
						glob.shapes.Add(json_shp["name"].ToString(), (Shape)Activator.CreateInstance(type, json_shp["name"].ToString(), JsonSerializer.Deserialize<List<Vertex>>(json_shp["vertices"])));
						UpdateShapeList();
					}
					catch (ArgumentNullException) {
						MessageBox.Show("Incorrect shape type", json_shp["name"].ToString(), MessageBoxButtons.OK, MessageBoxIcon.Error);
					}
				}
			}
		}

		private void clear_btn_Click(object sender, EventArgs e) {
			if (MessageBox.Show("You really wanna clear all shapes?", "Delete confirmation", MessageBoxButtons.YesNo) == DialogResult.Yes) {
				glob.shapes.Clear();
				UpdateShapeList();
				canvas.Image = null;
			}
		}

		private void shapeList_KeyDown(object sender, KeyEventArgs e) {
			if (e.KeyCode == Keys.Delete) {
				edit_rm_btn_Click(sender, e);
			}
		}

		private void edit_mv_btn_Click(object sender, EventArgs e) {
			if (shapeList.SelectedIndex == -1) {
				MessageBox.Show("Виберіть фігуру зі списку");
				return;
			}

			fm_move f = new fm_move(shapeList.Text);

			f.curVts_lb.Items.Clear();
			f.curVts_lb.Items.AddRange(glob.shapes[shapeList.Text].vertices.ToArray());

			f.newVts_lb.Items.Clear();
			f.vtxX_tb.Text = f.vtxY_tb.Text = "0";
			f.ShowDialog();
		}

		private void file_save_txt_Click(object sender, EventArgs e) {
			if (shapeList.Items.Count == 0) {
				MessageBox.Show("Nothing to save", "Saving", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				return;
			}

			saveDialog.Filter = "txt files (*.txt)|*.txt";
			if (saveDialog.ShowDialog() == DialogResult.OK) {
				using (var fs = File.Create(saveDialog.FileName))
				using (var sw = new StreamWriter(fs)) {
					sw.WriteLine($"Count: {glob.shapes.Count}");
					var maxSqShp = fm_info.getMaxSquareShape();
					sw.WriteLine($"Max square: {maxSqShp.square()} ({maxSqShp.name})\n");

					foreach (Shape shape in glob.shapes.Values) {
						sw.WriteLine(shape);
					}
				}
				MessageBox.Show("Successfully saved", "Saving", MessageBoxButtons.OK, MessageBoxIcon.Information);
			}
		}

		private void file_save_json_btn_Click(object sender, EventArgs e) {
			if (shapeList.Items.Count == 0) {
				MessageBox.Show("Nothing to save", "Saving", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				return;
			}

			saveDialog.Filter = "json files (*.json)|*.json";
			if (saveDialog.ShowDialog() != DialogResult.OK)
				return;

			JsonObject jobj = new JsonObject();
			var j_info = jobj["info"] = new JsonObject();

			j_info["count"] = shapeList.Items.Count;
			var j_max_sq = j_info["max_square"] = new JsonObject();
			Shape maxSqShp = fm_info.getMaxSquareShape();
			j_max_sq["shape_name"] = maxSqShp.name;
			j_max_sq["square"] = maxSqShp.square();

			jobj["shapes"] = new JsonArray();
			foreach (Shape shape in glob.shapes.Values) {
				JsonObject curObj = shape.makeJson().AsObject();
				curObj.Add("type", shape.GetType().Name);
				jobj["shapes"].AsArray().Add(curObj);
			}
			File.WriteAllText(saveDialog.FileName, jobj.ToString());
			MessageBox.Show("Successfully saved", "Saving", MessageBoxButtons.OK, MessageBoxIcon.Information);
		}

		private void file_load_json_btn_Click(object sender, EventArgs e) {
			try {
				if (openDialog.ShowDialog() != DialogResult.OK)
					return;
				
				var jobj = JsonSerializer.Deserialize<JsonObject>(File.ReadAllText(openDialog.FileName));
				foreach (var curObj in jobj["shapes"].AsArray()) {
					string name = curObj["name"].ToString();
					List<Vertex> verts = JsonSerializer.Deserialize<List<Vertex>>(curObj["vertices"]);

					string shpType = curObj["type"].ToString();
					string nsName = GetType().Namespace + ".";
					if (!shpType.StartsWith(nsName))
						shpType = nsName + shpType;
					Shape shape = (Shape)Activator.CreateInstance(Type.GetType(shpType), name, verts);

					if (curObj["color"] != null && curObj["color"].ToString() != "")
						shape.color = JsonSerializer.Deserialize<Color>(curObj["color"], new JsonSerializerOptions { Converters = { new ColorConverter() } });
					else shape.color = Color.Black;

					glob.shapes.Add(name, shape);
					UpdateShapeList();
				}

			} catch(Exception ex) {
				MessageBox.Show(ex.Message, "Opening error", MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}

		private void showMaxSq_btn_Click(object sender, EventArgs e) {
			try {
				var shp = fm_info.getMaxSquareShape();
				MessageBox.Show($"Max square: {shp.square()}" +
					$"\nShape name: {shp.name}",
					"Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
			}
			catch (Exception ex) {
				MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}
	}
}
