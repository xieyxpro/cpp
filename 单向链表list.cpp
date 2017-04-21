enum Error_code {
	success, underflow, overflow
};

template <class List_entry>
struct Node {
	List_entry entry;
	Node<List_entry> *next;
};

template <class List_entry>
class MyList {
public:
	MyList();
	~MyList();
	MyList(const MyList<List_entry> &copy);
	void operator=(const MyList<List_entry> &copy);
	void clear();
	bool empty() const;
	bool full() const;
	int size() const;
	Error_code insert(int position, const List_entry &entry);
	Error_code remove(int position, List_entry &entry);
	Error_code retrieve(int position, List_entry &entry) const;
	Error_code replace(int position, const List_entry &entry);
	void traverse(void (*visit)(List_entry &));
protected:
	int count;
	Node<List_entry> *head;
	mutable int curPosition;
	mutable Node<List_entry> *current;
	void setPosition(int position) const;
};

template <class List_entry>
MyList<List_entry>::MyList() {
	count = 0;
	head = NULL;
	curPosition = 0;
	current = NULL;
}

template <class List_entry>
MyList<List_entry>::~MyList() {
	clear();
}

template <class List_entry>
MyList<List_entry>::MyList(const MyList<List_entry> &copy) {
	head = NULL;
	count = 0;
	curPosition = 0;
	Node<List_entry> *p = copy.head;
	int i = 0;
	while (p != NULL) {
		insert(i, p->entry);
		p = p->next;
		i++;
	}
	curPosition = copy.curPosition;
	setPosition(curPosition);
}

template <class List_entry>
void MyList<List_entry>::operator=(const MyList<List_entry> &copy) {
	if (this != &copy) {
		clear();
		Node<List_entry> *p = copy.head;
		int i = 0;
		while (p != NULL) {
			insert(i, p->entry);
			p = p->next;
			i++;
		}
		curPosition = copy.curPosition;
		setPosition(curPosition);
	}
}

template <class List_entry>
void MyList<List_entry>::clear() {
	int i;
	while (head != NULL) {
		remove(0, i);
	}
}

template <class List_entry>
bool MyList<List_entry>::empty() const {
	return count == 0;
}

template <class List_entry>
bool MyList<List_entry>::full() const {
	Node<List_entry> *p = NULL;
	p = new Node<List_entry>();
	if (p == NULL) {
		return true;
	} else {
		delete p;
		return false;
	}
}

template <class List_entry>
int MyList<List_entry>::size() const {
	return count;
}

template <class List_entry>
Error_code MyList<List_entry>::insert(int position, const List_entry &entry) {
	if (full()) return overflow;
	if (position < 0 || position > count) return underflow;
	if (count == 0) {
		head = new Node<List_entry>();
		head->entry = entry;
		head->next = NULL;
		curPosition = 0;
		current = head;
	} else if (position == 0) {
		Node<List_entry> *p = new Node<List_entry>();
		p->entry = entry;
		p->next = head;
		head = p;
		current = head;
		curPosition = 0;
	} else {
		setPosition(position - 1);
		Node<List_entry> *p = new Node<List_entry>();
		p->entry = entry;
		p->next = current->next;
		current->next = p;
	}
	count++;
	return success;
}

template <class List_entry>
Error_code MyList<List_entry>::remove(int position, List_entry &entry) {
	if (position < 0 || position >= count) return underflow;
	if (count == 1) {
		entry = head->entry;
		delete head;
		head = NULL;
		curPosition = 0;
		current = NULL;
	} else if (position == 0) {
		Node<List_entry> *p = head;
		head = head->next;
		entry = p->entry;
		delete p;
		current = head;
		curPosition = 0;
	} else {
		setPosition(position - 1);
		Node<List_entry> *tmp = current->next;
		current->next = tmp->next;
		entry = tmp->entry;
		delete tmp;
	}
	count--;
	return success;
}

template <class List_entry>
Error_code MyList<List_entry>::retrieve(int position, List_entry &entry) const {
	if (position < 0 || position >= count) return underflow;
	setPosition(position);
	entry = current->entry;
	return success;
}

template <class List_entry>
Error_code MyList<List_entry>::replace(int position, const List_entry &entry) {
	if (position < 0 || position >= count) return underflow;
	setPosition(position);
	current->entry = entry;
	return success;
}

template <class List_entry>
void MyList<List_entry>::traverse(void (*visit)(List_entry &)) {
	Node<List_entry> *p = head;
	while (p != NULL) {
		visit(p->entry);
		p = p->next;
	}
}

template <class List_entry>
void MyList<List_entry>::setPosition(int position) const {
	if (position < curPosition) {
		curPosition = 0;
		current = head;
	}
	for ( ; curPosition != position; curPosition++)
		current = current->next;
}