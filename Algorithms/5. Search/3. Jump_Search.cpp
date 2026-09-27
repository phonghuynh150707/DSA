#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// LÝ THUYẾT JUMP_SEARCH:
// THUẬT TOÁN TÌM KIẾM TRÊN MẢNG ĐÃ SẮP XẾP (SORTED ARR)
// NHẢY TỪNG ĐOẠN CÓ KÍCH THƯỚC CỐ ĐỊNH, XÁC ĐỊNH PHẦN TỬ CẦN TÌM Ở ĐOẠN NÀO RỒI LINEAR SEARCH
// KÍCH THƯỚC BƯỚC NHẢY: THƯỜNG LÀ SQRT(N)
// ĐỘ PHỨC TẠP THỜI GIAN: O(SQRT(N))
// ĐỘ PHỨC TẠP KHÔNG GIAN: O(1): DO KHÔNG DÙNG CẤU TRÚC DỮ LIỆU PHỤ
// EDGE CASE: TARGET < PHẦN TỬ ĐẦU || TARGET > PHẦN TỬ CUỐI: KHÔNG TỒN TẠI

// MÔ PHÒNG CHẠY TAY:
// A = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31]
// MẢNG ĐÃ SORTED VÀ CÓ 16 PT: BƯỚC NHẢY: 4, TARGET = 19
// [0,1,2,3];[4,5,6,7];[8,9,10,11];[12,13,14,15]: INDEX CHIA RA
// [1,3,5,7];[9,11,13,15];[17,19,21,23];[25,27,29,31]
// NHÌN CUỐI MỖI BLOCK: 7 -> 15 -> 23 -> 31
// JUMP 1: 7 < 19, QUA BLOCK TIẾP THEO
// JUMP 2: 15 < 19, QUA BLOCK TIẾP THEO
// JUMP 3: 23 > 19: TARGET PHẢI NẰM Ở BLOCK NÀY
// LINEAR_SEARCH VÀO BLOCK 3: XÉT TỪNG PT: 17 -> 19 (THỎA) -> 21 -> 23


#include <iostream>
#include <cmath>       // Dùng sqrt() để tính √n
#include <algorithm>   // Dùng min()
using namespace std;


int jumpSearch(int a[], int n, int target) {
    int step = sqrt(n);
    int prev = 0; // prev = vị trí bắt đầu của block hiện tại
    while (prev < n && a[min(step, n) - 1] < target) {
        prev = step; // Đưa prev tới đầu block tiếp theo
        step += sqrt(n); // NHẢY QUA BLOCK KẾ
        if(prev >= n) return -1; // ĐÃ VƯỢT NGOÀI MẢNG THÌ KHÔNG TÌM THẤY
    }
    while(prev < min(step, n) && a[prev] < target){
        prev++; // DỊCH CON TRỎ TỚI KHI BẰNG HOẶC LỚN HƠN TARGET THÌ DỪNG LẠI
    }

    if (prev < min(step, n) && a[prev] == target)  return prev; // NẾU = THÌ TRẢ VỀ INDEX
    return -1; // KHÔNG TÌM THẤY
}
int main(){

}