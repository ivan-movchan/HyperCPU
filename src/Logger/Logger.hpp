#pragma once

#include <cstdint>

#include <string>
#include <format>
#include <utility>

#include <Logger/Colors.hpp>
#include <Emulator/Misc/print.hpp>
#include <Emulator/Misc/unreachable.hpp>


namespace HyperCPU {
  enum class LogLevel : std::uint_fast8_t {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
  };

  class Logger {
  private:
    LogLevel _loglevel;

    constexpr char DefineMsgChar(HyperCPU::LogLevel lvl) const noexcept {
      switch (lvl) {
        case HyperCPU::LogLevel::DEBUG:   return '-';
        case HyperCPU::LogLevel::INFO:    return '*';
        case HyperCPU::LogLevel::WARNING: return '=';
        case HyperCPU::LogLevel::ERROR:   return '!';
        default:
          HyperCPU::unreachable();
      }
    }

    constexpr const char* DefineBoldColor(HyperCPU::LogLevel lvl) const noexcept {
      switch (lvl) {
        case HyperCPU::LogLevel::DEBUG:
        case HyperCPU::LogLevel::INFO:    return RESET;
        case HyperCPU::LogLevel::WARNING: return B_YELLOW;
        case HyperCPU::LogLevel::ERROR:   return B_RED;
        default:
          HyperCPU::unreachable();
      }
    }

    constexpr const char* DefineColor(HyperCPU::LogLevel lvl) const noexcept {
      switch (lvl) {
        case HyperCPU::LogLevel::DEBUG:
        case HyperCPU::LogLevel::INFO:    return RESET;
        case HyperCPU::LogLevel::WARNING: return YELLOW;
        case HyperCPU::LogLevel::ERROR:   return RED;
        default:
          HyperCPU::unreachable();
      }
    }

  public:
    Logger(LogLevel default_loglevel) : _loglevel(default_loglevel) { }

    template<typename... Args>
    void Log(LogLevel lvl, std::string_view fmt, Args&&... args) const noexcept {
      if (static_cast<std::uint_fast8_t>(lvl) < static_cast<std::uint_fast8_t>(_loglevel)) {
        return;
      }
      
      auto ch = DefineMsgChar(lvl);
      auto bold_col = DefineBoldColor(lvl);
      auto col = DefineColor(lvl);

      print("{}[{}]{} {}", bold_col, ch, RESET, col);
      print("{}{}\n", std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...)), RESET);
    }
  };
}
