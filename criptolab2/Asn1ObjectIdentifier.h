#pragma once
#include "Asn1Value.h"

class Asn1Tlv;
class Asn1ObjectIdentifier :public Asn1Value
{
private:
	int* values_;
	int values_length_;
public:
	Asn1ObjectIdentifier(char* values);
	Asn1Tlv & GetTlv();
	void FillData(Asn1Tlv& tlv);
};

