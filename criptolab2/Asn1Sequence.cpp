#include "stdafx.h"
#include "Asn1Sequence.h"
#include "Asn1Tlv.h"
#include "Helper.h"
#include "Asn1Factory.h"
#include <vector>

Asn1Sequence::Asn1Sequence()
{
}

void Asn1Sequence::Add(Asn1Value* object)
{
	contents_.push_back(object);
}

Asn1Tlv & Asn1Sequence::GetTlv()
{
	char* content = NULL;
	int sum_of_components = 0;
	for (std::vector<Asn1Value*>::size_type i = 0; i != contents_.size(); i++)//untested
	{
		Asn1Tlv tlvito = contents_[i]->GetTlv();//TODO define a proper constructor/operator overload
		int old_size = sum_of_components;
		tlvito.GetRaw();
		sum_of_components += tlvito.GetActualLength();
		content = (char*)realloc(content, sum_of_components);
		memcpy_s(content + old_size, sum_of_components - old_size, tlvito.GetRaw(), sum_of_components - old_size);
	}
	Asn1Tlv* tlv = new Asn1Tlv(0x30, sum_of_components, content);
	return *tlv;
}

void Asn1Sequence::FillData(Asn1Tlv & tlv)
{
	char* raw_content = tlv.GetValue();
	int limit = tlv.GetLength();
	int offset = 0;
	Asn1Value* object_pointer;
	while (offset < limit)
	{
		object_pointer = &Asn1Factory::MakeAsn1ValueFromRaw(raw_content + offset);
		offset += object_pointer->GetTlv().GetLength();
		contents_.push_back(object_pointer);
	}
}
