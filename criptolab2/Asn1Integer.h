#pragma once
#include "IAsn1Value.h"

class Asn1Tlv;
class Asn1Integer : IAsn1Value
{
private:
	int value_;
public:
	Asn1Integer(int value) { value_ = value; };
	Asn1Tlv & GetTlv();
	void FillData(Asn1Tlv& tlv);
};