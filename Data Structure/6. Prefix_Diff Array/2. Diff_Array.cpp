#include <iostream>
using namespace std;

int main(){
    // MẢNG HIỆU 1 CHIỀU: LƯU HIỆU PHẦN TỬ SAU VÀ PHẦN TỬ TRƯỚC
    // SAU KHI CẬP NHẬT ĐOẠN L,R THÌ DÙNG PREFIX_SUM TÍNH LẠI RA KẾT QUẢ
    int n; cin >> n; int a[100]; diff[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    diff[0] = a[0];
    for(int i = 1; i < n; i++){
        diff[i] = a[i] - a[i-1]; // XÂY DỰNG MẢNG HIỆU DIFF
    }
    int tc; int >> tc; 
    while(tc--){
        int left, right, k; cin >> left >> right >> k; // THỰC HIỆN UPDATE
        diff[left] += k; // MẢNG BAN ĐẦU [L,N-1] += K
        diff[right+1] -= k; // MẢNG BAN ĐẦU [RIGHT+1, N-1] -= K
    }
    int prefix[1000];
    prefix[0] = diff[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + diff[i]; // TÍNH LẠI MẢNG ĐÃ CẬP NHẬT BẰNG PREFIX_SUM
    }
    
}