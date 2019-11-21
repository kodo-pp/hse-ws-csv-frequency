#ifndef CSVFREQ_FREQUENCY_ANALYZER_HPP_INCLUDED
#define CSVFREQ_FREQUENCY_ANALYZER_HPP_INCLUDED

#include <map>
#include <string>
#include <vector>


namespace csv
{

class FrequencyAnalyzer
{
public:
    using MapType = std::map<std::string, size_t>;
    using SortedType = std::vector<std::pair<size_t, std::string>>;

    void add(const std::string& value);
    SortedType getSorted() const;

private:
    MapType _map;
};

}

#endif // CSVFREQ_FREQUENCY_ANALYZER_HPP_INCLUDED
