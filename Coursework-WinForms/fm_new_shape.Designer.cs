namespace Coursework_WinForms {
	partial class fm_new_shape {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.type_sq_rd = new System.Windows.Forms.RadioButton();
			this.shape_type_pan = new System.Windows.Forms.GroupBox();
			this.type_rec_rd = new System.Windows.Forms.RadioButton();
			this.name_lbl = new System.Windows.Forms.Label();
			this.name_tb = new System.Windows.Forms.TextBox();
			this.shape_params_pan = new System.Windows.Forms.Panel();
			this.penColor_lbl = new System.Windows.Forms.Label();
			this.warning_lbl = new System.Windows.Forms.Label();
			this.sideH_x_btn = new System.Windows.Forms.Button();
			this.sideW_x_btn = new System.Windows.Forms.Button();
			this.lb_vtxY_x_btn = new System.Windows.Forms.Button();
			this.lb_vtxX_x_btn = new System.Windows.Forms.Button();
			this.name_x_btn = new System.Windows.Forms.Button();
			this.sideH_lbl = new System.Windows.Forms.Label();
			this.sideH_tb = new System.Windows.Forms.TextBox();
			this.sideW_lbl = new System.Windows.Forms.Label();
			this.sideW_tb = new System.Windows.Forms.TextBox();
			this.lb_vtxY_tb = new System.Windows.Forms.TextBox();
			this.lb_vtxY_lbl = new System.Windows.Forms.Label();
			this.lb_vtx_lbl = new System.Windows.Forms.Label();
			this.lb_vtxX_tb = new System.Windows.Forms.TextBox();
			this.lb_vtxX_lbl = new System.Windows.Forms.Label();
			this.ok_btn = new System.Windows.Forms.Button();
			this.cancel_btn = new System.Windows.Forms.Button();
			this.statusStrip = new System.Windows.Forms.StatusStrip();
			this.statusLabel = new System.Windows.Forms.ToolStripStatusLabel();
			this.colorDialog = new System.Windows.Forms.ColorDialog();
			this.shape_type_pan.SuspendLayout();
			this.shape_params_pan.SuspendLayout();
			this.statusStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// type_sq_rd
			// 
			this.type_sq_rd.AutoSize = true;
			this.type_sq_rd.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.type_sq_rd.Location = new System.Drawing.Point(9, 31);
			this.type_sq_rd.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
			this.type_sq_rd.Name = "type_sq_rd";
			this.type_sq_rd.Size = new System.Drawing.Size(77, 25);
			this.type_sq_rd.TabIndex = 0;
			this.type_sq_rd.Text = "Square";
			this.type_sq_rd.UseVisualStyleBackColor = true;
			this.type_sq_rd.CheckedChanged += new System.EventHandler(this.type_sq_rd_CheckedChanged);
			// 
			// shape_type_pan
			// 
			this.shape_type_pan.Controls.Add(this.type_rec_rd);
			this.shape_type_pan.Controls.Add(this.type_sq_rd);
			this.shape_type_pan.Font = new System.Drawing.Font("Segoe UI Semibold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.shape_type_pan.Location = new System.Drawing.Point(3, 0);
			this.shape_type_pan.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
			this.shape_type_pan.Name = "shape_type_pan";
			this.shape_type_pan.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
			this.shape_type_pan.Size = new System.Drawing.Size(121, 264);
			this.shape_type_pan.TabIndex = 1;
			this.shape_type_pan.TabStop = false;
			this.shape_type_pan.Text = "Shape type";
			// 
			// type_rec_rd
			// 
			this.type_rec_rd.AutoSize = true;
			this.type_rec_rd.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.type_rec_rd.Location = new System.Drawing.Point(9, 68);
			this.type_rec_rd.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
			this.type_rec_rd.Name = "type_rec_rd";
			this.type_rec_rd.Size = new System.Drawing.Size(96, 25);
			this.type_rec_rd.TabIndex = 1;
			this.type_rec_rd.Text = "Rectangle";
			this.type_rec_rd.UseVisualStyleBackColor = true;
			this.type_rec_rd.CheckedChanged += new System.EventHandler(this.type_sq_rd_CheckedChanged);
			// 
			// name_lbl
			// 
			this.name_lbl.Location = new System.Drawing.Point(3, 4);
			this.name_lbl.Name = "name_lbl";
			this.name_lbl.Size = new System.Drawing.Size(59, 26);
			this.name_lbl.TabIndex = 2;
			this.name_lbl.Text = "Name";
			this.name_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// name_tb
			// 
			this.name_tb.Location = new System.Drawing.Point(68, 4);
			this.name_tb.Name = "name_tb";
			this.name_tb.Size = new System.Drawing.Size(112, 29);
			this.name_tb.TabIndex = 3;
			// 
			// shape_params_pan
			// 
			this.shape_params_pan.Controls.Add(this.penColor_lbl);
			this.shape_params_pan.Controls.Add(this.warning_lbl);
			this.shape_params_pan.Controls.Add(this.sideH_x_btn);
			this.shape_params_pan.Controls.Add(this.sideW_x_btn);
			this.shape_params_pan.Controls.Add(this.lb_vtxY_x_btn);
			this.shape_params_pan.Controls.Add(this.lb_vtxX_x_btn);
			this.shape_params_pan.Controls.Add(this.name_x_btn);
			this.shape_params_pan.Controls.Add(this.sideH_lbl);
			this.shape_params_pan.Controls.Add(this.sideH_tb);
			this.shape_params_pan.Controls.Add(this.sideW_lbl);
			this.shape_params_pan.Controls.Add(this.name_tb);
			this.shape_params_pan.Controls.Add(this.name_lbl);
			this.shape_params_pan.Controls.Add(this.sideW_tb);
			this.shape_params_pan.Controls.Add(this.lb_vtxY_tb);
			this.shape_params_pan.Controls.Add(this.lb_vtxY_lbl);
			this.shape_params_pan.Controls.Add(this.lb_vtx_lbl);
			this.shape_params_pan.Controls.Add(this.lb_vtxX_tb);
			this.shape_params_pan.Controls.Add(this.lb_vtxX_lbl);
			this.shape_params_pan.Location = new System.Drawing.Point(124, 0);
			this.shape_params_pan.Name = "shape_params_pan";
			this.shape_params_pan.Size = new System.Drawing.Size(184, 264);
			this.shape_params_pan.TabIndex = 4;
			// 
			// penColor_lbl
			// 
			this.penColor_lbl.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
			this.penColor_lbl.Location = new System.Drawing.Point(8, 224);
			this.penColor_lbl.Name = "penColor_lbl";
			this.penColor_lbl.Size = new System.Drawing.Size(168, 34);
			this.penColor_lbl.TabIndex = 35;
			this.penColor_lbl.Text = "#FF8000";
			this.penColor_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.penColor_lbl.Click += new System.EventHandler(this.penColor_lbl_Click);
			// 
			// warning_lbl
			// 
			this.warning_lbl.AutoSize = true;
			this.warning_lbl.Location = new System.Drawing.Point(4, 240);
			this.warning_lbl.Name = "warning_lbl";
			this.warning_lbl.Size = new System.Drawing.Size(0, 21);
			this.warning_lbl.TabIndex = 34;
			this.warning_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// sideH_x_btn
			// 
			this.sideH_x_btn.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.sideH_x_btn.ForeColor = System.Drawing.Color.Red;
			this.sideH_x_btn.Location = new System.Drawing.Point(148, 187);
			this.sideH_x_btn.Name = "sideH_x_btn";
			this.sideH_x_btn.Size = new System.Drawing.Size(28, 27);
			this.sideH_x_btn.TabIndex = 33;
			this.sideH_x_btn.Text = "X";
			this.sideH_x_btn.UseVisualStyleBackColor = true;
			this.sideH_x_btn.Click += new System.EventHandler(this.side2_x_btn_Click);
			// 
			// sideW_x_btn
			// 
			this.sideW_x_btn.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.sideW_x_btn.ForeColor = System.Drawing.Color.Red;
			this.sideW_x_btn.Location = new System.Drawing.Point(148, 152);
			this.sideW_x_btn.Name = "sideW_x_btn";
			this.sideW_x_btn.Size = new System.Drawing.Size(28, 27);
			this.sideW_x_btn.TabIndex = 32;
			this.sideW_x_btn.Text = "X";
			this.sideW_x_btn.UseVisualStyleBackColor = true;
			this.sideW_x_btn.Click += new System.EventHandler(this.side1_x_btn_Click);
			// 
			// lb_vtxY_x_btn
			// 
			this.lb_vtxY_x_btn.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.lb_vtxY_x_btn.ForeColor = System.Drawing.Color.Red;
			this.lb_vtxY_x_btn.Location = new System.Drawing.Point(148, 110);
			this.lb_vtxY_x_btn.Name = "lb_vtxY_x_btn";
			this.lb_vtxY_x_btn.Size = new System.Drawing.Size(28, 27);
			this.lb_vtxY_x_btn.TabIndex = 31;
			this.lb_vtxY_x_btn.Text = "X";
			this.lb_vtxY_x_btn.UseVisualStyleBackColor = true;
			this.lb_vtxY_x_btn.Click += new System.EventHandler(this.lb_vtxY_x_btn_Click);
			// 
			// lb_vtxX_x_btn
			// 
			this.lb_vtxX_x_btn.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.lb_vtxX_x_btn.ForeColor = System.Drawing.Color.Red;
			this.lb_vtxX_x_btn.Location = new System.Drawing.Point(148, 75);
			this.lb_vtxX_x_btn.Name = "lb_vtxX_x_btn";
			this.lb_vtxX_x_btn.Size = new System.Drawing.Size(28, 27);
			this.lb_vtxX_x_btn.TabIndex = 30;
			this.lb_vtxX_x_btn.Text = "X";
			this.lb_vtxX_x_btn.UseVisualStyleBackColor = true;
			this.lb_vtxX_x_btn.Click += new System.EventHandler(this.lb_vtxX_x_btn_Click);
			// 
			// name_x_btn
			// 
			this.name_x_btn.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.name_x_btn.ForeColor = System.Drawing.Color.Red;
			this.name_x_btn.Location = new System.Drawing.Point(152, 4);
			this.name_x_btn.Name = "name_x_btn";
			this.name_x_btn.Size = new System.Drawing.Size(28, 27);
			this.name_x_btn.TabIndex = 29;
			this.name_x_btn.Text = "X";
			this.name_x_btn.UseVisualStyleBackColor = true;
			this.name_x_btn.Click += new System.EventHandler(this.name_x_btn_Click);
			// 
			// sideH_lbl
			// 
			this.sideH_lbl.Location = new System.Drawing.Point(3, 186);
			this.sideH_lbl.Name = "sideH_lbl";
			this.sideH_lbl.Size = new System.Drawing.Size(59, 26);
			this.sideH_lbl.TabIndex = 13;
			this.sideH_lbl.Text = "Side_h";
			this.sideH_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.sideH_lbl.Visible = false;
			// 
			// sideH_tb
			// 
			this.sideH_tb.Location = new System.Drawing.Point(68, 186);
			this.sideH_tb.Name = "sideH_tb";
			this.sideH_tb.Size = new System.Drawing.Size(108, 29);
			this.sideH_tb.TabIndex = 12;
			this.sideH_tb.Visible = false;
			this.sideH_tb.TextChanged += new System.EventHandler(this.checkPicBoundsAndWarn);
			// 
			// sideW_lbl
			// 
			this.sideW_lbl.Location = new System.Drawing.Point(1, 151);
			this.sideW_lbl.Name = "sideW_lbl";
			this.sideW_lbl.Size = new System.Drawing.Size(61, 26);
			this.sideW_lbl.TabIndex = 11;
			this.sideW_lbl.Text = "Side_w";
			this.sideW_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// sideW_tb
			// 
			this.sideW_tb.Location = new System.Drawing.Point(68, 151);
			this.sideW_tb.Name = "sideW_tb";
			this.sideW_tb.Size = new System.Drawing.Size(108, 29);
			this.sideW_tb.TabIndex = 10;
			this.sideW_tb.TextChanged += new System.EventHandler(this.checkPicBoundsAndWarn);
			// 
			// lb_vtxY_tb
			// 
			this.lb_vtxY_tb.Location = new System.Drawing.Point(33, 109);
			this.lb_vtxY_tb.Name = "lb_vtxY_tb";
			this.lb_vtxY_tb.Size = new System.Drawing.Size(144, 29);
			this.lb_vtxY_tb.TabIndex = 8;
			this.lb_vtxY_tb.TextChanged += new System.EventHandler(this.checkPicBoundsAndWarn);
			// 
			// lb_vtxY_lbl
			// 
			this.lb_vtxY_lbl.Location = new System.Drawing.Point(2, 109);
			this.lb_vtxY_lbl.Name = "lb_vtxY_lbl";
			this.lb_vtxY_lbl.Size = new System.Drawing.Size(25, 26);
			this.lb_vtxY_lbl.TabIndex = 7;
			this.lb_vtxY_lbl.Text = "y";
			this.lb_vtxY_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lb_vtx_lbl
			// 
			this.lb_vtx_lbl.Location = new System.Drawing.Point(1, 43);
			this.lb_vtx_lbl.Name = "lb_vtx_lbl";
			this.lb_vtx_lbl.Size = new System.Drawing.Size(175, 26);
			this.lb_vtx_lbl.TabIndex = 5;
			this.lb_vtx_lbl.Text = "Left bottom vertex";
			this.lb_vtx_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lb_vtxX_tb
			// 
			this.lb_vtxX_tb.Location = new System.Drawing.Point(33, 74);
			this.lb_vtxX_tb.Name = "lb_vtxX_tb";
			this.lb_vtxX_tb.Size = new System.Drawing.Size(144, 29);
			this.lb_vtxX_tb.TabIndex = 6;
			this.lb_vtxX_tb.TextChanged += new System.EventHandler(this.checkPicBoundsAndWarn);
			// 
			// lb_vtxX_lbl
			// 
			this.lb_vtxX_lbl.Location = new System.Drawing.Point(2, 71);
			this.lb_vtxX_lbl.Name = "lb_vtxX_lbl";
			this.lb_vtxX_lbl.Size = new System.Drawing.Size(25, 26);
			this.lb_vtxX_lbl.TabIndex = 5;
			this.lb_vtxX_lbl.Text = "x";
			this.lb_vtxX_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// ok_btn
			// 
			this.ok_btn.Location = new System.Drawing.Point(3, 266);
			this.ok_btn.Name = "ok_btn";
			this.ok_btn.Size = new System.Drawing.Size(213, 34);
			this.ok_btn.TabIndex = 9;
			this.ok_btn.Text = "Create";
			this.ok_btn.UseVisualStyleBackColor = true;
			this.ok_btn.Click += new System.EventHandler(this.ok_btn_Click);
			// 
			// cancel_btn
			// 
			this.cancel_btn.Location = new System.Drawing.Point(216, 266);
			this.cancel_btn.Name = "cancel_btn";
			this.cancel_btn.Size = new System.Drawing.Size(89, 34);
			this.cancel_btn.TabIndex = 10;
			this.cancel_btn.Text = "Cancel";
			this.cancel_btn.UseVisualStyleBackColor = true;
			this.cancel_btn.Click += new System.EventHandler(this.cancel_btn_Click);
			// 
			// statusStrip
			// 
			this.statusStrip.Font = new System.Drawing.Font("Segoe UI", 11F);
			this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusLabel});
			this.statusStrip.Location = new System.Drawing.Point(0, 299);
			this.statusStrip.Name = "statusStrip";
			this.statusStrip.Size = new System.Drawing.Size(308, 25);
			this.statusStrip.TabIndex = 11;
			this.statusStrip.Text = "fff";
			// 
			// statusLabel
			// 
			this.statusLabel.Name = "statusLabel";
			this.statusLabel.Size = new System.Drawing.Size(49, 20);
			this.statusLabel.Text = "Status";
			// 
			// colorDialog
			// 
			this.colorDialog.AnyColor = true;
			this.colorDialog.Color = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
			// 
			// fm_new_shape
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 21F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(308, 324);
			this.Controls.Add(this.statusStrip);
			this.Controls.Add(this.cancel_btn);
			this.Controls.Add(this.ok_btn);
			this.Controls.Add(this.shape_params_pan);
			this.Controls.Add(this.shape_type_pan);
			this.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
			this.MaximizeBox = false;
			this.Name = "fm_new_shape";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
			this.Text = "New shape";
			this.Load += new System.EventHandler(this.fm_new_shape_Load);
			this.shape_type_pan.ResumeLayout(false);
			this.shape_type_pan.PerformLayout();
			this.shape_params_pan.ResumeLayout(false);
			this.shape_params_pan.PerformLayout();
			this.statusStrip.ResumeLayout(false);
			this.statusStrip.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion
		private System.Windows.Forms.Label name_lbl;
		private System.Windows.Forms.TextBox name_tb;
		private System.Windows.Forms.Panel shape_params_pan;
		private System.Windows.Forms.Label lb_vtx_lbl;
		private System.Windows.Forms.TextBox lb_vtxX_tb;
		private System.Windows.Forms.Label lb_vtxX_lbl;
		private System.Windows.Forms.TextBox lb_vtxY_tb;
		private System.Windows.Forms.Label lb_vtxY_lbl;
		private System.Windows.Forms.Label sideW_lbl;
		private System.Windows.Forms.TextBox sideW_tb;
		private System.Windows.Forms.Button ok_btn;
		private System.Windows.Forms.Button cancel_btn;
		private System.Windows.Forms.Label sideH_lbl;
		private System.Windows.Forms.TextBox sideH_tb;
		internal System.Windows.Forms.GroupBox shape_type_pan;
		internal System.Windows.Forms.RadioButton type_sq_rd;
		internal System.Windows.Forms.RadioButton type_rec_rd;
		private System.Windows.Forms.Button name_x_btn;
		private System.Windows.Forms.Button sideH_x_btn;
		private System.Windows.Forms.Button sideW_x_btn;
		private System.Windows.Forms.Button lb_vtxY_x_btn;
		private System.Windows.Forms.Button lb_vtxX_x_btn;
		private System.Windows.Forms.Label warning_lbl;
		private System.Windows.Forms.StatusStrip statusStrip;
		private System.Windows.Forms.ToolStripStatusLabel statusLabel;
		private System.Windows.Forms.Label penColor_lbl;
		private System.Windows.Forms.ColorDialog colorDialog;
	}
}