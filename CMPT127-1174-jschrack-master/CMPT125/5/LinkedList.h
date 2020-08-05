#include "Node.h"
 
class LinkedList{
private:
  Node* head;
  Node* tail;
 
  // PRE:
  // PARAM: current = node to be searched
  //        target = value to be searched for
  // POST: recursive helper method for LLsearch
  int searchHelper(Node* current, int target);
 
public:
  // Default (and only constructor)
  LinkedList();
 
  // Destructor
  ~LinkedList();
 
  // PRE:
  // POST: Returns 1 if list is empty, 0 otherwise
  int empty();
 
  // PRE:
  // PARAM: value = value to be appended
  // POST: Adds a new element to the tail of list
  void append(int value);
 
  // PRE:
  // PARAM: value = value to be inserted
  // POST: Adds a new element to the head of list
  void prepend(int value);
 
  // PRE: list is non-empty
  // POST: Removes element from head of list, and returns value
  int removeHead();
 
  // PRE: list is non-empty
  // POST: Removes element from tail of list, and returns value
  int removeTail();
 
  // PRE:
  // POST: prints list elements from head to tail
  void print();
 
  // PRE:
  // PARAM: list = list to be inserted at end of calling object
  // POST: concatenates list with calling object and frees memory
  //       associated with list parameter
  void concatenate(LinkedList & list);
 
  // PRE:
  // PARAM: target = value to be searched for
  // POST: returns true if target is in list, false otherwise
  bool search(int target);
};