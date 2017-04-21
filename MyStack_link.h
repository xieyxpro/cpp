enum ErrorCode
{
	success,
	underflow,
	overflow
};

template <class StackEntry>
struct Node
{
	StackEntry data;
	Node *next;
};

template <class StackEntry>
class MyStack
{
public:
	MyStack();
	bool empty() const;
	int size() const;
	ErrorCode pop();
	ErrorCode top(StackEntry &item);
	ErrorCode push(const StackEntry &item);
	void clear();
private:
	Node<StackEntry> *pTop;
};

template <class StackEntry>
MyStack<StackEntry>::MyStack()
{
	pTop = NULL;
}

template <class StackEntry>
bool MyStack<StackEntry>::empty() const
{
	return pTop == NULL;
}

template <class StackEntry>
int MyStack<StackEntry>::size() const
{
	int count = 0;
	Node<StackEntry> *tmp = pTop;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}

template <class StackEntry>
ErrorCode MyStack<StackEntry>::pop()
{
	if (empty()) return underflow;
	Node<StackEntry> *tmp = pTop;
	pTop = pTop->next;
	delete tmp;
	return success;
}

template <class StackEntry>
ErrorCode MyStack<StackEntry>::top(StackEntry &item)
{
	if (empty()) return underflow;
	item = pTop->data;
	return success;
}

template <class StackEntry>
ErrorCode MyStack<StackEntry>::push(const StackEntry &item)
{
	Node<StackEntry> *tmp = new Node<StackEntry>;
	if (tmp == NULL) return overflow;
	tmp->data = item;
	tmp->next = pTop;
	pTop = tmp;
	return success;
}

template <class StackEntry>
void MyStack<StackEntry>::clear()
{
	while (!empty())
	{
		pop();
	}
}