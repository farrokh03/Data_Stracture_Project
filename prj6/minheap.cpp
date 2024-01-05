#include <iostream>

using namespace std;

class MinHeap {
private:
    int* heapArray;
    int capacity;
    int size;

public:
    MinHeap(int cap) : capacity(cap), size(0) {
        heapArray = new int[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        size++;
        int i = size - 1;
        heapArray[i] = value;

        
        while (i > 0 && heapArray[parent(i)] > heapArray[i]) {
            swap(heapArray[i], heapArray[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin() {
        if (size <= 0) {
            cout << "Heap underflow\n";
            return -1; 
        }

        if (size == 1) {
            size--;
            return heapArray[0];
        }

        int root = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;

        
        heapifyDown(0);

        return root;
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << "\n";
    }

private:
    int parent(int i) {
        return (i - 1) / 2;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heapArray[left] < heapArray[minIndex]) {
            minIndex = left;
        }

        if (right < size && heapArray[right] < heapArray[minIndex]) {
            minIndex = right;
        }

        if (i != minIndex) {
            swap(heapArray[i], heapArray[minIndex]);
            heapifyDown(minIndex);
        }
    }
};

