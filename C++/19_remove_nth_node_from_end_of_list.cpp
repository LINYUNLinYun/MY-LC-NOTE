#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //哨兵节点
        ListNode* sentinal = new ListNode(-1);
        sentinal->next = head;
        vector<ListNode*> temp(31);
        temp[0] = sentinal;
        int length = 0;
        while(head!=nullptr){
            temp[length+1] = head;
            length++;
            head = head->next;
        }
        //删除倒数第n个
        temp[length - n]->next = temp[length - n]->next->next;
        return temp[0]->next;

    }
};

int main(int argc, char const *argv[]) {
  cout << "hello wrold" << endl;
  return 0;
}

