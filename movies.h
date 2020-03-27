#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifndef MOVIES_H
#define MOVIES_H

/*class Movie{
    pubilc:
    void setName(string n);
    void setRate(double r);
    string getName() const;
    string getRate() const;
    private :
    string name;
    double rate;
};*/
    


class Node {
    public:
        Node(string n="", double r=0.0);
        ~Node();
        string getName() const;
        double getRate() const;
        Node* getRight() const;
        Node* getLeft() const;
        Node* getParent() const;
        int getHeight();
        int getHeightHelper(Node* n);
        void setName (string n);
        void setRate (double r);
        void incrementHeight();
        void setLeft(Node* n);
        void setRight(Node* n);
        void setParent(Node* n);
        string printNode();
   //maybe firend function for operator
        friend bool operator == (const Node& n1, const Node& n2);
        friend bool operator > (const Node& n1, const Node& n2);
        friend bool operator < (const Node& n1, const Node& n2);
    private:
        string name;
        double rate;
        Node* left;
        Node* right;
        Node* parent;
        int height;
};

class BST{
    public:
        BST(Node* p=0);
        ~BST();
        bool insert(Node* p);
        bool insertHelper(Node* p,Node* root);
        string preOrder() const;
        Node* preOrderTraversal(Node* root);
        void printPreorder() const;//according to rate
        string printPreorderHelper(Node* root) const;
        //bool contains(Node* n, Node* root);
        void searchPrefix(string prefix);
        
        void  searchPrefixHelper (vector<Node*>& v, Node* n, string prefix);
        Node* search(Node* n,Node* root) const;
        int getHeight();
        int getHeightHelper(Node* n);
        void setroot(Node* root);
        Node * getRoot() const;
        Node *maximum();
        friend ostream& operator << (ostream& out, const BST&bst);
   private:
        Node* root;
        
};


#endif
