#include <stdio.h>

int main()
{
	char line[15];
	FILE*file = fopen("text.txt", "w");
	fprintf(file, "zdec bil ia");
	fclose(file);
	return 0;
}