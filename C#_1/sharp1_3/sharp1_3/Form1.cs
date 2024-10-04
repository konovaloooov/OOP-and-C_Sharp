using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sharp1_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                // Получение исходных данных из TextBox
                double x = Convert.ToDouble(textBox1.Text);
                double y = Convert.ToDouble(textBox2.Text);
                double z = Convert.ToDouble(textBox3.Text);

                // Ввод исходных данных в окно результатов
                textBox4.Text = "Результаты работы программы ст. Коновалова А.С. " + Environment.NewLine;
                textBox4.Text += "При X = " + textBox1.Text + Environment.NewLine;
                textBox4.Text += "При Y = " + textBox2.Text + Environment.NewLine;
                textBox4.Text += "При Z = " + textBox3.Text + Environment.NewLine;
                // Определение номера выбранной функции
                int n = 0;
                if (radioButton2.Checked) n = 1;
                else if (radioButton3.Checked) n = 2;
                // Вычисление M
                double func_x = 0;
                switch (n)
                {
                    case 0:
                        func_x = Math.Sinh(x);
                        break;
                    case 1:
                        func_x = x * x;
                        break;
                    case 2:
                        func_x = Math.Exp(x);
                        break;

                }
                double max_1 = Math.Max(func_x, Math.Max(y, z));
                double min_2 = Math.Min(func_x, y);
                int tmp;
                if (min_2 == 0)
                    tmp = 1 / Convert.ToInt32(min_2);
                double m = max_1 / min_2 + 5;
                textBox4.Text += "M = " + Convert.ToString(m) + Environment.NewLine;
            }
            catch (FormatException)
            {
                MessageBox.Show("Вы ввели не число. Проверьте входные данные и попробуйте снова!");
                textBox4.Text = "";
            }
            catch (DivideByZeroException)
            {
                MessageBox.Show("Произошла попытка деления на 0. Проверьте входные данные и попробуйте снова!");
                textBox4.Text = "";
            }
            finally
            {
                textBox1.Text = textBox2.Text = textBox3.Text = "";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox2.Text = textBox3.Text = textBox4.Text = "";
        }
    }
}
