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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> map;
        while (headA)
        {
            map[headA]++;
            headA = headA->next;
        }
        while (headB)
        {
            if(map.count(headB)){
                return headB;
            }
            headB = headB->next;
            
        }
        
        return nullptr;
    }
};

int main(int argc, char const *argv[]) {
  cout << "hello wrold" << endl;
  return 0;
}

