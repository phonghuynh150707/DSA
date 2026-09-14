#include <iostream>
using namespace std;

int main(){
    int n; cin >> n; int a[1000];
    int x; cin >> x; // SỐ CẦN TÌM KIẾM
    for(int i = 0; i < n; i++) cin >> a[i];
    // LINEAR SEARCH: DUYỆT QUA TỪNG PHẦN TỬ TRONG MẢNG TỪ ĐẦU TỚI CUỐI RỒI SO SÁNH
    // ĐỘ PHỨC TẠP: O(N)
    for(int i = 0; i < n; i++){ 
        if(a[i] == x){
            cout << "YES" << endl;
            return 0;
        }
    } 
    cout << "NO" << endl;
}