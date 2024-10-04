using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sharp1_4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void res(double div)
        {
            // Считывание начальных данных
            double x0 = Convert.ToDouble(textBox1.Text);
            double xk = Convert.ToDouble(textBox2.Text);
            double dx = Convert.ToDouble(textBox3.Text);
            double a = Convert.ToDouble(textBox4.Text);
            double b = Convert.ToDouble(textBox6.Text);
            textBox5.Text = "Работу выполнил ст. Иванов М.А." + Environment.NewLine;
            // Цикл для табулирования функции
            double x = x0;
            while (x < (xk + dx / div))
            {
                double y = x + Math.Sqrt(Math.Abs(x * x * x + a - b * Math.Exp(x)));
                textBox5.Text += "x=" + Convert.ToString(x) +
                                 "; y=" + Convert.ToString(y) + Environment.NewLine;
                x = x + dx / div;
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            res(1);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            res(2);
        }
    }
}
