// criptolab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <openssl\asn1.h>
#include <vector>
#include <string.h>
#include "Asn1Tlv.h"
#include "Helper.h"
#include "Asn1Integer.h"
#include "Asn1PrintableString.h"
#include "Asn1Utf8String.h"

class Tema
{

};

class Nume
{

};

class Student
{
	int age;
	Nume nume;
	bool cu_taxa;
	Tema tema;
};


int main()
{
	char* test2 = Helper::TextToHex((char*)"fghijklm");
	char* test3 = Helper::HexToText(test2);
	printf("test2: %s\ntest3: %s\n", test2, test3);
	int flag = 0;
	int rip = 0;
	char* merge_banda = Helper::WriteAsn1Length(342512, &rip);
	int come_back = Helper::ReadAsn1Length(merge_banda, &flag);
	printf("%d", come_back);
	Asn1Integer intorin(256);
	Asn1Tlv asiiin = intorin.GetTlv();
	return 0;
}