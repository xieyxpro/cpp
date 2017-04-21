#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int main(void)
{
	int m;
	string str;
	cin >> m;
	getline(cin, str);
	while (m--)
	{
		getline(cin, str);
		string tmp;
		stack<char> s;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ') continue;
			else if (str[i] == '+' || str[i] == '-')
			{
				if (s.empty()) s.push(str[i]);
				else
				{
					while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'))
					{
						tmp += s.top();
						s.pop();
					}
					s.push(str[i]);
				}
			}
			else if (str[i] == '*' || str[i] == '/')
			{
				if (s.empty()) s.push(str[i]);
				else
				{
					while (!s.empty() && (s.top() == '*' || s.top() == '/'))
					{
						tmp += s.top();
						s.pop();
					}
					s.push(str[i]);
				}
			}
			else
			{
				tmp += str[i];
			}
		}
		while (!s.empty())
		{
			tmp += s.top();
			s.pop();
		}
		stack<double> data;
		for (int i = 0; i < tmp.length(); ++i)
		{
			if (tmp[i] == '+')
			{
				double a = data.top();
				data.pop();
				double b = data.top();
				data.pop();
				data.push(a + b);
			}
			else if (tmp[i] == '-')
			{
				double a = data.top();
				data.pop();
				double b = data.top();
				data.pop();
				data.push(b - a);
			}
			else if (tmp[i] == '*')
			{
				double a = data.top();
				data.pop();
				double b = data.top();
				data.pop();
				data.push(a * b);
			}
			else if (tmp[i] == '/')
			{
				double a = data.top();
				data.pop();
				double b = data.top();
				data.pop();
				data.push(b / a);
			}
			else
			{
				data.push(tmp[i] - '0');
			}
		}
		printf("%.3f\n", data.top());
	}
	return 0;
}
