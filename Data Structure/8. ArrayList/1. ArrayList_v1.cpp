#include <iostream>
using namespace std;

void resize(int *&a, int size, int &capacity){
    capacity = capacity*2; // TĂNG SỨC CHỨA LÊN 2
    int* new_list = new int[capacity];
    for(int i = 0; i < size; i++){
        new_list[i] = a[i];
    }
    delete[] a;
    a = new_list;
}

void add(int* &a, int &size, int &capacity, int value){ // THÊM VÀO CUỐI MẢNG

    if(size == capacity) resize(a,size,capacity); // MẢNG ĐẦY THÌ RESIZE
    a[size] = value; // GÁN PHẦN TỬ CUỐI 
    ++size; // TĂNG KÍCH THƯỚC
}

int get(int* a, int size, int index){ // TRUY XUẤT TRONG MẢNG
    if(index >= 0 && index < size) return a[index]; // INDEX HỢP LỆ THÌ TRẢ VỀ VỊ TRÍ ĐÓ
    else return -1; // INDEX KHÔNG HỢP LỆ
}


void set(int* a, int size, int index, int value){ // SỬA ĐỔI GIÁ TRỊ
    if(index >= 0 && index < size) a[index] = value; // KIỂM TRA INDEX HỢP LỆ RỒI SỬA
    else return;
}

void insert(int* &a, int &size, int &capacity, int index, int value){ // CHÈN VÀO MỘT VỊ TRÍ BẤT KÌ
    if(index >= 0 && index <= size){
        if(size == capacity) resize(a,size,capacity); // NẾU ĐẦY MẢNG THÌ RESIZE
        for(int i = size-1; i >= index; i--){ // DỊCH CÁC PHẦN TỬ SANG PHẢI
            a[i+1] = a[i];
        }
        a[index] = value; // GÁN INDEX = VAL
        ++size; // TĂNG KÍCH THƯỚC
    }
    else return;
}

void remove(int* a, int &size, int index){ // XÓA MỘT PHẦN TỬ TẠI INDEX
    if(index >= 0 && index < size){
        for(int i = index; i < size-1; i++){
            a[i] = a[i+1]; // DỜI CÁC PHẦN TỬ SANG BÊN TRÁI 1 Ô
        }
        --size; // GIẢM KÍCH THƯỚC 1 ĐƠN VỊ
    }
    else return;
}


bool isEmpty(int size){ // KIỂM TRA RỖNG
    if(size == 0) return true; // NẾU SIZE = 0 THÌ RỖNG
    else return false;
}

int getSize(int size){ // LẤY KÍCH THƯỚC
    return size; 
}

bool contains(int* a, int size, int value){ // KIỂM TRA XEM PHẦN TỬ CÓ TỒN TẠI TRONG LIST 
    // Ý TƯỞNG LINEAR SEARCH: DUYỆT TUYẾN TÍNH
    for(int i = 0; i < size; i++){
        if(a[i] == value) return true;
    }
    return false;
}

int indexOf(int* a, int size, int value){ // INDEX PHẦN TỬ TRUY XUẤT: LẤY ĐẦU TIÊN
    for(int i = 0; i < size; i++){
        if(a[i] == value) return i;
    }
    return -1; // KHÔNG TỒN TẠI PHẦN TỬ ĐÓ
}

int lastIndexOf(int* a, int size, int value){ // INDEX PHẦN TỬ TRUY XUẤT CUỐI LÊN
    for(int i = size-1; i >= 0; i--){ // DUYỆT NGƯỢC LẠI
        if(a[i] == value) return i;
    }
    return -1; // KHÔNG TỒN TẠI PHẦN TỬ ĐÓ
}

void clear(int* a, int &size){ // XÓA TẤT CẢ PHẦN TỬ
    size = 0; // CHUYỂN KÍCH THƯỚC VỀ 0
}

void destroy(int* &a){ // XÓA MẢNG -> K SỬ DỤNG NỮA
    delete[] a; // GIẢI PHÓNG
    a = nullptr; // GÁN A = CON TRỎ NULL
}

void removeValue(int* a, int &size, int value){ // XÓA PHẦN TỬ XH ĐẦU TIỀN
    int ind = indexOf(a, size, value); // LẤY INDEX PHẦN TỬ ĐÓ
    if(ind != -1){ // TỒN TẠI TRONG MẢNG MỚI XÓA
        remove(a, size, ind);
    }
}

void print(int* a, int size){ // IN PHẦN TỬ TRONG MẢNG
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

int main(){
    
}