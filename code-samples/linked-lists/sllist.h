// ====================
// FlyingWaffle
// 3/3/2020
// Singly Linked List
// ====================

#ifndef __SLLIST__
#define __SLLIST__

#include <iostream>

template<typename T> class SLList {
	private:
        class Node {
            private:
                T value;
                Node *next = nullptr;
                
            public:
                explicit Node(T value) {
                    this->value = value;
                }
        
            friend class SLList<T>;
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
		SLList() = default;

		explicit SLList(T value) {
			AddToEmpty(value);
		}

		SLList(const SLList<T>& src) {
			Node* curr = src.first;
			while (curr != nullptr) {
				Append(curr->value);
				curr = curr->next;
			}
		}

		~SLList() {
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
                    Node* curr = first;
                    while (curr->next != last) {
                        curr = curr->next;
                    }
                    curr->next = nullptr;
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
