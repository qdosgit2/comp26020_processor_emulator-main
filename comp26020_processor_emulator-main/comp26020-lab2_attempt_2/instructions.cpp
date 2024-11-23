#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "instructions.h"

// ========== InstructionBase ==========
void InstructionBase::execute(ProcessorState& state) const {
  // virtual call that implements the actual functionality of the instruction
  _execute(state);

  // move the pc forward
  state.pc += INSTRUCTION_SIZE;

  // trim the accumulator and the PC to fit in number of bits of the architecture
  state.acc &= ARCH_BITMASK;
  state.pc &= ARCH_BITMASK;
}

addr_t InstructionBase::get_address() const {
  return _address;
}

void InstructionBase::_set_address(addr_t address) {
  _address = address & ARCH_BITMASK;
}

std::string InstructionBase::to_string() const {

  std::string buffer;

  //  Figure out what the instruction actually is based on the return value of name()
  //  and then generate an appropriate instruction-specific string
  
  if (name() == "ADD")
    buffer = name() + ": ACC <- ACC + [" + std::to_string(get_address()) + "]";

  else if (name() == "AND")
    buffer = name() + ": ACC <- ACC & [" + std::to_string(get_address()) + "]";

  else if (name() == "ORR")
    buffer = name() + ": ACC <- ACC | [" + std::to_string(get_address()) + "]";

  else if (name() == "XOR")
    buffer = name() + ": ACC <- ACC ^ [" + std::to_string(get_address()) + "]";

  else if (name() == "LDR")
    buffer = name() + ": ACC <- [" + std::to_string(get_address()) + "]";

  else if (name() == "STR")
    buffer = name() + ": ACC -> [" + std::to_string(get_address()) + "]";

  else if (name() == "JMP")
    buffer = name() + ": PC  <- " + std::to_string(get_address());

  else if (name() == "JNE")
    buffer = name() + ": PC  <- " + std::to_string(get_address()) + " if ACC != 0";
  
  //  This should never happen unless we have an error in name() or one of the strncmp's above
  //  i.e. the tests will never try to trigger this code
  else
    assert(0);
  
  return buffer;
  
}

InstructionBase* InstructionBase::generateInstruction(InstructionData data) {
  // This could be a switch-case, but it's not important
  if (data.opcode == ADD)
    return new Iadd(data.address);
  if (data.opcode == AND)
    return new Iand(data.address);
  if (data.opcode == ORR)
    return new Iorr(data.address);
  if (data.opcode == XOR)
    return new Ixor(data.address);
  if (data.opcode == LDR)
    return new Ildr(data.address);
  if (data.opcode == STR)
    return new Istr(data.address);
  if (data.opcode == JMP)
    return new Ijmp(data.address);
  if (data.opcode == JNE)
    return new Ijne(data.address);

  return NULL;
}

// ========== ADD Instruction ==========
Iadd::Iadd(addr_t address) {
  _set_address(address);
}

void Iadd::_execute(ProcessorState& state) const {
  state.acc += state.memory[get_address()];
}

const std::string Iadd::name() const {
  return "ADD";
}

// ========== AND Instruction ==========
Iand::Iand(addr_t address) {
  _set_address(address);
}

void Iand::_execute(ProcessorState& state) const {
  state.acc &= state.memory[get_address()];
}

const std::string Iand::name() const {
  return "AND";
}

// ========== ORR Instruction ==========
Iorr::Iorr(addr_t address) {
  _set_address(address);
}

void Iorr::_execute(ProcessorState& state) const {
  state.acc |= state.memory[get_address()];
}

const std::string Iorr::name() const {
  return "ORR";
}

// ========== XOR Instruction ==========
Ixor::Ixor(addr_t address) {
  _set_address(address);
}


void Ixor::_execute(ProcessorState& state) const {
  state.acc ^= state.memory[get_address()];
}

const std::string Ixor::name() const {
  return "XOR";
}

// ========== LDR Instruction ==========
Ildr::Ildr(addr_t address) {
  _set_address(address);
}

void Ildr::_execute(ProcessorState& state) const {
  state.acc = state.memory[get_address()];
}

const std::string Ildr::name() const {
  return "LDR";
}

// ========== STR Instruction ==========
Istr::Istr(addr_t address) {
  _set_address(address);
}

void Istr::_execute(ProcessorState& state) const {
  state.memory[get_address()] = state.acc;
}

const std::string Istr::name() const {
  return "STR";
}

// ========== JMP Instruction ==========
Ijmp::Ijmp(addr_t address) {
  _set_address(address);
}

void Ijmp::_execute(ProcessorState& state) const {
  // Why minus two? Because execute() will increment PC by two,
  // so to make the PC take (eventually) the value `address`
  // I need to subtract two here. Same applies for JNE below
  // This kind of unintuitive behaviour is a clear sign of bad
  // class hierarchy design 
  state.pc = get_address() - 2;
}

const std::string Ijmp::name() const {
  return "JMP";
}

// ========== JNE Instruction ==========
Ijne::Ijne(addr_t address) {
  _set_address(address);
}

void Ijne::_execute(ProcessorState& state) const {
  // Same hack as above
  if (state.acc != 0)
    state.pc = get_address() - 2;
}

const std::string Ijne::name() const {
  return "JNE";
}

