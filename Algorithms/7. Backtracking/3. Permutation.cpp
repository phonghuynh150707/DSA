#include <iostream>
using namespace std;

// SINH CÁC HOÁN VỊ CỦA N SỐ ĐẦU
int n; 
int X[1005]; // MẢNG CHỨA HOÁN VỊ
int temp[1000]; // MẢNG ĐÁNH DẤU PHẦN TỬ CỦA X ĐÃ XUẤT HIỆN
// CÁC KHẢ NĂNG CỦA X[I] = [1,...,N]: NÊN PHẢI BỊT GIÁ TRỊ ĐÃ XH TRƯỚC
void backtrack(int i){
    for(int j = 1; j <= n; j++){
        if(temp[j] == 0){ // J CHƯA ĐƯỢC CHỌN
            X[i] = j;
            temp[j] = 1; // BỊT LẠI GIÁ TRỊ ĐÓ
            if(i == n){ // ĐỦ PHẦN TỬ THÌ IN RA
                for(int k = 1; k <= n; k++) cout << X[k] << " ";
                cout << endl;
            }
            else backtrack(i+1); // XÉT PHẦN TỬ TIẾP THEO
            temp[j] = 0; // QUAY LUI THÌ NHẢ LẠI GIÁ TRỊ ĐÃ BỊT
        }
    }
}

int main(){
    cin >> n;
    backtrack(1);
}   