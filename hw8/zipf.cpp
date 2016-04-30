#include <iostream>
#include <ctime>
#include "splayTree.h"
#include "hasTable.h"

int main(int argc, char* argv[]){

	clock_t start;
    double duration;

    start = clock();

    /* Your algorithm here */

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << duration << endl;





	return 0;
}