using System;
namespace ConsoleApp1
{
	class Class
	{
		static int[][] Input()
		{
			Console.WriteLine("Введите размерность массива");
			Console.Write("n = ");
			int n = int.Parse(Console.ReadLine());
			int[][] a = new int[n][];
			for (int i = 0; i < n; ++i)
			{
				a[i] = new int[n];
				for (int j = 0; j < n; ++j)
				{
					Console.Write("a[{0},{1}]= ", i, j);
					a[i][j] = int.Parse(Console.ReadLine());
				}
			}
			return a;
		}

		static void Print1(int[] a)
		{
			for (int i = 0; i < a.Length; ++i)
				Console.Write("{0,5} ", a[i]);
			Console.WriteLine();
		}

		static void Print2(int[][] a)
		{
			for (int i = 0; i < a.Length; ++i, Console.WriteLine())
				for (int j = 0; j < a[i].Length; ++j)
					Console.Write("{0,5} ", a[i][j]);
		}

		static int LastOdd(int[][] a, int j)
		{
			int last_odd = -1;
			for (int i = 0; i < a.Length; ++i)
			{
				if (a[i][j] % 2 == 1) { last_odd = i; }
			}
			return last_odd;
		}

		static void Main()
		{
			try
			{

				int[][] myArray = Input();
				Console.WriteLine("Исходный массив:");
				Print2(myArray);
				int[] rez = new int[myArray.Length];
				for (int j = 0; j < myArray.Length; ++j)
					rez[j] = LastOdd(myArray, j);
				Console.WriteLine("Новый массив(номер нечетного элементв в столбце):");
				Print1(rez);
				Console.WriteLine("-1 - отсутствие нечётного элемента в столбце");
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
	}
}
