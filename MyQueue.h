enum ErrorCode
{
	success,
	underflow,
	overflow
};

const int maxQueue = 100;

template <class QueueEntry>
class MyQueue
{
public:
	MyQueue() { front = rear = 0; }
	bool empty() const { return front == rear; }
	ErrorCode append(const QueueEntry &item);
	ErrorCode serve();
	ErrorCode retrieve(QueueEntry &item);
	bool full() const { return (rear + 1) % maxQueue == front; }
	int size() const { return (rear - front + maxQueue) % maxQueue; }
	void clear() { front = rear = 0; }
	ErrorCode retrieve_and_serve(QueueEntry &item);
private:
	int front;
	int rear;
	QueueEntry entry[maxQueue];
};

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::append(const QueueEntry &item)
{
	if (full())
	{
		return overflow;
	} else
	{
		entry[rear] = item;
		rear = (rear + 1) % maxQueue;
		return success;
	}
}

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::serve()
{
	if (empty())
	{
		return underflow;
	} else
	{
		front = (front + 1) % maxQueue;
		return success;
	}
}

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve(QueueEntry &item)
{
	if (empty())
	{
		return underflow;
	} else
	{
		item = entry[front];
		return success;
	}
}

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve_and_serve(QueueEntry &item)
{
	if (empty())
	{
		return underflow;
	} else
	{
		item = entry[front];
		front = (front + 1) % maxQueue;
		return success;
	}
}