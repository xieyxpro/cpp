enum ErrorCode
{
	success,
	underflow,
	overflow
};

template <class QueueEntry>
struct Node
{
	QueueEntry data;
	Node<QueueEntry> *next;
};

template <class QueueEntry>
class MyQueue
{
public:
	MyQueue();
	bool empty() const;
	ErrorCode append(const QueueEntry &item);
	ErrorCode serve();
	ErrorCode retrieve(QueueEntry &item) const;
	int size() const;
	void clear();
	ErrorCode retrieve_and_serve(QueueEntry &item);
private:
	Node<QueueEntry> *front;
	Node<QueueEntry> *rear;
};

template <class QueueEntry>
MyQueue<QueueEntry>::MyQueue()
{
	front = rear = NULL;
}

template <class QueueEntry>
bool MyQueue<QueueEntry>::empty() const
{
	return front == NULL && rear == NULL;
}

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::append(const QueueEntry &item)
{
	Node<QueueEntry> *tmp = new Node<QueueEntry>;
	if (tmp == NULL) return overflow;
	tmp->data = item;
	tmp->next = NULL;
	if (empty())
	{
		front = rear = tmp;
	} else
	{
		rear->next = tmp;
		rear = tmp;
	}
	return success;
}

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::serve()
{
	if (empty()) return underflow;
	Node<QueueEntry> *tmp = front;
	front = front->next;
	if (front == NULL) rear = NULL;
	delete tmp;
	return success;
}

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve(QueueEntry &item) const
{
	if (empty()) return underflow;
	item = front->data;
	return success;
}

template <class QueueEntry>
int MyQueue<QueueEntry>::size() const
{
	int count = 0;
	Node<QueueEntry> *tmp = front;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}

template <class QueueEntry>
void MyQueue<QueueEntry>::clear()
{
	while (!empty())
	{
		serve();
	}
}

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve_and_serve(QueueEntry &item)
{
	retrieve(item);
	serve();
}