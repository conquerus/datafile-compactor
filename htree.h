#include "define.h"
#include <stdio.h>

struct node {
  char label;
  double weight;

  node *left;
  node *right;
};

class htree {

 private:
  int size;
  node elem[SIZE];
  
  int SizeIsOne();
  void DeleteNode();
  void InsertNode(double weight, node * left, node * right) ;
  void Swap(int i, int j);
  void Heapify(int i);

 public:
  htree();
  node * RootNode();
  void BuildHeap(char label[], double *weight, int size_in);
  void BuildHuffman();
  void PrintHuffman(node * root, int arr[], int top);

};
