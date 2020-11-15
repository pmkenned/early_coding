using System;

namespace Song
{
	/// <summary>
	/// Creates this old man song using 5 different methods contained in ThisOldMan class.
	/// </summary>
	class ThisOldMan
	{
		/// <summary>
		/// Prints this old man song to console.
		/// </summary>
		static void Main(string[] args)
		{
			int i;

			for (i = 1; i <= 10; i++)
			{
				doVerse(i);
				doChorus();
			}
			
			pause();
		}

		static void doChorus()
		{
			string message = "";
			message += "\nWith a knick-knack paddy whack\n";
			message += "Give a dog a bone\n";
			message += "This old man came rolling home.";
			message += "\n\n";
			Console.WriteLine(message);
		}
		static void doVerse(int verseNum)
		{
			string message = "";
			message += "This old man, he played ";
			message += (verseNum);
			message += (". \nHe played knick-knack ");
			message += getPlace(verseNum);
			Console.WriteLine(message);
		}
		static string getPlace(int verseNum)
		{
			string message = "";
			switch (verseNum)
			{
				case 1:
					message = "on my thumb ";
					break;
				case 2:
					message = "on my shoe ";
					break;
				case 3:
					message = "on my knee ";
					break;
				case 4:
					message = "on my door ";
					break;
				case 5:
					message = "on my hive ";
					break;
				case 6:
					message = "on my sticks ";
					break;
				case 7:
					message = "up to heaven ";
					break;
				case 8:
					message = "on my gate ";
					break;
				case 9:
					message = "on my line ";
					break;
				case 10:
					message = "on my hen ";
					break;
				default:
					message = "not yet defined ";
					break;
			}
			return message;
		}
		static void pause()
		{
			Console.ReadLine();
		}
	}
}
