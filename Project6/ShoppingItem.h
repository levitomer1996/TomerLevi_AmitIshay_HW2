#pragma once
#include "Product.h"

#ifndef _SHOPPINGITEM_
#define _SHOPPINGITEM_

typedef struct
{
	char* barcode;
	float price;
	int quantity;

} ShoppingItem;

void	initShoppingItem(ShoppingItem* pItem, Product* pProd);
void	printShoppingItem(const ShoppingItem* pItem);
int		raiseItemQuantity(ShoppingItem* pItem);
int		decreaseItemQuantity(ShoppingItem* pItem);
void	freeShoppingItem(ShoppingItem* pItem);
#endif