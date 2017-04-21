#include<stdio.h>
#include<string.h>
int main(void) {
	int t, count;
	long long n, num[20], tmp, ans, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%ld", &n);
		memset(num, 0, sizeof(num));
		for (i = 1; i <= n; i++) {
			scanf("%ld", &tmp);
			count = 19;
			while(tmp) {
				printf("sssssssss\n");
				if (tmp % 2 == 1) num[count]++;
				count--;
				tmp /= 2;
			}
		}
		//printf("sssssssss\n");
		ans = 0;
		for (i = 0; i < 20; i++) {
			ans += num[i] * (n - num[i]);
			ans *= 2;
		}
		printf("%ld\n", ans);
	}
	return 0;
}
