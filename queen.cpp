#include <iostream>
using namespace std;

int position[8];

void search(int cur, int n) {
	if (cur == n) {
		for (int i = 0; i <= n - 2; ++i) cout << position[i] << " ";
		cout << position[n - 1] << endl;
	} else {
		for (int i = 1; i <= n; ++i) {
			bool flag = true;
			position[cur] = i;
			for (int j = 0; j < cur; ++j) {
				if (position[cur] == position[j] || cur - position[cur] == j - position[j]
					|| cur + position[cur] == j + position[j]) {
					flag = false;
					break;
				}
			}
			if (flag) search(cur + 1, n);
		}
	}
}

int main(void) {
	search(0, 8);
	return 0;
}
