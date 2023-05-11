#include <Arduino.h>
#include <ShiftRegister.h>

ShiftRegister shift_register = ShiftRegister(2, 3, 4);

class Matrix{
  private:
    static const int vertical_count   = 8;
    static const int horizontal_count = 8;
    byte matrix[vertical_count*horizontal_count] = {0};
  
  public:
    byte GetRow(int index /* 0 <= index <= vertical_count*/){
      byte row = 0;
      for(int i = 0; i < horizontal_count; i++){
        int matrix_index = i + index*horizontal_count;
        row = row << 1;
        row = row + matrix[matrix_index];
      }
      return row;
    }
};

void setup() {
  shift_register.setup();
  byte vertical   = B01111111;
  byte horizontal = B01000000;
  shift_register.setLedRow(vertical);
  shift_register.setLedRow(horizontal);
  
}

void loop() {

}
