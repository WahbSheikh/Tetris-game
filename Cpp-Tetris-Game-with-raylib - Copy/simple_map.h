#pragma once
#include <vector>
#include <stdexcept>
#include "position.h"

class SimpleMap
{
public:
    struct KeyValuePair {
        int key;
        std::vector<Position> value;
    };

    // Insert a key-value pair
    void Insert(int key, const std::vector<Position>& value) {
        for (int i = 0; i < size; i++) {
            if (pairs[i].key == key) {
                pairs[i].value = value;  // Update if key exists
                return;
            }
        }
        if (size < MAX_SIZE) {
            pairs[size++] = { key, value };  // Add new key-value pair
        }
    }

    // Retrieve a value by key using operator[]
    std::vector<Position>& operator[](int key) {
        for (int i = 0; i < size; i++) {
            if (pairs[i].key == key) {
                return pairs[i].value;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Get the number of key-value pairs
    int GetSize() const {
        return size;
    }

    // Check if the key exists
    bool ContainsKey(int key) const {
        for (int i = 0; i < size; i++) {
            if (pairs[i].key == key) {
                return true;
            }
        }
        return false;
    }

private:
    static const int MAX_SIZE = 10; 
    KeyValuePair pairs[MAX_SIZE];   
    int size = 0;                   
};
