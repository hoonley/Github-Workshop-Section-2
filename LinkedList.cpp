#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList(){
	
	while(head != NULL){
		Node* current = head;
		head = head->next;
		delete current;
	}
}


void LinkedList::append(int i){
	Node *newNode = new Node;
	newNode->val = i;
	newNode->next = NULL;
	
	if (head == NULL){
		head = newNode;
		return;
	}
	
	Node* current = head;
	// while you have not reached the end
	while (current->next != NULL){
		current = current->next;
	}	
	
	current->next = newNode;
	
	
}

void LinkedList::prepend(int i){
	Node *newNode = new Node;
	newNode->val = i;
	newNode->next = NULL;
	
	newNode->next = head;
	head = newNode;
	
}






int LinkedList::pop_front(){
	if (head == NULL){
		cout << "Nothing to pop!!!!!!" << endl;
		return -1;
	
	}
	
	Node* temp = head;
	head = head->next;
	int value = temp->val;
	delete temp;
	return value;

}


int LinkedList::pop_back(){
	if (head == NULL){
		cout << "Nothing to pop!!!!!!" << endl;
		return -1;
	
	}
	
	if (head->next == NULL){
		int value = head->val;
		delete head;
		head = NULL;
		return value;
	
	}
	
	Node* current = head;
	while(current->next->next != NULL){
		current = current->next;
	}
	int value = current->next->val;
	delete current->next;
	current->next = NULL;
	return value;

}

Node* LinkedList::find(int i){
	Node* current = head;
	
	while (current != NULL){
		if(current->val == i){
			return current;
		}
		current = current->next;
	}
	cout << "There is not any i (input number) in the list to find:" << endl;
	return NULL;
	
}

void LinkedList::remove(int i){
	
	Node* current = head;
	Node* prev = NULL;
	
	// what if empty list.
	if (head == NULL){
		cout << "Nothing to remove!!!" << endl;
		return;
	}
	
	//what if removable value i is first
	
	if(current->val == i){
		head = current->next;
		delete current;
		return;
	}
	
	// while you have not that i value
	while (current->val != i){	
		if (current->next == NULL){
			cout << "There is not nothing in the list with the value i" << endl;
			return;
		}
		
		if(current->next->next == NULL ){
			if(current->next->val == i){
				Node* temp = current->next;
				current->next = NULL;
				delete temp;
				return;
			}		
		}
		prev = current;
		current = current->next;
		
	}
	
	prev->next = current->next;
	delete current;
}


void LinkedList::print_list(){
	Node* current = head;
	cout << "{";
	while(current != NULL){
		cout << current->val << " ";
		current  = current->next;
	}
	cout<< "}" << endl;
	
}
