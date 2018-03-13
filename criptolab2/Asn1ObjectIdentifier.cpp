#include "stdafx.h"
#include "Asn1ObjectIdentifier.h"
#include "Asn1Tlv.h"
#include <string.h>
#include <stdlib.h>

Asn1ObjectIdentifier::Asn1ObjectIdentifier(char * values)
{//TODO
	values_ = new int[5];
	values_[0] = 1;
	values_[1] = 2;
	values_[2] = 3;
	values_[3] = 4;
	values_[4] = 5;
	values_length_ = 5;
	/*int values_count= 0;
	char* part = strtok(values, ".");
	while (part !=NULL)
	{
		part = strtok(NULL, ".");
		values_count++;
	}
	values_length_ = values_count;
	values_ = new int[values_count];
	values_count = 0;
	char* part = strtok(values, ".");
	while (part != NULL)
	{
		values_[values_count++] = atoi(part);
		part = strtok(NULL, ".");
	}*/
}

Asn1Tlv & Asn1ObjectIdentifier::GetTlv()
{
	char* encoded = new char[2048];
	memset(encoded, 0, 2048);
	int write_ptr = 0;
	int length_of_components = 0;
	for (int i = 0; i < values_length_; i++)
	{
		if (values_[i] < 127)
		{
			encoded[write_ptr++] = values_[i];
		}
		else
		{
			//da sigur
			printf("I am lazy\n"); //TODO
		}
	}
	Asn1Tlv* tlv = new Asn1Tlv(0x6, write_ptr, encoded);
	return *tlv;
}

void Asn1ObjectIdentifier::FillData(Asn1Tlv & tlv)
{

}
