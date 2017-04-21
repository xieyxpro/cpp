 #include <iostream>

 template <typename E>

class LinkedList
{
private:
 
  // inner class: linked-list node
  class Node
  {
  public:
    E data;
    Node * next;
  };
 
  Node * first;
 
public:
  LinkedList() {
    first = 0;
  }
 
  ~LinkedList() {
    while (first != 0) {
      removeFirst();
    }
  }
 
  E getFirst() {
    return first->data;
  }
 
  bool isEmpty() {
    return first == 0;
  }
 
// TODO:
  LinkedList(const LinkedList & that);
  LinkedList & operator= (const LinkedList & that);
  void removeFirst() ;
  void addFirst(E data);
};

template <typename E>
LinkedList<E>::LinkedList(const LinkedList &that) {
    first = NULL;
    Node *tmp = that.first;
    while (tmp != NULL) {
        addFirst(tmp->data);
        tmp = tmp->next;
    }
}

template <typename E>
LinkedList<E> & LinkedList<E>::operator=(const LinkedList &that) {
    if (this != &that) {
        while (first != NULL)
            removeFirst();

        Node *tmp = that.first;
        while (tmp != NULL) {
            addFirst(tmp->data);
            tmp = tmp->next;
        }
    }
    return *this;
}

template <typename E>
void LinkedList<E>::removeFirst() {
    if (first != NULL) {
        Node *newFirst = first->next;
        delete first;
        first = newFirst;
    }
}

template <typename E>
void LinkedList<E>::addFirst(E data) {
    if (first != NULL) {
        Node *tmp = new Node();
        tmp->data = data;
        tmp->next = first;
        first = tmp;
    } else {
        first = new Node();
        first->data = data;
        first->next = NULL;
    }
}                           