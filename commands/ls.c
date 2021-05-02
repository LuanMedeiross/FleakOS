#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

void listdir(char dir_name[]);
void hidedata(char data[]);
int setupargs(int argn, char *args[]);

bool hide = true;

int main(int argc, char *argv[]) {

	register int c;

	int qtdD;

	if (argc > 1) {

		qtdD = setupargs(argc, argv);

		// se 
		for (c = 1; c < argc; c++) {
			if (argv[c][0] != '-')
				listdir(argv[c]);
			else if (qtdD == 0)
				listdir(".");
		}

	} else 
		// if not args
		listdir(".");

	return 0;
}

void listdir(char dir_name[]) {

	static DIR *d;
	static struct dirent *dir;

	d = opendir(dir_name);

	printf("%s:\n", dir_name);

	if (d != NULL) {
		while (dir = readdir(d)) {
			if (!hide) {
				printf("%s  ", dir->d_name);
			} else {
				if (dir->d_name[0] != '.') {
					printf("%s  ", dir->d_name);
				}
			}		
		}

		printf("\n");

	} else {
		perror("error");
	}
}

int setupargs(int argn, char *args[]) {

	register int c = 1;

	int qtdD = 0;

	for (c; c < argn; ++c) {

		if (args[c][0] == '-') {
			// conforme for atualizando, tera mais opcoes
			switch (args[c][1]) {
				case 'a':
					hide = false;
				break;
			}
		} else 
			++qtdD;
	}

	return qtdD;
}

