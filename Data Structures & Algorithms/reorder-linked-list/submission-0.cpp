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


      //brute force
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // Step 1: convert linked list to array
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: reorder array
        vector<int> result;
        int i = 0, j = arr.size() - 1;

        while (i < j) {
            result.push_back(arr[i++]);
            result.push_back(arr[j--]);
        }
        if (i == j)  // middle element (odd length)
            result.push_back(arr[i]);

        // Step 3: copy reordered values back to linked list
        temp = head;
        int k = 0;
        while (temp != NULL) {
            temp->val = result[k++];
            temp = temp->next;
        }
    }
};
