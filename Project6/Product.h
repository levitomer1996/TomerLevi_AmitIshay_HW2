#pragma once
#ifndef _PRODUCT_
#define _PRODUCT_

#define NAME_LEN 20
#define BARCODE_LENGTH 7

typedef enum { Shelf, Frozen, Fridge, FruitVegtable, NofTypes } ProductType;
const char* typeTitle[NofTypes];

typedef struct
{
	char* name;
	ProductType type;
	char* barCode;
	float price;
	int inStock;
} Product;

void	initProduct(Product* pProd);
void	printProduct(const Product* pProd);
int		isBarcodeValid(const char* barcode);
void	freeProduct(Product* product);
void    printAllTypes();

#endif
