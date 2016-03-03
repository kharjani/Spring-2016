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

  // Insert an item at the head.
  list->insert(0, 3);
  list->insert(1, 8);
  list->insert(2, 31);
  list->insert(3, 75);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after 4 insertions." << endl;
  } else {
    cout << "FAIL: List is empty after 4 insertions." << endl;
  }

  if (list->size() == 4) {
    cout << "SUCCESS: List has size 4 after 4 insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after 4 insertions.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(2) == 3) {
    cout << "SUCCESS: 3 is at the 2nd index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 2nd index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }
  

  // Clean up memory.
  delete list;
}
