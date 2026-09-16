#include <iostream>
using namespace std;

// LƯU Ý: RETURN ĐỆ QUY THÌ PHẦN PHÍA SAU KHÔNG CÓ QUAY LUI

void A(int k){ // GIẢ SỬ GỌI A(3)
    if(k > 0){ // BASE CASE
        A(k-1); // GỌI ĐỆ QUY
        cout << k << " ";
    }
    cout << "? ";
    // STACK: A(3) A(2) A(1) A(0) -> ? -> POP A(0), A(1) CHẠY TIẾP: IN 1 ?, POP A(1)
    // CHẠY A(2), IN 2 ?, POP A(2), CHẠY A(3), IN 3 ?, POP A(3) -> STACK RỖNG: XONG
}

void B(int n){ // GS GỌI B(123)
    if(n!=0){ // BASE CASE
        cout << n << " ";
        B(n/10);
        cout << n%10 << " ";
    }
    cout << "? ";
    // STACK: B(123), IN 123, B(12), IN 12, B(1), IN 1, B(0), IN ?
    // POP B(0), B(1) CHẠY TIẾP, IN 1 ?; POP B(1), B(12) CHẠY TIẾP, IN 2 ?
    // POP B(12), B(123) CHẠY TIẾP, IN 3 ? -> STACK RỖNG: XONG
}

int F(int n){ // GIÁ SỬ GỌI F(2)
    if(n == 0) return 1; // BASE CASE
    return n*F(n-1); // GỌI ĐỆ QUY
    // STACK: F(2) (2*F(1)), GỌI F(1) (2*F(0)), GỌI F(0), F(0) = 1
    // POP F(0), CHẠY F(1) = 2*1 = 2, POP F(1), CHẠY F(2) = 2*2 = 4
    // POP F(2) -> STACK RỖNG: XONG 
}

int Fibo(int n){
    if(n == 0 || n == 1) return n; // BASE CASE
    return Fibo(n-1) + Fibo(n-2); // TRUY HỒI: ĐỆ QUY
    // BIỂU DIỄN BẰNG CÂY ĐỆ QUY ĐI SAU RỒI NHÁNH RỒI QUAY LUI: DẦN QUA PHẢI
}

int main(){
    // CTDL NGĂN XẾP (STACK): THÔNG TIN GỌI HÀM ĐƯỢC ĐÓNG VÀO NGĂN XẾP
    // ĐỢI HÀM BÊN TRÊN CHẠY XONG THÌ CHẠY TIẾP 
    // CÓ THỂ BIỂU DIỄN QUÁ TRÌNH BẰNG STACK HOẶC CÂY ĐỆ QUY (ĐI SAU 1 NHÁNH RỒI QUAY LUI)
    // QUAY LUI: THỰC CHẤT LÀ CƠ CHẾ POP CỦA STACK
}