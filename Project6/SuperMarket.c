#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SuperMarket.h"
#include "functions.h"

void printSuperMarket(const SuperMarket* pSM)
{
	printf("Name: %s \n", pSM->name);
	printAddress(pSM->adress);
	printSuperMarketProductFunc(pSM);
	printSuperMarketCustomerFunc(pSM);
}

void initSuperMarket(SuperMarket* pSM)
{
	
	pSM->name = createDynStr("Please enter Supermarket's name: \n");

	Address adress;
	initAddress(&adress);
	pSM->adress = &adress;
	pSM->customers = NULL;
	pSM->numOfCustomers = 0;
	pSM->products = NULL;
	pSM->numOfProducts = 0;
	printf("Super market initialized. \n");
	
}

int addProductToSuperMarket(SuperMarket* pSM, Product* pProd)
{
	 (Product**)realloc(pSM->products, (pSM->numOfProducts+1)*sizeof(Product*));
	
	if (pSM->products == NULL) {
		return 0;
	}
	pSM->products[pSM->numOfProducts] = pProd;
	pSM->numOfProducts++;
	printf("New product added.");
}
