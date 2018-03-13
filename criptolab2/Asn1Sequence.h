#pragma once
#include "Asn1Value.h"
#include <vector>


class Asn1Tlv;
class Asn1Sequence :public Asn1Value
{
private:
	std::vector<Asn1Value*>contents_;
public:
	Asn1Sequence();
	void Add(Asn1Value* object);
	Asn1Tlv & GetTlv();
	void FillData(Asn1Tlv& tlv);
};

