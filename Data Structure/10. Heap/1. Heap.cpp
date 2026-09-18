#include <iostream>
using namespace std;

// HEAP: ĐỐNG -> CÂY NHỊ PHÂN GẦN NHƯ HOÀN TOÀN
// MAX_HEAP: DỮ LIỆU NODE NÀY >= MỌI NÚT SAU
// MIN_HEAP: DỮ LIỆU NODE NÀY <= MỌI NÚT SAU 

struct Heap{
    int* arr;
    int size; // SỐ NODE TỐI ĐA 
    int count; // SỐ NODE HIỆN TẠI
};

// KHỞI TẠO HEAP RỖNG BAN ĐẦU
void init(Heap& heap, int size){
    heap.arr = new int[size];
    heap.size = size;
    heap.count = 0;
}

// KIỂM TRA HEAP RỖNG
bool empty(Heap heap){
    return heap.count == 0; // SỐ LƯỢNG NODE HIỆN TẠI LÀ 0
}

// KIỂM TRA HEAP BỊ ĐẦY
bool full(Heap heap){
    return heap.count == heap.size;
}

// TẠO HEAP TỪ MẢNG CÓ N PHẦN TỬ
// THUẬT TOÁN SHIFT UP:
// THUẬT TOÁN SHIFT DOWN:



















int main(){

}