using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sharp1_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox4.Text += "Лаб. раб. N1.2 гр. 211 Коновалов А.С.";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                textBox4.Text = "Лаб. раб. N1.2 гр. 211 Коновалов А.С.";
                double x = double.Parse(textBox1.Text);

                textBox4.Text += Environment.NewLine +
                    "X = " + x.ToString();

                double y = double.Parse(textBox2.Text);

                textBox4.Text += Environment.NewLine +
                    "Y = " + y.ToString();

                double z = double.Parse(textBox3.Text);

                textBox4.Text += Environment.NewLine +
                    "Z = " + z.ToString();

                double x_power = Math.Pow(Math.Abs(x), 1.0 / 3);
                double a = Math.Pow(y, x_power);

                double cos_3 = Math.Cos(y) * Math.Cos(y) * Math.Cos(y);
                double f = Math.Sin(z) * Math.Sin(z) / Math.Sqrt(x + y);
                double c = Math.Abs(x - y) * (1.0 + f);

                double d = Math.Exp(Math.Abs(x - y)) + (x / 2);
                if (Math.Abs(x) - Math.Abs(y) == 0 || d == 0)
                {
                    int tmp = 0;
                    int tmp1 = 1 / tmp;
                }
                double b = a + (cos_3 * (c / d));

                textBox4.Text += Environment.NewLine +
                "Результат B = " + b.ToString();
            }
            catch (FormatException)
            {
                MessageBox.Show("Ну вот буквы нам считать ещё не хватало...!");
            }
            catch (DivideByZeroException)
            {
                MessageBox.Show("Ой! Произошло деление на 0, проверьте входные данные.");
            }
            finally
            {
                textBox1.Text = textBox2.Text = textBox3.Text = "";
            }
        }

    }
}
