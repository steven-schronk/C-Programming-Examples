#include <stdio.h>

struct symbol_hash {
	char *name;
	int address;
};

int main()
{
	struct symbol_hash symbol_hash[512];

	symbol_hash[0].name = "This is a long string of data";

	printf("hash name %s\n", symbol_hash[0].name);

	symbol_hash[0].name = "This is a short string.";

	printf("hash name %s\n", symbol_hash[0].name);

	symbol_hash[0].address = 4;

	printf("hash add %d\n", symbol_hash[0].address);
	return 1;
}
