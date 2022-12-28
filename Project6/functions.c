#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



char* getDynString(char* str)
{
	char* newStr;
	newStr = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (!newStr)
		return NULL;

	strcpy(newStr, str);
	return newStr;
}

void removeExtraSpaces(char* str) {
	int i, x;
	for (i = x = 0; str[i]; ++i)
		if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1])))
			str[x++] = str[i];
	str[x] = '\0';
}





char** initSuperMarketAdress()
{
	int pSize = 0;
	int finalPos = 0;
	char* dynStr = createDynStr("Please insert adress: ");
	char** adress = removeHashTagsFromString(dynStr, &pSize);

	return adress;
}

void initTests()
{
	for (int i = 0; i < 7; i++)
	{

	}
}

char* createDynStr(const char* msg)
{
	char buffer[MAX_LENGTH];
	printf("%s", msg);

	//getchar();//getChar cleanes the input stream from '\n' **amit hide getchar because its pass on the first letter
	fgets(buffer, sizeof(buffer), stdin);
	char* dynamicString = malloc(strlen(buffer) + 1);
	if (!dynamicString) return 0;
	strcpy(dynamicString, buffer);
	return dynamicString;
}
char** removeHashTagsFromString(char* str, int* pSize)
{


	const char delim[2] = "#";
	char* token = strtok(str, delim);
	char** adressesArray = NULL;// An array of adresses of tokens aka words...
	int pos = 0, size = 0;
	int* pp;
	while (token != NULL) {
		pp = *token;
		if (pp == ' ') // strtok City start with ' ' so with pp pointer i promoted to the City first letter
		{
			pp = (char*)token + sizeof(char);
			token = pp;
		}
		adressesArray = (char**)realloc(adressesArray, (pos + 1) * sizeof(char*));
		if (!adressesArray)
		{
			return 0;
		}
		
		adressesArray[pos] = getDynString(token);
		size += strlen(token);
		token = strtok(NULL, delim);
		pos++;
	}
	free(token);

	*pSize = size;
	return  adressesArray;
}

void removeSpacedExtraSpacesFromStr(char** str, int* pSize)
{
	for (int i = 0; i < *pSize; i++) {
		removeExtraSpaces(*(str + i));
	}


}

//Swtich case in main.

//Print superMarket

void printSuperMarketProductFunc(const SuperMarket* pSm)
{
	if (pSm->numOfProducts == 0) {
		printf("Super market has no products. \n");
		return 0;
	}
	int i = 0;
	for (int i = 0; i < pSm->numOfProducts; i++) {
		printf("%d) ", i + 1 );
		printProduct(pSm->products[i]);
	}
}

void freeSuperMarket(SuperMarket* superMarket) {
	free(superMarket->name);
	freeAddress(superMarket->adress);
	free(superMarket->customers);
	for (int i = 0; i < superMarket->numOfProducts; i++) {
		freeProduct(superMarket->products[i]);
	}
	free(superMarket->products);
	free(superMarket);
}





void printSuperMarketCustomerFunc(const SuperMarket* pSM)
{
	if (pSM->numOfCustomers == 0) {
		printf("Super market has no Customers. \n");
		return 0;
	}
	
	int i = 0;
	for (int i = 0; i < pSM->numOfCustomers; i++) {
		printCustomer(&pSM->customers[i]);
	}

}

//Had product to Supermarket.
void addProductFunc(SuperMarket* pSm)
{
	addProductToSuperMarket(pSm);
}

void addCustomerToSuperMarket(SuperMarket* pSm)
{
	addCustomer(pSm);
}

void makePurchaseFunc(SuperMarket* pSm)
{
	getchar();
	char* customerName = createDynStr("Please insert customer's name:");
	while (isCustomerExist(pSm, customerName) == 0) {
	char* customerName = createDynStr("Customer is not listed. Please insert customer's name:");
	};
	
	Customer* customer;
	ShoppingCart* pCart;
	customer = findCustomerByName(pSm, customerName);

	//If shopping cart is not exist
	if (customer->shoppingCart == NULL) {
		pCart = (ShoppingCart*)malloc(sizeof(ShoppingCart));
		initShoppingCart(pCart);
		customer->shoppingCart = pCart;
	}
	else {
		pCart = customer->shoppingCart;
	}
		
	
	if (pSm->numOfProducts == 0) {
		printf("Super martket doesn't have any product. you cannot make a purchase.  \n");
		return;
	}
	char clear = 'y';
	while ((clear == 'Y' || clear == 'y')) {
		
		printSuperMarketProductFunc(pSm);
	
		
		handleAddItem(pSm, pCart);
		printf("Press y/Y to procceed, anything else is back to main menu   \n");
		scanf_s("%c", &clear);
		getchar();
	}
	printShoppingCart(pCart);
}

Product* getProductByBarCode(SuperMarket* pSm, char* barcode)
{
	for (int i = 0; i < pSm->numOfProducts; i++) {
		if (strcmp(barcode, pSm->products[i]->barCode) == 0) {
			return pSm->products[i];
		}
	}
	return 0;
}

void handleAddItem(SuperMarket* pSm, ShoppingCart* pCart)
{
	
	char* barcode = createDynStr("Please insert barcode that you would like to had: \n");
	printf(barcode);
	int amount;
	printf("Please enter amount of the chosen product: \n");
	
	scanf_s("%d", &amount);
	getchar();
	Product* chosenProd = getProductByBarCode(pSm, barcode);
	while (chosenProd == 0) {
	
		char* barcode = createDynStr("Please insert barcode that you would like to had: \n");
		Product* chosenProd = getProductByBarCode(pSm, barcode);
	}
	while (chosenProd->inStock < amount) {
		printf("There are only %d of this item. \n", chosenProd->inStock);
		printf("Please enter amount of the chosen product: \n");
		scanf_s("%d", &amount);
		getchar();
	}
	chosenProd->inStock -= amount;
	//Init new ITem in cart:
	ShoppingItem* item = malloc(sizeof(ShoppingItem));
	initShoppingItem(item, chosenProd);
	item->quantity = amount;
	addItemToCart(pCart,item);
	printf("Item Added to cart. \n");
}

void makeCustomerPaymentFunc(SuperMarket* pSM)
{
	getchar();
	char* name = createDynStr("Please type customers name that you would like to check out :\n");
	Customer* cust = findCustomerByName(pSM, name);
	printShoppingCart(cust->shoppingCart);
	printf("Payment has made ! \n");
	freeShoppingCart(cust->shoppingCart);
	printf("Shopping cart emptied. \n");

}

void printProductsWithSameType(SuperMarket* pSM)
{
	ProductType type = getProdcutTypeFromUser();
	printByType(pSM, type);
	
}

char* initBarcode()
{
	char* barcode = createDynStr("Please enter Barcode: \n");
	while (isBarcodeValid(barcode) == 0) {
		barcode = createDynStr("Please create a barcode:(Must be in the length of 7, First and last letters must be Capital) \n");
	}
	return barcode;
}

int barcodeExists(SuperMarket* supermarket, char* barcode)
{
	for (int i = 0; i < supermarket->numOfProducts; i++) {
		if (strcmp(supermarket->products[i]->barCode, barcode) == 0) {
			return 1;
		}
	}
	return 0;
}

void printShoppingCartFunc(SuperMarket* pSm)
{
	
	getchar();
	char* name = createDynStr("Please type customers name from the list to show his cart :\n");
	Customer*	cust = findCustomerByName(pSm, name);
	printCustomer(cust);
	printShoppingCart(cust->shoppingCart);
}



