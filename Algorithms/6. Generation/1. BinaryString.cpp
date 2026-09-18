#include <iostream>
using namespace std;

// LIỆT KÊ XÂU NHỊ PHÂN CÓ ĐỘ DÀI N
// Ý TƯỞNG: THỰC HIỆN CỘNG TAY 1 BIT: DUYỆT PHẢI SANG TRÁI: 1 -> 0, 0 -> 1 RỒI GIỮ NGUYÊN PHẦN CÒN LẠI

int n; // ĐỘ DÀI XÂU
int X[1005]; // MẢNG CHỨA CÁC CẤU HÌNH XÂU NHỊ PHÂN
bool final = false; // ĐÁNH DÂU CẤU HÌNH CUỐI CÙNG

void init(){
    for(int i = 1; i <= n; i++){
        X[i] = 0; // CẤU HÌNH ĐẦU TIÊN LÀ N SỐ 0
    }
}

void sinh(){
    int index = n; // XÉT TỪ PHẢI QUA TRÁI
    while(index >= 1 && X[index] == 1){ // TÌM SỐ 0 ĐỂ CỘNG LÊN 1, GẶP 1 THÌ CỘNG LÊN 0 NHỚ 1
        X[index] = 0; // = 1 THÌ GÁN CHO BẰNG 0
        index--; // DỊCH SANG TRÁI ĐỂ TÌM SỐ 0
    }
    if(index == 0) final = true; // ĐÃ ĐI HẾT CẤU HÌNH
    else X[index] = 1; // GẶP SỐ 0 THÌ GÁN CHO 1
}
int main(){
    cin >> n; // NHẬP ĐỘ DÀI XÂU
    init(); // TẠO CẤU HÌNH ĐẦU TIÊN
    while(!final){
        // IN CẤU HÌNH HIỆN TẠI
        for(int i = 1; i <= n; i++){
            cout << X[i];
        }
        cout << endl; // XUỐNG DÒNG SAU MỖI CẤU HÌNH
        sinh(); // TIẾP TỤC SINH
    }
    return 0;
}