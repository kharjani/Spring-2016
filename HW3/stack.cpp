#include "llistint.h"
#include "stackint.h"
#include <cstdlib>

using namespace std;

StackInt::StackInt(){
	list = new LListInt();
}

StackInt::~StackInt(){
	delete list;
}

bool StackInt::empty() const{
	return list.empty();
}

void StackInt::push(const int& val){
	Item* insert = new Item();
	insert->val = val;
	list->head_->prev = insert;
	insert->next = list->head_;
	insert->prev = NULL;
	list->head_ = insert;
	list->size_++;
}

int const & StackInt::top() const{
	return list->head_->val;
}

void StackInt::pop(){
	// check if size == 0 ? or check before calling the function
	Item* temp = list->head_;
	list->head_->next = list->head_;
	delete temp;
	
	
}

