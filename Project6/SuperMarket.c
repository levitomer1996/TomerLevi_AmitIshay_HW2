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
	printf("New product added. \n");
	return 1;
}
addCustomer(SuperMarket* pSM) {
	if (pSM == NULL) {
		return 0;
	}

	pSM->customers = (Customer*)realloc(pSM->customers, (pSM->numOfCustomers + 1) * sizeof(Customer));

	if (pSM->customers == NULL) {
		return 0;
	}
	Customer cust = initCustomer();
	
	pSM->customers[pSM->numOfCustomers] = cust;
	
	pSM->numOfCustomers++;
	
	printf("New Customer added. \n");
	return 1;
}

int isCustomerExist(SuperMarket* pSM,char* name)
{
	
	for (int i = 0; i < pSM->numOfCustomers; i++) {
		if (strcmp(name,pSM->customers[i].name) == 0) {
			return 1;
		}
	}
	return 0;
}

Customer* findCustomerByName(SuperMarket* pSM, char* name)
{
	for (int i = 0; i < pSM->numOfCustomers; i++) {
		if (strcmp(name, pSM->customers[i].name) == 0) {
			return  &(pSM->customers[i]);
		}
	}
	return;
}

void printSuperMarketCustomers(SuperMarket* pSM)
{
	for (int i = 0; i < pSM->numOfCustomers; i++)
	{
		printf("%d", i);
		printCustomer(&pSM->customers[i]);
	}
}

void printByType(SuperMarket* pSM, ProductType type)
{
	for (int i = 0; i < pSM->numOfProducts; i++)
	{
		if (pSM->products[i]->type == type) {
			printProduct(pSM->products[i]);
		}
	}
}
