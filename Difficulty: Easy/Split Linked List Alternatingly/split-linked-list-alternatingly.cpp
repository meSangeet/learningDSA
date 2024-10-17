//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
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

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
    Node* evenHead = NULL, *evenTail = NULL;
    Node* oddHead = NULL, *oddTail = NULL;
    
    Node* current = head;
    int index = 0;  // To track even or odd position

    // Traverse the original list
    while (current != NULL) {
        // Create a new node with the current data
        Node* newNode = new Node(current->data);

        if (index % 2 == 0) {  // Even index
            if (evenHead == NULL) {
                evenHead = evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        } else {  // Odd index
            if (oddHead == NULL) {
                oddHead = oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        }

        // Move to the next node and update the index
        current = current->next;
        index++;
    }
    
    // Return both sub-lists as a vector
    return {evenHead, oddHead};
    
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends