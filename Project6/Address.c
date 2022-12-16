#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#include "Address.h"
#include "functions.h"
#define MAX_LENGTH 99


void initAddress(Address* pAd)
{
	int pSize = 0;
	int finalPos = 0;
	char* dynStr = createDynStr("Please insert adress: ");
	char** adress = removeHashTagsFromString(dynStr, &pSize);
	pAd->street = adress[0];
	pAd->houseNumber = adress[1];
	pAd->city = adress[2];
	printAddress(pAd);
}


void printAddress(const Address* pAd)
{
	printf("Adress: %s %s, %s", pAd->street, pAd->houseNumber, pAd->city);
}

void freeAdress(Address* pAd)
{
	free(pAd->city);
	free(pAd->street);
}


//char* getStrExactLength()
//{
//	char* theStr = NULL;
//	int len;
//	char inpStr[MAX_LENGTH];
//
//	//printf("Enter a String:");
//	fgets(inpStr, sizeof(inpStr), stdin);
//	len = strlen(inpStr) + 1;
//	theStr = (char*)malloc(len * sizeof(char));
//		if (theStr != NULL)
//			strcpy(theStr, inpStr);
//
//		//for (int i = 0; i < len; ++i) {
//		//	printf("%c", theStr[i]);
//		//}
//		return theStr;
//}