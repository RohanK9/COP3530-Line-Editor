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

int main(){
	list docx;
	docx.addToEnd("now is the time");
	docx.addToEnd("for all good men");
	docx.addToEnd("to come to the aid of their country");
	docx.insert("test1", 4);
	docx.insert("test", 6);
	docx.print();
	
	return 0;
}