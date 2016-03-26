#include <iostream>
#include <string>
#include <vector>

using namespace std;


template <class T>
struct StringLexiComp {
    bool operator()(const string& lhs, const string& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs <= rhs; 
    }
  };

template <class T>
struct StringSizeComp {
    bool operator()(const string& lhs, const string& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs.size() <= rhs.size(); 
    }
  };

 template<class t>
  struct IntComp {
    bool operator()(const int& lhs, const int& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs < rhs; 
    }
  };

template <class Comparator>
void DoComparison(const T& s1, const T& s2, Comparator comp)
{
  return comp(s1, s2);  
 
}
template <class T, class Comparator>
void mergeSort(vector<T>& myArray, Comparator comp){
	mergeHelper(myArray, 0, myArray.size() - 1, comp);

}

template <class T, class Comparator>
void mergeHelper(vector<T>& myArray, int l, int r, int m, Comparator comp){
	if(l < r){
		int m = (l + r)/2;
		mergeHelper(myArray, l, m, comp);
		mergeHelper(myArray, m+1, r, comp);


		vector<T> merged; // will contain merged vector
		int i = l;
		int j = m+1;
		int k = 0;
		while (i < m || j <= r){ // while atleast one of the halves still has unprocessed elements
			if(i < m && (j > r || DoComparison(myArray[i], myArray[j], comp))){ //If there are still unprocessed elements in the first half, and either
				merged.push_back(myArray[i]); 						//second half is done or myArray[i] <= myArray[j]
				i++; // add myArray[i] as the next element in the merged vector
			}
			else{ // is executed if myArray[j] > myArray[i], or the first half has been completely processed
				merged.push_back(myArray[j]);
				j++;
			}
			k++;
		}

		for(k = 0; k < r -l + 1; k++){ //copy contents from merged into original vector myArray
			myArray[k+l] = merged[k];
		}
	}

}