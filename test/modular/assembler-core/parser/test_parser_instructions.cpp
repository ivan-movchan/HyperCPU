#include <fixtures.hpp>

#include <core/compiler.hpp>

TEST_F(asm_parser_stmt_test, STMT1) {
    std::string data = "adc x0, x1;";
    hcasm::compiler_state state;

    state = compiler.transform_to_IR(data);

    EXPECT_EQ(state.ir.size(), 1);
    EXPECT_EQ(state.labels.size(), 0);

    auto& instr = std::get<hcasm::instruction>(state.ir[0]);
    EXPECT_EQ(instr.opcode, hypercpu::opcode::ADC);
    
    EXPECT_EQ(instr.op1.type, hcasm::operand_type::reg);
    EXPECT_EQ(instr.op1.reg, hypercpu::registers::X0);

    EXPECT_EQ(instr.op2.type, hcasm::operand_type::reg);
    EXPECT_EQ(instr.op2.reg, hypercpu::registers::X1);
}

TEST_F(asm_parser_stmt_test, STMT2) {
    std::string data = "adc x0;";
    hcasm::compiler_state state;

    state = compiler.transform_to_IR(data);

    EXPECT_EQ(state.ir.size(), 1);
    EXPECT_EQ(state.labels.size(), 0);

    auto& instr = std::get<hcasm::instruction>(state.ir[0]);
    EXPECT_EQ(instr.opcode, hypercpu::opcode::ADC);
    
    EXPECT_EQ(instr.op1.type, hcasm::operand_type::reg);
    EXPECT_EQ(instr.op1.reg, hypercpu::registers::X0);

    EXPECT_EQ(instr.op2.type, hcasm::operand_type::none);
}

TEST_F(asm_parser_stmt_test, STMT3) {
    std::string data = "adc;";
    hcasm::compiler_state state;

    state = compiler.transform_to_IR(data);

    EXPECT_EQ(state.ir.size(), 1);
    EXPECT_EQ(state.labels.size(), 0);

    auto& instr = std::get<hcasm::instruction>(state.ir[0]);
    EXPECT_EQ(instr.opcode, hypercpu::opcode::ADC);
    
    EXPECT_EQ(instr.op1.type, hcasm::operand_type::none);

    EXPECT_EQ(instr.op2.type, hcasm::operand_type::none);
}

TEST_F(asm_parser_stmt_test, LABEL) {
    std::string data = "test:";
    hcasm::compiler_state state;

    state = compiler.transform_to_IR(data);

    EXPECT_EQ(state.ir.size(), 0);
    EXPECT_EQ(state.labels.size(), 1);

    EXPECT_EQ(std::get<hcasm::label>(state.ir[0]).index, 0);
}