CS104 HW6 - Krish Harjani

Problem 2 - answers in hw6q2.pdf

Problem 4:

Main issue is with A*Search which I implemented for all 3 choices, but had trouble implementing priority queue from heap.h 
	in solveByAStar(int choice). However, I proceeded to write the function given that I have a priority queue 'pq' which
	stores pair<pair<int, int>, double> where the inner pair holds coordinates (row, col) and the double value holds
	the relevant 'f' value (priority in this case) of the given cell. I attempted to use STL priority queue on line 105
	in mazesolver.cpp but couldn't figure out the comparator object given how I stored the priority value. 

	Therefore, I need the grader to implement the priority queue pq, which my code will then work with to implement
	the A* Search algorithm. So currently code will not compile/run successfully without this. 
	Note: currently the 'pq' I use in my code uses pq.push(), pq.top(), and pq.pop() so these may need to be changed
		depending on if the grader decides to use 'heap.h' which would instead require pq.add(), pq.peek(), and pq.remove()