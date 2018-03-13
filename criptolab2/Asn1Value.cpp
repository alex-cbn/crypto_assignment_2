#include "stdafx.h"
#include "Asn1Value.h"
#include "Asn1Tlv.h"

Asn1Tlv & Asn1Value::GetTlv()
{
	// TODO: insert return statement here
	return *(new Asn1Tlv(0,0,0));
}

void Asn1Value::FillData(Asn1Tlv & tlv)
{
}
