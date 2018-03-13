#include "stdafx.h"
#include "Asn1Factory.h"
#include "Asn1Boolean.h"
#include "Asn1Integer.h"
#include "Asn1ObjectIdentifier.h"
#include "Asn1PrintableString.h"
#include "Asn1Sequence.h"
#include "Asn1Tlv.h"
#include "Asn1Utf8String.h"
#include "Asn1Value.h"

Asn1Value & Asn1Factory::MakeAsn1ValueFromTlv(Asn1Tlv& tlv)
{
	int type = tlv.GetType();
	Asn1Value* object;
	switch (type)
	{
	case 0x01:
		object = new Asn1Boolean(0);
		object->FillData(tlv);
		return *(object);
		break;
	case 0x02:
		object = new Asn1Integer(0);
		object->FillData(tlv);
		return *(object);
		break;
	case 0x06:
		object = new Asn1ObjectIdentifier(0);
		object->FillData(tlv);
		return *(object);
		break;
	case 0x0c:
		object = new Asn1UTF8String((char*)"");//TODO
		object->FillData(tlv);
		return *(object);
		break;
	case 0x13:
		object = new Asn1PrintableString((char*)"");//TODO
		object->FillData(tlv);
		return *(object);
		break; 
	case 0x30:
		object = new Asn1Sequence();
		object->FillData(tlv);
		return *(object);
		break;
	default:
		object = nullptr;
		return *(object);
		break;
	}


}

Asn1Value & Asn1Factory::MakeAsn1ValueFromRaw(char* raw)
{
	Asn1Tlv tlv(raw);
	return MakeAsn1ValueFromTlv(tlv);
}
