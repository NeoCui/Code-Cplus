#include<iostream>

using namespace std;

struct LNode{
	int value;
	LNode* next;
	LNode(int x):value(x),next(NULL){
		cout<<"Initialization complete."<<endl;
	}
};

LNode* addNode(LNode* end, int val){
	LNode* temp=new LNode(0);
	temp->value=val;
	end->next=temp;
	end=temp;
	return end;
}

 LNode* Reverse(LNode* head){
	if(head==NULL){
		return NULL;
	}
	LNode* prev=head;
	LNode* pcur=head;
	LNode* end;
	while(pcur!=NULL && pcur->next!=NULL){
		end=prev;
		prev=prev->next;
		pcur=pcur->next->next;
	}
	pcur=prev->next;
	LNode* temp;
	prev->next=NULL;
	while(pcur!=NULL){
		temp=pcur->next;
		pcur->next=prev;
		prev=pcur;
		pcur=temp;
	}
	end->next=prev;
	return head;
}

int main(){
	LNode* head=new LNode(1);
	LNode* end=head;
	end=addNode(end, 2);
	end=addNode(end, 3);
	end=addNode(end, 4);
	end=addNode(end, 5);
	addNode(end, 6);
	end=head;
	
	end=Reverse(head);
	while(end->next!=NULL){
		cout<<end->value<<"->";
		end=end->next;
	}
	cout<<end->value<<endl;
return 0;
}
