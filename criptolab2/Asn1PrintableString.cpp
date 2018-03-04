#include "stdafx.h"
#include "Asn1PrintableString.h"
#include "Asn1Tlv.h"

Asn1Tlv & Asn1PrintableString::GetTlv()
{
	Asn1Tlv* tlv = new Asn1Tlv(19, strlen(value_), value_);
	return *tlv;
}

void Asn1PrintableString::FillData(Asn1Tlv & tlv)
{

}
