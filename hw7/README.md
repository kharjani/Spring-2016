CS104 HW7 - Krish Harjani

Answers to Q1 are in Hw7q1.pdf

Notes: bst.h and avlbst.h contain some syntax errors and therefore will not compile, however the vast majority of
	the implementation is correct. 

	For exam.cpp I attempted to retrieve all data from the file and store it in a map where key = class (e.g. 104) 
		and the value is a vector<int> which contains all possible clashes for that class(key). It will contain 
		duplicates and well as instances of itself (e.g. vector<int> for key=104 may contain 104, 170, 104, 350,...).
		My goal was to use this to track potential clashes in my recursive solver() function when using backtracking 
		to find a potential schedule to solve the given input. 



