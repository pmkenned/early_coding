using System;

namespace Concat
{
	/// <summary>
	/// Demonstrates string concatenation,
	/// escaped characters
	/// </summary>
	class Concat
	{
		static void Main(string[] args)
		{
			string userName = "Jacob";
			Console.WriteLine("This is regular text");
			Console.WriteLine("Hi there, " + userName + "!");
			Console.WriteLine("This line has a \t tab in it");
			Console.WriteLine("The line has a \n newline in it");
			Console.WriteLine("This line has a \\ slash in it");
			Console.WriteLine("This line has \"quotes\" in it");
			Console.WriteLine();
			Console.WriteLine("Press Enter to continue");
			Console.ReadLine();
		}
	}
}
