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
        if(head == nullptr)
            return nullptr;
        ListNode* nodePrev = head;
        ListNode* nodeNext = head->next;
        nodePrev->next = nullptr;
        while(nodeNext){
            ListNode* temp = nodeNext;
            nodeNext = nodeNext->next;
            temp->next = nodePrev;
            nodePrev = temp;
        }
        return nodePrev;
    }
};
