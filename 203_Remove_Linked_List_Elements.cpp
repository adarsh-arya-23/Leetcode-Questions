/*

Approach:
1. Create a dummy node that points to the head of the list. This helps handle edge cases where the head node itself needs to be removed.
2. Use two pointers, `prev` and `curr`, to traverse the list. `prev` will always point to the last node that is not removed, while `curr` will be used to check each node's value.
3. If `curr->val` is equal to the target value `val`, update `prev->next` to skip the current node, effectively removing it from the list. Otherwise, move `prev` to point to `curr`.
4. Move `curr` to the next node in each iteration.
5. After the loop, return `dummy->next` as the new head of the modified list, and delete the dummy node to free memory.
Time Complexity: O(n), where n is the number of nodes in the linked list, since we need to traverse the entire list once.
Space Complexity: O(1), since we are using only a constant amount of extra space for the dummy node and pointers.

*/

#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution solution;
    int valToRemove = 6;
    ListNode* newHead = solution.removeElements(head, valToRemove);

    ListNode* current = newHead;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    current = newHead;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}