#include <iostream>

using std::cout;
using std::endl;

class MyArray
{
public:
	MyArray();
	void insert(int position, int content);
	void deleteByPosition(int position);
	void print();
private:
	int contents[100];
	int size;
};

MyArray::MyArray() {
	size = 0;
}

void MyArray::insert(int position, int content) {
	if (position <= size) {
		for (int i = size - 1; i >= position; i--) {
			contents[i + 1] = contents[i];
		}
		contents[position] = content;
	} else {
		contents[size] = content;
	}
	size++;
}

void MyArray::deleteByPosition(int position) {
	if (position < size) {
		for (int i = position; i < size; ++i) {
			contents[i] = contents[i + 1];
		}
		size--;
	} else {}
}

void MyArray::print() {
	for (int i = 0; i < size; ++i) {
		cout << contents[i] << "\t";
	}
	cout << endl;
}