#include <iostream>
using namespace std;

template <class Record>
void quick_sort(Record *startPointer, Record *endPointer) {
	if (startPointer < endPointer) {
		Record x = *startPointer;
		Record *low = startPointer, *high = endPointer - 1;

		do {
			while (*low < x) low++;
			while (*high > x) high--;
			if (low <= high) {
				Record tmp = *low;
				*low = *high;
				*high = tmp;
				low++, high--;
			}
		} while (low <= high);

		quick_sort(startPointer, high + 1);
		quick_sort(low, endPointer);
	}
}

int main(void) {
	int arr[5] = {5, 4, 3, 2, 1};
	quick_sort(arr, arr + 5);
	for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
