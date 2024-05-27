namespace Coursework_WinForms {
	partial class fm_move {
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
			this.curVts_lb = new System.Windows.Forms.ListBox();
			this.picture_label = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.newVts_lb = new System.Windows.Forms.ListBox();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.cancel_btn = new System.Windows.Forms.Button();
			this.save_btn = new System.Windows.Forms.Button();
			this.vtxY_tb = new System.Windows.Forms.TextBox();
			this.vtxX_tb = new System.Windows.Forms.TextBox();
			this.vtxX_x_btn = new System.Windows.Forms.Button();
			this.vtxY_x_btn = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// curVts_lb
			// 
			this.curVts_lb.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.curVts_lb.FormattingEnabled = true;
			this.curVts_lb.ItemHeight = 21;
			this.curVts_lb.Location = new System.Drawing.Point(185, 40);
			this.curVts_lb.Name = "curVts_lb";
			this.curVts_lb.SelectionMode = System.Windows.Forms.SelectionMode.None;
			this.curVts_lb.Size = new System.Drawing.Size(176, 214);
			this.curVts_lb.TabIndex = 15;
			// 
			// picture_label
			// 
			this.picture_label.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.picture_label.BackColor = System.Drawing.Color.AliceBlue;
			this.picture_label.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold);
			this.picture_label.Location = new System.Drawing.Point(185, 0);
			this.picture_label.Margin = new System.Windows.Forms.Padding(4);
			this.picture_label.Name = "picture_label";
			this.picture_label.Size = new System.Drawing.Size(176, 40);
			this.picture_label.TabIndex = 16;
			this.picture_label.Text = "Current vertex list";
			this.picture_label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label1
			// 
			this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.label1.BackColor = System.Drawing.Color.AliceBlue;
			this.label1.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold);
			this.label1.Location = new System.Drawing.Point(361, 0);
			this.label1.Margin = new System.Windows.Forms.Padding(4);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(176, 40);
			this.label1.TabIndex = 18;
			this.label1.Text = "New vertex list";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// newVts_lb
			// 
			this.newVts_lb.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.newVts_lb.FormattingEnabled = true;
			this.newVts_lb.ItemHeight = 21;
			this.newVts_lb.Location = new System.Drawing.Point(360, 40);
			this.newVts_lb.Name = "newVts_lb";
			this.newVts_lb.SelectionMode = System.Windows.Forms.SelectionMode.None;
			this.newVts_lb.Size = new System.Drawing.Size(176, 214);
			this.newVts_lb.TabIndex = 17;
			// 
			// label2
			// 
			this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.label2.BackColor = System.Drawing.Color.AliceBlue;
			this.label2.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold);
			this.label2.Location = new System.Drawing.Point(8, 0);
			this.label2.Margin = new System.Windows.Forms.Padding(4);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(177, 40);
			this.label2.TabIndex = 19;
			this.label2.Text = "Vertex difference";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label3
			// 
			this.label3.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.label3.Location = new System.Drawing.Point(4, 82);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(25, 26);
			this.label3.TabIndex = 22;
			this.label3.Text = "y";
			this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label4
			// 
			this.label4.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.label4.Location = new System.Drawing.Point(4, 44);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(25, 26);
			this.label4.TabIndex = 20;
			this.label4.Text = "x";
			this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// cancel_btn
			// 
			this.cancel_btn.Location = new System.Drawing.Point(96, 220);
			this.cancel_btn.Name = "cancel_btn";
			this.cancel_btn.Size = new System.Drawing.Size(88, 34);
			this.cancel_btn.TabIndex = 24;
			this.cancel_btn.Text = "Cancel";
			this.cancel_btn.UseVisualStyleBackColor = true;
			this.cancel_btn.Click += new System.EventHandler(this.cancel_btn_Click);
			// 
			// save_btn
			// 
			this.save_btn.Location = new System.Drawing.Point(4, 220);
			this.save_btn.Name = "save_btn";
			this.save_btn.Size = new System.Drawing.Size(92, 34);
			this.save_btn.TabIndex = 25;
			this.save_btn.Text = "Save";
			this.save_btn.UseVisualStyleBackColor = true;
			this.save_btn.Click += new System.EventHandler(this.save_btn_Click);
			// 
			// vtxY_tb
			// 
			this.vtxY_tb.Location = new System.Drawing.Point(36, 79);
			this.vtxY_tb.Name = "vtxY_tb";
			this.vtxY_tb.Size = new System.Drawing.Size(148, 29);
			this.vtxY_tb.TabIndex = 27;
			this.vtxY_tb.Text = "0";
			this.vtxY_tb.TextChanged += new System.EventHandler(this.vtxY_tb_TextChanged);
			// 
			// vtxX_tb
			// 
			this.vtxX_tb.Location = new System.Drawing.Point(36, 44);
			this.vtxX_tb.Name = "vtxX_tb";
			this.vtxX_tb.Size = new System.Drawing.Size(148, 29);
			this.vtxX_tb.TabIndex = 26;
			this.vtxX_tb.Text = "0";
			this.vtxX_tb.TextChanged += new System.EventHandler(this.vtxX_tb_TextChanged);
			// 
			// vtxX_x_btn
			// 
			this.vtxX_x_btn.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.vtxX_x_btn.ForeColor = System.Drawing.Color.Red;
			this.vtxX_x_btn.Location = new System.Drawing.Point(156, 44);
			this.vtxX_x_btn.Name = "vtxX_x_btn";
			this.vtxX_x_btn.Size = new System.Drawing.Size(28, 27);
			this.vtxX_x_btn.TabIndex = 28;
			this.vtxX_x_btn.Text = "X";
			this.vtxX_x_btn.UseVisualStyleBackColor = true;
			this.vtxX_x_btn.Click += new System.EventHandler(this.vtxX_x_btn_Click);
			// 
			// vtxY_x_btn
			// 
			this.vtxY_x_btn.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.vtxY_x_btn.ForeColor = System.Drawing.Color.Red;
			this.vtxY_x_btn.Location = new System.Drawing.Point(156, 80);
			this.vtxY_x_btn.Name = "vtxY_x_btn";
			this.vtxY_x_btn.Size = new System.Drawing.Size(28, 27);
			this.vtxY_x_btn.TabIndex = 29;
			this.vtxY_x_btn.Text = "X";
			this.vtxY_x_btn.UseVisualStyleBackColor = true;
			this.vtxY_x_btn.Click += new System.EventHandler(this.vtxY_x_btn_Click);
			// 
			// fm_move
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 21F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(537, 255);
			this.Controls.Add(this.vtxY_x_btn);
			this.Controls.Add(this.vtxX_x_btn);
			this.Controls.Add(this.vtxY_tb);
			this.Controls.Add(this.vtxX_tb);
			this.Controls.Add(this.save_btn);
			this.Controls.Add(this.cancel_btn);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.newVts_lb);
			this.Controls.Add(this.picture_label);
			this.Controls.Add(this.curVts_lb);
			this.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
			this.MaximizeBox = false;
			this.Name = "fm_move";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Move shape";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		internal System.Windows.Forms.ListBox curVts_lb;
		internal System.Windows.Forms.Label picture_label;
		internal System.Windows.Forms.Label label1;
		internal System.Windows.Forms.ListBox newVts_lb;
		internal System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Button cancel_btn;
		private System.Windows.Forms.Button save_btn;
		internal System.Windows.Forms.TextBox vtxY_tb;
		internal System.Windows.Forms.TextBox vtxX_tb;
		private System.Windows.Forms.Button vtxX_x_btn;
		private System.Windows.Forms.Button vtxY_x_btn;
	}
}