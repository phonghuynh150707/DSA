#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    // HÀNG ĐỢI ƯU TIÊN: GIỮ PHẦN TỬ QUAN TRỌNG Ở ĐẦU
    priority_queue<int> pq; // KHAI BÁO MAX HEAP
    priority_queue<int, vector<int>, greater<int>> pq; // KHAI BÁO MIN HEAP
    pq.push(x); // ĐẨY VÀO HÀNG ĐỢI
    pq.pop(); // ĐẨY TOP RA KHỎI HÀNG ĐỢI
    pq.top(); // XEM PHẦN TỬ ĐƯỢC ƯU TIÊN
    pq.size(); // XEM SỐ PHẦN TỬ PQ
    pq.empty(); // KIỂM TRA PQ CÓ RỖNG KHÔNG
    // MAX HEAP: PHẦN TỬ LỚN NHẤT NẰM Ở TOP
    // MIN HEAP: PHẦN TỬ NHỎ NHẤT NẰM Ở TOP
    // DUYỆT
    while(!pq.empty()){ // DUYỆT LẦN LƯỢT PHẦN TỬ ƯU TIÊN
        cout << pq.top() << " ";
        pq.pop();
    }
}