#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}
//deep copy constructor
LListInt::LListInt(const LListInt& other){

	Item* first = new Item();
	Item* starter = other.head_;
	if(starter == NULL) return; // incase of empty list given to be copied
	first->val = starter->val;
	first->prev = NULL;
	first->next = NULL;
	this->head_ = first;
	this->tail_ = first;
	this->size_ = 1;
	starter = starter->next;
	for(;starter != NULL; starter = starter->next){
		Item* newItem = new Item();
		this->tail_->next = newItem;
		newItem->prev = this->tail_;
		newItem->next = NULL;
		newItem->val = starter->val;
		this->size_++;
		this->tail_ = this->tail_->next;
	}
	return;

}
//assignment operator
LListInt& LListInt::operator=(const LListInt& other){

	LListInt * newList = new LListInt();
	
	Item* first = new Item();
	Item* starter = other.head_;
	if(starter == NULL) return *newList; // incase of empty list given to be copied
	first->val = starter->val;
	first->prev = NULL;
	first->next = NULL;
	newList->head_ = first;
	newList->tail_ = first;
	newList->size_ = 1;
	starter = starter->next;
	for(;starter != NULL; starter = starter->next){
		Item* newItem = new Item();
		newList->tail_->next = newItem;
		newItem->prev = newList->tail_;
		newItem->next = NULL;
		newItem->val = starter->val;
		newList->size_++;
		newList->tail_ = newList->tail_->next;
	}
	return *newList;
}


// Concatenation Operator (other should be appended to the end of this)

LListInt LListInt::operator+(const LListInt& other) const{
	Item* starter = other->head_;
	this->tail_->next = starter;
	this->tail_ = starter;

	for(other->head_; starter != NULL; starter = starter->next){
		Item* newItem = new Item();
		this->tail_->next = newItem;
		newItem->prev = this->tail_;
		newItem->next = NULL;
		newItem->val = starter->val;
		this->size_++;
		this->tail_ = this->tail_->next;
	}
	//delete newItem;   ??
	return this;
}


// Access Operator 

int const & LListInt::operator[](int position) const{
	Item* newItem = this->head_;
	for(int i=0; i < position; i++){
		newItem = newItem->next;
	}
	return newItem->val;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  if ((loc > size_) || (loc < 0)){
	 return;
  }
  else {
  	Item* entry = new Item;
  	 if (size_ == 0){ // if the list is empty
  	 	entry->val = val;
	 	entry->next = NULL;
	 	entry->prev = NULL;
	 	tail_ = entry;
	 	head_ = entry;
  	 }
	 else if (loc == size_) { // add to the end of the list
	 	entry->val = val;
	 	entry->next = NULL;
	 	entry->prev = tail_;
	 	entry->prev->next = entry;
	 	tail_ = entry;
	 }
	 else{
	 	Item* A = getNodeAt(loc-1); // Insert somewhere in the middle of the list
	 	Item* temp = getNodeAt(loc);
	 	entry->val = val;
	 	entry->next = temp;
	 	entry->prev = A;
	 	A->next = entry; // the insertion is made between A and temp
	 	temp->prev = entry;
	 }
	 size_++; 
  }
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
	if ((loc > size_ -1) || (loc < 0)){
		return;
	}
	else{
		Item* temp = getNodeAt(loc);
		if (loc == 0){ // removing the head
			head_ = head_->next;
			head_->prev = NULL;
		}
		else if (loc == size_ -1){ // removing the tail
			tail_ = tail_->prev;
			tail_->next = NULL;
		}
		else{
			Item* A = temp->prev; // removing a node in the middle of the list (between A and B) 
			Item* B = temp->next;
			A->next = B;
			B->prev = A;
		}
		size_--;

		delete temp;
	}
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
	Item* node = head_;
	for(int i=0; i< loc; i++){
		node = node->next;
	}
	return node;

}
