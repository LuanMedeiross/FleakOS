#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	void printfile(char file_name[100]);

	printfile(argv[1]);

	return 0;
}

void printfile(char file_name[100]) {

	FILE *file;
	char line[100];
	file = fopen(file_name, "r");

	if (file != NULL) {
		if ((fgets(line, 100, file)) != NULL) {
			
			fseek(file, 0, SEEK_SET);
			
			while (fgets(line, 100, file)) {
				printf("%s", line);
			}
		} else {
			printf("cat: %s: Is a directory\n", file_name);
			exit(1);
		}
	} else {
		printf("cat: %s: No such file or directory\n", file_name);
		exit(2);
	}

	fclose(file);
}


