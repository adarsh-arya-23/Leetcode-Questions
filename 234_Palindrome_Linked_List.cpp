/*

Approach Used:- 234. Palindrome Linked List
-> We can solve this problem by finding the middle of the linked list, reversing the second half of the linked list, and then comparing the first half with the reversed second half.
-> The time complexity of this approach is O(n) because we need to traverse the linked list a few times (to find the middle, reverse the second half, and compare).
-> The space complexity is O(1) because we are reversing the linked list in place and not using any extra space for data structures.
-> The algorithm can be implemented as follows:
    1. Use the fast and slow pointer technique to find the middle of the linked list.
    2. Reverse the second half of the linked list starting from the middle.
    3. Compare the first half of the linked list with the reversed second half. If they are the same, then the linked list is a palindrome; otherwise, it is not.

*/

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void Reverse(ListNode*& head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Reverse(slow);
        ListNode* ctr = head;
        while (slow != NULL) {
            if (slow->val != ctr->val) {
                return false;
            }
            ctr = ctr->next;
            slow = slow->next;
        }
        return true;
    }
};
int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << s.isPalindrome(head) << endl; // Output: 1 (true)
    return 0;
}