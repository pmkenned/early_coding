using System;

namespace Pi
{
	/// <summary>
	/// Calculates Pi
	/// </summary>
	class CalcPi
	{
		static void Main(string[] args)
		{
			decimal pi = 0;
			decimal i;

			Console.Write("Calculate to Pi to decimal place: ");
			int n = Convert.ToInt32(Console.ReadLine());

			for (i = 0; i < n; i++)
			{
				pi = pi + (4/(8*i+1)-2/(8*i+4)-1/(8*i+5)-1/(8*i+6))*Convert.ToDecimal((1/Math.Pow(16, Convert.ToDouble(i))));
				Console.WriteLine(Math.Round(pi, 24));
			}
			Console.ReadLine();
		}
	}
}
