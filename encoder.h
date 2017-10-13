#include <fstream>

//generate valid encodings based 
class encoder {
  std::ofstream file;
  int index;
  char c;
  char buffer;
  
  void AddBit(int bit);
  
 public:
    encoder();
    void Compress();
    void Close();
};
