#include <iostream>
#include <climits>
using namespace std;

// CHO MẢNG KÍCH THƯỚC MxN, CHI PHÍ Ô I,J = X[I][J]
// CẦN ĐI TỪ (1,1)->(N,M) VỚI CHI PHÍ THẤP NHẤT
// IN RA SỐ TIỀN ÍT NHẤT

int n,m;
int X[1005][1005]; // MẢNG NHỊ PHÂN
int temp[1005][1005]; // ĐÁNH DẤU Ô ĐÃ ĐI QUA


int dx[4] = {0,-1,0,1}; // TRÁI TRÊN PHẢI DƯỚI
int dy[4] = {-1,0,1,0};

int fee = 0; int mn = INT_MAX;

void backtrack(int i, int j){
    if(fee >= mn) return; // NHÁNH CẬN: BIẾT ĐƯỜNG TIẾP THEO KHÔNG THỎA THÌ QUAY LUI LUÔN
    if(i == n && j == m){
        mn = min(fee,mn); // CẬP NHẬT LẠI MIN FEE MỖI KHI ĐẾN ĐÍCH
        return;
    }
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k], j1 = j + dy[k]; // DI CHUYỂN SANG 4 Ô
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && temp[i1][j1] == 0){ // ĐỦ ĐK DỂ NHẢY
            fee += X[i1][j1];
            temp[i1][j1] = 1; // BỊT Ô ĐÃ DI CHUYỂN
            backtrack(i1,j1); // Ô HỢP LỆ THÌ NHẢY VÀO XÉT TIẾP
            temp[i1][j1] = 0; // NHẢ LẠI Ô ĐÓ KHI QUAY LUI
            fee -= X[i1][j1]; // NHẢ Ô THÌ TRẢ LẠI GIÁ TRỊ
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
    fee = X[1][1];
    temp[1][1] = 1;
    backtrack(1,1);
    cout << mn;
}