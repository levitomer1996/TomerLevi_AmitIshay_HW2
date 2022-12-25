#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "Customer.h"
#include "functions.h"
void initCustomer(Customer* pCust)
{
	getchar();
	pCust->name = createDynStr("Please enter customer name.");
	pCust->shoppingCart = NULL;
}

void printCustomer(Customer* pCust)
{
	printf("Customer's name - %s , \n", pCust->name);
	if(pCust->shoppingCart != NULL){
		printShoppingCart(pCust->shoppingCart);
	}
	
}

void freeCustomer(Customer* pCust)
{
	free(pCust->name);
}

//Check if customer has items in his cart, if not cart is null.
int isCartExistEmpty(Customer* pCust) {
	if (pCust->shoppingCart == NULL) {
		return 1;
	}
	return 0;
}