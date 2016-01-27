#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  int **objSize; // keeps track of number of possessions of each student
  string ***trojans; 
  string curr;

  input >> floors;
  trojans = new string**[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];
  objSize = new int*[floors]; 
  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
	  objSize[i] = NULL; //students dont' exist
  }
  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
			  continue;
		  }
		  else {
		  	if (i<0 || i>=floors){
		  		output << "Error - floor " << i << " does not exist" << endl;
		  		continue;
		  	}
		  	else if (trojans[i] != NULL){
		  		output << "Error - floor " << i << " is not empty" << endl;
		  		continue;
		  	}
		  	else{
		  		objSize[i] = new int[k];
		  		floorsizes[i] = k;
		  		trojans[i] = new string *[k];
		  		for (int n=0; n < k; n++){
		  			objSize[i][n] = 0; //student exists but has 0 possessions (currently)
		  		}
		  		
		  	}


		  }
	  }
	  else if (curr == "MOVEOUT") {
	  	int i;
	  	ss >> i;

	  	if (trojans[i] != NULL){
		  	for(int j=0; j < floorsizes[i]; j++){
		  		if (trojans[i][j] != NULL){ // If the student exists
		  			if (objSize[i][j] != 0){ // If the student has possessions
		  				
		  				delete [] trojans[i][j];
		  				
		  				delete [] objSize[i];
		  				objSize[i] = NULL;
		  			}
		  		}
		  		
		  	}
		  	delete [] trojans[i];
		  	trojans[i] = NULL;
		  	floorsizes[i] = 0;
		}
		else{
			if (i<0 || i>=floors){
				output << "Error - floor " << i << " does not exist" << endl;
		  		continue;
		  	}
		  	else if (trojans[i] == NULL){
		  		output << "Error - floor " << i << " is empty" << endl;
		  		continue;
		  	}
		}

	  }
	  else if (curr == "OBTAIN") {
	  	int i, j, k;
	  	ss >> i;
	  	ss >> j;
	  	ss >> k;
	  	if ((trojans[i]!=NULL) && (objSize[i][j] == 0)){ 	  	
		  	trojans[i][j] = new string[k];
		  	objSize[i][j] = k;
		  	for (int m=0; m < k; m++){
		  		string object;
		  		ss >> object;
		  		trojans[i][j][m] = object;
		  	}
		}
		else{
			if(trojans[i]==NULL||trojans[i][j] == NULL){
				output << "Error - floor/student invalid" << endl;
				continue;
			}
			if (objSize[i][j] !=0){
				output << "Error - student already has possessions" << endl;
				continue;
			}

		}
	  }
	  else if (curr == "OUTPUT") {
	  	int i, j;
	  	ss >> i;
	  	ss >> j;
	  	//checks: does floor exist, does floor have students, is student# within floorsizes[i], does that student have any possessions
	  	if(i<0 || i>=floors || trojans[i]==NULL){
	  		output << "Error - floor invalid" << endl;
	  	}
	  	else if(trojans[i]==NULL){
	  		output << "Error - floor " << i << "has no students" << endl;
	  	}
	  	else if (j<0 || j>=floorsizes[i]){
	  		output << "Error - student invlaid" << endl;
	  	}
	  	else if((objSize[i][j]==0)){
				output << "Error - student has no possessions" << endl;
				continue; 
			}
		else {
			for (int k=0; k < objSize[i][j]; k++){
	  			output << trojans[i][j][k] << endl;
	  		}
		}
		
	  }
	  else {
	  	if (curr == "") continue;
	  	output << "Error - Try again" <<  endl;
	  	continue;
	  }
  }
  // for each floor, check if NULL - if not then for each student check if they have possessions - if yes-delete possessions then student
  // Memory cleanup
  for (int i=0; i < floors; i++){
  	if(trojans[i] == NULL) continue;
  	else{
  		for(int j=0; j < floorsizes[i]; j++){
  			if (objSize[i][j] == 0) continue;
  			else{
  				for(int k=0; k < objSize[i][j]; k++)
  				delete [] trojans[i][j];	
  			}
  			//delete trojans[i][j];

  		}
  		delete [] trojans[i];
  		delete [] objSize[i];
  	}
  }

  delete [] floorsizes;
  //for objSize - go through each floor, check if null - if not then check for each  student if they have possessions - if yes-deletepossesion then 
  return 0;
}
