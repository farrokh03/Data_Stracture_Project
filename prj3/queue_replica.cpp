#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int cruiser;
    int queue[5];

public:
    Queue()
    {
        this->size = 5;
        this->cruiser = -1;
    }
    void dequeue(){
        if(cruiser != -1 ){
            for( int i = 0; i<=cruiser ; i++){

                queue[i] = queue[i+1];
            }
            cruiser--;
        }else{
            is_empty();
        }
    }

    void enqueue(int value )
    {
        if(cruiser == -1){
            cruiser++;
            queue[cruiser] = value ; 
        }else{
            cruiser++;
            queue[cruiser] = value ;
        }
    }

    bool is_full(){
        if( cruiser == size-1 ){
            return true;
        }else{
            return false;
        }

    }

    int peek()
    {
        int peek = queue[0];
        return peek;
    }

    int reverse_queue()
    {
        int reverse[size];

        for (int i = cruiser; i >= 0; i--)
        {
            cout << queue[i] << endl;
        }
        return 0;
    }

    bool is_empty()
    {
        if (cruiser == -1)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        for (int i = 0; i <= cruiser; i++)
        {
            cout << queue[i] << endl;
        }
    }

    void clear()
    {
        while (is_empty() == false)
        {
            dequeue();
        }
        cout << "cleared";
    }
};
