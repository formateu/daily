#include <unordered_map>
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* null = new ListNode(0, head);
        std::unordered_map<int, ListNode*> prefixSumMap;
        int prefixSum = 0;

        for (ListNode* node = null; node; node = node->next) {
            prefixSum += node->val;
            prefixSumMap[prefixSum] = node;
        }

        prefixSum = 0;
        for (ListNode* node = null; node; node = node->next) {
            prefixSum += node->val;
            ListNode* nextSumNode =  prefixSumMap[prefixSum];
            node->next = nextSumNode ? nextSumNode->next : nullptr;
        }

        return null->next;
    }
};