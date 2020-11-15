using System;

namespace Prime
{
	/// <summary>
	/// Lists prime numbers
	/// </summary>
	class ListPrime
	{
		static void Main(string[] args)
		{
			Console.WriteLine("1) List prime numbers between two numbers\n2) List a specified amount of prime numbers\n3) Find the nth prime number");
			string choice = Console.ReadLine();

			switch (choice)
			{
				case "1":
					Choice1();
					break;
				case "2":
					Choice2();
					break;
				case "3":
					Choice3();
					break;
				default:
					Console.WriteLine("Invalid Input");
					Console.ReadLine();
					break;
			}
		}

		static void Choice1()
		{
			decimal n = 2;
			decimal i;
			bool a = true;

			Console.Write("Enter a number to start listing prime numebrs at: ");
			int x = Convert.ToInt32(Console.ReadLine());
			Console.Write("Enter a number to stop listing prime numbers at: ");
			int y = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine();
			
			for (n = x; n <= y; n++)
			{
				a = true;

				for (i = 2; i <= n/2; i++)
				{
					if (n/i == (int)(n/i))
					{
						a = false;
					}
				}
			
				if (a == true)
				{
					Console.WriteLine(n);
				}
			}

			Console.ReadLine();
		}

		static void Choice2()
		{
			decimal n = 2;
			decimal i;
			bool a = true;
			int b;

			Console.Write("Enter amout of prime numbers to list: ");
			int x = Convert.ToInt32(Console.ReadLine());

			for (b = 1; b <= x; n++)
			{
				a = true;

				for (i = 2; i <= n/2; i++)
				{
					if (n/i == (int)(n/i))
					{
						a = false;
					}
				}
			
				if (a == true)
				{
					Console.WriteLine(n);
					b++;
				}
			}

			Console.ReadLine();
		}

		static void Choice3()
		{
			decimal n = 2;
			decimal i;
			int b;
			bool a = true;

			Console.Write("Find nth prime number: ");
			int x = Convert.ToInt32(Console.ReadLine());

			for (b = 1; b <= x; n++)
			{
				a = true;

				for (i = 2; i <= n/2; i++)
				{
					if (n/i == (int)(n/i))
					{
						a = false;
					}
				}
			
				if (a == true)
				{
					b++;
				}
			}

			Console.WriteLine(n-1);
			Console.ReadLine();
		}
	}
}
