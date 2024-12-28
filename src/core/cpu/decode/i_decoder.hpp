#pragma once

#include <core/memory_controller/i_memory_controller.hpp>
#include <core/cpu/instructions/opcodes.hpp>
#include <core/cpu/instructions/flags.hpp>


namespace hypercpu {
  struct i_instruction {
    opcode m_opcode;
    mode m_opcode_mode;
    operand_types m_op_types;
    std::size_t m_op1, m_op2;
  };

  class i_decoder {
  public:
    virtual i_instruction fetch_and_decode() = 0;
  };
}