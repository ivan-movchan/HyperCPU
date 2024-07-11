#include <gtest/gtest.h>
#include <test/tests.hpp>
#include <opcodes.hpp>
#include <exitcodes.hpp>

TEST_F(CPU_TESTING, TEST_F_JG){
    cpu.memoryptr[0x0100] = JG;
    cpu.memoryptr[0x0101] = static_cast<uint8_t>(HyperCPU::IMM);
    *reinterpret_cast<uint32_t*>(&cpu.memoryptr[0x0102]) = 0x0110;
    cpu.memoryptr[0x0110] = HLT;
    cpu.cmpr = false;
    cpu.carry_flag = true;
    EXPECT_EQ(cpu.Execute(), EXIT_HALT);
    EXPECT_EQ(cpu.insp, 0x0111);
}