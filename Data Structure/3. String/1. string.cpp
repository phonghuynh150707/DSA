#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

int main(){
    string s; // KHAI BÁO CHUỖI S
    cin >> s; // NHẬP TỚI DẤU SPACE
    cin.ignore(); // XÓA DẤU XUỐNG DÒNG ĐỂ DÙNG GETLINE
    getline(cin,s); // NHẬP HẾT DÒNG
    s.size(); // ĐỘ DÀI CHUỖI
    s.empty(); // KIỂM TRA CHUỖI CÓ RỖNG KHÔNG
    s.clear(); // XÓA HẾT MỌI KÍ TỰ
    s.front(); // KÍ TỰ ĐẦU TIÊN
    s.back(); // KÍ TỰ CUỐI
    s.push_back('x'); // THÊM VÀO CUỐI XÂU KÍ TỰ CHAR
    s.pop_back(); // XÓA PHẦN TỬ CUỐI CÙNG
    s.insert(index, "XXX"); // CHÈN VÀO VỊ TRÍ THỨ INDEX
    s.erase(index, erased_number); // XÓA KÍ TỰ TRONG XÂU (TỪ INDEX, XÓA BAO NHIÊU SỐ)
    s.substr(index, length); // TẠO MẢNG CON TRONG XÂU
    s.replace(index,length,str_sub); // THAY XÂU VÀO XÂU
    if(s.find("XXX") != string::npos){} // KIỂM TRA XEM CÓ TÌM THẤY
    s.rfind("XXX"); // TÌM NGƯỢC CHUỖI LÊN
    // TRẢ VỀ VỊ TRÍ XUẤT HIỆN ĐẦU TIÊN CỦA CHUỖI CON TÌM KIẾM

    // CÁC XÂU NỐI VỚI NHAU QUA TOÁN TỬ +
    string s = a + b;
    // SO SÁNH XÂU THEO THỨ TỰ TỪ ĐIỂN, BẰNG THÌ SO ĐỘ DÀI!
    for(char x : s){} // DUYỆT XÂU
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());

    long long a = stoll(s); // CHUYỂN XÂU QUA SỐ LL 
    int a = stoi(s); // CHUYỂN XÂU QUA SỐ INT
    double a = stod(s); // CHUYỂN XÂU QUA SỐ DOUBLE
    string t = to_string(a); // CHUYỂN SỐ QUA XÂU

    // HÀM THÔNG DỤNG TRONG THƯ VIỆN <CCTYPE>
    isdigit(char c); // KIỂM TRA KÍ TỰ CÓ PHẢI LÀ SỐ
    isalpha(char c); // KIỂM TRA KÍ TỰ CÓ PHẢI LÀ CHỮ
    isalnum(char c); // KIỂM TRA KÍ TỰ CÓ PHẢI CHỮ HOẶC SỐ

    // CHUYỂN THƯỜNG SANG HOA, HOA SANG THƯỜNG
    for(char &c : s){ c = toupper(c)}; // CHUYỂN SANG HOA HẾT
    for(char &c : s){ c = tolower(c)}; // CHUYỂN SANG THƯỜNG HẾT

    // STRINGSTREAM: XỬ LÝ TỪNG TỪ TRONG XÂU
    stringstream ss(s); // TẠO LUỒNG
    string word; // TỪ ĐỂ ĐỌC
    while(ss >> word){ // ĐỌC TỪNG TỪ
        // XỬ LÝ TỪNG WORD
    }

}