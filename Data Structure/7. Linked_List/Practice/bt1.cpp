#include <iostream>
using namespace std;

class LLNode{
    public:
        int val;
        LLNode* next;
        LLNode(){ // Constructor: val = 0, next = nullptr
            this->val = 0;
            this->next = nullptr;
        }
        LLNode(int val, LLNode* next){ // Constructor with customized data
            this->val = val;
            this->next = next;
        }
};

// LẬT NGƯỢC SLL
LLNode* reverseLinkedList(LLNode* head){
    LLNode* prev = nullptr; // CON TRỎ NODE ĐÚNG TRƯỚC CUR
    LLNode* current = head; // CON TRỎ NODE ĐANG XỬ LÝ
    while(current != nullptr){ // DUYỆT TỚI NODE CUỐI
        LLNode* next = current->next; // CON TRỎ NEXT: CON TRỎ NODE KẾ CUR
        current->next = prev; // TRỎ NGƯỢC LẠI PREV
        prev = current; // TIẾN PREV LÊN 1 NODE
        current = next; // TIẾN CUR LÊN 1 NODE
    }
    return prev;
}

// QUAY LL SANG PHẢI K ĐƠN VỊ
LLNode* rotateLinkedList(LLNode* head, int k){
    if(head == nullptr || head->next == nullptr) return head; // List rỗng hoặc chỉ có 1 node
    // BƯỚC 1: Tìm độ dài và tail
    int n = 1;
    LLNode* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
        n++;
    }
    // BƯỚC 2: k lớn hơn n thì lấy phần dư
    k = k % n;
    // Không cần rotate
    if(k == 0) return head;
    // BƯỚC 3: Tìm node ngay trước head mới
    int steps = n - k;
    LLNode* newTail = head;
    for(int i = 1; i < steps; i++){
        newTail = newTail->next;
    }
    // BƯỚC 4: Lưu head mới
    LLNode* newHead = newTail->next;
    // BƯỚC 5: Cắt list
    newTail->next = nullptr;
    // BƯỚC 6: Nối tail cũ vào head cũ
    tail->next = head;
    return newHead;
}
int main(){

}