using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data.SqlClient;

namespace Lab1_profa
{
    public partial class Form1 : Form
    {
        SqlConnection sqlCon = new SqlConnection("Data Source = DESKTOP-EVCQN0H\\SQLEXPRESS; Initial Catalog = Magazin; Integrated Security = True");
        SqlDataAdapter da = new SqlDataAdapter();
        DataSet ds = new DataSet();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           
            da.SelectCommand =  new SqlCommand("SELECT * FROM Client", sqlCon);
            ds.Clear();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
        }
    }
}
