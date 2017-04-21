#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int len[1001][1001] = {0};

int main(void) {
	char a[1001], b[1001];
	while (scanf("%s%s", a, b) != EOF) {
		int al = strlen(a), bl = strlen(b);
		for (int i = 0; i < al; i++) {
			for (int j = 0; j < bl; j++) {
				if (a[i] == b[j]) len[i + 1][j + 1] = len[i][j] + 1;
				else len[i + 1][j + 1] = max(len[i][j + 1], len[i + 1][j]);
			}
		}
		printf("%d\n", len[al + 1][bl + 1]);
	}
	return 0;
}