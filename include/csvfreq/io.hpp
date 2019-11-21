#ifndef CSVFREQ_IO_HPP_INCLUDED
#define CSVFREQ_IO_HPP_INCLUDED

#include <fstream>
#include <utility>


namespace csv::io
{

/**
 * File reader which throws exceptions if any operation fails
 */
class FileReader
{
public:
    FileReader(const std::string& fileName);

    std::string readLine();
    bool eof() const;

private:
    std::ifstream stream;
};

}

#endif // CSVFREQ_IO_HPP_INCLUDED
