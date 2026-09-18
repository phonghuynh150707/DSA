#include <iostream>
using namespace std;

int main(){
    // BACKTRACKING (QUAY LUI): THUẬT TOÁN VÉT CẠN (BRUTEFORCE) DÙNG LIỆT KÊ CẤU HÌNH CỦA VẬT
    // NGUYÊN LÝ: DỰA TRÊN CƠ CHẾ POP CỦA STACK ĐỂ QUAY LẠI CẤU HÌNH TRƯỚC TÌM KIẾM
    // THAY VÌ CHỌN XONG MỘT NGHIỆM MỖI LẦN SINH: TA XÂY TỪNG VỊ TRÍ 
    // GS XÁC ĐỊNH ĐƯỢC I-1 THÀNH PHẦN: X[1],...,X[I-1], TA LẦN LƯỢT THỬ CÁC KHẢ NĂNG CỦA X[I]:
    // - NẾU X[I] CÓ THỂ NHẬN GIÁ TRỊ ĐÓ: I == N: ĐỦ 1 NGHIỆM THÌ IN RA HOẶC I < N THÌ TIẾP TỤC THỬ X[I+1]
    // - NẾU X[I] KHÔNG NHẬN GIÁ TRỊ ĐÓ THÌ QUAY LUI LẠI CẤU HÌNH TRƯỚC ĐỂ CHỌN LẠI GIÁ TRỊ PHÙ HỢP

    // NHÁNH CẬN (BRANCH AND BOUND): QUAY LUI LẠI KHI BIẾT HƯỚNG ĐI TIẾP KHÔNG TỐT ĐỂ TRÁNH MẤT THỜI GIAN

    // MÃ GIẢ (PSEUDOCODE)
    // TRY(INT I){
        // FOR(INT J = KHẢ NĂNG 1; J <= KHẢ NĂNG N; J++){
        // IF(X[I] CHẤP NHẬN KHẢ NĂNG J) X[I] = J
        // IF(I == N) IN RA KQ
        // ELSE TRY(I+1)
        // }
    // }
}