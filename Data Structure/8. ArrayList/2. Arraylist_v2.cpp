#include <iostream>
using namespace std;

template <class T>
class ArrayList{
    protected:
        T* data;        // dynamic array to store the list's items
        int capacity;   // size of the dynamic array
        int count;      // number of items stored in the array
    public:
        ArrayList(){ // CONSTRUCTOR
            capacity = 5; 
            count = 0; 
            data = new T[5];
        }
        ~ArrayList(){ // DESTRUCTOR
            delete[] data; // GIẢI PHÓNG MẢNG SAU KHI DÙNG XONG
        }
        void add(T e); // THÊM VÀO CUỐI MẢNG
        void add(int index, T e); // THÊM VÀO VỊ TRÍ INDEX
        int size(); // TRẢ VỀ SỐ PHẦN TỬ MẢNG ĐANG CÓ
        void ensureCapacity(int index); // ĐẢM BẢO KÍCH THƯỚC ĐỦ CHỖ ĐỂ THAO TÁC
        bool empty(); // KIỂM TRA MẢNG RỖNG
        void clear(); // XÓA HẾT MẢNG
        T get(int index); // TRUY XUẤT GIÁ TRỊ TẠI INDEX
        void set(int index, T e); // CHỈNH SỬA GIÁ TRỊ TẠI INDEX
        int indexOf(T item); // TÌM VỊ TRÍ INDEX CỦA PHẦN TỬ CHỈNH ĐỊNH
        bool contains(T item); // XEM MẢNG CÓ CHỨA PHẦN TỬ KHÔNG
        T removeAt(int index); // XÓA PHẦN TỬ TẠI INDEX
        bool removeItem(T item); // XÓA PHẦN TỬ VÀ KIỂM TRA XEM THÀNH CÔNG CHƯA
};

template <class T>
void ArrayList<T>::ensureCapacity(int index){ // RESIZE MẢNG NẾU CẦN
    if(index >= capacity){ // NẾU INDEX VƯỢT NGOÀI KÍCH THƯỚC
        int newCapacity = capacity * 1.5; // TĂNG KÍCH THƯỚC LÊN THÊM 1.5 LẦN
        T* newData = new T[newCapacity]; // TẠO MẢNG MỚI VỚI KÍCH THƯỚC MỚI
        for(int i = 0; i < count; i++) newData[i] = data[i]; // GÁN LẠI DỮ LIỆU TỪ MẢNG CŨ QUA
        delete[] data; // XÓA MẢNG CŨ
        data = newData; // CHO DATA TRỎ VÀO MẢNG MỚI
        capacity = newCapacity; // CẬP NHẬT LẠI CAPACITY
    }
}

template <class T>
void ArrayList<T>::add(T e){ // THÊM PHẦN TỬ VÀO CUỐI MẢNG
    ensureCapacity(count); // SỐ LƯỢNG PHẦN TỦ HIỆN TẠI ĐÃ ĐẦY THÌ TẠO MẢNG MỚI
    data[count] = e; // THÊM VÀO CUỐI MẢNG
    count++; // SỐ LƯỢNG PHẦN TỬ MẢNG ĐANG CHỨA TĂNG 1
}

template <class T>
void ArrayList<T>::add(int index, T e){ // THÊM PHẦN TỬ VÀO INDEX CỤ THỂ
    if(index < 0 || index > count) throw std::out_of_range("the input index is out of range!");
    ensureCapacity(count); // ĐẢM BẢO KÍCH THƯỚC CÓ THỂ CHÈN
    for(int i = count; i > index; i--) data[i] = data[i - 1]; // DỜI TỪ INDEX SANG PHẢI
    data[index] = e; // GÁN TẠI INDEX ĐÓ LÀ E
    count++; // TĂNG KÍCH THƯỚC PHẦN TỬ
}

template <class T>
int ArrayList<T>::size(){
    return count; // TRẢ VỀ SỐ PHẦN TỬ MẢNG ĐANG CHỨA
}

template<class T>
T ArrayList<T>::removeAt(int index){
    if(index < 0 || index >= count) throw std::out_of_range("index is out of range"); // INDEX KHÔNG HỢP LỆ
    T removed = data[index]; // LẤY GIÁ TRỊ PHẦN TỬ BỊ XÓA ĐỂ TRẢ VỀ
    for(int i = index; i < count - 1; i++) data[i] = data[i + 1]; // DỜI TỪ INDEX + 1 SANG TRÁI ĐỂ ĐÈ LÊN PHẦN TỬ XÓA
    count--; // SỐ LƯỢNG PHẦN TỬ MẢNG CHỨA GIẢM 1
    return removed; // TRẢ VỀ PHẦN TỬ BỊ XÓA
}

template<class T>
bool ArrayList<T>::removeItem(T item){
    for(int i = 0; i < count; i++){
        if(data[i] == item){ // DUYỆT TỚI PHẦN TỬ ĐÓ
            removeAt(i); // XÓA
            return true; // KẾT THÚC BẰNG VIỆC XÓA THÀNH CÔNG!
        }
    }
    return false; // KHÔNG XÓA ĐƯỢC THÌ TRẢ VỀ FALSE
}

template<class T>
void ArrayList<T>::clear(){
    delete[] data; // XÓA MẢNG CŨ
    capacity = 5; // CẬP NHẬT LẠI KÍCH THƯỚC BAN ĐẦU (5)
    count = 0; // SỐ LƯỢNG PHẦN TỬ BAN ĐẦU LÀ 0
    data = new T[capacity]; // TRỎ TỚI MẢNG MỚI RỖNG HOÀN TOÀN
}

template<class T>
T ArrayList<T>::get(int index){ // TRẢ VỀ PHẦN TỬ TẠI INDEX ĐÓ
    if(index < 0 || index >= count) throw std::out_of_range("index is out of range"); // INDEX KHÔNG HỢP LỆ
    return data[index]; // HỢP LỆ THÌ TRẢ VỀ GIÁ TRỊ TẠI INDEX ĐÓ
}

template<class T>
void ArrayList<T>::set(int index, T e){ // CHỈNH SỬA GIÁ TRỊ TẠI INDEX
    if(index < 0 || index >= count) throw std::out_of_range("Index is out of range"); // INDEX KHÔNG HỢP LỆ
    data[index] = e; // GÁN GIÁ TRỊ LẠI TẠI INDEX ĐÓ
}

template<class T>
bool ArrayList<T>::empty(){ // KIỂM TRA MẢNG RỖNG
    return count == 0; // SỐ LƯỢNG PHẦN TỬ MẢNG CHỨA = 0 THÌ TRUE
}

template<class T>
int ArrayList<T>::indexOf(T item){ // TÌM INDEX PHẦN TỬ ĐANG XÉT
    for(int i = 0; i < count; i++){ // DUYỆT HẾT MẢNG
        if(data[i] == item) return i; // NẾU CÓ PHẦN TỬ ĐANG TÌM THÌ TRẢ VỀ VỊ TRÍ
    }
    return -1; // KHÔNG TỒN TẠI THÌ TRẢ VỀ -1
}

template<class T>
bool ArrayList<T>::contains(T item){ // KIỂM TRA XEM MẢNG CÓ CHỨA PHẦN TỬ ĐÓ KHÔNG
    for(int i = 0; i < count; i++){ // DUYỆT QUA HẾT MẢNG
        if(data[i] == item) return true; // NẾU MẢNG CHỨA THÌ TRẢ VỀ TRUE
    }
    return false; // KHÔNG CHỨA THÌ TRẢ VỀ FALSE
}

int main(){

}