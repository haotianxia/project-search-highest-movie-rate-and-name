#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"
using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  
  string line, movieName;
  double movieRating;
  if (flag==true){ 
  if (movieFile.fail()){
    cerr << "Could not open file " << argv[1];
    exit(1);
  }
  
  string prefix=argv[3];

  //cout << "adding: " << endl;
  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file

  // Read each file and store the name and rating
  BST b1;
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects
    Node* n=new Node;
    n->setName(movieName);
    n->setRate(movieRating);
    //cout<<"inserting: " << movieName << endl;

    b1.insert(n);
    //cout << movieName << " has rating " << movieRating << endl;
  }
  movieFile.close();
  b1.printPreorder();
/* Node* ptr=b1.getRoot();
  while (!ptr){
    ptr->getName();
    for ( i=0; i<prefix.size();i++){
       if (prefix[i]!=ptr->getName()[i]){
           return false;
       }
    }return true;
}}*/
b1.searchPrefix(prefix);
  }
else{
    //string line, movieName;
    //double movingRating;
    if (movieFile.fail()){
    cerr << "Could not open file " << argv[1];
    exit(1);
}
    int w = std::stoi(argv[3]);
    BST b2;
    vector<Node*> v;
    clock_t t;
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        Node *n=new Node;
        n->setName(movieName);
        n->setRate(movieRating);
        v.push_back(n); 
        b2.insert(n);
    }
    movieFile.close();
    for (int i=0; i<w;i++){
        
        t=clock();
        for(int j=0;j<v.size();j++){
            b2.search(v[j],b2.getRoot());
        }
        t=clock()-t;
        cout<<t<<endl;
   }

    
 }
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

