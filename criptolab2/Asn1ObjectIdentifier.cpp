#include "stdafx.h"
#include "Asn1ObjectIdentifier.h"
#include "Asn1Tlv.h"

Asn1ObjectIdentifier::Asn1ObjectIdentifier(char * values)
{

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
			printf("I am lazy\n");
		}
	}
	Asn1Tlv* tlv = new Asn1Tlv(0x6, write_ptr, encoded);
	return *tlv;
}

void Asn1ObjectIdentifier::FillData(Asn1Tlv & tlv)
{

}
