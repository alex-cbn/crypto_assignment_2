#include "stdafx.h"
#include "Asn1Utf8String.h"
#include "Asn1Tlv.h"

Asn1Tlv & Asn1UTF8String::GetTlv()
{
	Asn1Tlv* tlv = new Asn1Tlv(12, strlen(value_), value_);
	return *tlv;
}

void Asn1UTF8String::FillData(Asn1Tlv & tlv)
{

}