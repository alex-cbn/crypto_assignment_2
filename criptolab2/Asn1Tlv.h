#pragma once
#include<cstdio>

class Asn1Tlv {

private:
	int type_;
	int length_;
	char* value_;
	int overall_length_;
public:
	Asn1Tlv(int type, int length, char* value);
	Asn1Tlv(char* raw_string);
	void WriteTlv(FILE* file_descriptor);
	void ReadTlv(FILE* file_descriptor);
	char* GetRaw();
	void ReadRaw(char* raw_form);
	int GetActualLength();
};