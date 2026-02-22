/*

Approach:
1. We will use a pointer to traverse the linked list.
2. We will compare the current node's value with the next node's value.
3. If they are the same, we will delete the next node and update the current node's next pointer to skip the duplicate node.
4. If they are different, we will move the current pointer to the next node.
Time Complexity: O(n), where n is the number of nodes in the linked list.

*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;c
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head;
        while(curr->next != NULL){
            if(curr->val == curr->next->val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    Solution s;
    ListNode* ans = s.deleteDuplicates(head);
    while(ans != NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    return 0;
}



/*

void RemoveDuplicate(Node* &head){
    if(head == NULL){
        cout<<"No duplicate"<<endl;
        return;
    }
    Node* curr = head;
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else{
            curr = curr;
            curr = curr->next;
        }
    }
}

*/