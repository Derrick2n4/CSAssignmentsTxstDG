#include <iostream>
#include <cassert>
#include "recursive_list.h"

//implementation of ADT

const unsigned int list_node_id = 0x11341134;
const unsigned int list_empty_id = 0x22452245;

struct ListNode {
      unsigned int ln_id;
      
      int ln_elt;
      struct ListNode *ln_rest: //rest of this list or null for empty node
};

//Modifies std::cerr

static struct ListNode *ListCheckValid(RecursiveList list){
      struct ListNode *lnp = (struct ListNode *) list; // assigns the value back to the struct point LNP
      
      if ((lnp ->ln_id != list_node_id) && (lnp-> ln_id !=list_empty_id)){ // pointer use arrow operator is used to the pointer of the object
                                                                           //value use dot operator is used to access object data   
            std::cerr<< "Error : user passed invalid list\n";
            assert(0);
      }
      retrun lnp;
}

static void ListCheckNonEmpty(RecursiveList list){
      if(ListIsEmpty(list)){
            std::cerr << "error: user passed empty list where non-empty required\n";
            assert(0);
      }
}
static void NotAllocated (){
      std::cerr<<"Your test case is too large for this machine\n";
      std::cerr<<"Try using a smaller test case\n";
}
//return true if list is empty other wise returns false
bool ListIsEmpty(RecursiveList list){
      struct ListNode *lnp = ListCheckValid(list);
      return (lnp->ln_id == list_empty_id);
}//end

//returns an empty list
RecursiveList MakeList(){
      struct ListNode *newp = 0;
      try{
            newp = new struct ListNode;
      } catch )std::bad_alloc a){
            NotAllocated();
      }
      newp->ln_id = list_empty_id;
      newp->ln_rest = NULL;
      return newp;
}
// EFFECTS: given the list, make a new list consisting of the new element
//          followed by the elements of the original list
RecursiveList MakeList (int elt, RecursiveList list) {
  struct ListNode *newp = 0;
  struct ListNode *restp = ListCheckValid(list);

  try {
    newp = new struct ListNode;
  } catch (std::bad_alloc a) {
    NotAllocated();
  }

  newp->ln_id = list_node_id;
  newp->ln_elt = elt;
  newp->ln_rest = restp;

  return newp;
}

// REQUIRES: list is not empty
// EFFECTS: returns the first element of list
int ListFirst (RecursiveList list) {
  ListCheckNonEmpty(list);
  struct ListNode *lnp = ListCheckValid(list);
  return lnp->ln_elt;
}

// REQUIRES: list is not empty
// EFFECTS: returns the list containing all but the first element of list
RecursiveList ListRest (RecursiveList list) {
  ListCheckNonEmpty(list);
  struct ListNode *lnp = ListCheckValid(list);
  return lnp->ln_rest;
}

// MODIFIES: std::cout
// EFFECTS: prints list contents to std::cout, with no parens
static void PrintListHelper (RecursiveList list) {
  if (ListIsEmpty(list)) {
    return;
  } else {
    std::cout << ListFirst(list) << " ";
    PrintListHelper(ListRest(list));
  }
}

// MODIFIES: std::cout
// EFFECTS: prints list to std::cout
void PrintList (RecursiveList list) {
  std::cout << "( ";
  PrintListHelper(list);
  std::cout << ")";
}