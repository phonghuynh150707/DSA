#include <iostream>
#include <algorithm>
using namespace std;
// KIỂM TRA TRONG MẢNG CÓ 2 PHẦN TỬ SAO CHO TỔNG = K
int main(){
    int n, k; cin >> n >> k; int a[10000];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n); // SẮP XẾP TĂNG DẦN
    int left = 0, right = n-1; // 2 CON TRỎ ĐẦU CUỐI
    while(left < right){
        if(a[left] + a[right] == k){
            cout << "YES" << endl;
            return 0;
        }
        else if(a[left] + a[right] > k) right--;
        else left++;
    }
    cout << "NO" << endl;
}