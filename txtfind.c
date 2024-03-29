/*
 * txtfind.c
 *
 *
 * Aouters: Ginton & fooxi
 *
 *
 */
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30


// This function need to check if str contain word

int substring (char *str, char *word)
{
  int i=0;

  while (*str!='\0')
  {
     if (*str == *(word+i))
     { //check if the char  is equals
        i++;
        if (strlen(word)==i)
        	return 1; //return true
     }
     else
    	 i=0;

     str++;
   }
return 0; // return false

}




// This functin check if the word similiar until num of change to str
int similar (char *s, char *t, int n)
{
	int i=0;
    int j=-1;// num of mistake

    if (strlen(s)>strlen(t)+n)
    	return 0;

    while (*s!='\0')
    {
    	if (*s == *(t+i))
    	{
    		i++;
    		if (strlen(t)==i)
    			return 1;
    	}

    	else // if the char is not equals
    	{
    		j++; // num of mistake
            if (j==n)
              {
                 i=0;
                 j=0;
              }

    	 }

       s++; // pointers ++
     }

return 0;
}

//*************************************

int getLine(char s[])
{
	int SizeLine = 0;
	char letter = getchar();

		while(letter=='\n')  //remove the spare whitelines in the begening of the file.
			letter = getchar();

	if(letter==EOF) //if the input is empty.
		return 0;

	while((letter != EOF) &&(letter != '\n') && (SizeLine < LINE))
	{
		s[SizeLine]=letter;
		SizeLine++;
		letter = getchar();
	}
	s[SizeLine]='\0'; // end of the srtring;

	return SizeLine;

}

//*********************************************************

int getword(char w[])
{
	int SizeWord = 0;
	char letter = getchar();

	while((letter != EOF)&&(letter != ' ') &&(letter != '\t')&&(letter != '\n') && (SizeWord < WORD))
	{
		w[SizeWord]=letter;
		SizeWord++;
		letter = getchar();
	}



	w[SizeWord]='\0'; // end of the srtring;


	return SizeWord;

}

//*****************************************************


void print_lines(char * str)
{
	char line[LINE];
	int SizeLine = getLine(line);

	while(SizeLine != 0)
	{
		if(substring(line, str)==1)
			printf("%s\n", line);

		SizeLine = getLine(line); //line.next();
	}

}

//*****************************************************

void print_similar_words(char * str)
{
	char word[WORD];
	int SizeWord = getword(word);


	while(SizeWord != 0)
	{

		if(similar(word, str,1)==1)
			printf("%s\n", word); //check it


		SizeWord = getword(word); //word.next();
	}


}

//******************************************************

int main ()
{

   //part A
   char word[WORD];
   char option;

   getword(word); //take the first word in the first line



   scanf(" %c\n" , &option);




   //Part B

   	if(option == 'a')
   		print_lines(word);

   	else if(option == 'b')
   		print_similar_words(word);


}

