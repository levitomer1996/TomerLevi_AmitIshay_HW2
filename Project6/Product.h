#pragma once
#ifndef _PRODUCT_
#define _PRODUCT_

#define NAME_LEN 20
#define BARCODE_LENGTH 7

typedef enum { Shelf, Frozen, Fridge, FruitVegtable, NofTypes } ProductType;
const char* typeTitle[NofTypes];

typedef struct
{
	char* name[NAME_LEN];
	ProductType type;
	char* barCode[BARCODE_LENGTH];
	float price;
	int inStock;
} Product;

void	initProduct(Product* pProd);
void	printProduct(const Product* pProd);
char* initBarCode(const char* msg);
void	freeProduct(Product* pProd);

#endif
