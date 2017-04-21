#ifndef AVL_NODE
#define AVL_NODE

template <class Entry>
struct AvlNode {
    Entry entry;
    AvlNode<Entry> *left;
	AvlNode<Entry> *right;
    int bf;                // balance factor 平衡因子
};

#endif

// 查找AVL树里面是否有元素entry，如果有则返回该结点，没有则返回NULL
template <class Entry>
AvlNode<Entry> *AVL_search(AvlNode<Entry> *&root, const Entry entry) {
	AVL_NODE<Entry>* result = root;
	while (result != NULL && result->entry != entry) {
		if (result->entry > target) result = result->left;
		else result = result->right;
	}
	return result;
}

// 将entry插入到AVL树
template <class Entry>
void AVL_insert(AvlNode<Entry> *&root, const Entry entry) {
	bool taller;
	insert(root, entry, taller);
}

template <class Entry>
bool insert(AvlNode<Entry> *t, const Entry& entry, bool &taller) {
	if (t == NULL) {
		t = new AvlNode<Entry>();
		t->left = t->right = NULL;
		t->entry = entry;
		taller = true;
	} else if (t->entry == entry) taller = false;
	else if (entry < t->entry) {
		
	}
}

template <class Entry>
AvlNode<Entry> *rightRotate(AvlNode<Entry> *a) {
	AvlNode<Entry> *b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

template <class Entry>
AvlNode<Entry> *leftRotate(AvlNode<Entry> *a) {
	AvlNode<Entry> *b = a->right;
	a->right = b->left;
	b->left = a;
	return b;
}

template <class Entry>
AvlNode<Entry> *leftRightRotate(AvlNode<Entry> *a) {
	a->left = leftRotate(a->left);
	return rightRotate(a);
}

template <class Entry>
AvlNode<Entry> *rightLeftRotate(AvlNode<Entry> *a) {
	a->right = rightRotate(a->right);
	return leftRotate(a);
}