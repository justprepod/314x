#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char			name[20];
	char			surname[20];
	char			sex[20];
	char			position[20];
	unsigned int	salary;
} TTuple;

int main(int argc, char** argv) {
	FILE* f;
	TTuple* data = NULL, *tmp = NULL;
	unsigned data_count = 0;
	size_t len;
	unsigned i;

	char buffer[100];
	char *cursor, *cursor1;

	if (argc != 3) {
		printf("CSV scanner. Counts average salary on choosen position.\n Usage:\n csv.exe <filename> <position>\n");
		return 2;
	}

	if (NULL == (f = fopen(argv[1], "r"))) {
		fprintf(stderr, "cannot open file '%s'", argv[1]);
		return 1;
	}

	while (!feof(f)) {
		tmp = (TTuple*)realloc(data, sizeof(TTuple) * (data_count + 1));
		if (tmp == NULL) {
			fprintf(stderr, "not enough memory");
			free(data);
			return 3;
		}
		data = tmp;

		fgets(buffer, sizeof(buffer), f);
		cursor = buffer;

		//reading name
		cursor1 = strchr(cursor, ',');
		len = cursor1 - cursor;
		strncpy(data[data_count].name, cursor, len);
		data[data_count].name[len] = 0;

		cursor = cursor1 + 1;
		//reading surname
		cursor1 = strchr(cursor, ',');
		len = cursor1 - cursor;
		strncpy(data[data_count].surname, cursor, len);
		data[data_count].surname[len] = 0;

		cursor = cursor1 + 1;
		//reading sex
		cursor1 = strchr(cursor, ',');
		len = cursor1 - cursor;
		strncpy(data[data_count].sex, cursor, len);
		data[data_count].sex[len] = 0;

		cursor = cursor1 + 1;
		//reading position
		cursor1 = strchr(cursor, ',');
		len = cursor1 - cursor;
		strncpy(data[data_count].position, cursor, len);
		data[data_count].position[len] = 0;

		cursor = cursor1 + 1;
		//reading salary
		sscanf(cursor, "%u", &data[data_count].salary);

		data_count++;
	}
	fclose(f);


	for (i = 0; i < data_count; i++) {
		if (0 == strcmp(data[i].position, argv[2]))
			printf("%s, %s, %s, %s, %u\n", data[i].name, data[i].surname, data[i].sex, data[i].position, data[i].salary);
	}

	return 0;
}