#include "Utils.h"
#include "Program.h"

int main(int argc, char* argv[])
{
  Program program;
  program.ProgramInit();
  program.ProgramLoop();
  program.Close();
  return 0;
}