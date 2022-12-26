#pragma once

#ifndef _ADDRESS_
#define _ADDRESS_

#define LEN 99

typedef struct
{
	char* houseNumber;
	char* street;
	char* city;

} Address;
void	initAddress(Address* pAd);
void	printAddress(const Address* pAd);
void	freeAdress(Address* pAd);
void	getTextWithOutSpaces(char* str);

//void addDoubleSpace(Address* pAd);

#endif