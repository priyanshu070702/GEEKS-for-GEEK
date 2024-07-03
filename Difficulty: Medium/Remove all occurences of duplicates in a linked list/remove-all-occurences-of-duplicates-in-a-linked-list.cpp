//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
         if (!head) return nullptr;

    unordered_map<int, int> freq;
    Node* temp = head;

    // Count the frequency of each element in the list
    while (temp) {
        freq[temp->data]++;
        temp = temp->next;
    }

    // Create a dummy node to handle edge cases easily
    Node dummy(0);
    Node* newHead = &dummy;
    Node* current = newHead;

    temp = head;

    // Traverse the list again and only keep elements with a frequency of 1
    while (temp) {
        if (freq[temp->data] == 1) {
            current->next = new Node(temp->data);
            current = current->next;
        }
        temp = temp->next;
    }

    return newHead->next;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends