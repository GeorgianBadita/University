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
    public partial class Concerts : Form
    {
        private List<DTOConcert> DTOList;
        private BindingSource bindingSource;
        public Concerts(List<DTOConcert> dtoLst)
        {
            this.DTOList = dtoLst;
            InitializeComponent();
            InitTable();
        }

        private void InitTable()
        {
            bindingSource = new BindingSource();
            bindingSource.DataSource = this.DTOList;
            concertTable.DataSource = bindingSource;
        }
    }
}
