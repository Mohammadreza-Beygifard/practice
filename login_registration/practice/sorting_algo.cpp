#include <iostream>
#include <vector>

#define print std::cout<<std::boolalpha

template<typename T>
void print_vector(const T& p_vector)
{
    print << "memebers:" << std::endl;
    for(auto member: p_vector)
    {
        print << member << " ";
    }
    print << std::endl;

}
template <typename T, typename F>
bool is_sorted(const T& p_vector, const F& function)
{
    //check if type T has size() method and at() method
    int size = p_vector.size();
    if (size < 2) return true;

    int first_element = p_vector.at(0);
    for(int index = 1; index < size; index ++)
    {
        int second_element = p_vector.at(index);
        if(!function(first_element, second_element)) return false;
        first_element = second_element;
    }
    return true;
}

template <typename T, typename F>
void sort_step(T& p_vector, const F& function)
{
    //check if type T has size() method and at() method
    if(is_sorted(p_vector, function)) return;
    auto size = p_vector.size();
    if(size == 2)
    {
        auto first_element = p_vector.at(0);
        auto second_element = p_vector.at(1);
        p_vector[0] = second_element;
        p_vector[1] = first_element;
        return;
    }
    int index = 0;
    while(!is_sorted(p_vector, function) && (index + 1) < size)
    {
        T two_memeber_window{};
        two_memeber_window.push_back(p_vector.at(index));
        two_memeber_window.push_back(p_vector.at(index + 1));
        sort_step(two_memeber_window, function);
        p_vector[index] = two_memeber_window.at(0);
        p_vector[index + 1] = two_memeber_window.at(1);
        index++;
    }
    
    // int size = p_vector.size();
    // int half_size = size/2;

    // std::vector<int> first_half_size_vector{};

    // for(int index = 0; index < half_size; index ++)
    // {
    //     first_half_size_vector.push_back(p_vector.at(index));
    // }
    // sort_step(first_half_size_vector, function);

    // std::vector<int> second_half_size_vector{};
    // for(int index = half_size; index < size; index ++)
    // {
    //     second_half_size_vector.push_back(p_vector.at(index));
    // }
    // sort_step(second_half_size_vector, function);

    // p_vector.clear();
    // for(auto member : first_half_size_vector)
    // {
    //     p_vector.push_back(member);
    // }

    // for(auto member : second_half_size_vector)
    // {
    //     p_vector.push_back(member);
    // }

    return;
}

template <typename T, typename F>
void sort(T& p_vector, const F& function)
{
    auto size = p_vector.size();
    int index = 0;
    while(!is_sorted(p_vector, function))
    {
        T two_memeber_window{};
        two_memeber_window.push_back(p_vector.at(index));
        two_memeber_window.push_back(p_vector.at(index + 1));
        sort_step(two_memeber_window, function);
        p_vector[index] = two_memeber_window.at(0);
        p_vector[index + 1] = two_memeber_window.at(1);
        index++;
        index = index % (size-1);
    }
    return;
}

int main()
{
    using std::boolalpha;
    auto sorting_lambda = [](int x, int y) -> bool { return x < y; };

    std::vector<int> zero_size{};
    print << "size 0: " << "expect_true, result: "<<is_sorted(zero_size, sorting_lambda) << std::endl;

    std::vector<int> size_1{1};
    print << "size 1: " << "expect_true, result: "<<is_sorted(size_1, sorting_lambda) << std::endl;

    std::vector<int> size_2_sorted{1, 2};
    print << "size_2_sorted: " << "expect_true, result: "<<is_sorted(size_2_sorted, sorting_lambda) << std::endl;

    std::vector<int> size_2_unsorted{2, 1};
    print << "size_2_unsorted: " << "expect_false, result: "<<is_sorted(size_2_unsorted, sorting_lambda) << std::endl;

    std::vector<int> size_3_sorted{1, 2, 3};
    print << "size_3_sorted: " << "expect_true, result: "<<is_sorted(size_3_sorted, sorting_lambda) << std::endl;

    std::vector<int> size_3_unsorted{1, 2, 0};
    print << "size_3_unsorted: " << "expect_false, result: "<<is_sorted(size_3_unsorted, sorting_lambda) << std::endl;

    auto vector_under_test = size_3_sorted;
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    vector_under_test = size_2_unsorted;
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    vector_under_test = std::vector<int>{2,1,3,4};
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    vector_under_test = std::vector<int>{1,2,4,3};
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    vector_under_test = std::vector<int>{1,2,4,3,5};
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    vector_under_test = std::vector<int>{1,10,4,3,5};
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    vector_under_test = std::vector<int>{1,10,4,3,5,-1};
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    vector_under_test = std::vector<int>{1,2,4,3,5,0,-1,11,12};
    print << "members before sort" << std::endl;
    print_vector(vector_under_test);
    sort(vector_under_test, sorting_lambda);
    print << "members after sort" << std::endl;
    print_vector(vector_under_test);

    return 0;
}