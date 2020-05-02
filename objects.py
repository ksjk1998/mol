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
 series = "type of atom defined by the row number"
 melting_point = 0.0 # K
 boiling_point = 0.0 # K
 electronegativity = 0
 electron_affinity = 0.0 # kJ/mol
 valence = 1
 ionization = 0.0 # kJ/mol

 def __init__(self, atomic_number, symbol, name, atomic_weight, column, row, radius, hardness, modulus, density, conductivity, heat, abundance, discovered, series, melting_point, boiling_point, electronegativity, electron_affinity, valence, ionization) :
  self.atomic_number = atomic_number
  self.symbol = symbol
  self.name = name
  self.atomic_weight = atomic_weight
  self.column = column
  self.row = row
  self.radius = radius
  self.hardness = hardness
  self.modulus = modulus
  self.density = density
  self.conductivity = conductivity
  self.heat = heat
  self.abundance = abundance
  self.series = series
  self.melting_point = melting_point
  self.boiling_point = boiling_point
  self.electronegativity = electronegativity
  self.electron_affinity = electron_affinity
  self.valence = valence
  self.ionization = ionization

 def get_atomic_number() :
  return self.atomic_number

 def get_symbol() :
  return self.symbol

 def get_name() :
  return self.name

 def get_atomic_weight() :
  return self.atomic_weight

 def get_column() :
  return self.column

 def get_row() :
  return self.row

 def get_radius() :
  return self.radius

 def get_hardness() :
  return self.hardness

 def get_modulus() :
  return self.modulus

 def get_density() :
  return self.density

 def get_conductivity() :
  return self.conductivity

 def get_heat() :
  return self.heat

 def get_abundance() :
  return self.abundance

 def get_series() :
  return self.series

 def get_melting_point() :
  return self.melting_point

 def get_boiling_point() :
  return self.boiling_point

 def get_electronegativity() :
  return self.electronegativity

 def get_electron_affinity() :
  return self.electron_affinity

 def get_valence() :
  return self.valence

 def get_ionization() :
  return self.ionization

 def set_atomic_number(atomic_number) :
  return self.atomic_number = atomic_number

 def set_symbol(symbol) :
  return self.symbol = symbol

 def set_name(name) :
  return self.name = name

 def set_atomic_weight(atomic_weight) :
  return self.atomic_weight = atomic_weight

 def set_column(column) :
  return self.column = column

 def set_row(row) :
  return self.row = row

 def set_radius(radius) :
  return self.radius = radius

 def set_hardness(hardness) :
  return self.hardness = hardness

 def set_modulus(modulus) :
  return self.modulus = modulus

 def set_density(density) :
  return self.density = density

 def set_conductivity(conductivity) :
  return self.conductivity = conductivity

 def set_heat(heat) :
  return self.heat = heat

 def set_abundance(abundance) :
  return self.abundance = abundance

 def set_series(series) :
  return self.series = series

 def set_melting_point(melting_point) :
  return self.melting_point = melting_point

 def set_boiling_point(boiling_point) :
  return self.boiling_point = boiling_point

 def set_electronegativity(electronegativity) :
  return self.electronegativity = electronegativity

 def set_electron_affinity(electron_affinity) :
  return self.electron_affinity = electron_affinity

 def set_valence(valence) :
  return self.valence = valence

 def set_ionization(ionization) :
  return self.ionization = ionization


class bond :

 bond_type = "ionic, covalent, polar, hydrogen, etc."
 energy = 0.0

 def __init__(self) :
  return "Nil"


class molecule :

 atoms = []
 bonds = []
 atomic_mass = 0.0

 def __init__(self) :
  return "Nil"
