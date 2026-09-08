#include <iostream>
#include <stack>

int main(){
    // NGĂN XẾP STACK: CHỒNG SÁCH, HĐ THEO LIFO (LAST IN FIRST OUT)
    stack<int> st; // KHAI BÁO STACK RỖNG
    st.push(x); // THÊM PHẦN TỬ X VÀO STACK
    st.pop(); // XÓA Ở ĐỈNH STACK
    st.top(); // XEM PHẦN TỬ TRÊN ĐỈNH STACK
    st.empty(); // KIỂM TRA STACK CÓ RỖNG KHÔNG
    st.size(); // SỐ PHẦN TỬ TRONG STACK
    // LƯU Ý: TRƯỚC KHI POP CẦN PHẢI XEM STACK KHÔNG RỖNG

    // ĐẨY RA KHỎI STACK
    while(!st.empty()){
        cout << st.top << " "; // LẤY PHẦN TỬ ĐÓ
        st.pop(); // ĐẨY RA KHỎI STACK
    }
}