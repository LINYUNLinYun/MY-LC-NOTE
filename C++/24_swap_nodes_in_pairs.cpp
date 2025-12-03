#include <iostream>
#include <vector>
using namespace std;

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

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* currPairHead = nullptr;
        ListNode* currPairTail = nullptr;
        ListNode* prePairTail = nullptr;
        ListNode* result = head;
        if(result == nullptr){
            return result;
        }
        if(result->next!=nullptr){
            result = result->next;
        }
        currPairHead = head;
        currPairTail = head -> next;
        //如果这个对的尾不为空，交换头尾
        while(currPairTail!=nullptr){
            currPairHead->next = currPairTail->next;
            currPairTail->next = currPairHead;
            // 上个对的尾指向当前交换完的对的头
            if(prePairTail!=nullptr){
                prePairTail->next = currPairTail;
            }
            //存储当前对的信息，移动到下个对
            prePairTail = currPairHead;
            currPairHead = currPairHead->next;
            // 如果当前对head空会报错
            if(currPairHead==nullptr){
                break;
            }
            currPairTail = currPairHead->next;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
  cout << "hello wrold" << endl;
  return 0;
}

