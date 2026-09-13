#include <iostream>
using namespace std;

struct node{ // STRUCT NODE
    int data; // DỮ LIỆU
    node* next; // CON TRỎ NEXT TỚI NODE TIẾP THEO
};

node* MakeNode(int x){
    node* NewNode = new node;
    NewNode->data = x;
    NewNode->next = nullptr;
    return NewNode;
}

void Print_List(node* head){ // DUYỆT DS VÒNG
    node* temp = head;
    if(head == nullptr) return;
    cout << temp->data << " ";
    temp = temp->next;
    while(temp != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int CountNode(node* head){ // ĐẾM SỐ NODE
    node* temp = head;
    if(head == nullptr) return 0;
    int cnt = 0;
    cnt++;
    temp = temp->next;
    while(temp != head){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

node* InsertHead(node* head, int x){ // CHÈN ĐẦU
    node* NewNode = MakeNode(x);
    if(head == nullptr){
        NewNode->next = NewNode; // TRỎ LẠI CHÍNH NÓ
        return NewNode;
    }
    node* last = head;
    while(last->next != head){
        last = last->next; // ĐI TỚI NODE CUỐI
    }
    NewNode->next = head;
    last->next = NewNode;
    return NewNode;
}

node* InsertTail(node* head, int x){ // CHÈN CUỐI
    node* NewNode = MakeNode(x);
    if(head == nullptr){
        NewNode->next = NewNode; // TỰ TRỎ LẠI CHÍNH NÓ
        return NewNode;
    }
    node* last = head;
    while(last->next != head){
        last = last->next; // ĐI TỚI NODE CUỐI 
    }
    last->next = NewNode;
    NewNode->next = head;
    return head;
}

node* InsertMiddle(node* head, int x, int index){ // CHÈN GIỮA
    if(head == nullptr){
        node* NewNode = MakeNode(x);
        NewNode->next = NewNode;
        return NewNode;
    }
    if(index <= 1){
        head = InsertHead(head,x);
        return head;
    }
    if(index >= CountNode(head)){
        head = InsertTail(head,x);
        return head;
    }
    node* NewNode = MakeNode(x);
    node* temp = head;
    for(int i = 1; i < index - 1; i++){ // DUYỆT TỚI TRƯỚC INDEX
        temp = temp->next;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
    return head;
}

node* Delete_Head(node* head){ // XÓA ĐẦU
    if(head == nullptr) return nullptr; // NẾU DSLK RỖNG
    if(head->next == head){ // NẾU CHỈ CÓ MỘT NODE
        delete head;
        return nullptr;
    }
    node* a = head;
    node* b = head;
    a = a->next; // GIỮ VỊ TRÍ KẾ ĐẦU
    while(b->next != head){ // ĐI TỚI NODE CUỐI
        b = b->next;
    }
    b->next = a;
    delete head;
    return a;
}

node* Delete_Tail(node* head){ // XÓA CUỐI
    if(head == nullptr) return nullptr; // NẾU DSLK RỖNG
    if(head->next == head){ // CHỈ CÓ MỘT NODE
        delete head;
        return nullptr;
    }
    node* temp = head;
    while(temp->next->next != head){ // DUYỆT TỚI NODE ÁP CUỐI
        temp = temp->next;
    }
    delete temp->next;
    temp->next = head;
    return head;
}

node* Delete_Middle(node* head, int index){ // XÓA GIỮA
    if(head == nullptr) return nullptr; // NẾU DSLK RỖNG
    if(index <= 1) return Delete_Head(head);
    if(index > CountNode(head)) return Delete_Tail(head);
    node* temp = head;
    for(int i = 1; i < index-1; i++){
        temp = temp->next;
    }
    node* del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

bool Has_Cycle(node* head){ // KIỂM TRA XEM CÓ CHU KÌ 
    // DÙNG 2 CON TRỎ RÙA (ĐI 1 BƯỚC), THỎ (ĐI 2 BƯỚC)
    if(head == nullptr) return false;
    node* slow = head;
    node* fast = head;
    while(fast != nullptr  && fast->next != nullptr){
        slow = slow->next; // ĐI 1 NODE
        fast = fast->next->next; // ĐI 2 NODE
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    // DSLK VÒNG ĐƠN THÌ NODE CUỐI TRỎ LẠI VÀO HEAD 

}