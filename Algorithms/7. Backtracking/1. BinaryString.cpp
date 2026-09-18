#include <iostream>
using namespace std;

// SINH XÂU NHỊ PHÂN ĐỘ DÀI N

int n; // ĐỘ DÀI XÂU
int X[1005]; // MẢNG CHỨA XÂU 
void backtrack(int i){
    for(int j = 0; j <= 1; j++){ // DUYỆT QUA TẤT CẢ KHẢ NĂNG CỦA MỘT BIT
        X[i] = j; // NHẬN GIÁ TRỊ J VÀO VỊ TRÍ I
        if(i == n){ // NẾU MẢNG ĐÃ ĐỦ ĐỘ DÀI XÂU
            for(int k = 1; k <= n; k++){
                cout << X[k];
            }
            cout << endl; // XUỐNG DÒNG SAU MỖI XÂU
        }
        else backtrack(i+1); // CHƯA ĐỦ ĐỘ DÀI THÌ GỌI TIẾP
    }
}

int main(){
    cin >> n;
    backtrack(1); // GỌI ĐỆ QUY ĐẾN PHẦN TỬ SỐ 1 TRONG MẢNG
}