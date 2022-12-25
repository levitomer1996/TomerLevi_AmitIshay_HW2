#pragma once
#include "Customer.h"
#include "Product.h"
#include "Address.h"
#ifndef _SUPERMARKET_
#define _SUPERMARKET_

typedef struct {
	char* name;
	Address* adress;
	Customer** customers;
	int numOfCustomers;
	Product** products;
	int numOfProducts;
} SuperMarket;
//SM - Super Market
void	printSuperMarket(const SuperMarket* pSM);
void	initSuperMarket(SuperMarket* pSM, Address* pAd);
int	addProductToSuperMarket(SuperMarket* pSM);
void printSuperMarketProductFunc(const SuperMarket* pSm);
#endif