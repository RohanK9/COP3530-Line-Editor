#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

struct node {
	string data;
	node* next;
};

class list {
private:
	node* head;
	node* tail;
	node* curr;

public:
	list() {
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
void list::addToEnd(string text) {
	//node to be added to the linked list
	node* toAdd = new node;
	toAdd->next = NULL;
	toAdd->data = text;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = toAdd;
	}

	//if the linked list is empty then the head becomes new node
	else {
		head = toAdd;
	}
}

//method to print the linked list with line numbers
void list::print() {

	if (head == NULL) {
		cout << "Can't print an empty list" << endl;
		return;
	}

	int lineCount = 1;
	curr = head;

	while (curr->next != NULL) {
		cout << lineCount << " " << curr->data << endl;
		curr = curr->next;
		lineCount++;
	}
	cout << lineCount << " " << curr->data << endl;
}

//method to insert a node into a given position in the linked list
void list::insert(string text, int position) {

	node* toAdd = new node;
	toAdd->next = NULL;
	toAdd->data = text;

	if (head != NULL) {
		int lineCount = 1;
		curr = head;

		while (curr->next != NULL) {
			curr = curr->next;
			lineCount++;
		}

		if (position > (lineCount + 1)) {
			//cout << "The given position is out of bounds" << endl;
			return;
		}

		curr = head;
		int count = 1;


		if (position == 1) {
			toAdd->next = head;
			head = toAdd;
			return;
		}

		else if (position > 1) {
			while (count < position - 1) {
				curr = curr->next;
				count++;
			}

			toAdd->next = curr->next;
			curr->next = toAdd;
		}

		else if (position == (lineCount + 1)) {
			addToEnd(text);
		}
	}
	else {
		head = toAdd;
	}
}

void list::deleteLine(int position) {

	curr = head;
	int lineCount = 1;

	while (curr->next != NULL) {
		curr = curr->next;
		lineCount++;
	}

	if (position > lineCount) {
		return;
	}

	curr = head;
	int count = 1;

	if (position == 1) {
		head = head->next;
	}

	while (count < position - 1) {
		curr = curr->next;
		count++;
	}

	curr->next = curr->next->next;
}

void list::edit(string text, int position) {

	curr = head;
	int count = 1;

	if (position == 1) {
		head->data = text;
	}

	while (count < position) {
		curr = curr->next;
		count++;
	}
	curr->data = text;
}

void list::search(string text) {
	curr = head;
	int count = 1;
	bool found = false;

	while (curr != NULL) {
		if ((curr->data).find(text) != string::npos) {
			cout << count << " " << curr->data << endl;
			found = true;
		}


		curr = curr->next;
		count++;
	}
	if (!found) {
		cout << "not found" << endl;
	}
}

int main() {
	list docx;


	string userInput = "";
	bool inputCondition = true;

	while (inputCondition) {
		//cout << "hello" << endl;
		getline(cin, userInput);

		for (int i = 0; i < userInput.length(); i++) {
			if (userInput[i] == '\"') {
				break;
			}
			else if (userInput[i] == ' ' && userInput[i + 1] == ' ') {
				userInput.erase(i, 1);
				i--;
			}
		}

		if (userInput.substr(0, 9) == "insertEnd") {
			userInput = userInput.substr(11, userInput.length() - 2);
			string message = userInput.substr(0, userInput.length() - 1);
			docx.addToEnd(message);
		}

		else if (userInput.substr(0, 7) == "insert ") {
			string sline = "";
			

			 if (isdigit(userInput[7]) && !(isdigit(userInput[8]))) {
			 	sline = userInput.substr(7, 1);

			 	int singleLine = std::stoi(sline);
			 	userInput = userInput.substr(10, userInput.length() - 2);
			 	string message = userInput.substr(0, userInput.length() - 1);
			 	docx.insert(message, singleLine);
			 }


			 else if (isdigit(userInput[7]) && isdigit(userInput[8])) {
			 	sline += userInput[7];
			 	sline += userInput[8];
			 	int doubleLine = std::stoi(sline);
			 	userInput = userInput.substr(11, userInput.length() - 2);
			 	string message = userInput.substr(0, userInput.length() - 1);
			 	docx.insert(message, doubleLine);
			 }

			// if (isdigit(userInput[7])) {
			// sline = userInput.substr(7, 1);


			// if (isdigit(userInput[8])) {
			//  		sline = sline + userInput[8];
			//  	}
			//  }
			//  int line = std::stoi(sline);

			//  userInput = userInput.substr(10, userInput.length() - 2);
			//  string message = userInput.substr(0, userInput.length() - 1);
			

			//  docx.insert(message, line);
		}


		else if (userInput.substr(0, 6) == "delete") {
			string sline = "";
			if (isdigit(userInput[7])) {
				sline = userInput.substr(7, 1);


				if (isdigit(userInput[8])) {
					sline = sline + userInput[8];
				}
			}
			int line = std::stoi(sline);

			docx.deleteLine(line);
		}

		else if (userInput.substr(0, 4) == "edit") {

			string sline = "";
			if (isdigit(userInput[5])) {

				sline = userInput.substr(5, 1);

				if (isdigit(userInput[6])) {
					sline = sline + userInput[6];
				}
			}
			int line = std::stoi(sline);

			userInput = userInput.substr(8, userInput.length() - 2);
			string message = userInput.substr(0, userInput.length() - 1);

			docx.edit(message, line);
		}

		else if (userInput.substr(0, 6) == "search") {
			userInput = userInput.substr(8, userInput.length() - 2);
			string message = userInput.substr(0, userInput.length() - 1);

			docx.search(message);
		}

		else if (userInput.substr(0, 5) == "print") {
			//cout << endl;
			docx.print();
		}

		else if (userInput.substr(0, 4) == "quit") {
			inputCondition = false;
			return 0;
		}

		else {
			cout << "Invalid input. Please try again." << endl;
		}

	}



	return 0;
}