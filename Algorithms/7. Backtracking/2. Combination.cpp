#include <iostream>
using namespace std;

// SINH CÁC TẬP HỢP K PHẦN TỬ TRONG N SỐ ĐẦU TIÊN

int n,k; // SỐ N VÀ K PHẦN TỬ TRONG TẬP HỢP
int X[1005]; // MẢNG CHỨA K PHẦN TỬ
// X[0] = 0
void backtrack(int i){
    for(int j = X[i-1]+1; j <= n-k+i; j++){ // GIÁ TRỊ VỊ TRÍ I CÓ THỂ NHẬN ĐƯỢC
        X[i] = j;                         // MIN: SỐ TRƯỚC NÓ +1, MAX: N-K+I
        if(i == k){ // ĐỦ SỐ LƯỢNG THÌ IN RA
            for(int i = 1; i <= k; i++) cout << X[i] << " ";
            cout << endl; // XUỐNG DÒNG MỖI TỔ HỢP
        }
        else backtrack(i+1); // CHƯA ĐỦ THÌ XÉT PHẦN TỬ KẾ TIẾP
    }
}
int main(){
    cin >> n >> k;
    backtrack(1);
}