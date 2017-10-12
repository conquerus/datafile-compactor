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
  int sizeIsOne();
  void deleteNode();
  void insertNode(double weight, node * left, node * right) ;
  void swap(int i, int j);
  void heapify(int i);
  node elem[SIZE];
 public:
  node * root_node();
  htree();
  void buildHeap(char label[], double *weight, int size_in);
  void buildHuffman();
  void printHuffman(node * root, int arr[], int top);

};
