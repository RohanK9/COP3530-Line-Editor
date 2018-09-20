#include <iostream>
#include <string>
using namespace std;

struct node{
	string data;
	node* next;
};

class list{
private:
	node* head;
	node* tail;
	node* curr;

public:
	list(){
		head = NULL;
		tail = NULL;
		curr = NULL;
	}

	void addToEnd(string text);
	void PrintList();
};

void list::addToEnd(string text){
	node* toAdd = new node;
	toAdd->next = NULL;
	toAdd->data = text;

	if(head != NULL){
		curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = toAdd;
	}
	else{
		head = toAdd;
	}

}

void list::PrintList(){
	curr = head;
	while(curr->next != NULL){
		cout<<curr->data<<endl;
		curr = curr->next;
	}
	cout<<curr->data<<endl;
}

int main(){
	list docx;
	docx.addToEnd("first node");
	docx.addToEnd("second node");
	docx.PrintList();
	
	return 0;
}