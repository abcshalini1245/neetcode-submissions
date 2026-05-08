// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {
// private:
//   ListNode* reverse_list(ListNode* head){
//         ListNode*prev = NULL;
//         ListNode* curr = head;
//         while(curr != NULL){
//             ListNode*forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         return prev;
//     }

//     void insertAtTail(struct ListNode* &ansHead, struct ListNode* &ansTail, int val){
//         ListNode*temp = new ListNode(val);
//         //empty list
//         if(ansHead == NULL){
//             ansHead = temp;
//             ansTail = temp;
//         }
//         else{
//             ansTail ->next = temp;
//             ansTail = temp;
//         }
//     }

//      ListNode* add( ListNode* l1,  ListNode* l2){
//         if (!l1 && !l2) return NULL; //IF BOTH LIST ARE EMPTY

//         int carry = 0;
//         ListNode* ansHead = NULL;
//         ListNode* ansTail = NULL;
//         while(l1 != NULL|| l2 !=NULL || carry !=0){
//             int val1 =0;
//             if(l1 != NULL){
//                 val1 = l1->val;
//             }
//             int val2 = 0;
//             if(l2 != NULL){
//                 val2 = l2->val;
//             }
//             int sum = carry + val1+ val2;
//             int digit = sum%10;
//             //create node for digit and insert at tail
//             insertAtTail(ansHead,ansTail,digit);

//             carry = sum/10;
//             if(l1 != NULL)
//               l1 =l1->next;
//             if(l2 != NULL)
//               l2 = l2->next;
//         }
//       return ansHead;
//     }
   
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         //step1 : reverse both list
//         l1 = reverse_list(l1);
//         l2  = reverse_list(l2);
//         //add two  LL
//         ListNode*ans = add(l1,l2);
//         //reverse ans
//         ans = reverse_list(ans);
//         return ans; 
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
    void insertAtTail(struct ListNode* &ansHead, struct ListNode* &ansTail, int val){
        ListNode*temp = new ListNode(val);
        //empty list
        if(ansHead == NULL){
            ansHead = temp;
            ansTail = temp;
        }
        else{
            ansTail ->next = temp;
            ansTail = temp;
        }
    }

     ListNode* add( ListNode* l1,  ListNode* l2){
        if (!l1 && !l2) return NULL; //IF BOTH LIST ARE EMPTY

        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        while(l1 != NULL|| l2 !=NULL || carry !=0){
            int val1 =0;
            if(l1 != NULL){
                val1 = l1->val;
            }
            int val2 = 0;
            if(l2 != NULL){
                val2 = l2->val;
            }
            int sum = carry + val1+ val2;
            int digit = sum%10;
            //create node for digit and insert at tail
            insertAtTail(ansHead,ansTail,digit);

            carry = sum/10;
            if(l1 != NULL)
              l1 =l1->next;
            if(l2 != NULL)
              l2 = l2->next;
        }
      return ansHead;
    }
   
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //add two  LL
        ListNode*ans = add(l1,l2);
        return ans; 
    }
};
