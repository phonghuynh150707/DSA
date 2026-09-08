// TÍNH GIÁ TRỊ TỚI KHI NHẬP VÀO SỐ 0 THÌ DỪNG
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int main(){
    double x; cin >> x;
    double sum = 0, cnt = 0;
    while(x != 0){
        sum += x;
        cnt++;
        cin >> x;
    }

    double Average;
    if(cnt == 0){
        cout << 0 << endl;
    }
    else{
        Average = sum/cnt;
        cout << Average << endl;
    } 
}