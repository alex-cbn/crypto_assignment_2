#include "stdafx.h"
#include "Asn1Sequence.h"
#include "Asn1Tlv.h"
#include "Helper.h"
#include <vector>

Asn1Sequence::Asn1Sequence()
{
}

void Asn1Sequence::Add(IAsn1Value* object)
{
	contents_.push_back(object);
}

Asn1Tlv & Asn1Sequence::GetTlv()
{
	char* content = NULL;
	int sum_of_components = 0;
	for (std::vector<IAsn1Value*>::size_type i = 0; i != contents_.size(); i++)
	{
		Asn1Tlv tlvito = contents_[i]->GetTlv();//TODO define a proper constructor/operator overload
		int old_size = sum_of_components;
		sum_of_components += tlvito.GetActualLength();
		content = (char*)realloc(content, sum_of_components);
		memcpy_s(content + old_size, sum_of_components - old_size, tlvito.GetRaw(), sum_of_components - old_size);		
	}
	Asn1Tlv* tlv = new Asn1Tlv(0x30, sum_of_components, content);
	return *tlv;
}

void Asn1Sequence::FillData(Asn1Tlv & tlv)
{

}