#include <stdio.h>
#include <cstring>

int n = 150;
char a[1000];

int main () {
	for (int i = 1; i <= n; ++i) {
		gets(a);
		printf("%s\n", a);
	}
	return 0;
}
