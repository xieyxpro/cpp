#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[100001];

int find_k_max(int *num, int n, int k) {
	int x = num[n >> 1];
	int i = 0, j = n - 1;

	do {
		while (num[i] > x) i++;
		while (num[j] < x) j--;
		if (i <= j) {
			int t = num[i];
			num[i] = num[j];
			num[j] = t;
			i++, j--;
		}
	} while (i <= j);

	if (j + 1 < k && k == i) return k;
	if (j + 1 >= k) return find_k_max(num, j + 1, k);
	return find_k_max(num + i, n - i, k - i) + i;
}

bool cmp(int a, int b) {
	return a > b;
}

int main(void) {
	int n, k;
	while (cin >> n >> k) {
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		sort(num, num + find_k_max(num, n, k), cmp);

		for (int i = 0; i < k - 1; i++)
			printf("%d ", num[i]);
		printf("%d\n", num[k - 1]);
		/*for (int i = 0; i < n; i++)
			printf("%d ", num[i]);*/
	}
	return 0;
}
