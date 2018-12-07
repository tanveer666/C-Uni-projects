
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int word_count(char*);
char* char_count(char*,int*);
char ** sentence_split(char*,int);

int main()
{
    char input[81];
    gets_s(input,81);

    int num_of_words = word_count(input);

    char **pp_split = sentence_split(input,num_of_words);

	for (int i = 0; i < num_of_words; i++)
	{
		puts(*(pp_split + i))
			;
	}
    getchar();


}

/*              word_count              */
int word_count(char* p_input) //Counts the number of word in a string by counting the spaces. By default it is one.
{
    char* p_first = p_input;
    char* p_last = strrchr(p_input,' ');
    char* p_curr;
    int word_num = 1;

    while(1) //infinite loop!
    {
        p_curr = strchr(p_first,' '); //p_curr points to the first occurance of the string p_first.
        if(p_curr == NULL)
        {
            return word_num; //This is the exit condition for the loop, when p_first is at the last word, p_curr is NULL as there is no space after it. so it will break the loop and funtion by returning the word number;
        }
		*p_curr = 0;

        word_num++; //increments the word counter
        p_first = p_curr+1; //p_first points to the element after the space, so when the second interation starts it is not pointing to a space
    }

    return word_num;

}

/* --------- char_count () ----------- */
char* char_count(char* p_input,int* p_char_ctr) //counts the number of char in a particular word.
{
    char* p_first = p_input; //takes in the input string
    char* p_last = strchr(p_input,0);
    *p_char_ctr = p_last - p_first; //the number is char is simply the subtraction of 2 address, it is the number of elements between first character and space, but the subtraction will not count space.

    return p_last+1;
}
/* ------- sentence_split() ------------ */

char** sentence_split(char* p_input, int word_num)
{
    char** pp_split = (char **)malloc(sizeof(char*) * word_num);
    int char_number = 0;
    int string_length = strlen(p_input);
    int in_ctr = 0; 

    char* p_char_count = p_input;
    for(int i = 0; i < word_num; i++)
    {
        p_char_count = char_count(p_char_count,&char_number);
        printf("char number%d:\n",char_number);
        *(pp_split+i) = (char *) malloc(sizeof(char) * (char_number+1));
		strcpy(*(pp_split + i), (p_char_count - char_number - 1) ); //copies the word (including null zero from input to destination

        
    }

    return pp_split;

}