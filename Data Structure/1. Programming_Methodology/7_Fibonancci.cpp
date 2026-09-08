// In RA SỐ FIBONANCCI THỨ N
#include <iostream>
using namespace std;
int main(){
    int n; cin >> n; int a[1000];
    if(n <= 0){
        cout << "Wrong input" << endl;
        return 0;
    }
    a[1] = 0;
    a[2] = 1;
    for(int i = 3; i <= n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    cout << "Fibonancci Nth is: " << a[n] << endl;
}