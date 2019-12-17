/*
 * txtfind.c
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
       if (*str == *(word+i)){ //check if the char  is equals
          i++;
          if (strlen(word)==i) return 1; //return true
       }
       else
       {
                 i=0;
       }

       str++;
       }
return 0; // return false

}

// This functin check if the word similiar until num of change to str
int similar (char *str, char *word, int change)
{
          int i=0;
          int j=-1; // num of mistake
       while (*str!='\0')
       {
       if (*str == *(word+i)){
          i++;
          if (strlen(word)==i) return 1;
       }
       else // if the char is not equals
       {
                 j++; // num of mistake
                 if (j==change){
                    i=0;
                    j=0;
                 }

       }

       str++; // pointers ++
       }

return 0;

}


// this function need to split word from str
//have a problem with function
int word_split( char *str, char *word, int counter){
//           printf("%d""\n", sub);

          int i=0;
           while ((*str!=' '))
          {
          *(word)= *(str+counter);
          word++;
          str++;
          i++;
          }
          *word='\0';
          return i+1;
}
//this function need to split lines

int line_split( char *str, char *word, int counter)
{

          int i=0;
           while ((*str!='\0')) //need to change to \n or '\0'
          {
          *(word)= *(str+counter);
          word++;
          str++;
          i++;
          }
          *word='\0';
          return i+1;
}

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
		SizeLine++;
		s[SizeLine]=letter;
		letter = getchar();
	}
	s[SizeLine]='\0'; // end of the srtring;

	return SizeLine;

}



int getword(char w[])
{
	int SizeWord = 0;
	char letter = getchar();

	while((letter != EOF)&&(letter != ' ') &&(letter != '\t')&&(letter != '\n') && (SizeWord < WORD))
	{
		SizeWord++;
		w[SizeWord]=letter;
		letter = getchar();
	}
	w[SizeWord]='\0'; // end of the srtring;

	return SizeWord;

}


void print_lines(char * str)
{
	char line[LINE];
	int SizeLine = getLine(line);
	while(SizeLine != 0)
	{
		if(substring(str, line)==1)
			printf("%s\n", line);

		SizeLine = getLine(line); //line.next();
	}

}



void print_similar_words(char * str)
{
	char word[WORD];
	int SizeWord = getword(word);
	while(SizeWord != 0)
	{
		if(similar(str, word,1)==1)
			printf("%s\n", word);

		SizeWord = getLine(word); //word.next();
	}

}

int main ()
{
	printf("sfdgvfcghgn ");
   //part A
   char word[WORD];
   char option;
   getword(word); //take the first word in the first line

   printf("%s",&option);
   while(option!=' ') // fllow the first line until get the option letter
	   scanf(" %c\n", &option);
   printf("%s000009",&option);
   //Part B

   	if(option == 'a')
   		print_lines(word);

   	else if(option == 'b')
   		print_similar_words(word);


   	return 0;

   }




