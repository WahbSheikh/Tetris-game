#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    deleteList();
}

void LinkedList::addNode(std::string name, int score) {
    Node* newNode = new Node(name, score);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::deleteNode(std::string name) {
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Node not found" << std::endl;
        return;
    }
    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
}

void LinkedList::deleteList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}

void LinkedList::SortList() {
    // Using Insertion Sort (O(n^2))
    Node* sorted = nullptr;

    while (head != nullptr) {
        Node* current = head;
        head = head->next;

        if (sorted == nullptr || sorted->score < current->score) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->score >= current->score) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}

LinkedList::Node* LinkedList::getHead() const {
    return head;
}
