namespace Lab2_Festival.Forms
{
    partial class Concerts
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
            this.concertTable = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.concertTable)).BeginInit();
            this.SuspendLayout();
            // 
            // concertTable
            // 
            this.concertTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.concertTable.Location = new System.Drawing.Point(76, 48);
            this.concertTable.Name = "concertTable";
            this.concertTable.Size = new System.Drawing.Size(683, 534);
            this.concertTable.TabIndex = 1;
            // 
            // Concerts
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(867, 616);
            this.Controls.Add(this.concertTable);
            this.Name = "Concerts";
            this.Text = "Concerts";
            ((System.ComponentModel.ISupportInitialize)(this.concertTable)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView concertTable;
    }
}