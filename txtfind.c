#include <stdio.h>
#include <string.h>
#define Line 256
#define Word 30
// This function need to check if str contain word
int subString (char *str, char *word){
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
int similiar (char *str, char *word, int change){
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
int line_split( char *str, char *word, int counter){
          
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
int main () {
   char str[50]="crat lcat meir cats"; //Ginton need to change it to scan redicration 
   char find_word[] ="cat"; // the word to find
   char word_line[Line];
   //part A
   
   //Part B
   // check similiar word and print
   char word1[Word];
   int counter = 0;

   while (*(str+counter)!='\0'){
          
 char *c =str;
int num_word = word_split(c, word1,counter);
counter= counter + num_word;
c= c+counter;
          if (similiar(word1,find_word,1)==1)
   printf("%s"" \n \n", word1); 

   }
   
}
