// ====================
// FlyingWaffle
// 3/3/2020
// Skip List
// ====================

#ifndef __SKIPLIST__
#define __SKIPLIST__

#include <iostream>
#include "../Random.h"

using namespace std;

template<typename T> class SkipList {
private:
    static Random random;

    class Node {
    private:
        T data;
        Node* next = nullptr;

        Node(T value, int level) {
            if (level == 1) {
                unsigned int flips = random.nextInt();
                while ((flips & 1u) == 1) {
                    flips >>= 1u;
                    level++;
                }
            }
            data = value;
            next = new Node*[level];
        }

    public:
        explicit Node(T value) {
            this(value, 1);
        }

        friend class SkipList<T>;
    };

    Node* first = nullptr;
    Node* last = nullptr;
    int length = 0;
    int max_levels = 30;

    void RemoveFinal() {
        delete first;
        first = last = nullptr;
        length--;
    }

public:
    SkipList() {
        first = new Node(NULL, max_levels);
        last = new Node(NULL, max_levels);
        for (int i = 0; i < max_levels; i++)
            first->next[i] = last;
    }

    explicit SkipList(int max_levels) {
        this->max_levels = max_levels;
        SkipList();
    }

    SkipList(int max_levels, const SkipList<T>& src) {
        this->max_levels = max_levels;
        first = new Node(NULL, max_levels);
        last = new Node(NULL, max_levels);
    }

    ~SkipList() {
        while(!IsEmpty())
            RemoveFirst();
    }

    [[nodiscard]] bool IsEmpty() const {
        return (length == 0);
    }

    [[nodiscard]] int GetLength() const {
        return length;
    }

    void Add(T value) {
        Node* newNode = new Node(value);
        Node* current = first;
        for (int i = current->next.length - 1; i >= 0; i--) {
            if (current->next[i].data >= newNode->data && i < newNode->next.length) {
                newNode->next[i] = current->next[i];
                current->next[i] = newNode;
            } else if (current->next[i].data < newNode->data) {
                current = current->next[i];
                i++;
            }
        }
    }

    bool Contains(T target) {
        Node* current = first;
        for (int i = current->next.length - 1; i >= 0; i--) {
            if (current->next[i].data == target) {
                return true;
            } else if (current->next[i].data < target) {
                current = current->next[i];
                i++;
            }
        }
        return false;
    }

    


};

#endif //__SKIPLIST__
