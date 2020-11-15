using System;

namespace Critter
{
	/// <summary>
	/// Simulates a critter you can talk to, feed, and play with.
	/// Demonstrates the use of scopes, public variables, and the use of multiple classes.
	/// </summary>
	class Menu
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		static void Main(string[] args)
		{
			bool keepGoing = true;
			int choice;

			Critter myCritter = new Critter();
			myCritter.name = "George";

			while (keepGoing)
			{
				choice = showMenu();
				switch (choice)
				{
					case 0:
						keepGoing = false;
						break;
					case 1:
						Console.WriteLine(myCritter.talk());
						break;
					case 2:
						myCritter.eat();
						Console.WriteLine("You have fed the critter");
						break;
					case 3:
						myCritter.play();
						Console.WriteLine("You have played with the critter");
						break;
					case 4:
						Console.WriteLine("Current name: {0}", myCritter.name);
						Console.Write("Change name to: ");
						myCritter.name = Console.ReadLine();
						break;
					default:
						Console.WriteLine("That was not a valid input");
						break;
				}
			}
		}
		static int showMenu()
		{
			int input = 1;
			Console.WriteLine();
			Console.WriteLine("0) Exit");
			Console.WriteLine("1) Listen to the critter");
			Console.WriteLine("2) Feed critter");
			Console.WriteLine("3) Play with critter");
			Console.WriteLine("4) Rename critter");
			try
			{
				input = Convert.ToInt32(Console.ReadLine());
			}
			catch (FormatException)
			{
				Console.WriteLine("Incorrect Input");
				showMenu();
			}
			return input;
		}

	}
	class Critter
	{
		private string pName;
		private int pFull = 10;
		private int pHappy = 10;
		private int pAge = 0;

		public string name 
		{
			get
			{
				return pName;
			}
			set
			{
				if (value.Length > 8)
				{
					Console.WriteLine("The name can't  be any more than 8 characters");
					pName = value;
					pName = pName.Substring(0,8);
					Console.WriteLine("Changing name to {0}", pName);
				}
				else
				{
					pName = value;
				}
			}
		}

		public string talk()
		{
			string message;
			message = "The critter says: \n";

			age();

			if (pHappy > 5)
			{
				message += " Hi! My name is " + name + "\n";
				message += " I feel happy today!";
			}
			else if (pHappy > 2)
			{
				message += " " + name + " doesn't feel so good...";
			}
			else if (pHappy > 0)
			{
				message = " " + name + " is MAD...";
			}
			else
			{
				message += " ...nothing at all but lays in a heap.";
			}
			if (pFull < 3)
			{
				message += "\n " + name + " is hungry.";
			}
			return message;
		}
		public void age()
		{
			pAge++;
			pFull--;

			if (pFull < 3)
			{
				pHappy--;
			}
		}
		public void eat()
		{
			age();
			pFull += 4;
		}
		public void play()
		{
			age();
			pHappy += 4;
			pFull += -1;
		}
	}
}
