#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include "emulator.h"

// ============= Breakpoint ==============

//  Not touching this much, pretty basic functions.

Breakpoint::Breakpoint() { }

Breakpoint::Breakpoint(addr_t address, const std::string name) {
  _address = address & ARCH_BITMASK;
  _name = name;
}

// Copy constructor
Breakpoint::Breakpoint(const Breakpoint& other) {
  _address = other._address;
  _name = other._name;
}

// Move constructor
Breakpoint::Breakpoint(Breakpoint&& other) noexcept {
  std::swap(_address, other._address);
  std::swap(_name, other._name);
}

// Copy assignment
Breakpoint& Breakpoint::operator=(const Breakpoint& other) {
  if (this == &other)
    return *this;
  _address = other._address;
  _name = other._name;
  return *this;
}

// Move assignment
Breakpoint& Breakpoint::operator=(Breakpoint&& other) noexcept {
  std::swap(_address, other._address);
  std::swap(_name, other._name);
  return *this;
}

addr_t Breakpoint::get_address() const {
  return _address;
}

const std::string Breakpoint::get_name() const {
  return _name;
}

int Breakpoint::has(addr_t address) const {
  return _address == (address & ARCH_BITMASK);
}

int Breakpoint::has(const std::string name) const {
  return (_name == name);
}

// ============= Emulator ==============

// ----------> Initialisation
Emulator::Emulator() {
  state = ProcessorState();

  // An array as big as the max number of instructions we could ever have
  // This is obviously an overkill. Initialising the array to be shorter
  // is okay, as long as you can handle the worst case of MAX_INSTRUCTIONS
  // breakpoints

  total_cycles = 0;
}

// Copy Constructor
Emulator::Emulator(const Emulator& other) {
  state = other.state;
  
  total_cycles = other.total_cycles;

  int i;

  for (i = 0 ; i < other.breakpoints_v.size(); i++ ) {

    breakpoints_v.push_back(other.breakpoints_v[i]);

  }

}

// Move Constructor
Emulator::Emulator(Emulator&& other) noexcept {
  std::swap(state, other.state);
  std::swap(breakpoints_v, other.breakpoints_v);
  std::swap(total_cycles, other.total_cycles);
}

// Copy Assignment Operator
Emulator& Emulator::operator=(const Emulator& other) {
  if (this == &other)
    return *this;

  state = other.state;
  total_cycles = other.total_cycles;

  int i;

  for (i = 0 ; i < other.breakpoints_v.size(); i++ ) {

    breakpoints_v.push_back(other.breakpoints_v[i]);

  }
  
  return *this;
}

// Move Assignment Operator
Emulator& Emulator::operator=(Emulator&& other) noexcept {
  std::swap(state, other.state);
  std::swap(breakpoints_v, other.breakpoints_v);
  std::swap(total_cycles, other.total_cycles);
  return *this;
}

// ----------> Main emulation loop

//  Not touching this, calls other files not part of coursework.

InstructionData Emulator::fetch() const {
  InstructionData data;
  data.opcode = state.memory[state.pc];
  data.address = state.memory[state.pc + 1];
  return data;
}

InstructionBase* Emulator::decode(InstructionData data) const {
  // decode here is just a thin wrapper around generateInstruction()
  // In a more complex emulator, more things would happen here
  return InstructionBase::generateInstruction(data);
}

int Emulator::execute(InstructionBase* instr) {
  // Again this is just a thin wrapper,
  // but this is a side-effect of having a simple emulator
  instr->execute(state);
  return 1;
}

int Emulator::run(int steps) {
  // No steps to execute
  if (steps == 0)
    return 1;

  // Repeat for the given number of steps
  // Break with return code 0, if we find an error
  // Break with return code 1, if we find a breakpoint
  // Keep track of the total number of cycles we've executed successfully
  for (; steps > 0; --steps) {
    // Instructions are supposed to be aligned on two-byte offsets:
    // PC should be even. Terminate if PC is odd.
    if ((state.pc % 2) == 1)
      return 0;

    // Fetch the next instruction from memory and transform it into an InstructionBase-derived object
    InstructionBase* instr = decode(fetch());
   
    if (instr == NULL)
      return 0;

    // What the function name says
    int success = execute(instr);

    // Terminate if we didn't execute the instruction successfully
    if (success == 0)
      return 0;

    ++total_cycles;
    
    if (is_breakpoint() == 1)
      return 1;
  }

  return 1;
}

// ----------> Breakpoint management

int Emulator::insert_breakpoint(addr_t address, const std::string name) {
  // breakpoints is full (should never happen though!)

  
  // Breakpoint already exists
  if (find_breakpoint(address) != NULL)
    return 0;

  // Breakpoint name already used
  if (find_breakpoint(name) != NULL)
    return 0;

  breakpoints_v.push_back(Breakpoint(address, name));

  return 1;
}


const Breakpoint* Emulator::find_breakpoint(addr_t address) const {
  // iterate over all breakpoints

  int i = 0;

  for (i = 0; i < breakpoints_v.size(); ++i) {

    if (breakpoints_v[i].has(address)) {

      // std::cout << i << "  via vectors  " <<  breakpoints_v[i].get_name() << "  " << breakpoints_v[i].get_address() << "  " << &breakpoints_v[i] << "\n";

      return &breakpoints_v[i];

    }

  }
  
  return NULL;
}

// Basically the same as above, but for the name

const Breakpoint* Emulator::find_breakpoint(const std::string name) const {

  int i = 0;

  for (i = 0; i < breakpoints_v.size(); ++i) {

    if (breakpoints_v[i].has(name)) {
      
      return &breakpoints_v[i];

    }

  }
  
  return NULL;
  
}

int Emulator::delete_breakpoint(addr_t address) {
  
  const Breakpoint* found = find_breakpoint(address);

  if (found == NULL)
    return 0;
  
  int i = 0;

  int target = -1;

  for ( Breakpoint b : breakpoints_v ) {

    if (b.get_address() == address) {

      target = i;

    }

    i++;

  }

  if (target == -1) {

    return 0;

  } else {

    breakpoints_v.erase(breakpoints_v.begin() + target);
    
  }

  return 1;
  
}

// Oh, look, this function is practically identical to the one above
int Emulator::delete_breakpoint(const std::string name) {
  
  const Breakpoint* found = find_breakpoint(name);

  if (found == NULL)
    return 0;
 
  return delete_breakpoint(found->get_address());  

}

int Emulator::num_breakpoints() const {
  
  return breakpoints_v.size();
  
}

// ----------> Manage state

int Emulator::cycles() const {
  return total_cycles;
}

data_t Emulator::read_acc() const {
  return state.acc;
}

addr_t Emulator::read_pc() const {
  return state.pc;
}

addr_t Emulator::read_mem(addr_t address) const {
  // limit address to the allowed range of values
  address &= ARCH_BITMASK;
  return state.memory[address];
}

// ----------> Utilities

int Emulator::is_zero() const {
  return state.acc == 0;
}

int Emulator::is_breakpoint() const {
  return find_breakpoint(state.pc) != NULL;
}

int Emulator::print_program() const {
  for (int offset = 0; offset < MEMORY_SIZE; offset += INSTRUCTION_SIZE) {
    InstructionData data;
    data.opcode = state.memory[offset];
    data.address = state.memory[offset + 1];
    InstructionBase* instr = decode(data);

    if ((instr == NULL) || (data.opcode == 0 && data.address == 0))
      printf("%d:\t%d\t%d\n", offset, data.opcode, data.address);
    else 
      printf("%d:\t%d\t%d\t:\t%s\n", offset, data.opcode, data.address, instr->to_string().c_str());
  }
  return 1;
}

int Emulator::load_state(const std::string filename) {

  //  This is a lengthy function that really needs breaking down into pieces.

  
  
  // Delete all breakpoints

  breakpoints_v.clear();


  


  // std::cout << filename << "\n";


  


  int read = 0;
  
  FILE *fp = fopen(filename.c_str(), "r");

  if (fp == NULL)
    return 0;

  ////    Make sure that each fscanf reads the right number of items
  
  read = fscanf(fp, "%d\n", &total_cycles);
  
  if ((read != 1) || (total_cycles < 0))
    return 0;

  read = fscanf(fp, "%d\n", &state.acc);
  if ((read != 1) || (state.acc > ARCH_MAXVAL) || (state.acc < 0))
    return 0;

  read = fscanf(fp, "%d\n", &state.pc);
  if ((read != 1) || (state.pc >= MEMORY_SIZE) || (state.pc < 0))
    return 0;


  std::ifstream file;

  std::string line;

  std::string word;

  std::vector<std::string> split_str;

  int num = 0;

  int offset = 0;


  ////    Load first 3 lines from file, heavy error checking.

  ////    Below works, tested.
  
  file.open(filename);

  std::getline(file, line);

  try { total_cycles = std::stoi(line); }

  catch (...) { return 0; }

  if (!file.good() || total_cycles < 0) { return 0; } 

  std::getline(file, line);
  
  try { state.acc = std::stoi(line); }

  catch (...) { return 0; }

  if (!file.good() || state.acc > ARCH_MAXVAL || state.acc < 0) { return 0; }

  std::getline(file, line);
  
  try { state.pc = std::stoi(line); }

  catch (...) { return 0; }

  if (!file.good() || state.pc >= MEMORY_SIZE || state.pc < 0) { return 0; }

  ////    Iterate over file based on offset size, parse numbers, load state to memory.

  ////    Below works, tested.

  for (offset ; offset < MEMORY_SIZE; offset++) {
    
    std::getline(file, line);

    if ( !line.empty() ) {
  
      try { num = std::stoi(line); }

      catch (...) { return 0; }

      if (!file.good() || (num > ARCH_MAXVAL) || (num < 0)) {

	return 0;

      }

      // std::cout << offset << "  " << num << "\n";
    
      state.memory[offset] = num;
      
    } else { return 0; }
   
  }


  ////    Iterate over file, load breakpoint numbers and names from file.

  ////    Below works, tested.

  // std::cout <<  "LOADING STATE\n";

  while (std::getline(file, line)) {
    
    std::stringstream ss(line);

    //  Split into vector of strings.

    while (ss >> word) { split_str.push_back(word); }

    //  Extract number.

    try { num = std::stoi(split_str[0]); }

    catch (...) { return 0; }

    //  Sanity test number.

    if ( num < 0 || num >= MEMORY_SIZE ) { return 0; }

    // std::cout << num << "  " << split_str[1] << "\n";

    if (!insert_breakpoint(num, split_str[1])) { return 0; }
    
    split_str.clear();
    
  }


  return 1;

  ////    Iterate over file, load state to memory.
  
  // num = 0;
  
  // for (offset = 0; offset < MEMORY_SIZE; ++offset) {
    
  //   // PP: Why not read a number directly into a state.memory location?
  //   // C++ by default assumes that your byte sized variable (e.g. state.memory[offset])
  //   // is supposed to hold a character, so it might assume that you are trying to read an
  //   // individual character from the file, not a number that fits in 8-bits.
  //   // E.g. if your next number is '0', it might load memory[offset] = '0' (48).
  //   // There are ways to force fscanf to read a number, but it will cause fewer
  //   // issues down the line, if you use integers as temporary storage, which forces C++
  //   // to read a number
    
  //   read = fscanf(fp, "%d\n", &num);
    
  //   if ((read != 1) || (num > ARCH_MAXVAL) || (num < 0))
  //     return 0;
    
  //   // std::cout << offset << "  " << num << "\n";
    
  //   state.memory[offset] = num;
    
  // }

  // while (1) {

  //   // Load line to number and string.
  
  //   char name[MAX_NAME];
  //   int read = fscanf(fp, "%d %s\n", &num, name);

  //   // If file ends, break.
  
  //   // End of the file
  //   if (read != 2)
  //     break;

  //   // If data invalid, return.

  //   // Wrong data (num is supposed to be an address)
  //   if ((num < 0) || (num >= MEMORY_SIZE))
  //     return 0;

  //   // Try to insert the breakpoint and return fail if unsuccessful
  //   std::cout << num << "  " << name << "\n";
    
  //   if (!insert_breakpoint(num, name))
  //     return 0;
  // }

  // Close file

  fclose(fp);
  return 1;
}

int Emulator::save_state(const std::string filename) const {
  FILE* fp = fopen(filename.c_str(), "w");

  if (fp == NULL)
    return 0;

  fprintf(fp, "%d\n", total_cycles);
  fprintf(fp, "%d\n", state.acc);
  fprintf(fp, "%d\n", state.pc);

  for (int offset = 0; offset < MEMORY_SIZE; ++offset) {
    // PP: Use temporary variables for the same reason as in load_state
    int num = state.memory[offset];
    fprintf(fp, "%d\n", num);
  }

  for (Breakpoint b : breakpoints_v) {
    
    fprintf(fp, "%d %s\n", b.get_address(), b.get_name());

  }


  fclose(fp);
  
  return 1;
}
