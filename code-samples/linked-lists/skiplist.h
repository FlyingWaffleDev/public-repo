// ====================
// FlyingWaffle
// 3/3/2020
// Skip List
// ====================

#ifndef __SLLIST__
#define __SLLIST__

#include <iostream>

template<typename T> class SLList;

template<typename T> class Node {
private:
    T value;
    Node* next;
public:
    Node(T value) {
        this->value = value;
        Node* next = NULL;
    }
    friend class SLList<T>;
};


template<typename T> class SLList {
	private:
		Node<T>* first;
		Node<T>* last;
		int length;
		
		void RemoveFinal() {
			delete first;
			first = last = NULL;
			length--;
		}

	public:
		SLList() {
			first = last = NULL;
			length = 0;
		}

		SLList(T value) {
			first = last = NULL;
			length = 0;
			AddToEmpty(value);	
		}

		SLList(const SLList<T>& src) {
			first = last = NULL;
			length = 0;
			Node<T>* curr = src.first;
			while (curr != NULL) {
				Append(curr->value);
				curr = curr->next;
			}
		}

		~SLList() {
			while(!IsEmpty())
				RemoveFirst();
		}

		bool IsEmpty() const {
			return (length == 0);
		}

		T GetFirst() const {
			//assert(!IsEmpty());
			return first->value;
		}

		T GetLast() const {
			//assert(!IsEmpty());
			return last->value;
		}

		int GetLength() const {
			return length;
		}

		void AddToEmpty(T value) {
			first = last = new Node<T>(value);
			length++;
		}

		void Prepend(T value) {
			if (IsEmpty())
				AddToEmpty(value);
			else {
				Node<T>* curr = new Node<T>(value);
				curr->next = first;
				first = curr;
				length++;
			}
		}

		void Append(T value) {
			if (IsEmpty())
				AddToEmpty(value);
			else {
				Node<T>* curr = new Node<T>(value);
				last->next = curr;
				last = curr;
				length++;
			}
		}

		bool RemoveFirst() {
			if (length > 0) {
                if (length == 1) {
                    RemoveFinal();
                } else {
                    Node<T> *curr = first;
                    first = first->next;
                    delete curr;
                    length--;
                }
                return true;
            }
			return false;
		}

		bool RemoveLast() {
		    if (length > 0) {
                if (length == 1)
                    RemoveFinal();
                else {
                    Node<T> *curr = first;
                    while (curr->next != last) {
                        curr = curr->next;
                    }
                    curr->next = NULL;
                    delete last;
                    last = curr;
                    length--;
                }
                return true;
		    }
		    return false;
		}
};

#endif //__SLLIST__
