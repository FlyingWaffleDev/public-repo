// ====================
// FlyingWaffle
// 3/3/2020
// Doubly Linked List
// ====================

#ifndef __DLLIST__
#define __DLLIST__

#include <iostream>

template<typename T> class DLList {
	private:
        class Node {
            private:
                T value;
                Node *next = nullptr;
                Node *prev = nullptr;

            public:
                explicit Node(T value) {
                    this->value = value;
                }
                
            friend class DLList<T>;
        };

		Node* first = nullptr;
		Node* last = nullptr;
		int length = 0;
		
		void RemoveFinal() {
			delete first;
			first = last = nullptr;
			length--;
		}

	public:
		DLList() = default;

		explicit DLList(T value) {
			AddToEmpty(value);	
		}

		DLList(const DLList<T>& src) {
			Node* curr = src.first;
			while (curr != nullptr) {
				Append(curr->value);
				curr = curr->next;
			}
		}

		~DLList() {
			while(!IsEmpty())
				RemoveFirst();
		}

		[[nodiscard]] bool IsEmpty() const {
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

		[[nodiscard]] int GetLength() const {
			return length;
		}

		void AddToEmpty(T value) {
			first = last = new Node(value);
			length++;
		}

		void Prepend(T value) {
			if (IsEmpty())
				AddToEmpty(value);
			else {
				auto* curr = new Node(value);
				curr->next = first;
				first->prev = curr;
				first = curr;
				length++;
			}
		}

		void Append(T value) {
			if (IsEmpty())
				AddToEmpty(value);
			else {
				auto* curr = new Node(value);
				last->next = curr;
				curr->prev = last;
				last = curr;
				length++;
			}
		}

		bool RemoveFirst() {
			if (length > 0) {
                if (length == 1) {
                    RemoveFinal();
                } else {
                    Node* curr = first;
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
                    Node* curr = last;
                    last = last->prev;
                    delete curr;
                    length--;
                }
                return true;
		    }
		    return false;
		}
};

#endif //__DLLIST__
