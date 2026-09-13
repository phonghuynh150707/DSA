#include <iostream>
using namespace std;

struct node{ // STRUCT NODE
    int data; // DỮ LIỆU
    node* next; // CON TRỎ NEXT
};

node* Makenode(int x){ // HÀM TẠO NODE
    node* NewNode = new node; // CON TRỎ NEWNODE QUẢN LÝ Ô NODE ĐƯỢC CẤP PHÁT
    NewNode->data = x; // TRUY CẬP VÀO DATA
    NewNode->next = nullptr; // TRUY CẬP VÀO NEXT
    return NewNode; // TRẢ VỀ CON TRỎ NODE ĐƯỢC TẠO
}

void PrintList(node* head){ // DUYỆT LINKED LIST
    node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " "; // LẤY GIÁ TRỊ
        temp = temp->next; // NHẢY QUA NODE TIẾP THEO
    }
}

int countNode(node* head){ // ĐẾM SÓ PHẦN TỬ TRONG LINKED LIST
    int cnt = 0;
    node* temp = head;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

node* InsertHead(node* head, int x){ // THÊM VÀO ĐẦU DSLK
    node* p = Makenode(x); // TẠO NODE MỚI
    p->next = head; // NỐI VÀO ĐẦU DSLK
    return p; // TRẢ VỀ CON TRỎ ĐẦU DSLK
}

node* InsertTail(node* head, int x){ // THÊM NODE VÀO CUỐI
    node* NewNode = Makenode(x);
    if( head == nullptr) return NewNode; // NẾU RỖNG THÌ TRẢ VỀ NEWNODE
    node* temp = head; // BIẾN TẠM
    while(temp->next != nullptr){
        temp = temp->next; // DỪNG Ở NODE CUỐI CÙNG
    }
    temp->next = NewNode;
    return head;
}

node* InsertMiddle(node* head, int x, int index){ // THÊM NODE VÀO GIỮA
    node* NewNode = Makenode(x);
    if(index == 0 || head == nullptr){ // CHÈN ĐẦU
        NewNode->next = head;
        return NewNode;
    }
    node* temp = head; // BIẾN TẠM
    // DUYỆT TỚI VỊ TRÍ K-1
    for(int i = 0; (i < index-1) && (temp->next != nullptr); i++){
        temp = temp->next;
    } // CHÈN VÀO GIỮA
    NewNode->next = temp->next;
    temp->next = NewNode;
    return head;
}

node* DeleteHead(node* head){ // XÓA ĐẦU
    if(head == nullptr) return nullptr;
    node* temp = head;
    head = head->next; // DỊCH HEAD LÊN MỘT NODE
    delete temp; // XÓA NODE ĐẦU
    return head;
}

node* DeleteTail(node* head){ // XÓA CUỐI
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){ // CHỈ CÓ MỘT NODE
        delete head;
        return nullptr;
    }
    node* temp = head;
    // DUYỆT TỚI PHẦN TỬ TRƯỚC NODE CUỐI
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

node* DeletaMiddle(node* head, int index){ // XÓA GIỮA
    if(head == nullptr) return nullptr;
    if(index == 0){ // XÓA ĐẦU
        head = DeleteHead(head);
    }
    node* temp = head;
    // DUYỆT TỚI VỊ TRÍ K-1
    for(int i = 0; (i < index-1) && (temp->next != nullptr); i++){
        temp = temp->next;
    }
    if(temp->next == nullptr) return head; // INDEX VƯỢT QUÁ LIST
    node* del = temp->next; // XÓA NODE THỨ INDEX
    temp->next = del->next;
    delete del;
    return head;
}

node* SortLL(node* head){
    for(node* i = head; i != nullptr; i = i->next){
        for(node* j = i->next; j != nullptr; j = j->next){
            if(i->data > j->data){
                swap(i->data,j->data);
            }
        }
    }
}
int main(){
    // DSLK LÀ CTDL DÙNG ĐỂ LƯU TRỮ CÁC PHẦN TỬ
    // DSLK ĐƯỢC CẤU THÀNH TỪ CÁC NODE: GẦM DỮ LIỆU (DATA) VÀ CON TRỎ TỚI ĐỊA CHỈ TIẾP THEO (NEXT)
    // NODE NẰM RẢI RÁC TRONG BỘ NHỚ

}