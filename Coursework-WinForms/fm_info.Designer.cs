namespace Coursework_WinForms {
	partial class fm_info {
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
			this.vertices_lbl = new System.Windows.Forms.Label();
			this.sideW_tb = new System.Windows.Forms.TextBox();
			this.sideW_lbl = new System.Windows.Forms.Label();
			this.sideH_tb = new System.Windows.Forms.TextBox();
			this.name_lbl = new System.Windows.Forms.Label();
			this.name_tb = new System.Windows.Forms.TextBox();
			this.sideH_lbl = new System.Windows.Forms.Label();
			this.vertexList = new System.Windows.Forms.ListBox();
			this.type_lbl = new System.Windows.Forms.Label();
			this.type_tb = new System.Windows.Forms.TextBox();
			this.shape_params_pan = new System.Windows.Forms.Panel();
			this.penColor = new System.Windows.Forms.Label();
			this.shapePic = new System.Windows.Forms.PictureBox();
			this.shape_params_pan.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.shapePic)).BeginInit();
			this.SuspendLayout();
			// 
			// vertices_lbl
			// 
			this.vertices_lbl.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.vertices_lbl.Location = new System.Drawing.Point(4, 83);
			this.vertices_lbl.Name = "vertices_lbl";
			this.vertices_lbl.Size = new System.Drawing.Size(222, 26);
			this.vertices_lbl.TabIndex = 5;
			this.vertices_lbl.Text = "Vertices";
			this.vertices_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// sideW_tb
			// 
			this.sideW_tb.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.sideW_tb.Location = new System.Drawing.Point(76, 268);
			this.sideW_tb.Name = "sideW_tb";
			this.sideW_tb.ReadOnly = true;
			this.sideW_tb.Size = new System.Drawing.Size(147, 29);
			this.sideW_tb.TabIndex = 10;
			// 
			// sideW_lbl
			// 
			this.sideW_lbl.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.sideW_lbl.Location = new System.Drawing.Point(2, 269);
			this.sideW_lbl.Name = "sideW_lbl";
			this.sideW_lbl.Size = new System.Drawing.Size(72, 26);
			this.sideW_lbl.TabIndex = 11;
			this.sideW_lbl.Text = "Side_w";
			this.sideW_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// sideH_tb
			// 
			this.sideH_tb.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.sideH_tb.Location = new System.Drawing.Point(76, 308);
			this.sideH_tb.Name = "sideH_tb";
			this.sideH_tb.ReadOnly = true;
			this.sideH_tb.Size = new System.Drawing.Size(146, 29);
			this.sideH_tb.TabIndex = 12;
			// 
			// name_lbl
			// 
			this.name_lbl.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.name_lbl.Location = new System.Drawing.Point(4, 10);
			this.name_lbl.Name = "name_lbl";
			this.name_lbl.Size = new System.Drawing.Size(59, 26);
			this.name_lbl.TabIndex = 6;
			this.name_lbl.Text = "Name";
			this.name_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// name_tb
			// 
			this.name_tb.BackColor = System.Drawing.SystemColors.Control;
			this.name_tb.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.name_tb.Location = new System.Drawing.Point(69, 9);
			this.name_tb.Name = "name_tb";
			this.name_tb.ReadOnly = true;
			this.name_tb.Size = new System.Drawing.Size(157, 29);
			this.name_tb.TabIndex = 7;
			// 
			// sideH_lbl
			// 
			this.sideH_lbl.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.sideH_lbl.Location = new System.Drawing.Point(4, 308);
			this.sideH_lbl.Name = "sideH_lbl";
			this.sideH_lbl.Size = new System.Drawing.Size(68, 26);
			this.sideH_lbl.TabIndex = 13;
			this.sideH_lbl.Text = "Side_h";
			this.sideH_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			this.sideH_lbl.Visible = false;
			// 
			// vertexList
			// 
			this.vertexList.FormattingEnabled = true;
			this.vertexList.ItemHeight = 21;
			this.vertexList.Location = new System.Drawing.Point(4, 112);
			this.vertexList.Name = "vertexList";
			this.vertexList.SelectionMode = System.Windows.Forms.SelectionMode.None;
			this.vertexList.Size = new System.Drawing.Size(222, 109);
			this.vertexList.TabIndex = 14;
			// 
			// type_lbl
			// 
			this.type_lbl.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.type_lbl.Location = new System.Drawing.Point(4, 46);
			this.type_lbl.Name = "type_lbl";
			this.type_lbl.Size = new System.Drawing.Size(59, 26);
			this.type_lbl.TabIndex = 15;
			this.type_lbl.Text = "Type";
			this.type_lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// type_tb
			// 
			this.type_tb.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.type_tb.Location = new System.Drawing.Point(69, 46);
			this.type_tb.Name = "type_tb";
			this.type_tb.ReadOnly = true;
			this.type_tb.Size = new System.Drawing.Size(157, 29);
			this.type_tb.TabIndex = 16;
			// 
			// shape_params_pan
			// 
			this.shape_params_pan.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.shape_params_pan.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.shape_params_pan.Controls.Add(this.penColor);
			this.shape_params_pan.Controls.Add(this.shapePic);
			this.shape_params_pan.Controls.Add(this.type_tb);
			this.shape_params_pan.Controls.Add(this.type_lbl);
			this.shape_params_pan.Controls.Add(this.vertexList);
			this.shape_params_pan.Controls.Add(this.sideH_lbl);
			this.shape_params_pan.Controls.Add(this.name_tb);
			this.shape_params_pan.Controls.Add(this.name_lbl);
			this.shape_params_pan.Controls.Add(this.sideH_tb);
			this.shape_params_pan.Controls.Add(this.sideW_lbl);
			this.shape_params_pan.Controls.Add(this.sideW_tb);
			this.shape_params_pan.Controls.Add(this.vertices_lbl);
			this.shape_params_pan.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.shape_params_pan.Location = new System.Drawing.Point(-1, 1);
			this.shape_params_pan.Name = "shape_params_pan";
			this.shape_params_pan.Size = new System.Drawing.Size(568, 344);
			this.shape_params_pan.TabIndex = 8;
			// 
			// penColor
			// 
			this.penColor.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
			this.penColor.Location = new System.Drawing.Point(4, 228);
			this.penColor.Name = "penColor";
			this.penColor.Size = new System.Drawing.Size(220, 34);
			this.penColor.TabIndex = 18;
			this.penColor.Text = "#FF8000";
			this.penColor.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// shapePic
			// 
			this.shapePic.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.shapePic.Location = new System.Drawing.Point(232, 6);
			this.shapePic.Name = "shapePic";
			this.shapePic.Size = new System.Drawing.Size(330, 330);
			this.shapePic.TabIndex = 17;
			this.shapePic.TabStop = false;
			this.shapePic.WaitOnLoad = true;
			this.shapePic.Paint += new System.Windows.Forms.PaintEventHandler(this.shapePic_Paint);
			// 
			// fm_info
			// 
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
			this.ClientSize = new System.Drawing.Size(567, 346);
			this.Controls.Add(this.shape_params_pan);
			this.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.Name = "fm_info";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Shape info";
			this.Load += new System.EventHandler(this.fm_info_Load);
			this.shape_params_pan.ResumeLayout(false);
			this.shape_params_pan.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.shapePic)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Label vertices_lbl;
		internal System.Windows.Forms.TextBox sideW_tb;
		internal System.Windows.Forms.Label sideW_lbl;
		internal System.Windows.Forms.TextBox sideH_tb;
		private System.Windows.Forms.Label name_lbl;
		internal System.Windows.Forms.TextBox name_tb;
		internal System.Windows.Forms.Label sideH_lbl;
		internal System.Windows.Forms.ListBox vertexList;
		private System.Windows.Forms.Label type_lbl;
		internal System.Windows.Forms.TextBox type_tb;
		private System.Windows.Forms.Panel shape_params_pan;
		private System.Windows.Forms.PictureBox shapePic;
		private System.Windows.Forms.Label penColor;
	}
}