//Задание. Добавьте в программу метод InputArray, предназначенный для ввода с клавиатуры элементов массива. Продемонстрируйте работу данного метода.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2
{
    class Program
    {
        static int[] InputArray()
        {
            int[] MyArray;
            Console.Write("Введите размерность массива: ");
            int n = int.Parse(Console.ReadLine());
            MyArray = new int[n];
            for (int i = 0; i < MyArray.Length; ++i)
            {
                Console.Write("a[{0}]=", i);
                MyArray[i] = int.Parse(Console.ReadLine());
            }
            return MyArray;
        }
            static void Main()
        {
            try
            {
                int[] MyArray = InputArray();
                PrintArray("исходный массив:", MyArray);
                Array.Sort(MyArray);
                PrintArray("массив отсортирован по возрастанию", MyArray);
                Array.Reverse(MyArray);
                PrintArray("массив отсортирован по убыванию", MyArray);
            }
            catch (FormatException)
            {
                Console.WriteLine("неверный формат ввода данных");
            }
            catch (OverflowException)
            {
                Console.WriteLine("переполнение");
            }
            catch (OutOfMemoryException)
            {
                Console.WriteLine("недостаточно памяти для создания нового объекта");
            }
        }
        static void PrintArray(string a, int[] mas)
        {
            Console.WriteLine(a);
            for (int i = 0; i < mas.Length; i++) Console.Write("{0} ", mas[i]);
            Console.WriteLine();
        }
    }
}

