#include "stdafx.h"
#include "Asn1Tlv.h"
#include "Asn1Integer.h"

Asn1Tlv& Asn1Integer::GetTlv()
{
	char* raw_value = new char[6];
	int write_ptr = 0;
	int flag = 0;
	int is_negative = (value_ < 0);
	for (int i = 0; i < 4; i++)
	{
		char bitorin = ((char*)&value_)[3 - i];
		if (flag == 0)
		{
			if (bitorin != 0)
			{
				flag = 1;
				if (is_negative)
				{
					if (((unsigned char)bitorin > unsigned char(127)) && is_negative)//TODO
					{
						raw_value[write_ptr++] = '\xFF';
					}
					raw_value[write_ptr++] = bitorin;
				}
				else
				{
					if (((unsigned char)bitorin > unsigned char(127)) && !is_negative)
					{
						raw_value[write_ptr++] = 0;
					}
					raw_value[write_ptr++] = bitorin;
				}

			}
		}
		else
		{
			raw_value[write_ptr++] = bitorin;
		}
	}
	if (write_ptr == 0)
	{
		raw_value[write_ptr++] = 0;
	}
	//TODO
	Asn1Tlv* tlv = new Asn1Tlv(2, write_ptr, raw_value);
	return *tlv;
}

void Asn1Integer::FillData(Asn1Tlv& tlv)
{
	//TODO

}
