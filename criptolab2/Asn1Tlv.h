#pragma once
#include<cstdio>

class Asn1Tlv {

private:
	int type_;
	int length_;
	char* value_;
public:
	Asn1Tlv(int type, int length, char* value);
	void WriteTlv(FILE* file_descriptor);
	void ReadTlv(FILE* file_descriptor);
};