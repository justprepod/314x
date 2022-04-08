#include <stdio.h>

int main(int argc, char** argv) {
	FILE* f; //файловый дескриптор (file handle)
	char filename[] = "C:\\file.txt";
	char s[200];
	int x,y;

	f = fopen(filename, "r");
	if (f == NULL) {
		printf("Cannot open file '%s'", filename);
		return 1;
	}

	while (!feof(f)) {
		fgets(s, sizeof(s), f);
		sscanf(s, "(%d;%d)\n", &x, &y);
		printf("%d %d", x, y);
	}

	fclose(f);

	return 0;
}