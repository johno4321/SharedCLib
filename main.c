#include "tests.h"
#include <string.h>

int main(int argc, char* argv[])
{
	// Check for --test or -t command line argument to run tests
	if (argc > 1 && (strcmp(argv[1], "--test") == 0 || strcmp(argv[1], "-t") == 0))
	{
		RunTests();
	}
	else if (argc > 1)
	{
		printf("Usage: %s [--test|-t]\n", argv[0]);
		printf("  --test, -t    Run all tests\n");
		return 1;
	}
	
 	return 0;
}