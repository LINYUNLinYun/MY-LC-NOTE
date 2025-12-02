#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = nullptr;
        while(preNode != nullptr){
            nextNode = currNode->next;  // 0 1 0 -> 0 1 2
            currNode->next = preNode;   // 
            preNode = currNode;         // 1 1 2
            currNode = nextNode;        // 1 2 2
        }
        return preNode;
    }
};


int main(int argc, char const *argv[]) {
  cout << "hello wrold" << endl;
  return 0;
}
