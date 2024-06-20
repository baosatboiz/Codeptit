#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
		    this->next=nullptr;
		}
};
Node* addNewNode(Node* head,int data){
	if(head==nullptr) head = new Node(data);
	else{
		head->next=addNewNode(head->next,data);
	}
	return head;
}
void in(Node* head){
	if(head==nullptr) return;
	cout<<head->data<<" ";
	in(head->next);
}
Node* patrition(Node* start, Node* end,Node*& newHead){
	Node* pivot=start;
	Node* prevStore=start;
	Node* store =start->next;
	Node* cur=start->next;
	while(cur!=end->next){
		if(cur->data<pivot->data){
			int tmp = store->data;
			store->data=cur->data;
			cur->data=tmp;
			prevStore=store;
			store=store->next;
			
		}
		cur=cur->next;
	}
	int tmp = prevStore->data;
	prevStore->data=pivot->data;
	pivot->data=tmp;
	newHead=pivot;
	return prevStore;
}
Node* quicksort(Node* start,Node* end){
	if(start==nullptr||start==end) return start;
	Node* newHead=nullptr;
	Node* p = patrition(start,end,newHead);
	if(newHead!=p){
		Node* tmp = newHead;
		while(tmp->next!=p) tmp=tmp->next;
		tmp->next=nullptr;
	quicksort(start,tmp);
	tmp->next=p;
	}
	quicksort(p->next,end);
	return newHead;
}
Node* getLastNode(Node* head){
	while(head->next!=nullptr) head=head->next;
	return head;
}
int main(){
      int n; cin>>n;
      Node* head = nullptr;
      for(int i=0;i<n;i++){
      	  int x; cin>>x;
      	  head=addNewNode(head,x);
	  }
	  head=quicksort(head,getLastNode(head));
	  in(head);
}
