#include <csvfreq/arguments.hpp>
#include <csvfreq/frequency_analyzer.hpp>
#include <csvfreq/io.hpp>
#include <csvfreq/util.hpp>

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>


int main(int argc, char** argv)
{
    try
    {
        csv::args::ParsedArguments args = csv::args::parseArguments(argc, const_cast<const char**>(argv));

        csv::io::FileReader reader(args.inputFileName);
        size_t lineNumber = 0;
        csv::FrequencyAnalyzer analyzer;

        while (true)
        {
            std::string inputLine = reader.readLine();
            if (reader.eof())
            {
                break;
            }
            ++lineNumber;

            std::vector<std::string> columns = csv::util::split(inputLine, ',');
            if (args.columnIndex < 0 || static_cast<size_t>(args.columnIndex) >= columns.size())
            {
                throw std::out_of_range(
                    "Column index "
                    + std::to_string(args.columnIndex)
                    + " is out of range [0; "
                    + std::to_string(columns.size())
                    + ") [input file, line "
                    + std::to_string(lineNumber)
                    + "]"
                );
            }
            analyzer.add(columns[args.columnIndex]);
        }

        csv::FrequencyAnalyzer::SortedType frequencies = analyzer.getSorted();
        for (const std::pair<size_t, std::string>& value : frequencies)
        {
            std::cout
                << "Value ["
                << value.second
                << "], frequency: "
                << std::to_string(value.first)
                << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
