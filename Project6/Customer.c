#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "Customer.h"
#include "functions.h"
Customer initCustomer()
{
	(void)getchar();
	Customer cust = { createDynStr("Please enter customer name."), NULL };
	return cust;
}

void printCustomer(Customer* pCust)
{
	printf("Customer's name - %s , \n", pCust->name);
	printShoppingCart(pCust->shoppingCart);
	
}

void freeCustomer(Customer* customer) {
	free(customer->name);
	freeShoppingCart(customer->shoppingCart);
}

//Check if customer has items in his cart, if not cart is null.
int isCartExistEmpty(Customer* pCust) {
	if (pCust->shoppingCart == NULL) {
		return 1;
	}
	return 0;
}