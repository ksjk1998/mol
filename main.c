#include <stdio.h>
#include <math.h>

int getDigit(int digit, int number) {
  if (pow(10, digit-1)<number)
    return (int)(number/pow(10, digit-1)) % 10;
  else return -1;
}

int combineDigits(int number, int startDigit, int endDigit) {
  int out = 0;
  int multiplier = 1;
  while (startDigit<=endDigit) {
    out += getDigit(startDigit, number)*multiplier;
    multiplier *=10;
    startDigit++;
  }
  return out;
}

int decodeAtomId(int atomId, int *targetArray) {
  /*breaks down the atom id into an array of the numbers we need*/
  *targetArray = getDigit(1, atomId);
  *(targetArray+1) = getDigit(2, atomId);
  *(targetArray+2) = combineDigits(atomId, 3, 4);
  *(targetArray+3) = combineDigits(atomId, 5, 7);
  return 0;
}

int main() {
  printf("hello\n");
  fflush(stdout);
  int array[4];
  int id = 1010111;
  decodeAtomId(id, array);
  printf("%i", getDigit(4, id));
  printf("valence number: %i\n", array[0]);
  printf("atomic number: %i\n", array[3]);
  printf("column: %i\n", array[2]);
  printf("row: %i\n", array[1]);
  return 0;
}
