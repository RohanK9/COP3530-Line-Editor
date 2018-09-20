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

public:
	list(){
		head = NULL;
		tail = NULL;
	}

	void addToEnd(string text);
};

void list::addToEnd(string text){
	node* temp = new node;
	temp->data = text;
	
	

	if (head == NULL){
		head = temp;
	}

	
}




int main(){
	list docx;
	docx.addToEnd("pls");
	
	return 0;
}