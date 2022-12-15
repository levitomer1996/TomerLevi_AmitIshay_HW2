#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "SuperMarket.h"
#include "functions.h"



char* getDynString(char* str)
{
	char* newStr;
	newStr = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (!newStr)
		return NULL;

	strcpy(newStr, str);
	return newStr;
}

void removeExtraSpaces(char* str) {
	int i, x;
	for (i = x = 0; str[i]; ++i)
		if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1])))
			str[x++] = str[i];
	str[x] = '\0';
}



char* formatStringAdress(char** str, int* size)
{
	for (int i = 0; i < &size; i++)
	{
		str[i] = (char*)realloc(str, sizeof(str[i]) + sizeof(char));

	}
}

char** initSuperMarketAdress()
{
	int pSize = 0;
	int finalPos = 0;
	char* dynStr = createDynStr("Please insert adress: ");
	char** adress = removeHashTagsFromString(dynStr, &pSize);

	return adress;
}

char* createDynStr(const char* msg)
{
	char buffer[MAX_LENGTH];
	printf("%s", msg);

	getchar();//getChar cleanes the input stream from '\n'
	fgets(buffer, sizeof(buffer), stdin);
	char* dynamicString = malloc(strlen(buffer) + 1);
	if (!dynamicString) return 0;
	strcpy(dynamicString, buffer);
	return dynamicString;
}


char** removeHashTagsFromString(char* str, int* pSize)
{


	const char delim[2] = "#";
	char* token = strtok(str, delim);
	char** adressesArray = NULL;// An array of adresses of tokens aka words...
	int pos = 0, size = 0;

	while (token != NULL) {

		adressesArray = (char**)realloc(adressesArray, (pos + 1) * sizeof(char*));
		if (!adressesArray)
		{
			return 0;
		}
		token[0] = toupper(token[0]);
		adressesArray[pos] = getDynString(token);
		size += strlen(token);
		token = strtok(NULL, delim);
		pos++;
	}
	free(token);

	*pSize = size;
	return  adressesArray;
}

void removeSpacedExtraSpacesFromStr(char** str, int* pSize)
{
	for (int i = 0; i < *pSize; i++) {
		removeExtraSpaces(*(str + i));
	}


}

//Swtich case in main.

void addProductFunc(Product* pProd)
{
	printf("Enter the Product you want to add:\n");
	initProduct(pProd);
}

