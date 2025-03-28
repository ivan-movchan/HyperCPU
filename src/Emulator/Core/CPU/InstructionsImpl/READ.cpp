#include <Core/CPU/Decoders/StdDecoder.hpp>
#include <Core/CPU/CPU.hpp>

#include <Misc/bit_cast.hpp>
#include <Misc/unreachable.hpp>
#include <utility>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

void HyperCPU::CPU::ExecREAD(const IInstruction& instr, void* op1, void* op2) {
  read_operation_handler* handler = nullptr;
  switch (instr.m_op_types) {
    case HyperCPU::IMM:
      handler = &read_io_handlers[HyperCPU::bit_cast<std::uint8_t>(op1)];
      break;
    case HyperCPU::R:
      handler = &read_io_handlers[HyperCPU::bit_cast_from<std::uint8_t>(op1)];
      break;
    default:
      HyperCPU::unreachable();
  }

  if (handler) {
    *xlll0 = (*handler)();
  }
}

#pragma GCC diagnostic pop
