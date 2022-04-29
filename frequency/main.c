#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(int argc, char** argv) {
	FILE* f;
	char buffer[BUFFER_SIZE];
	size_t i, n;
	char m;
	size_t freq[52];
	size_t count = 0;

	if (argc != 2) {
		printf("Letter frequency analyser\nUsage: freq.exe <filename>");
		return;
	}

	if (NULL == (f = fopen(argv[1], "r"))) {
		fprintf(stderr, "Cannot open file %s", argv[1]);
		return;
	}

	memset(freq, 0, sizeof(freq));

	while (!feof(f)) {
		n = fread(buffer, 1, BUFFER_SIZE, f);
		for (i = 0; i < n; i++) {
			m = buffer[i];
			if ((m >= 'a') && (m <= 'z')) {
				freq[m - 'a']++;
				count++;
			}
			else if ((m >= 'A') && (m <= 'Z')) {
				freq[m - 'A' + 26]++;
				count++;
			}
		}
	}

	for (i = 0; i < 26; i++) {
		//printf("%c %06u\n", 'a' + i, freq[i]);
		printf("%c %.8f\n", 'a' + i, (double)freq[i] / count);
	}

	for (i = 0; i < 26; i++) {
		//printf("%c %06u\n", 'A' + i, freq[26 + i]);
		printf("%c %.8f\n", 'a' + i, (double)freq[26 + i] / count);
	}

	fclose(f);

}