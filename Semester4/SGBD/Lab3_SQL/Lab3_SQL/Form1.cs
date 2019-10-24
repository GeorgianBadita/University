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
    
namespace Lab3_SQL
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            SqlConnection sqlCon = new SqlConnection("Data Source=DESKTOP-EVCQN0H\\SQLEXPRESS;Initial Catalog=Diana;Integrated Security=True");
            SqlDataAdapter da = new SqlDataAdapter();
            
            InitializeComponent();
        }
    }
}
