#pragma once
class Asn1Tlv;
class IAsn1Value
{
public:
	virtual Asn1Tlv& GetTlv();
	virtual void FillData(Asn1Tlv& tlv);
};
