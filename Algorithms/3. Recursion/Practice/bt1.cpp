#include <iostream>
using namespace std;

// IN CÁC SỐ TỪ 0 ĐẾN N
void PrintN(int n){ // GS GỌI F(2)
    if(n == 0){ // BASE CASE
        cout << n << " ";
        return;
    }
    PrintN(n-1); // ĐỆ QUY
    cout << n << " ";
    // STACK: F(2) F(1) F(0), IN 0, POP F(0), CHẠY TIẾP F(1), IN 1
    // POP F(1), CHẠY TIẾP F(2), IN 2 -> STACK RỖNG: XONG!
}

// IN SỐ GIẢM 5 ĐƠN VỊ XUỐNG, VỀ < 0 THÌ QUAY NGƯỢC LẠI
void Down5(int n){ // GIẢ SỬ F(10)
    if(n <= 0){
        cout << n << " "; // BASE CASE
        return;
    } 
    cout << n << " "; // IN TRƯỚC ĐỆ QUY: GỌI VÀO SẼ IN
    Down5(n-5); // ĐỆ QUY
    cout << n << " "; // QUAY LUI SẼ IN
    // STACK: F(10) IN 10, F(5) IN 5, F(0) IN 0
    // POP F(0), CHẠY TIẾP F(5) IN 5
    // POP F(5), CHẠY TIẾP F(10) IN 10 -> STACK RỖNG: XONG
}

// TÌM PHẦN TỬ LỚN NHẤT TRONG MẢNG
int FindMax(int a[], int len){ // GS 1 3 2
    if(len == 0) return a[len]; // BASE CASE
    return max(a[len-1],FindMax(a,len-1)); // ĐỆ QUY
    // Ý TƯỞNG: DÒ QUA MẢNG: LIÊN TIẾP TỪNG CẶP CẬP NHẬT MAX
    // STACK: F(3) = MAX(A[2],F(2)), F(2) = MAX(A[1],F(1)), F(1) = MAX(A[0],F(0)), F(0) = A[0]
    // POP F(0), F(1) = A[0], POP F(1), F(2) = MAX(A[1],A[0]), POP F(2), F(3) = MAX(A[2],MAX(A[1],A[0]))
    // POP F(3) (GIÁ TRỊ TRẢ VỀ) THÌ STACK RỖNG: XONG
}

// KIỂM TRA MẢNG ĐỐI XỨNG
bool Palindrome(int a[], int left, int right){ // GIẢ SỬ LÀ A[5] = {1,1,0,1,1}
    if(left >= right) return true; // BASE CASE
    if(a[left] == a[right]){ // KIỂM TRA 2 ĐẦU
        return Palindrome(a,left+1,right-1); // THỎA THÌ KT TIẾP
    }
    else return false; // 1 TH KHÔNG THỎA THÌ RETURN FALSE
    // STACK: P(A,0,4), P(A,1,3), P(A,2,2): TRUE
    // POP P(A,2,2), P(A,1,3) = TRUE, POP P(A,1,3), P(A,0,4) = TRUE (GT TRẢ VỀ)
    // POP P(A,0,4) THÌ STACK RỖNG: XONG
}

int FindGCD(int a, int b){ // GIẢ SỬ F(8,3)
    if(b == 0) return a; // BASE CASE
    return FindGCD(b,a%b); // ĐỆ QUY
    // STACK: F(8,3), F(3,2), F(2,1), F(1,0): A -> QUAY LUI GIÁ TRỊ LÊN 1
}

// CHO SỐ DƯƠNG: CHẴN/2, LẺ: 3*X+1
void HailStone(int n){ // IN RA QUY TRÌNH: GS: F(5)
    if(n == 1){ // BASE CASE: VÌ NÓ SẼ LUÔN TRỞ LẠI 1 SAU VÀI LẦN LẶP
        cout << n << " ";
        return;
    } 
    if(n%2 == 0){
        cout << n << " "; // IN TRƯỚC, QUAY LUI SẼ KHÔNG IN
        HailStone(n/2); // ĐỆ QUY KHI N CHẴN
    }
    else{
        cout << n << " "; // IN TRƯỚC, QUAY LUI SẼ KHÔNG IN
        HailStone(3*n+1); // ĐỆ QUY KHI N LẺ
    }
    // STACK: F(5), IN 5, F(16), IN 16, F(8), IN 8, F(4), IN 4, F(2), IN 2, F(1), IN 1 -> POP NGƯỢC: KHÔNG CÓ GÌ CHẠY Ở SAU
    // POP HẾT THÌ STACK RỖNG: XONG
}

// CHUYỂN SỐ TRONG CHUỖI CHAR THÀNH SỐ INT
int ArraytoInt(char* str, int len){ // GIẢ SỬ "101"
    // Ý TƯỞNG: CÀNG VỀ TRÁI THÌ PHẢI NHÂN 10 RỒI CỘNG VỚI SỐ TRƯỚC ĐÓ
    if(len == 0) return 0; // BASE CASE
    return ArraytoInt(str,len-1)*10 + (str[len-1]-'0'); // TRUY HỒI: ĐỆ QUY
    // STACK: F(101,3), F(101,2), F(101,1), F(101,0): TRẢ VỀ 0
    // POP F(101,0), F(101,1) = 0*10 + 1 = 1
    // POP F(101,1), F(101,2) = 1*10 + 0 = 10
    // POP F(101,2), F(101,3) = 10*10 + 1 = 101 (GIÁ TRỊ TRẢ VỀ)
    // POP HẾT THÌ STACK RỖNG: XONG
}

// TÍNH ĐỘ DÀI CHUỖI CHAR
int strlen(char* str){ 
    if(*str == '\0') return 0; // ĐI TỚI CUỐI THÌ TRẢ VỀ 0 (KHÔNG TÍNH VÀO ĐỘ DÀI)
    return 1 + strlen(str+1); // ĐỆ QUY ĐI MỖI BƯỚC
    // STACK: F(abc), F(bc), F(c), F(): TRẢ VỀ 0
    // POP F(), F(c) = 1 + 0 = 1
    // POP F(c), F(bc) = 1 + 1 = 2
    // POP F(bc), F(abc) = 1 + 2 = 3 (GIÁ TRỊ TRẢ VỀ)
    // POP HẾT THÌ STACK RỖNG: XONG
}
int main(){

}