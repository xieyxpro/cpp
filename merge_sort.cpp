#include <iostream>
using namespace std;

template <class Record>
struct Node
{
	Record entry;
	Node<Record> *next;
};

template <class Record>
class Sortable_list {
public:
	Sortable_list();
	~Sortable_list();
	void insert(int position, const Record &entry);
	void print();
	void merge_sort();
private:
	Node<Record> *head;
	void recursive_merge_sort(Node<Record> *&sub_list);
	Node<Record> *divide_from(Node<Record> *sub_list);
	Node<Record> *merge(Node<Record> *first, Node<Record> *second);
};

template <class Record>
Sortable_list<Record>::Sortable_list() {
	head = NULL;
}

template <class Record>
Sortable_list<Record>::~Sortable_list() {
	while (head != NULL) {
		Node<Record> *tmp = head->next;
		delete head;
		head = tmp;
	}
}

template <class Record>
void Sortable_list<Record>::insert(int position, const Record &entry) {
	Node<Record> *tmp = new Node<Record>();
	if (position == 0) {
		tmp->entry = entry;
		tmp->next = head;
		head = tmp;
	} else {
		tmp->entry = entry;
		Node<Record> *count = head;
		for (int i = 0; i < position - 1; i++) {
			count = count->next;
		}
		tmp->next = count->next;
		count->next = tmp;
	}
}

template <class Record>
void Sortable_list<Record>::print() {
	Node<Record> *count = head;
	if (count == NULL) cout << endl;
	else {
		while (count->next != NULL) {
			cout << count->entry << " ";
			count = count->next;
		}
		cout << count->entry << endl;
	}
}

template <class Record>
void Sortable_list<Record>::merge_sort() {
	recursive_merge_sort(head);
}

template <class Record>
void Sortable_list<Record>::recursive_merge_sort(Node<Record> *&sub_list) {
	if (sub_list != NULL && sub_list->next != NULL) {
		Node<Record> *second_half = divide_from(sub_list);
		recursive_merge_sort(sub_list);
		recursive_merge_sort(second_half);
		sub_list = merge(sub_list, second_half);
	}
}

template <class Record>
Node<Record> *Sortable_list<Record>::divide_from(Node<Record> *sub_list) {
	Node<Record> *position, *midPoint, *second_half;
	if (sub_list == NULL) return NULL;
	midPoint = sub_list, position = midPoint->next;

	while (position != NULL) {
		position = position->next;
		if (position != NULL) {
			position = position->next;
			midPoint = midPoint->next;
		}
	}

	second_half = midPoint->next;
	midPoint->next = NULL;

	return second_half;
}

template <class Record>
Node<Record> *Sortable_list<Record>::merge(Node<Record> *first, Node<Record> *second) {
	Node<Record> *last_sorted, combined;
	last_sorted = &combined;

	while (first != NULL && second != NULL) {
		if (first->entry <= second->entry) {
			last_sorted->next = first;
			last_sorted = first;
			first = first->next;
		} else {
			last_sorted->next = second;
			last_sorted = second;
			second = second->next;
		}
	}

	if (first == NULL) last_sorted->next = second;
	else last_sorted->next = first;

	return combined.next;
}

int main(void) {
	Sortable_list<int> l;
}