namespace UdpClient_Simulator
{
    partial class Form1
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
            this.SendBtn = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SendMsg = new System.Windows.Forms.TextBox();
            this.sendedMsg = new System.Windows.Forms.TextBox();
            this.sendFromTexbox = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // SendBtn
            // 
            this.SendBtn.Location = new System.Drawing.Point(40, 112);
            this.SendBtn.Name = "SendBtn";
            this.SendBtn.Size = new System.Drawing.Size(75, 23);
            this.SendBtn.TabIndex = 0;
            this.SendBtn.Text = "Send";
            this.SendBtn.UseVisualStyleBackColor = true;
            this.SendBtn.Click += new System.EventHandler(this.sendFromFile);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(153, 112);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "load data";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.loadData);
            // 
            // SendMsg
            // 
            this.SendMsg.Location = new System.Drawing.Point(40, 200);
            this.SendMsg.Multiline = true;
            this.SendMsg.Name = "SendMsg";
            this.SendMsg.Size = new System.Drawing.Size(500, 450);
            this.SendMsg.TabIndex = 2;
            // 
            // sendedMsg
            // 
            this.sendedMsg.Location = new System.Drawing.Point(640, 200);
            this.sendedMsg.Multiline = true;
            this.sendedMsg.Name = "sendedMsg";
            this.sendedMsg.Size = new System.Drawing.Size(500, 450);
            this.sendedMsg.TabIndex = 3;
            // 
            // sendFromTexbox
            // 
            this.sendFromTexbox.Location = new System.Drawing.Point(40, 153);
            this.sendFromTexbox.Name = "sendFromTexbox";
            this.sendFromTexbox.Size = new System.Drawing.Size(75, 23);
            this.sendFromTexbox.TabIndex = 4;
            this.sendFromTexbox.Text = "Send Box";
            this.sendFromTexbox.UseVisualStyleBackColor = true;
            this.sendFromTexbox.Click += new System.EventHandler(this.sendFromTextbox_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.ClientSize = new System.Drawing.Size(1184, 761);
            this.Controls.Add(this.sendFromTexbox);
            this.Controls.Add(this.sendedMsg);
            this.Controls.Add(this.SendMsg);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.SendBtn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button SendBtn;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox SendMsg;
        private System.Windows.Forms.TextBox sendedMsg;
        private System.Windows.Forms.Button sendFromTexbox;
    }
}

