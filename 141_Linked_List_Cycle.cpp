/*

Approach Used:
1. We can use the Floyd’s Cycle Detection Algorithm, also known as the Tortoise and Hare algorithm.
2. We will maintain two pointers, one slow pointer (tortoise) that moves one step at a time, and one fast pointer (hare) that moves two steps at a time.
3. If there is no cycle, the fast pointer will reach the end of the list (NULL) before the slow pointer.
4. If there is a cycle, the fast pointer will eventually meet the slow pointer within the cycle.
5. Once we detect a cycle, we can reset one pointer to the head of the list and keep the other pointer at the meeting point. Move both pointers one step at a time until they meet again. The point at which they meet will be the start of the cycle.

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast != slow){
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            slow = slow->next;
            fast=fast->next->next;
        }
        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
int main() {
    // Create a linked list with a cycle for testing
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    head->next = second;
    second->next = third;
    third->next = second; // Creates a cycle

    Solution solution;
    bool result = solution.hasCycle(head);
    cout << "Does the linked list have a cycle? " << (result ? "Yes" : "No") << endl;

    // Clean up memory (in a real application, you would want to handle this more carefully)
    delete head;
    delete second;
    delete third;

    return 0;
}


