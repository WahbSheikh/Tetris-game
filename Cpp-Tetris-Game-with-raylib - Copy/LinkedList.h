#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

class LinkedList {
public:
    // Public nested Node class
    class Node {
    public:
        std::string name;
        int score;
        Node* next;

        Node(std::string name, int score) : name(name), score(score), next(nullptr) {}
    };

private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void addNode(std::string name, int score);
    void deleteNode(std::string name);
    void deleteList();
    void SortList();
    Node* getHead() const;
};

#endif
