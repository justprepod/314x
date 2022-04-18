#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

enum STATE {LINE_START = 100, VALUE, VALUE_END, ERROR};

int main(int argc, char** argv) {
	FILE* f;
	char buffer[BUFFER_SIZE];
	enum STATE state = LINE_START;
	size_t n, i;
	char ch;
	size_t line = 0, position = 0;

	if (argc != 2) {
		printf("CSV syntax checker\n Usage:\n .exe <filename.csv>\n");
		return 2;
	}

	if (NULL == (f = fopen(argv[1], "r"))) {
		fprintf(stderr, "cannot open file '%s'", argv[1]);
		return 1;
	}

	while (!feof(f)) {
		n = fread(buffer, 1, BUFFER_SIZE, f);
		for (i = 0; i < n; i++) {
			if (state == ERROR)
				break;

			ch = buffer[i];
			position++;

			switch (state) {
			case LINE_START:
				if (ch == '"')
					state = VALUE;
				else {
					fprintf(stderr, "Error at line %u position %u: \" expected.", line, position);
					state = ERROR;
				}
				break;
			case VALUE:
				if (ch == '"')
					state = VALUE_END;
				break;
			case VALUE_END:
				if (ch == ',')
					state = LINE_START;
				else if (ch == '\n') {
					state = LINE_START;
					line++;
					position = 0;
				}
				else {
					fprintf(stderr, "Error at line %u position %u: , or \\n expected.", line, position);
					state = ERROR;
				}
				break;
			default:
				fprintf(stderr, "Something bad happened, undefined state %d", state);
			}
		}
		if (state == ERROR)
			break;
	}

	fclose(f);


	return 0;
}