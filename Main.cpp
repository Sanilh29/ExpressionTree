//sanil Hattangadi, 3/14/17
//the program takes an equation and creates it into a tree and translates it into infix, postfix, and prefix
#include <cstring>
#include "Node.h"
#include "Stack.h"
#include "BinaryNode.h"
#include <iostream>
#include <stdlib.h>

int precedence(char operation);
bool isOperator(char o);
void Postfix(BinaryNode* n);
void Prefix(BinaryNode* n);
void Infix(BinaryNode* n);
void print(BinaryNode* n, int indent = 0);
Stack* shuntingYard(char* input);
BinaryNode* Tree(Stack* stack);

//my main
int main(){
  char command[100];//initialized varialbe
  cout << "Welcome to the translator. We can put an equation into Infix, Postfix, or Prefix Notation." << endl;
  bool running = true;
  while (running == true){//while playing
    cout << "Enter a command: translate or quit." << endl;
    cin.get(command, 100);
    cin.ignore();
    if (0 == strcmp(command, "quit")){//if quit is inputted, stop program
      running = false;
    }
    if (0 == strcmp(command, "translate")){//if translated in iputted
      char input[100];
      cout << "Enter an equation please." <<endl;//get an equation
      cin.get(input, 100);
      cin.ignore();
      Stack* stack = shuntingYard(input);
      BinaryNode* head = Tree(stack);//make tree
      cout << "Tree:" << endl;//
      print(head);//print it out
      cout << "Postfix:" << endl;
      Postfix(head);//print postfix
      cout << "Prefix:"  <<  endl;
      Prefix(head);//print prefix
      cout << "Infix:" << endl;
      Infix(head);//print infix
    }
  }
}

Stack* shuntingYard(char* input){//runs algorithm
  Stack* outputStack = new Stack();//creates output stack
  Stack* operatorStack = new Stack();//and operator stack
  int i = 0;//start counting at the first input
  while (input[i]){
    //cout << input << endl;
    if (isdigit(input[i])){//if the input is a number
      outputStack->push(new Node(atoi(&input[i])));//creates a new node and changes string to int
      while(isdigit(input[i+1])){//go to end of the number
	i++;
      }
    }
    if (isOperator(input[i])){ //if its a + - * / ^
      while (operatorStack->peek()){//while there is something on operator stack
	Node* o2 = operatorStack->peek();//create node that is on top of operator
	if (precedence(input[i]) >= precedence(o2->getDatai())){//check precedence
	  break;
	}
	outputStack->push(operatorStack->pop());//pop it
      }
      operatorStack->push(new Node(input[i]));
    }
    if (input[i] == '('){ //if the input is (
      operatorStack->push(new Node(input[i]));//push it
    }
    else if (input[i] == ')'){ //if the input is )
      while(operatorStack->peek()->getDatac() != '('){//while there is a ( on the top of the operator stack
	outputStack->push(operatorStack->pop());//pop
      }
      delete operatorStack->pop();
    }
    i++; //go the the next value in the input
  }
  while(operatorStack->peek()){//while there is something in the operator stack
    outputStack->push(operatorStack->pop());//push the the top of operator stack
  }
  delete operatorStack;
  return outputStack;
}

//actually print out the tree
void print(BinaryNode* n, int indent){
  if (n->getRight()){//get the left
    print(n->getRight(), indent+1);//indent it
  }
  for (int i =0;i<=indent; i++){ //prints out the space
    cout << "  "; 
  }
  n->printData();
  cout << endl;
  if (n->getLeft()){
    print(n->getLeft(), indent+1);
  }
}

//prints postfix: left, parent, right
void Postfix(BinaryNode* n){
  if (n->getType() == 2){//if char
    Postfix(n->getRight());//get left
    Postfix(n->getLeft());//get right
  }
  n->printData();
}

//prints prefix: symbol, left and hen right
void Prefix(BinaryNode* n){
  n->printData();//prints symbols
  if (n->getType() == 2){//if a char
    Prefix(n->getRight());//get left
    Prefix(n->getLeft());//get right
  }
}
//translates it into infix: prints left, right, parent
void Infix(BinaryNode* n){
  if (n->getType() ==2){//if its a char
    Infix(n->getRight());//recursive on itself
    n->printData();
    Infix(n->getLeft());
  }
  else{
    n->printData();
  }
}

//takes the values from the stack and makes it into a tree
BinaryNode* Tree(Stack* stack){//
  BinaryNode* b;
  if (stack->peek()->getType() == 2){//look if the top value is a char
    b = new BinaryNode(stack->pop()->getDatac());//create a new binary node
    b->setLeft(Tree(stack));//sets them to the left
    b->setRight(Tree(stack));
  }
  else {//if its a number, create a branch
    b = new BinaryNode (stack->pop()->getDatai());
  }
  return b;
}

bool isOperator (char o){//check to see if its an operator (+ - * / ^)
  if (o == '+' || o == '-' || o == '*' || o == '/' || o == '^'){
    return true;
  }
  return false;
}

int precedence(char operation){ //setting PEMDAS essentially. the greater the value, the more precedence
  int precedence[256] = {};
  precedence ['+'] = 1;
  precedence ['-'] = 1;
  precedence ['*'] = 2;
  precedence ['/'] = 2;
  precedence ['^'] = 3;
  return precedence[operation];
}
