//
// Created by vaugh on 2025-02-13.
//
#include <iostream>
#include "Node.cpp"
using namespace std;

class List {

public:
    //This is head = first and tail = first
    Node* first = nullptr;
    Node* last = nullptr;

    void append(int value) {
        Node *newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
        }  else {
            newNode->prev = last;
            last->next = newNode;
        }
        last = newNode;
    }

    void prepend(int value) {
        Node *newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }  else {
            newNode-> next = first;
            first->prev = newNode;
            first = newNode;
        }
    }

    int size() {
        int count = 1;
        Node* current = first;
        while (current != last) {
            count++;
            current = current->next;
        }
        return count;
    }

    Node* index(int value) {
        if (value < 0) {
            cout << "Enter Valid Number." << endl;
            return nullptr;
        }

        int count = 0;
        Node* current = first;
        while (current != nullptr) {
            if (count == value) {
                return current;
            }
            count++;
            current = current->next;
        }
        cout << "Enter a smaller number." << endl;
        return nullptr;
    }

    void pop() {
        if (last == nullptr) {
            return;
        }

        if(first == last){
            first = nullptr;;
            last = nullptr;
        }
        else {
            last = last->prev;
            last->next = nullptr;
        }
    }

    bool contains(int value) {
        Node* current = first;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int find(int value) {
        Node* current = first;
        int count = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return count;
            }
            count++;
            current = current->next;
        }
        return -1;
    }
};