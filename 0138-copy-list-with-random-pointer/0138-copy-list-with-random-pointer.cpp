/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>m;                         //stores the list value and address of both original and copy of the ll  
            Node* newHead = new Node(head->val);             // first node of the copy ll 
            Node* oldtemp = head->next;                      //temp help travelling the ll                          
            Node* newtemp = newHead;                            //temp help travelling the ll 
            m[head] = newHead;                                  //stores the head and new head of old and copy ll in the map
            while(oldtemp != NULL){
                Node* copyNode = new Node(oldtemp->val);        // copying the values of old ll and adding into copy ll
                m[oldtemp] = copyNode;                          // storing values of both ll in the map
                newtemp->next = copyNode;                       // creation of next node of the ll 
                oldtemp = oldtemp->next;                        //updating temp
                newtemp = newtemp->next;                        //updating temp
            }
            oldtemp = head, newtemp = newHead;                  //reinitialising the temps to the start of each ll to travel them again
            while(oldtemp != NULL){
                newtemp->random = m[oldtemp->random];           // extract the address of nodes from the map and stores them into random connnections of the copy ll
                oldtemp = oldtemp->next;                        //updating temp
                newtemp = newtemp->next;                        //updating temp
            }
            return newHead;
    }
};