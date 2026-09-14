#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

// CÁC THUẬT TOÁN SẮP XẾP O(N^2)
void BubbleSort(int a[], int n){ // PHẦN TỬ LỚN NHẤT NỔI VỀ CUỐI MỖI LƯỢT, O(N^2)
    for(int i = 0; i < n-1; i++){ // DUYỆT TỪ ĐẦU TỚI ÁP CHÓT
    // THỰC HIỆN TỐI ĐA N-1 LƯỢT
        for(int j = 0; j < n-1-i; j++){ // DUYỆT TỚI TRƯỚC PHẦN TỬ DUYỆT 2 BẬC
            if(a[j] > a[j+1]) swap(a[j],a[j+1]); // SAI VỊ TRÍ THÌ ĐỔI CHỖ
        }
    }
}

void SelectionSort(int a[], int n){ // TÌM TRONG DÃY CHƯA ĐƯỢC SẮP XẾP PTU BÉ NHẤT, ĐƯA VỀ ĐẦU
    for(int i = 0; i < n-1; i++){ 
    // THỰC HIỆN TỐI ĐA N-1 LƯỢT
        int minIndex = i; // INDEX PHẦN TỬ NHỎ NHẤT, NẾU KHÔNG TỒN TẠI THÌ HOÁN VỊ CHÍNH NÓ
        int mn = INT_MAX; // PHẦN TỬ BÉ NHẤT
        for(int j = i+1; j < n; j++){ // DÒ TỪ BÊN PHẢI VỊ TRÍ INDEX CẦN CHÈN
            if(a[j] < mn){ // TÌM PHẦN TỬ BÉ NHẤT
                mn = a[j];
                minIndex = j; // CẬP NHẬT INDEX PHẦN TỬ BÉ NHẤT
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void InsertionSort(int a[], int n){ // LẤY PHẦN TỬ HIỆN TẠI, DỊCH PHẦN TỬ LỚN HƠN SANG PHẢI, RỒI CHÈN THÍCH HỢP
    // LẤY A[0] LÀM MỐC ĐÃ SẮP XẾP
    for(int i = 1; i < n; i++){ // DUYỆT TỪ INDEX 1 TỚI CUỐI
        int key = a[i]; // PHẦN TỬ HIN TẠI CẦN CHÈN: LƯU LẠI TRÁNH GHI ĐÈ
        int j = i-1; // DUYỆT TỪ PHẦN TỬ TRƯỚC KEY VỀ TRƯỚC
        while( j >= 0 && a[j] > key){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key; // GÁN VÀO INDEX THÍCH HỢP
    }
}

void InterchangeSort(int a[], int n){ // MY FAVOURITE SORT!
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; i++){
            if(a[i] > a[j]) swap(a[i],a[j]);
        }
    }
}

// ĐỘ PHỨC TẠP KHÔNG XÁC ĐỊNH
void ShellSort(int a[], int n){ // INSERTION SORT + GAP
    // INSERTION SORT -> DỜI TỪNG PHẦN TỬ QUA -> GAP = 1 -> CHẬM
    // SHELL SORT -> ĐỔI VỊ TRÍ THEO GAP -> CÁC PHẦN TỬ LỚN TRÔI VỀ SAU, NHỎ TRÔI LÊN TRƯỚC
    for(int gap = n / 2; gap > 0; gap /= 2){ // GIẢM GAP LẦN LƯỢT CHIA ĐÔI
    // GAP = 1 THÀNH INSERTION SORT, LÚC NÀY MẢNG ĐÃ XẾP TỐT -> HÀM CHẠY NHANH HƠN
        for(int i = gap; i < n; i++){ // CHẠY TỪ GAP TỚI CUỐI!
            int key = a[i]; // PHẦN TỬ HIỆN TẠI
            int j = i; // VỊ TRÍ HIỆN TẠI CỦA KEY
            while(j >= gap && a[j - gap] > key){ // CÒN PHẦN TỬ Ở TRƯỚC > KEY
                a[j] = a[j - gap]; // DỊCH SANG PHẢI GAP
                j -= gap; // NHẢY NGƯỢC GAP
            }
            a[j] = key;
        }
    }
}

// CÁC THUẬT TOÁN SẮP XẾP (ONLOGN)

// THUẬT TOÁN MERGE SORT
void Merge(int a[], int left, int mid, int right){ // TRỘN LẠI CÁC PHẦN TỬ
    // GIẢ SỬ RẰNG: 2 NỬA MẢNG ĐÃ ĐƯỢC SẮP XẾP, TỨC A[LEFT->MID] VÀ A[MID+1,RIGHT]
    int i = left, j = mid+1; // 2 CON TRỎ VÀO ĐẦU 2 MẢNG ĐÃ SẮP XẾP
    int temp[10000]; // MẢNG TẠM
    int index = 0; // INDEX CỦA MẢNG PHỤ
    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            temp[index] = a[i]; i++; index++;
        }
        else if(a[i] > a[j]){
            temp[index] = a[j]; j++; index++;
        }
        else{
            temp[index] = a[i]; i++; index++;
        }
    }
    while(i <= mid){
        temp[index] = a[i]; i++; index++;
    }
    while(j <= right){
        temp[index] = a[j]; j++; index++;
    }
    for(int x = 0; x < index; x++){ // GÁN A = TEMP
        a[left + x] = temp[x];
    }
}

void MergeSort(int a[], int left, int right){ // CHIA MẢNG THÀNH CÁC PHẦN
    if(left >= right) return; // CHỈ CÒN 1 PTU KHÔNG CHIA NỮA
    int mid = left + (right - left) / 2; // LEFT CÓ THỂ KHÁC 0
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

// THUẬ TOÁN QUICK SORT
// PHÂN HOẠCH LOMUTO: CHỌN PIVOT CHIA DÃY LÀM 2 NỬA, <= PIVOT VÀ >= PIVOT
// PHÂN HOẠCH TỚI KHI DÃY CON CÒN 1 PHẦN TỬ
int LomutoPartition(int a[], int left, int right){ 
    int pivot = a[right]; // CHỐT LÀ PHẦN TỬ CUỐI CÙNG BÊN PHẢI
    int i = left-1; // INDEX TRƯỚC VỊ TRÍ ĐẦU TIÊN
    for(int j = left; j < right; j++){ // DUYỆT TỪ LEFT TỚI TRƯỚC PIVOT
        if(a[j] <= pivot){ // NẾU PHẦN TỬ XÉT <= CHỐT
            ++i; // TĂNG I
            swap(a[i],a[j]); // DỒN SỐ BÉ VỀ BÊN TRÁI, ĐƯA SỐ LỚN QUA BÊN PHẢI
        }
    }
    ++i; // I ĐANG Ở INDEX SỐ <= PIVOT -> TĂNG LÊN 1 QUA SỐ >= PIVOT
    swap(a[i],a[right]);
    return i; // VỊ TRÍ PIVOT VÀO GIỮA
}

void QuickSort1(int a[], int left, int right){
    if(left >= right) return;
    int p = LomutoPartition(a,left,right); // PHÂN HOẠCH 2 NỬA
    QuickSort1(a,left,p-1); // PHÂN HOẠCH NỬA TRÁI
    QuickSort1(a,p+1,right); // PHÂN HOẠCH NỬA PHẢI
}


// PHÂN HOẠCH HOARE
int Hoare_Partition(int a[], int left, int right){
    int pivot = a[left]; // CHỐT LÀ PHẦN TỬ ĐẦU TIÊN
    int i = left-1, j = right+1; // 2 CON TRỎ I,J Ở TRƯỚC ĐẦU VÀ SAU CUỐI
    while(true){ // LẶP TỚI KHI HOÀN THÀNH (RETURN)
        do{
            ++i; // TĂNG I TỚI KHI GẶP PHẦN TỬ >= PIVOT
        } while(a[i] < pivot);
        do{
            --j; // GIẢM J TỚI KHI GẶP PHẦN TỬ <= PIVOT
        } while(a[j] > pivot); 
        if(i < j){
            swap(a[i],a[j]); // ĐỔI VỊ TRÍ 2 PHẦN TỬ NGHỊCH THẾ
        }
        else return j; // PHẦN TỬ SAU CÙNG <= PIVOT
    }
}

void QuickSort2(int a[], int left, int right){
    if(left >= right) return;
    int p = Hoare_Partition(a,left,right);
    QuickSort2(a,left, p); // NỬA TRÁI GỒM CÁI P
    QuickSort2(a, p+1, right); // NỬA PHẢI TỪ P+1 TRỞ ĐI
}

// THUẬT TOÁN HEAP SORT
void heapify(int a[], int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if(l < n && a[l] > a[largest]){
        largest = l;
    }

    if(r < n && a[r] > a[largest]){
        largest = r;
    }

    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

// CÁC THUẬT TOÁN SẮP XẾP O(N+K)
// SẮP XẾP CÁC PHẦN TỬ CÓ GIÁ TRỊ NHỎ
void CountingSort1(int a[], int n){ // UNSTABLE SORT
    int count[10000] = {0}; // MẢNG ĐẾM, BAN ĐẦU TOÀN 0
    int index = 0; // DUY TRÌ VỊ TRÍ TRONG MẢNG SORT
    for(int i = 0 ; i < n; i++){
        count[a[i]]++; // ĐẾM SỐ LẦN XUẤT HIỆN CỦA A[I]
    }
    for(int i = 0; i < 10000; i++){
        while(count[i] > 0){
            count[i]--;
            a[index] = i;
            index++;
        }
    }
}

void CountingSort2(int a[], int n){ // STABLE SORT: GIỮ NGUYÊN VỊ TRÍ TƯƠNG ĐỐI PHẦN TỬ CÙNG KEY
    int count[10000] = {0}; // MẢNG ĐẾM TẦN SUẤT
    int sort[10000]; // MẢNG SAU SẮP XẾP
    for(int i = 0; i < n; i++) count[a[i]]++; // LƯU TẦN SUẤT
    for(int i = 1; i < 10000; i++) count[i] += count[i-1]; // CỘNG TÍCH LŨY SỐ LẦN XUẤT HIỆN
    // COUNT[X] LƯU SỐ PHẦN TỬ <= X: COUNT[3] = 5 THÌ SỐ 3 ĐẶT VÀO INDEX 4
    for(int i = n-1; i >= 0; i--){ // DUYỆT NGƯỢC LẠI
        sort[count[a[i]]-1] = a[i];
        count[a[i]]--; // GIẢM TẦN SUẤT 
    }
    for(int i = 0; i < n; i++){
        a[i] = sort[i]; // GÁN MẢNG A THÀNH MẢNG SORT
    }
}
bool comp(int a, int b){ // DỮ LIỆU CỦA MẢNG
    return a < b;
}
int main(){
    int n; cin >> n; int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n); // 2 CON TRỎ ĐẦU VÀ CUỐI
    sort(a,a+n, greater<int>()); // XẾP GIẢM DẦN
    int left, right; cin >> left >> right;
    sort(a+left,a+right+1); // XẾP TRONG ĐOẠN [L,R]
    sort(a,a+n,comp);
    stable_sort(a,a+n,comp); // GIỮ NGUYÊN TÍNH THỨ TỰ XUẤT HIỆN
}