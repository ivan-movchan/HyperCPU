#pragma once

#include <type_traits>
#include <utility>
#include <string>
#include <vector>

#include <Emulator/Core/CPU/Instructions/Registers.hpp>
#include <Emulator/Core/CPU/Instructions/Flags.hpp>
#include <Emulator/Core/CPU/Instructions/Opcodes.hpp>
#include <Logger/Logger.hpp>

#include <pog/parser.h>


namespace HCAsm {
  enum class ValueType {
    operand,
    string,
    sint,
    uint
  };

  enum class OperandType {
    reg,
    mem_reg_add_int,
    sint,
    uint,
    memaddr_reg,
    memaddr_int,
    none
  };

  enum class Mode : std::uint8_t {
    b8  = 0b00,
    b16 = 0b01,
    b32 = 0b10,
    b64 = 0b11,
    none
  };

  struct Operand {
    OperandType type;
    HyperCPU::Registers reg;
    enum Mode mode;
    union {
      std::uint64_t uint1;
      std::int64_t sint2;
    };
  };

  struct Instruction {
    HyperCPU::Opcode opcode;
    Operand op1, op2;
  };

  struct Label {
    std::string name;
    std::uint64_t index;
  };

  struct Value {
    std::variant<std::int64_t, std::uint64_t, std::string, Operand, Instruction> val;
  };

  struct BinaryResult {
    unsigned char* binary;
    std::uint64_t ptr;

    template<typename T, std::enable_if_t<
      std::is_integral_v<T> && 
      std::is_unsigned_v<T>, bool> = true>
    constexpr inline void push(T data) {
      std::memcpy(binary + ptr, &data, sizeof(data));
      ptr += sizeof(data);
    }

    ~BinaryResult() {
      delete[] binary;
    }
  };

  struct LineCounter {
    int a;
  };

  struct CompilerState {
    CompilerState() : code_size(0) { }

    std::vector<std::variant<Instruction, Label>> ir;
    std::unordered_map<std::string, std::uint64_t> labels;
    std::uint64_t code_size;
  };

  constexpr inline Mode ModeFromRegister(HyperCPU::Registers reg) {
    using namespace HyperCPU;
    switch (reg) {
      case Registers::X0:
      case Registers::X1:
      case Registers::X2:
      case Registers::X3:
      case Registers::X4:
      case Registers::X5:
      case Registers::X6:
      case Registers::X7:
        return Mode::b64;
      case Registers::XH0:
      case Registers::XH1:
      case Registers::XH2:
      case Registers::XH3:
      case Registers::XH4:
      case Registers::XH5:
      case Registers::XH6:
      case Registers::XH7:
      case Registers::XL0:
      case Registers::XL1:
      case Registers::XL2:
      case Registers::XL3:
      case Registers::XL4:
      case Registers::XL5:
      case Registers::XL6:
      case Registers::XL7:
        return Mode::b32;
      case Registers::XLL0:
      case Registers::XLL1:
      case Registers::XLL2:
      case Registers::XLL3:
        return Mode::b16;
      case Registers::XLLH0:
      case Registers::XLLH1:
      case Registers::XLLH2:
      case Registers::XLLH3:
      case Registers::XLLL0:
      case Registers::XLLL1:
      case Registers::XLLL2:
      case Registers::XLLL3:
        return Mode::b8;
      default:
        std::unreachable();
    }
  }

  Value TokenizeSignedInt(std::string_view str);
  Value TokenizeUnsignedInt(std::string_view str);
  Value TokenizeString(std::string_view str);
  Value TokenizeHexadecimal(std::string_view str);
  Value TokenizeIdentifier(std::string_view str);
  Value TokenizeBinary(std::string_view str);

  Value ParseOperand1(std::vector<Value>&& args);
  Value ParseOperand2(std::vector<Value>&& args);
  Value ParseOperand3(std::vector<Value>&& args);
  Value ParseOperand4(std::vector<Value>&& args);
  Value ParseOperand5(std::vector<Value>&& args);
  Value ParseOperand6(std::vector<Value>&& args);
  Value ParseOperand7(std::vector<Value>&& args);
  Value ParseOperand8(std::vector<Value>&& args);
  Value ParseOperand9(std::vector<Value>&& args);
  Value parse_operand10(std::vector<Value>&& args);
  Value parse_operand11(std::vector<Value>&& args);

  Value CompileStatement1(std::vector<Value>&& args);
  Value CompileStatement2(std::vector<Value>&& args);
  Value CompileStatement3(std::vector<Value>&& args);
  Value CompileLabel(std::vector<Value>&& args);

  extern HyperCPU::Logger logger;
  extern CompilerState* current_state;
  extern std::uint64_t current_index;

  class HCAsmCompiler {
  public:
    HCAsmCompiler(HyperCPU::LogLevel lvl = HyperCPU::LogLevel::WARNING);

    void Compile(std::string& source, std::string& destination);
    CompilerState TransformToIR(std::string& src);
    BinaryResult TransformToBinary(CompilerState& ir);

  private:
    pog::Parser<Value> parser;
    CompilerState* state;

    constexpr inline std::uint8_t OperandSize(Operand op);
    std::uint8_t InstructionSize(Instruction& instr);
  };
  
}