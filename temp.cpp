#include <cstdio>
#include <cstring>

int main (){
	freopen("NewSentenceCand.txt", "r", stdin);
	freopen("NewSentenceCand_ad.txt", "w", stdout);

	char a[1000];
	for (int i = 1; i <= 8936; ++i) {
		gets(a);
		printf("%s.\n", a);
	}
	return 0;
}