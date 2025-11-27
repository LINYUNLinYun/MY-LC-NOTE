#include <iostream>
#include <vector>

using namespace std;

/**单链表结构实现 */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}; 
    ListNode(int x) : val(x), next(nullptr){}; 
    ListNode(int x, ListNode* ptr) : val(x), next(ptr){}; 
};


/**
 * Definition for singly-linked list.
 *     int val;
 * struct ListNode {
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* beginNode = new ListNode(-1, head);     //分配一个前向头，指向head
        ListNode* nowNode = beginNode;     //分配一个前向头，指向head
        while(nowNode->next != nullptr){
            if(nowNode->next->val == val){
                // 如果当前节点的指向（循环开始时指向head）的val符合，指向跳过他
                nowNode->next = nowNode->next->next;
            }
            else{
                // 如果不符合，当前指向移动到下一个
                nowNode = nowNode->next;
            }
        }
        return beginNode->next;
    }
};

int main(int argc, char const *argv[]) {
//   cout << "hello wrold" << endl;
    Solution s;
    ListNode* n = nullptr;
    ListNode* n1 = s.removeElements(n, 1);
    cout<< n1->val <<endl;
    return 0;
}

