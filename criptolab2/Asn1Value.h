#pragma once
#include "IAsn1Value.h"
#include "Helper.h"

class Asn1Tlv;
class Asn1Value: public IAsn1Value
{
public:
	Asn1Tlv& GetTlv();
	void FillData(Asn1Tlv& tlv);
};
