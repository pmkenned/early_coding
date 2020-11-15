using System;

namespace Adventure
{
	/// <summary>
	/// Silly adventure game
	/// User responds to some questions, and these
	/// responses are used to write a goofy story
	/// Paul Kennedy, 4/23/05
	/// </summary>
	class Adventure
	{
		static void Main(string[] args)
		{
			string person;
			string occupation;
			string seaCreature;
			string animal;
			string friend;
			string tool;
			string problem;
			Console.WriteLine("Simple Adventure Game");

			Console.Write("What is your name? ");
			person = Console.ReadLine();

			Console.Write("What is your occupation? ");
			occupation = Console.ReadLine();

			Console.Write("Please tell me your favorite animal: ");
			animal = Console.ReadLine();

			Console.Write("What is the name of one of your friends? ");
			friend = Console.ReadLine();

			Console.Write("Name a problem you might face: ");
			problem = Console.ReadLine();

			Console.Write("Name a tool: ");
			tool = Console.ReadLine();

			Console.Write("Please give me the name of a sea creature: ");
			seaCreature = Console.ReadLine();

			//Create some blank lines
			Console.WriteLine();
			Console.WriteLine();

			//Write the story
			Console.WriteLine("One day there was a person named {0}. Now, {0} was usually ", person);
			Console.WriteLine("very content to work as a {0}, but sometimes the job ", occupation);
			Console.WriteLine("was very difficult.");
			Console.WriteLine("One day, {0} discovered that the heartbreak of {1} had ", person, problem);
			Console.WriteLine("occured just one time too often. \"I can't stand being a ");
			Console.WriteLine("{0} anymore!\" yelled {1}, as he hurled away his ", occupation, person);
			Console.WriteLine("{0} in anger. No {1} will keep me from fulfilling", tool, problem);
			Console.WriteLine("my dreams! What I really want, said {0}, is to be just like", person);
			Console.WriteLine("{0}. Now THAT's somebody to admire. So {1} put away the ", friend, person);
			Console.WriteLine("{0} forever, and followed {1} into the pastoral", tool, friend);
			Console.WriteLine("world of {0}-ranching. Eventually, {1} was able to ", animal, person);
			Console.WriteLine("retire, as happy as a {0}", seaCreature);

			//Create some blank lines
			Console.WriteLine();
			Console.WriteLine();

			//Ask for Enter to quit
			Console.WriteLine("Please press Enter to continue");
			Console.ReadLine();
		}
	}
}
