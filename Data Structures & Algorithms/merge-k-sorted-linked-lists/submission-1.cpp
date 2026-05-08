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
//  class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {

//         // Step 1: convert all lists to array
//         vector<int> arr;
//         for (ListNode* head : lists) {
//             while (head != NULL) {
//                 arr.push_back(head->val);
//                 head = head->next;
//             }
//         }

//         // Step 2: sort array
//         sort(arr.begin(), arr.end());

//         // Step 3: convert array to linked list
//         if (arr.size() == 0)
//             return NULL;

//         ListNode* head = new ListNode(arr[0]);
//         ListNode* tail = head;

//         for (int i = 1; i < arr.size(); i++) {
//             tail->next = new ListNode(arr[i]);
//             tail = tail->next;
//         }

//         return head;
//     }
// };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //min heap - node value, node pointer, by default max heap , we need to make min heap here to get minimum element
      priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
      // Push head of each list
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL) {
            pq.push({lists[i]->val, lists[i]});
        }
    }

    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    // Extract min and push next node
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        if (it.second->next != NULL) {
            pq.push({it.second->next->val, it.second->next});
        }

        temp->next = it.second;
        temp = temp->next;
    }

    return dummyNode->next;
        
    }
};
