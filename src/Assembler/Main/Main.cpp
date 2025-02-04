#include <filesystem>
#include <print>

#include <Assembler/Core/Compiler.hpp>
#include <Logger/Logger.hpp>
#include <Logger/Colors.hpp>
#include <Assembler/Utils/Extension.hpp>
#include <Emulator/Main/Main.hpp>

#include <argparse/argparse.hpp>

#include <mapbox/eternal.hpp>


constexpr const inline auto loglevel_assoc = mapbox::eternal::map<mapbox::eternal::string, HyperCPU::LogLevel>({
  {"debug", HyperCPU::LogLevel::DEBUG},
  {"info", HyperCPU::LogLevel::INFO},
  {"warning", HyperCPU::LogLevel::WARNING},
  {"error", HyperCPU::LogLevel::ERROR},
});

int main(int argc, char** argv) {
  argparse::ArgumentParser program("hcasm");
  program.add_argument("source")
    .help("source file to be assembled")
    .required();
  program.add_argument("-o")
    .help("name of the binary file");
  program.add_argument("-c")
    .help("compile to object file");
  program.add_argument("-v")
    .default_value(std::string{"warning"})
    .help("set verbosity level. possible modes:\n- debug\n- info\n- warning\n- error");

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception& err) {
    std::cerr << err.what() << '\n';
    std::exit(1);
  }

  auto source = program.get<std::string>("source");
  std::string result;
  if (program.present("-o")) {
    result = program.get<std::string>("-o");
  } else {
    result = HCAsm::CreateObjectFilename(source);
    if (result == source) {
      result += ".o";
    }
  }

  HCAsm::HCAsmCompiler compiler{ loglevel_assoc.at(program.get<std::string>("-v").c_str()) };
  
  // Verify that files are available
  std::ifstream src(source);
  std::ofstream dst(result, std::ios::binary | std::ios::ate);
  if (!src.is_open()) {
    HCAsm::logger.Log(HyperCPU::LogLevel::ERROR, "Failed to open source file!");
    std::exit(1);
  }

  HCAsm::logger.Log(HyperCPU::LogLevel::DEBUG, "Source and destination files handles acquired");
  std::string contents(
    (std::istreambuf_iterator<char>(src)),
    std::istreambuf_iterator<char>()
    );

  std::uint32_t code_size;

  auto binary = compiler.Compile(contents, code_size);

  HCAsm::WriteResultFile(program.present("-c") ? HyperCPU::FileType::Object : HyperCPU::FileType::Binary, binary, dst, code_size);
}

std::string HCAsm::CreateObjectFilename(std::string str) {
  std::size_t lastDotPos = str.rfind('.');
  if (lastDotPos != std::string::npos) {
    str.replace(lastDotPos + 1, str.length() - lastDotPos - 1, "o");
  }
  return str;
}

void HCAsm::WriteResultFile(HyperCPU::FileType type, HCAsm::BinaryResult& result, std::ofstream& output, std::uint32_t code_size) {
  HyperCPU::GenericHeader gen_header;
  gen_header.type = type;
  gen_header.magic = HyperCPU::magic;
  gen_header.version = HyperCPU::current_version;
  gen_header.code_size = code_size;
  output.write(reinterpret_cast<char*>(&gen_header), sizeof(gen_header));

  output.write(reinterpret_cast<char*>(result.binary), code_size);
}
