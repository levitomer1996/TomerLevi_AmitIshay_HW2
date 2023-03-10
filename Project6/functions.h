#pragma once
#include "SuperMarket.h"

#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#define MAX_LENGTH 255


void initTests();
char* createDynStr(const char* msg);
char** removeHashTagsFromString(const char* msg, int* pSize); // Made to be used when init supermarket

char* getDynString(char* str);


char** initSuperMarketAdress();

//Switch cases Main FUNC
//Print super market
void printSuperMarketProductFunc(const SuperMarket* pSM);
void printSuperMarketCustomerFunc(const SuperMarket* pSM);

//Add product
void addProductFunc(SuperMarket* pSm);
//Add customer
void addCustomerToSuperMarket(SuperMarket* pSm);

//Make a purchase

 void makePurchaseFunc(SuperMarket* pSm);
 Product* getProductByBarCode(SuperMarket* pSm, char* barcode);
 void handleAddItem(SuperMarket* pSm, ShoppingCart* pCart);
 
 //Print shopping cart
 void printShoppingCartFunc(SuperMarket* pSm);

 void makeCustomerPaymentFunc(SuperMarket* pSM);
 void printProductsWithSameType(SuperMarket* pSM);
 char* initBarcode();
 int barcodeExists(SuperMarket* supermarket, char* barcode);

 //Check if everyonechecked out.
 int isEveryonePay(SuperMarket* superMarket);
#endif