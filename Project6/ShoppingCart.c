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
}



int addItemToCart(ShoppingCart* pCart, ShoppingItem* pItem)
{
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






