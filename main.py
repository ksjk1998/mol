import objects

'''
!!!!! VERY IMPORTANT !!!!!!!!!
"none" in python does not mean that there is 
no weight, etc. it means that there is no value
to put there. Likley that it is unknown
"none" means "unknown"
'''

def pack_atom_to_numbers(atom) :
 return 10000000 + atom.atomic_number * 10000 + atom.column * 100 + atom.row * 10 + atom.valence


sulfur = objects.atom(16, 16, 3, 6)

print(pack_atom_to_numbers(sulfur))
