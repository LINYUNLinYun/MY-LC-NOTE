struct ListNode
{
    ListNode* next;
    int val;
    ListNode() : val(), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode* ptr) : val(x), next(ptr){};
};


class MyLinkedList {
public:
    ListNode* head;
    int n;
    

    //单链表
    MyLinkedList() {
        // head = new ListNode(-1);
        n = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= n){
            return -1;
        }
        ListNode* temp = head;
        int i = 0;
        while(i<index - 1){
            if(temp->next != nullptr){
                temp = temp->next;
                i++;
            }
            else{
                break;
            }
        }
    }
    
    void addAtHead(int val) {
        ListNode* temp = new ListNode(val);
        temp->next = head;
        head = temp;
        n++;
    }
    
    void addAtTail(int val) {
        ListNode* temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = new ListNode(val);
        n++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > n){
            return;
        }
        ListNode* temp = head;
        int i = 0;
        while(i<index - 1){
            if(temp->next != nullptr){
                temp = temp->next;
                i++;
            }
            else{
                break;
            }
        }
        if(i == index -1){
            ListNode* indexNode = new ListNode(val);
            indexNode->next = temp->next;
            temp->next = indexNode;
        }
        n--;
        return;
        
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= n){
            return;
        }
        ListNode* temp = head;
        int i = 0;
        while(i<index - 1){
            if(temp->next != nullptr){
                temp = temp->next;
                i++;
            }
            else{
                break;
            }
        }
        if(i == index - 1 && temp->next != nullptr){
            temp->next = temp->next->next;
        }
        n--;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */