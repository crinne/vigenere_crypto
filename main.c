/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Caesar cipher
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *         Author:  Caspar Rinne, caspar.rinne@gmail.com
 *
 * ===========make
 ==========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>

// Constants
#define caesar(x, y) rot(13, y)
#define decaesar(x, y) rot((26 - 13), y)

// Function prototypes
void remove_newline_ch(char *line);
void rot(int c, char *str);
void print_usage(char *argv[]);
int get_num_of_shift(char arr[]);

int main(int argc, char *argv[]) {
    
    //int decrypt = 0;
    //int encrypt = 0;
    //int shiffer = 0;


    

    
    char str[80] = "Caspar is cool!";	
    //printf("Enter sentence: ");
    //fgets(str, sizeof(str), stdin);
    //remove_newline_ch(str);

    printf("Tell me an shffer: ");
    char shiffer[80] = "hello";
    // scanf("%s", shiffer);

    int i;
    int j = 0;

    char shiffer_string[80];

    for (i = 0; str[i] != '\0'; i++) {
        
        if (tolower(str[i]) >= 97 && tolower(str[i]) < 122) {
        
            shiffer_string[i] = shiffer[j];
            j++;
        }
        else {
            
            shiffer_string[i] = str[i];
        }
     
        
        if (shiffer[j] == '\0') 
            j = 0;


    }

    puts("++++++++++++++++++");

    for (i = 0; shiffer_string[i] != '\0'; i++) {
        
        printf("%c", shiffer_string[i]);
    }
    puts("");

    for (i = 0; str[i] != '\0'; i++) {
        
        printf("%c", str[i]);
    }
    puts("");


	return 0;
}


int get_num_of_shift(char arr[]) {

    int temp;
    
    const char *alpha[] = {"abcdefghijklmnopqrstuvwxyz"};
    

    return temp;


}

void rot(int c, char *str)
{
	int l = strlen(str);
	const char *alpha[2] = { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        int index = 0;
	int i;
	for (i = 0; i < l; i++)
	{
		if (!isalpha(str[i]))
			continue;
			
		if (isupper(str[i]))
			index = 1;

		str[i] = alpha[index][((int)(tolower(str[i])-'a')+c)%26];
		index = 0;
	}
}

void remove_newline_ch(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

