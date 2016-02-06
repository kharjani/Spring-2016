#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt * list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Calls to insert function
  list->insert(0, 88);
  
  list->insert(1, 3);
  
  list->insert(2, 14);
  
  list->insert(1, 5);
  list->insert(4, 28);
  list->insert(-3, 31);
  //current list is: 88 5 3 14 28


  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after 5 insertions." << endl;
  } else {
    cout << "FAIL: List is empty after 5 insertions." << endl;
  }
  // Check if there are 5 items in the list.
  if (list->size() == 5) {
    cout << "SUCCESS: List has size 5 after the insertions." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after 5 insertions." << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 88) {
    cout << "SUCCESS: 88 is at the 1st index of the list." << endl;
  } else {
    cout << "FAIL: 88 is not at the 1st index of the list, " << list->get(1) << " is instead." << endl;
  }

  list->remove(2);
  // Check if the value is correct.
  if (list->get(2) == 14) {
    cout << "SUCCESS: 14 is at the 2nd index of the list, remove function worked" << endl;
  } else {
    cout << "FAIL: 14 is not at the 2nd index of the list, " << list->get(2) << " is instead." << endl;
  }


  // Clean up memory.
  delete list;
}
