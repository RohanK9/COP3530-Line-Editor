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
	void print();
	void insert(string text, int position);
	void deleteLine(int position);
};

//method to add to the end of the linked list
void list::addToEnd(string text){
	//node to be added to the linked list
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

	//if the linked list is empty then the head becomes new node
	else{
		head = toAdd;
	}
}

//method to print the linked list with line numbers
void list::print(){

	if (head == NULL){
		cout << "Can't print an empty list" << endl;
		return;
	}
	int lineCount = 1;
	curr = head;

	while(curr->next != NULL){
		cout << lineCount << " " << curr->data << endl;
		curr = curr->next;
		lineCount++;
	}

	cout << lineCount << " " << curr->data << endl;
}

//method to insert a node into a given position in the linked list
void list::insert(string text, int position){
	node* toAdd = new node;
	toAdd->next = NULL;
	toAdd->data = text;

	int lineCount = 1;
	curr = head;

	while(curr->next != NULL){
		curr = curr->next;
		lineCount++;
	}

	if(position > (lineCount + 1)){
		cout << "The given position is out of bounds" << endl;
		return;
	} 

	curr = head;
	int count = 1;

	if(position == 1){
		toAdd->next = head;
		head = toAdd;
	}

	else if(position > 1){
		while(count < position - 1){
			curr = curr->next;
			count++;
		}

		toAdd->next = curr->next;
		curr->next = toAdd;
	}

	else if(position == (lineCount + 1)){
		addToEnd(text);
	}
}

void list::deleteLine(int position){
	curr = head;
	int count = 1;

	if (position == 1){
		head = head->next;
	}

	while(count < position - 1){
		curr = curr->next;
		count++;
	}

	curr->next = curr->next->next;
}

int main(){
	list docx;
	docx.addToEnd("line one");
	docx.addToEnd("line two");
	docx.addToEnd("line three");
	docx.insert("line four", 4);
	docx.insert("line five", 5);
	docx.deleteLine(5);
	docx.print();
	
	return 0;
}