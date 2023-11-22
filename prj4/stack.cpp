#include <iostream>
using namespace std;


class StackReplica{
    private:
        int capacity = 100 ;
        int top = -1;
        int stack_replica[100];

    public:
       

        void push(int value){
            if(top == capacity - 1) {
                is_full();
            } else {
                top++;
                this->stack_replica[top] = value;
            }
        }


        int pop(){
            if(is_empty()){
                cout << "stack is empty";
            } else {
                int to_pop = this->stack_replica[top];
                top--;
                return to_pop;
            }
            return 0;
        }

        int top_pointer(){
             return stack_replica[top];
         }

        int size(){
            return capacity;
        }

        bool is_empty(){
            if(top == -1){
                return true;
            } else {
                return false;
            }
        }
        void display(){
            for(int i = 0 ; i <= top ; i++ ){
                cout<<stack_replica[i]<<endl;
            }
        }

        bool is_full(){
            if(top == capacity - 1){
                return true;
            } else {
                return false;
            }
        }




};


int main(){
    
    return 0;
}