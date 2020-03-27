#include<iostream>
#include<string>
#include"movies.h"
#include<iomanip>
#include<sstream>
#include "math.h"
using namespace std;


BST :: BST(Node *r){
    root=r;
}

BST :: ~BST(){
    delete root;
}

bool BST :: insert(Node* n){
    if (!this->getRoot()){
        this->setroot(n);
        //cout<< root->getName()<<endl;
        return true;
    }
   
    return insertHelper(n,this->getRoot());
}

bool BST :: insertHelper(Node* n , Node* root){
    if (n->getName() == root->getName()){
        return false;
    }
    else if (n->getName() < (root->getName())){
        if (root->getLeft()){
            n->incrementHeight();
            return insertHelper(n , root->getLeft());
            }
        else{
            root->setLeft(n);
            n->setParent(root);
            n->incrementHeight();
            return true;
        }
    }
    else{
        if (root->getRight()){
            n->incrementHeight();
            return insertHelper(n, root->getRight());
        }
        else{
            root->setRight(n);
            n->setParent(root);
            n->incrementHeight();
            return true;
        }
         }
}

void BST :: printPreorder() const{
    cout<<(this->preOrder())<<endl;
}

string BST :: preOrder() const{
    return printPreorderHelper(root);
}

string BST :: printPreorderHelper(Node * root) const{
    if (root==NULL) {
        return "";
    }
    return root->printNode()+"\n" +printPreorderHelper(root->getLeft())+ printPreorderHelper(root->getRight());
}

/*bool BST :: contains(Node*n, Node* root){
    if (!root || !n){
        return false;
        }
    if (*n == *root) {
      return true;
    }
    if ( *n > *root) {
        return contains(n, root->getRight());
    }
    return contains(n, root->getLeft());
}*/
Node* BST :: search(Node* n, Node* root) const{
    if (!root || !n){
        return NULL;
    }
    if (*n == *root) {
        return root;
    }
    if ( *n > *root) {
        return search(n, root->getRight());
    }
    return search(n, root->getLeft());
}

void Node:: incrementHeight(){
    height++;
}

int Node :: getHeight() {
    return height;
}

int Node :: getHeightHelper(Node* n){
    if (!n){
        return -1;
    }
    int leftHeight = getHeightHelper(n->getLeft());
    int rightHeight = getHeightHelper(n->getRight());
    if(leftHeight>rightHeight){
        return 1+leftHeight;
    }
    else{
        return 1+rightHeight;
    }
}
Node* BST :: maximum(){
    return NULL;
}//change later

void BST :: setroot(Node* root){
    this->root =root;
}
Node* BST :: getRoot() const{
    return root;
}

Node :: Node(string n, double r){
    height=0;
    name = n;
    rate=r;
    right=NULL;
    left=NULL;
    parent=NULL;
}
Node :: ~Node(){
    if (this->getLeft()){
        delete this->getLeft();
    }
    if(this->getRight()){
        delete this ->getRight();
    }
}

string Node :: getName() const {
    return name;
}
double Node :: getRate() const{
    return rate;
}
Node* Node::getLeft() const{
    return left;
}

Node* Node :: getRight()const{
    return right;
}
Node* Node:: getParent() const{
    return parent;
}
void Node :: setName (string n){
    name=n;
}
void Node :: setRate(double r){
    rate=r;
}
void Node :: setLeft(Node* n){
    left=n;
}
void Node :: setRight(Node* n){
    right=n;
}
void Node :: setParent(Node* n){
    parent=n;
}
bool operator == (const Node& n1, const Node& n2){
     if (n1.getName()==n2.getName() && n1.getRate()==n2.getRate()){
         return true;
     }
     return false;
 }
bool operator > (const Node& n1, const Node& n2){
      if (n1.getName()=="" ||n2.getName()==""||n1.getRate()<0||n2.getRate()<0){
          return false;
      }
      if (n1.getName()>n2.getName()){
          return true;
      }
      return false;
  }
bool operator < (const Node& n1, const Node& n2){
    return (n2>n1);
}

string Node ::printNode(){
    stringstream stream;
    if (fmod(this->getRate()*10,10)==0){
    //if( (((this ->getRate()*10))%10.0)==0){
    stream << fixed<<setprecision(0)<<(this->getRate());
    return (this->getName()+ ", "+ (stream.str())+", "+to_string(this->getHeight()));
}
    else{
        stream << fixed<<setprecision(1)<<(this->getRate());
        return (this->getName()+ ", "+ (stream.str())+", "+to_string(this->getHeight()));
    }
}
ostream & operator << (ostream& out, const BST& bst){
    string s =bst.preOrder();
    out<<s<<endl;
    return out;
}

void BST::searchPrefix(string prefix){
    vector<Node*> v;
    searchPrefixHelper( v, root, prefix );
    string y=v[0]->getName();
    double x=v[0]->getRate();
    for (int i=0; i<v.size();i++){
        if (x<v[i]->getRate()){
            x=v[i]->getRate();
            y=v[i]->getName();
        }
    }
    cout<<"Best movie is "<<y<<" with rating "<<x<<endl;
}
void  BST:: searchPrefixHelper(vector<Node*>& v, Node* n, string prefix ){
    if (!n){
        return;
    }
    if(n->getName().find(prefix)==0){
        v.push_back(n);       
    }
    searchPrefixHelper(v, n->getLeft(), prefix);
    searchPrefixHelper(v, n->getRight(),prefix);
 }

