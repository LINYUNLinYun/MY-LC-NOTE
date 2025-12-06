#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //方法一
    // ListNode *detectCycle(ListNode *head) {
    //     ListNode* temp = head;
    //     unordered_map<ListNode*, int> nodeMap;
    //     while(temp){
    //         if(nodeMap.count(temp)){
    //             return temp;
    //         }
    //         nodeMap.insert({temp,1});
    //         temp = temp->next;  
    //     }
    //     return nullptr;
    // }
    // 方二
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ptr = nullptr;
        //如果环存在那是不会有空指针的
        while(slow!=nullptr && fast!= nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(ptr!=nullptr){
                ptr = ptr->next;
            }
            if (slow == fast && ptr == nullptr)
            {
                ptr = head;
            }
            if(ptr == slow){
                return ptr;
            }
            
        }
        return nullptr;
    }
};


int main(int argc, char const *argv[]) {
  cout << "hello wrold" << endl;
  return 0;
}

