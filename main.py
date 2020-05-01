#this code does not run, 'atom' is not defined, but the objects.py file which is imported defines it

import objects

def pack_atom_to_numbers(atom) :
 return 10000000 + atom.atomic_number * 100000 + atom.column * 1000 + column * 100 + atom.valence


sulfur = atom(16, 16, 3, 6)
