/*

Appraoch:
1. We create a dummy node to simplify the process of building the result linked list.
2. We initialize a carry variable to handle sums that exceed 9.
3. We iterate through both linked lists simultaneously, adding corresponding nodes along with the carry.
4. If one linked list is shorter, we continue adding the remaining nodes of the longer list along with the carry.
5. If there's a carry left after processing both lists, we add a new node with the carry value.
Time Complexity: O(max(m, n)), where m and n are the lengths of the two linked lists.
Space Complexity: O(max(m, n)) for the new linked list that we create to store the result.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); 
        ListNode* l3 = dummy; 
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            l3->next = new ListNode(sum % 10);
            
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remaining = (l1 != nullptr) ? l1 : l2;
        while(remaining != nullptr) {
            int sum = remaining->val + carry;
            carry = sum / 10;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            remaining = remaining->next;
        }
        if(carry > 0) {
            l3->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}