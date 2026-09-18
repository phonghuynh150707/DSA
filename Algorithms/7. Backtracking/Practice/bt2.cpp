#include <iostream>
#include <string>
using namespace std;

// CHO MẢNG NHỊ PHÂN NxM, ĐI ĐƯỢC NẾU 1, KHÔNG ĐI ĐƯỢC NẾU 0
// CÓ THỂ ĐI XUỐNG (D), PHẢI (R), TRÁI (L), LÊN UP, MỖI Ô ĐI 1 LẦN
// IN RA CÁC ĐƯỜNG ĐI KHẢ DĨ

int n,m;
int X[1005][1005]; // MẢNG NHỊ PHÂN
int temp[1005][1005]; // ĐÁNH DẤU Ô ĐÃ ĐI QUA
string res = ""; // XÂU LƯU ĐƯỜNG ĐI

int dx[4] = {0,-1,0,1}; // TRÁI TRÊN PHẢI DƯỚI
int dy[4] = {-1,0,1,0};
string dir = "LURD";

void backtrack(int i, int j){
    if(i == n && j == m){
        cout << res << endl;
        return;
    }
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k], j1 = j + dy[k]; // DI CHUYỂN SANG 4 Ô
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && temp[i1][j1] == 0 && X[i1][j1] == 1){ // ĐỦ ĐK DỂ NHẢY
            res += dir[k]; // CẬP NHẬT BƯỚC DI CHUYỂN
            temp[i1][j1] = 1; // BỊT Ô ĐÃ DI CHUYỂN
            backtrack(i1,j1); // Ô HỢP LỆ THÌ NHẢY VÀO XÉT TIẾP
            temp[i1][j1] = 0; // NHẢ LẠI Ô ĐÓ KHI QUAY LUI
            res.pop_back(); // NHẢ LẠI ĐƯỜNG ĐI
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= m; j++){
            cin >> X[i][j];
        }
    }
    if(X[1][1] == 1){
        temp[1][1] = 1;
        backtrack(1,1);
    }
    else cout << "NO WAYS!";
}