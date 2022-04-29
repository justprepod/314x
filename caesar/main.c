#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(int argc, char** argv) {
	FILE* f;
	char buffer[BUFFER_SIZE];
	size_t i, n;
	char c, m;

	if (argc != 3) {
		printf("Caesar cipher/decipher\nUsage: caesar.exe <filename> <mode>\nModes:\nc - Cipher\nd - Decipher)");
		return;
	}

	if (NULL == (f = fopen(argv[1], "r"))) {
		fprintf(stderr, "Cannot open file %s", argv[1]);
		return;
	}

	while (!feof(f)) {
		n = fread(buffer, 1, BUFFER_SIZE, f);
		for (i = 0; i < n; i++) {
			m = buffer[i];
			if ((m >= 'a') && (m <= 'z')) {
				c = 'a' + (m - 'a' + 3) % 26;
			}
			else if ((m >= 'A') && (m <= 'Z')) {
				c = 'A' + (m - 'A' + 3) % 26;
			}
			else {
				c = m;
			}
			printf("%c", c);
		}
	}

	fclose(f);
	
}