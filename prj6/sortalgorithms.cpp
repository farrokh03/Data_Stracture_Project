#include <iostream>

using namespace std;
class SortingAlgorithms {
public:

    static void bubbleSort(int* arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static void selectionSort(int* arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    static void insertionSort(int* arr, int size) {
        for (int i = 1; i < size; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    static void mergeSort(int* arr, int size) {
        mergeSortHelper(arr, 0, size - 1);
    }

    
    static void quickSort(int* arr, int size) {
        quickSortHelper(arr, 0, size - 1);
    }

    static void bucketSort(int* arr, int size, int bucketSize) {
        int minValue = findMin(arr, size);
        int maxValue = findMax(arr, size);

        int bucketCount = (maxValue - minValue) / bucketSize + 1;
        int** buckets = new int*[bucketCount];
        for (int i = 0; i < bucketCount; ++i) {
            buckets[i] = new int[size];
        }

        for (int i = 0; i < size; ++i) {
            int bucketIndex = (arr[i] - minValue) / bucketSize;
            buckets[bucketIndex][i] = arr[i];
        }

        int index = 0;
        for (int i = 0; i < bucketCount; ++i) {
            insertionSort(buckets[i], size);
            for (int j = 0; j < size; ++j) {
                arr[index++] = buckets[i][j];
            }
        }

        for (int i = 0; i < bucketCount; ++i) {
            delete[] buckets[i];
        }
        delete[] buckets;
    }

    static void countingSort(int* arr, int size) {
        int maxValue = findMax(arr, size);
        int* count = new int[maxValue + 1]();

        for (int i = 0; i < size; ++i) {
            count[arr[i]]++;
        }

        int index = 0;
        for (int i = 0; i <= maxValue; ++i) {
            while (count[i] > 0) {
                arr[index++] = i;
                count[i]--;
            }
        }

        delete[] count;
    }

private:
    
    static void mergeSortHelper(int* arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSortHelper(arr, low, mid);
            mergeSortHelper(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    static void merge(int* arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        int* left = new int[n1];
        int* right = new int[n2];

        for (int i = 0; i < n1; ++i) {
            left[i] = arr[low + i];
        }
        for (int j = 0; j < n2; ++j) {
            right[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < n1) {
            arr[k++] = left[i++];
        }

        while (j < n2) {
            arr[k++] = right[j++];
        }

        delete[] left;
        delete[] right;
    }

    static void quickSortHelper(int* arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSortHelper(arr, low, pivotIndex - 1);
            quickSortHelper(arr, pivotIndex + 1, high);
        }
    }

    static int partition(int* arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    static int findMin(int* arr, int size) {
        int minValue = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < minValue) {
                minValue = arr[i];
            }
        }
        return minValue;
    }
    static int findMax(int* arr, int size) {
        int maxValue = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
        return maxValue;
    }
    static void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
