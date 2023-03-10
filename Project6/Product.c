#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "Product.h"



const char* typeTitle[NofTypes] = { "Shelf","Frozen","Fridge", "FruitVegtable" };

void initProduct(Product* pProd)
{
	(void)getchar();
	pProd->name = createDynStr("Please enter products's name: \n");
	pProd->barCode = initBarcode();
	pProd->type = getProdcutTypeFromUser();
	printf(" Please enter price: \n");
	scanf_s("%f", &pProd->price);
	while (pProd->price <= 0) {
		printf("Price must be above 0. \n");
		scanf_s("%f", &pProd->price);
	}
	(void)getchar();
	printf(" Please enter how many items: \n");
	scanf_s("%d", &pProd->inStock);
	while (pProd->inStock <= 0) {
		printf("quantity must be above 0. \n");
		scanf_s("%d", &pProd->inStock);
	}
	
	//pProd->inStock = 1;
}

void printProduct(const Product* pProd)
{
	printf("Name - %s, Type - %s , Price - %.2f, in stock - %d, Barcode - %s \n", pProd->name, typeTitle[pProd->type], pProd->price,pProd->inStock, pProd->barCode);
}

int isBarcodeValid(const char* barcode)
{
	if (strlen(barcode) !=8) {
		printf("BardCode must be in length of 7\n");
		return 0;
	}
	if (!(barcode[0] >= 'A' && barcode[0]  <= 'Z')|| !(barcode[6] >= 'A' && barcode[6] <= 'Z')) {
		printf("First and last must be Capital\n");
		return 0;
	}
	int numberCounter = 0;
	for (int i = 0; i < strlen(barcode) - 1; i++)
	{
		if (!(barcode[i] >= 'A' && barcode[i] <= 'Z')) {
			
			if (barcode[i] <= '9' && barcode[i] >= '0') {

				numberCounter++;
			}
			else {
				printf("All must be Capital\n");
				return 0;
			}
		
		}
		
	}
	if (numberCounter < 3 || numberCounter > 5) {
		printf("must be 3-5 numbers\n");
		return 0;
	}
	
	return 1;
}




void freeProduct(Product* product) {
	free(product->name);
	free(product->barCode);
}

void printAllTypes()
{
	
}



ProductType getProdcutTypeFromUser()
{
	int type;
	printf("Please choose product type: \n");
	for (int i = 0; i < NofTypes; i++)
	{
		printf("%d for %s \n", i, typeTitle[i]);
	}
	scanf_s("%d", &type);
	return (ProductType)type;
}