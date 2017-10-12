#include <fstream>

//generate valid encodings based 
class encoder {
  std::ofstream file;
  int index;
  char c;
  char buffer;
  void add_bit(int bit);
  
 public:
    encoder();
    void compress();
    void close();
};
