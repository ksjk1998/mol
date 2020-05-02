#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int printArray(int* numbers, int size) {
  for (int i=0;i<size;i++) printf("%i, ", numbers[i]);
  printf("\n");
}

struct atom {
  int id;
  int valence;
  int row;
  int column;
  int atomicNumber;
  int maxBonds; // TODO: implement max bonds
  int nBonds;
  struct atom** bonds; // may need to know the types of bonds for certain interactions, if so we can add a separate array with bond ids
};

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

struct atom createAtom(int atomId) {
  struct atom atom;
  int traits[4];
  decodeAtomId(atomId, traits);
  atom.id = atomId;
  atom.valence = traits[0];
  atom.row = traits[1];
  atom.column = traits[2];
  atom.atomicNumber = traits[3];
  atom.nBonds = 0;
  atom.bonds = (struct atom**) malloc(0);
  if (!atom.bonds) {
    printf("out of memory error when trying to allocate no memory for atom id %i", atomId);
  }
  return atom;
}

int addAtom(struct atom *atom, struct atom **array, int size) {
  // adds an atom to an array
  struct atom **newArray = realloc(array, (sizeof(struct atom*)*(size+1)));
  if (!newArray) {
    return -1;
  } else {
    array = newArray;
    array[size] = atom;
  }
  return 0;
}

int removeAtom(struct atom *atom, struct atom **array, int size) {
  // removes atom from an array, name might be slightly confusing
  int index;
  struct atom** newArray;
  for (int i=0; i<size; i++) { // currently a naiive implementation, optimize later if this causes performance problems
    if (array[i] = atom) index = i;
  }
  for (int i=index; i<size; i++) {
    array[i] = array[i+1];
  }
  if (size>1) {
    newArray = (struct atom**) realloc(array, (sizeof(struct atom*)*(size-1)));
    if (!newArray) {
      return -1;
    } else {
      array = newArray;
    }
  }
  return 0;
}

int bond(struct atom *atom1, struct atom *atom2) {
  // bonds two atoms together
  int f1 = addAtom(atom1, atom2->bonds, atom2->nBonds);
  int f2 = addAtom(atom2, atom1->bonds, atom2->nBonds);
  if (f1 == -1 || f2 == -1) {
    printf("out of memory error trying to bond atom id %i to atom id %i", atom1->id, atom2->id);
    return -1;
  } else {
    atom1->nBonds++;
    atom2->nBonds++;
  }
  return 0;
}

int unbond(struct atom *atom1, struct atom *atom2) {
  removeAtom(atom1, atom2->bonds, atom2->nBonds); // TODO: add an error message here if something went wrong in removeAtom
  removeAtom(atom2, atom1->bonds, atom1->nBonds);
  atom1->nBonds--;
  atom2->nBonds--;
}

int destroyAtom(struct atom *atom) {
  // dust to dust, int to int
  // if the atom was malloced, for now you will have to free it manually after this. this will likely change when the program becomes more dynamic
  for (int i=0;i<atom->nBonds;i++) {
    unbond(atom, atom->bonds[i]);
  }
}

int printAtom(struct atom *atom) {
  printf("ID: %i\n", atom->id);
  printf("valence: %i\n", atom->valence);
  printf("row: %i\n", atom->row);
  printf("column: %i\n", atom->column);
  printf("atomic number: %i\n", atom->atomicNumber);
  printf("max bonds: %i\n", atom->maxBonds);
  printf("number of bonds: %i\n", atom->nBonds);
  printf("bonded with: \n");
  for (int i=0;i<atom->nBonds;i++) {
    printf("\t%i, \n", atom->bonds[i]->id);
  }
}

int main() {
  printf("hello\n");
  fflush(stdout);
  int id1 = 1010111;
  int id2 = 123456789;
  struct atom atom1 = createAtom(id1);
  printAtom(&atom1);
  struct atom atom2 = createAtom(id2);
  printAtom(&atom2);
  bond(&atom1, &atom2);
  printAtom(&atom1);
  printAtom(&atom2);
  unbond(&atom1, &atom2);
  printAtom(&atom1);
  printAtom(&atom2);
  bond(&atom1, &atom2);
  destroyAtom(&atom1);
  printAtom(&atom1); // atom1 is still here for now, it will be removed when we exit the function as normal, this is not the case for atoms made with malloc
  printAtom(&atom2);
  destroyAtom(&atom2);
  return 0;
}
