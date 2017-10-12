#include "define.h"
#include "encoder.h"

encoder::encoder() {
  file.open(OUT_FILE_NAME , std::ios::binary);
  index = 0;
  buffer = 0;
}

void encoder::close() {
    file.close();
}

void encoder::add_bit(int bit) {

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
void encoder::compress() {

    while ((c = getchar()) != EOF) {
    switch(c) {
    case '0': {
      add_bit(0);
      add_bit(1);
      break;
    }
    case '1': {
      add_bit(0);
      add_bit(0);
      add_bit(1);
      break;
    }
    case '5': {
      add_bit(1);
      add_bit(1);
      add_bit(0);
      add_bit(1);
      break;
    }
    case '2': {
      add_bit(1);
      add_bit(1);
      add_bit(0);
      add_bit(0);
      break;
    }
    case '3': {
      add_bit(1);
      add_bit(0);
      add_bit(1);
      add_bit(1);
      break;
    }
    case '7': {
      add_bit(1);
      add_bit(0);
      add_bit(1);
      add_bit(0);
      break;
    }
    case '9': {
      add_bit(1);
      add_bit(0);
      add_bit(0);
      add_bit(0);
      break;
    }
    case '4': {
      add_bit(0);
      add_bit(0);
      add_bit(0);
      add_bit(1);
      break;
    }
    case '.': {
      add_bit(1);
      add_bit(1);
      add_bit(1);
      add_bit(1);
      add_bit(1);
      break;
    }
    case 'e': {
      add_bit(0);
      add_bit(0);
      add_bit(0);
      add_bit(0);
      break;
    }
    case '6': {
      add_bit(1);
      add_bit(1);
      add_bit(1);
      add_bit(1);
      add_bit(0);
      break;
    }
    case ' ': {
      add_bit(1);
      add_bit(1);
      add_bit(1);
      add_bit(0);
      add_bit(1);
      break;
    }
    case '8': {
      add_bit(1);
      add_bit(1);
      add_bit(1);
      add_bit(0);
      add_bit(0);
      break;
    }
    case '-': {
      add_bit(1);
      add_bit(0);
      add_bit(0);
      add_bit(1);
      add_bit(1);
      break;
    }
    case '+': {
      add_bit(1);
      add_bit(0);
      add_bit(0);
      add_bit(1);
      add_bit(0);
      add_bit(1);
      break;
    }
    case '\n': {
      add_bit(1);
      add_bit(0);
      add_bit(0);
      add_bit(1);
      add_bit(0);
      add_bit(0);
      break;
    }
    default: printf("error");
    }
  }

  //fill up the extra space in the last char
  for (;index<=7;index++){
    add_bit(0);
  }
}
