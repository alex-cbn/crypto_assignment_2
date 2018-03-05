#pragma once
class Helper
{
public:
	static char* WriteAsn1Length(unsigned int length, int* lengths_length);

	static int ReadAsn1Length(char* stuff, int* lengths_length);

	static char* TextToHex(char* text);

	static char* HexToText(char* text);


};

