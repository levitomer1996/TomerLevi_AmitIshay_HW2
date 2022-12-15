#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SuperMarket.h"

void printSuperMarket(const SuperMarket* pSM)
{
}

void initSuperMarket(SuperMarket* pSM)
{
	pSM->name = createDynStr("Please enter Supermarket's name: \n");
	pSM->adress = initSuperMarketAdress();
	pSM->customers = NULL;
	pSM->numOfCustomers = 0;
	pSM->products = NULL;
	pSM->numOfProducts = 0;
	printf("Super market initialized. \n");
}

int addProductToSuperMarket(SuperMarket* pSM, Product* pProd)
{
	return 0;
}
