/*
 * avlbst.h
 *
 * Date        Author    Notes
 * =====================================================
 * 2014-04-14  Kempe     Initial version
 * 2015-04-06  Redekopp  Updated formatting and removed
 *                         KeyExistsException
 * 2016-03-31  Cote      Modify for AVL Trees
 */
#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"

template <class KeyType, class ValueType>
class AVLNode : public Node<KeyType, ValueType>
{
public:
  AVLNode (KeyType k, ValueType v, AVLNode<KeyType, ValueType> *p)
    : Node<KeyType, ValueType> (k, v, p)
    { height = 0; }
  
  virtual ~AVLNode () {}
  
  int getHeight () const
    { return height; }
  
  void setHeight (int h)
    { height = h; }
  
  virtual AVLNode<KeyType, ValueType> *getParent () const
    { return (AVLNode<KeyType,ValueType>*) this->_parent; }
  
  virtual AVLNode<KeyType, ValueType> *getLeft () const
    { return (AVLNode<KeyType,ValueType>*) this->_left; }
  
  virtual AVLNode<KeyType, ValueType> *getRight () const
    { return (AVLNode<KeyType,ValueType>*) this->_right; }
  
 protected:
  int height;
};

/* -----------------------------------------------------
 * AVL Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class AVLTree : public BinarySearchTree<KeyType, ValueType>
{
public:
  void insert (const std::pair<const KeyType, ValueType>& new_item){
    if(this->root == NULL){
      root = new AVLNode(new_item.first, new_item.second, NULL);
      root.setHeight(0);
    }
    else if(this->internalFind(new_item.first) != NULL){
      std::throw logic_error("Node with given Key already exists");
    }
    else{
      if(this->root.getKey() > new_item.first){ // new item's key is smaller than root
        Node<KeyType,ValueType>* temp = this->root;
        while(temp != NULL){
          if(temp->getLeft().getKey() > new_item.first){
            temp = temp->getLeft();
          }
          else{
            temp = temp->getRight();
          }
        }
        temp = temp->getParent();
        Node<KeyType,ValueType>* newNode = Node(new_item.first, new_item.second, temp);
        if(temp.getKey() < new_item.first){
          temp.setRight(newNode);
        }
        else{
          temp.setLeft(newNode);
        }
        static_cast<AVLNode<K,V>*>(temp);
        static_cast<AVLNode<K,V>*>(newNode);
        newNode.setHeight(1);
      }
    }

    //Dealing with all AVL nodes
     AVLNode x = newNode;
     AVLNode y = newNode->getParent();
     AVLNode z = y->getParent();
     while(abs(z->getLeft().getHeight() - z->getRight().getHeight()) <= 1){
        z = z->getParent();
        y = y->getParent();
        x = x->getParent();
     }
     // after this while loop, 'z' is the first un-balanced ancestor of 'newNode'
     balanceTree(z, y, x);
     updateHeights();
  }
  
  void balanceTree(AVLNode* z, AVLNode* y, AVLNode* x){
    if(z->getRight() == y && y->getRight() == x){ // pattern 1, right right
      z->setRight(y->getLeft());
      y->setLeft(z);
      z->setParent(z);
    }
    else if(z->getLeft() == y && y->getLeft() == x){ // pattern 2 , left left
      z->setRight(y->getRight());
      y->setRight(z);
      z->setParent(y);
    }
    else if(z->getRight() == y && y->getLeft() == x){ // pattern 3, right left
      z->setRight(x->getLeft());
      y->setLeft(x->getRight());
      x->setLeft(z);
      z->setParent(x);
      x->setRight(x);
      y->setParent(x);
    }
    else{ // pattern 4, left right
      z->setLeft(x->getRight());
      y->setRight(x->getLeft());
      x->setLeft(y);
      y->setParent(x);
      x->setRight(z);
      z->setParent(x);
    }
  }

    

  void remove (const KeyType &toRemove){
  /* Implement this as well.  It should remove the (key, value) pair from
   * the tree which corresponds to the input parameter.
   * If the key is not in the tree, you should throw an exception.
   */
   
   Node<KeyType, ValueType>* node = this->internalFind(toRemove);
   Node<KeyType, ValueType>* temp;
   Node<KeyType, ValueType>* p; // parent
   if(node == NULL){
    std::throw logic_error("Node with given Key does not exist");
   }
   else{
    if(node->getLeft() == NULL && node->getRight() == NULL){ // node has no children
      if(node->getParent()->getLeft() == node){
        node->getParent()->setLeft(NULL);
        /*if(node->getParent()->getRight() == NULL){ // if parent now has no children, it becomes a leaf node (h=1)
          temp = node->getParent();
          static_cast<AVLNode<K, V>*>(temp);
          temp.setHeight(1);
        }*/
          // Will call updateHeights() later
      }
      else{
        node->getParent()->setRight(NULL);
        /*if(node->getParent()->getLeft() == NULL){ // if parent now has no children, it becomes a leaf node (h=1)
          temp = node->getParent();
          static_cast<AVLNode<K, V>*>(temp);
          temp.setHeight(1);
        }*/
          // Will call updateHeights() later

      }
      delete node;
    }
    else if ((node->getLeft() != NULL) != (node->getRight() != NULL)){ //has one child

      if(node->getLeft() == NULL){ // it's the right child
        temp = node->getRight();
        p = node->getParent();
        if(p->getLeft() == node){
          p->setLeft(temp);
        }
        else{
          p->setRight(temp);
        }
        temp->setParent(p);

      }
      else{ //it's the left child
        temp = node->getLeft();
        p = node->getParent();
        if(p->getRight() == node){
          p->setRight(temp);
        }
        else{
          p->setLeft(temp);
        }
        temp->setParent(p);
      }
      delete node;
    }
    else{ // has 2 children, will replace it with the largest node in the left subtree
      temp = node->getLeft(); // temp will hold replacement node
      while(temp->getRight() != NULL){
        temp = temp->getRight();
      }
      node->setKey(temp->getKey());
      node->setValue(temp->getValue());
      if(temp->getLeft() != NULL){ // temp isn't a leaf node, need to connect parent and left child
        temp->getParent()->setRight(temp->getLeft());
        temp->getLeft()->setParent(temp->getParent());
      }
      delete temp;

    }

   }
   updateHeights();

   //Dealing with all AVL nodes
     AVLNode x = static_cast<AVLNode<K,V>*>(node);
     AVLNode y = x->getParent();
     AVLNode z = y->getParent();
     while(z->getParent() != NULL){ // balance each potentially unbalanced node from x upto root
       while(abs(z->getLeft().getHeight() - z->getRight().getHeight()) <= 1){
          z = z->getParent();
       }
       if(z->getLeft().getHeight() > z->getRight().getHeight()){
          y = z->getLeft();
          if(y->getLeft().getHeight() > z->getRight().getHeight()){
            x = y->getLeft();
          }
          else{
            x = y->getRight();
          }
       }
       else{ 
          y = z->getRight();
          if(y->getLeft().getHeight() > z->getRight().getHeight()){
            x = y->getLeft();
          }
          else{
            x = y->getRight();
          }
       }
       balanceTree(z, y, x);
       updateHeights();
       z = z->getParent();
    }
    updateHeights();
 }

 void updateHeights(){ // for each leaf node sets h=1, then traverses through ancestors to set h = (child's height) +1
  AVLNode root = static_cast<AVLNode<K, V>*>(this->root);

  for(it = this->begin(); this->end(); it++){
    if(it->getRight() == NULL && it->getLeft() == NULL){ //if no children, it's a leaf node where h = 1
      static_cast<AVLNode<K,V>*>(it);
      AVLNode temp = static_cast<AVLNode<K, V>*>(it);
      it.setHeight(1);
      while(temp != NULL ){
        int h = temp->getheight();
        temp = temp->getParent();
        if(temp->getHeight() < h+1)
          temp.setHeight(h+1);
        }
    }
  }
 }
};

#endif
