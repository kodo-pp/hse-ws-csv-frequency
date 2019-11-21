#include <csvfreq/util.hpp>

#include <stdexcept>


namespace csv::util
{

int stringToInt(const std::string& str)
{
    size_t index = 0;
    int converted;

    try
    {
        converted = std::stoi(str, &index);
    }
    catch (const std::invalid_argument&)
    {
        throw std::runtime_error("Invalid integer: " + str);
    }

    if (index != str.size())
    {
        throw std::runtime_error("Invalid integer: " + str);
    }
    return converted;
}

}
