#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ShoppingCart.h"


void initShoppingCart(ShoppingCart* pCart)
{
	pCart->numOfItems = 0;
	pCart->items = NULL;
}

void printShoppingCart(const ShoppingCart* pCart)
{
	int totalPrice = 0;
	printf("Shopping cart is: \n");
	for (int i = 0; i < pCart->numOfItems; i++)
	{
		totalPrice += (pCart->items[i]->price * pCart->items[i]->quantity);
		printShoppingItem(pCart->items[i]);
	}
	printf("The bill is: %d\n", totalPrice);
}



int addItemToCart(ShoppingCart* pCart, ShoppingItem* pItem)
{
	ShoppingItem* isExist = getShoppingItemFromCart(pCart, pItem->barcode);
	if (isExist) {
		isExist->quantity += pItem->quantity;
		return 1;
	}
	pCart->items = (ShoppingItem*)realloc(pCart->items, (pCart->numOfItems + 1) * sizeof(ShoppingItem));
	if (!pCart->items || !pItem)
	{
		return 0;
	}
	pCart->numOfItems++;
	pCart->items[pCart->numOfItems] = pItem;
	return 1;
}

int sumCartCheckOut(ShoppingCart* pCart)
{
	int sum = 0;
	for (int i = 0; i < pCart->numOfItems; i++)
	{
		sum = pCart->items[i]->price * pCart->items[i]->quantity;
	}
	return sum;
}

void freeShoppingCart(ShoppingCart* pCart)
{
	free(pCart->items);
}

ShoppingItem* getShoppingItemFromCart(ShoppingCart* pCart, char* barcode)
{
	for (int i = 0; i < pCart->numOfItems; i++) {
		if (strcmp(barcode, pCart->items[i]->barcode) == 0) {
			return pCart->items[i];
		}
	}
	return 0;
}






