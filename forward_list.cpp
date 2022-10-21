#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Prototype.h"

int main()
{
    list<int> T = {1,2,3,8,34};
  //T.push_back(4);
  //T.push_back(5);
  //T.push_back(6);
  //T.push_back(7);
  //T.push_front(8);
  //T.push_front(13);
  //T.push_front(13);
 // T.push_front(11);
 // T.push_front(10);
    //list<int> M = {6,7,9,22};
   // T.assign(4,66);
   // T.swap(M);
     //T.remove(13);
   // T.pop_front();
   // T.pop_front();
    //T.sort();
    //T.merge(M);
    //T.resize(20);
   // T.reverse();
   // T.clear();
   // list<int>::iterator<int> it = T.begin();
    //T.insert_after(it,20);
   /////// T.erase_after(it,T.end());
    //T.erase_after(it);
    //for(;it != T.end();++it) {
     //   std::cout << *it << " ";
    //}
  //std::cout << std::endl;
  //list<int>::iterator<int> i = M.begin();
  //for(;i != M.end();++i) {
  //    std::cout << *i << " ";
  //}
    //std::cout << *it << std::endl;
    //list<int> ob;
    //ob = std::move(T);
    //ob.print_count();
    //list<int> copy = T;
    //copy.print_count();
    //list<int> move = std::move(T);
    //move.print_count();
    T.remove(34);
    std::cout << T << std::endl;
    //T.print_count();
    return 0;
}

