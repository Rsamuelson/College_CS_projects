//FRIDAY
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define EMPTY_SPACE ' '

char UpperCase[26] = 
{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','U','T','U','V','W','X','Y','Z'};

char LowerCase[26] =
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

/* 
Pre: The original plaintext phrase with spaces is passed in.
The function searches for a space.  When found,
the spece is removed by shifting all remaining elements 
in the array one space to the left.  
Post: The plaintext phrase has been modified so it no longer
contains spaces.
*/
void RmSpaces (char plaintext[]);
/* 
Pre: The plaintext phrase with the spaces removed is passed in.
Each character in the plaintext phrase is converted to lowercase.  
Post: The plaintext phrase has been modified so it no longer
has any uppercase letters in it.
*/

void MkLowerCase (char plaintext[]);

/* 
Pre: The plaintext phrase with the spaces removed, the key, the alphabet, 
the array to store the secret phrase, and the flag are passed in.  A true flag value
means the function should encrypt the plaintext phrase.  A false flag value 
means the function should decrypt the plaintext phrase.  
Post: Both the plaintext and the secret phrase arrays are filled.
*/

void EncryptDecrypt (int flag, char encryption[], char plaintext[], char secretkey[], char alphaList[] );
/* 
Pre: The plaintext phrase and the secret phrase are passed in.  
Post: The plaintext phrase and the secret phrase are printed.
*/
void PrintOutput (char plaintext[], char encryption[]);

int main (int argc, char* argv[]) {
	char alphabet[26] = 
	{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char key[26] = 
	{'n', 'o', 'p', 'q', 'r', 's', 't', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'};
	
	char phrase[100] = "These are not the droids you are looking for";
	char secretphrase[100];
	
	//Write your function calls here.  
	RmSpaces(phrase);
	//printf("%s\n", phrase);
	MkLowerCase(phrase);
	//printf("%s\n", phrase);
	EncryptDecrypt(TRUE, secretphrase, phrase, key, alphabet);
	PrintOutput(phrase, secretphrase);
	
	
	return 0;
	
}

//Write your functions here.  

void RmSpaces (char plaintext[]){
	int x, j;
	for(x = 0; x < 100; x++){
		if(isspace(plaintext[x])){
			plaintext[x] = plaintext[x + 1];
		}
		// for(j = 0; j < 100; j++){
			// plaintext[j + x] = plaintext[j + x +1];
		// }
	}
	
}

void MkLowerCase (char plaintext[]){
	int x,j;
	for(x = 0; x < strlen(plaintext); x++){
		for(j = 0; j < 26; j++){
			if(plaintext[x] == UpperCase[j]){
				plaintext[x] = LowerCase[j];
			}
		}
	}
}

void EncryptDecrypt (int flag, char encryption[], char plaintext[], char secretkey[], char alphaList[] ){
	
	//encrypt
	int x, j;
	if(flag == 1){
		for(x = 0; x < strlen(plaintext); x++){
			for(j = 0; j < 26; j++){
				if(plaintext[x] == alphaList[j]){
					encryption[x] = secretkey[j];
				}
			}
		}
	}
	//decrypt
	
	if(flag == 0){
		for(x = 0; x < strlen(encryption); x++){
			for(j = 0; j < 26; j++){
				if(encryption[x] == secretkey[j]){
					plaintext[x] = alphaList[j];
				}
			}
		}
	}
}

void PrintOutput (char plaintext[], char encryption[]){
	printf("The plain text is %s.\n", plaintext);
	printf("The secret phrase is %s.", encryption);
}