#include <iostream>
#include <exception>
#include <cstdlib>
#include "avlbst.h"

using namespace std;

bool solver(int exams, int, timeslots, int students, ){
	for(int i=0; i < timeslots; i++){
		for(int j=0; j < schedule[i].size(); j++){
			set.count()
		}
	}
}

int main(int argc, char* argv[]){
	string filename = argv[1];
	istream inf;
	inf = ifstream infile(filename);
	int exams, students, timeslots;
	inf >> exams;
	inf >> students;
	inf >> timeslots;
	vector<vector<int>> clashes;
	int array[100][100];
	set<int> classes;
	vector<int> one;
	vector<int> two;
	vector<int> classList;
	for(int i=1; i <= timeslots; i++){
		schedule.push_back()
	}

	while( ! inf.eof() )
	{
		string name;
		int classNum;
		stringstream ss;
		getline(inf, line);
		ss << line;
		ss >> name;
		vector<int> conflicts;
		while(!ss){
			
			ss >> classNum;
			classes.insert(classNum);
			one.push_back(classNum);
			two.push_back(classNum);
			array[i][0] = classNum;
			clashes[i].push_back(classNum);
			conflicts.push_back(classNum);

		}
		for(int a=0; a<one.size(); a++){
			for(int b=0; b<one.size(); b++){
				array[a][a+b] = one[b];
			}
		}

		i++		
	}



	map<int, vector<int>>map;
	for (set<int>::iterator it=classes.begin(); it!=classes.end(); ++it){
		int key = *it;
		vector<int>v;
		pair<int, vector<int>> myPair = make_pair(key, v);
		map.insert(myPair);
	}

	for(int i=0; i < students; i++){
		for(int j=0; j<array[i].size(); j++){
			for(int k=0; k<array[i].size(); k++){
				map[array[i][j]].push_back(array[i][k]); // there will be duplicates
			}
			
		}
	}





	vector<int>v;
	int i=0;
	schedule is 2D vector array
	for (set<int>::iterator it=classes.begin(); it!=classes.end(); ++it){
		vector[i] = *it;
		i++;
	}

	for(int i=0; i < exams; i++){
		for(int j = 0; j < array[i].size(); j++){
			schedule[i].push_back(array[i][j]);
		}
	}
	



	return 0;
}