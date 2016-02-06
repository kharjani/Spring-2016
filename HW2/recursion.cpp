#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};



Node* merge (Node*& first, Node*& second){
	Node* newList = new Node();

	if (first == NULL){
		newList->value = second->value;
		newList->next = second->next;
		second = NULL;
		return newList;
	}
	else if (second == NULL){
		newList->value = first->value;
		newList->next = first->next;
		first = NULL;
		return newList;
	}
	else{
		if (first->value < second->value){
			newList->value = first->value;
			newList->next = merge(first->next, second);
		}
		else{
			newList->value = second->value;
			newList->next = merge(first, second->next);
		}
	}
	return newList;

}




int main(){

	Node * fN = new Node();
	fN->value = 4;
	fN->next = new Node();
	fN->next->value = 5;
	fN->next->next = NULL;
	Node * sN = new Node();
	sN->value = 3;
	sN->next = new Node();
	sN->next->value = 7;
	sN->next->next = NULL;

	Node * merged = merge(fN,sN);
	while(merged != NULL){
		cout << merged->value << endl;
		merged = merged->next;
	}

	return 0;
}