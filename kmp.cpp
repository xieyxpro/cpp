#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int next[60000];

void kmp(vector<int> &s1, vector<int> &s2) {
	int i, j;
	bool flag = false;
	next[0] = -1, next[1] = 0;
	int t = 0;
	for (i = 2; i < s1.size(); i++) {
		if (s1[i - 1] == s1[t]) {				
			next[i] = ++t;
		}
		else {
			next[i] = 0;
			t = 0;
		}
	}

	//for (i = 0; i < s1.size(); i++) cout << next[i] << " ";
	//cout << endl;

	for (i = 0; i <= s2.size() - s1.size(); ) {
		for (j = 0; j < s1.size(); j++) {
			if (s2[i + j] != s1[j]) break;
		}
		if (j == s1.size()) {
			flag = true;
			break;
		} else i += j - next[j];
	}

	if (flag) cout << i << endl;
	else cout << "no solution\n";
}

int main(void) {
	int n1, n2;
	vector<int> s1, s2;
	while (cin >> n1 && n1 != 0) {
		s1.clear();
		s2.clear();

		int tmp;

		for (int i = 0; i < n1; i++) {
			scanf("%d", &tmp);
			s1.push_back(tmp);
		}

		cin >> n2;
		for (int i = 0; i < n2; i++) {
			scanf("%d", &tmp);
			s2.push_back(tmp);
		}

		kmp(s1, s2);
	}
	return 0;
}