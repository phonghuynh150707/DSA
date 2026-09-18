#include <iostream>
using namespace std;

// IN CÁC TẬP CON K PHẦN TỬ TRONG N SỐ BAN ĐẦU
// Ý TƯỞNG:
// - CẤU HÌNH ĐẦU: [1,2,3,...,K]
// - CẤU HÌNH CUỐI: [N-K+1, N-K+2, ..., N]
// TẬP CON ĐƯỢC MẶC ĐỊNH XÁC THEO THỨ TỰ TĂNG DẦN TỪ TRÁI SANG PHẢI
// GIÁ TRỊ TẠI MỘT VỊ TRÍ ĐẠT MAX: N-K+I
// DUYỆT PHẢI SANG: GẶP CHƯA MAX THÌ TĂNG LÊN, RỒI RESET ĐẰNG SAU BẰNG CÁCH CỘNG TĂNG DẦN

int n, k; // CÓ N SỐ VÀ TẬP HỢP K
int X[1005]; // MẢNG CHỨA TỔ HỢP CỦA K
bool final = false; // ĐÁNH DẤU CẤU HÌNH CUỐI

void init(){ // KHỞI TẠO CẤU HÌNH ĐẦU
    for(int i = 1; i <= k; i++){
        X[i] = i; // [1,2,3,...,K]
    }
}

void sinh(){
    int i = k; // VỊ TRÍ CUỐI CÙNG TRONG MẢNG
    while(i >= 1 && X[i] == n-k+i) i--; // NẾU VỊ TRÍ ĐÃ MAX THÌ XÉT SANG TRÁI
    if(i == 0) final = true; // ĐÃ DUYỆT HẾT CẤU HÌNH
    else{
        X[i]++; // CHƯA MAX THÌ TĂNG VỊ TRÍ ĐÓ LÊN 1 ĐƠN VỊ
        for(int j = i + 1; j <= k; j++){ // XÉT PHẦN TỬ BÊN PHẢI
            X[j] = X[j-1] + 1; // TĂNG DẦN 1 ĐƠN VỊ TỚI CUỐI
        }
    }
}

int main(){
    cin >> n >> k;
    init();
    while(!final){
        for(int i = 1; i <= k; i++){ // IN RA CẤU HÌNH HIỆN TẠI
            cout << X[i] << " ";
        }
        cout << endl; // XUỐNG DÒNG SAU MỖI CẤU HÌNH
        sinh(); // TIẾP TỤC SINH
    }
}