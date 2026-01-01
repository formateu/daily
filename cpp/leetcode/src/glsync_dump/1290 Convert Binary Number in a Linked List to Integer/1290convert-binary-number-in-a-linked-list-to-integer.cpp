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
    int getDecimalValue(ListNode* head) {
        int currentPower = 1;
        return recursiveBuild(head, currentPower);
    }

    int recursiveBuild (ListNode* curr, int &currentPower) {
        int val = curr->next ? recursiveBuild(curr->next, currentPower) : 0;
        if (curr->val) {
            val += currentPower* curr->val;
        }
        currentPower *= 2;

        return val;
    }
};