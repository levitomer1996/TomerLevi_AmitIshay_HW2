#pragma once

#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#define MAX_LENGTH 255
#include "SuperMarket.h"
#include "Product.h"

char* createDynStr(const char* msg);
char** removeHashTagsFromString(const char* msg, int* pSize); // Made to be used when init supermarket
void removeSpacedExtraSpacesFromStr(char** str, int* pSize);
void removeExtraSpaces(char* str);
char* getDynString(char* str);

char* formatStringAdress(char** str, int* pSize);
char** initSuperMarketAdress();

//Switch cases Main FUNC
//Print super market
void printSuperMarketProductFunc(const SuperMarket* pSM);
void printSuperMarketCustomerFunc(const SuperMarket* pSM);

//Add product
void addProductFunc(SuperMarket* pSm);
#endif