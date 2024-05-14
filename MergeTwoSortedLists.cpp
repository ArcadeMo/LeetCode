#include <iostream>
#include <vector>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the start of the merged list 
        ListNode* dummy = new ListNode();
        // Create a current pointer that will traverse and build a new list
        ListNode* current = dummy;

        // Traverse both lists until we reach the end of one of the lists
        while (list1 != nullptr && list2 != nullptr) {
            // Compare the current nodes of the lists
            if (list1->val < list2->val) {
                // If list1's node is smaller, attach it the merged list first
                current->next = list1;
                // Move list1 to the next node
                list1 = list1->next;
            } else {
                // If list2's node is a smaller or equal, attach it to the merged list first
                current->next = list2;
                // Move list2 to the next node
                list2 = list2->next;
            }
            // Move the current pointer to the next node in the merged list
            current = current->next;
        }

        // One of the lists would be exhausted so now attach the remaining nodes of the other list to the merged list
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // The merged list will start at the next node of the dummy node
        ListNode* mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Test case 1
    vector<int> values1 = {1, 2, 4};
    vector<int> values2 = {1, 3, 4};
    ListNode* list1 = createList(values1);
    ListNode* list2 = createList(values2);
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    cout << "Merged list 1: ";
    printList(mergedList);

    // Test case 2
    values1 = {};
    values2 = {};
    list1 = createList(values1);
    list2 = createList(values2);
    mergedList = solution.mergeTwoLists(list1, list2);
    cout << "Merged list 2: ";
    printList(mergedList);

    // Test case 3
    values1 = {};
    values2 = {0};
    list1 = createList(values1);
    list2 = createList(values2);
    mergedList = solution.mergeTwoLists(list1, list2);
    cout << "Merged list 3: ";
    printList(mergedList);

    return 0;
}