#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "ShoppingItem.h"


void initShoppingItem(ShoppingItem* pItem, Product* pProd)
{

	pItem->barcode = &pProd->barCode;
	pItem->price = pProd->price;
	pItem->quantity = 1;
}

void printShoppingItem(const ShoppingItem* pItem)
{
	printf("Product Bar code - %s, Price - %f,Quantity - %d  \n", pItem->barcode, pItem->price, pItem->quantity);
}

int raiseItemQuantity(ShoppingItem* pItem)
{
	if (!pItem) {
		return 0;
	}
	pItem->quantity++;
	return 1;
}

int decreaseItemQuantity(ShoppingItem* pItem)
{
	if (!pItem) {
		return 0;
	}
	pItem->quantity--;
	return 1;
}

void freeShoppingItem(ShoppingItem* pItem)
{

}
