#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createnode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void pushfront(Node*& head, int x){
    Node* temp = createnode(x);
    temp->next = head;
    head = temp;
}
void pushback(Node*& head, int x){
    if(head == NULL){
        pushfront(head,x);
    }else{
        Node* last = createnode(x);
        Node* temp = head;
        while(temp->next !=NULL){
            temp=temp->next;
        }
        temp->next = last;
    }
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* Reverse(Node* head){
    Node*curr = head;
    Node* prev = NULL;
    while(curr !=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int countNode(Node*head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
void swapK(Node*& head, int k){
    int n = countNode(head);
    if(k==n) return;
    if(2*k+1==n) return;
    Node* x=head, * x_prev=NULL;
    for(int i=1;i<k;i++){
        x_prev = x;
        x=x->next;
    }
    Node* y = head, * y_prev=NULL;
    for(int i=1;i<n-k+1;i++){
        y_prev=y;
        y=y->next;
    }
    if(x_prev) x_prev->next=y;
    if(y_prev) y_prev->next=x;
    Node*temp = x->next;
    x->next = y->next;
    y->next = temp;
    if(k==1) head = y;
    if(k==n) head = x;
}
int main(){
    Node*head =NULL;
    int n;cin>>n;
    int*a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        pushback(head,a[i]);
    }
    int k;cin>>k;
    swapK(head,k);
    print(head);
}
