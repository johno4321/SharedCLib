#include "tests.h"

int main(int argc, char* argv[])
{
	uint8 val = 0xFF;

	for (int i = 0; i <= 8; i++)
	{
		printf("%d %#04x\n\n", val << i, val << i);
	}

	for (int i = 0; i <= 8; i++)
	{
		printf("%d %#04x\n\n", val >> i, val >> i);
	}

	uint8 mask = 0x00;

	uint8 mask1 = 0x01;
	uint8 mask2 = 0x02;
	uint8 mask3 = 0x04;
	uint8 mask4 = 0x08;
	uint8 mask5 = 0x10;
	uint8 mask6 = 0x20;
	uint8 mask7 = 0x40;
	uint8 mask8 = 0x80;

	val = mask | mask6;

	printf("%d %#08x\n\n", val, val);

	if (val & mask6)
	{
		printf("mask 6");
	}
	

	//printf("%d %#04x\n\n", val >> i, val >> i);
	/*TestDatatypeSizes();

	TestString();

	TestStack();

	TestQueue();

	TestList();

	TestDictionary();*/
	
 	return 0;
}