#include <csvfreq/io.hpp>

#include <stdexcept>


namespace csv::io
{

// FileReader

FileReader::FileReader(const std::string& fileName):
    stream(fileName)
{
    if (!stream.is_open())
    {
        throw std::runtime_error("Unable to open file " + fileName + " for reading");
    }
}

std::string FileReader::readLine()
{
    std::string line;
    std::getline(stream, line);

    if (stream.eof())
    {
        return "";
    }
    if (!stream.good())
    {
        throw std::runtime_error("Read error");
    }

    return line;
}

bool FileReader::eof() const
{
    return stream.eof();
}

}
