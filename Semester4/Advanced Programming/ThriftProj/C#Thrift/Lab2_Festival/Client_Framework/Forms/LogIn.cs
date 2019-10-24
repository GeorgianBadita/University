using Common.service;
using Common.utils.observer;
using Lab2_Festival.service;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2_Festival.Forms
{
    public partial class LogIn : Form, IObserver
    {
        private readonly IService _festivalService;


       

        public LogIn(IService festivalService)
        {
            this._festivalService = festivalService;
            InitializeComponent();
            passTxt.PasswordChar = '*';
        }

        private void LogInBtn_Click(object sender, EventArgs e)
        {
            string userName = nameTxt.Text.ToString();
            string pass = passTxt.Text.ToString();

            bool logInSuccess = ValidateLogInController(userName, pass);

            if (!logInSuccess)
            {
                MessageBox.Show("Sorry, Incorrect credentials, please try again", "Incorrect credentials!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            else
            {
                this.Visible = false;
                HandleMainWindowStart();
            }
        }

        private void HandleMainWindowStart()
        {
            MainForm mainForm = new MainForm(this._festivalService);
            mainForm.Show();
        }

        private bool ValidateLogInController(string userName, string pass)
        {
            return _festivalService.ValidateLogIn(userName, pass, this);
        }

        private void LogIn_Load(object sender, EventArgs e)
        {

        }

        public void ReloadObserver()
        {
            throw new NotImplementedException();
        }
    }
}
