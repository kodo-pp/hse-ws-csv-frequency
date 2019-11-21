#include <csvfreq/frequency_analyzer.hpp>

#include <algorithm>
#include <utility>


namespace csv
{

void FrequencyAnalyzer::add(const std::string& value)
{
    if (_map.count(value) == 0)
    {
        _map.emplace(std::move(value), 1);
    }
    else
    {
        ++_map.at(value);
    }
}


FrequencyAnalyzer::SortedType FrequencyAnalyzer::getSorted() const
{
    SortedType result;
    result.reserve(_map.size());

    for (const std::pair<std::string, size_t>& pair : _map)
    {
        result.emplace_back(pair.second, pair.first);
    }

    using Pair = std::pair<size_t, std::string>;
    std::sort(result.begin(), result.end(), [](const Pair& a, const Pair& b) {
        return std::make_pair(-a.first, a.second) < std::make_pair(-b.first, b.second);
    });
    return result;
}

}
