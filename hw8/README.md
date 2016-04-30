CS104 HW8 - Krish Harjani

Comments:

Splay Tree:
	Inherits from Binary Search Tree (built in HW7)
	splay(Node* x)  is used to splay a given node (when it has been added, or accessed)

Hash Table:
	hashHelper(word)  takes a string and does most of the calculations for hashing, resulting in the final has value.
	Then hash(word)  is used to see if this position is valid, otherwise uses quadratic probing to find the right spot.
	My implementation treats every word as 28 characters (assume worst case) and fills in preceeding empty spaces
		with 0's. 
	checkLoad() is called after every insert, then calls resize() if the load factor > 0.5


Note: zipf.cpp is not complete, however I have built the splayTree and hashTable to perform correctly.



-----------------------------------
Answers to questions from Problem 6

Used hamlet text as large input

Hash table runs faster, unless there is an infinite loop via quadratic probing

unsorted list - slower than both, need to traverse every single time
sorted list - similar to splay tree but splay tree is a bit faster because of occasional O(1) access, but hash is still 				faster than both
BST - faster than splay because you dont have to rotate, hash is still faster
AVL - similar to splay tree given they both require a lot of rotations, hash table is faster than both
