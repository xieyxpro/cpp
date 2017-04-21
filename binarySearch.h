//没有则返回-1，有则返回最后出现的地址
template <typename T>
int binarySearch(const vector<T> table, int bot, int top, const T &x) {
	while (bot < top) {
		int mid = (bot + top) / 2 + 1;
		if (table[mid] <= x) bot = mid;
		else top = mid - 1;
	}
	if (bot > top) return -1;
	else {
		if (table[bot] == x) return bot;
		else return -1;
	}
}