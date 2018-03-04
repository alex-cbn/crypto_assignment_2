#pragma once
#include "IAsn1Value.h"
#include <vector>


class Asn1Tlv;
class Asn1Sequence :IAsn1Value
{
private:
	std::vector<IAsn1Value*>contents_;
public:
	Asn1Sequence();
	void Add(IAsn1Value* object);
	Asn1Tlv & GetTlv();
	void FillData(Asn1Tlv& tlv);
};

