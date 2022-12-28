#pragma once
#include "ShoppingCart.h"

#ifndef _CUSTOMER_
#define _CUSTOMER_

typedef struct
{
	char* name;
	ShoppingCart* shoppingCart;
} Customer;

Customer	initCustomer();
void		printCustomer(Customer* pCust);
void		freeCustomer(Customer* customer);

#endif
