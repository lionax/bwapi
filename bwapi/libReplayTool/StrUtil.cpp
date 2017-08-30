#include "StrUtil.h"
#include <cstdarg>
#include <stdio.h>

using namespace ReplayTool;

std::string StrUtil::format(const char* format, ...)
{
  va_list marker;
  const size_t bufferMaxSize = 1024;
  char buffer[bufferMaxSize];

  va_start(marker, format);
  vsnprintf(buffer, format, marker);
  va_end(marker);

  return std::string(buffer);
}
