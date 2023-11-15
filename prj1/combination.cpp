#include <iostream>
using namespace std;

int combination(int n  , int k ){

    if( n==k || k == 0 ){

        return 1;
    }else{

        return combination(n-1 , k-1 ) + combination( n-1 , k  );
    }


}
int main (){

    return 0;
}