namespace Coursework_WinForms {
	partial class fm_main {
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
			this.shapeList = new System.Windows.Forms.ListBox();
			this.actions_label = new System.Windows.Forms.Label();
			this.shapes_label = new System.Windows.Forms.Label();
			this.saveDialog = new System.Windows.Forms.SaveFileDialog();
			this.canvas = new System.Windows.Forms.PictureBox();
			this.canvas_label = new System.Windows.Forms.Label();
			this.openDialog = new System.Windows.Forms.OpenFileDialog();
			this.flowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
			this.create_gr = new System.Windows.Forms.GroupBox();
			this.create_sq_btn = new System.Windows.Forms.Button();
			this.create_rec_btn = new System.Windows.Forms.Button();
			this.edit_gr = new System.Windows.Forms.GroupBox();
			this.edit_mv_btn = new System.Windows.Forms.Button();
			this.edit_rm_btn = new System.Windows.Forms.Button();
			this.clear_btn = new System.Windows.Forms.Button();
			this.info_gr = new System.Windows.Forms.GroupBox();
			this.showMaxSq_btn = new System.Windows.Forms.Button();
			this.file_gr = new System.Windows.Forms.GroupBox();
			this.file_save_txt = new System.Windows.Forms.Button();
			this.file_load_json_btn = new System.Windows.Forms.Button();
			this.file_save_json_btn = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.canvas)).BeginInit();
			this.flowLayoutPanel.SuspendLayout();
			this.create_gr.SuspendLayout();
			this.edit_gr.SuspendLayout();
			this.info_gr.SuspendLayout();
			this.file_gr.SuspendLayout();
			this.SuspendLayout();
			// 
			// shapeList
			// 
			this.shapeList.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
			this.shapeList.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.shapeList.FormattingEnabled = true;
			this.shapeList.IntegralHeight = false;
			this.shapeList.ItemHeight = 21;
			this.shapeList.Location = new System.Drawing.Point(235, 41);
			this.shapeList.Margin = new System.Windows.Forms.Padding(4);
			this.shapeList.Name = "shapeList";
			this.shapeList.Size = new System.Drawing.Size(200, 456);
			this.shapeList.TabIndex = 0;
			this.shapeList.DoubleClick += new System.EventHandler(this.shape_list_DoubleClick);
			this.shapeList.KeyDown += new System.Windows.Forms.KeyEventHandler(this.shapeList_KeyDown);
			// 
			// actions_label
			// 
			this.actions_label.BackColor = System.Drawing.Color.AliceBlue;
			this.actions_label.Font = new System.Drawing.Font("Segoe UI", 12.5F, System.Drawing.FontStyle.Bold);
			this.actions_label.Location = new System.Drawing.Point(0, 0);
			this.actions_label.Margin = new System.Windows.Forms.Padding(4);
			this.actions_label.Name = "actions_label";
			this.actions_label.Size = new System.Drawing.Size(234, 40);
			this.actions_label.TabIndex = 3;
			this.actions_label.Text = "Actions";
			this.actions_label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// shapes_label
			// 
			this.shapes_label.BackColor = System.Drawing.Color.AliceBlue;
			this.shapes_label.Font = new System.Drawing.Font("Segoe UI", 12.5F, System.Drawing.FontStyle.Bold);
			this.shapes_label.Location = new System.Drawing.Point(235, 0);
			this.shapes_label.Margin = new System.Windows.Forms.Padding(4);
			this.shapes_label.Name = "shapes_label";
			this.shapes_label.Size = new System.Drawing.Size(200, 40);
			this.shapes_label.TabIndex = 4;
			this.shapes_label.Text = "Shapes (0)";
			this.shapes_label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// canvas
			// 
			this.canvas.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.canvas.Location = new System.Drawing.Point(438, 45);
			this.canvas.Name = "canvas";
			this.canvas.Size = new System.Drawing.Size(450, 450);
			this.canvas.TabIndex = 9;
			this.canvas.TabStop = false;
			this.canvas.WaitOnLoad = true;
			this.canvas.Paint += new System.Windows.Forms.PaintEventHandler(this.shapePics_Paint);
			// 
			// canvas_label
			// 
			this.canvas_label.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.canvas_label.BackColor = System.Drawing.Color.AliceBlue;
			this.canvas_label.Font = new System.Drawing.Font("Segoe UI", 12.5F, System.Drawing.FontStyle.Bold);
			this.canvas_label.Location = new System.Drawing.Point(436, 0);
			this.canvas_label.Margin = new System.Windows.Forms.Padding(4);
			this.canvas_label.Name = "canvas_label";
			this.canvas_label.Size = new System.Drawing.Size(453, 40);
			this.canvas_label.TabIndex = 10;
			this.canvas_label.Text = "Canvas (X and Y 0–500)";
			this.canvas_label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// openDialog
			// 
			this.openDialog.FileName = "openFileDialog1";
			this.openDialog.Filter = "JSON (*.json)|*.json";
			// 
			// flowLayoutPanel
			// 
			this.flowLayoutPanel.AutoScroll = true;
			this.flowLayoutPanel.Controls.Add(this.create_gr);
			this.flowLayoutPanel.Controls.Add(this.edit_gr);
			this.flowLayoutPanel.Controls.Add(this.info_gr);
			this.flowLayoutPanel.Controls.Add(this.file_gr);
			this.flowLayoutPanel.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
			this.flowLayoutPanel.Location = new System.Drawing.Point(0, 41);
			this.flowLayoutPanel.Name = "flowLayoutPanel";
			this.flowLayoutPanel.Size = new System.Drawing.Size(230, 456);
			this.flowLayoutPanel.TabIndex = 12;
			this.flowLayoutPanel.WrapContents = false;
			// 
			// create_gr
			// 
			this.create_gr.AutoSize = true;
			this.create_gr.BackColor = System.Drawing.SystemColors.Control;
			this.create_gr.Controls.Add(this.create_sq_btn);
			this.create_gr.Controls.Add(this.create_rec_btn);
			this.create_gr.Font = new System.Drawing.Font("Segoe UI Semibold", 12F, System.Drawing.FontStyle.Bold);
			this.create_gr.ForeColor = System.Drawing.SystemColors.WindowText;
			this.create_gr.Location = new System.Drawing.Point(3, 3);
			this.create_gr.Name = "create_gr";
			this.create_gr.Size = new System.Drawing.Size(206, 122);
			this.create_gr.TabIndex = 6;
			this.create_gr.TabStop = false;
			this.create_gr.Text = "Create";
			// 
			// create_sq_btn
			// 
			this.create_sq_btn.Font = new System.Drawing.Font("Segoe UI Semibold", 12F);
			this.create_sq_btn.Location = new System.Drawing.Point(5, 24);
			this.create_sq_btn.Name = "create_sq_btn";
			this.create_sq_btn.Size = new System.Drawing.Size(195, 34);
			this.create_sq_btn.TabIndex = 0;
			this.create_sq_btn.Text = "Square";
			this.create_sq_btn.UseVisualStyleBackColor = true;
			this.create_sq_btn.Click += new System.EventHandler(this.crate_sq_btn_Click);
			// 
			// create_rec_btn
			// 
			this.create_rec_btn.Font = new System.Drawing.Font("Segoe UI Semibold", 12F);
			this.create_rec_btn.Location = new System.Drawing.Point(5, 60);
			this.create_rec_btn.Name = "create_rec_btn";
			this.create_rec_btn.Size = new System.Drawing.Size(195, 34);
			this.create_rec_btn.TabIndex = 1;
			this.create_rec_btn.Text = "Rectangle";
			this.create_rec_btn.UseVisualStyleBackColor = true;
			this.create_rec_btn.Click += new System.EventHandler(this.create_rec_btn_Click);
			// 
			// edit_gr
			// 
			this.edit_gr.AutoSize = true;
			this.edit_gr.BackColor = System.Drawing.SystemColors.Control;
			this.edit_gr.Controls.Add(this.edit_mv_btn);
			this.edit_gr.Controls.Add(this.edit_rm_btn);
			this.edit_gr.Controls.Add(this.clear_btn);
			this.edit_gr.Font = new System.Drawing.Font("Segoe UI Semibold", 12F);
			this.edit_gr.ForeColor = System.Drawing.SystemColors.WindowText;
			this.edit_gr.Location = new System.Drawing.Point(3, 131);
			this.edit_gr.Name = "edit_gr";
			this.edit_gr.Size = new System.Drawing.Size(206, 158);
			this.edit_gr.TabIndex = 7;
			this.edit_gr.TabStop = false;
			this.edit_gr.Text = "Edit";
			// 
			// edit_mv_btn
			// 
			this.edit_mv_btn.Location = new System.Drawing.Point(5, 20);
			this.edit_mv_btn.Name = "edit_mv_btn";
			this.edit_mv_btn.Size = new System.Drawing.Size(195, 34);
			this.edit_mv_btn.TabIndex = 2;
			this.edit_mv_btn.Text = "Move selected";
			this.edit_mv_btn.UseVisualStyleBackColor = true;
			this.edit_mv_btn.Click += new System.EventHandler(this.edit_mv_btn_Click);
			// 
			// edit_rm_btn
			// 
			this.edit_rm_btn.Location = new System.Drawing.Point(5, 58);
			this.edit_rm_btn.Name = "edit_rm_btn";
			this.edit_rm_btn.Size = new System.Drawing.Size(195, 34);
			this.edit_rm_btn.TabIndex = 3;
			this.edit_rm_btn.Text = "Remove selected";
			this.edit_rm_btn.UseVisualStyleBackColor = true;
			this.edit_rm_btn.Click += new System.EventHandler(this.edit_rm_btn_Click);
			// 
			// clear_btn
			// 
			this.clear_btn.Location = new System.Drawing.Point(5, 96);
			this.clear_btn.Name = "clear_btn";
			this.clear_btn.Size = new System.Drawing.Size(195, 34);
			this.clear_btn.TabIndex = 4;
			this.clear_btn.Text = "Clear all";
			this.clear_btn.UseVisualStyleBackColor = true;
			this.clear_btn.Click += new System.EventHandler(this.clear_btn_Click);
			// 
			// info_gr
			// 
			this.info_gr.AutoSize = true;
			this.info_gr.BackColor = System.Drawing.SystemColors.Control;
			this.info_gr.Controls.Add(this.showMaxSq_btn);
			this.info_gr.Font = new System.Drawing.Font("Segoe UI Semibold", 12F);
			this.info_gr.ForeColor = System.Drawing.SystemColors.WindowText;
			this.info_gr.Location = new System.Drawing.Point(3, 295);
			this.info_gr.Name = "info_gr";
			this.info_gr.Size = new System.Drawing.Size(206, 86);
			this.info_gr.TabIndex = 10;
			this.info_gr.TabStop = false;
			this.info_gr.Text = "Info";
			// 
			// showMaxSq_btn
			// 
			this.showMaxSq_btn.Location = new System.Drawing.Point(5, 24);
			this.showMaxSq_btn.Name = "showMaxSq_btn";
			this.showMaxSq_btn.Size = new System.Drawing.Size(195, 34);
			this.showMaxSq_btn.TabIndex = 5;
			this.showMaxSq_btn.Text = "Show max square";
			this.showMaxSq_btn.UseVisualStyleBackColor = true;
			this.showMaxSq_btn.Click += new System.EventHandler(this.showMaxSq_btn_Click);
			// 
			// file_gr
			// 
			this.file_gr.AutoSize = true;
			this.file_gr.BackColor = System.Drawing.SystemColors.Control;
			this.file_gr.Controls.Add(this.file_save_txt);
			this.file_gr.Controls.Add(this.file_load_json_btn);
			this.file_gr.Controls.Add(this.file_save_json_btn);
			this.file_gr.Font = new System.Drawing.Font("Segoe UI Semibold", 12F);
			this.file_gr.ForeColor = System.Drawing.SystemColors.WindowText;
			this.file_gr.Location = new System.Drawing.Point(3, 387);
			this.file_gr.Name = "file_gr";
			this.file_gr.Size = new System.Drawing.Size(206, 158);
			this.file_gr.TabIndex = 9;
			this.file_gr.TabStop = false;
			this.file_gr.Text = "File";
			// 
			// file_save_txt
			// 
			this.file_save_txt.Location = new System.Drawing.Point(5, 96);
			this.file_save_txt.Name = "file_save_txt";
			this.file_save_txt.Size = new System.Drawing.Size(195, 34);
			this.file_save_txt.TabIndex = 8;
			this.file_save_txt.Text = "Save as txt";
			this.file_save_txt.UseVisualStyleBackColor = true;
			this.file_save_txt.Click += new System.EventHandler(this.file_save_txt_Click);
			// 
			// file_load_json_btn
			// 
			this.file_load_json_btn.Location = new System.Drawing.Point(5, 24);
			this.file_load_json_btn.Name = "file_load_json_btn";
			this.file_load_json_btn.Size = new System.Drawing.Size(195, 34);
			this.file_load_json_btn.TabIndex = 6;
			this.file_load_json_btn.Text = "Load from json";
			this.file_load_json_btn.UseVisualStyleBackColor = true;
			this.file_load_json_btn.Click += new System.EventHandler(this.file_load_json_btn_Click);
			// 
			// file_save_json_btn
			// 
			this.file_save_json_btn.Location = new System.Drawing.Point(5, 60);
			this.file_save_json_btn.Name = "file_save_json_btn";
			this.file_save_json_btn.Size = new System.Drawing.Size(195, 34);
			this.file_save_json_btn.TabIndex = 7;
			this.file_save_json_btn.Text = "Save as json";
			this.file_save_json_btn.UseVisualStyleBackColor = true;
			this.file_save_json_btn.Click += new System.EventHandler(this.file_save_json_btn_Click);
			// 
			// fm_main
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 21F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.SystemColors.Control;
			this.ClientSize = new System.Drawing.Size(890, 498);
			this.Controls.Add(this.flowLayoutPanel);
			this.Controls.Add(this.canvas_label);
			this.Controls.Add(this.canvas);
			this.Controls.Add(this.shapeList);
			this.Controls.Add(this.actions_label);
			this.Controls.Add(this.shapes_label);
			this.Font = new System.Drawing.Font("Segoe UI", 12F);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Margin = new System.Windows.Forms.Padding(5);
			this.MaximizeBox = false;
			this.Name = "fm_main";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Shape Creator by Остап Гайванович";
			((System.ComponentModel.ISupportInitialize)(this.canvas)).EndInit();
			this.flowLayoutPanel.ResumeLayout(false);
			this.flowLayoutPanel.PerformLayout();
			this.create_gr.ResumeLayout(false);
			this.edit_gr.ResumeLayout(false);
			this.info_gr.ResumeLayout(false);
			this.file_gr.ResumeLayout(false);
			this.ResumeLayout(false);

		}

		#endregion
		private System.Windows.Forms.Label actions_label;
		internal System.Windows.Forms.ListBox shapeList;
		internal System.Windows.Forms.Label shapes_label;
		private System.Windows.Forms.SaveFileDialog saveDialog;
		internal System.Windows.Forms.Label canvas_label;
		private System.Windows.Forms.OpenFileDialog openDialog;
		private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel;
		private System.Windows.Forms.GroupBox create_gr;
		private System.Windows.Forms.Button create_sq_btn;
		private System.Windows.Forms.Button create_rec_btn;
		private System.Windows.Forms.GroupBox edit_gr;
		private System.Windows.Forms.Button edit_mv_btn;
		private System.Windows.Forms.Button edit_rm_btn;
		private System.Windows.Forms.Button clear_btn;
		private System.Windows.Forms.GroupBox file_gr;
		private System.Windows.Forms.Button file_save_txt;
		private System.Windows.Forms.Button file_load_json_btn;
		private System.Windows.Forms.Button file_save_json_btn;
		private System.Windows.Forms.GroupBox info_gr;
		private System.Windows.Forms.Button showMaxSq_btn;
		internal System.Windows.Forms.PictureBox canvas;
	}
}

