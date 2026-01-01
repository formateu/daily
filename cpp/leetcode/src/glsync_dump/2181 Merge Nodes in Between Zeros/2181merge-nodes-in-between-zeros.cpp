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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *out = new ListNode(), *curr = out;
        int sum = 0, zeroCnt = 0;

        while (head) {
            if (head->val == 0) {
                ++zeroCnt;

                if (zeroCnt == 2) {
                    if (out->val == 0) {
                        out->val = sum;
                    } else {
                        ListNode* newNode = new ListNode(sum);
                        curr->next = newNode;
                        curr = newNode;
                    }
                    zeroCnt = 1;
                    sum = 0;
                }
            } else {
                sum += head->val;
            }

            head = head->next;
        }

        return out;
    }
};