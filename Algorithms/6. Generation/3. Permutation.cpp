#include <iostream>
#include <algorithm>
using namespace std;

// SINH XÂU HOÁN VỊ:
// Ý TƯỞNG: 
// - CẤU HÌNH ĐẦU: [1,2,3,..,N]
// - CẤU HÌNH CUỐI: [N,...,3,2,1]
// - THUẬT TOÁN: MỖI SỐ PHẢI TẠO RA ĐƯỢC HOÁN VỊ TIẾP THEO LỚN HƠN TỐI THIỂU
// - ĐI TỪ PHẢI SANG: TÌM SỐ LÀM MẤT TÍNH GIẢM DẦN (TỪ TRÁI QUA) ĐẦU TIÊN
// - ĐI TỪ PHẢI SANG: TÌM PHẦN TỬ ĐẦU TIÊN > SỐ TÌM ĐƯỢC TRÊN, SWAP
// - LẬT NGƯỢC MẢNG TỪ I+1 TỚI N

int n; // HOÁN VỊ TỪ 1 -> N
int X[1005]; // MẢNG LƯU PHẦN TỬ HOÁN VỊ
bool final = false; // ĐÁNH DẤU CẤU HÌNH CUỐI CÙNG

void init(){ // KHỞI TẠO CẤU HÌNH ĐẦU TIÊN
    for(int i = 1; i <= n; i++){
        X[i] = i; // [1,2,3,...,N]
    }
}

void sinh(){
    int i = n-1; // INDEX ÁP CUỐI: ĐỂ BẮT ĐẦU SO SÁNH VỚI SỐ CUỐI
    while( i >= 1 && X[i] > X[i+1]) i--; // TÌM SỐ ĐẦU TIÊN PHÁ VỠ TÍNH GIẢM DẦN (TRÁI SANG)
    if( i == 0) final = true; // ĐÁNH DẤU CẤU HÌNH CUỐI CÙNG
    else{
        int j = n; // INDEX CUỐI CÙNG
        while(X[i] < X[j]) j--; // TÌM PHẦN TỬ ĐẦU TIÊN > SỐ ĐÓ
        swap(X[i],X[j]); // ĐỔI GIÁ TRỊ 2 PHẦN TỬ ĐÓ
        reverse(X+i+1, X+n+1); // LẬT TỪ (I+1,N)
    }
}

void sinh2(){ // SINH HOÁN VỊ BẰNG HÀM NEXT_PERMUTATION
    do{
        for(int i = 1; i <= n; i++){
            cout << X[i] << " ";
        }
        cout << endl;
    }
    while(next_permutation(X+1,X+n+1));
}

int main(){
    cin >> n; 
    init();
    while(!final){
        for(int i = 1; i <= n; i++) cout << X[i] << " "; // IN RA CẤU HÌNH HIỆN TẠI
        cout << endl; // XUỐNG DÒNG MỖI CẤU HÌNH
        sinh(); // TIẾP TỤC SINH
    }
}