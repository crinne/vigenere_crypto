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
#define ENCRYPT 0
#define DECRYPT 1
#define viegner(x, y) rot(ENCRYPT, x, y)
#define deviegner(x, y) rot(DECRYPT, x, y)

// Function prototypes
void rot(int z, char *shifer, char *str);
void remove_newline_ch(char *line);
int get_shift_num(char d);
void print_usage(char *argv[]);


int main(int argc, char *argv[]) {

    int decrypt = 0;
    int encrypt = 0;
    char *shiffer;

    if (argc != 3) {
        //fprintf(stderr, "You need to give 1 arguments\n");
        print_usage(argv);
        return 1;
    }

    char ch;
    while ((ch = getopt(argc, argv, "des:")) != EOF)

        switch (ch) {
            case 'd':
                decrypt = 1;
                break;
            case 'e':
                encrypt = 1;
                break;
            case 's':
                shiffer = strdup(optarg);
                break;
            default:
                fprintf(stderr, "Unknown option '%s'\n", optarg);
                return 1;
        }

    char str[180];
    printf("Enter sentence: ");
    fgets(str, sizeof(str), stdin);
    remove_newline_ch(str);

    if (encrypt) {
        viegner(shiffer, str);
        printf("Encrypted: %s\n", str);
    }

    else if (decrypt) {
        deviegner(shiffer, str);
        printf("Decrypted: %s\n", str);
    }
    else {
        printf("Original: %s\n", str);
    }

	return 0;
}


void rot(int z, char *shifer, char *str)
{

	int l = strlen(str);
	const char *alpha[2] = { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  int index = 0;
  int count = 0;
  int i, c;

	for (i = 0; i < l; i++)
	{
		if (!isalpha(str[i]))
			continue;

		if (isupper(str[i]))
			index = 1;

      if (z) {
        c = (26 - get_shift_num(shifer[count]));
      } else {
        c = get_shift_num(shifer[count]);
      }

		str[i] = alpha[index][((int)(tolower(str[i])-'a')+c)%26];
		index = 0;
    count++;
    if (shifer[count] == '\0') {
        count = 0;
    }
	}
}

int get_shift_num(char d) {

  int temp = 0;
  const char alpha[] = {"abcdefghijklmnopqrstuvwxyz"};
  int i;
  for (i = 0; i < strlen(alpha); i++) {
    if (tolower(d) == alpha[i]) {
      temp = i;
      break;
    }
  }
  return temp;
}

void remove_newline_ch(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

void print_usage(char *argv[]) {

    printf("Usage: %s [option][shiffer]\n", argv[0]);
    printf("\nOptions:\n\n");
    printf(" -h\t\t Print usage\n");
    printf(" -d\t\t Decrypt the message\n");
    printf(" -e\t\t Encrypt the message\n");
    printf(" -s\t\t shiffer\n");

}
