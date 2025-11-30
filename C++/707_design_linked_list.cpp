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
        //哨兵节点，并无实际值，所以给-1
        head = new ListNode(-1);
        n = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= n){
            return -1;
        }
        ListNode* temp = head;
        int i = 0;
        while(i<index + 1){
            temp = temp->next;
            i++;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
        return;
    }
    
    void addAtTail(int val) {
        addAtIndex(n, val);
        return;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > n){
            return;
        }
        ListNode* temp = head;
        int i = 0;
        while(i<index){
            temp = temp->next;
            i++;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;

        n++;
        return;
        
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= n || n == 0){
            return;
        }
        ListNode* temp = head;
        int i = 0;
        while(i<index){
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
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