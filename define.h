//the number of unique characters in the file to be compressed
#define NUM_CHARS 16

//name of the "compressed" file
#define OUT_FILE_NAME "outfile.yyz"

//do you want to print the Huffman encodings?
#define PRINT true

//a helpful family of functions
#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2
#define SIZE 1000
