/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {             //slow fast approach used
        ListNode* slow = head;
        ListNode* fast = head;

        bool isCycle = false;                           // check if a cycle exist

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;                                  //cycle found
            }
        }
        if(!isCycle){                                   // if cycle is not found
            return NULL;
        }
        slow = head;                                    // again initialising slow with head to find the point at which the cycle starts
        while(slow != fast){                            // the cycle starts at at a point at which slow == fast 
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

        
    }
};