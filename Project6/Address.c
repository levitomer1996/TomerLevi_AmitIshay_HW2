#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address.h"
#include "functions.h"



void initAddress(Address* pAd)
{
	int pSize = 0;
	int finalPos = 0;
	char* dynStr = createDynStr("Please insert adress: ");
	char** adress = removeHashTagsFromString(dynStr, &pSize);
	pAd->street = adress[0];
	//void addDoubleSpace(Address* pAd);
	pAd->houseNumber = adress[1];
	pAd->city = adress[2];
    getTextWithOutSpaces(pAd->street);
    getTextWithOutSpaces(pAd->city);
	printAddress(pAd);
}


void printAddress(const Address* pAd)
{
	printf("Adress: %s %s, %s", pAd->street, pAd->houseNumber, pAd->city);
}

void freeAddress(Address* address) {
    free(address->houseNumber);
    free(address->street);
    free(address->city);

}


void getTextWithOutSpaces(char* str)
{
    // Allocate memory for the result string
    char* result = malloc(strlen(str) * 3 + 1); // *3 for the spaces, +1 for the null terminator
    int resultIndex = 0;

    // Use strtok to split the string into tokens separated by space characters
    const char delim[2] = " ";
    char* token = strtok(str, delim);
    while (token != NULL) {
        // Capitalize the first letter of the token
        if (token[0] >= 'a' && token[0] <= 'z') {
            token[0] = token[0] - 'a' + 'A';
        }

        // Copy the capitalized token into the result string
        strcpy(result + resultIndex, token);
        resultIndex += strlen(token);

        // Insert two space characters after the token
        result[resultIndex++] = ' ';
        result[resultIndex++] = ' ';

        // Get the next token
        token = strtok(NULL, delim);
    }

    // Make the last word lowercase
    if (resultIndex > 0 && result[resultIndex - 1] == ' ' && result[resultIndex - 2] == ' ') {
        result[resultIndex - 3] = tolower(result[resultIndex - 3]);
    }

    // Remove the last two space characters, if any
    if (resultIndex > 0 && result[resultIndex - 1] == ' ' && result[resultIndex - 2] == ' ') {
        result[resultIndex - 2] = '\0';
    }

    // Add the null terminator to the result string
    result[resultIndex] = '\0';

    // Copy the result string back into the input string
    strcpy(str, result);

    // Free the memory allocated for the result string
    free(result);
}
