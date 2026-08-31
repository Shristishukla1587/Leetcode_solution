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
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int index = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        
        while (curr != nullptr && curr->next != nullptr) {
            
            ListNode* next = curr->next;
            
            // Check if current node is a critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first == -1) {
                    first = index;
                } else {
                    minDist = min(minDist, index - last);
                }
                
                last = index;
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        // Less than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }
        
        return {minDist, last - first};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna