#include <cpu.hpp>
#include <bit>
#include <cstdio>

#define RM_T(ptr, type) *reinterpret_cast<type*>(_memory + *reinterpret_cast<uint32_t*>(ptr))
#define R_T(ptr, type) *reinterpret_cast<type*>(ptr)
#define M_T(ptr, type) *reinterpret_cast<type*>(ptr)
#define IMM_T(ptr, type) *reinterpret_cast<type*>(ptr)
#define CARRY_T() static_cast<int>(_carry)

int HyperCPU::CPU::_ins_adc_exec(HyperCPU::_instruction_t &instr, void* ptr1, void* ptr2) {
    switch (instr.args){
        case RM_R:
            if (instr.size == b8)
                RM_T(ptr1, uint8_t) += R_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                RM_T(ptr1, uint16_t) += R_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                RM_T(ptr1, uint32_t) += R_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        case R_RM:
            if (instr.size == b8)
                R_T(ptr1, uint8_t) += RM_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                R_T(ptr1, uint16_t) += RM_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                R_T(ptr1, uint32_t) += RM_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        case RM_IMM:
            if (instr.size == b8)
                RM_T(ptr1, uint8_t) += IMM_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                RM_T(ptr1, uint16_t) += IMM_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                RM_T(ptr1, uint32_t) += IMM_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        case R_IMM:
            if (instr.size == b8)
                R_T(ptr1, uint8_t) += IMM_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                R_T(ptr1, uint16_t) += IMM_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                R_T(ptr1, uint32_t) += IMM_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        case RM_M:
            if (instr.size == b8)
                RM_T(ptr1, uint8_t) += M_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                RM_T(ptr1, uint16_t) += M_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                RM_T(ptr1, uint32_t) += M_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        case R_M:
            if (instr.size == b8)
                R_T(ptr1, uint8_t) += M_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                R_T(ptr1, uint16_t) += M_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                R_T(ptr1, uint32_t) += M_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        case M_R:
            if (instr.size == b8)
                M_T(ptr1, uint8_t) += R_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                M_T(ptr1, uint16_t) += R_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                M_T(ptr1, uint32_t) += R_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        case M_RM:
            if (instr.size == b8)
                M_T(ptr1, uint8_t) += RM_T(ptr2, uint8_t) + CARRY_T();
            else if (instr.size == b16)
                M_T(ptr1, uint16_t) += RM_T(ptr2, uint16_t) + CARRY_T();
            else if (instr.size == b32)
                M_T(ptr1, uint32_t) += RM_T(ptr2, uint32_t) + CARRY_T();
            else return 1;
            break;
        default: return 1;
    }
    return 0;
}