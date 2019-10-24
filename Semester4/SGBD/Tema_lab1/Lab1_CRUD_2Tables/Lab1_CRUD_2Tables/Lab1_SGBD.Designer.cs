namespace Lab1_CRUD_2Tables
{
    partial class Lab1_SGBD
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
            this.addrGridView = new System.Windows.Forms.DataGridView();
            this.providerGridView = new System.Windows.Forms.DataGridView();
            this.ParentTableLabel = new System.Windows.Forms.Label();
            this.ChildTableLabel = new System.Windows.Forms.Label();
            this.showAdrBtn = new System.Windows.Forms.Button();
            this.providerLbl = new System.Windows.Forms.Label();
            this.nameLbl = new System.Windows.Forms.Label();
            this.quantLbl = new System.Windows.Forms.Label();
            this.providerNameTxt = new System.Windows.Forms.TextBox();
            this.providerQuantityTxt = new System.Windows.Forms.TextBox();
            this.updBtn = new System.Windows.Forms.Button();
            this.delBtn = new System.Windows.Forms.Button();
            this.AddBtn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.addrGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.providerGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // addrGridView
            // 
            this.addrGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.addrGridView.Location = new System.Drawing.Point(25, 91);
            this.addrGridView.Name = "addrGridView";
            this.addrGridView.Size = new System.Drawing.Size(481, 528);
            this.addrGridView.TabIndex = 0;
            this.addrGridView.SelectionChanged += new System.EventHandler(this.addrGridView_SelectionChanged);
            // 
            // providerGridView
            // 
            this.providerGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.providerGridView.Location = new System.Drawing.Point(622, 91);
            this.providerGridView.Name = "providerGridView";
            this.providerGridView.Size = new System.Drawing.Size(510, 528);
            this.providerGridView.TabIndex = 1;
            this.providerGridView.SelectionChanged += new System.EventHandler(this.providerGridView_SelectionChanged);
            // 
            // ParentTableLabel
            // 
            this.ParentTableLabel.AutoSize = true;
            this.ParentTableLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ParentTableLabel.Location = new System.Drawing.Point(192, 37);
            this.ParentTableLabel.Name = "ParentTableLabel";
            this.ParentTableLabel.Size = new System.Drawing.Size(114, 31);
            this.ParentTableLabel.TabIndex = 2;
            this.ParentTableLabel.Text = "Address";
            // 
            // ChildTableLabel
            // 
            this.ChildTableLabel.AutoSize = true;
            this.ChildTableLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ChildTableLabel.Location = new System.Drawing.Point(811, 37);
            this.ChildTableLabel.Name = "ChildTableLabel";
            this.ChildTableLabel.Size = new System.Drawing.Size(115, 31);
            this.ChildTableLabel.TabIndex = 3;
            this.ChildTableLabel.Text = "Provider";
            // 
            // showAdrBtn
            // 
            this.showAdrBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.showAdrBtn.Location = new System.Drawing.Point(1242, 91);
            this.showAdrBtn.Name = "showAdrBtn";
            this.showAdrBtn.Size = new System.Drawing.Size(153, 37);
            this.showAdrBtn.TabIndex = 4;
            this.showAdrBtn.Text = "Show Addresses";
            this.showAdrBtn.UseVisualStyleBackColor = true;
            this.showAdrBtn.Click += new System.EventHandler(this.showAdrBtn_Click);
            // 
            // providerLbl
            // 
            this.providerLbl.AutoSize = true;
            this.providerLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.providerLbl.Location = new System.Drawing.Point(1280, 167);
            this.providerLbl.Name = "providerLbl";
            this.providerLbl.Size = new System.Drawing.Size(88, 24);
            this.providerLbl.TabIndex = 5;
            this.providerLbl.Text = "Provider";
            // 
            // nameLbl
            // 
            this.nameLbl.AutoSize = true;
            this.nameLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nameLbl.Location = new System.Drawing.Point(1173, 220);
            this.nameLbl.Name = "nameLbl";
            this.nameLbl.Size = new System.Drawing.Size(53, 16);
            this.nameLbl.TabIndex = 6;
            this.nameLbl.Text = "Name:";
            // 
            // quantLbl
            // 
            this.quantLbl.AutoSize = true;
            this.quantLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.quantLbl.Location = new System.Drawing.Point(1173, 263);
            this.quantLbl.Name = "quantLbl";
            this.quantLbl.Size = new System.Drawing.Size(72, 16);
            this.quantLbl.TabIndex = 7;
            this.quantLbl.Text = "Quantity: ";
            // 
            // providerNameTxt
            // 
            this.providerNameTxt.Location = new System.Drawing.Point(1259, 215);
            this.providerNameTxt.Name = "providerNameTxt";
            this.providerNameTxt.Size = new System.Drawing.Size(136, 20);
            this.providerNameTxt.TabIndex = 8;
            // 
            // providerQuantityTxt
            // 
            this.providerQuantityTxt.Location = new System.Drawing.Point(1259, 259);
            this.providerQuantityTxt.Name = "providerQuantityTxt";
            this.providerQuantityTxt.Size = new System.Drawing.Size(136, 20);
            this.providerQuantityTxt.TabIndex = 9;
            // 
            // updBtn
            // 
            this.updBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.updBtn.Location = new System.Drawing.Point(1164, 321);
            this.updBtn.Name = "updBtn";
            this.updBtn.Size = new System.Drawing.Size(95, 34);
            this.updBtn.TabIndex = 11;
            this.updBtn.Text = "Update";
            this.updBtn.UseVisualStyleBackColor = true;
            this.updBtn.Click += new System.EventHandler(this.providerAddBtn_Click);
            // 
            // delBtn
            // 
            this.delBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.delBtn.Location = new System.Drawing.Point(1335, 321);
            this.delBtn.Name = "delBtn";
            this.delBtn.Size = new System.Drawing.Size(95, 34);
            this.delBtn.TabIndex = 12;
            this.delBtn.Text = "Delete";
            this.delBtn.UseVisualStyleBackColor = true;
            this.delBtn.Click += new System.EventHandler(this.delBtn_Click);
            // 
            // AddBtn
            // 
            this.AddBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AddBtn.Location = new System.Drawing.Point(1259, 394);
            this.AddBtn.Name = "AddBtn";
            this.AddBtn.Size = new System.Drawing.Size(95, 34);
            this.AddBtn.TabIndex = 13;
            this.AddBtn.Text = "Add";
            this.AddBtn.UseVisualStyleBackColor = true;
            this.AddBtn.Click += new System.EventHandler(this.AddBtn_Click);
            // 
            // Lab1_SGBD
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1442, 651);
            this.Controls.Add(this.AddBtn);
            this.Controls.Add(this.delBtn);
            this.Controls.Add(this.updBtn);
            this.Controls.Add(this.providerQuantityTxt);
            this.Controls.Add(this.providerNameTxt);
            this.Controls.Add(this.quantLbl);
            this.Controls.Add(this.nameLbl);
            this.Controls.Add(this.providerLbl);
            this.Controls.Add(this.showAdrBtn);
            this.Controls.Add(this.ChildTableLabel);
            this.Controls.Add(this.ParentTableLabel);
            this.Controls.Add(this.providerGridView);
            this.Controls.Add(this.addrGridView);
            this.Name = "Lab1_SGBD";
            this.Text = "Lab1SGBD";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.addrGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.providerGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView addrGridView;
        private System.Windows.Forms.DataGridView providerGridView;
        private System.Windows.Forms.Label ParentTableLabel;
        private System.Windows.Forms.Label ChildTableLabel;
        private System.Windows.Forms.Button showAdrBtn;
        private System.Windows.Forms.Label providerLbl;
        private System.Windows.Forms.Label nameLbl;
        private System.Windows.Forms.Label quantLbl;
        private System.Windows.Forms.TextBox providerNameTxt;
        private System.Windows.Forms.TextBox providerQuantityTxt;
        private System.Windows.Forms.Button updBtn;
        private System.Windows.Forms.Button delBtn;
        private System.Windows.Forms.Button AddBtn;
    }
}

