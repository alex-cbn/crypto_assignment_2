#include "stdafx.h"
#include "Asn1Tlv.h"
#include <stdlib.h>
#include <string.h>
#include "Helper.h"

Asn1Tlv::Asn1Tlv(int type, int length, char * value)
{
	type_ = type;
	length_ = length;
	value_ = new char[length];
	memcpy_s(value_, length, value, length);//WARNING
	overall_length_ = 0;
}

Asn1Tlv::Asn1Tlv(char * raw_string)
{
	ReadRaw(raw_string);
}

void Asn1Tlv::WriteTlv(FILE * file_descriptor)
{
	fprintf(file_descriptor, "%x", type_);
	fprintf(file_descriptor, "%x", Helper::WriteAsn1Length);
	fprintf(file_descriptor, "%s", value_);//TBD
}

void Asn1Tlv::ReadTlv(FILE * file_descriptor)
{
	char rawview[2048];
	memset(rawview, 0, 2048);
	int bytes_read = fread(rawview, 1, 2048, file_descriptor);
	//get type
	type_ = rawview[0];
	//get length
	int length_length = 0;
	length_ = Helper::ReadAsn1Length(rawview + 1, &length_length);
	//get raw_data
	int raw_size = bytes_read - 1 - length_length; //DANGER
	value_ = new char[raw_size];//DANGER
	_memccpy(value_, rawview + length_length + 1, 1, raw_size);//DANGER

}

char* Asn1Tlv::GetRaw()
{
	int additional_length = 0;
	char* length_representation = Helper::WriteAsn1Length(length_, &additional_length);
	overall_length_ = 1 + length_ + additional_length;
	char* raw = new char[overall_length_];
	raw[0] = char(type_);
	memcpy_s(raw + 1, additional_length, length_representation, additional_length);
	memcpy_s(raw + 1 + additional_length, length_, value_, length_);
	return raw;
}

void Asn1Tlv::ReadRaw(char* raw_form)
{
	//get type
	type_ = raw_form[0];
	//get length
	int length_length = 0;
	length_ = Helper::ReadAsn1Length(raw_form + 1, &length_length);
	//get data
	value_ = new char[length_];
	memcpy_s(value_, length_, raw_form + 1 + length_length, length_);
}

int Asn1Tlv::GetActualLength()
{
	int additional_length = 0;
	char* length_representation = Helper::WriteAsn1Length(length_, &additional_length);
	overall_length_ = 1 + length_ + additional_length;
	return overall_length_;
}

int Asn1Tlv::GetType()
{
	return type_;
}

int Asn1Tlv::GetLength()
{
	return length_;
}

char * Asn1Tlv::GetValue()
{
	return value_;
}

int Asn1Tlv::GetLengthLength()
{
	return GetActualLength() - length_ - 1;
}
