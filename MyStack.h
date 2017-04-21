enum ErrorCode
{
	success,
	underflow,
	overflow
};

const int maxStack = 100;

template <class StackEntry>
class MyStack
{
public:
	MyStack();
	bool empty() const {return size == 0;}
	ErrorCode pop();
	ErrorCode top(StackEntry &item);
	ErrorCode push(const StackEntry &item);
private:
	int size;
	StackEntry entry[maxStack];
};

template <class StackEntry>
MyStack<StackEntry>::MyStack()
{
	size = 0;
}

template <class StackEntry>
ErrorCode MyStack<StackEntry>::pop()
{
	if (empty())
	{
		return underflow;
	} else
	{
		size--;
		return success;
	}
}

template <class StackEntry>
ErrorCode MyStack<StackEntry>::top(StackEntry &item)
{
	if (empty())
	{
		return underflow;
	} else
	{
		item = entry[--size];
		return success;
	}
}

template <class StackEntry>
ErrorCode MyStack<StackEntry>::push(const StackEntry &item)
{
	if (size < maxStack)
	{
		entry[size++] = item;
		return success;
	} else
	{
		return overflow;
	}
}