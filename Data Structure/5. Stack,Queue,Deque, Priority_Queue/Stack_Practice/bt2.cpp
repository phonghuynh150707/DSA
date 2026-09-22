#include <iostream>
#include <stack>
using namespace std;

// TRUNG TỐ: A + B
// TIỀN TỐ: +AB
// HẬU TỐ: AB+

// CHUYỂN TỪ TIỀN TỐ SANG TRUNG TỐ
string A(string s){
    stack<string> st; // STACK LƯU STRING
    for(int i = s.size()-1; i >= 0; i--){ // DUYỆT TỪ CUỐI LÊN
        if(isalpha(s[i])) st.push(string(1,s[i])); // CHUYỂN CHAR THÀNH STRING
        else{
            string x = st.top(); st.pop(); // LẤY 2 TOÁN HẠNG RA
            string y = st.top(); st.pop();
            string temp = x + s[i] + y; // NHÉT TOÁN TỬ VÀO GIỮA
            st.push(temp); // NHÉT LẠI VÀO STACK
        }
    }
    return st.top(); // PHẦN TỬ CUỐI CÙNG Ở DẠNG TRUNG TỐ
}

// CHUYỂN TỪ TIỀN TỐ SANG HẬU TỐ
string B(string s){
    stack<string> st; // STACK LƯU STRING
    for(int i = s.size()-1; i >= 0; i--){
        if(isalpha(s[i])) st.push(string(1,s[i])); // CHUYỂN CHAR THÀNH STRING
        else{
            string x = st.top(); st.pop(); // LẤY 2 TOÁN HẠNG RA
            string y = st.top(); st.pop();
            string temp = x + y + s[i]; // NHÉT TOÁN TỬ VÀO CUỐI
            st.push(temp); // NHÉT LẠI VÀO STACK
        }
    }
    return st.top();
}

// CHUYỂN TỪ HẬU TỐ SANG TRUNG TỐ

int main(){

}