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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        while(count < k){                                       //checks if k nodes exist
            if(temp == NULL){
                return head;
            }
            temp= temp->next;
            count++;
        }

        ListNode* newNext = reverseKGroup(temp,k);              //recursively reverse the rest of ll 

        temp = head,count = 0;
        while(count < k){                                       //reverse the current group till the k group
            ListNode* storer = temp->next;                      //stores the address of the temp->next so that it remains saved
            temp->next = newNext;                               //updating the temp->next to the newNext  
            newNext = temp;                                     //updating newNext
            temp = storer;                                      //updating the temp 
            count++;                                            //updating count
        }
        return newNext;
    }
};



