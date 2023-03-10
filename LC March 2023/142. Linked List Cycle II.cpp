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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        // Initializing the pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        // 1. To find the cycle in the ll
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next ;
            fast = fast->next->next;

        // 2. To find the starting point of the cycle in the ll
            if(slow == fast){
                // It means there is a cycle in the ll
                while(entry != slow){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry; 
                // return slow; // both are correct since slow and entry both are pointing to the starting point of ll
            }
        }
        return NULL;
    }
};

/* 
142. Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/
