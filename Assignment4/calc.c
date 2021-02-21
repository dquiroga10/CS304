/*
Danny Quiroga
October 18, 2019
CSCI 304
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned short get_binary_op (char *bin){
	int power[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768}; //this is a list that contains all of the powers of two i will need in order to convert the binary to a decimal value 
	int index = 0;
	int i = 0;
	unsigned short val = 0; //this will be the variable that keeps track of what the value is currently 
	while(index < 20){

		if(bin[index] == '1'){
			val += (unsigned short) power[15 - i];//this will check where the 1 is located and then add that specific value in base 10 to the temp variable val 
			i++;
		}
		else if(bin[index] == '0'){ //if it is a 0 we will just increment i
			i++;
		}
		index++;
	}
	val = (val>>(16 - i)); //since the value is based off how long the string is. we want to shift the value properly bitwise to account for all the leading 0s that were not inputted 
	return val;
}

void convert_to_binary (short acc, char *bin){
	int power[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768}; //this is a list that contains all of the powers of two i will need in order to convert the binary to a decimal value 
	int i = 0; //this is keeping track of the binary position 
	int index; //this will keep track of how many characters have been added 
	int count = 0; //this is the variable that will be keeping track of the grouping in order to have proper formatting 

	for(index = 0; index < 19; index++){
//the if statements will add the proper character in the proper location on the string 
		if(acc < 0){
			bin[index] = '1';
			acc += (short) power[15 - i];
			count++;
			i++;
		}

		else if(count == 4){
			bin[index] = ' ';
			count = 0;
		}
		else if(acc >= power[15 - i]){
			bin[index] = '1';
			acc -= (short) power[15 - i];
			i++;
			count++;
		}
		else{
			bin[index] = '0';
			i++;
			count++;
		}

	}
}

short get_opperand(char mode){

	char input[20];
	short numIn;

	// if(letter =='c' || letter == 'C'){ //checking to make sure c was not clicking, if so return 0 for the accumulator
	// 	return 0;
	// }
	switch(mode){//scan proper value based off the mode that is selected currently
		case 'D':
			printf("Enter decimal value: ");
			scanf("%hd", &numIn);
			printf("%hd\n", numIn);
			return numIn;
			break;
		case 'H':
			printf("Enter hex value: ");
			scanf("%04hX", &numIn);
			printf("%hX\n", numIn);
			return numIn;
			break;
		case 'O':
			printf("Enter octal value: ");
			scanf("%06ho", &numIn);
			printf("%ho\n",numIn);
			return numIn;
			break;
		case 'B':
			printf("Enter binary value: ");
			scanf("%s", (char *) &input);
			printf("%s\n",input);
			numIn = (short) get_binary_op(input);
			return numIn;

		default:
			return 0;
			break;
	}
}
//this function just adds the values of the passed in acc value and what is inputted 
// we use a pointer to update the actual acc value after the addition 
void add(short *acc, char mode){
	short intnum;
	short* num = acc;
	short init = *num;
	intnum = get_opperand(mode);
	*num += intnum;
	//cases for overflow 
	if((init > 0) && (intnum > 0) && (*num < 0)){
		printf("Overflow Error\n");
	}
	else if(init < 0 && intnum < 0 && *num > 0){
		printf("Negative Overflow Error\n");
	}
}

//this function just subtracts the values of the passed in acc value and what is inputted 
// we use a pointer to update the actual acc value after the subtraction 
void substract(short *acc, char mode){
	short intnum;
	short* num = acc;
	short init = *num;
	intnum = get_opperand(mode);
	*num -= intnum;
	//cases for overflow 
	if((init > 0) && (intnum < 0) && (*num < 0) ){
		printf("Overflow Error\n");
	}
	else if((init < 0) && (intnum > 0) && (*num > 0) ){
		printf("Negative Overflow Error\n");
	}
	
}

void print_acc(short acc){ //print the accumulator with the proper values and correct spacing of the stars 
	char binary[20] = "0000 0000 0000 0000";
	convert_to_binary(acc, binary);
	printf("\n**************************************\n");
	printf("* Accumulator:%-23c*\n",' ');
	printf("*   Binary  :  %-22s*\n", binary );
	printf("*   Hex%-5c:  %04hX %-17c*\n",' ',acc, ' ');
	printf("*   Octal%-3c:  %06ho %-15c*\n",' ', acc, ' '); 
	printf("*   Decimal :  %-22d*\n",acc); 
	printf("**************************************\n");
}

char print_menu(void){//prints out the menu with the proper spacing
	char op;
	char option[10];

	printf("\nPlease select one of the following options: \n");
	printf("\nB  Binary Mode             &  AND with Accumulator           +  Add to Accumulator");
	printf("\nO  Octal Mode              |  OR  with Accumulator           -  Subtract from Accumulator");
	printf("\nH  Hexadecimal Mode        ^  XOR with Accumulator           N  Negate Accumulator"); 
	printf("\nD  Decimal Mode            ~  Complement Accumulator\n");
	printf("\nC  Clear Accumulator       <  Shift Accumulator Left");
	printf("\nS  Set Accumulator         >  Shift Accumulator Right\n");
	printf("\nQ  Quit \n\nOption: ");

	scanf("%s", (char *) &option);


	while(strlen(option) > 1){
		printf("%s\n\nInvalid option: %s\n", option, option);
		printf("\nPlease select one of the following options: \n");
		printf("\nB  Binary Mode             &  AND with Accumulator           +  Add to Accumulator");
		printf("\nO  Octal Mode              |  OR  with Accumulator           -  Subtract from Accumulator");
		printf("\nH  Hexadecimal Mode        ^  XOR with Accumulator           N  Negate Accumulator"); 
		printf("\nD  Decimal Mode            ~  Complement Accumulator\n");
		printf("\nC  Clear Accumulator       <  Shift Accumulator Left");
		printf("\nS  Set Accumulator         >  Shift Accumulator Right\n");
		printf("\nQ  Quit \n\nOption: ");

		scanf("%s", (char *) &option);
	}
	op = option[0];

	return op;
}



int main(void){//the main loop that keeps the program running until Q is slected

	char mode = 'D';
	short oper;
	int shift;
	char letter = ' ';
	short number = 0;

	print_acc(0);
	letter = print_menu();

	while (letter != 'Q' && letter != 'q'){

		switch(letter){
			case 'h':
				printf("%c\n", letter);
				mode = 'H';
				printf("Mode is Hexadecimal\n");
				print_acc(number);
				letter = print_menu();
				break;
			case 'H':
				printf("%c\n", letter);
				mode = 'H';
				printf("Mode is Hexidecimal\n");
				print_acc(number);
				letter = print_menu();
				break;
			case 'O':
				printf("%c\n", letter);
				mode = 'O';
				printf("Mode is Octal\n");
				print_acc(number);
				letter = print_menu();
				break;
			case 'o':
				printf("%c\n", letter);
				mode = 'O';
				printf("Mode is Octal\n");
				print_acc(number);
				letter = print_menu();
				break;
			case 'D':
				printf("%c\n", letter);
				mode = 'D';
				printf("Mode is Decimal\n");
				print_acc(number);
				letter = print_menu();
				break;
			case 'd':
				printf("%c\n", letter);
				mode = 'D';
				printf("Mode is Decimal\n");
				print_acc(number);
				letter = print_menu();
				break;
			case 'B':
				printf("%c\n", letter);
				mode = 'B';
				printf("Mode is Binary\n");
				print_acc(number);
				letter = print_menu();
				break;
			case 'b':
				printf("%c\n", letter);
				mode = 'B';
				printf("Mode is Binary\n");
				print_acc(number);
				letter = print_menu();
				break;


			case 's':
				printf("%c\n", letter);
				number = get_opperand(mode);
				print_acc(number);
				letter = print_menu();
				break;
			case 'S':
				printf("%c\n", letter);
				number = get_opperand(mode);
				print_acc(number);
				letter = print_menu();
				break;


			case 'c':
				printf("%c\n", letter);
				print_acc(0);
				number = 0;
				letter = print_menu();
				break;
			case 'C':
				printf("%c\n", letter);
				print_acc(0);
				number = 0;
				letter = print_menu();
				break;
			case '&':
				printf("%c\n", letter);
				oper = get_opperand(mode);
				number = (number & oper);
				print_acc(number);
				letter = print_menu();
				break;
			case '|':
				printf("%c\n", letter);
				oper = get_opperand(mode);
				number = (number | oper);
				print_acc(number);
				letter = print_menu();
				break;
			case '^':
				printf("%c\n", letter);
				oper = get_opperand(mode);
				number = (number ^ oper);
				print_acc(number);
				letter = print_menu();
				break;
			case '~':
				printf("%c\n",letter );
				number = (~number);
				print_acc(number);
				letter = print_menu();
				break;

			case 'N':
				printf("%c\n",letter );
				number = (number * -1);
				print_acc(number);
				letter = print_menu();
				break;
			case 'n':
				printf("%c\n",letter );
				number = (number * -1);
				print_acc(number);
				letter = print_menu();
				break;

			case '<':
				printf("%c\n",letter );
				printf("Enter number of positions to left shift accumulator: ");
				scanf("%d", &shift);
				printf("%d\n", shift);
				number = (number << shift);
				print_acc(number);
				letter = print_menu();
				break;
			case '>':
				printf("%c\n",letter );
				printf("Enter number of positions to right shift accumulator: ");
				scanf("%d", &shift);
				printf("%d\n", shift);
				number = (number >> shift);
				print_acc(number);
				letter = print_menu();
				break;

			case '+':
				printf("%c\n", letter);
				add(&number, mode);
				print_acc(number);
				letter = print_menu();
				break;
			case '-':
				printf("%c\n", letter);
				substract(&number, mode);
				print_acc(number);
				letter = print_menu();
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
				letter = print_menu();

			}
	}
	printf("%c\n", letter);
}