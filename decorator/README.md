#### Decorator Pattern ###

The decorator is a class that inherits from another, and adds an extra layer of processing to the base class function called. In this example, the base class is a **CSV file reader**. The decorator, called **CSV Processor** does this. It first checks the permission level of the input files in `CSVProcessor::pre_process()`, then calls the base class function **CSVReader::process()**, and lastly, applies the same permission levels in `CSVProcessor::post_process()`. 


Interesting function ... 

```
void CSVProcessor::process(std::string const& output)
{
  pre_process();
  CSVReader::process(output);
  post_process(output);

```

... reflected in the execution. **Rember to remove the `output.txt` before running**. 

```
ubuntu: ~/development/c++/design_patterns/build
$ rm -f ../decorator/data/output.txt
$ ./decorator/decorator 
CSVProcessor::process 
CSVProcessor::pre_process 
mode_t = 33060
CSVReader::process
CSVProcessor::post_process
```

... we notice the priviledges of `output.txt` are not the same as the `input.txt` after processing 

```
ubuntu: ~/development/c++/design_patterns/build
$ ll ../decorator/data/\*
-r--r--r-- 1 ubuntu user 218 Mar 30 18:55 ../decorator/data/input.txt
-r--r--r-- 1 ubuntu user 365 Mar 30 19:33 ../decorator/data/output.txt
```
