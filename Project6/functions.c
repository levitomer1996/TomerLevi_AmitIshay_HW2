#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "SuperMarket.h"
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



char* formatStringAdress(char** str, int* size)
{
	for (int i = 0; i < &size; i++)
	{
		str[i] = (char*)realloc(str, sizeof(str[i]) + sizeof(char));

	}
}

char** initSuperMarketAdress()
{
	int pSize = 0;
	int finalPos = 0;
	char* dynStr = createDynStr("Please insert adress: ");
	char** adress = removeHashTagsFromString(dynStr, &pSize);

	return adress;
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
		token[0] = toupper(token[0]);
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





void printSuperMarketCustomerFunc(const SuperMarket* pSM)
{
	if (pSM->numOfCustomers == 0) {
		printf("Super market has no Customers. \n");
		return 0;
	}
	
	int i = 0;
	for (int i = 0; i < pSM->numOfCustomers; i++) {
		printCustomer(pSM->customers[i]);
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
	printf("Arrvied here");
	Customer* customer = malloc(sizeof(Customer*));
	customer = findCustomerByName(pSm, customerName);;
	ShoppingCart* pCart = malloc(sizeof(ShoppingCart));
	initShoppingCart(pCart);
	customer->shoppingCart = malloc(sizeof(ShoppingCart*));
	customer->shoppingCart = pCart;
	
	printSuperMarketProductFunc(pSm);
	printf("Please choose product from the list above. \n");
	char clear = 'y';
	while ((clear == 'Y' || clear == 'y')) {
		printSuperMarketProductFunc(pSm);
	
		
		handleAddItem(pSm, pCart);
		printf("Press y/Y to procceed, anything else is back to main menu   \n");
		scanf_s(" %c", &clear);
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

int handleAddItem(SuperMarket* pSm, ShoppingCart* pCart)
{
	getchar();
	char* barcode = createDynStr("Please insert barcode that you would like to had: \n");
	int amount;
	printf("Please enter amount of the chosen product: \n");
	getchar();
	scanf_s("%d", &amount);
	Product* chosenProd = getProductByBarCode(pSm, barcode);
	while (chosenProd == 0) {
		getchar();
		char* barcode = createDynStr("Please insert barcode that you would like to had: \n");
		Product* chosenProd = getProductByBarCode(pSm, barcode);
	}
	while (chosenProd->inStock < amount) {
		printf("There are only %d of this item. \n", chosenProd->inStock);
		printf("Please enter amount of the chosen product: \n");
		getchar();
		scanf_s("%d", &amount);
	}
	chosenProd->inStock -= amount;
	//Init new ITem in cart:
	ShoppingItem* item = malloc(sizeof(ShoppingItem));
	initShoppingItem(item, chosenProd);
	item->quantity = amount;
	addItemToCart(pCart,item);
	printf("Item Added to cart. \n");
}
