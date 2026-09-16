#include <iostream>
using namespace std;

// CHO CHUỖI s CHỈ GỒM '(' VÀ ')'
// TRẢ VỀ SỐ LƯỢNG DẤU NGOẶC TỐI THIỂU CẦN CHÈN VÀO s ĐỂ CHUỖI CÂN BẰNG
// CHUỖI CÂN BẰNG: KHÔNG CÓ DẤU NGOẶC NÀO BỊ THỪA/THIẾU
// VÍ DỤ: "(()())" CÂN BẰNG, ")))(" KHÔNG CÂN BẰNG

int solve(string& s, size_t& index, int& balance){ // TRUYỀN BẢN GỐC ĐỂ CHẠY NHANH HƠN
    // INDEX: KÍ TỰ ĐANG XÉT TRONG CHUỖI, SỐ NGOẶC '(' HIỆN CHƯA CÓ ')' TƯƠNG ỨNG
    if(index == s.length()) return balance; // DUYỆT HẾT CHUỖI THÌ TRẢ VỀ KQ
    if(s[index] == '(') balance++; // '(' THÌ BALANCE++
    else if(balance > 0) balance--; // GẶP ) NHƯNG ĐANG CÓ ( CHƯA GHÉP)
    else return 1 + solve(s, ++index, balance); // GẶP ) NHƯNG KHÔNG CÓ ( ĐỂ GHÉP
    // CỘNG 1 RỒI DỊCH SANG PHẢI 1 INDEX ĐỂ ĐẾM TIÉP
    return solve(s, ++index, balance); // XỬ LÝ KÍ TỰ XONG, THÌ SANG KÍ TỰ TIẾP THEO
}

int minimumBracketAdd(string s){ // HÀM NÀY KHÔNG CÓ INDEX VỚI BALANCE
    size_t index = 0; int balance = 0; // XÉT TỪ INDEX ĐẦU TIÊN, CHƯA CÓ NGOẶC NÀO!
    return solve(s,index,balance);
}

int main(){

}