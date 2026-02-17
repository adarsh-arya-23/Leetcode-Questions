#include <iostream>
#include <vector>

// 1. Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2. Your fixed Solution class
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while(curr != nullptr){
            next = curr->next;  // Save next node
            curr->next = prev;  // Reverse pointer
            prev = curr;        // Move prev forward
            curr = next;        // Move curr forward
        }
        return prev; // prev is the new head
    }
};

// 3. Utility function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

// 4. Main function to execute the code
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);

    std::cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    std::cout << "Reversed List: ";
    printList(reversedHead);

    // Clean up memory (optional but good practice)
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
