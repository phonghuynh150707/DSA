#include <iostream>
using namespace std;

int main(){
    // ĐỘ PHỨC TẠP GỒM: KHÔNG GIAN VÀ THỜI GIAN
    // KHÔNG GIAN: CÓ THỂ BỔ SUNG BỘ NHỚ ĐƯỢC -> QUAN TÂM NHIỀU VỀ THỜI GIAN: SỐ PHÉP TOÁN THỰC HIỆN
    // TRONG 1S THỰC HIỆN ĐƯỢC 10^8-5.10^8 PHÉP TOÁN --> C++: 1-2S, PYTHON, JAVA: 4S
    // BIG O: O(F(N)): TRƯỜNG HỢP TỆ NHẤT CỦA THUẬT TOÁN: N LÀ ĐẦU VÀO 
    // O(F(N)): LẤY BẬC CAO NHẤT, BỎ HỆ SỐ
    // O(1) -> O(LOG) -> O(N) -> O(NLOGN) -> O(N^2) -> O(2^N) -> O(N!): ĐỘ PHỨC TẠP TĂNG DẦN
    // O(1): GÁN, NHẬP XUẤT, CỘNG TRỪ NHÂN CHIA, KHÔNG CÓ VÒNG LẶP, K PHỤ THUỘC VÀO INPUT
    // O(N): VÒNG LẶP (BÊN TRONG LÀ O(1)), NGƯỢC LẠI LÀ QUY TẮC NHÂN; I+=A TRONG VÒNG LẶP
    // O(N^2): 2 VÒNG LẶP LÒNG NHAU (THƯỜNG) = M*N*(ĐỘ PHƯC TẠP BÊN TRONG CÙNG)
    // O(LOGN): I* = A TRONG VÒNG LẶP, K/=10
    // O(NLOGN): I++, J+=I TRONG 2 VÒNG LẶP LỒNG NHAU
    // HÀM CÓ SẴN: PHẢI NHÂN THÊM VÀO
}