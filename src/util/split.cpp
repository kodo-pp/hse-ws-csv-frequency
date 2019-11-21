#include <csvfreq/util.hpp>


namespace csv::util
{

namespace
{
    void recursiveSplit(
        const std::string& s,
        char delimiter,
        std::vector<std::string>& result,
        size_t offset
    )
    {
        size_t index = s.find(delimiter, offset);
        if (index == s.npos)
        {
            result.emplace_back(s.substr(offset));
            return;
        }

        result.emplace_back(s.substr(offset, index - offset));
        recursiveSplit(s, delimiter, result, index + 1);
    }
}


std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    recursiveSplit(str, delimiter, result, 0);
    return result;
}

}
