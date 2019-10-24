namespace Lab2_Festival.Forms
{
    partial class MainForm
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
            this.mainTable = new System.Windows.Forms.DataGridView();
            this.ConcertDatePicker = new System.Windows.Forms.DateTimePicker();
            this.ShowConcertsBtn = new System.Windows.Forms.Button();
            this.SellTicketsButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.ClientName = new System.Windows.Forms.TextBox();
            this.NumTickets = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.mainTable)).BeginInit();
            this.SuspendLayout();
            // 
            // mainTable
            // 
            this.mainTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.mainTable.Location = new System.Drawing.Point(36, 94);
            this.mainTable.Name = "mainTable";
            this.mainTable.Size = new System.Drawing.Size(683, 534);
            this.mainTable.TabIndex = 0;
            // 
            // ConcertDatePicker
            // 
            this.ConcertDatePicker.Location = new System.Drawing.Point(853, 94);
            this.ConcertDatePicker.Name = "ConcertDatePicker";
            this.ConcertDatePicker.Size = new System.Drawing.Size(200, 20);
            this.ConcertDatePicker.TabIndex = 1;
            // 
            // ShowConcertsBtn
            // 
            this.ShowConcertsBtn.Location = new System.Drawing.Point(853, 148);
            this.ShowConcertsBtn.Name = "ShowConcertsBtn";
            this.ShowConcertsBtn.Size = new System.Drawing.Size(116, 37);
            this.ShowConcertsBtn.TabIndex = 2;
            this.ShowConcertsBtn.Text = "Show Concerts!";
            this.ShowConcertsBtn.UseVisualStyleBackColor = true;
            this.ShowConcertsBtn.Click += new System.EventHandler(this.ShowConcertsBtn_Click);
            // 
            // SellTicketsButton
            // 
            this.SellTicketsButton.Location = new System.Drawing.Point(853, 543);
            this.SellTicketsButton.Name = "SellTicketsButton";
            this.SellTicketsButton.Size = new System.Drawing.Size(116, 37);
            this.SellTicketsButton.TabIndex = 3;
            this.SellTicketsButton.Text = "SellTickets!";
            this.SellTicketsButton.UseVisualStyleBackColor = true;
            this.SellTicketsButton.Click += new System.EventHandler(this.SellTicketsButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(850, 433);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "NumTickets:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(850, 381);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "ClientName:";
            // 
            // ClientName
            // 
            this.ClientName.Location = new System.Drawing.Point(933, 381);
            this.ClientName.Name = "ClientName";
            this.ClientName.Size = new System.Drawing.Size(100, 20);
            this.ClientName.TabIndex = 6;
            // 
            // NumTickets
            // 
            this.NumTickets.Location = new System.Drawing.Point(933, 433);
            this.NumTickets.Name = "NumTickets";
            this.NumTickets.Size = new System.Drawing.Size(44, 20);
            this.NumTickets.TabIndex = 7;
            this.NumTickets.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1133, 654);
            this.Controls.Add(this.NumTickets);
            this.Controls.Add(this.ClientName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SellTicketsButton);
            this.Controls.Add(this.ShowConcertsBtn);
            this.Controls.Add(this.ConcertDatePicker);
            this.Controls.Add(this.mainTable);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.Click += new System.EventHandler(this.MainForm_Click);
            ((System.ComponentModel.ISupportInitialize)(this.mainTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView mainTable;
        private System.Windows.Forms.DateTimePicker ConcertDatePicker;
        private System.Windows.Forms.Button ShowConcertsBtn;
        private System.Windows.Forms.Button SellTicketsButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox ClientName;
        private System.Windows.Forms.TextBox NumTickets;
    }
}