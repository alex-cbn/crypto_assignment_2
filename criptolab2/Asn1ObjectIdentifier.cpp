#include "stdafx.h"
#include "Asn1ObjectIdentifier.h"
#include "Asn1Tlv.h"

Asn1ObjectIdentifier::Asn1ObjectIdentifier(char * values)
{
}

Asn1Tlv & Asn1ObjectIdentifier::GetTlv()
{
	int length_of_components = 0;
	Asn1Tlv* tlv = new Asn1Tlv(0x6, values_length_ - 1, (char*)values_);
	return *tlv;
}

void Asn1ObjectIdentifier::FillData(Asn1Tlv & tlv)
{
}
