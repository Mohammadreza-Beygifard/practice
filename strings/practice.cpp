#include <iostream>
#include<string>
#include <cstring>

std::string ToUpper (const std::string & input)
{
    std::string output{};

    for(char c : input)
    {
        output.push_back(std::toupper(c));
    }

    return output;

}

std::string ToLower (const std::string & input)
{
    std::string output{};

    for(char c : input)
    {
        output.push_back(std::tolower(c));
    }

    return output;

}

enum class Case {SENSETIVE, INSENSETIVE};

struct SearchResult
{
    std::size_t index{};
    bool exist{false};
};

SearchResult Search(const Case& search_case, const std::string& interesting_string, const std::string& source)
{
    std::string local_interesting_string = interesting_string;
    std::string local_source = source;
    if(search_case == Case::INSENSETIVE)
    {
        local_interesting_string = ToLower(interesting_string);
        local_source = ToLower(source);
    }
    SearchResult result{};

    result.index = local_source.find(local_interesting_string);
    result.exist = (result.index != std::string::npos);

    return result;

}

int main()
{
    std::string phrase = "Hello";
    std::cout << ToUpper(phrase) << "\n";
    std::cout << ToLower(phrase) << "\n";

    auto result = Search(Case::INSENSETIVE, "hello", "Hello World");
    std::cout << result.exist << "\n";

    result = Search(Case::SENSETIVE, "hello", "Hello World");
    std::cout << result.exist << "\n";
    
    return 0;
}