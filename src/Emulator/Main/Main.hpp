#pragma once

#include <cctype>
#include <charconv>
#include <cstdint>

#include <limits>
#include <string>
#include <expected>
#include <system_error>


namespace HyperCPU {
  enum Version : std::uint8_t {
    PreRelease = 0x01,
    Release1_0 = 0x02
  };

  enum IOSubsystem : std::uint8_t {
    NCurses = 0x01,
    Simple = 0x02
  };

  enum FileType : std::uint8_t {
    Object = 0x01,
    Binary = 0x02
  };
  
  using Magic = std::uint64_t;

  static inline constexpr Magic magic = 0xb7a6457636cf6c3a;
  static inline constexpr Version current_version = Version::PreRelease;

  struct GenericHeader {
    Magic magic;
    Version version;
    FileType type;
    std::uint32_t code_size;
  };

  enum class ParseError {
    Empty,
    Invalid
  };

  std::expected<std::uint64_t, ParseError> ParseMemoryString(const std::string& str);
}
