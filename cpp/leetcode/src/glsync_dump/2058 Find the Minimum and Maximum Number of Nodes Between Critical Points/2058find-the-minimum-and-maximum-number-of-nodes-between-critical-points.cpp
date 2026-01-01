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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstPosition = 0, lastPosition = 0, currInd = 1;
        int minDistance = std::numeric_limits<int>::max(), maxDistance = 0;
        ListNode *prev = head, *curr = head->next;
        if (!curr || !curr->next) {
            return {-1, -1};
        }

        ListNode *next = curr->next;

        while (next) {
            if ((prev->val < curr->val && next->val < curr->val) || (prev->val > curr->val && next->val > curr->val)) {
                if (firstPosition == 0) {
                    firstPosition = currInd;
                    lastPosition = currInd;
                } else {
                    minDistance = min(minDistance, currInd - lastPosition);
                    lastPosition = currInd;
                }
            }
            ++currInd;
            prev = curr;
            curr = next;
            next = next->next;
        }

        // too small or not found local extremas
        if (currInd < 3 || minDistance == std::numeric_limits<int>::max() && maxDistance == 0) {
            return {-1, -1};
        }

        maxDistance = lastPosition - firstPosition;
        return {minDistance, maxDistance};

    }
};