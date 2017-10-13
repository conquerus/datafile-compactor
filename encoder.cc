#include "define.h"
#include "encoder.h"

encoder::encoder() {
  file.open(OUT_FILE_NAME , std::ios::binary);
  index = 0;
  buffer = 0;
}

void encoder::Close() {
    file.close();
}

void encoder::AddBit(int bit) {

  if (index >= 7){
    //write to data file
    file.write(&buffer,sizeof(char));
    index = 0;
    buffer = 0;
  }
    
  if (bit){
    buffer ^= (-1 ^ buffer) & (1 << index);
  }
  else {
    buffer ^= (-0 ^ buffer) & (0 << index);
  }
  (index)++;
}

//hardcoded for this dataset...
void encoder::Compress() {

    while ((c = getchar()) != EOF) {
      
      switch(c) {
      case '0': {
        AddBit(0);
        AddBit(1);
        break;
      }
      case '1': {
        AddBit(0);
        AddBit(0);
        AddBit(1);
        break;
      }
      case '5': {
        AddBit(1);
        AddBit(1);
        AddBit(0);
        AddBit(1);
        break;
      }
      case '2': {
        AddBit(1);
        AddBit(1);
        AddBit(0);
        AddBit(0);
        break;
      }
      case '3': {
        AddBit(1);
        AddBit(0);
        AddBit(1);
        AddBit(1);
        break;
      }
      case '7': {
        AddBit(1);
        AddBit(0);
        AddBit(1);
        AddBit(0);
        break;
      }
      case '9': {
        AddBit(1);
        AddBit(0);
        AddBit(0);
        AddBit(0);
        break;
      }
      case '4': {
        AddBit(0);
        AddBit(0);
        AddBit(0);
        AddBit(1);
        break;
      }
      case '.': {
        AddBit(1);
        AddBit(1);
        AddBit(1);
        AddBit(1);
        AddBit(1);
        break;
      }
      case 'e': {
        AddBit(0);
        AddBit(0);
        AddBit(0);
        AddBit(0);
        break;
      }
      case '6': {
        AddBit(1);
        AddBit(1);
        AddBit(1);
        AddBit(1);
        AddBit(0);
        break;
      }
      case ' ': {
        AddBit(1);
        AddBit(1);
        AddBit(1);
        AddBit(0);
        AddBit(1);
        break;
      }
      case '8': {
        AddBit(1);
        AddBit(1);
        AddBit(1);
        AddBit(0);
        AddBit(0);
        break;
      }
      case '-': {
        AddBit(1);
        AddBit(0);
        AddBit(0);
        AddBit(1);
        AddBit(1);
        break;
      }
      case '+': {
        AddBit(1);
        AddBit(0);
        AddBit(0);
        AddBit(1);
        AddBit(0);
        AddBit(1);
        break;
      }
      case '\n': {
        AddBit(1);
        AddBit(0);
        AddBit(0);
        AddBit(1);
        AddBit(0);
        AddBit(0);
        break;
      }
      default: printf("error");
    }
      
  }

  //fill up the extra space in the last char
  for (;index<=7;index++){
    AddBit(0);
  }
}
