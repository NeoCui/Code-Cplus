#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* addList(ListNode* l1, ListNode* l2, int carry){
	if(l1==NULL && l2==NULL && carry==0)
		return NULL;
	ListNode* result = new ListNode(0);
	int value=carry;
	if(l1!=NULL){
		value+=l1->val;
	}
	if(l2!=NULL){
		value+=l2->val;
	}
	result->val=value%10;
	ListNode* more=addList(l1==NULL ? NULL:l1->next,
								l2==NULL ? NULL:l2->next,
								value>=10 ? 1:0);
	result->next=more;
	return result;
}

int main(){
	ListNode* head1=new ListNode(6);
	ListNode* end1=head1;
	ListNode* head2=new ListNode(6);
	ListNode* end2=head2;
	int count=6;
	for(int i=0;i<3;++i){
		ListNode* temp=new ListNode(0);
		temp->val=--count;
		end1->next=temp;
		end1=temp;
	}
	count=6;
	for(int i=0;i<3;++i){
		ListNode* temp=new ListNode(0);
		temp->val=--count;
		end2->next=temp;
		end2=temp;
	}
	ListNode* ret;
	ret=addList(head1,head2,0);
	int len=0;
	while(ret->next!=NULL){
		cout<<ret->val;
		ret=ret->next;
		cout<<"("<<++len<<"):";
	}
	cout<<endl;

	cout<<"sizeof(int)"<<sizeof(char)<<endl;
	return 0;
}
