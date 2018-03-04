#pragma once
class Asn1Tlv;
class IAsn1Value
{
public:
	virtual Asn1Tlv& GetTlv() = 0;
	virtual void FillData(Asn1Tlv& tlv) = 0;
};
