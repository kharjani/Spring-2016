#include "mazesolver.h"
#include "mazedisplay.h"
#include "visitedtracker.h"
#include <QMessageBox>
#include <queue>
#include <stack>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>


MazeSolver::MazeSolver(Maze * m, MazeDisplay * md)
    : maze(m), display(md)
{}



std::vector<Direction> MazeSolver::pathCreator(std::vector<Direction> p){
    std::vector<Direction> path;
    std::stack<Direction> st;
    int r = maze->getGoalRow();
    int c = maze->getGoalCol();

    while( r != maze->getStartRow() || c != maze->getStartCol())
    {
        st.push( p[ squareNumber(r,c) ]);
        switch( st.top() )
        {
        case UP: r++; break; // yes, r++.  I went up to get here...
        case DOWN: r--; break;
        case LEFT: c++; break;
        case RIGHT: c--; break;
        }
    }
    while ( ! st.empty() )
    {
        path.push_back(st.top());
        st.pop();
    }
    return path;
}

void MazeSolver::dfsHelper(int r, int c, VisitedTracker &vt, std::vector<Direction> &p, int &numExplored){
    Direction dir; // these variables change depending on direction of neighbour that will be explored
    int rVal;
    int cVal;
    
    for(int i=0; i < 4; i++){
        if(i==0){dir = RIGHT; rVal = r; cVal=c+1;}
        else if(i==1){dir = LEFT; rVal = r; cVal=c-1;}
        else if(i==2){dir = DOWN; rVal = r+1; cVal=c;}
        else {dir = UP; rVal = r-1; cVal=c;}
        if ( maze->canTravel(dir, r, c) && ! vt.isVisited(rVal,cVal))
        {
            p[squareNumber(rVal, cVal)] = dir; // set predecessor
            vt.setVisited(rVal,cVal);
            
            dfsHelper(rVal, cVal, vt, p, numExplored);
        }

    }
    numExplored++;

}


void MazeSolver::solveByDFSRecursive()
{
    VisitedTracker vt(maze->numRows(), maze->numCols());
    int numSquares = maze->numRows() * maze->numCols();
    std::vector<Direction> p( numSquares );
    int numExplored = 0;
    
    dfsHelper(maze->getStartRow(), maze->getStartCol(), vt, p, numExplored);
    std::vector<Direction> path = pathCreator(p);
    display->reportSolution(path, vt, numExplored);
    return;
    

}




void MazeSolver::solveByAStar(int choice)
{
    // TODO:
    //    if choice is 1, solve by A* using heuristic of "return 0"
    //    else if choice is 2, solve by A* using heuristic of Manhattan Distance
    //    else if choice is 3, solve by A* using heuristic of Euclidean Distance

    // else completely up to you.
    if(choice > 3 || choice < 1) return;
   
    
    int numSquares = maze->numRows() * maze->numCols();
    double h[maze->numRows()][maze->numCols()]; // (estimated) distance from target, depends on heuristic
    double g[maze->numRows()][maze->numCols()]; // will store g values (depth of path to current cell)
    VisitedTracker vt(maze->numRows(), maze->numCols());
    int numExplored = 0;
    std::vector<Direction> p( numSquares ); // stores predecessors

    
    //std::priority_queue<std::pair<std::pair<int, int>, double>, 
      //                  std::vector<std::pair<std::pair<int, int>, double>>, std::greater<int>> pq;
    
    //fill up h array to store h[n] values for each cell
    int tR = maze->getGoalRow(); // target Row coordinate
    int tC = maze->getGoalCol(); // target Col coordinate
    int sR = maze->getStartRow();
    int sC = maze->getStartCol();
    double d;
    for(int i=0; i < maze->numRows(); i++){
        for(int j=0; j < maze->numCols(); j++){
            if(choice==1)d=0;
            else if(choice==2){d = sqrt((tR-i)*(tR-i) + (tC-j)*(tC-j));}
            else{d = std::abs((tR - i) + (tC - j));}
            h[i][j] = d;
            g[i][j] = -1.0; // set to -1 initially instead of garbage values
        }
    }


    
    
    h[tR][tC] = 0.0; // heuristic distance to goal is 0
    g[sR][sC] = 0.0; // depth of path from Start is 0
    myPair = std::make_pair(std::make_pair(sR, sC), h[sR][sC]); // starting node/cell
    pq.push(myPair);
    while(!pq.empty()){
        std::pair<std::pair<int, int>, double> v;
        v = pq.top(); 
        pq.pop();
        if(vt.isVisited(v.first.first, v.first.second)) continue;
        vt.setVisited(v.first.first, v.first.second);

        int r = v.first.first;
        int c = v.first.second;
        
        // in each of the 4 cases, make sure then next node isn't the predecessor of the current node
        if ( maze->canTravel(UP, r, c))
        {
            p[squareNumber(r-1, c)] = UP;
            //vt.setVisited(r-1,c);
            g[r-1][c] = g[r][c] + 1;
            double f = h[r][c] + g[r-1][c];
            std::pair<int, int>loc = std::make_pair(r-1, c);
            pq.push(std::make_pair(loc, f));
        }
        // Note:  this is NOT "else if" ...
        if ( maze->canTravel(DOWN, r, c))
        {
            p[squareNumber(r+1, c)] = DOWN;
            //vt.setVisited(r+1, c);
            g[r+1][c] = g[r][c] + 1;
            double f = h[r][c] + g[r+1][c];
            std::pair<int, int>loc = std::make_pair(r+1, c);
            pq.push(std::make_pair(loc, f));
        }
        if ( maze->canTravel(LEFT, r, c) )
        {
            p[squareNumber(r, c-1)] = LEFT;
            //setVisited(r, c-1);
            g[r][c-1] = g[r][c] + 1;
            double f = h[r][c] + g[r][c-1];
            std::pair<int, int>loc = std::make_pair(r, c-1);
            pq.push(std::make_pair(loc, f));
        }
        if ( maze->canTravel(RIGHT, r, c) )
        {
            p[squareNumber(r, c+1)] = RIGHT;
            //vt.setVisited(r, c+1);
            g[r][c+1] = g[r][c] + 1;
            double f = h[r][c] + g[r][c+1];
            std::pair<int, int>loc = std::make_pair(r, c+1);
            pq.push(std::make_pair(loc, f));
        }
    }   


    std::vector<Direction> path = pathCreator(p);
    display->reportSolution(path, vt, numExplored);


    
}




void MazeSolver::solveByDFSIterative()
{
    int r, c;
    int numSquares = maze->numRows() * maze->numCols();
    VisitedTracker vt(maze->numRows(), maze->numCols());

    std::vector<Direction> parent( numSquares ); // what was my immediate prior direction to get here?
    int numExplored = 0;
    vt.setVisited(maze->getStartRow(), maze->getStartCol());
    std::stack<std::pair<int, int>> q;
    q.push(std::pair<int,int>(maze->getStartRow(), maze->getStartCol()));

    while( ! q.empty() )
    {
        std::pair<int, int> v = q.top();
        q.pop();
        numExplored++;

        r = v.first;
        c = v.second;

        /* This one if statement is different from the pseudo-code provided
           in lecture, because we want to stop when we've reached the goal.
           The code provided in lecture was for if you wanted to do a BFS
           that explored the entire graph.
        */
        if( r == maze->getGoalRow() && c == maze->getGoalCol() )
        {
            std::vector<Direction> path;
            std::stack<Direction> st;

            while( r != maze->getStartRow() || c != maze->getStartCol())
            {
                st.push( parent[ squareNumber(r,c) ]);
                switch( st.top() )
                {
                case UP: r++; break; // yes, r++.  I went up to get here...
                case DOWN: r--; break;
                case LEFT: c++; break;
                case RIGHT: c--; break;
                }
            }
            while ( ! st.empty() )
            {
                path.push_back(st.top());
                st.pop();
            }
            display->reportSolution(path, vt, numExplored);
            return;
        }

        /*
         * Now we're back to code that looks like the pseudo-code you've seen.
         * The difference here is that we aren't keeping track of distances;
           that's similar to the difference above.  You could add, and ignore,
           the vector that would result if you wanted to do so.
         */
        if ( maze->canTravel(UP, r, c) && ! vt.isVisited(r-1,c))
        {
            parent[squareNumber(r-1, c)] = UP;
            vt.setVisited(r-1,c);
            q.push(std::pair<int,int>(r-1, c));
        }
        // Note:  this is NOT "else if" ...
        if ( maze->canTravel(DOWN, r, c) && ! vt.isVisited(r+1,c) )
        {
            parent[squareNumber(r+1, c)] = DOWN;
            vt.setVisited(r+1, c);
            q.push(std::pair<int,int>(r+1, c));
        }
        if ( maze->canTravel(LEFT, r, c) && ! vt.isVisited(r,c-1) )
        {
            parent[squareNumber(r, c-1)] = LEFT;
            vt.setVisited(r, c-1);
            q.push(std::pair<int,int>(r, c-1));
        }
        if ( maze->canTravel(RIGHT, r, c) && ! vt.isVisited(r, c+1) )
        {
            parent[squareNumber(r, c+1)] = RIGHT;
            vt.setVisited(r, c+1);
            q.push(std::pair<int,int>(r, c+1));
        }
    }
}

void MazeSolver::solveByBFS()
{
    /* In lecture on Tuesday March 22, we had a graph
       with vertices numbered 0 to n-1, inclusive.
       Instead, we have vertices with two numbers,
       row and col, in the range:
       [0, maze->numRows()-1], [0, maze->numCols() -1 ]
       to assign each a unique number [0, maze->numRows() * maze->numCols() -1]
       we will say that maze square (r,c) is really number
       r * maze->numCols() + c
    */
    int r, c;
    int numSquares = maze->numRows() * maze->numCols();
    VisitedTracker vt(maze->numRows(), maze->numCols());

    std::vector<Direction> parent( numSquares ); // what was my immediate prior direction to get here?
    int numExplored = 0;
    vt.setVisited(maze->getStartRow(), maze->getStartCol());
    std::queue<std::pair<int, int>> q;
    q.push(std::pair<int,int>(maze->getStartRow(), maze->getStartCol()));

    while( ! q.empty() )
    {
        std::pair<int, int> v = q.front();
        q.pop();
        numExplored++;

        r = v.first;
        c = v.second;

        /* This one if statement is different from the pseudo-code provided
           in lecture, because we want to stop when we've reached the goal.
           The code provided in lecture was for if you wanted to do a BFS
           that explored the entire graph.
        */
        if( r == maze->getGoalRow() && c == maze->getGoalCol() )
        {
            std::vector<Direction> path;
            std::stack<Direction> st;

            while( r != maze->getStartRow() || c != maze->getStartCol())
            {
                st.push( parent[ squareNumber(r,c) ]);
                switch( st.top() )
                {
                case UP: r++; break; // yes, r++.  I went up to get here...
                case DOWN: r--; break;
                case LEFT: c++; break;
                case RIGHT: c--; break;
                }
            }
            while ( ! st.empty() )
            {
                path.push_back(st.top());
                st.pop();
            }
            display->reportSolution(path, vt, numExplored);
            return;
        }

        /*
         * Now we're back to code that looks like the pseudo-code you've seen.
         * The difference here is that we aren't keeping track of distances;
           that's similar to the difference above.  You could add, and ignore,
           the vector that would result if you wanted to do so.
         */
        if ( maze->canTravel(UP, r, c) && ! vt.isVisited(r-1,c))
        {
            parent[squareNumber(r-1, c)] = UP;
            vt.setVisited(r-1,c);
            q.push(std::pair<int,int>(r-1, c));
        }
        // Note:  this is NOT "else if" ...
        if ( maze->canTravel(DOWN, r, c) && ! vt.isVisited(r+1,c) )
        {
            parent[squareNumber(r+1, c)] = DOWN;
            vt.setVisited(r+1, c);
            q.push(std::pair<int,int>(r+1, c));
        }
        if ( maze->canTravel(LEFT, r, c) && ! vt.isVisited(r,c-1) )
        {
            parent[squareNumber(r, c-1)] = LEFT;
            vt.setVisited(r, c-1);
            q.push(std::pair<int,int>(r, c-1));
        }
        if ( maze->canTravel(RIGHT, r, c) && ! vt.isVisited(r, c+1) )
        {
            parent[squareNumber(r, c+1)] = RIGHT;
            vt.setVisited(r, c+1);
            q.push(std::pair<int,int>(r, c+1));
        }
    }
}


int MazeSolver::squareNumber(int r, int c) const
{
    return maze->numCols() * r + c;
}


