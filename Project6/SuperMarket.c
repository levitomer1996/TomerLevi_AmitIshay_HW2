#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "SuperMarket.h"
#include "functions.h"

void printSuperMarket(const SuperMarket* pSM)
{
	printf("Name: %s \n", pSM->name);
	printAddress(pSM->adress);
	printSuperMarketProductFunc(pSM);
	printSuperMarketCustomerFunc(pSM);
}

void initSuperMarket(SuperMarket* pSM, Address* pAd)
{	
	pSM->name = createDynStr("Please enter Supermarket's name: \n");
	initAddress(pAd);
	pSM->adress = pAd;
	pSM->customers = NULL;
	pSM->numOfCustomers = 0;
	pSM->products = NULL;
	pSM->numOfProducts = 0;
	printf("Super market initialized. \n");
	
}

int addProductToSuperMarket(SuperMarket* pSM)
{
	if (pSM == NULL) {
		return 0;
	}
	
	pSM->products = (Product**)realloc(pSM->products, (pSM->numOfProducts + 1) * sizeof(Product*));
	
	if (pSM->products == NULL) {
		return 0;
	}
	pSM->products[pSM->numOfProducts] = malloc(sizeof(Product));
	initProduct(pSM->products[pSM->numOfProducts]);
	pSM->numOfProducts++;
	printf("%d\n", pSM->numOfProducts);
	printf("New product added.");
	return 1;
}
