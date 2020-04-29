class atom :

 atomic_number = 0
 symbol = "symbols start with a capitol letter and any extra letter is lowercase"
 name = "not listed in the peroidic table"
 atomic_weight = 0.00
 column = 0
 row = 0
 radius = 0 # pm
 hardness = 0 # MPa
 modulus = 0 # GPa
 density = 0.00 # kg/m³
 conductivity = 0.00 # W/mK
 heat = 0 # J/kgK
 abundance = 0.00 # percentage point represented in decimal
 discovered = 0
 series = "type of atom defined by the row number"
 state_at_0_K = "solid, liquid, gas or unknown"
 melting_point = 0.0 # K
 boiling_point = 0.0 # K
 electronegativity = 0
 electron_affinity = 0.0 # kJ/mol
 valence = 1
 ionization = 0.0 # kJ/mol

 def __init__(self) :

class bond :

 bond_type = "ionic, covalent, polar, hydrogen, etc."

 def __init__(self) :

class molecule :

 atoms = []
 bonds = []
 atomic_mass = 0.0

 def __init__(self) :
  
