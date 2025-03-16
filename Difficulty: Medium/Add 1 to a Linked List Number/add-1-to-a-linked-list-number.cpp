//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

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
  
    Node* reverseLL(Node* head) {
        Node* temp = head;
        Node* prev = nullptr;
        Node* front = head->next;
        
        while(temp) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        
        return prev;
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int hasCarry = 1;
        Node* newHead = reverseLL(head);
        Node* temp = newHead;
        
        while(temp && hasCarry) {
            
            if(temp->data == 9) {
                temp->data = 0;
                hasCarry = 1;
            }
            
            else {
                temp->data = temp->data+1;
                hasCarry = 0;
            }
            
            temp = temp->next;
        }
        
        if(hasCarry) {
            head->next = new Node(1);
            head = head->next;
        }
        
        return reverseLL(newHead);
        
    }
};


//{ Driver Code Starts.

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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends