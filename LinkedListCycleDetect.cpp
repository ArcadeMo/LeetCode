#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Check if there is no nodes or only one node since neither can have a cycle
        if (head == nullptr || head->next == nullptr) {
            return false; 
        }

        ListNode* slow = head; // Tortoise pointer
        ListNode* fast = head; // Hare pointer

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
};

// Helper function to create a cycle in the list for testing
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* cycleNode = nullptr;
    ListNode* tail = head;
    int index = 0;
    while (tail->next != nullptr) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    tail->next = cycleNode;
}

// Function to print whether a cycle exists in the list
void testHasCycle(Solution& solution, ListNode* head) {
    if (solution.hasCycle(head)) {
        cout << "Cycle detected in the list." << endl;
    } else {
        cout << "No cycle in the list." << endl;
    }
}

int main() {
    Solution solution;

    // Example 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    createCycle(head1, 1);
    cout << "Test case 1: ";
    testHasCycle(solution, head1);

    // Example 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    createCycle(head2, -1);
    cout << "Test case 2: ";
    testHasCycle(solution, head2);

    return 0;
}
