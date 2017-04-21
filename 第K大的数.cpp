#include <iostream>
#include <cstdio>
using namespace std;

int num[10000001];
bool is[20000001] = {0};

int find_kth_max(int *num, int n, int k) {
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

	if (j + 1 < k && k == i) return num[k - 1];
	if (j + 1 >= k) return find_kth_max(num, j + 1, k);
	return find_kth_max(num + i, n - i, k - i);
}

int main(void) {
	int n, k, tmp, i, j;
	cin >> n >> k;
	for (i = 0, j = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (!is[tmp + 10000000]) {
			num[j] = tmp;
			j++;
			is[tmp + 10000000] = true;
		}
	}
	cout << find_kth_max(num, j, k) << endl;
	return 0;
}
