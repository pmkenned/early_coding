#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_WORDS 100

char * program_name = "flash";

struct entry
{
	char word[512];
	char definition[512];
};

int open_dictionary(struct entry * words, FILE * fd);

int main(int argc, char ** argv)
{
	FILE * dictionary = NULL;	/* file which contains definitions */
	char buffer[BUFSIZ];		/* used for retrieving definitions */
	char answer[BUFSIZ];		/* holds user answer */
	int correct;			/* 0: correct non-0: incorrect */
	struct entry words[MAX_WORDS];
	struct entry foo;
	int rand_index;
	int num_of_words;

	if(argc < 2)
	{
		printf("usage: %s [FILE]\n", program_name);
		exit(1);
	}

	dictionary = fopen(argv[1], "r");	/* open the dictionary file */

	if(dictionary == NULL)	/* if the file failed to open */
	{
		printf("error: cannot open file %s\n", argv[1]);
		exit(1);
	}

	num_of_words = open_dictionary(words, dictionary);

	while(1)
	{
		rand_index = (int)(random(num_of_words));

		printf("%s\n",words[rand_index].definition);
		fgets(answer,BUFSIZ,stdin);
		correct = strncmp(answer, words[rand_index].word, BUFSIZ);
		if(correct == 0)
			printf("correct\n");
		else
			printf("%s\n",words[rand_index].word);
	}

	fclose(dictionary);

	return 0;
}

int open_dictionary(struct entry * words, FILE * fd)
{
	int i;
	char buffer[BUFSIZ];

	for(i=0; (feof(fd) == 0) && (i<MAX_WORDS); i++)
	{
		fgets(buffer,BUFSIZ,fd);
		strncpy(words[i].definition, buffer, BUFSIZ);
		fgets(buffer,BUFSIZ,fd);
		strncpy(words[i].word, buffer, BUFSIZ);

/*		printf("%s\n", words[i].definition); */
	}

	if(i >= MAX_WORDS)
		printf("number of words in dictionary exceed MAX_WORDS\n");
	return i;
}
