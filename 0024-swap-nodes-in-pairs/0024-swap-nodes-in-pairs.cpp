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
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL){             //checks if the ll is empty or a single unit
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = NULL;        

        while(first != NULL && second != NULL){
            ListNode* third = second->next;

            second->next = first;                               //re estabilishing connections
            first->next = third;                                //re estabilishing connections
            if(prev != NULL){                                   //this means that the first is not the head    
                prev->next = second;
            }else{                                              //this means that first is the head
                head = second;
            }

            //updating the variables for the next pair
            prev = first;           
            first = third;
            if(third != NULL){                                  //this means there are more elements in the ll
                second = third->next;
            }else{
                second = NULL;                                  //no more elements in the ll                
            }
        }
        return head;
    }   
};