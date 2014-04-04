#include <cstdio>
#include <cstring>
#include <cstdlib>

int n = 170;
const int dicsize = 45104;

FILE *fin;
char dic[dicsize + 1][40];
double afabet[256];
char str[50];

int unktest() {
	for (int i = 1; i <= dicsize; ++i)
		if (strcmp(str, dic[i]) == 0)
			return 0;
	return 1;
}

int uppertest() {
	int ret = 0;
	for (int i = strlen(str) - 1; i >= 0; --i)
		if ('A' <= str[i] && str[i] <= 'Z') {
			++ ret;
			str[i] += 'a' - 'A';
		}
	return ret;
}

int main() {
	//freopen("sampleparse.out", "r", stdin);
	//freopen("test.out", "w", stdout);

	fin = fopen("dic.txt", "r");

	int freq;
	for (int i = 1; i <= dicsize; ++i)
		fscanf(fin, "%s\n", &dic[i]);
	fclose(fin);

	int length = 0, hy = 0; //length of the sentence
	int cla = 1; // class flag
	//scanf("%d\n", &cla);
	
	while (scanf("%d %d\n", &length, &hy) != EOF) {
		int unk = 0; // unkown words
		int upper = 0; //upper characters
		int slashadds = 0; // 's exist'
		int colom = 0; // ; test
		for (int i = 0; i < 256; ++i)
			afabet[i] = 0;
		int totalcharter = 0;
		
		for (int i = 1; i <= length; ++i) {
			scanf("%s\n", &str);

			upper += uppertest();
			unk += unktest();
			if (strcmp(str, "\'s") == 0)
				slashadds = 1;
			if (strcmp(str, ";") == 0)
				colom = 1;
			
			totalcharter += strlen(str);
		}

		double tmp = length;
		int longeo = 0;
		if (length > 50)
			longeo = 1;
		printf("%d 1:%d 2:%lf 3:%d 4:%d 5:%d 6:%d 7:%lf",
			cla, 
			unk, upper / tmp, slashadds,
			colom, longeo, hy / tmp);
		printf(" 8:%d\n", length
			);

	}
	return 0;
}
