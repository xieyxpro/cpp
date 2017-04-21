#include <iostream>
#include <cstdio>
using namespace std;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n, num[1000];
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		for (int i = 0; i < n - 1; i++) {
			int min = i;
			for (int j = i; j < n; j++) {
				if (num[j] < num[min]) min = j;
			}
			if (min != i) {
				swap(num[min], num[i]);
			}
			for (int i = 0; i < n - 1; i++) printf("%d ", num[i]);
			printf("%d\n", num[n - 1]);
		}
	}
	return 0;
}
