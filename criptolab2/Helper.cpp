#include "stdafx.h"
#include "Helper.h"
#include <string.h>

char* Helper::WriteAsn1Length(unsigned int length, int* lengths_length) //retruns the length encoding in a "string"
{
	char* length_string = new char[6];
	memset(length_string, 0, 6);//DANGER
	int write_ptr = 0;
	int bytes_count = 0;
	if (length > 127)
	{
		for (int i = 0; i < 4; i++)
		{
			char bitorin = ((char*)&length)[3 - i];
			if (bitorin != 0)
			{
				length_string[1 + bytes_count++] = bitorin;
			}
		}
		length_string[0] = (char)(128 + char(bytes_count));
	}
	else
	{
		length_string[write_ptr++] = (char)(length);
	}
	*lengths_length = write_ptr;
	return length_string;
}

int Helper::ReadAsn1Length(char* stuff, int* lengths_length) //returns the lenght read from stuff and sets lengths_length to the length of the length field
{
	if ((unsigned char)stuff[0] > 127)
	{
		int bytes = (unsigned char)stuff[0] & 127;
		int size = 0;
		for (int i = 0; i < bytes; i++)
		{
			size *= 256;
			size += (unsigned char)stuff[i + 1];
		}
		*lengths_length = bytes;
		return size;
	}
	else
	{
		*lengths_length = 1;
		return (unsigned char)stuff[0];
	}
}

char* Helper::TextToHex(char* text) //converts hex representation of an ascii string into an ascii string
{
	int text_length = strlen(text);
	char* result = new char[text_length * 3 + 1];
	result[text_length * 3] = 0;
	for (int i = 0; i < text_length; i++)
	{
		char low = text[i] % 16;
		char hi = text[i] - low;
		hi = hi / 16;
		if (low < 10)
		{
			result[3 * i + 1] = '0' + low;
		}
		else
		{
			result[3 * i + 1] = 'a' + low - 9;
		}
		if (hi < 10)
		{
			result[3 * i] = '0' + hi;
		}
		else
		{
			result[3 * i] = 'a' + hi - 9;
		}
		result[3 * i + 2] = ' ';
	}
	return result;
}

char* Helper::HexToText(char* text) //reads the hex representation and converts it in an ascii string 
{
	int text_length = strlen(text);
	char* result = new char[text_length / 3 + 1];
	result[text_length / 3] = 0;
	for (int i = 0; i < text_length / 3; i++)
	{
		char low = text[3 * i + 1];
		char hi = text[3 * i];
		if (low <= 57)
		{
			low = low - '0';
		}
		else
		{
			low = low + 9 - 'a';
		}
		if (hi <= 57)
		{
			hi = hi - '0';
		}
		else
		{
			hi = hi + 9 - 'a';
		}
		result[i] = 16 * hi + low;
	}
	return result;
}