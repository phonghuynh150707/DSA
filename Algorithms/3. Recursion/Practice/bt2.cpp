#include <iostream>
using namespace std;

// TRẢ VỀ CHUỖI ĐẢO NGƯỢC: A B C -> C B A
string reverse(string s){
    size_t pos = s.find(' ');
    if(pos == string::npos) return s; // KHÔNG CÒN SPACE THÌ RETURN TỪ ĐÓ
    return reverse(s.substr(pos + 1)) + " " + s.substr(0, pos); // ĐỆ QUY ĐẢO NGƯỢC LẠI
    // STACK: F(A B C), F(B C), F(C): TRẢ VỀ "C"
    // POP F(C), F(B C) = "C" + " " + "B" = "C B"
    // POP F(B C), F(A B C) = "C B" + " " + "A" = "C B A" (GIÁ TRỊ TRẢ VỀ)
    // POP HẾT THÌ STACK RỖNG: XONG
}

int main(){

}