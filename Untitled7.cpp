#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void printNum(char ch, int p2) {
	for (int i = 1; i <= p2; i++) cout << ch;
}

void print(char start, char end, int p1, int p2, int p3) {
	if (p3 == 1) {
		if (p1 == 3) {
			for (char i = start + 1; i < end; i++) {
				printNum('*', p2);
			}
		} else if (p1 == 1) {
			for (char i = start + 1; i < end; i++) {
				printNum(i, p2);
			}
		} else {
			if (start >= '0' && start <= '9') {
				for (char i = start + 1; i < end; i++) {
					printNum(i, p2);
				}
			} else {
				for (char i = start + 1; i < end; i++) {
					printNum(i + 32, p2);
				}
			}
		}
	} else {
		if (p1 == 3) {
			for (char i = end - 1; i > start; i--) {
				printNum('*', p2);
			}
		} else if (p1 == 1) {
			for (char i = end - 1; i > start; i--) {
					printNum(i, p2);
			}
		} else {
			if (start >= '0' && start <= '9') {
				for (char i = end - 1; i > start; i--) {
					printNum(i, p2);
				}
			} else {
				for (char i = end - 1; i > start; i--) {
					printNum(i - 32, p2);
				}
			}
		}
	}
}

bool isTrue(char a, char b) {
	if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') return true;
	if (a >= '0' && a <= '9' && b >= '0' && b <= '9') return true;
	else return false;
}

int main(void) {
	int p1, p2, p3;
	char str[150];
	while (scanf("%d%d%d", &p1, &p2, &p3) != EOF) {
		scanf("%s", str);
		int len = strlen(str);
		cout << str[0];
		for (int i = 1; i < len; i++) {
			if (str[i] != '-') cout << str[i];
			else {
				if (isTrue(str[i - 1], str[i + 1])) {
					if (str[i + 1] <= str[i - 1]) {
						cout << '-';
					} else if (str[i + 1] == str[i - 1] + 1) {
					} else {
						print(str[i - 1], str[i + 1], p1, p2, p3);
					}
				}
				else cout << str[i];
			}
		}
		cout << endl << endl;
	}
    return 0;
}

