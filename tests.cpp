#include"tests.h"
#include"movies.h"
#include <iostream>
#include <string>
#include<cassert>
#include<cstdlib>
using namespace std;
void test_insert(){
    BST b1;
    Node* n=new Node;
    n->setName("the");
    n->setRate(6.6);
    b1.insert(n);
    assert(b1.getRoot()->getName()=="the");
    assert(b1.getRoot()->getRate()==6.6);
    Node* p=new Node;
    p->setName("ziza");
    p->setRate(1.1);
    b1.insert(p);
    assert(b1.getRoot()->getRight()->getName()=="ziza");
    assert(b1.getRoot()->getRight()->getRate()==1.1);

}

int main(){
    test_insert();
        cout<<"pass test_insert"<<endl;
}
