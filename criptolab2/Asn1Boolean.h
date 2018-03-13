#pragma once
#include "Asn1Value.h"
class Asn1Tlv;

class Asn1Boolean :
	public Asn1Value
{
private:
	bool value_;
public:
	Asn1Boolean(bool value) { value_ = value; };
	Asn1Tlv & GetTlv();
	void FillData(Asn1Tlv& tlv);
};

