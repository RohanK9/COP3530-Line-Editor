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
	void edit(string text, int position);
	void search(string text);
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

void list::edit(string text, int position){

	curr = head;
	int count = 1;

	if(position == 1){
		head->data = text;
	}

	while(count < position){
		curr = curr->next;
		count++;
	}
	curr->data = text;
}

void list::search(string text){
	curr = head;
	int count = 1;
	bool found = false;

	while(curr != NULL){
		if((curr->data).find(text) != string::npos){
			cout << count << " " << curr->data << endl;
			found = true;
			return;
		}

		else{
		curr = curr->next;
		count++;
		}
	}
	if(!found){
	 	cout << "Not found" << endl;
	 }
}

int main(){
	list docx;
	docx.addToEnd("now is the time");
	docx.addToEnd("for all good people");
	docx.addToEnd("to come to the aid of their country");
	docx.deleteLine(2);
	docx.print();
	docx.insert("for all good people", 2);
	docx.print();

	
	return 0;
}