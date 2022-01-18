#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <vector>

class CsvParser
{
private:
    std::string separator;
public:
    CsvParser(const std::string& separator);
    std::vector<std::string> parseLine(std::string line);
    const std::string& getSeparator() const;
};

#endif // CSVPARSER_H
