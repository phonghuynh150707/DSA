#include <iostream>
using namespace std;

// BÀI TOÁN ĐẾM ĐẢO NHỊ PHÂN CHUNG CẠNH
int dx[4] = {0,-1,0,1}; // DI CHUYỂN SANG 4 CẠNH
int dy[4] = {-1,0,1,0};

int a[100][100]; // MẢNG ĐẢO NHỊ PHÂN: KHAI BÁO TRƯỚC ĐỂ LOANG
int m,n; // ĐỂ DÙNG TRONG HÀM
void Flood_Fill(int i, int j){
    if(a[i][j] == 0) return; // BASE CASE
    a[i][j] = 0; // CẬP NHẬT LẠI 0
    for(int k = 0; k < 4; k++){
        int x = i + dx[k], y = j + dy[k];
        if(x >= 1 && x <= m && y >= 1 && y <= n){ // INDEX THỎA MÃN TRONG Ô
            Flood_Fill(x,y);
        }
    }
} // QUAY LUI!

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j]; // NHẬP MẢNG NHỊ PHÂN BAN ĐẦU
        }
    }
    int cnt = 0; // SỐ LƯỢNG ĐẢO
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1){
                ++cnt;
                Flood_Fill(i,j); // THỎA Ô 1 THÌ VÀO LOẠI BỎ HẾT CÙNG CẠNH
            }
        }
    }
    cout << cnt << endl;
}