#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// LÝ THUYẾT INTERPOLATION_SEARCH
// THUẬT TOÁN TÌM KIẾM TRÊN MẢNG ĐÃ SẮP XẾP (SORTED)
// ƯỚC LƯỢNG VỊ TRÍ PHẦN TỬ DỰA TRÊN GIÁ TRỊ CÁC PHẦN TỬ (XÁC ĐỊNH NẰM Ở KHOẢNG NÀO)
// ĐK TỐT NHẤT: CÁC PHẦN TỬ PHÂN BỐ ĐỀU
// TÌM PHẦN TỬ ĐÓ TRONG ĐOẠN LOW -> HIGH
// POS = LOW + ((TARGET-A[LOW])*(HIGH-LOW))/(A[HIGH]-A[LOW])
// TH1: A[POS] == TARGET: TRẢ VỀ INDEX
// TH2: A[POS] < TARGET: LOW = POS + 1
// TH3: A[POS] > TARGET: HIGH = POS - 1
// ĐỘ PHỨC TẠP TRUNG BÌNH: O(LOG(LOGN))
// ĐỘ PHỨC TẠP TỆ NHẤT: O(N: KHI CÁC PHẦN TỬ PHÂN BỐ KHÔNG ĐỀU

// MÔ PHỎNG CHẠY CODE:
// A = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100], N = 10, TARGET = 70
// BAN ĐẦU LOW = 0, HIGH = 9, ÁP DỤNG CT TÍNH POS: POS = 6
// KIỂM TRA A[POS] == 70, ĐÚNG NGAY -> DỪNG VÀ TRẢ VỀ NDEX
// GIẢ SỬ TARGET = 85
// LẦN 1: POS = 7 -> A[POS] < 85, LOW = POS + 1
// LÚC NÀY LOW = 8, HIGH = 9
// LẦN 2: POS = 7 < LOW -> NOT FOUND

int interpolationSearch(int a[], int n, int target) {
    int low = 0; int high = n - 1;
    while (low <= high && target >= a[low] && target <= a[high]) {
        if(a[low] == a[high]){
            if (a[low] == target) return low;
            return -1;
        }
        int pos = low + ((target - a[low]) * (high - low)) / (a[high] - a[low]);

        if(a[pos] == target) return pos;
        if(a[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main(){

}