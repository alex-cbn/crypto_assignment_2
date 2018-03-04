#pragma once
#include "IAsn1Value.h"
#include <string.h>

class Asn1Tlv;
class Asn1UTF8String : IAsn1Value
{
private:
	char* value_;
public:
	Asn1UTF8String(char* value) { value_ = _strdup(value); };
	Asn1Tlv & GetTlv();
	void FillData(Asn1Tlv& tlv);
};
