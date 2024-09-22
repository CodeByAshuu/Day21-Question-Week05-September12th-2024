#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void createCycle(Node* head, int pos) {
    if (pos == -1) {
        return;
    }

    Node* temp = head;
    Node* cycleNode = nullptr;
    int index = 0;

    while (temp->next != nullptr) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }

    temp->next = cycleNode;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

    int pos = 1;
    createCycle(head, pos);

    if (hasCycle(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
