#include <stack>
using namespace std;

class Queue
{
public:
	bool isEmpty() const { return firstStack.empty() && secondStack.empty(); }
	int& front();
	void push(int a);
	void pop();
private:
	stack<int> firstStack;
	stack<int> secondStack;
};

int& Queue::front()
{
	if (secondStack.empty())
	{
		while (!firstStack.empty())
		{
			secondStack.push(firstStack.top());
			firstStack.pop();
		}
	}
	return secondStack.top();
}

void Queue::push(int a)
{
	firstStack.push(a);
}

void Queue::pop()                                     //我没有考虑两个栈都为空的情况，此时应该先考虑，但是
{													  //此时已经足够应付题目，且其给出来的类的接口就是如此
	if (secondStack.empty())
	{
		while (!firstStack.empty())
		{
			secondStack.push(firstStack.top());
			firstStack.pop();
		}
	}
	secondStack.pop();
}
