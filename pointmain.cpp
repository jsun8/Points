//main.cpp
#include "point.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  Point<int> p1 = Point<int>();   //default constructor
  cout<<"Default constructor p1:";
  for (int i = 0; i < p1.getSize(); i++) {
    cout << p1.getArr(i) << ",";
  }
  cout << endl;

  cout<<"Printing string list: ";
  string stringList[3] = {"843","j39d","words"};
  for(int i = 0; i < 3; i++){
  std::cout << stringList[i]<<" ";
}

cout<<endl;

  int newArray[4]={4,2,6,3};
  cout<<"Printing out p2:";
  Point<int> p2 = Point<int>(4, newArray);
  for (int i = 0; i < p2.getSize(); i++) {
    cout << p2.getArr(i) << ",";
  }
  cout << endl;

  int newArrayTwo[4]={1,6,3,2};
  Point<int> p3 = Point<int>(4, newArrayTwo);
  cout<<"Printing out p3:";
  for (int i = 0; i < p3.getSize(); i++) {
    cout << p3.getArr(i) << ",";
  }
  cout << endl;

  Point<int> p4 = p2+p3;  //6. B4:  test + operator
  cout<<"Testing + operator: p4 (p4 = p2+p3) is: ";
  for (int i = 0; i < p4.getSize(); i++) {  //if we want to print out the point
    cout << p4.getArr(i) << ",";
  }
  cout<<endl;

  p3+=p4;  //5. B3: test += operator
  cout<<"Testing += operator: p3 (p3+=p4) is: ";
  for (int i = 0; i < p3.getSize(); i++) {
    cout << p3.getArr(i) << ",";
  }
  cout << endl;

  int nA1[2]={3,7};  //7. B5: Testing distance
  Point<int> d1 = Point<int>(2, nA1);
  int nA2[2]={8,5};
  Point<int> d2 = Point<int>(2, nA2);
  cout<<"Testing distance: distance between these two points (3,7) and (8,5) is: "<<distance(d1,d2)<<endl;
  bool q=p2==p3;  //test == operator
  cout<<"Testing bool == operator: is p2==p3? (0 means false, 1 means true.):"<<" "<<q<<endl;

  cout<<"Testing distance between strings' first letters: "<<endl;  //7. B5. Testing distance strings
  string strArr[2] = {"Ei", "Pi"};
  Point<string> d3 = Point<string>(2, strArr);
  string strTwo[2]= {"Hi", "Ri"};
  Point<string> d4 = Point<string>(2, strTwo);
  //cout<<"distance between the first character of these two strings is"<<distance(d3,d4)<<endl;
  cout<<"Distance between strings' first letters is"<<distance(d3,d4);

  return 0;
}
