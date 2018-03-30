#include <decorator.hpp>

#include <iostream>

using namespace design_patterns;

int main()
{
  std::string inputFile("../decorator/data/input.txt");
  std::string outputFile("../decorator/data/output.txt");

  CSVProcessor reader(inputFile, ',');
  reader.process(outputFile);

  return 0;
}
