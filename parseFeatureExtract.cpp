#include <cstdio>
#include <cstring>

char a[150][50];

int main() {
	//freopen("sample.output.txt", "r", stdin);
	//freopen("sampleparse.out", "w", stdout);

	int count = 0; // #s of ()
	int maxcount = 0; //hy of tree
	int SentenceLength = 0;
	int totalSentence = 0; // total #s of sentence

	char str[50];
	while (scanf("%s", &str) != EOF) {
		if (str[0] == '(') {
			++ count;
			if (count > maxcount)
				maxcount = count;
		}
		int length = strlen(str);
		if (str[length - 1] == ')') {
			int j = length - 1;
			for (;str[j] == ')' && j > 0; --j)
				--count;
			if (count < 0) {
				count = 0;
				continue;
			}
			++ SentenceLength;
			strncpy(a[SentenceLength], str, j + 1);
		}
		if (str[0] != '(' && str[length - 1] != ')')
			continue;

		if (count == 0) {
			printf("%d %d\n", SentenceLength, maxcount);
			for (int i = 1; i <= SentenceLength; ++i)
				printf("%s\n", a[i]);

			++ totalSentence;
			SentenceLength = 0;
			maxcount = 0;
			memset(a, 0, sizeof(a));
		}
	}

//	printf("%d\n", totalSentence);
	return 0;
}
