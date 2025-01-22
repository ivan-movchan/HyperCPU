#pragma once

#include <Core/MemoryController/IMemoryController.hpp>
#include <Core/CPU/Instructions/Opcodes.hpp>
#include <Core/CPU/Instructions/Flags.hpp>
#include <Core/CPU/Decoders/IDecoder.hpp>


namespace HyperCPU {
  struct Instruction {
    Opcode op;
    Mode op_mode;
  };

  class CPU;

  class Decoder final : public IDecoder {
  private:
    IMemoryController* mem_controller;
    std::uint64_t* rip;
    class CPU* cpu;
    bool decoder_halted;

    bool CheckSupportedOperandSize(std::uint8_t byte, std::uint8_t mask) const noexcept;
    void RaiseException(bool expr) noexcept;

  public:
    explicit Decoder() = default; // For testing purposes - causes UB if used incorrectly
    explicit Decoder(IMemoryController* mc, std::uint64_t* counter, class CPU* cpu) 
      : mem_controller(mc)
      , rip(counter)
      , cpu(cpu)
      , decoder_halted(false) {}

    IInstruction FetchAndDecode() override;
    bool IsHalted() const noexcept override;

    ~Decoder() = default;
  };
}