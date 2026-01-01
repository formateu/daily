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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());

        ListNode* prev = nullptr, *curr = head;

        while (curr != nullptr) {
            if (nums_set.contains(curr->val)) {
                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};