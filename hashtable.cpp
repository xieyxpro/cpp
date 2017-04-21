 #include <iostream>
 #include <vector>
 using namespace std;
 
 template <typename Key, typename Value>

class HashTable // HashMap, Dictionary, Table
{
	struct Pair
	{
		bool isEmpty;
		Key key;
		Value value;
		
		Pair() {
			isEmpty = true;
		}
	};
	
private:
	Pair * storage;
	int capacity;
	int count;
	
public:
	HashTable(int size = 10) {
		capacity = size;
		storage = new Pair[capacity];
		count = 0;
	}
 
	~HashTable() {
		delete [] storage;
	}
 
	void clear() {
		delete [] storage;
		storage = new Pair[capacity];
		count = 0;
	}
 
	int size() const {
		return count;
	}
 
	vector<Key> getKeys() const {
		vector<Key> keys;
		for (int i = 0; i < capacity; ++ i) {
			if (storage[i].isEmpty) continue;
			keys.push_back(storage[i].key);
		}
		return keys;
	}
 
// TODO:
	HashTable(const HashTable & table);
	HashTable & operator = (const HashTable & table);
	bool hasKey(const Key & key) const;
	const Value & get(const Key & key) const;
	void put(const Key & key, const Value & value);
};

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(const HashTable &table) {
	capacity = table.capacity;
	count = table.count;

	if (capacity > 0)
		storage = new Pair[capacity];

	int i;
	for (i = 0; i < count; i++) {
		storage[i] = table.storage[i];
	}
}

template <typename Key, typename Value>
HashTable<Key, Value> & HashTable<Key, Value>::operator=(const HashTable &table) {
	if (this != &table) {
		delete []storage;
		capacity = table.capacity;
		count = table.count;
		if (capacity > 0)
			storage = new Pair[capacity];

		int i;
		for (i = 0; i < count; i++)
			storage[i] = table.storage[i];
	}
	return *this;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::hasKey(const Key & key) const {
	vector<Key> v = getKeys();
	int i;
	for (i = 0; i < v.size(); i++)
		if (v[i] == key) return true;

	return false;
}

template <typename Key, typename Value>
const Value & HashTable<Key, Value>::get(const Key & key) const {
	int i;
	for (i = 0; i < count; i++) {
		if (!storage[i].isEmpty && storage[i].key == key) {
			return storage[i].value;
		}
	}
}

template <typename Key, typename Value>	
void HashTable<Key, Value>::put(const Key & key, const Value & value) {
	int i;
	if (hasKey(key)) {
		for (i = 0; i < count; i++) {
			if (!storage[i].isEmpty && storage[i].key == key)
				storage[i].value = value;
		}
	} else {
		if (count == capacity) {
			capacity *= 2;
			Pair *tmp = new Pair[capacity];
			for (i = 0; i < count; i++)
				tmp[i] = storage[i];
			delete []storage;
			storage = tmp;
		}
		storage[count].key = key;
		storage[count].value = value;
		storage[count].isEmpty = false;
		count++;
	}
}

int main(void) {
	HashTable<int, int> a;
	a.put(1, 1);
	cout << a.get(1);
	return 0;
}
