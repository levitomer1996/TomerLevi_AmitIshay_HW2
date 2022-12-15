#pragma once
#include "Customer.h"
#include "Product.h"
#ifndef _SUPERMARKET_
#define _SUPERMARKET_

typedef struct {
	char* name;
	char** adress;
	Customer** customers;
	int numOfCustomers;
	Product** products;
	int numOfProducts;
} SuperMarket;
//SM - Super Market
void	printSuperMarket(const SuperMarket* pSM);
void	initSuperMarket(SuperMarket* pSM);
int		addProductToSuperMarket(SuperMarket* pSM, Product* pProd);
#endif