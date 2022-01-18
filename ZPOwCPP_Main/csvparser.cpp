#include "csvparser.h"


CsvParser::CsvParser(const std::string &separator)
{
    this->separator = separator;
}

std::vector<std::string> CsvParser::parseLine(std::string line)
{
    std::vector<std::string> cells;

    if (line.length() == 0)
    {
        return cells;
    }

    int currentPosition = 0;
    int cellStartPosition = 0;

    while (true)
    {
        auto nextSeparatorPosition = line.find(separator, currentPosition);
        auto nextQuotePosition = line.find('"', currentPosition);

        if (nextQuotePosition != line.npos && nextQuotePosition < nextSeparatorPosition)
        {
            currentPosition = line.find('"', nextQuotePosition + 1) + 1;
            continue;
        }

        cells.push_back(line.substr(cellStartPosition, nextSeparatorPosition - cellStartPosition));
        currentPosition = cellStartPosition = nextSeparatorPosition + 1;

        if (nextSeparatorPosition == line.npos)
        {
            return cells;
        }
    }
}

const std::string &CsvParser::getSeparator() const
{
    return separator;
}
