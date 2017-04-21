#include<cstdio>
#include<cstring>

bool isZero(char* str) {
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (str[i] != '0') return false;
	}
	return true;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char a[100], b[100], ans[100];
		scanf("%s %s", a, b);
		printf("%d ", i);
		int la = strlen(a), lb = strlen(b), len = la < lb?la:lb;
		if (isZero(a) && isZero(b)) printf("0\n");
		else if (isZero(a)) {
			int q = 0;
			while (b[q] == '0') q++;
			for (int w = q; q < lb; q++) printf("%c", b[q]);
			printf("\n");
		} else if (isZero(b)) {
			int q = 0;
			while (a[q] == '0') q++;
			for (int w = q; q < la; q++) printf("%c", a[q]);
			printf("\n");
		} else {
			int k = la - 1, l = lb - 1, j, flag = 0;
			for (j = 0; j < len; j++) {
				ans[j] = a[k--] + b[l--] + flag - '0';
				if (ans[j] > '1') {
					flag = 1;
					ans[j] -= 2;
				} else {
					flag = 0;
				}
			}
			if (la == lb) {
				if (flag == 0) {
					for (int n = len - 1; n >= 0; n--) printf("%c", ans[n]);
					printf("\n");
				} else {
					printf("%d", flag);
					for (int n = len - 1; n >= 0; n--) printf("%c", ans[n]);
					printf("\n");
				}
			} else if (la > lb) {
				for (j = len; j < la; j++) {
					ans[j] = a[k--] + flag;
					if (ans[j] > '1') {
						flag = 1;
						ans[j] -= 2;
					} else {
						flag = 0;
					}
				}
				if (flag == 0) {
					for (int n = la - 1; n >= 0; n--) printf("%c", ans[n]);
					printf("\n");
				} else {
					printf("%d", flag);
					for (int n = la - 1; n >= 0; n--) printf("%c", ans[n]);
					printf("\n");
				}
			} else {
				for (j = len; j < lb; j++) {
					ans[j] = a[k--] + flag;
					if (ans[j] > '1') {
						flag = 1;
						ans[j] -= 2;
					} else {
						flag = 0;
					}
				}
				if (flag == 0) {
					for (int n = lb - 1; n >= 0; n--) printf("%c", ans[n]);
					printf("\n");
				} else {
					printf("%d", flag);
					for (int n = lb - 1; n >= 0; n--) printf("%c", ans[n]);
					printf("\n");
				}
			}
		}
	}
	return 0;
}
