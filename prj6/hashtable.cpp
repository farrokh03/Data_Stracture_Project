#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
    static const int capacity = 10;
    list<pair<int, string>> table[capacity];

public:
    
    int hash(int key) {
        return key % capacity;
    }

    
    void insert(int key, const string& value) {
        int index = hash(key);
        table[index].push_back(make_pair(key, value));
    }


    string search(int key) {
        int index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Key not found";
    }

    
    void remove(int key) {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
    void printTable() {
        for (int i = 0; i < capacity; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            cout << "\n";
        }
    }
};

