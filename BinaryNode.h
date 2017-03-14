//Sanil Hattangadi, 3/14/17
//initializes methods and variable names
#include <cstring>

using namespace std;

class BinaryNode{
 public:
  BinaryNode (char input);//constructor
  BinaryNode (int input);
  ~BinaryNode();//deconstructor
  BinaryNode* getLeft();//gets left node
  BinaryNode* getRight();//gets right node
  char getDatac();//gets char data
  int getDatai();//gets int data
  int getType();//gets type
  void setLeft(BinaryNode* n);
  void setRight(BinaryNode* n);
  void printData();
 private:
  //variables
  BinaryNode* right;
  BinaryNode* left;
  int type;
  char datac;
  int datai;
};
