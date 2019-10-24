using Lab2_Festival.domain.entities;
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
    public partial class MainForm : Form
    {
        private readonly FestivalService _festivalService;
        private BindingSource bindingSource;


        public MainForm(FestivalService festivalService)
        {
            this._festivalService = festivalService;
            InitializeComponent();
            InitTable();
        }

        private void InitTable()
        {
            bindingSource = new BindingSource();
            bindingSource.DataSource = _festivalService.GetConcertDtos();
            mainTable.DataSource = bindingSource;
            mainTable.Columns[0].Visible = false;
            foreach (DataGridViewRow row in mainTable.Rows)
            {
                if (Convert.ToInt32(row.Cells[6].Value) == 0)
                {
                    
                    row.DefaultCellStyle.BackColor = Color.Red;
                    
                }
            }
           
        }

        private void ShowConcertsBtn_Click(object sender, EventArgs e)
        {
            Concerts concerts = new Concerts(_festivalService.GetDTOsByDate(ConcertDatePicker.Value));
            concerts.Show();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void SellTicketsButton_Click(object sender, EventArgs e)
        {
            string clName = ClientName.Text.ToString();
            string numTick = NumTickets.Text.ToString();
            var countSelected = mainTable.SelectedRows.Count;
            if(countSelected < 1)
            {
                MessageBox.Show("Please select a concert first!");
                return;
            }

            if(countSelected > 1)
            {
                MessageBox.Show("You can select only one concert!");
                return;
            }
            if(numTick.Equals("") || clName.Equals(""))
            {
                MessageBox.Show("Sorry, client name and number of tickets can't be empty!");
                return;
            }

            var row = mainTable.SelectedRows[0].DataBoundItem;
            DTOConcert selectedDto = (DTOConcert)row;
            var ticketsNum = Int32.Parse(numTick);
            if(ticketsNum > selectedDto.FreeSeasts)
            {
                MessageBox.Show("Sorry, you can't buy more seats than te available seats!");
                return;
            }

            SellTicket(selectedDto, clName, ticketsNum);
            UpdateTable(selectedDto, ticketsNum);
        }

        private void SellTicket(DTOConcert dTOConcert, string clName, int ticketsNum)
        {
            _festivalService.SellTicket(dTOConcert.ConcertID, clName, DateTime.Now, ticketsNum);
        }

        private void UpdateTable(DTOConcert dTOConcert, int ticketsNum)
        {
            
            var dtos = _festivalService.GetConcertDtos();
            foreach(var dto in dtos)
            {
                if(dto.ConcertID == dTOConcert.ConcertID)
                {
                    dto.SoldSeats += ticketsNum;
                    dto.FreeSeasts -= ticketsNum;
                    break;
                }
            }
            
            bindingSource = new BindingSource();
            bindingSource.DataSource = dtos;
            mainTable.DataSource = bindingSource;
            
            foreach (DataGridViewRow row in mainTable.Rows)
            {
                mainTable.Columns[0].Visible = false;
                var free = Convert.ToInt32(row.Cells[6].Value);
               
                if (free == 0)
                {
                    row.Cells[6].Value = free.ToString();
                    row.DefaultCellStyle.BackColor = Color.Red;
                }
            }
            
        }

        

    }
}
