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
void RearrangeEvenOdd(Node*& head){
    // even: chẵn, odd: lẻ
  if(head == NULL) return;
  Node* odd= head;
  Node*even = head->next;
  Node* evenFirst = even;
  while(1){
    if(!odd || !even || !(even->next)){
        odd->next = evenFirst;
        break;
    }
    odd->next = even->next;
    odd = even->next;
    if(odd->next == NULL){
        even->next = nullptr;
        odd->next = evenFirst;
        break;
    }
    even->next = odd->next;
    even = odd->next;
  }
}
int main(){
    Node*head =NULL;
    int n;cin>>n;
    int*a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        pushback(head,a[i]);
    }
    RearrangeEvenOdd(head);
    print(head);
}
