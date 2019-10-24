using Lab1_CRUD_2Tables.Domain.Entities;
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
using Lab1_CRUD_2Tables.Repository;
using Lab1_CRUD_2Tables.Domain.Validators;

namespace Lab1_CRUD_2Tables
{
    public partial class Lab1_SGBD : Form
    {
        string conn = "Data Source=DESKTOP-EVCQN0H\\SQLEXPRESS;Initial Catalog=My_lib;Integrated Security=True";
        SqlConnection sqlCon = new SqlConnection("Data Source=DESKTOP-EVCQN0H\\SQLEXPRESS;Initial Catalog=My_lib;Integrated Security=True");
        SqlDataAdapter da1 = new SqlDataAdapter();
        SqlDataAdapter da2 = new SqlDataAdapter();
        DataSet ds1 = new DataSet();
        DataSet ds2 = new DataSet();

        public Lab1_SGBD()
        {
       
            InitializeComponent();
            delBtn.Enabled = false;
            updBtn.Enabled = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public void print()
        {
            da1.SelectCommand = new SqlCommand("SELECT * FROM Adresa", sqlCon);
            ds1.Clear();
            da1.Fill(ds1);
            //dataGridView1.DataSource = ds.Tables[0]; 
        }

        public void insert()
        {
            SqlCommand cmd = new SqlCommand("INSERT INTO Adresa " + "(Oras, Strada, Numar) " +
              "VALUES (@Oras, @Strada, @Numar)", sqlCon);


            cmd.Parameters.Add("@Oras", SqlDbType.VarChar);
            cmd.Parameters.Add("@Strada", SqlDbType.VarChar);
            cmd.Parameters.Add("@Numar", SqlDbType.Int);


            cmd.Parameters["@Oras"].Value = "Valea seaca";
            cmd.Parameters["@Strada"].Value = "Strada1";
            cmd.Parameters["@Numar"].Value = Convert.ToInt32(18);

            sqlCon.Open();
            int RowsAffected = cmd.ExecuteNonQuery();
            //textBox1.Text = RowsAffected.ToString();
            sqlCon.Close();
        }

        public void delete()
        {
            SqlCommand cmd = new SqlCommand("DELETE FROM ADRESA " + "WHERE Id_Adr = @Id_Adr", sqlCon);

            cmd.Parameters.Add("@Id_Adr", SqlDbType.Int);

            cmd.Parameters["@Id_Adr"].Value = Convert.ToInt32(11);

            sqlCon.Open();
            cmd.ExecuteNonQuery();
            sqlCon.Close();
        }

        public void update()
        {
            SqlCommand cmd = new SqlCommand("UPDATE Adresa " + "SET Oras = @Oras, Strada = @Strada, Numar = @Numar " +
              "WHERE Id_Adr = @Id_Adr", sqlCon);

            cmd.Parameters.Add("@Id_Adr", SqlDbType.Int);
            cmd.Parameters.Add("@Oras", SqlDbType.VarChar);
            cmd.Parameters.Add("@Strada", SqlDbType.VarChar);
            cmd.Parameters.Add("@Numar", SqlDbType.Int);

            cmd.Parameters["@Id_Adr"].Value = Convert.ToInt32(1);
            cmd.Parameters["@Oras"].Value = "Valea seaca";
            cmd.Parameters["@Strada"].Value = "Strada1";
            cmd.Parameters["@Numar"].Value = Convert.ToInt32(18);

            sqlCon.Open();
            int RowsAffected = cmd.ExecuteNonQuery();

            //textBox1.Text = RowsAffected.ToString();
            sqlCon.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            var addrRepo = new AddressDBRepository(new AddressValidator(), conn);
            Address addr = new Address(12, "Valcea", "Ipatescu", 21);
            var retValue = addrRepo.Save(addr);
            sqlCon.Open();
            print();
            sqlCon.Close(); ///TODO: first search then insert
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void showAdrBtn_Click(object sender, EventArgs e)
        {
            sqlCon.Open();
            da1 = new SqlDataAdapter();
            ds1 = new DataSet();
            da1.SelectCommand = new SqlCommand("SELECT * FROM Adresa", sqlCon);
            ds1.Clear();
            da1.Fill(ds1);
            addrGridView.DataSource = ds1.Tables[0];
            sqlCon.Close();
        }

        private void addrGridView_SelectionChanged(object sender, EventArgs e)
        {
            var rowsCount = addrGridView.SelectedRows.Count;
            if (rowsCount == 0 || rowsCount > 1) return;

            var row = addrGridView.SelectedRows[0];
            var id = addrGridView.Rows[row.Index].Cells[0].Value;
            sqlCon.Open();
            ds2 = new DataSet();
            da1 = new SqlDataAdapter();
            SqlCommand cmd = new SqlCommand("SELECT * FROM Furnizor WHERE Id_adr = @id_adr", sqlCon);
            cmd.Parameters.Add("@id_adr", SqlDbType.Int);

            cmd.Parameters["@id_adr"].Value = Int32.Parse(id.ToString());

            da1.SelectCommand = cmd;
            ds2.Clear();
            da1.Fill(ds2);
            providerGridView.DataSource = ds2.Tables[0];
            sqlCon.Close();
        }

        private void providerGridView_SelectionChanged(object sender, EventArgs e)
        {
            var rowsCount = providerGridView.SelectedRows.Count;


            if (rowsCount != 1)
            {
                updBtn.Enabled = false;
                delBtn.Enabled = false;
                return;
            }

            updBtn.Enabled = true;
            delBtn.Enabled = true;
            var index = providerGridView.SelectedRows[0].Index;
            var name = providerGridView.Rows[index].Cells[1].Value.ToString();
            var cuant = providerGridView.Rows[index].Cells[2].Value.ToString();

            providerNameTxt.Text = name;
            providerQuantityTxt.Text = cuant;
        }

        private void providerAddBtn_Click(object sender, EventArgs e)
        {
            var rowsCount = providerGridView.SelectedRows.Count;


            if (rowsCount != 1)
            {
                return;
            }

           
            var index = providerGridView.SelectedRows[0].Index;
            var id = Int32.Parse(providerGridView.Rows[index].Cells[0].Value.ToString());
            var name = providerNameTxt.Text.ToString();
            var cuant = providerQuantityTxt.Text.ToString();

            sqlCon.Open();
            ds2 = new DataSet();
            da1 = new SqlDataAdapter();
            SqlCommand cmd = new SqlCommand("UPDATE Furnizor SET Nume=@nume, Cantitate=@cantitate WHERE Id_fur=@id_fur", sqlCon);
            cmd.Parameters.Add("@nume", SqlDbType.VarChar);
            cmd.Parameters.Add("@cantitate", SqlDbType.Int);
            cmd.Parameters.Add("@id_fur", SqlDbType.Int);


            cmd.Parameters["@id_fur"].Value = Int32.Parse(id.ToString());
            cmd.Parameters["@nume"].Value = name;
            cmd.Parameters["@cantitate"].Value = Int32.Parse(cuant.ToString());
            cmd.ExecuteNonQuery();
            sqlCon.Close();

            addrGridView_SelectionChanged(null, null);

            /*
            

            cmd = new SqlCommand("SELECT * FROM Furnizor WHERE Id_adr = @id_adr", sConn);
            dataAdapter.SelectCommand = cmd;
            dataSet.Clear();
            dataAdapter.Fill(dataSet);
            providerGridView.DataSource = dataSet.Tables[0];*/

        }

        private void delBtn_Click(object sender, EventArgs e)
        {
            var rowsCount = providerGridView.SelectedRows.Count;


            if (rowsCount != 1)
            {
                return;
            }


            var index = providerGridView.SelectedRows[0].Index;
            var id = Int32.Parse(providerGridView.Rows[index].Cells[0].Value.ToString());
            var name = providerGridView.Rows[index].Cells[1].Value.ToString();
            var cuant = providerGridView.Rows[index].Cells[2].Value.ToString();

            sqlCon.Open();

            DataSet dataSet = new DataSet();
            SqlDataAdapter dataAdapter = new SqlDataAdapter();                
            dataAdapter.UpdateCommand = new SqlCommand("Delete FROM Furnizor WHERE Id_fur=@id_fur", sqlCon);
            dataAdapter.UpdateCommand.Parameters.Add("@id_fur", SqlDbType.Int).Value = Int32.Parse(id.ToString());

               
            Console.WriteLine(id);
            if(dataAdapter.UpdateCommand.ExecuteNonQuery() >= 1)
            {
                MessageBox.Show("The record has been deleted");
            }


            sqlCon.Close();
            addrGridView_SelectionChanged(null, null);

                /*
                 cmd.ExecuteNonQuery();

                 cmd = new SqlCommand("SELECT * FROM Furnizor WHERE Id_adr = @id_adr", sConn);
                 dataAdapter.SelectCommand = cmd;
                 dataSet.Clear();
                 dataAdapter.Fill(dataSet);
                 providerGridView.DataSource = dataSet.Tables[0];*/

        }

        private void AddBtn_Click(object sender, EventArgs e)
        {
           
            var rowsCountAddr = addrGridView.SelectedRows.Count;

            if (rowsCountAddr != 1)
            {
                return;
            }


            var indexAdr = addrGridView.SelectedRows[0].Index;
            var name = providerNameTxt.Text.ToString();
            var cuant = providerQuantityTxt.Text.ToString();
            var adr_id = Int32.Parse(addrGridView.Rows[indexAdr].Cells[0].Value.ToString());

            sqlCon.Open();
            ds2 = new DataSet();
            da1 = new SqlDataAdapter();
            var cmd = new SqlCommand("insert into Furnizor values(@nume, @cantitate, @id_adr)", sqlCon);
            cmd.Parameters.Add("@nume", SqlDbType.VarChar);
            cmd.Parameters.Add("@cantitate", SqlDbType.Int);
            cmd.Parameters.Add("@id_adr", SqlDbType.Int);

            cmd.Parameters["@nume"].Value = name;
            cmd.Parameters["@cantitate"].Value = Int32.Parse(cuant.ToString());
            cmd.Parameters["@id_adr"].Value = Int32.Parse(adr_id.ToString());
            cmd.ExecuteNonQuery();
            sqlCon.Close();
            addrGridView_SelectionChanged(null, null);
        }
    }
}
