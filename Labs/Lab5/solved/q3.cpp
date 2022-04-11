#include <algorithm>

template<typename MapIt>
void showCommonWords(MapIt begin, MapIt end, const std::size_t n) { 
    // typedef std::vector<MapIt> TempContainerType;
    // typedef typename TempContainerType::iterator IterType;
    std::vector<MapIt> wordIters;
    wordIters.reserve(std::distance(begin, end));
    for (auto i = begin; i != end; ++i) wordIters.push_back(i);

    auto sortedRangeEnd = wordIters.begin() + n;
    std::partial_sort(wordIters.begin(), sortedRangeEnd, wordIters.end(),
    [](MapIt it1, MapIt it2){ return it1->second > it2->second; });

    for (auto it = wordIters.cbegin(); it != sortedRangeEnd; ++it) {
        std::printf(" %-10s%10zu\n", (*it)->first.c_str(), (*it)->second);
    }
}





















