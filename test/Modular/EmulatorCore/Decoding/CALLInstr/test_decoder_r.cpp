#include <gtest/gtest.h>

#include <cstring>

#include <fixtures.hpp>

TEST_F(DECODER_TEST, CALL_INSTR_R) {
  decoder.mem_controller->Load16(counter, HyperCPU::Opcode::CALL);
  counter += 2;
  decoder.mem_controller->Load8(counter, (HyperCPU::Mode::b64 << 6) | HyperCPU::OperandTypes::R);
  ++counter;
  decoder.mem_controller->Load8(counter, HyperCPU::Registers::X3);
  ++counter;
  decoder.mem_controller->Load8(counter, HyperCPU::Registers::X7);
  counter = 0;
  
  HyperCPU::IInstruction instr = decoder.FetchAndDecode();

  ASSERT_EQ(instr.m_opcode, HyperCPU::Opcode::CALL);
  ASSERT_EQ(instr.m_opcode_mode, HyperCPU::Mode::b64);
  ASSERT_EQ(instr.m_op_types, HyperCPU::OperandTypes::R);
}