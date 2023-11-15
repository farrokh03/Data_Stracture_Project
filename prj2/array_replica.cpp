#include <iostream>
using namespace std;

class ArrayReplica
{
private:
    int array[100];
    int cruiser = 0;

public:
    // Method append adds a new value to end of the array
    void append(int value)
    {
        this->array[this->cruiser] = value;
        cruiser++;
    }

    // Method insert adds a value exactly in the given index
    void insert(int value, int index)
    {
        for (int i = cruiser; i >= index; i--)
        {
            this->array[i + 1] = array[i];
        }
        this->array[index] = value;
        this->cruiser++;
    }

    // simply shows the array content
    void display()
    {
        sort(this->array);
        for (int i = 0; i < cruiser; i++)
        {
            cout << array[i] << endl;
        }
    }

    // bubble sort method
    int sort(int array[])
    {
        for (int i = 0; i < cruiser - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < cruiser - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j];
                    this->array[j] = array[j + 1];
                    this->array[j + 1] = temp;
                    swapped = true;
                }
            }
            if (swapped == false)
            {
                break;
            }
        }
        return 0;
    }
};
