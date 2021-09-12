/*
caesar cipher : 

rot 1: 
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
B C D E F G H I J K L M N O P Q R S T U V W X Y Z A 

rot 2:
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
C D E F G H I J K L M N O P Q R S T U V W X Y Z A B 

rot 3: 
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
D E F G H I J K L M N O P Q R S T U V W X Y Z A B C

Encode :

rot 1:

input  : ABC
output : BCD

rot 2:

input  : ABC
output : CDE

rot 3 : 

input  : ABC 
output : DEF 

Hints : 90 - 26 + shift

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define VERSION 	"1.0"
#define AUTHOR 		"vasanth"

const int upper = 65;
const int lower = 97;
const int total_words = 26;

char upper_case[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char lower_case[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };


/*
upper and lower find :
A-Z    ->  1
a-z    ->  0
others -> -1
*/

// find index
int find_index(char Char){
	int char_index = -1;

	// get values from uppercase
	if(isupper(Char) != 0 && isupper(Char) == 256){
		for(short upper_index=0; upper_index<strlen(upper_case); upper_index++){
		
			// matching char `index`
			if(upper_case[upper_index] == Char) char_index = upper_index;
		}
	}
	else if(islower(Char) != 0 && islower(Char) == 512){
		for(short lower_index=0; lower_index < strlen(lower_case); lower_index++){

			// match char `index`
			if(lower_case[lower_index] == Char) char_index = lower_index;
		}
	}
	return char_index;
}

/*
Encrypt :
e = (p + k) % 26
*/ 
void Encrypt(char text[], int shift){
	int e; 

	// caesar cipher 
	for(int Char=0; Char<strlen(text); Char++){
		// printf("%c", text[Char]);
		// check upper 
		if(isupper(text[Char]) != 0 && isupper(text[Char]) == 256){

			// find ( e )
			e = (find_index(text[Char]) + shift) % total_words;
			printf("%c", upper_case[e]);
		}
		// check lower
		else if(islower(text[Char]) != 0 && islower(text[Char]) == 512){

			// find ( e )
			e = (find_index(text[Char]) + shift) % total_words;
			printf("%c", lower_case[e]);
		}
		// others 
		else printf("%c", text[Char]);

	}

	printf("\n");
}

/*
Decryption :

d = (p - k) % 26

d = -1 + 26

*/
void Decrypt(char text[], int shift){
	int d;

	// get plaintext values one by one char
	for(int Char=0; Char<strlen(text); Char++){

		// check upper
		if(isupper(text[Char]) != 0){

			// find ( d )
			d = (find_index(text[Char]) - shift) % total_words;
			// printf("%d %c ", d, text[Char]);
			
			if((abs(d) / d) == -1) printf("%c", upper_case[d + 26]);
			else printf("%c", upper_case[d]);
		}

		// check lower
		else if(islower(text[Char]) != 0 ){

			// find ( d )
			d = (find_index(text[Char]) - shift) % total_words;			

			if(abs(d) / d == -1) printf("%c", lower_case[d + 26]);
			else printf("%c", lower_case[d]);
		}

		// others
		else printf("%c", text[Char]);

	}

	printf("\n");	
}

// help 
void help(){
	printf("optional arguments : \n");
	printf("    --help, -h			show help\n");
	printf("    --version, -v		show version\n");
	printf("\nrequired arguments : \n");
	printf("    --rotate, -r		number of shift(default 13)\n");
	printf("    --string, -s		input string\n\n");
	printf("options : \n");
	printf("    --encrypt, -e		encrypt input string\n");
	printf("    --decrypt, -d		decrypt input string\n\n");
	printf("Example : \n");
	printf("	caesar-cipher -r 13 -s ABC -e\n");
	printf("	caesar-cipher -r 13 -s CDE -d\n");
}

int main(int argc, char *argv[]){
	// default 
	int shift = 13;
	const int size = 1024;
	char input_string[size];

	// printf("%d\n", find_index('Z'));

	// Encrypt("abcdez123", 1);
	// Decrypt("BCDA bcda", 1);	

	if( 1 < argc ){
		
		// check help option
		if(argc == 2){
			// input argument `help`
			if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) help();
			else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) printf("%s\n", VERSION);
		}

		// check rotate option
		else if(argc == 6){
			// input argument `rotate`
			if(strcmp(argv[1], "--rotate") == 0 || strcmp(argv[1], "-r") == 0){
				if(!argv[2]){
					printf("Please Specify The Rotate Number");
				}
				// get rotate number
				else shift = atoi(argv[2]);
			}

			// input argument `strings`
			if(strcmp(argv[3], "--string") == 0 || strcmp(argv[3], "-s") == 0) {
				if(!argv[4]){
					printf("Please Specify The Encrypt String \n", argv[2]);
				}
				else{
					// copy string
					if(strlen(argv[4]) < size) strcpy(input_string, argv[4]);
				}
			}

			// input argument `type`
			if(strcmp(argv[5], "--encrypt") == 0 || strcmp(argv[5], "-e") == 0){
				// encrypt 
				Encrypt(input_string, shift);
			}
			else if(strcmp(argv[5], "--decrypt") == 0 || strcmp(argv[5], "-d") == 0){
				// decrypt 
				Decrypt(input_string, shift);
				// Decrypt("CDE", 2); // output : ABC
			}
		}
		else help();
	}
	else exit(1);

	return 0;
}