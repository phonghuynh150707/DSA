#include <iostream>
#include <queue>
using namespace std;

int main(){
    // HÀNG ĐỢI QUEUE: FIFO (FIRST IN, FIRST OUT): ĐẾN SAU THÌ ĐỨNG SAU, ĐẾN TRƯỚC ĐỨNG TRƯỚC!
    queue<int> q; // KHAI BÁO HÀNG ĐỢI Q RỖNG
    q.push(x); // THÊM VÀO CUỐI HÀNG
    q.pop(); // ĐẨY RA KHỎI ĐẦU HÀNG
    q.front(); // XEM PHẦN TỬ ĐẦU HÀNG, CB ĐƯỢC POP RA
    q.back(); // XEM PHẦN TỬ CUỐI HÀNG, MỚI ĐƯỢC PUSH VÀO
    q.size(); // SỐ PHẦN TỬ TRONG HÀNG ĐỢI
    q.empty(); // KIỂM TRA RỖNG

    // DUYỆT QUEUE
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}