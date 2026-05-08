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
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if (head == NULL || head->next == NULL)
//             return;

//         // Step 1: convert linked list to array
//         vector<int> arr;
//         ListNode* temp = head;
//         while (temp != NULL) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }

//         // Step 2: reorder array
//         vector<int> result;
//         int i = 0, j = arr.size() - 1;

//         while (i < j) {
//             result.push_back(arr[i++]);
//             result.push_back(arr[j--]);
//         }
//         if (i == j)  // middle element (odd length)
//             result.push_back(arr[i]);

//         // Step 3: copy reordered values back to linked list
//         temp = head;
//         int k = 0;
//         while (temp != NULL) {
//             temp->val = result[k++];
//             temp = temp->next;
//         }
//     }
// };





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
private:
    ListNode* find_mid(ListNode* head){
        if (head == NULL)
             return NULL;

         ListNode*slow = head;
         ListNode*fast = head;
      while(fast!=NULL && fast->next !=NULL){
      slow = slow->next;
      fast = fast->next->next;
       }
   return slow;
    }

    ListNode* reverse_list(ListNode* head){
        ListNode*prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode*forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
   //find the midpoint
    ListNode*midpoint = find_mid(head);
    ListNode*forward = midpoint->next;
    midpoint->next = NULL;
   //reverse the second half
    forward = reverse_list(forward);
   //join both lined list
      ListNode* curr1 = head;
ListNode* curr2 = forward;

while (curr1 != NULL && curr2 != NULL) {
    ListNode* next1 = curr1->next;
    ListNode* next2 = curr2->next;

    curr1->next = curr2;          // attach node from second list

    if (next1 == NULL)            // if first list ends
        break;

    curr2->next = next1;          // attach back to first list

    curr1 = next1;
    curr2 = next2;
}

     

   
        
    }
};
