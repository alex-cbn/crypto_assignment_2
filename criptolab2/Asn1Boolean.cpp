#include "stdafx.h"
#include "Asn1Boolean.h"
#include "Asn1Tlv.h"

Asn1Tlv & Asn1Boolean::GetTlv()
{
	char* value = new char[2];
	value[1] = 0;
	if (value_)
	{
		value[0] = 1;
	}
	else
	{
		value[0] = 0;
	}
	Asn1Tlv* tlv = new Asn1Tlv(1, 1, value);
	return *tlv;
}

void Asn1Boolean::FillData(Asn1Tlv & tlv)
{
}
