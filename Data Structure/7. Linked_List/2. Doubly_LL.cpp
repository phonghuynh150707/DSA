#include <iostream>
using namespace std;
struct node(){ // STRUCT NODE
    int data; // DỮ LIỆU
    node* next; // CON TRỎ TỚI NODE TIẾP THEO
    node* prev; // CON TRỎ TỚI NODE PHÍA TRƯỚC
}

node* MakeNode(int x){
    node* NewNode = new node;
    NewNode->data = x;
    NewNode->next = nullptr;
    NewNode->prev = nullptr;
}

int CountNode(node* head){ // ĐẾM SỐ LƯỢNG NODE
    int cnt = 0;
    node* temp = head;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void Print_Forward(node* head){ // DUYỆT THUẬN
    node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void Print_Reverse(node* head){ // DUYỆT NGƯỢC
    node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

node* InsertHead(node* head, int x){ // CHÈN VÀO ĐẦU
    node* NewNode = MakeNode(x);
    if(head == nullptr) return NewNode;
    NewNode->next = head;
    head->prev = NewNode;
    return NewNode;
}

node* InsertTail(node* head, int x){ // CHÈN VÀO CUỐI
    node* NewNode = MakeNode(x);
    if(head == nullptr) return NewNode;
    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = NewNode;
    NewNode->prev = temp;
    return head;
}

node* InsertMiddle(node* head, int x, int index){ // CHÈN VÀO GIỮA
    node* NewNode = MakeNode(x);
    if(head == nullptr) return NewNode; // DSLK RỖNG
    if(index == 1){ // CHÈN ĐẦU
        NewNode->next = head;
        head->prev = NewNode;
        return NewNode;
    }
    // DUYỆT TỚI VỊ TRÍ TRƯỚC INDEX
    node* temp = head;
    for(int i = 1; i < index - 1 && temp->next != nullptr ; i++){
        temp = temp->next;
    }
    if(temp->next == nullptr){ // INDEX VƯỢT QUÁ, CHÈN CUỐI
        temp->next = NewNode;
        NewNode->prev = temp;
        return head;
    } 
    NewNode->next = temp->next;
    temp->next->prev = NewNode;
    temp->next = NewNode;
    NewNode->prev = temp;
    return head;
}

node* DeleteHead(node* head){ // XÓA ĐẦU
    if(head == nullptr) return nullptr;
    node* temp = head;
    head = head->next;
    if(head != nullptr) head->prev = nullptr;
    delete temp;
    return head;
}

node* DeleteTail(node* head){ // XÓA CUỐI
    if(head == nullptr) return nullptr; // NẾU DSLK RỖNG
    if(head->next == nullptr){ // NẾU CHỈ CÓ MỘT NODE
        delete head;
        return nullptr;
    }
    node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

node* DeleteMiddle(node* head, int index){ // XÓA GIỮA
    if(head == nullptr) return nullptr;
    if( index <= 0 || index > CountNode(head)) return head;
    if(index == 1){ // XÓA ĐẦU
        node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }
    if( index == CountNode(head)){
        if(head->next == nullptr){ // NẾU CHỈ CÓ MỘT NODE
            delete head;
            return nullptr;
        }
        node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }
    node* temp = head;
    for( int i = 1; i < index -1 && temp->next != nullptr; i++){
        temp = temp->next;
    }
    node* del = temp->next;
    temp->next = del->next;
    del->next->prev = temp;
    delete del;
    return head;
}

int main(){
    // CÁC NODE NỐI VỚI NHAU QUA 2 CON TRỎ NEXT, PREV
    // 2 NODE ĐẦU CUỐI TRỎ VÀO NULL
}