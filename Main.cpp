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

int main(){
  char command[100];
  cout << "Welcome to the translator. We can put an equation into Infix, Postfix, or Prefix Notation." << endl;
  bool running = true;
  while (running == true){
    cout << "Enter a command: translate or quit." << endl;
    cin.get(command, 100);
    cin.ignore();
    if (0 == strcmp(command, "quit")){
      running = false;
    }
    if (0 == strcmp(command, "translate")){
      char input[100];
      cout << "Enter an equation please." <<endl;
      cin.get(input, 100);
      cin.ignore();
      Stack* stack = shuntingYard(input);
      BinaryNode* head = Tree(stack);
      cout << "Tree:" << endl;
      print(head);
      cout << "Postfix:" << endl;
      Postfix(head);
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

void print(BinaryNode* n, int indent){
  if (n->getLeft()){
    print(getLeft(), indent+1);
    for (int i =0;i<=indent; i++){
      cout << "  ";
    } 
  }
  n->printData();
  cout << endl;
  if (n->getRight()){
    print(n->getRight(), indent+1);
  }
}

void Postfix(BinaryNode* n){
  if (n->getType() == 2){
    Postfix(n->getLeft());
    Postfix(n->getRight());
  }
  n->printData();
}

void Prefix(BinaryNode* n){
  n->printData();
  if (n->getType() == 2){
    Prefix(n->getLeft());
    Prefix(n->getRight());
  }
}

void Infix(BinaryNode* n){
  if (n->getType() ==2){
    Infix(n->getLeft());
    n->printData();
    Infix(n->getRight());
  }
  else{
    n->printData();
  }
}

BinaryNode* Tree(Stack* stack){
  BinaryNode* b;
  if (stack->peek()->getType() == 2){
    b = new BinaryNode(stack->pop()->getDatac());
    b->setLeft(Tree(stack));
    b->setRight(Tree(stack));
  }
  else {
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
