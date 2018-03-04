#include "stdafx.h"
#include "Asn1Tlv.h"
#include <stdlib.h>
#include <string.h>
#include "Helper.h"

Asn1Tlv::Asn1Tlv(int type, int length, char * value)
{
	type_ = type;
	length_ = length;
	value_ = _strdup(value);
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
