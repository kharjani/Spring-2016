#include <iostream>
#include <vector>
#include <cmath>
#include "Map.h"


template <class KeyType, class ValueType>
class hashTable : public Map
{
public:

	hashTable(){
		size = 11;
		sizeCounter = 0;
		count = 0;
		std::vector<std::pair<std::string, int>>map;
		map.resize(size);
		for(int i=0; i<size; i++){
			map[i].first = ""; // initialize all strings to the empty string
			map[i].second = -1; // initialize all count to -1
		}
	}

	virtual void add(const std::KeyType& word){
		if(map[hash(word)].second != -1){ // word already exists in the map
			map[hash(word)].second++;
		}
		else{ // need to add the word to the map
			int loc = hash(word);
			map[loc].first = word;
			map[loc].second = 1;
			count++;
			checkLoad();
		}

	}

	virtual void reportAll(std::ostream& output){
		for(int i =0; i < size; i++){
			if(map[i].second != -1){ // word exists at map[i]
				output << map[i].first << " " << map[i].second;
			}
		}
	}

private:

	int size; // current table size
	int count; // stores # of positions filled
	int sizeCounter;
	int sizes[13] = {11, 23, 41, 83, 163, 331, 641, 1283, 2579, 5147, 10243, 20483, 40961};

	std::vector<std::pair<std::string, int>>map;

	void resize(){
		int oldSize = size;
		sizeCounter++;
		size = sizes[sizeCounter + 1]; // size is updated, now hash() will work with the new size
		std::vector<std::pair<std::string, int>>newMap;
		newMap.resize(size);
		for(int i=0; i < size; i++){ // set up new map;
			newMap[i].first = ""; 
			newMap[i].second = -1;
		}
		for(int i=0; i < oldSize; i++){
			if(map[i].second != -1){
				std::string word = map[i].first;
				int val = hash(word);
				std:pair<string, int> myPair;
				myPair = std::make_pair(word, map[i].second);
				newMap[val] = myPair;
			}
		}
		map = newMap;
		
	}

	void checkLoad(){ // call resize() if load factor > 0.5
		if((count/size) > 0.5){
			resize();
		}
		else{
			return;
		}
	}


	int hash(std::string word){
		std::vector<long long int> w = hashHelper(word);
		int hashValue = (34394 * w[0] + 36706 * w[1] + 38074 * w[2] + 16351 * w[3] + 2623 * w[4] + 10174 * w[5] 
						+ 22339 * w[6] + 27779 * w[7] + 36642 * w[8] + 19250 * w[9] + 36216 * w[10]
						+ 33514 * w[11] + 24019 * w[12] + 5552 * w[13]) % size;

		bool found = false; // if we have found a spot for the word in our map
		int quadCounter = 1; // keeps track of the increments of quadratic probing
		while(!found){
			if(map[hashValue].second != -1){ // this position in the map has been filled already
				if(map[hashValue].first == word){ // it's been filled by the same word, this is its location
					found = true;
					return hashValue;
				}
				else{
					hashValue = hashValue + pow(quadCounter, 2); // change hashValue according to quadratic probing
					hashValue = hashValue % size;
					quadCounter++;
					continue;
				}
			}
			else{ // position is empty, new word can be placed here
				found = true;
				return hashValue;
			}
		}
		

	}

	std::vector<long long int> hashHelper(std::string word){ // returns vector with 'w' values
		int n = word.size();
		std::vector<long long int> w(14,0); // store's w values, size=14, all initially set to 0
		int a[28]; // at most we will process words with 28 letters
		long long int num1 = 0; // to hold value used to generate w1 & w2
		long long int num2 = 0; // to hold value used to generate w3 - w6
		long long int num3 = 0; // to hold value used to generate w7 - w10
		long long int num4 = 0; // to hold value used to generate w11 - w14
		
		// populate a[] with letters from the word, filling leading spots with 0 if word.size() < 28
		for(int i=0; i < 28; i++){
			if(i < n){
				int val = word[i];
				a[27-i] = val;
			}
			else{
				a[i] = 0;
			}
		}
		// to process a21 - a28, to generate w11 - w14
		for(int i = 0; i < 8; i++){
			num4 += (pow(128,7-i))*(a[20+i]);
		}
		long long int w11 = num4 % 40961;
		w[10] = w11;
		for(int i=0; i < 3; i++){
			num4 = num4/40961;
			w[11+i] = num4 % 40961;
		}

		// to process a13 - a20, to generate w7 - w10
		for(int i = 0; i < 8; i++){
			num3 += (pow(128,7-i))*(a[12+i]);
		}
		long long int w7 = num3 % 40961;
		w[6] = w7;
		for(int i=0; i < 3; i++){
			num3 = num3/40961;
			w[7+i] = num3 % 40961;
		}

		// to process a5 - a12, to generate w3 - w6
		for(int i = 0; i < 8; i++){
			num2 += (pow(128,7-i))*(a[4+i]);
		}
		long long int w3 = num2 % 40961;
		w[2] = w3;
		for(int i=0; i < 3; i++){
			num2 = num2/40961;
			w[3+i] = num2 % 40961;
		}

		// to process a1 - a4, to generate w1 & w2
		for(int i = 0; i < 4; i++){
			num1 += (pow(128,3-i))*(a[i]);
		}
		long long int w2 = num1 % 40961;
		w[1] = w2;
		num1 = num1/40961;
		w[0] = num1 % 40961;
		

	}

	return w;
	

}