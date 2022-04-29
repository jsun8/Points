//point.h file
#ifndef POINT_H
#define POINT_H

#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <cmath>

template <typename T>   //for templates, the .h file includes the class declarations and the implementations, so there's only .h and main file
class Point{
public:
  Point();  //default constructor
  Point(int dimension);
  Point(int dimension, T arr[]);
  int getSize () const {
    return dimension;
  }
  T getArr(int i) const {
    return array[i];
  }
  void operator =(const Point<T> &p);   //member functions
  void operator +=(const Point<T> &p);

private:
  T array[10];
  int dimension;

};


template <typename T>
bool operator ==(const Point<T> &p, const Point<T> &p1);

template <typename T>
Point<T> operator +(const Point<T> &p, const Point<T> &p1);

template <typename T>
Point<T>::Point(){     //.h and .cpp files are in same doc for templates
  array[0] = T();
  dimension = 1;
}

template <typename T>
Point<T>::Point(int dimension) : dimension(dimension) {
  for (int i = 0; i < dimension; i++) {
    array[i] = T();
  }
}

template <typename T>
Point<T>::Point(int dimension, T arr[]) : dimension(dimension) {
  for (int i = 0; i < 10; i++) {
    array[i] = arr[i];
  }
}

template <typename T>
void Point<T>::operator =(const Point<T>& p) {
  dimension = p.dimension;
  for (int i = 0; i < p.dimension; i++) {
    array[i] = p.array[i];
  }
}


//5. B3       CHECK MARK
template <typename T>  //5. Implement the += operator
void Point<T>::operator +=(const Point<T> &p){
  if(dimension==p.dimension){
    for(int i=0;i<p.dimension; i++){
      array[i] += p.array[i];
    }
  }

  else if(dimension>p.dimension){
    for(int i=0;i<p.dimension;i++){
      array[i]+= p.array[i];
    }
    //for(int i=p.dimension;i<dimension;i++){                           CHECK MARK
    //array[i]=array[i];
    //}
  }

  else if(dimension<p.dimension){
    for(int i=0;i<dimension;i++){
      array[i]+=p.array[i];
    }
    for(int i=dimension;i<p.dimension;i++){
      array[i]=p.array[i];
    }
    dimension=p.dimension;     //set dimension equal to p.dimension because p.dimension is larger
  }
}
//6. B4         CHECK MARK
template <typename T>  //6. Implement the == operator
bool operator ==(const Point<T> &p, const Point<T> &p1){
  if(p.getSize()==p1.getSize()){   //for the points to be the same, they both have to have the same dimension(e.g. two dimension, six dimension, etc.)
    for(int i=0;i<p.getSize();i++){
      if(p.getArr(i)!=p1.getArr(i)){     //if an index in either array is different, the points aren’t the same.
        return false;                                         //  CHECK MARK
      }
    }
    return true;                    //if dimensions and points in the array are the same, returns true
  }
  else {         //if the dimensions aren’t the same, points cant be same
    return false;
  }
}

//6. B4       CHECK MARK
template <typename T>  //6. Implement the + operator
Point<T> operator +(const Point<T> &p, const Point<T> &p1){
  Point<T> sum=Point<T>();                  // set equal to default constructor
  sum+=p;
  sum+=p1;
  return sum;
}

//7. B5    CHECK MARK
template <typename T>
  double distance(const Point<T> &p, const Point<T> &p1){
  double p2 = 0;
  //assert(p.getSize()==p1.getSize());    //you can do either assert or if loop
  if(p.getSize()==p1.getSize()){
    for (int i=0;i<p.getSize();i++){
      //(pow((p[i]-p1[i]),2));
      p2 += pow((p.getArr(i)-p1.getArr(i)),2);  //calls the - operator
    }
  }
  double root = sqrt(p2);
  return root;
}

double operator -(const std::string &s1, const std::string &s2){
  double dist=s1[0]-s2[0]; //first character
  return dist;
}

/*
double distance(const Point<std::string> &p, const Point<std::string> &p1){
  double p2 = 0;
  //assert(p.getSize()==p1.getSize());    //you can do either assert or if loop
  if(p.getSize()==p1.getSize()){
    for(int i=0;i<1;i++){
    p2 += pow((p.getArr(0)-p1.getArr(0)),2);
  }
}
  double root = sqrt(p2);
  return root;
} */



#endif //point.h
