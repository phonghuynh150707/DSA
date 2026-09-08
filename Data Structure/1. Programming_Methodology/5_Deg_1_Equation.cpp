// GIẢI PHƯƠNG TRÌNH BẬC NHẤT
#include <iostream>
using namespace std;

int main(){
    double a,b; cin >> a >> b;
    if(a == 0){
        if(b == 0){
            cout << "Infinite Solution" << endl;
        }
        else{
            cout << "No Solution" << endl;
        }
    }
    else{
        double res = -b/a;
        cout << "One Solution: " << res << endl;
    }
}