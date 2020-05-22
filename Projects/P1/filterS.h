/**
   Jocelin Darma
   10/04/2018
   version 1.0

   Purpose:
    Headers for filterS type
   
   Class Description:
    A filterS is much like a regular stack but it stores only filtered numbers. Each filterS object encapsulates a stable integer, X, that
    varies from object to object. The stack stores only values that are NOT evenly divisible by X. It doubles in size automatically if storage
    space is exceeded.
**/

#ifndef FILTERS_H
#define FILTERS_H

class filterS
{
  /**
   * Constructor for filterS
   * @param divisor the integer that is to be assigned to X
   * @param s default size
   */
  filterS(int x, unsigned s = 100)
    {maxSize = s; stackList = new int[maxSize]; top = 0; X = x;}

  
  filterS(const filterS& otherStack);
  void operator=(const filterS& rhs);
  ~filterS();

  bool isEmpty() const;
  bool isFull() const;
  int getTop() const;
  void push(int num);
  void pop();

 private:
  int X; //divisor
  int maxSize;
  int top;
  int* stackList;
  bool filter(int num);
  void resize();
};

#endif
