#pragma once
#include "Product.h"
#include "ShoppingCart.h"
#ifndef _CUSTOMER_
#define _CUSTOMER_

typedef struct
{
	char* name;
	ShoppingCart* shoppingCart;

} Customer;

void	initCustomer(Customer* pCust);
void	printCustomer(Customer* pCust);
void	freeCustomer(Customer* pCust);
#endif
