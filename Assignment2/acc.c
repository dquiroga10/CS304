/*
Danny Quiroga
October 1, 2019
CSCI 304
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char letter = ' ', mode = 'D';
short acc;
short number = 0;
char string[10];

short get_opperand(char mode){
	if(letter =='c' || letter == 'C'){ //checking to make sure c was not clicking, if so return 0 for the accumulator
		return 0;
	}
	switch(mode){//scan proper value based off the mode that is selected currently
		case 'D':
			printf("Enter decimal value: ");
			scanf("%hd", &number);
			printf("%hd\n", number);
			return number;
			break;
		case 'H':
			printf("Enter hex value: ");
			scanf("%04hX", &number);
			printf("%hX\n", number);
			return number;
			break;
		case 'O':
			printf("Enter octal value: ");
			scanf("%06ho", &number);
			printf("%ho\n",number);
			return number;
			break;
		default:
			return 0;
			break;
	}
}

void print_acc(short acc){ //print the accumulator with the proper values and correct spacing of the stars 
			
	printf("\n**************************************\n");
	printf("* Accumulator:%-23c*\n",' ');
	printf("*   Hex%-5c:  %04hX %-17c*\n",' ',acc, ' ');
	printf("*   Octal%-3c:  %06ho %-15c*\n",' ', acc, ' '); 
	printf("*   Decimal :  %-22d*\n",acc); 
	printf("**************************************\n");

	// printf(" ****************************************\n * Accumulator: \n *\t Hex: %x \n *\t Octal: %o \n *\t Decimal: %d \n ****************************************\n", hex, oct, decimal);
}

char print_menu(void){//prints out the menu with the proper spacing
	printf("\nPlease select one of the following options: \n");
	printf("\nO  Octal Mode ");
	printf("\nH  Hexadecimal Mode "); 
	printf("\nD  Decimal Mode \n");
	printf("\nC  Clear Accumulator ");
	printf("\nS  Set Accumulator \n");
	printf("\nQ  Quit \n\nOption: ");
	return 'd';
}

int main(void){//the main loop that keeps the program running until Q is slected 
	// scanf("%s", (char *) &string);
	// printf("%d\n",(int) strlen(string) );
	// printf("%s\n",string );

	print_acc(0);
	print_menu();
	scanf("%s", (char *) &string);
	//printf("%c \n", letter);
	while (letter != 'Q' && letter != 'q'){

		if(strlen(string) > 1){//error handling for stirngs greater than length 1 
			printf("%s\n\nInvalid option: %s\n", string, string);
			print_menu();
			letter = ' ';
			scanf("%s", (char *) &string);
		}
		else{//uses index 0 to see what letter is selected 
			letter = string[0];


			switch(letter){
				case 'h':
					printf("%c\n", letter);
					mode = 'H';
					printf("Mode is Hexadecimal\n");
					print_acc(number);
					print_menu();
					break;
				case 'H':
					printf("%c\n", letter);
					mode = 'H';
					printf("Mode is Hexidecimal\n");
					print_acc(number);
					print_menu();
					break;
				case 'O':
					printf("%c\n", letter);
					mode = 'O';
					printf("Mode is Octal\n");
					print_acc(number);
					print_menu();
					break;
				case 'o':
					printf("%c\n", letter);
					mode = 'O';
					printf("Mode is Octal\n");
					print_acc(number);
					print_menu();
					break;
				case 'D':
					printf("%c\n", letter);
					mode = 'D';
					printf("Mode is Decimal\n");
					print_acc(number);
					print_menu();
					break;
				case 'd':
					printf("%c\n", letter);
					mode = 'D';
					printf("Mode is Decimal\n");
					print_acc(number);
					print_menu();
					break;


				case 's':
					printf("%c\n", letter);
					print_acc(get_opperand(mode));
					print_menu();
					break;
				case 'S':
					printf("%c\n", letter);
					print_acc(get_opperand(mode));
					print_menu();
					break;


				case 'c':
					printf("%c\n", letter);
					print_acc(0);
					number = 0;
					print_menu();
					break;
				case 'C':
					printf("%c\n", letter);
					print_acc(0);
					number = 0;
					print_menu();
					break;

				case 'Q':
					break;

				case 'q':
					break;

				case ' ':
					break;

				case '\n':
					break;

				case '\t':
					break;

//default case for when no valid option is chosen and prints out the invalid option properly

				default:
					printf("%c\n\nInvalid option: %c\n", letter, letter);
					print_menu();

			}

			scanf("%s", (char *) &string);
		}
		//printf("%c \n",letter);
	}
	printf("%c\n", letter);
}
