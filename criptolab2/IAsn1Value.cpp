#include "stdafx.h"
#include "IAsn1Value.h"
#include "Asn1Tlv.h"

Asn1Tlv & IAsn1Value::GetTlv()
{
	// TODO: insert return statement here
	return *(new Asn1Tlv(0,0,0));
}

void IAsn1Value::FillData(Asn1Tlv & tlv)
{
}
