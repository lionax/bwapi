#include "Logger.h"
#include <stdio.h>

using namespace ReplayTool;

Logger::Logger(const char *filename)
  : file(filename == nullptr ? nullptr : fopen(filename, "a"))
{
}

Logger::~Logger()
{
  if (file != nullptr)
  {
    fclose(file);
    file = nullptr;
  }
}

void Logger::writeLine(const char *pszFormat, ...)
{
  if (file != nullptr)
  {
    va_list vl;
    va_start(vl,pszFormat);
    vfprintf(file, pszFormat, vl);
    fprintf(file, "\n");
    va_end(vl);
  }
}