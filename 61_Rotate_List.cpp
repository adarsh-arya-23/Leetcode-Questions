/*

Approach:
1. First, we need to find the length of the linked list and also keep track of the last node.
2. Then, we can calculate the effective number of rotations needed by taking k modulo the length of the list.
3. If the effective rotations is 0, we can return the head as it is.
4. Otherwise, we can connect the last node to the head to form a circular linked list.
5. Next, we need to find the new tail of the list, which will be at the position (length - k - 1) from the head.
6. We can then set the new head to be the next node of the new tail and break the circular link by setting the next of the new tail to NULL.
Time Complexity: O(n) where n is the number of nodes in the linked list.

*/

#include <iostream>
#include <vector>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* curr = head;
        int len = 1;
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }
        k = k % len;
        if (k == 0) return head;
        curr->next = head;

        ListNode* temp = head;
        int stepsToNewTail = len - k - 1;

        while(stepsToNewTail > 0){
            temp = temp->next;
            stepsToNewTail--;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = sol.rotateRight(head, k);

    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
/*Rotate List*/
