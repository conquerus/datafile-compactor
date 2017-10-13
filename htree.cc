#include "define.h"
#include "htree.h"

htree::htree() {
  size = 0;
}

int htree::SizeIsOne() {
  return (size==1);
}

node * htree::RootNode(){
  return elem;
}

void htree::DeleteNode() {
  size--;
  elem[0] = elem[size] ;

  Heapify(0) ;
}

void htree::InsertNode(double weight, node * left, node * right) {
  node nd ;
  nd.label = '\0' ;
  nd.weight = weight ;
  nd.left = left;
  nd.right = right;

  int i = size++ ;
  while(i && nd.weight < elem[PARENT(i)].weight) {
    elem[i] = elem[PARENT(i)] ;
    i = PARENT(i) ;
  }
  elem[i] = nd ;
}

void htree::Swap(int i, int j) {
  node temp = elem[i] ;
  elem[i] = elem[j] ;
  elem[j] = temp ;
}

//min heapify
void htree::Heapify(int i) {
  int smallest = (LCHILD(i) < size && elem[LCHILD(i)].weight < elem[i].weight) ? LCHILD(i) : i ;
  if(RCHILD(i) < size && elem[RCHILD(i)].weight < elem[smallest].weight) {
    smallest = RCHILD(i) ;
  }
  if(smallest != i) {
    Swap(i, smallest) ;
    Heapify(smallest) ;
  }
}

//build the initial heap structure
void htree::BuildHeap(char label[], double *weight, int size_in) {
  int i ;

  size = size_in;
  // Insertion into the heap without violating the shape property
  for(i = 0; i < size_in; i++) {
    elem[i].label = label[i];
    elem[i].weight = weight[i];
    elem[i].left = NULL;
    elem[i].right = NULL;
  }

  // Making sure that heap property is also satisfied
  for(i = (size - 1) / 2; i >= 0; i--) {
    Heapify(i) ;
  }
}

//build the huffman tree using the min heap
void htree::BuildHuffman() {
  node min_nodes [NUM_CHARS*NUM_CHARS];
  double newweight=0.0;

  int count = 0;
  while (!SizeIsOne()) {
    //delete two lowest weights
    min_nodes[count]=elem[0];
    DeleteNode();
    count++;
    min_nodes[count]=elem[0];
    DeleteNode();
    count++;
    //add node with old nodes as children and the sum of their weights
    newweight= min_nodes[count-2].weight+min_nodes[count-1].weight; 
    InsertNode(newweight, min_nodes+count-2, min_nodes+count-1);
  }
}

// Prints huffman codes from the root of Huffman Tree.  It uses arr[] to
// store codes
void htree::PrintHuffman(node * root, int arr[], int top)
{
  // Assign 0 to left edge and recur
  if (root->left)
    {
      arr[top] = 0;
      PrintHuffman(root->left, arr, top + 1);
    }

  // Assign 1 to right edge and recur
  if (root->right)
    {
      arr[top] = 1;
      PrintHuffman(root->right, arr, top + 1);
    }

  // If this is a leaf node, then it contains one of the input
  // characters, print the character and its code from arr[]
  if (root->label!='\0')
    {
      printf("%c: ", root->label);
      for (int i = 0; i<top; i++){
        printf("%d", arr[i]);
      }
      printf("\n");
    }
}
