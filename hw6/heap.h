#include <vector>
#include <cstring>
#include <cmath>
#include <utility>

using namespace std;


template <typename T>
	class MinHeap {
		 public:
			 MinHeap (int d);
			 /* Constructor that builds a d-ary Min Heap
					This should work for any d >= 2,
					but doesn't have to do anything for smaller d.*/

			 ~MinHeap ();

			 void add (T item, double priority);
				 /* adds the item to the heap, with the given priority. */

			 const T & peek () const;
				 /* returns the element with smallest priority. */

			 void remove ();
				 /* removes the element with smallest priority. */

			 bool isEmpty ();
				 /* returns true iff there are no elements on the heap. */

	 private:
			// whatever you need to naturally store things.
			// You may also add helper functions here.
	 	int size;
	 	int d; // for d-ary tree
	 	vector<pair<T, double>> heap; // first = key, second = priority
	 	
	 	//helper functions
	 	void bubbleUp(int pos);
	 	void trickleDown(int pos);
	};

template<class T>
MinHeap<T>::MinHeap(int d){
	size = 0;
	d = d;

}

template<class T>
MinHeap<T>::~MinHeap(){
	heap.clear();
}

template<class T>
void MinHeap<T>::add(T item, double priority){
	pair<T, double> newPair;
	newPair = make_pair(item, priority);
	heap.push_back(newPair); // add new node to the end, then bubble it up
	size++;
	bubbleUp(size);
}

template<class T>
void MinHeap<T>::bubbleUp(int pos){
	if(pos>0 && heap[pos].second < heap[ceil((pos-1)/d)].second){ // if node's priority is lower than it's parent's
		heap[pos].swap(heap[ceil((pos-1)/d)]); // swap with parent
		bubbleUp((pos-1)/d); // bubble up again
	}
}

template<class T>
const T & MinHeap<T>::peek() const{
	return heap[0].first;
}

template<class T>
void MinHeap<T>::remove(){
	if(heap.isEmpty()) return;
	heap[0].swap(heap[size-1]); // replaces root node with the current last node, then trickle it down
	size--;
	heap.pop_back();
	trickleDown(0);
}

template<class T>
void MinHeap<T>::trickleDown(int pos){
	int child = d*pos + 1; // location of first child
	if(child < size){
		for(int i=0; i<d-1; i++){ // for loop for finding the child with the lowest priority
			if(child+1 < size && heap[child].second > heap[child+1].second) child++;
		}
		if(heap[child].second < heap[pos].second){
			heap[child].swap(heap[pos]);
			trickleDown(child);
		}
	}
}

template<class T>
bool MinHeap<T>::isEmpty(){
	return size==0;
}