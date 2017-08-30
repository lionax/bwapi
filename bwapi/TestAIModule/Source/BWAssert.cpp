#include "BWAssert.h"
#include <fstream>
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>
#include <BWAPI.h>

#define BUFFER_SIZE 1024

void log(const char* format, ...)
{
  char buffer[BUFFER_SIZE];

  va_list ap;
  va_start(ap, format);
  vsnprintf(buffer, BUFFER_SIZE, format, ap);
  va_end(ap);

  FILE *outfile;
  BWAPI::Broodwar->printf(buffer);
  if (fopen_s(&outfile, "bwapi-data/logs/TestModule - Failed Asserts.log", "a+")==0)
  {
    if (outfile)
    {
      fprintf(outfile, buffer);
      fprintf(outfile, "\n");
      fclose(outfile);
    }
  }
}