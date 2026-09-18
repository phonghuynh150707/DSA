#include <iostream>
#include <string>
using namespace std;

// CHO MẢNG NHỊ PHÂN NxM, TÌM ĐƯỜNG ĐI HỢP LỆ (1) TỪ (1,1) -> (N,M)
// BIẾT CHỈ ĐƯỢC XUỐNG (D) HOẶC SANG PHẢI (R), IN RA CÁC CÁCH ĐI

int dx[2] = {1,0}; // DI CHUYỂN XUỐNG VÀ SANG PHẢI
int dy[2] = {0,1}; 

int n, m; 
int X[1005][1005]; // MẢNG ĐƯỜNG ĐI 
string res = ""; // CHUỖI LƯU KẾT QUẢ
// VÌ CHỈ ĐI XUỐNG HOẶC SANG PHẢI NÊN KHÔNG GỌI ĐỆ QUY LẠI Ô ĐÃ ĐI: K CẦN ĐÁNH DẤU
void backtrack(int i, int j){
    if(i == n && j == m){
        cout << res << endl;
        return;
    }
    for(int k = 0; k <= 1; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && X[i1][j1] == 1){
            if(k == 0) res += "D";
            else res += "R";
            backtrack(i1,j1);
            res.pop_back();
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){ // NHẬP MA TRẬN NHỊ PHÂN
        for(int j = 1; j <= m; j++){
            cin >> X[i][j];
        }
    }
    // Ô BẮT ĐẦU PHẢI LÀ 1
    if(X[1][1] == 1) backtrack(1, 1);
}