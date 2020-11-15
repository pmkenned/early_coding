using System;

namespace DiceSet3
{
	/// <summary>
	/// Rolls two sets of dice with different values.
	/// Problem from Mathmatics: A Human Endeavor pg. 459
	/// </summary>
	class Class1
	{
		static void Main(string[] args)
		{
			Random rand = new Random();
			int i;
			int a;
			int b;
			int aGreater = 0;
			int bGreater = 0;
			Console.Write("For loop exit integer: ");
			int exitFor = Convert.ToInt32(Console.ReadLine());
			for (i = 0; i < exitFor; i++)
			{
				do
				{
					a = rand.Next(11)+1;
				}
				while (a == 4 | a == 5 | a == 6 | a == 7 | a == 8);

				Console.WriteLine("A = {0}", a);

				do
				{
					b = rand.Next(11);
				}
				while (b == 2 | b == 2 | b == 3 | b == 4 | b == 5 | b==6);

				if (b > 8)
					b--;

				Console.WriteLine("B = {0}", b);

				if (a > b)
				{
					aGreater++;
					Console.WriteLine("A is greater");
				}
				else if (b > a)
				{
					bGreater++;
					Console.WriteLine("B is greater");
				}
				else
				{
					Console.WriteLine("A and B equal");
				}

			}
			Console.WriteLine();
			Console.WriteLine("A was greater {0} times\nB was greater {1} times", aGreater, bGreater);
			Console.ReadLine();

			aGreater = 0;
			bGreater = 0;

			for (i = 0; i < exitFor; i++)
			{
				a = rand.Next(6)+5;
				if (a > 7)
					a = a-3;

				Console.WriteLine("A = {0}", a);

				do
				{
					b = rand.Next(11)+3;
				}
				while (b == 6 | b == 7 | b == 8 | b == 9 | b == 10);

				if (b == 13)
					b = 4;

				Console.WriteLine("B = {0}", b);

				if (a > b)
				{
					aGreater++;
					Console.WriteLine("A is greater");
				}
				else if (b > a)
				{
					bGreater++;
					Console.WriteLine("B is greater");
				}
				else
				{
					Console.WriteLine("A and B equal");
				}
			}

			Console.WriteLine("A was greater {0} times\nB was greater {1} times", aGreater, bGreater);
			Console.ReadLine();
		}
	}
}
