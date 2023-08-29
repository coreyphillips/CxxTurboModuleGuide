#pragma once

#if __has_include(<React-Codegen/AppSpecsJSI.h>) // CocoaPod headers on Apple
#include <React-Codegen/AppSpecsJSI.h>
#elif __has_include("AppSpecsJSI.h") // CMake headers on Android
#include "AppSpecsJSI.h"
#endif
#include <memory>
#include <string>

namespace facebook::react
{
  class NativeSampleModule : public NativeSampleModuleCxxSpec<NativeSampleModule>
  {
  public:
    NativeSampleModule(std::shared_ptr<CallInvoker> jsInvoker);

    int doFibExpensive(jsi::Runtime &rt, int n);
    std::string hello(jsi::Runtime &rt);
    std::string hashString(jsi::Runtime &rt, const std::string& input);
  };
} // namespace facebook::react
