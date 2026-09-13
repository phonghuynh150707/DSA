#include <iostream>
using namespace std;
// KIỂM TRA MẢNG ĐỐI XỨNG
int main(){
    int n; cin >> n; int a[10000];
    for(int i = 0; i < n; i++) cin >> a[i];
    int i = 0, j = n-1; // 2 CON TRỎ ĐẦU CUỐI
    while(i < j){
        if(a[i] != a[j]){
            cout << "Non_Palindrome" << endl;
            return 0;
        }
        else{
            i++; j--;
        }
    }
    cout << "Palindrome" << endl;
}