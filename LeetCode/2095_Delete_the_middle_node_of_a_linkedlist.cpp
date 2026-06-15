/*
LeetCode 2095 - Delete the Middle Node of a Linked List

Idea:
- If the list contains only one node, return NULL.
- Use two pointers:
    slow -> moves 1 step
    fast -> moves 2 steps
- Maintain a prev pointer to the node before slow.
- When fast reaches the end, slow points to the middle node.
- Remove the middle node using:
    prev->next = slow->next

Time Complexity: O(n)
Space Complexity: O(1)

Concepts Used:
- Linked List
- Two Pointers (Slow & Fast)
*/

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* marker = NULL;
        while (fast != NULL && fast->next != NULL) {
            marker = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        marker->next = slow->next;
        delete (slow);
        return head;
    }
};

/*
//Alternative Approach

    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            ListNode* temp=head->next;
            head->next=NULL;
            delete temp;
            return head;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
*/
