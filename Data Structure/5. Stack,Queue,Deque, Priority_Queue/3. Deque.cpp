#include <iostream>
#include <deque>
using namespace std;

int main(){
    // DEQUE: HÀNG ĐỢI 2 ĐẦU, GIỐNG QUEUE NHƯNG CÓ 2 ĐẦU
    deque<int> dq; // KHAI BÁO HÀNG ĐỢI 2 ĐẦU RỖNG
    dq.push_front(x); // THÊM VÀO ĐẦU
    dq.pop_front(); // XÓA Ở ĐẦU
    dq.push_back(x); // THÊM VÀO CUỐI 
    dq.pop_back(); // XÓA Ở CUỐI
    dq.front(); // XEM ĐẦU HÀNG
    dq.back(); // XEM CUỐI HÀNG
    dq.size(); // XEM SỐ PHẦN TỬ
    dq.empty(); // KIỂM TRA CÓ RỖNG KHÔNG
    // DEQUE CÓ THỂ TRUY CẬP BẰNG INDEX
    dp[x]; // PHẦN TỬ THỨ X
    // DEQUE CÓ ITERATOR
    dq.insert(dq.begin() + index, val); // CHÈN VÀO GIỮA
    dq.erase(dq.begin() + index); // XÓA PHẦN TỬ BẰNG ITER
    // DUYỆT DEQUE
    while(!dq.empty()){ // DUYỆT TỪ ĐẦU TỚI CUỐI
        cout << dq.front << " ";
        dq.pop_front();
    }
    while(!dq.empty()){ // DUYỆT TỪ CUỐI TỚI ĐẦU
        cout << dq.back() << " ";
        dq.pop_back();
    }
    for( int x : dq){ cout << x << " "}; // DUYỆT BẰNG RANGED_BASED
    for( auto it = dq.begin(); it != dq.end(); it++){ cout << *it << " ";}
}