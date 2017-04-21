#include <iostream>
#include <cstdio>
using namespace std;

template <class Record>
class Sortable_list {
public:
	void build_heap();
	void heap_sort();
	void insert_heap(const Record &current, int low, int high);
	void input(int count);
	void print();
private:
	Record entry[100001];
	int count;
};

template <class Record>
void Sortable_list<Record>::build_heap() {
	int low;
	for (low = count / 2 - 1; low >= 0; low--) {
		Record current = entry[low];
		insert_heap(current, low, count - 1);
	}
	print();
}

template <class Record>
void Sortable_list<Record>::heap_sort() {
	Record current;
	int last_unsorted;
	build_heap();
	for (last_unsorted = count - 1; last_unsorted > 0; last_unsorted--) {
		current = entry[last_unsorted];
		entry[last_unsorted] = entry[0];
		insert_heap(current, 0, last_unsorted - 1);
		print();
	}
}

template <class Record>
void Sortable_list<Record>::insert_heap(const Record &current, int low, int high) {
	int large = low * 2 + 1;
	while (large <= high) {
		if (large < high && entry[large] < entry[large + 1]) large++;
		if (current >= entry[large]) break;
		else {
			entry[low] = entry[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	entry[low] = current;
}

template <class Record>
void Sortable_list<Record>::input(int count) {
	this->count = count;
	for (int i = 0; i < count; i++)
		cin >> entry[i];
}

template <class Record>
void Sortable_list<Record>::print() {
	for (int i = 0; i < count - 1; i++) cout << entry[i] << " ";
	cout << entry[count - 1] << endl;
}

int main(void) {
	int n;
	while (cin >> n) {
		Sortable_list<int> s;
		s.input(n);
		s.heap_sort();
	}
	return 0;
}
