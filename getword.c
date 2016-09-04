//Name: Shad Aziz
//Instructor: Carroll
//Class: CS570 
//Due: 9/7/16

#include<stdio.h>
#include "getword.h"

//A method that takes in an array and fills it with whatever is in STDIN
//It also counts how many characters there are, ingroing whitespace.

int getword(char *w) 
{
	//Initializing variables

	int count = 0;
	int input;
	
	//Takes in STDIN a character at a time and runs the loop until it hits EOF
	
	while( (input = getchar()) != EOF)
	{
		//The rest are straight forward if statements
		
		if(input == '\n' && count == 0)
		{
			w[0] = '\0';
			ungetc('\n', stdin);
			return -1;
		}
		
		if(input == '\n' && count > 0)
		{
			w[count] = '\0';
			ungetc('\n', stdin);
			return count;	
		}
		
		if(input == ' ' && count > 0)
		{
			w[count] = '\0';
			return count;	
		}
		
		if(input == ' ' && count == 0)
			continue;
		
		w[count] = (char)input;
		count++;
	}
	
	//If an EOF is hit it will erase everything in the array and spit out a -2
	
	w[0] = '\0';
	return -2;
}
