#include "tests.h"

int main(int argc, char* argv[])
{
	TestDatatypeSizes();

	TestMasks();
	
	TestString();

	TestStack();

	TestQueue();

	TestList();

	TestDictionary();
	
 	return 0;
}