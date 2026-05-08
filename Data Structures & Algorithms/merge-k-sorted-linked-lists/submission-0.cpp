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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Step 1: convert all lists to array
        vector<int> arr;
        for (ListNode* head : lists) {
            while (head != NULL) {
                arr.push_back(head->val);
                head = head->next;
            }
        }

        // Step 2: sort array
        sort(arr.begin(), arr.end());

        // Step 3: convert array to linked list
        if (arr.size() == 0)
            return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* tail = head;

        for (int i = 1; i < arr.size(); i++) {
            tail->next = new ListNode(arr[i]);
            tail = tail->next;
        }

        return head;
    }
};
