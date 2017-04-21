enum Error_code {
	success, underflow, overflow
};

template <class List_entry>
struct Node {
	List_entry entry;
	Node<List_entry> *next;
	Node<List_entry> *back;
	Node() {
		entry = 0;
		back = next = NULL;
	}
	Node(List_entry _entry, Node<List_entry> *link_back = NULL,
		Node<List_entry> *link_next = NULL) {
		entry = _entry;
		back = link_back;
		next = link_next;
	}
};

template <class List_entry>
class MyList {
public:
	MyList();
	~MyList();
	MyList(const MyList<List_entry> &copy);
	void operator=(const MyList<List_entry> &copy);
	void clear();
	bool empty() const { return count == 0; }
	bool full() const;
	int size() const { return count; }
	Error_code insert(int position, const List_entry &entry);
	Error_code remove(int position, List_entry &entry);
	Error_code retrieve(int position, List_entry &entry) const;
	Error_code replace(int position, const List_entry &entry);
	void traverse(void (*visit)(List_entry &));
protected:
	int count;
	mutable int curPosition;
	mutable Node<List_entry> *current;
	void setPosition(int position) const;
};

template <class List_entry>
MyList<List_entry>::MyList() {
	count = 0;
	curPosition = 0;
	current = NULL;
}

template <class List_entry>
MyList<List_entry>::~MyList() {
	clear();
	curPosition = 0;
}

template <class List_entry>
MyList<List_entry>::MyList(const MyList<List_entry> &copy) {
	current = NULL;
	curPosition = 0;
	count = 0;
	if (copy.count) {
		insert(0, copy.current->entry);
		Node<List_entry> *p = copy.current->back;
		while (p != NULL) {
			insert(0, p->entry);
			p = p->back;
		}
		p = copy.current->next;
		while (p != NULL) {
			insert(count, p->entry);
			p = p->next;
		}
	}
}

template <class List_entry>
void MyList<List_entry>::operator=(const MyList<List_entry> &copy) {
	if (this != &copy) {
		clear();
		if (copy.count) {
			insert(0, copy.current->entry);
			Node<List_entry> *p = copy.current->back;
			while (p != NULL) {
				insert(0, p->entry);
				p = p->back;
			}
			p = copy.current->next;
			while (p != NULL) {
				insert(count, p->entry);
				p = p->next;
			}
		}
	}
}

template <class List_entry>
void MyList<List_entry>::clear() {
	int i = 0;
	while (!empty()) {
		remove(0, i);
	}
}

template <class List_entry>
bool MyList<List_entry>::full() const {
	Node<List_entry> *p = NULL;
	p = new Node<List_entry>();
	if (p == NULL) return true;
	else {
		delete p;
		return false;
	}
}

template <class List_entry>
Error_code MyList<List_entry>::insert(int position, const List_entry &entry) {
	if (full()) return overflow;
	if (position < 0 || position > count) return underflow;
	Node<List_entry> *new_node, *follow, *preceding;
	if (position < 0 || position > count) return underflow;
	if (position == 0) {
		if (count == 0) {
			current = new Node<List_entry>(entry, NULL, NULL);
			curPosition = 0;
		} else {
			setPosition(0);
			Node<List_entry> *p = new Node<List_entry>(entry, NULL, current);
			current->back = p;
			current = p;
			curPosition = 0;
		}
	} else {
		if (position == count) {
			setPosition(position -1);
			Node<List_entry> *p = new Node<List_entry>(entry, current, NULL);
			current->next = p;
		} else {
			setPosition(position - 1);
			Node<List_entry> *p = new Node<List_entry>(entry, current, current->next);
			current->next = p;
			p->next->back = p;
		}
	}
	count++;
	return success;
}

template <class List_entry>
Error_code MyList<List_entry>::remove(int position, List_entry &entry) {
	if (position < 0 || position >= count) return underflow;
	if (count == 1) {
		entry = current->entry;
		delete current;
		current = NULL;
	} else if (position == 0) {
		setPosition(1);
		Node<List_entry> *p = current->back;
		entry = p->entry;
		current->back = NULL;
		curPosition = 0;
		delete p;
	} else if (position == count - 1) {
		setPosition(position - 1);
		Node<List_entry> *p = current->next;
		entry = p->entry;
		current->next = NULL;
		delete p;
	} else {
		setPosition(position - 1);
		Node<List_entry> *p = current->next;
		entry = p->entry;
		current->next = p->next;
		p->next->back = current;
		delete p;
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
	if (current != NULL) {
		setPosition(0);
		Node<List_entry> *p = current;
		while (p != NULL) {
			visit(p->entry);
			p = p->next;
		}
	}
}

template <class List_entry>
void MyList<List_entry>::setPosition(int position) const {
	if (position < curPosition) 
		for ( ; curPosition != position; curPosition--)
			current = current->back;
	else 
		for ( ; curPosition != position; curPosition++)
			current = current->next;
}