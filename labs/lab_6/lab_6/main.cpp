//
//  main.cpp
//  lab_6
//
//  Created by Christopher Chandler on 3/1/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
// ===========================================================================

// A SIMPLE LINKED LIST CLASS
// (note: it's ok that all the member variables are public for this tiny class)

class Node {
public:
    int value;
    Node* ptr;
};


// ===========================================================================

// a helper function to print the contents of a linked list of Nodes
void print_linked_list(const std::string &name, Node *my_linked_list) {
    // print the name of this list
    std::cout << name;
    // use a temporary pointer to walk down the list
    Node *tmp = my_linked_list;
    while (tmp != NULL) {
        // print out each element
        std::cout << " " << tmp->value;
        tmp = tmp->ptr;
    }
    std::cout << std::endl;
}


Node* make_linked_list_from_STL_list(const std::list<int> &lst) {
    
    // create a linked list chain of Nodes, populating the structure
    // with the data in the STL list
    Node* ll = new Node;
    Node* curnode=ll;
    std::list<int>::const_iterator i=lst.begin();
    for (int j=0;j<lst.size();j++){
        curnode->value=*i;
        if (j==lst.size()-1){
            curnode->ptr=NULL;
            break;
        }
        curnode->ptr=new Node;
        curnode=curnode->ptr;
        i++;
    }
    // NOTE: this code should work for input STL lists of arbitrary
    // length
    return ll;
}


// YOU NEED TO WRITE THIS FUNCTION
Node* reverse_nodes_in_linked_list(Node *input) {
    
    // rearrange the pointers in the linked list chain of Nodes,
    // so that the structure is reversed.
    
    
    //Get length of linked list
    Node* curnode=input;
    int l=0;
    while (curnode->ptr!=NULL){
        curnode=curnode->ptr;
        l++;
    }
    l++;
    
    //reverse the nodes
    Node* current=input;
    Node* next=current->ptr;
    Node* previous=NULL;
    while(next!=NULL){
        current->ptr=previous;
        previous=current;
        current = next;
        next=next->ptr;
    }
    current->ptr = previous;
    return current;
}
    // rearrange the pointers in the linked list chain of Nodes,
    // so that the structure is reversed.
    
    // NOTE: Do not edit the values of the Nodes.  Do not create any new
    // Node objects (don't call 'new').  Instead, change the ptrs of the
    // existing Nodes to shuffle the order.
    


void reverse_vector(std::vector<int>& v){
    int oldi=0;
    for (int i=0;i<v.size()/2;i++){
        oldi=v[i];
        v[i]=v[v.size()-(i+1)];
        v[v.size()-(i+1)]=oldi;
    }
}
void print_vec(std::vector<int>& v){
    std::cout<<"vector printed: ";
    for(int i=0; i<v.size(); i++){
        std::cout<<v[i]<<", ";
    }
    std::cout<<std::endl;
}
std::vector<int> fill_vec(int step){
    std::vector<int> out(99);
    int hold = step*100;
    for(int i=1; i<hold; i+=step){
        out[i/step] = i;
    }
    return out;
}
void print_list(std::list<int>& v){
    std::cout << "size: " << v.size() << std::endl;
    std::cout <<"list printed: ";
    for (std::list<int>::iterator i=v.begin();i!=v.end();i++){
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
}

void reverse_list(std::list<int>& v){
    int oldi=0;
    std::list<int>::reverse_iterator ri=v.rbegin();
    std::list<int>::iterator i=v.begin();
    for (int j=0;j<v.size()/2;j++){
        oldi=*i;
        *i=*ri;
        *ri=oldi;
        ++ri;
        i++;
    }
}
std::list<int> fill_list(int size, int step){
    std::list<int> a;
    for(int i =1; i<size;i++){
        a.push_back(i*step);
    }
    return a;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::vector<int> this_vec = {0,1,2,3,4,5,6};
    print_vec(this_vec);

    reverse_vector(this_vec);
    print_vec(this_vec);
    std::vector<int> big_vector = fill_vec(47);
    print_vec(big_vector);
    reverse_vector(big_vector);
    print_vec(big_vector);
    std::list<int> small_list = fill_list(15, 47);
    print_list(small_list);
    reverse_list(small_list);
    print_list(small_list);
    std::list<int> big_list = fill_list(100, 710);
    print_list(big_list);
    reverse_list(big_list);
    print_list(big_list);
    
    Node* a = new Node;
    a->value = 6;
    a->ptr = new Node;
    a->ptr->value = 7;
    a->ptr->ptr = new Node;
    a->ptr->ptr->value = 8;
    a->ptr->ptr->ptr = new Node;
    a->ptr->ptr->ptr->value = 9;
    a->ptr->ptr->ptr->ptr = NULL;
    // print out this list
    print_linked_list("a",a);
    
    // create an STL list with 4 elements
    std::list<int> b;
    b.push_back(10);
    b.push_back(11);
    b.push_back(12);
    b.push_back(13);
    
    // use the STL list as input to a creator function that creates
    // linked lists with the same data
    Node* c = make_linked_list_from_STL_list(b);
    // print that data
    print_linked_list("c",c);
    
    //
    // WRITE A FEW MORE TEST CASES OF make_linked_list_from_STL_list
    //
    
    
    // reverse a linked list of nodes
    Node* d = reverse_nodes_in_linked_list(c);
    // print this data
    print_linked_list("d",d);
    
    //
    // WRITE A FEW MORE TEST CASES OF reverse_nodes_in_linked_list
    return 0;
}
