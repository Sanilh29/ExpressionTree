#include <cstring>

using namespace std;

class BinaryNode{
 public:
  BinaryNode (char input);
  BinaryNode (int input);
  ~BinaryNode();
  BinaryNode* getLeft();
  BinaryNode* getRight();
  char getDatac();
  int getDatai();
  int getType();
  void setLeft(BinaryNode* n);
  void setRight(BinaryNode* n);
  void printData();
 private:
  BinaryNode* right;
  BinaryNode* left;
  int type;
  char datac;
  int datai;
};
