#include "emulator/core/cpu/instructions/flags.hpp"
#include <core/binary_transformer.hpp>
#include <core/compiler.hpp>

hypercpu::operand_types hcasm::binary_transformer::determine_op_types(operand& op1, operand& op2) {
  op1_t tp1;
  op2_t tp2;

  switch (op1.type) {
    case hcasm::operand_type::reg:
      tp1 = op1_t::R; break;
    case hcasm::operand_type::mem_reg_add_int:
    case hcasm::operand_type::memaddr_reg:
      tp1 = op1_t::RM; break;
    case hcasm::operand_type::sint:
    case hcasm::operand_type::uint:
      tp1 = op1_t::IMM; break;
    case hcasm::operand_type::memaddr_int:
      tp1 = op1_t::M; break;
    case hcasm::operand_type::none:
      tp1 = op1_t::NONE; break;
    default:
      __builtin_unreachable();
  }

  switch (op2.type) {
    case hcasm::operand_type::reg:
      tp2 = op2_t::R; break;
    case hcasm::operand_type::mem_reg_add_int:
    case hcasm::operand_type::memaddr_reg:
      tp2 = op2_t::RM; break;
    case hcasm::operand_type::sint:
    case hcasm::operand_type::uint:
      tp2 = op2_t::IMM; break;
    case hcasm::operand_type::memaddr_int:
      tp2 = op2_t::M; break;
    case hcasm::operand_type::none:
      tp2 = op2_t::NONE; break;
    default:
      __builtin_unreachable();
  }

  return quick_cast(quick_or(tp1, tp2));
}

void hcasm::binary_transformer::encode_instruction(hcasm::instruction& instr) {
  hypercpu::operand_types types = determine_op_types(instr.op1, instr.op2);

  res.push(static_cast<std::uint16_t>(instr.opcode));

  std::uint8_t encoded_operands = 0;
  if (types == hypercpu::operand_types::RM_IMM) {
    encoded_operands |= 0b10000000;
  }

  hcasm::mode md;
  switch (types) {
    case hypercpu::operand_types::RM_M:
      if (instr.op2.mode != hcasm::mode::none) {
        md = instr.op2.mode;
        break;
      }
    case hypercpu::operand_types::RM_IMM:
      if (instr.op1.mode == hcasm::mode::none) {
        logger.log(hypercpu::loglevel::ERROR, "Ambiguous operand size!");
        std::abort();
      }
    case hypercpu::operand_types::R_R:
    case hypercpu::operand_types::R_RM:
    case hypercpu::operand_types::R_M:
    case hypercpu::operand_types::R_IMM:
    case hypercpu::operand_types::R:
      md = instr.op1.mode;
      break;
    case hypercpu::operand_types::RM_R:
    case hypercpu::operand_types::M_R:
      md = instr.op2.mode;
      break;
    default:
      __builtin_unreachable();
  }
  encoded_operands |= (static_cast<std::uint8_t>(md) << 6);

  switch (types) {
    case hypercpu::operand_types::R_R:
    case hypercpu::operand_types::R_RM:
    case hypercpu::operand_types::RM_R:
      res.push(static_cast<std::uint8_t>(instr.op1.reg));
      res.push(static_cast<std::uint8_t>(instr.op2.reg));
      break;
    case hypercpu::operand_types::R_M:
      res.push(static_cast<std::uint8_t>(instr.op1.reg));
      res.push(instr.op2.uint1);
    case hypercpu::operand_types::R_IMM:
      res.push(static_cast<std::uint8_t>(instr.op1.reg));
      switch (md) {
        case hcasm::mode::b8:   res.push(static_cast<std::uint8_t>(instr.op2.uint1));  break;
        case hcasm::mode::b16:  res.push(static_cast<std::uint16_t>(instr.op2.uint1)); break;
        case hcasm::mode::b32:  res.push(static_cast<std::uint32_t>(instr.op2.uint1)); break;
        case hcasm::mode::b64:  res.push(static_cast<std::uint64_t>(instr.op2.uint1)); break;
        default:
          __builtin_unreachable();
      }
    case hypercpu::operand_types::R:
      res.push(static_cast<std::uint8_t>(instr.op1.reg));
      break;
    
    case hypercpu::operand_types::M_R:
      res.push(instr.op2.uint1);
      res.push(static_cast<std::uint8_t>(instr.op2.reg));
      break;
  }
}