#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "Address.h"
#include "Product.h"
#include "functions.h"
#include "SuperMarket.h"


#define MAX_ADDRESS 99

int main()
{
	//Init Super marketFirst
	Address adress;
	SuperMarket sm;
	initSuperMarket(&sm,&adress);

	char choice = '0';
	int exit = 0;

	while (choice != 'e')
	{
		switch (choice)
		{
		case '1':
			printSuperMarket(&sm);
			choice = '0';
			break;
		case '2':

			addProductFunc(&sm);
			choice = '0';
			break;
		case '3':
			addCustomer(&sm);
			choice = '0';
;			break;
		case '4':
			makePurchaseFunc(&sm);
			choice = '0';
			break;
		case '5':
			printShoppingCartFunc(&sm);
			choice = '0';
			break;
		case '6':
			makeCustomerPaymentFunc(&sm);
			choice = '0';
			break;			
		case '7':
			printProductsWithSameType(&sm);
			choice = '0';
			break;
		case '8':
			printf("thank you, see you soon..\n");
			choice = 'e';
			break;
		case '9':

			initSuperMarketAdress();
			choice = 'e';
			break;
		default:
			printf("/================/\n");
			printf("Menu online SuperMarket, Please choose 1-8:\n");
			printf("1.Print SuperMarket products.\n");
			printf("2.Add new Product.\n");
			printf("3.Add new Customer.\n");
			printf("4.Start new Purchase.\n");
			printf("5.Print ShoopingCart.\n");
			printf("6.Make a Payment.\n");
			printf("7.Print Products with the same Type.\n");
			printf("8.Exit,Dont forget to Pay before you leave!\n"); //We need to check if the customer payed
			printf("/================/\n");
			scanf(" %c", &choice);

		}

	}
}