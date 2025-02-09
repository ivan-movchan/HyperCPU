#pragma once

#include <cstddef>

#include <functional>
#include <memory>

#include <Core/MemoryController/IMemoryController.hpp>
#include <Core/CPU/Interrupts/ReservedInterrupts.hpp>
#include <Core/CPU/Instructions/Flags.hpp>
#include <Core/CPU/Decoders/StdDecoder.hpp>


#define DECLARE_INSTR(name) void Exec##name(const IInstruction& instr, void* op1, void* op2)

namespace HyperCPU {
  using opcode_handler = std::function<void(const IInstruction& instr, void* op1, void* op2)>;
  using read_operation_handler = std::function<std::uint8_t()>;
  using write_operation_handler = std::function<void(std::uint8_t)>;

  class MemoryControllerST;
  class MemoryControllerMT;

  class CPU {
  private:
    friend class Decoder;
    friend class MemoryControllerST;
    friend class MemoryControllerMT;
    // Components
    IMemoryController* mem_controller;
    std::unique_ptr<Decoder> m_decoder;

    // Data
    std::size_t core_count;
    std::size_t total_mem;
    bool halted;

    // General space for registers
    std::uint64_t data[13];

    // GP Registers
    std::uint64_t *x0, *x1, *x2, *x3, *x4, *x5, *x6, *x7;
    std::uint32_t *xh0, *xh1, *xh2, *xh3, *xh4, *xh5, *xh6, *xh7;
    std::uint32_t *xl0, *xl1,* xl2, *xl3, *xl4, *xl5, *xl6, *xl7;
    std::uint16_t *xll0, *xll1, *xll2, *xll3;
    std::uint8_t *xllh0, *xllh1, *xllh2, *xllh3;
    std::uint8_t *xlll0, *xlll1, *xlll2, *xlll3;

    // Specific registers
    std::uint64_t *xbp, *xsp, *xip, *xgdp, *xivt;

    // Flags
    bool crf, ovf, udf;

    std::array<opcode_handler, 128> opcode_handler_assoc;

    std::pair<void*, void*> GetOperands(OperandTypes op_types, Mode md, std::size_t& op1, std::size_t& op2);
    void* GetRegister(std::size_t& op1);

    // Stack
    void StackPush8(std::uint8_t) noexcept;
    void StackPush16(std::uint16_t) noexcept;
    void StackPush32(std::uint32_t) noexcept;
    void StackPush64(std::uint64_t) noexcept;

    std::uint8_t StackPop8() noexcept;
    std::uint16_t StackPop16() noexcept;
    std::uint32_t StackPop32() noexcept;
    std::uint64_t StackPop64() noexcept;

    // Interrupts
    void TriggerInterrupt(HyperCPU::cpu_exceptions exception);
    void RunInterruptSubroutine();
    
    // All instructions
    DECLARE_INSTR(ADD);
    DECLARE_INSTR(ADC);
    DECLARE_INSTR(AND);
    DECLARE_INSTR(ANDN);
    DECLARE_INSTR(BSWAP);
    DECLARE_INSTR(CALL);
    DECLARE_INSTR(CCRF);
    DECLARE_INSTR(COVF);
    DECLARE_INSTR(CUDF);
    DECLARE_INSTR(INC);
    DECLARE_INSTR(DEC);
    DECLARE_INSTR(HID);
    DECLARE_INSTR(MUL);
    DECLARE_INSTR(OR);
    DECLARE_INSTR(SUB);
    DECLARE_INSTR(SHFL);
    DECLARE_INSTR(SHFR);
    DECLARE_INSTR(DIV);
    DECLARE_INSTR(HALT);
    DECLARE_INSTR(MOV);
    DECLARE_INSTR(LOIVT);
    DECLARE_INSTR(INTR);
    DECLARE_INSTR(READ);
    DECLARE_INSTR(WRITE);

    // I/O
    std::array<read_operation_handler, 16> read_io_handlers;
    std::array<write_operation_handler, 16> write_io_handlers;
    std::uint8_t read_console();
    void write_console(std::uint8_t);
    
  public:
    explicit CPU(std::size_t core_count, std::size_t mem_size, char* binary = nullptr, std::uint64_t binary_size = 0);

    void Run();
    
    ~CPU();
  };
}
