//Задание.Добавьте в программу метод MakeArray, предназначенный для создания ступенчатого массива, 
//в котором количество элементов в каждой строке больше номера строки в два раза. А сам элемент 
//равен сумме номеров строки и столбца, в котором он находится.  Продемонстрируйте работу данного метода.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3
{
    class Program
    {
        static int[][] MakeArray(int n)
        {
            int[][] MyArray = new int[n][];
            for (int i = 0; i < MyArray.Length; i++)
            {
                int j = (i + 1) * 2; //количество элементов в каждой строке больше номера строки в два раза
                MyArray[i] = new int[j];
                for (j = 0; j < MyArray[i].Length; j++)
                {
                    MyArray[i][j] = 2 + i + j; //элемент равен сумме номеров строки и столбца, в котором он находится
                }
            }
            return MyArray;
        }
            static void Main()
        {
            try
            {
                Console.Write("Ввведите количество строк: ");
                int n = int.Parse(Console.ReadLine());
                int[][] MyArray = MakeArray(n);
                PrintArray("исходный массив:", MyArray);
                for (int i = 0; i < MyArray.Length; i++) Array.Sort(MyArray[i]);
                PrintArray("измененный массив", MyArray);
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

        static void PrintArray(string a, int[][] mas)
        {
            Console.WriteLine(a);
            for (int i = 0; i < mas.Length; i++)
            {
                for (int j = 0; j < mas[i].Length; j++) Console.Write("{0} ", mas[i][j]);
                Console.WriteLine();
            }
        }
    }
}
