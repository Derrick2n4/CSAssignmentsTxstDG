#ifndef __RECURSIVE_LIST_H__
#define __RECURSIVE_LIST_H__

typedef void *RecursiveList;

//returns true if list is empty
extern bool ListIsEmpty(RecursiveList list);

//returns an empty lost
RecursiveList MakeList();

//given a list make a new list consisting of the new elemetns followed
// by the elements of the original list

RecursiveList MakeList(int elem, RecursiveList list);

// if list is not empty returns the first element of the lost 
extern int ListFirst(RecursiveList list);

// if list is not empty returns the list containing all but the first element
extern RecursiveList LisstRest(RecursiveList list);

//modifies std::cout
//Effects prints the list to std::cout
extern void PrintList(RecursiveList list);

#endif /*__RECURSIVE_H__*/