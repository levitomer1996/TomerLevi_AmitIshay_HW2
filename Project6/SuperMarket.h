#pragma once
#include "Customer.h"
#include "Address.h"
#ifndef _SUPERMARKET_
#define _SUPERMARKET_


typedef struct {
	char* name;
	Address* adress;
	Customer* customers;
	int numOfCustomers;
	Product** products;
	int numOfProducts;
} SuperMarket;

//SM - Super Market

void	printSuperMarket(const SuperMarket* pSM);
void	initSuperMarket(SuperMarket* pSM, Address* pAd);
int		addProductToSuperMarket(SuperMarket* pSM);
void	printSuperMarketProductFunc(const SuperMarket* pSm);
void	freeSuperMarket(SuperMarket* superMarket);
//Add customer
int addCustomer(SuperMarket* pSM);

//Make a purchase
int isCustomerExist(SuperMarket* pSM, char* name);
Customer* findCustomerByName(SuperMarket* pSM, char* name);

//Print customers
void printSuperMarketCustomers(SuperMarket* pSM);

//Print by type
void printByType(SuperMarket* pSM, ProductType type);

#endif