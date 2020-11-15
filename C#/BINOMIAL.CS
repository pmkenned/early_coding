using System;

namespace Binomial
{
	/// <summary>
	/// Randomly chooses 1 or 0 a specified number of times and total results.
	/// </summary>
	class Class1
	{
		static void Main(string[] args)
		{
			int i;
			int j;

			int a0 = 0;
			int b1 = 0;
			int c2 = 0;
			int d3 = 0;
			int e4 = 0;
			int f5 = 0;
			int g6 = 0;
			int h7 = 0;
			int i8 = 0;
			int j9 = 0;
			int k10 = 0;

			int nTotal = 0;
			Random rand = new Random();

			Console.Write("Enter integer to exit for loop at: ");
			int forExit = Convert.ToInt32(Console.ReadLine());

			for (i = 0; i < forExit; i++)
			{
				for (j = 0; j < 10; j++)
				{
					int n = rand.Next(2);
					nTotal = n + nTotal;
				}
				switch (nTotal)
				{
					case 0:
						a0++;
						break;
					case 1:
						b1++;
						break;
					case 2:
						c2++;
						break;
					case 3:
						d3++;
						break;
					case 4:
						e4++;
						break;
					case 5:
						f5++;
						break;
					case 6:
						g6++;
						break;
					case 7:
						h7++;
						break;
					case 8:
						i8++;
						break;
					case 9:
						j9++;
						break;
					case 10:
						k10++;
						break;
				}
						
				nTotal = 0;
			}

			Console.WriteLine("N was equal to:");
			Console.WriteLine("0: {0}", a0);
			Console.WriteLine("1: {0}", b1);
			Console.WriteLine("2: {0}", c2);
			Console.WriteLine("3: {0}", d3);
			Console.WriteLine("4: {0}", e4);
			Console.WriteLine("5: {0}", f5);
			Console.WriteLine("6: {0}", g6);
			Console.WriteLine("7: {0}", h7);
			Console.WriteLine("8: {0}", i8);
			Console.WriteLine("9: {0}", j9);
			Console.WriteLine("10: {0}", k10);

			Console.ReadLine();
		}
	}
}
