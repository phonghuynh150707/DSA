#include <iostream>
using namespace std;

int main(){
    // MẢNG CỘNG DẦN 1 CHIỀU: Prefix[i] = TỔNG SỐ PHẦN TỬ TỪ A[0] TỚI A[I]
    int n; cin >> n; int a[100]; int prefix[100];
    for(int i = 0; i < n; i++) cin >> a[i];
    prefix[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    // CÁC TRUY VẤN TỔNG TRÊN CÁC ĐOẠN
    int testcase; cin >> testcase;
    while(testcase--){
        int left, right; cin >> left >> right;
        if(left == 0) cout << prefix[right] << endl; // TỔNG ĐOẠN TỪ VỊ TRÍ 0 TỚI RIGHT
        else cout << prefix[right] - prefix[left-1]; // TỔNG ĐOẠN TỪ LEFT TỚI RIGHT
    }

    // CỘNG DỒN MẢNG 2 CHIỀU: Prefix[i][j]: TỔNG PHẦN TỬ GIỚI HẠN HÀNG I CỘT J
    int a[1005][1005]; int prefix[1005][1005];
    int row, col; cin >> row >> col;
    for(int i = 1; i <=  row; i++){
        for(int j = 1; j <= col; j++){
            cin >> a[i][j]; // NHẬP GIÁ TRỊ VÀO MẢNG 2 CHIỀU
        }
    }
    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
        } // XÂY DỰNG MẢNG CỘNG DỒN TRÊN MẢNG 2D
    }
    int tc; cin >> tc;
    while(tc--){
        int h1, h2, c1, c2; cin >> h1 >> h2 >> c1 >> c2; // TỔNG GH BỞI HCN 
        cout << prefix[h2][c2] - prefix[h1-1][c2] - prefix[h2][c1-1] + prefix[h1-1][c1-1] << endl;
    }
}