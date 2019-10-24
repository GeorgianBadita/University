using Lab1_CRUD_2Tables.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Data;
using System.Windows.Forms;
using System.Data.SqlClient;
using Lab1_CRUD_2Tables.Repository;
using Lab1_CRUD_2Tables.Domain.Validators;
using System.Configuration;
using System.Drawing;
using System.Linq;
using System.Threading;

namespace Lab1_CRUD_2Tables
{
    public partial class Lab1_SGBD : Form
    {


        //database data
        private String parenttableName, childTableName;
        private int parentColCount, childColCount;
        private List<String> parentColumnNames, childColumnNames;
        private String childParameters;

        private SqlConnection sqlConnection;
        private SqlDataAdapter sqlDataAdapter;
        private DataSet dataSet, dataSet2;
        private BindingSource bindingSource;
        private string foreignKeyName;

        //panel data
        private List<TextBox> textBoxes;

        //database cmds
        private String parentSelect;
        private String childInsert, childUpdate, childDelete;

        string conn = "Data Source=DESKTOP-EVCQN0H\\SQLEXPRESS;Initial Catalog=My_lib;Integrated Security=True";
        SqlConnection sqlCon = new SqlConnection("Data Source=DESKTOP-EVCQN0H\\SQLEXPRESS;Initial Catalog=My_lib;Integrated Security=True");
        SqlDataAdapter da1 = new SqlDataAdapter();
        SqlDataAdapter da2 = new SqlDataAdapter();
        DataSet ds1 = new DataSet();
        DataSet ds2 = new DataSet();

        public Lab1_SGBD()
        {
       
            InitializeComponent();
            InitDataBaseData();
            InitPanel();
        }

        private void InitPanel()
        {
            int spacing = Int32.Parse(ConfigurationManager.AppSettings["textBoxSpacing"]);
            int line = 10, column = 100;
            textBoxes = new List<TextBox>();
            for(int index = 0; index<childColumnNames.Count; index++)
            {
                Label label = new Label();
                label.Text = childColumnNames[index];
                label.Location = new Point(0, line);

                TextBox textBox = new TextBox();
                textBox.Location = new Point(column, line);

                panel1.Controls.Add(textBox);
                panel1.Controls.Add(label);
                textBoxes.Add(textBox);

                line += spacing;
            }


        }

        private String GetAttributesString()
        {
            String s = "";
            foreach(var item in childColumnNames)
            {
                s = s + item + ",";
            }

            s = s.Remove(s.Count() - 1);
            return s;
        }

      
        private void InitDataBaseData()
        {
            parenttableName = ConfigurationManager.AppSettings["parenttableName"];
            childTableName = ConfigurationManager.AppSettings["childTableName"];

            parentColumnNames = new List<string>(ConfigurationManager.AppSettings["parentColumnNames"].Split(','));
            childColumnNames = new List<string>(ConfigurationManager.AppSettings["childColumnNames"].Split(','));

            childParameters = ConfigurationManager.AppSettings["childParameters"];
            foreignKeyName = ConfigurationManager.AppSettings["foreignKeyName"];

            String connection = ConfigurationManager.ConnectionStrings["cn"].ToString();
            this.sqlConnection = new SqlConnection(connection);
            this.sqlDataAdapter = new SqlDataAdapter();
            this.dataSet = new DataSet();
            this.dataSet2 = new DataSet();
            this.sqlConnection.Open();
            this.sqlConnection.Close();
            this.bindingSource = new BindingSource();
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
            sqlConnection.Open();
            this.sqlDataAdapter.SelectCommand = new SqlCommand("SELECT * FROM " + parenttableName, this.sqlConnection);
            this.dataSet.Clear();
            this.sqlDataAdapter.Fill(this.dataSet);
            addrGridView.DataSource = dataSet.Tables[0];
            bindingSource.DataSource = dataSet.Tables[0];
            sqlConnection.Close();
        }


        private SqlCommand GetInsertString(SqlConnection connection)
        {

            String command = "INSERT INTO " + childTableName + " (" + GetAttributesString() + ") " +
                            "VALUES (" + childParameters + ")";
            SqlCommand cmd = new SqlCommand(command, connection);


            for (int index = 0; index < childColumnNames.Count; index++)
            {
                String text = textBoxes[index].Text;
                String identificator = "@" + childColumnNames[index];
                cmd.Parameters.AddWithValue(identificator, text);
            }            return cmd;
        }

        private SqlCommand GetDeleteString(SqlConnection sqlConnection)
        {
            String command = "DELETE FROM " + childTableName + " WHERE " + childColumnNames[0] + "=" +
                "@" + childColumnNames[0];

            SqlCommand cmd = new SqlCommand(command, sqlConnection);

            String text = textBoxes[0].Text;
            String identificator = "@" + childColumnNames[0];
            cmd.Parameters.AddWithValue(identificator, text);

            return cmd;
        }

        private void dead_btn_Click(object sender, EventArgs e)
        {
            Thr1 t1 = new Thr1();
            Thread thr1 = new Thread(new ThreadStart(t1.run));
            thr1.Start();
            Thr2 t2 = new Thr2();
            Thread thr2 = new Thread(new ThreadStart(t2.run));
            thr2.Start();
        }

        private SqlCommand GetUpdateString(SqlConnection sqlConnection)
        {
            String command = "UPDATE " + childTableName + " SET ";
            for (int index = 0; index < childColumnNames.Count; index++)
            {
                command = command + childColumnNames[index] + "=@" + childColumnNames[index] + ",";
            }
            command = command.Remove(command.Count() - 1);

            command = command + " WHERE " + childColumnNames[0] + "=" + textBoxes[0].Text;

            SqlCommand cmd = new SqlCommand(command, sqlConnection);


            for (int index = 0; index < childColumnNames.Count; index++)
            {
                String text = textBoxes[index].Text;
                String identificator = "@" + childColumnNames[index];
                cmd.Parameters.AddWithValue(identificator, text);
            }            return cmd;
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

          

        }

        private void delBtn_Click(object sender, EventArgs e)
        {
            var rowsCount = providerGridView.SelectedRows.Count;


            if (rowsCount != 1)
            {
                return;
            }


            try
            {
                sqlConnection.Open();
            }
            catch (Exception) { }
            try
            {
                SqlCommand cmd = GetDeleteString(sqlConnection);
                sqlDataAdapter.InsertCommand = cmd;
                sqlDataAdapter.InsertCommand.ExecuteNonQuery();
                addrGridView_SelectionChanged(null, null);
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message + "Error on delete.");
            }
            sqlConnection.Close();

        }

        private void AddBtn_Click(object sender, EventArgs e)
        {
           
            var rowsCountAddr = addrGridView.SelectedRows.Count;

            if (rowsCountAddr != 1)
            {
                return;
            }


            try
            {
                sqlConnection.Open();
            }
            catch (Exception) { }
            try
            {
                SqlCommand cmd = GetInsertString(sqlConnection);
                sqlDataAdapter.InsertCommand = cmd;
                sqlDataAdapter.InsertCommand.ExecuteNonQuery();
                addrGridView_SelectionChanged(null, null);
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message + "Error on insert");
            }
            sqlConnection.Close();
        }
    }

}
