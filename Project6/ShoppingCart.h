#pragma once

#ifndef _SHOPPINGCART_
#define _SHOPPINGCART_

#include "ShoppingItem.h"

typedef struct
{
	ShoppingItem** items;
	int numOfItems;

} ShoppingCart;

void	initShoppingCart(ShoppingCart* pCart);
void	printShoppingCart(const ShoppingCart* pCart);
int	    addItemToCart(ShoppingCart* pCart, ShoppingItem* pItem);
//Calculate the sum of the total price of the cart.
int		sumCartCheckOut(ShoppingCart* pCart);
void	freeShoppingCart(ShoppingCart* pCart);

#endif