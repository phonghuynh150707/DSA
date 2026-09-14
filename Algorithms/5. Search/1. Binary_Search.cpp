#include <iostream>
#include <algorithm>
using namespace std;

bool BinarySearch(int a[], int left, int right, int x){ // MẢNG PHẢI ĐƯỢC SẮP XẾP
    while(left <= right){
        int mid = left + (right-left)/2; 
        if(a[mid] == x) return true;
        else if( a[mid] < x) left = mid + 1; // DỜI QUA NỬA PHẢI
        else right = mid - 1; // DỜI QUA NỬA TRÁI
    }
    return false; // KHÔNG TÌM THẤY
}

bool RecurBS(int a[], int left, int right, int x){ // BS BẰNG ĐỆ QUY
    if(left > right) return false;
    int mid = left + (right-left)/2;
    if(a[mid] == x) return true;
    else if(a[mid] < x) return RecurBS(a, mid+1, right, x);
    else return RecurBS(a,left,mid-1,x);
}

int LowerBound(int a[], int left, int right, int x){ // PHẦN TỬ ĐẦU TIÊN >= X
    int index = -1; // KHÔNG TÌM THẤY
    while(left <= right){
        int mid = left + (right-left)/2;
        if(a[mid] >= x){
            index = mid; // LƯU LẠI INDEX
            right = mid - 1; // TÌM BÊN TRÁI ĐỂ CÓ KQ TỐT HƠN
        }
        else left = mid + 1; // TÌM BÊN PHẢI ĐỂ CÓ KQ TỐT HƠN
    }
    return index; // INDEX PHẦN TỬ XH ĐẦU TIÊN >= X
}

int UpperBound(int a[], int left, int right, int x){ // INDEX PHẦN TỬ ĐẦU TIỀN > X
    int index = -1; // KHÔNG TÌM THẤY
    while(left <= right){
        int mid = left + (right-left)/2;
        if(a[mid] > x){
            index = mid; // LƯU LẠI INDEX
            right = mid - 1; // TÌM BÊN TRÁI ĐỂ CÓ KQ TỐT HƠN
        }
        else left = mid + 1; // TÌM BÊN PHẢI ĐỂ CÓ KQ TỐT HƠN
    }
    return index; // INDEX PHẦN TỬ XH ĐẦU TIÊN > X
}

int main(){
    int n,x; cin >> n >> x; int a[1005]; 
    for(int i = 0; i < n; i++) cin >> a[i];
    // DÙNG BINARY_SEARCH THÌ MẢNG BAN ĐẦU PHẢI ĐƯỢC SẮP XẾP -> SORT -> O(NLOGN)
    bool m = binary_search(a,a+n,x); // KIỂM TRA TỒN TẠI BẰNG BINARY_SEARCH: TRUYỀN 2 THAM SỐ CON TRỎ (ITER)
    int* it1 = lower_bound(a,a+n,x); // TRẢ VỀ CON TRỎ PHẦN TỬ ĐẦU TIÊN >= X
    int* it2 = upper_bound(a,a+n,x); // TRẢ VỀ CON TRỎ PHẦN TỬ ĐẦU TIÊN > X
    int tan_suat = it1 - it2; // UPPERBOUND - LOWERBOUND RA TẦN SUẤT XH
    // TƯƠNG TỰ: V.BEGIN(), V.END() THAY CHO CON TRỎ
    // MỘT ĐOẠN [I,J]BẤT KÌ: V.BEGIN()+I,V.BEGIN()+J+1 HAY A+I, A+J+1
    // IT2 - 1: PHẦN TỬ CUỐI CÙNG <= X, NẾU IT2 KHÔNG PHẢI V.END()
    // IT1 - V.BEGIN() (A): RA INDEX
}