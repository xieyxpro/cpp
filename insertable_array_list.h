#include <iostream>

using std::cout;
using std::endl;

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insert(int position, int content);
	void deleteByPosition(int position);
	void print();
private:
	Node *head;
	int size;
};

LinkedList::LinkedList()
{
	size = 0;
	head = new Node();
	head->next = NULL;
}

LinkedList::~LinkedList()
{
	while (head->next != NULL)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
	delete head;
}

void LinkedList::insert(int position, int content) {
	if (size == 0)
	{
		head->data = content;
	}
	else if (position == 0)
	{
		Node *tmp = new Node();
		tmp->data = content;
		tmp->next = head;
		head = tmp;
	} else if (position < size)
	{
		Node *count = head;
		for (int i = 0; i < position - 1; i++)
		{
			count = count->next;
		}
		Node *tmp = new Node();
		tmp->data = content;
		tmp->next = count->next;
		count->next = tmp;
	} else
	{
		Node *node = new Node();
		node->data = content;
		node->next = NULL;
		Node *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
	size++;
}

void LinkedList::deleteByPosition(int position)
{
	Node *count = head;
	if (position == 0)
	{
		if (size != 1)
		{
			head = head->next;
			delete count;
		}
		size--;
	} else if (position < size)
	{
		for (int i = 0; i < position - 1; ++i)
		{
			count = count->next;
		}
		Node *tmp = count->next;
		count->next = tmp->next;
		delete tmp;
		size--;
	} else {}
}

void LinkedList::print()
{
	if (size)
	{
		Node *count = head;
		while (count != NULL)
		{
			cout << count->data << "\t";
			count = count->next;
		}
	}
	cout << endl;
}