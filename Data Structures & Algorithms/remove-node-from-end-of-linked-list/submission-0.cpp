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
   ListNode* deleteNode(int count, ListNode*&head){
    //delete first node
    if(count == 1){
        ListNode*temp = head;
        head = head->next;
        //memory free start node
        temp->next = NULL;
        delete temp;
    }
    else{
        ListNode*curr = head;
        ListNode*prev = NULL;
        int cnt =1;
        while(cnt<count){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next =NULL;
        delete curr;
    }
   return head;
   }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int total_nodes = 0;
      ListNode*temp = head;
      while(temp != NULL){
        total_nodes++;
        temp = temp->next;
      }
      int count = (total_nodes - n) + 1;
      head = deleteNode(count,head);
        
    return head;
    }
};
