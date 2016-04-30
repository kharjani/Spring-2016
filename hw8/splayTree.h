#include <iostream>
#include "Map.h"
#include "bst.h"


template <class KeyType, class ValueType>
class splayTree : public BinarySearchTree<KeyType, ValueType>, public Map
{
public:

	virtual void add(const std::KeyType& word){
		if(this->root == NULL){ // tree is empty
			this->root = new Node(word, 1, NULL);
		}
		else{
			Node<KeyType,ValueType>* temp = this->internalFind(word);
			if(temp != NULL){ // node with given key exists
				temp.setValue(temp.getValue() + 1); // increment counter(value) for node with given key
				splay(temp);
			}
			else{ // node with given key does not exist in the tree, need to find where to insert it
				Node<KeyType,ValueType>* curr = this->root;
				Node<KeyType,ValueType>* p; // to store parent
				while(curr != NULL){
					if(curr->getKey() > word){
						p = curr;
						curr = curr->getLeft();
					}
					else{
						p = curr;
						curr = curr->getRight();
					}
				}
				if(word < p->getKey()){
					p->setLeft(curr);
				}
				else{
					p->setRight(curr);
				}
				curr->setValue(1);
				curr->setKey(word);
				splay(curr);

			}
		}
	}

	

	virtual void reportAll(std::ostream& output){
		for(iterator it = this->begin(); it!= this->end(); it++){
			output << (*it)->getKey() << " " << (*it)->getValue() << endl;
		}
	}

private:

	void splay(Node* x){
		if(x->getParent() == NULL){ // if x is the root, we're done
			return;
		}
		Node<KeyType, ValueType> *p = x->getParent(); // parent
		Node<KeyType, ValueType> *g = p->getParent(); // grandparent

		if(g->getLeft() == p){
			if(p->getLeft() == x){ // zig zig where x, p are their parents' left child
				p->setLeft(x->getRight());
				g->setLeft(p->getRight());
				x->setParent(g->getParent());
				p->setParent(x);
				x->setRight(p);
				g->setParent(p);
				p->setRight(g);
			}
			else{ // zig zag, where p is g's left child, x is p's right child
				g->setLeft(x->getRight());
				p->setRight(x->getLeft());
				x->setParent(g->getParent());
				g->setParent(x);
				x->setRight(g);
				p->setParent(x);
				x->setLeft(p);
			}
		}
		else{
			if(p->getRight() == x){ // zig zig where , p are their parents' right child
				p->setRight(x->getLeft());
				g->setRight(p->getLeft());
				x->setParent(g->getParent());
				p->setParent(x);
				x->setLeft(p);
				g->setParent(p);
				p->setLeft(g);
			}
			else{ // zig zag, where p is g's right child, x is p's left child
				g->setRight(x->getLeft());
				p->setLeft(x->getRight());
				x->setParent(g->getParent());
				g->setParent(x);
				x->setLeft(g);
				p->setParent(x);
				x->setRight(p);
			}
		}
		splay(x);
	}

};



