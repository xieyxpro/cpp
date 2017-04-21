#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int dis;
	bool flag;
    char str[80], pair[80][3];
    while (scanf("%s", str)&&str[0] != '*') {
    	if (strlen(str) <= 2) {
    		cout << str << " is surprising." << endl;
    	} else {
    		 flag = false;
    		 for (dis = 1; dis <= strlen(str)-2; dis++) {
    		 	for (int i = 0; i < strlen(str)-dis; i++) {
    		 		pair[i][0] = str[i], pair[i][1] = str[i+dis];
    		 		pair[i][3] = '\0';
    		 		cout << i << endl;
    		 		cout << pair[i] << endl;
    		 	}
    		 	for (int i = 0; i <= strlen(str)-dis; i++) {
    		 		for (int j = i+1; j <= strlen(str)-dis; j++) {
    		 			if (strcmp(pair[i], pair[j]) == 0) {
    		 				printf("%s is NOT surprising.\n", str);
    		 				flag = true;
    		 				break;
    		 			}
    		 		}
    		 		if (flag) break;
    		 	}
    		 }
    		 printf("%s is surprising.\n", str);
    	}
    }
    return 0;
}
