#include <csvfreq/arguments.hpp>
#include <csvfreq/util.hpp>

#include <cstdlib>
#include <iostream>


namespace csv::args
{

ParsedArguments parseArguments(int argc, const char** argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: csv-reader <input> <index>" << std::endl;
        std::cerr << "Arguments:" << std::endl;
        std::cerr << "    <input>       - Input file name" << std::endl;
        std::cerr << "    <index>       - Index of a column to select (starting from 0)" << std::endl;
        exit(1);
    }

    ParsedArguments args;
    args.inputFileName = argv[1];
    args.columnIndex = csv::util::stringToInt(argv[2]);
    return args;
}

}
