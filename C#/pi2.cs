using System;

namespace Pi
{
	class Class1
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Select a method for calculating Pi:");
			Console.WriteLine("1) Wallis' Formula");
			Console.WriteLine("2) Gregory's Formula");
			Console.WriteLine("3) Random Numbers");
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
				default:
					Console.WriteLine("Invalid Input");
					Console.ReadLine();
					break;
			}

		}
		static void wallis()
		{
			int n;
			double pi = 1;
			Console.Write("Exit for loop at integer: ");
			int x = Convert.ToInt32(Console.ReadLine());
			for (n = 2; n <= 2*x; n = n+2)
			{
				pi = pi * Math.Pow(n, 2)/((n-1)*(n+1));
				Console.WriteLine(2*pi);
			}
			Console.ReadLine();
		}
		static void arctan()
		{
			double x = 0;
			int n = 0;
			start:
			x = x + Math.Pow(-1, n)/(2*n+1);
			Console.WriteLine(4*x);
			n++;
			goto start;
		}
		static void random()
		{
			double x;
			double y;
			double n = 0;
			double i;
			Random rand = new Random();
			Console.Write("Exit for loop at integer: ");
			int exit = Convert.ToInt32(Console.ReadLine());
			for (i = 1; i <= exit; i++)
			{
				x = rand.NextDouble()*2-1;
				y = rand.NextDouble()*2-1;
				if (Math.Sqrt(Math.Pow(x, 2)+Math.Pow(y, 2)) <= 1)
					n++;
				Console.WriteLine(n/i*4);
			}
			Console.ReadLine();
		}
	}
}
