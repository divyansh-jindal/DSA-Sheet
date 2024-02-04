//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool isSmaller(string str1, string str2) { 
        int n1 = str1.length(), n2 = str2.length(); 
        if (n1 < n2) return true; 
        if (n2 < n1) return false; 
        for (int i = 0; i < n1; i++) 
            if (str1[i] < str2[i]) 
                return true; 
            else if (str1[i] > str2[i]) 
                return false; 
        return false; 
    }
    string findStringDiff(string str1,string str2){
        if(isSmaller(str1,str2))
            swap(str1,str2);
        string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end());  
    int carry = 0; 
   
    for (int i = 0; i < n2; i++) { 
        int sub=((str1[i] - '0') - (str2[i] - '0') - carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
    for (int i = n2; i < n1; i++) { 
        int sub = ((str1[i] - '0') - carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
    reverse(str.begin(), str.end()); 
    return str; 
}
    
    Node* subLinkedList(Node* head1, Node* head2) {
       Node* curr1=head1;Node* curr2=head2;
       string ans1="", ans2="";
       while(curr1!=NULL){
           char ch=curr1->data+'0';
           ans1+=ch;
           curr1=curr1->next;
       }
       ans1.erase(0, ans1.find_first_not_of('0'));//if leading zero then remove first
        while(curr2!=NULL){
           char ch=curr2->data+'0';
           ans2+=ch;
           curr2=curr2->next;
       }
       ans2.erase(0, ans2.find_first_not_of('0'));//if leading zero then remove first
     Node* newNode=new Node(0);
     if(ans1.size()==0 && ans2.size()==0)
        return newNode; 
    string str=findStringDiff(ans1,ans2);
    str.erase(0, str.find_first_not_of('0'));// removed leading zero from result
     
     if(str.size()==0) // after removing leading zero,it might be string having nothing
        return newNode; 
    Node* head=NULL;
    Node* curr=NULL;
        for(int i=0;i<str.size();i++){
          Node* newNode=new Node(str[i]-'0');// new node created here we converting into integer
          if(head==NULL){
              head=curr=newNode;
          }else{
              curr->next=newNode;
              curr=newNode;
          }
        }
          return head;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends