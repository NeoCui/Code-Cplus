/*algorithm.cpp: record of my study of c++*/
#include<iostream>
#include<string>
#include<cmath>

using namespace std;
#define MAX 100000

//single directional chain list
struct Node{
	int data;
	Node* next;
};
//output for big data multiplication begin
void output(Node* head){
	if(!head->next && !head->data)
		return;
	output(head->next);
	cout<<head->data;
}//output end
//reverse char begin
char* strrev(char* str){
	if(!str)
		return NULL;
	int len = strlen(str);
	char ctemp;
	for(int i=0; i<ceil(len/2); ++i){
		ctemp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1]=ctemp;
	}
	return str;
}//end strrev
//Multiply big data multiplication begin
void Multiply(char* a, char* b){
	char* ap=a;
	char* bp=b;
	Node* head=0;
	head = new Node;
	head->data = 0;
	head->next = 0;
	Node* p=head;
	Node* q=head;
	Node* p1;
	int temp=0,temp1,bit;
	while(*bp){
		p = q->next;
		p1=q;
		bit = *bp-48;
		while(*ap || temp){
			if(!p){
				p= new Node;
				p->data =0;
				p->next =0;
				p1->next =p;
			}
			if(*ap==0){
				temp1 = temp;
			}else{
				temp1 =(p1->data) + (*ap-48)*bit + temp;
				ap++;
			}
			p1->data = temp1%10;
			temp = temp/10;
			p1=p;
			p= p->next;
		}
		ap=a;
		bp++;
		q= q->next;
	}
	p=head;
	output(p);
	cout<<endl;
	while(head){
		p= head->next;
		delete head;
		head=p;
	}
}//end Multiply

//marry deduction problem begin
void Marry(){
	int x, y, z;
	for(x=1; x<=3; ++x){
		for(y=1; y<=3; ++y){
			for(z=1; z<=3; ++z){
				if(x!=1 && x!=3 && z!=3 && x!=y && x!=z && y!=z){
					cout<<"X will marry "<<char('A'+x-1)<<endl;
					cout<<"Y will marry "<<char('A'+y-1)<<endl;
					cout<<"Z will marry "<<char('A'+z-1)<<endl;
				}
			}
		}
	}	
}//marry deduction problem end
int main(int argc, char** argv){
	cout<<"marry question:"<<endl;
	Marry();
	cout<<"big data multiply question:"<<endl;
	char a[MAX], b[MAX];
	cout<<"Input the multiplicand:";
	cin.getline(a, MAX, '\n');
	cout<<"Input the multiplier:";
	cin.getline(b, MAX, '\n');
	Multiply(strrev(a), strrev(b));
	return 0;
}
