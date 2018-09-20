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
};




int main(){
	return 0;
}