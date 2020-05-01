#this code does not run, 'atom' is not defined, but the objects.py file which is imported defines it

import objects

def pack_atom_to_numbers(atom) :
 return 10000000 + atom.atomic_number * 10000 + atom.column * 100 + atom.row * 10 + atom.valence


sulfur = objects.atom(16, 16, 3, 6)

print(pack_atom_to_numbers(sulfur))
