#include "BinaryNode.h"
#include <cstring>
#include <iostream>

using namespace std;

BinaryNode::BinaryNode(int input){
  datai = input;
  type = 1;
  left = NULL;
  right = NULL;
}

BinaryNode::BinaryNode (char input){
  datac = input;
  type = 2;
  left = NULL;
  right = NULL;
}

BinaryNode::~BinaryNode(){
  left = NULL;
  right = NULL;
}

BinaryNode* BinaryNode::getLeft(){
  return left;
}

BinaryNode* BinaryNode::getRight(){
  return right;
}

char BinaryNode::getDatac(){
  return datac;
}

int BinaryNode::getDatai(){
  return datai;
}

int BinaryNode::getType(){
  return type;
}

void BinaryNode::setLeft(BinaryNode* n){
  left = n;
}

void BinaryNode::setRight(BinaryNode* n){
  right = n;
}

void printData(){
  if (type == 2){
    cout << datac << endl;
  }
  if (type == 1){
    cout << datai << endl;
  }
}
