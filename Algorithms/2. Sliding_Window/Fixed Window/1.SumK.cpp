#include <iostream>
using namespace std;

// TÌM MẢNG CON CÓ TỔNG ĐỘ DÀI K LỚN NHẤT
int main(){
    int n, k; cin >> n >> k; int a[10000];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0; // TỔNG K PHẦN TỬ LIÊN TIẾP
    for(int i = 1; i <= k; i++){
        sum += a[i]; // TỔNG K PHẦN TỬ ĐẦU TIÊN
    }
    int mx = sum; // LƯU TỔNG LỚN NHẤT
    for(int i = k+1; i <= n; i++){
        sum -= a[i-k]; //BỎ ĐI PHẦN TỬ ĐẦU
        sum += a[i]; // THÊM PHẦN TỬ CUỐI
        mx = max(mx,sum);
    }
    cout << mx;
}