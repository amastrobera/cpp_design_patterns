#ifndef decorator_h
#define decorator_h

#include <sys/stat.h> //all system calls for Linux
#include <fstream>

namespace design_patterns
{

class Reader
{
  public:
  Reader(std::string const& file);
  virtual ~Reader() = default;
  virtual void process(std::string const& output) = 0;

  protected:
  std::string mFile;
  std::ofstream mOutput;
  std::ifstream mInput;
};

class CSVReader : public Reader
{
  public:
  CSVReader(std::string const& file, char separator);
  ~CSVReader() = default;
  virtual void process(std::string const& output) override;

  protected:
  char mSeparator;
};

// decorator: adds functions pre-process and post-process
// --> these two functions check the level of priviledges, save them, and
//     write an output with the same priviledges as the input
class CSVProcessor : public CSVReader
{
  public:
  CSVProcessor(std::string const& file, char separator);
  ~CSVProcessor() = default;
  virtual void process(std::string const& output) override;

  private:
  void pre_process();
  void post_process(std::string const& output);
  mode_t mMode; // STAT: 666, 444, etc ... -> CHMOD mPermissions
};
}

#endif
