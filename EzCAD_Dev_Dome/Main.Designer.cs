namespace EzCAD_Dev_Dome
{
    partial class Main_Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.config_gBox = new System.Windows.Forms.GroupBox();
            this.redline_btn = new System.Windows.Forms.Button();
            this.preview_btn = new System.Windows.Forms.Button();
            this.mark_btn = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox = new System.Windows.Forms.TextBox();
            this.cancel_btn = new System.Windows.Forms.Button();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.openFilebtn = new System.Windows.Forms.Button();
            this.fileNametBox = new System.Windows.Forms.TextBox();
            this.config_gBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // config_gBox
            // 
            this.config_gBox.Controls.Add(this.redline_btn);
            this.config_gBox.Controls.Add(this.preview_btn);
            this.config_gBox.Controls.Add(this.mark_btn);
            this.config_gBox.Controls.Add(this.label2);
            this.config_gBox.Controls.Add(this.textBox);
            this.config_gBox.Controls.Add(this.cancel_btn);
            this.config_gBox.Controls.Add(this.pictureBox);
            this.config_gBox.Controls.Add(this.label1);
            this.config_gBox.Controls.Add(this.openFilebtn);
            this.config_gBox.Controls.Add(this.fileNametBox);
            this.config_gBox.Location = new System.Drawing.Point(10, 9);
            this.config_gBox.Name = "config_gBox";
            this.config_gBox.Size = new System.Drawing.Size(640, 670);
            this.config_gBox.TabIndex = 220;
            this.config_gBox.TabStop = false;
            this.config_gBox.Text = "参数配置";
            // 
            // redline_btn
            // 
            this.redline_btn.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.redline_btn.Location = new System.Drawing.Point(357, 516);
            this.redline_btn.Name = "redline_btn";
            this.redline_btn.Size = new System.Drawing.Size(166, 54);
            this.redline_btn.TabIndex = 227;
            this.redline_btn.Tag = "0";
            this.redline_btn.Text = "红光对标";
            this.redline_btn.UseVisualStyleBackColor = true;
            this.redline_btn.Click += new System.EventHandler(this.redline_btn_Click);
            // 
            // preview_btn
            // 
            this.preview_btn.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.preview_btn.Location = new System.Drawing.Point(115, 516);
            this.preview_btn.Name = "preview_btn";
            this.preview_btn.Size = new System.Drawing.Size(166, 54);
            this.preview_btn.TabIndex = 226;
            this.preview_btn.Tag = "0";
            this.preview_btn.Text = "生成预览";
            this.preview_btn.UseVisualStyleBackColor = true;
            this.preview_btn.Click += new System.EventHandler(this.preview_btn_Click);
            // 
            // mark_btn
            // 
            this.mark_btn.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.mark_btn.Location = new System.Drawing.Point(115, 598);
            this.mark_btn.Name = "mark_btn";
            this.mark_btn.Size = new System.Drawing.Size(166, 54);
            this.mark_btn.TabIndex = 225;
            this.mark_btn.Tag = "0";
            this.mark_btn.Text = "启动雕刻";
            this.mark_btn.UseVisualStyleBackColor = true;
            this.mark_btn.Click += new System.EventHandler(this.mark_btn_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(46, 460);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(137, 27);
            this.label2.TabIndex = 224;
            this.label2.Text = "要雕刻的数据:";
            // 
            // textBox
            // 
            this.textBox.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox.Location = new System.Drawing.Point(200, 458);
            this.textBox.Name = "textBox";
            this.textBox.Size = new System.Drawing.Size(392, 34);
            this.textBox.TabIndex = 223;
            // 
            // cancel_btn
            // 
            this.cancel_btn.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.cancel_btn.Location = new System.Drawing.Point(357, 598);
            this.cancel_btn.Name = "cancel_btn";
            this.cancel_btn.Size = new System.Drawing.Size(166, 54);
            this.cancel_btn.TabIndex = 222;
            this.cancel_btn.Tag = "0";
            this.cancel_btn.Text = "取消雕刻";
            this.cancel_btn.UseVisualStyleBackColor = true;
            this.cancel_btn.Click += new System.EventHandler(this.cancel_btn_Click);
            // 
            // pictureBox
            // 
            this.pictureBox.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.pictureBox.Location = new System.Drawing.Point(32, 106);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(560, 320);
            this.pictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pictureBox.TabIndex = 33;
            this.pictureBox.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 12);
            this.label1.TabIndex = 32;
            this.label1.Text = "选择丝印文件：";
            // 
            // openFilebtn
            // 
            this.openFilebtn.Font = new System.Drawing.Font("黑体", 6.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.openFilebtn.Location = new System.Drawing.Point(575, 52);
            this.openFilebtn.Name = "openFilebtn";
            this.openFilebtn.Size = new System.Drawing.Size(32, 21);
            this.openFilebtn.TabIndex = 1;
            this.openFilebtn.Text = "...";
            this.openFilebtn.UseVisualStyleBackColor = true;
            this.openFilebtn.Click += new System.EventHandler(this.openFilebtn_Click);
            // 
            // fileNametBox
            // 
            this.fileNametBox.Location = new System.Drawing.Point(21, 52);
            this.fileNametBox.Name = "fileNametBox";
            this.fileNametBox.Size = new System.Drawing.Size(548, 21);
            this.fileNametBox.TabIndex = 0;
            // 
            // Main_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(695, 691);
            this.Controls.Add(this.config_gBox);
            this.Name = "Main_Form";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "EzCad Dev Dome V0.1 (ospanic@qq.com)";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.ScinanLaserForm_FormClosed);
            this.Load += new System.EventHandler(this.Form_Load);
            this.config_gBox.ResumeLayout(false);
            this.config_gBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.GroupBox config_gBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button openFilebtn;
        private System.Windows.Forms.TextBox fileNametBox;
        public System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.TextBox textBox;
        private System.Windows.Forms.Button cancel_btn;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button redline_btn;
        private System.Windows.Forms.Button preview_btn;
        private System.Windows.Forms.Button mark_btn;
    }
}