#include <fstream>
#include "fib/fib.h"
#include "hello/hello.h"
#include "salt/salt.h"
#include <sstream>
#include "NativeSampleModule.h"

namespace facebook::react
{
  NativeSampleModule::NativeSampleModule(std::shared_ptr<CallInvoker> jsInvoker)
      : NativeSampleModuleCxxSpec(std::move(jsInvoker))
  {
    if (sodium_init() < 0) {
      // The library couldn't be initialized.
      throw std::runtime_error("Failed to initialize libsodium");
    }
  }

  int NativeSampleModule::doFibExpensive(jsi::Runtime &rt, int n)
  {
    return ::doFibExpensive(n);
  }

  std::string NativeSampleModule::hello(jsi::Runtime &rt) {
    return std::string(::hello()); // convert char* to std::string
  }

  std::string NativeSampleModule::hashString(jsi::Runtime &rt, const std::string& input) {
      unsigned char hash[crypto_hash_sha256_BYTES];
      crypto_hash_sha256(hash, reinterpret_cast<const unsigned char*>(input.c_str()), input.length());

      std::stringstream ss;
      for(int i = 0; i < crypto_hash_sha256_BYTES; i++)
          ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
      return ss.str();
  }
} // namespace facebook::react
