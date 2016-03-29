#ifndef MultiLL_h_
#define MultiLL_h_

#include <cassert>

//------------------------------------------------------------------------------------------------------//

template <class T>
class Node{
public:
    Node() : next_(NULL), prev_(NULL) {}
    Node(const T& v) : value_(v), next_(NULL), prev_(NULL) {}
    
    // REPRESENTATION
    T value_;
    Node<T>* next_;
    Node<T>* prev_;
};


template <class T>
class MultiLL {
public:
    MultiLL() : head_(NULL), tail_(NULL), size_(0) {}

private:
    void destroy_list();
    void add();
    Node<T>* head_;
    Node<T>* tail_;
    unsigned int size_;

};

#endif