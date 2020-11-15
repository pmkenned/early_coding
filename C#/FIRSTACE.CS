using System;

namespace Cards
{
	/// <summary>
	/// Randomly chooses a card (1-52) until it reaches an ace (1-4).
	/// </summary>
	class FirstAce
	{
		static void Main(string[] args)
		{
			Random rand = new Random();
			int i = 0;
			int count;
			double totalCount = 0;

			Console.Write("Repeat: ");
			int n = Convert.ToInt32(Console.ReadLine());

			for (i = 0; i < n; i++)
			{
				count = 1;

				double x = rand.Next(52)+1;
				Console.WriteLine(x);

				while (x > 4)
				{
					count++;
					x = rand.Next(52)+1;
					Console.WriteLine(x);
				}

				Console.WriteLine();
				Console.WriteLine(count);
				Console.WriteLine();
				totalCount = totalCount + count;
			}
			
			Console.WriteLine();
			Console.WriteLine("Total\t= {0}", totalCount);
			Console.WriteLine("Average\t= {0}", totalCount/n);
			Console.ReadLine();
		}
	}
}
