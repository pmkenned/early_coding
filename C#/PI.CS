using System;

namespace Pi
{
	class CalcPi
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Select a method for calculating Pi:");
			Console.WriteLine("1) Wallis' Formula");
			Console.WriteLine("2) Gregory's Formula");
			Console.WriteLine("3) Random Numbers");
			Console.WriteLine("4) Bailey, Borwein and Plouffe");
			string answer = Console.ReadLine();
			switch (answer)
			{
				case "1":
					wallis();
					break;
				case "2":
					arctan();
					break;
				case "3":
					random();
					break;
				case "4":
					bbp();
					break;
				default:
					Console.WriteLine("Invalid Input");
					Console.ReadLine();
					break;
			}

		}
		static void wallis()
		{
			decimal n;
			decimal pi = 1;
			Console.Write("Number of iterations: ");
			int x = Convert.ToInt32(Console.ReadLine());
			for (n = 1; n != x; n++)
			{
				pi = pi * 4 * n * n/(4 * n * n - 1);
				Console.WriteLine(2*pi);
			}
			Console.ReadLine();
		}
		static void arctan()
		{
			decimal x = 0;
			decimal i = 0;

			Console.Write("Number of iterations: ");
			int n = Convert.ToInt32(Console.ReadLine());

			for (i = 0; i != n; i++)
			{
				x = x + Convert.ToDecimal(Math.Pow(-1, Convert.ToDouble(i)))/(2*i+1);
				Console.WriteLine(4*x);
			}
			Console.ReadLine();
		}
		static void random()
		{
			double x;
			double y;
			double n = 0;
			double i;
			Random rand = new Random();
			Console.Write("Number of iterations: ");
			int exit = Convert.ToInt32(Console.ReadLine());
			for (i = 1; i != exit; i++)
			{
				x = rand.NextDouble()*2-1;
				y = rand.NextDouble()*2-1;
				if (Math.Sqrt(Math.Pow(x, 2)+Math.Pow(y, 2)) <= 1)
					n++;
				Console.WriteLine(n/i*4);
			}
			Console.ReadLine();
		}
		static void bbp()
		{
			decimal pi = 0;
			int i;

			Console.Write("Number of decimal places to calculate Pi: ");
			int n = Convert.ToInt32(Console.ReadLine());

			for (i = 0; i < n; i++)
			{
				pi = pi + Convert.ToDecimal((4/(8*Convert.ToDouble(i)+1)-2/(8*Convert.ToDouble(i)+4)-1/(8*Convert.ToDouble(i)+5)-1/(8*Convert.ToDouble(i)+6))*(1/Math.Pow(16, Convert.ToInt32(i))));
				Console.WriteLine(pi);
			}
			Console.ReadLine();
		}
	}
}
