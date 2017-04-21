#include <iostream>
#include <cstring>
using namespace std;

int x[50];

void display(int k)
{
	for (int i = 0; i < k - 1; ++i)
	{
		cout << x[i] << "+";
	}
	cout << x[k - 1] << endl;
}

void split(int n, int k)
{
	if (n == 0) display(k);
	else
		for (int i = n; i > 0; --i)
		{
			if (k == 0 || i <= x[k - 1])
			{
				x[k] = i;
				split(n - i, k + 1);
			}
		}
}

int main(void)
{
	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		memset(x, 0, sizeof(x));
		split(m, 0);
	}
	return 0;
}
