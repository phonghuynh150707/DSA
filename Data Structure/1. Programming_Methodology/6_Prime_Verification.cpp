// KIỂM TRA SỐ NGUYÊN TỐ
#include <iostream>
using namespace std;

bool Prime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    if( n <= 0){
        cout << "Wrong Input" << endl;
        return 0;
    }
    else{
        if(Prime(n)){
            cout << "Prime Number" << endl;
        }
        else cout << "Not a Prime Number" << endl;
    }
}