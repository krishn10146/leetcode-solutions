/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){                               //if the list is empty
            return head;
        }
        Node* curr = head;                              // currr travels the ll
        while(curr != NULL){                            
            if(curr->child != NULL){                    // to find if the node has a child node
                Node* temp = curr->next;                // storing the address of next of the curr (which also have a child) to a temp node
                curr->next = flatten(curr->child);      //changing the curr->next to the flattened ll of the child
                curr->next->prev = curr;                // creating the relation of next and prev as it is a doubly ll
                curr->child = NULL;                     // now the child ll is flattened so the child points to a NULL value

                while(curr->next != NULL){              //finding the tail in the child ll to connect it to the original ll
                    curr = curr->next;                  
                }
                
                if(temp != NULL){                       //attaching the tail to the temp pointer
                    curr->next = temp;                  // temp pointer stores the remaining nodes of the og ll
                    temp->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};