#include <decorator.hpp>

#include <iostream>
#include <vector>
#include <sstream>

namespace design_patterns
{

Reader::Reader(std::string const& file)
  : mFile(file)
{
}

void Reader::process(std::string const& output)
{
  // simply copy a file ..
  std::cout << "Reader::process" << std::endl;
  try
  {
    mInput.open(mFile);
    if (mInput.is_open())
    {
      mOutput.open(output);
      if (mOutput.is_open())
      {
        std::string line;
        while (std::getline(mInput, line))
        {
          mOutput << line;
        }
      }
      else
      {
        std::cerr << "error opening " << output << std::endl;
      }
    }
    else
    {
      std::cerr << "error opening " << mFile << std::endl;
    }
  }
  catch (...)
  {
    std::cerr << "exception while processing " << mFile
              << " into " << output << std::endl;
  }
}

CSVReader::CSVReader(std::string const& file, char separator)
  : Reader(file)
  , mSeparator(separator)
{
}

void CSVReader::process(std::string const& output)
{
  std::cout << "CSVReader::process" << std::endl;

  try
  {
    mInput.open(mFile);
    if (mInput.is_open())
    {
      mOutput.open(output);
      if (mOutput.is_open())
      {
        std::string line;
        while (std::getline(mInput, line))
        {
          std::vector<std::string> fields;
          std::string field;
          std::istringstream iss(line);
          while (std::getline(iss, field, mSeparator))
          {
            fields.emplace_back(field);
          }
          for (size_t i = 0; i < fields.size(); ++i)
          {
            mOutput << "<" << i+1 << ": " << fields[i] << "> ";
          }
          mOutput << std::endl;
        }
        mOutput.close();
      }
      else
      {
        std::cerr << "error opening " << output << std::endl;
      }
    }
    else
    {
      std::cerr << "error opening " << mFile << std::endl;
    }
  }
  catch (...)
  {
    std::cerr << "exception while processing " << mFile
              << " into " << output << std::endl;
  }
}

CSVProcessor::CSVProcessor(std::string const& file, char separator)
  : CSVReader(file, separator)
{
}

void CSVProcessor::pre_process()
{
  std::cout << "CSVProcessor::pre_process " << std::endl;
  struct stat st;
  if (stat(mFile.c_str(), &st) != 0)
  {
    std::cerr << "mode_t not found " << std::endl;
    return;  
  }
  std::cout << "mode_t = " << mMode << std::endl;
}

void CSVProcessor::post_process(std::string const& output)
{
  std::cout << "CSVProcessor::post_process " << std::endl;
  if (chmod(output.c_str(), mMode) != 0)
    std::cerr << "error in chmod " << output << std::endl;
}

void CSVProcessor::process(std::string const& output)
{
  std::cout << "CSVProcessor::process " << std::endl;
  pre_process();
  CSVReader::process(output);
  post_process(output);
}
}
