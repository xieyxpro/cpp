 template <typename E>

class list
{
private:
	struct Node
	{
		E data;
		Node * prev;
		Node * next;
	};
	
	int nodeCount;
	Node * first;
	
	void clear() {
		while (nodeCount > 0) {
			pop_front();
		}
	}	
	
public:
 
	list() {
		nodeCount = 0;
	}
	
	~list() {
		clear();
	}
	
	int size() {
		return nodeCount;
	}
	
	bool empty() {
		return nodeCount == 0;
	}
 
	E front() {
		if (nodeCount == 0)
			throw runtime_error("The first element does not exist.");
		return first->data;
	}
	
	E back() {
		if (nodeCount == 0)
			throw runtime_error("The last element does not exist.");
		return first->prev->data;
	}
	
	void push_back(E e) {
		push_front(e);
		first = first->next;
	}
 
	void pop_back() {
		if (nodeCount == 0)
			throw runtime_error("The last element does not exist.");
		first = first->prev;
		pop_front();
	}
	
// TODO:
	list(const list & that);
	list & operator= (const list & that);
	void push_front(E e);
	void pop_front();
};

template <typename E>
list<E>::list(const list &that) {
	first = 0;
	nodeCount = 0;
	Node *tmp = that.first;
	for (int i = 0; i < that.nodeCount; i++) {
		push_back(tmp->data);
		tmp = tmp->next;
	}
}

template <typename E>
list<E> & list<E>::operator=(const list &that) {
	if (this != &that) {
		clear();
		Node *tmp = that.first;
		for (int i = 0; i < that.nodeCount; i++) {
			push_back(tmp->data);
			tmp = tmp->next;
		}
	}
	return *this;
}

template <typename E>
void list<E>::push_front(E e) {
	if (nodeCount == 0) {
		first = new Node();
		first->data = e;
		first->next = first;//重要
		first->prev = first;//重要
	} else {
		Node *tmp = new Node();
		tmp->data = e;
		tmp->prev = first->prev;
		tmp->next = first;
		first->prev->next = tmp;
		first->prev = tmp;
		first = tmp;
	}
	nodeCount++;
}

template <typename E>
void list<E>::pop_front() {
	if (nodeCount == 0)
		throw runtime_error("The first element does not exist.");

	if (nodeCount == 1) {
		delete first;
		first = 0;
	} else {
		Node *tmp = first;
		first = first->next;
		tmp->prev->next = first;
		first->prev = tmp->prev;
		delete tmp;
	}

	nodeCount--;
}