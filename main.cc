#include "htree.h"
#include "encoder.h"
              
int main()
{

  htree main_tree;
  node * huffman;

  //these are generated using ./char_count.cc (should be generalized)
  char testc[NUM_CHARS] = {'+', '-', 'e', '.', ' ', '\n', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  double testd[NUM_CHARS] = {0.0242, 0.0336, 0.0471, 0.0471, 0.0449, 0.0022, 0.2335, 0.1044, 0.0731, 0.0661, 0.0493, 0.0733, 0.0449, 0.0604, 0.0418, 0.0540};

  //build the min heap data structure
  main_tree.BuildHeap(testc, testd, NUM_CHARS);
  //build the Huffman binary tree
  main_tree.BuildHuffman();

  //pointer to the root node of the huffman tree
  huffman = main_tree.RootNode();

  //array to store the generated encoding
  if (PRINT) {
    int codes[8];
    main_tree.PrintHuffman(huffman, codes, 0);
  }

  //compress the file with encoder
  encoder enc;
  enc.Compress();
  enc.Close();

  return 0;
}
