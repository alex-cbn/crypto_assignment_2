#pragma once
class Asn1Tlv;
class Asn1Value;

class Asn1Factory
{
private:
	//blank
public:
	static Asn1Value& MakeAsn1ValueFromTlv(Asn1Tlv& tlv);
	static Asn1Value& MakeAsn1ValueFromRaw(char* raw);
};

