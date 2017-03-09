//sanil Hattangadi, node header that creates methods and variables
#include <cstring>
#ifndef NODE_H//header guard
#define NODE_H
using namespace std;

class Node {
 private://creates the variables
  char datac;//char data
  int datai;//int data
  Node* next;//next node pointer
 public://methods
  Node(char input);//constructor for char data
  Node(int input);//constructor for int data
  ~Node();//deconstructor
  void setNext(Node* newnode);//sets the next node
  Node* getNext();//gets the next node
  char getDatac();//gets char data
  int getDatai();//gets int data
};

#endif
