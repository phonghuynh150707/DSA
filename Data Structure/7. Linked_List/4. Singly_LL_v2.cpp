#include <iostream>
using namespace std;

template <class T>
class SLinkedList{
    public:
        class Node; // Forward declaration
    protected:
        Node* head; // CON TRỎ TRỎ TỚI NODE ĐẦU
        Node* tail; // CON TRỎ TRỎ TỚI NODE CUỐI
        int count; // SỐ LƯỢNG PHẦN TỬ ĐANG CÓ
    public:
        SLinkedList(); // CONSTRUCTOR
        ~SLinkedList(); // DESTRUCTOR
        void add(T e); // THÊM VÀO CUỐI
        void add(int index, T e); // THÊM VÀO INDEX
        int size(); // TRẢ VỀ SỐ LƯỢNG PHẦN TỬ ĐANG CÓ
        bool empty(); // KIỂM TRA LL CÓ RỖNG K
        T get(int index); // LẤY GIÁ TRỊ TẠI INDEX
        void set(int index, T e); // CHỈNH SỬA GIÁ TRỊ TẠI INDEX
        int indexOf(T item); // TRẢ VỀ INDEX ĐẦU TIÊN CỦA PHẦN TỬ CẦN TÌM
        bool contains(T item); // KIỂM TRA XEM LL CÓ CHỨA PHẦN TỬ CẦN TÌM
        T removeAt(int index); // XÓA NODE TẠI INDEX
        bool removeItem(T item); // XÓA PHẦN TỬ
        void clear(); // XÓA LL
    public:
        class Node{ // NODE
            private:
                T data; // DỮ LIỆU NODE
                Node* next; // CON TRỎ NEXT TỚI NODE KẾ
                friend class SLinkedList<T>; // HÀM BẠN: TRUY CẬP ĐƯỢC CÁC HÀM VÀ THUỘC TÍNH CỦA SLL
            public:
                Node(){ // CONSTRUCTOR NODE
                    next = nullptr;
                }
                Node(Node* next){ // CONSTRUCTOR THAM SỐ NEXT: CẬP NHẬT NEXT KHI TẠO CON TRỎ
                    this->next = next;
                }
                Node(T data, Node* next){ // CONSTRUCTOR THAM SỐ DATA VÀ NEXT: TẠO CON TRỎ VỚI ĐẦY ĐỦ DỮ LIỆU VÀ CON TRỎ NEXT
                    this->data = data;
                    this->next = next;
                }
        };
};

template <class T>
void SLinkedList<T>::add(T e){ // THÊM NODE VÀO CUỐI
    Node* newNode = new Node(e, nullptr); // TẠO CON TRỎ MỚI VỚI GIÁ TRỊ E VÀ TRỎ VÀO NULL
    if(count == 0){ // LL CHƯA CÓ NODE NÀO
        head = newNode; // GÁN HEAD VÀ TAIL CÙNG TRỎ TỚI NODE ĐÓ
        tail = newNode;
    }
    else{
        tail->next = newNode; // THÊM VÀO CUỐI
        tail = newNode; // CẬP NHẬT LẠI TAIL
    }
    count++; // TĂNG SỐ LƯỢNG PHẦN TỬ LL
}

template<class T>
void SLinkedList<T>::add(int index, T e) {
    if(index < 0 || index > count) throw std::out_of_range("Index is out of range!"); // KIỂM TRA INDEX HỢP LỆ
    if(index == 0) { // CHÈN ĐẦU
        Node* newNode = new Node(e, head); // TẠO NODE
        head = newNode; // GÁN CON TRỎ HEAD VÀO NODE MỚI
        if(count == 0) tail = newNode; // NẾU NODE DUY NHẤT THÌ CẬP NHẬT TAIL
        count++; // TĂNG SỐ LƯỢNG PHẦN TỬ LÊN 1
        return; // DỪNG CHƯƠNG TRÌNH
    }
    if(index == count){ // CHÈN CUỐI
        add(e); // DÙNG LẠI HÀM ADD
        return;
    }
    // CHÈN GIỮA!
    Node* current = head; // DÙNG CON TRỎ TẠM ĐỂ DUYỆT
    for(int i = 0; i < index - 1; i++){ // DUYỆT TỚI TRƯỚC VỊ TRÍ CẦN THÊM VÀO (INDEX-2)
        current = current->next;
    }
    Node* newNode = new Node(e, current->next); // NODE MỚI TRỎ TỚI NODE SAU CURRENT
    current->next = newNode; // CHÈN
    count++; // TĂNG SỐ LƯỢNG PHẦN TỬ TRONG LL
}

template<class T>
int SLinkedList<T>::size(){
    return count; // TRẢ VỀ SỐ LƯỢNG PHẦN TỬ TRONG LL
}

template<class T>
T SLinkedList<T>::get(int index){
    if(index < 0 || index >= count) throw std::out_of_range("Index is out of range!"); // KIỂM TRA INDEX HỢP LỆ
    Node* current = head; // CON TRỎ TẠM ĐỂ GIỮ HEAD
    for(int i = 0; i < index; i++) current = current->next; // DUYỆT TỚI INDEX ĐÓ: INDEX-1
    return current->data; // TRẢ VỀ DỮ LIỆU NODE ĐÓ
}

template <class T>
void SLinkedList<T>::set(int index, T e) {
    if(index < 0 || index >= count) throw std::out_of_range("Index is out of range!"); // KIỂM TRA INDEX HỢP LỆ
    Node* current = head; // CON TRỎ TẠM GIỮ HEAD
    for(int i = 0; i < index; i++) current = current->next; // DUYỆT TỚI INDEX ĐÓ: INDEX-1
    current->data = e; // GÁN GIÁ TRỊ LẠI NODE ĐÓ
}

template<class T>
bool SLinkedList<T>::empty(){
    return count == 0; // RỖNG NẾU SỐ LƯỢNG PHẦN TỬ ĐANG CÓ TRONG LL LÀ 0
}

template<class T>
int SLinkedList<T>::indexOf(T item){
    Node* current = head;
    for(int i = 0; i < count; i++){ // DUYỆT QUA TẤT CẢ CÁC NODE: TỪ 0 -> COUNT-1
        if(current->data == item) return i; // NẾU ĐÚNG PHẦN TỬ ĐANG TÌM THÌ DỪNG
        current = current->next; // QUA NODE KẾ
    }
    return -1; // KHÔNG TỒN TẠI THÌ TRẢ VỀ FALSE
}

template<class T>
bool SLinkedList<T>::contains(T item){ 
    Node* current = head; // DÙNG CON TRỎ TẠM
    for(int i = 0; i < count; i++){ // DUYỆT QUA TẤT CẢ CÁC NODE
        if(current->data == item) return true; // NẾU TỒN TẠI PHẦN TỬ ĐANG TÌM THÌ TRUE
        current = current->next;
    }
    return false; // KHÔNG TỒN TẠI
}

template <class T>
T SLinkedList<T>::removeAt(int index){
    if(index < 0 || index >= count) throw std::out_of_range("Index is out of range!"); // KIỂM TRA INDEX HỢP LỆ
    Node* removed; // NODE CẦN XÓA
    if(index == 0){ // XÓA ĐẦU
        // ĐẢM BẢO YÊU CẦU LÀ LL KHÔNG RỖNG: ÍT NHÂT 1 NODE
        removed = head;
        head = head->next; // HEAD QUA NODE KẾ
        if(count == 1) // BAN ĐẦU CHỈ CÓ 1 NODE: GÁN TAIL
            tail = nullptr;
    }
    else{
        Node* prev = head; // CON TRỎ TẠM
        for(int i = 0; i < index - 1; i++) prev = prev->next; // DUYỆT TỚI NODE TRƯỚC NODE CẦN XÓA: INDEX-2
        removed = prev->next; // GÁN NODE CẦN XÓA
        prev->next = removed->next; // NỐI LẠI LL
        if(index == count - 1) // NẾU XÓA CUỐI
            tail = prev; // DỜI LẠI TAIL LÊN TRƯỚC
    }
    T result = removed->data; // LƯU LẠI GIÁ TRỊ XÓA
    delete removed; // XÓA NODE 
    count--; // GIẢM SỐ LƯỢNG PHẦN TỬ ĐANG CÓ
    return result; // TRẢ GIÁ TRỊ XÓA
}


template <class T>
bool SLinkedList<T>::removeItem(T item){
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr){ // Tìm node cần xóa
        if(current->data == item){
            if(current == head){ // CASE 1: XÓA NODE ĐẦU
                head = head->next;
                if(count == 1) tail = nullptr; // Nếu danh sách chỉ có 1 node
            }
            else if(current == tail){ // CASE 2: XÓA NODE CUỐI
                prev->next = nullptr;
                tail = prev;
            }
            else prev->next = current->next; // CASE 3: XÓA NODE Ở GIỮA
            delete current; // XÓA NODE ĐÓ
            count--; // GIẢM SỐ NODE LL ĐANG CÓ
            return true; // TRẢ VỀ TRUE KHI XÓA THÀNH CÔNG
        }
        prev = current; // PREV ĐI SAU CURRENT
        current = current->next; // Di chuyển sang node tiếp theo
    }
    return false; // Không tìm thấy item
}


template<class T>
void SLinkedList<T>::clear(){
    Node* current = head;
    while(current != nullptr){ // XÓA TỪNG NODE RỒI DỊCH RA NODE KẾ
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr; // CẬP NHẬT LẠI HEAD
    tail = nullptr; // CẬP NHẬT LẠI TAIL
    count = 0; // CẬP NHẬT LẠI SỐ PT
}

int main(){

}