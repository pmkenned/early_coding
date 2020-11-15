using System;

namespace RandomWalk
{
	/// <summary>
	/// Randomly walks foward or backward based on coin flip and records results to text file.
	/// </summary>
	class CoinToss
	{
		static void Main(string[] args)
		{
			int i;

			int finalPosition = 0;
			int northSide = 0;
			int southSide = 0;
			int origin = 0;

			int sumOfDistances = 0;
			int totalNorth = 0;
			int totalSouth = 0;
			int totalOrigin = 0;

			int repeatInput;
			int repeatVar;
			Random random = new Random();

			Console.Write("Repeat how many times? ");

			try
			{
				repeatInput = Convert.ToInt32(Console.ReadLine());
			}
			catch
			{
				Console.WriteLine("Invalid input.");
				repeatInput = 0;
			}

			System.IO.StreamWriter sw = new System.IO.StreamWriter("RandomWalk.txt");

			Console.WriteLine("\nWalk\t\tFinal\t\tTimes on\tTimes on\tTimes\n\t\tposition\tnorth side\tsouth side\tat origin");
			Console.WriteLine("------------------------------------------------------------------");
			sw.WriteLine("Walk\t\tFinal\t\tTimes on\tTimes on\tTimes");
			sw.WriteLine("\t\tposition\tnorth side\tsouth side\tat origin");
			sw.WriteLine("------------------------------------------------------------------");

			for (repeatVar = 1; repeatVar <= repeatInput; repeatVar++)
			{
				finalPosition = 0;
				northSide = 0;
				southSide = 0;
				origin = 0;

				for (i = 1; i <= 25; i++)
				{
					int x = random.Next(2);

					if (x == 0)
						finalPosition++;
					else
						finalPosition--;

					if (finalPosition > 0)
						northSide++;
					else if (finalPosition < 0)
						southSide++;
					else if (finalPosition == 0)
						origin++;
				}

				sumOfDistances = sumOfDistances + Math.Abs(finalPosition);
				totalNorth = totalNorth + Math.Abs(northSide);
				totalSouth = totalSouth + Math.Abs(southSide);
				totalOrigin = totalOrigin + Math.Abs(origin);

				Console.WriteLine("{0}\t\t{1}\t\t{2}\t\t{3}\t\t{4}", repeatVar, finalPosition, northSide, southSide, origin);
				sw.WriteLine("{0}\t\t{1}\t\t{2}\t\t{3}\t\t{4}", repeatVar, finalPosition, northSide, southSide, origin);
			}

			Console.WriteLine("------------------------------------------------------------------");
			Console.WriteLine("\t\t{0}\t\t{1}\t\t{2}\t\t{3}", sumOfDistances, totalNorth, totalSouth, totalOrigin);
			sw.WriteLine("------------------------------------------------------------------");
			sw.WriteLine("\t\t{0}\t\t{1}\t\t{2}\t\t{3}", sumOfDistances, totalNorth, totalSouth, totalOrigin);
			sw.Close();
			Console.ReadLine();
		}
	}
}
