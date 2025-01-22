#include <climits>
#include <gtest/gtest.h>

#include <fixtures.hpp>

#define private public
#include <Core/MemoryController/MemoryControllerMT.hpp>


static constexpr std::uint8_t BYTE = 0x55;
static constexpr std::uint16_t WORD = 0x5555;
static constexpr std::uint32_t DWORD = 0x55555555;
static constexpr std::uint64_t QWORD = 0x5555555555555555;

TEST_F(MC_MT_TEST, LOAD8) {
  for (std::size_t i = 0; i < MEM_FIXTURE_MEM_SIZE; i++, counter++)
    mcmt.Load8(counter, BYTE);
    
  ASSERT_TRUE(std::memcmp(mcmt.memory,&tmp_buffer, MEM_FIXTURE_MEM_SIZE) == 0);
}

TEST_F(MC_MT_TEST, LOAD16) {
  for (std::size_t i = 0; i < MEM_FIXTURE_MEM_SIZE / 2; ++i, counter += 2)
    mcmt.Load16(counter, WORD);

  ASSERT_TRUE(std::memcmp(mcmt.memory, tmp_buffer, MEM_FIXTURE_MEM_SIZE) == 0);
}

TEST_F(MC_MT_TEST, LOAD32) {
  for (std::size_t i = 0; i < MEM_FIXTURE_MEM_SIZE / 4; ++i, counter += 4)
    mcmt.Load32(counter, DWORD);

  ASSERT_TRUE(std::memcmp(mcmt.memory, tmp_buffer, MEM_FIXTURE_MEM_SIZE) == 0);
}

TEST_F(MC_MT_TEST, LOAD64) {
  for (std::size_t i = 0; i < MEM_FIXTURE_MEM_SIZE / 8; ++i, counter += 8)
    mcmt.Load64(counter, QWORD);

  ASSERT_TRUE(std::memcmp(mcmt.memory, tmp_buffer, MEM_FIXTURE_MEM_SIZE) == 0);
}

TEST_F(MC_MT_TEST, FETCH8) {
  mcmt.Load64(counter, QWORD);

  for (std::size_t i = 0; i < 8; ++i)
    ASSERT_EQ(mcmt.Fetch8(counter), BYTE);
}

TEST_F(MC_MT_TEST, FETCH16) {
  mcmt.Load64(counter, QWORD);

  for (std::size_t i = 0; i < 4; ++i)
    ASSERT_EQ(mcmt.Fetch16(counter), WORD);
}

TEST_F(MC_MT_TEST, FETCH32) {
  mcmt.Load64(counter, QWORD);

  for (std::size_t i = 0; i < 2; ++i)
    ASSERT_EQ(mcmt.Fetch32(counter), DWORD);
}

TEST_F(MC_MT_TEST, FETCH64) {
  mcmt.Load64(counter, QWORD);

  ASSERT_EQ(mcmt.Fetch64(counter), QWORD);
}

TEST_F(MC_MT_TEST, READ8) {
  mcmt.Load64(counter, QWORD);

  for (std::size_t i = 0; i < 8; ++i, ++counter)
    ASSERT_EQ(mcmt.Read8(counter), BYTE);
}

TEST_F(MC_MT_TEST, READ16) {
  mcmt.Load64(counter, QWORD);

  for (std::size_t i = 0; i < 4; ++i, counter += 2)
    ASSERT_EQ(mcmt.Read16(counter), WORD);
}

TEST_F(MC_MT_TEST, READ32) {
  mcmt.Load64(counter, QWORD);

  for (std::size_t i = 0; i < 2; ++i, counter += 4)
    ASSERT_EQ(mcmt.Read32(counter), DWORD);
}

TEST_F(MC_MT_TEST, READ64) {
  mcmt.Load64(counter, QWORD);

  ASSERT_EQ(mcmt.Read64(counter), QWORD);
}

TEST_F(MC_MT_FAILTEST, LOAD8) {
  ASSERT_EXIT(mcmt.Load8(counter, BYTE), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, LOAD16) {
  ASSERT_EXIT(mcmt.Load16(counter, WORD), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, LOAD32) {
  ASSERT_EXIT(mcmt.Load32(counter, DWORD), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, LOAD64) {
  ASSERT_EXIT(mcmt.Load64(counter, QWORD), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, FETCH8) {
  ASSERT_EXIT(mcmt.Fetch8(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, FETCH16) {
  ASSERT_EXIT(mcmt.Fetch16(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, FETCH32) {
  ASSERT_EXIT(mcmt.Fetch32(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, FETCH64) {
  ASSERT_EXIT(mcmt.Fetch64(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, READ8) {
  ASSERT_EXIT(mcmt.Read8(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, READ16) {
  ASSERT_EXIT(mcmt.Read16(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, READ32) {
  ASSERT_EXIT(mcmt.Read32(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_FAILTEST, READ64) {
  ASSERT_EXIT(mcmt.Read64(counter), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, LOAD8) {
  counter = 1023;
  ASSERT_EXIT({mcmt.Load8(counter, BYTE); exit(0); }, ::testing::ExitedWithCode(0), "");
  ++counter;
  ASSERT_EXIT({mcmt.Load8(counter, BYTE); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, LOAD16) {
  counter = 1022;
  ASSERT_EXIT({mcmt.Load16(counter, WORD); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1023;
  ASSERT_EXIT({mcmt.Load16(counter, WORD); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, LOAD32) {
  counter = 1020;
  ASSERT_EXIT({mcmt.Load32(counter, DWORD); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1021;
  ASSERT_EXIT({mcmt.Load32(counter, DWORD); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, LOAD64) {
  counter = 1016;
  ASSERT_EXIT({mcmt.Load64(counter, QWORD); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1017;
  ASSERT_EXIT({mcmt.Load64(counter, QWORD); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, FETCH8) {
  counter = 1023;
  ASSERT_EXIT({mcmt.Fetch8(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1024;
  ASSERT_EXIT({mcmt.Fetch8(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, FETCH16) {
  counter = 1022;
  ASSERT_EXIT({mcmt.Fetch16(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1023;
  ASSERT_EXIT({mcmt.Fetch16(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, FETCH32) {
  counter = 1020;
  ASSERT_EXIT({mcmt.Fetch32(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1021;
  ASSERT_EXIT({mcmt.Fetch32(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, FETCH64) {
  counter = 1016;
  ASSERT_EXIT({mcmt.Fetch64(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1017;
  ASSERT_EXIT({mcmt.Fetch64(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, READ8) {
  counter = 1023;
  ASSERT_EXIT({mcmt.Read8(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1024;
  ASSERT_EXIT({mcmt.Read8(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, READ16) {
  counter = 1022;
  ASSERT_EXIT({mcmt.Read16(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1023;
  ASSERT_EXIT({mcmt.Read16(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, READ32) {
  counter = 1020;
  ASSERT_EXIT({mcmt.Read32(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1021;
  ASSERT_EXIT({mcmt.Read32(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(MC_MT_NEARFAILTEST, READ64) {
  counter = 1016;
  ASSERT_EXIT({mcmt.Read64(counter); exit(0); }, ::testing::ExitedWithCode(0), "");
  counter = 1017;
  ASSERT_EXIT({mcmt.Read64(counter); exit(0); }, ::testing::KilledBySignal(SIGABRT), "");
}