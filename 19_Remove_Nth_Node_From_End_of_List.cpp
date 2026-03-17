/*

Approach: Two Pointers
1. We will use two pointers, slow and fast, to traverse the linked list. Both pointers will start at the head of the list.
2. We will move the fast pointer n steps ahead in the list. This will create a gap of n nodes between the slow and fast pointers.
3. If the fast pointer reaches the end of the list (NULL) after moving n steps, it means we need to remove the head node. In this case, we will return the next node of the head as the new head of the list.
4. If the fast pointer does not reach the end, we will continue moving both pointers (slow and fast) one step at a time until the fast pointer reaches the end of the list. At this point, the slow pointer will be at the node just before the node we want to remove.
5. We will then adjust the next pointer of the slow node to skip the node to be removed and point to the next node after it. Finally, we will delete the node to be removed to free up memory.
Time Complexity: O(L), where L is the length of the linked list, because we are traversing the list at most twice (once to move the fast pointer and once to move both pointers).
Space Complexity: O(1), because we are using only a constant amount of extra space for the pointers.

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
#include <iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        int cnt = 0;
        while(cnt < n){
            fast = fast->next;
            cnt++;
        }

        if (fast == NULL) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        while(fast != NULL){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
        return head;

    }
};
int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    ListNode* result = s.removeNthFromEnd(head, n);
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 1 2 3 5
    return 0;
}