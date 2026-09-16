#include <iostream>
#include <string>
using namespace std;

// CHO CHUỖI s GỒM CHỮ THƯỜNG, CHỮ SỐ, '(' VÀ ')', THỎA CÁC ĐIỀU KIỆN:
// - HAI CHỮ SỐ KHÔNG ĐƯỢC ĐỨNG LIỀN NHAU
// - HAI '(' KHÔNG ĐƯỢC ĐỨNG LIỀN NHAU
// - '(' VÀ ')' KHÔNG ĐƯỢC ĐỨNG LIỀN NHAU
// - SAU MỖI CHỮ SỐ PHẢI CÓ '('
// - SỐ LƯỢNG '(' VÀ ')' BẰNG NHAU
// QUY TẮC BIẾN ĐỔI:
// - CHUỖI DẠNG "n(p)" → "p" LẶP LẠI n LẦN (n LÀ CHỮ SỐ)
// - NẾU p VẪN CÒN SỐ, '(' HOẶC ')' → TIẾP TỤC BIẾN ĐỔI
//
// YÊU CẦU: VIẾT HÀM string expand(string s) TRẢ VỀ CHUỖI CHỈ GỒM CHỮ THƯỜNG
// VÍ DỤ:
// - "2(ab3(cd)ex)" → "abcdcdcdexabcdcdcdex"
// - "2(x0(y)3(z))" → "xxzzz"

string repeatString(string s, int n){ // LẶP MỘT CHUỖI N LẦN
    if(n == 0) return ""; // HẾT LẦN LẶP THÌ DỪNG!
    return s + repeatString(s, n - 1); // S + LẶP SỐ NHỎ DẦN
}
// repeatString("ab", 3)
// = "ab" + repeatString("ab", 2)
// = "ab" + "ab" + repeatString("ab", 1)
// = "ab" + "ab" + "ab" + repeatString("ab", 0)
// = "ababab"

int findClose(string s, int pos, int count){ // TÌM VỊ TRÍ DẤU NGOẶC ĐÓNG
    // POS: VỊ TRÍ HIỆN TẠI, COUNT: SỐ DẤU NGOẶC CHƯA ĐÓNG
    if(count == 0) return pos - 1; // VỊ TRÍ DẤU NGOẶC ĐÓNG HỢP LỆ!
    if(s[pos] == '(') return findClose(s, pos + 1, count + 1); // (: TĂNG INDEX, TĂNG CNT
    if(s[pos] == ')') return findClose(s, pos + 1, count - 1); // ): GIẢM INDEX, TĂNG CNT
    return findClose(s, pos + 1, count); // TÌM INDEX TIẾP THEO
}

string expand(string s){ // GẶP MỘT CHUỖI VÀ BIẾN ĐỔI BIỂU THỨC DẠNG N(P)
    size_t pos = s.find_first_of("0123456789"); // INDEX CHỮ SỐ ĐẦU XH
    if(pos == string::npos) return s; // KHÔNG CÓ SỐ NÀO THÌ CHUỖI ĐÃ BIẾN ĐỔI XONG
    int n = s[pos] - '0'; // CHUYỂN SỐ ĐẦU TIÊN (CHAR) VỀ SỐ
    int open = pos + 1; // OPEN: VỊ TRÍ DẤU NGOẶC '(' 
    int close = findClose(s, open + 1, 1); // TÌM DẤU NGOẶC ')': TƯƠNG ỨNG
    string inside = expand(s.substr(open + 1, close - open - 1)); // LẤY PHẦN NẰM GIỮA ()
    // ĐỆ QUY VÀO SÂU BÊN TRONG CÙNG CỦA DẤU () ĐÓ
    string repeated = repeatString(inside, n); // LẶP LẠI CÁI BÊN TRONG (), TỪ TRONG RA NGOÀI
    string newString = s.substr(0, pos) + repeated + s.substr(close + 1); // GHÉP
    return expand(newString); // TIẾP TỤC EXPAND
}

int main(){

}