//Sanil Hattangadi, binary node.cpp, creates the moethods and algorithms
#include "BinaryNode.h"
#include <cstring>
#include <iostream>

using namespace std;

//contructor for int input
BinaryNode::BinaryNode(int input){
  datai = input;
  type = 1;
  left = NULL;//put branch nodes as null
  right = NULL;
}

//constrcotr for char input
BinaryNode::BinaryNode (char input){
  datac = input;
  type = 2;//put type to 2
  left = NULL;//node becomes null
  right = NULL;
}

//deconstructor; sets everything to NULL
BinaryNode::~BinaryNode(){
  left = NULL;
  right = NULL;
}

//gets left node
BinaryNode* BinaryNode::getLeft(){
  return left;
}

//gets right node
BinaryNode* BinaryNode::getRight(){
  return right;
}
//gets the char data
char BinaryNode::getDatac(){
  return datac;
}
//gets the int data
int BinaryNode::getDatai(){
  return datai;
}

//gets the type of the char/int data
int BinaryNode::getType(){
  return type;
}

//sets the left node
void BinaryNode::setLeft(BinaryNode* n){
  left = n;
}
//sets the right node
void BinaryNode::setRight(BinaryNode* n){
  right = n;
}

//prints the data 
void BinaryNode::printData(){
  if (type == 2){
    cout << datac << endl;
  }
  if (type == 1){
    cout << datai << endl;
  }
}
