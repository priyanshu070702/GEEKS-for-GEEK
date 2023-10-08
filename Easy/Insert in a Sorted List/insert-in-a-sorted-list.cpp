//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int data) {
    Node* temp = head;
    Node* prev = nullptr; // To keep track of the previous node

    // Find the correct position to insert the new node
    while (temp != nullptr && data > temp->data) {
        prev = temp;
        temp = temp->next;
    }

    // Create the new node
    Node* newNode = new Node(data);

    // Insert the new node at the beginning of the list
    if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
    } else { // Insert the new node in the middle or at the end of the list
        newNode->next = temp;
        prev->next = newNode;
    }

    return head;
}

};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends