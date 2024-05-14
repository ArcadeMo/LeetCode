#include <iostream>

using namespace std;

// Singly-linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize prev to nullptr
        ListNode* prev = nullptr;
        // Start with current as the head of the list
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* next = current->next; // Save the next node
            current->next = prev;           // Reverse the current node's pointer
            prev = current;                 // Move prev to current
            current = next;                 // Move current to next
        }

        // Prev will be pointing to the new head of the reversed list at the end of the while loop
        return prev;
    }
};

// Print List Function 
void printList(ListNode* head) {
    ListNode* tmp = head;
    while (tmp != nullptr) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    // Create a Linked List 
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    cout << "The original linked list: ";
    printList(head);

    ListNode* reversedHead = solution.reverseList(head);
    cout << "The reversed linked list: ";
    printList(reversedHead);

    return 0;
}