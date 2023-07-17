#include <fstream>
#include "fib/fib.h"
#include "hello/hello.h"
#include "NativeSampleModule.h"


namespace facebook::react
{
  NativeSampleModule::NativeSampleModule(std::shared_ptr<CallInvoker> jsInvoker)
      : NativeSampleModuleCxxSpec(std::move(jsInvoker)) {}

  int NativeSampleModule::doFibExpensive(jsi::Runtime &rt, int n)
  {
    return ::doFibExpensive(n);
  }
  std::string NativeSampleModule::hello(jsi::Runtime &rt) {
            return std::string(::hello()); // convert char* to std::string
    }
} // namespace facebook::react
