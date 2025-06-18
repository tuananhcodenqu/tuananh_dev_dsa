#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* makenode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void pushfront(Node*& head, int x){
    Node* temp = makenode(x);
    temp->next = head;
    head = temp;
}
void pushback(Node*& head, int x){
    if(head==NULL) pushfront(head,x);
    else{
        Node* last = makenode(x);
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
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
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* reverseBetween(Node* head, int h, int k){
    if(h==k) return head;
    Node* start = NULL, * end = NULL;
    Node* prev_s = NULL, * e_next = NULL;
    Node* curr = head;
    int i = 1;
    while(curr != NULL && i<=k ){
        if(i<h) prev_s=curr;
        if(i==h) start=curr;
        if(i<=k){
            end = curr;
            e_next = curr->next;
        }
        curr=curr->next;i++;
    }
    end->next = NULL;
    end = Reverse(start);
    if(prev_s){
        prev_s->next=end;
    }else head = end;
    start->next = e_next;
    return head;
}
int main(){
    Node* head = NULL;int n;cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        pushback(head,a[i]);
    }
    int h,k; cin >> h >> k;
    head = reverseBetween(head,h,k);
    print(head);
    return 0;
}
