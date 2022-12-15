#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#include "Address.h"
#include "functions.h"
#define MAX_LENGTH 99


void	initAddress(Address* pAd)
{
	pAd->city = createDynStr("Please enter city name: \n");
	pAd->street = createDynStr("Please enter street name: \n");
	printf("Please enter house numebr: \n");
	scanf_s("%d", &pAd->houseNumber);
}


void printAddress(const Address* pAd)
{
	printf("street %s city %s number % d\n", pAd->street, pAd->city, pAd->houseNumber);
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