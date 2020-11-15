#include <iostream.h>
#include <string.h>
#include <sstream.h>
#include <direct.h>

int main(void)
{
	std::string PS1 = "# ";
	std::string args;
	char user_input[256];

	do
	{
		cout << PS1;
		cin.getline(user_input, 255);
		args = user_input;
		std::stringstream os(user_input);

		if(strncmp(user_input, "ls", 2) == 0)
		{
			os >> user_input;
			os >> user_input;

			if (strncmp(user_input, "-a", 2) == 0)
				system("dir /b/p/a");
			else
				system("dir /b/p");
		}
		else if(strncmp(user_input, "pwd", 2) == 0)
		{
			os >> user_input;
			os >> user_input;

			system("cd");
		}
		else if(strncmp(user_input, "cd", 2) == 0)
		{
			os >> user_input;
			os >> user_input;

			chdir(user_input);
		}
		else if(strncmp(user_input, "cp", 2) == 0)
		{
			os >> user_input;
			os >> user_input;

			char cmd[256] = "copy ";
			strcat(cmd, user_input);
			strcat(cmd, " ");
			os >> user_input;
			strcat(cmd, user_input);
			system(cmd);
		}
		else if(strncmp(user_input, "less", 4) == 0)
		{
			os >> user_input;
			os >> user_input;

			char cmd[256] = "type ";
			strcat(cmd, user_input);
			system(cmd);
			cout << endl;
		}
		else if(strncmp(user_input, "clear", 5) == 0)
			system("cls");
		else if(strncmp(user_input, "ifconfig", 8) == 0)
			system("ipconfig");
		else if(strncmp(user_input, "fsck", 4) == 0)
			system("chkdsk");
		else if(strncmp(user_input, "mv", 2) == 0)
		{
			os >> user_input;
			os >> user_input;

			char cmd[256] = "rename ";
			strcat(cmd, user_input);
			strcat(cmd, " ");
			os >> user_input;
			strcat(cmd, user_input);
			system(cmd);
		}
		else if(strncmp(user_input, "rm", 2) == 0)
		{
			os >> user_input;
			os >> user_input;

			char cmd[256] = "del ";
			strcat(cmd, user_input);
			system(cmd);
		}
		else if(strncmp(user_input, "rmdir", 5) == 0)
		{
			os >> user_input;
			os >> user_input;

			char cmd[256] = "rd ";
			strcat(cmd, user_input);
			system(cmd);
		}
		else if(strncmp(user_input, "mkdir", 5) == 0)
		{
			os >> user_input;
			os >> user_input;

			mkdir(user_input);
		}
		else if(strncmp(user_input, "diff", 4) == 0)
		{
			os >> user_input;
			os >> user_input;

			char cmd[256] = "fc ";
			strcat(cmd, user_input);
			strcat(cmd, " ");
			os >> user_input;
			strcat(cmd, user_input);
			system(cmd);
		}
		else if(strncmp(user_input, "exit", 4) == 0){}
		else
		{
			cout << user_input  << ": not known" << endl;
		}
	}
	while(strcmp(user_input, "exit") != 0);

	return 0;
}