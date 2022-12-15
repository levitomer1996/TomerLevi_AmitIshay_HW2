#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "Product.h"



const char* typeTitle[NofTypes] = { "Shelf","Frozen","Fridge", "FruitVegtable" };

void initProduct(Product* pProd)
{
	printf("Please enter product name, Maximum length of %d \n", NAME_LEN);
	fgets(pProd->name, sizeof(pProd->name), stdin);
	strcpy(initBarCode("Please instert a barcode with a length %d:\n", BARCODE_LENGTH), pProd->barCode);
	pProd->type = getProdcutTypeFromUser();
	printf(" Please enter price: \n");
	scanf_s("%f", &pProd->price);
	pProd->inStock = 0;
}

void printProduct(const Product* pProd)
{
	printf(" Name - %s ,price - %f type - %s \n ", pProd->name, pProd->price, typeTitle[pProd->type]);
}

char* initBarCode(const char* msg)
{

	char* barcode[BARCODE_LENGTH];

	int numCounter = 0, isBarcodeValid = 0;
	char letter;
	while (isBarcodeValid == 0)
	{
		for (int i = 0; i < BARCODE_LENGTH; i++)
		{
			printf("Please enter letter number: %d \n", i + 1);
			scanf_s(" %c", &letter);

			//Checks if first and last letter are capital letters
			if (i == 0 || i == BARCODE_LENGTH - 1) {
				while ((!(letter >= 'A' && letter <= 'Z')))
				{
					printf("First and last letters must be Capital. Please enter Capital letter: \n");
					scanf_s(" %c", &letter);


				}
			}
			//Checks if char with
			if (!(letter >= 'A' && letter <= 'Z') && !(letter >= '0' && letter <= '9')) {
				printf("Bardcode must be made by Capital letters and numbers 0 - 9 \n");
				i--;
			}
			else {
				if ((letter >= 'A' && letter <= 'Z')) {
					*(barcode + i) = letter;
					printf("It's a letter, letter is %c \n", *(barcode + i));
				}
				else
				{
					*(barcode + i) = letter;
					printf("it's a number, letter is %c \n", *(barcode + i));
					numCounter++;
				}
			}

		}
		if (numCounter >= 3 && numCounter <= 5) isBarcodeValid = 1;
		else {
			printf("Barcode must have 3-5 numbers! try again please! \n");
		}
	}
	//checks if amount of numbers in barcode is valid.

	return barcode;

}

void freeProduct(Product* pProd)
{
	free(pProd->barCode);
	free(pProd->name);

}


ProductType getProdcutTypeFromUser()
{
	int type;
	printf("Please choose product type: \n");
	for (int i = 0; i < NofTypes; i++)
	{
		printf("%d for %s \n", i, typeTitle[i]);
		;
	}
	scanf("%d", &type);
	return (ProductType)type;
}