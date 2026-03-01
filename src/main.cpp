#include <iostream>
#include <ostream>
#include <type_traits>



template<typename T, typename = void>
struct IsPrintable : std::false_type{};

template<typename T>
struct IsPrintable<T, std::void_t<decltype(
    std::declval<std::ostream>() << std::declval<T>()
)
>>: std::true_type{};

static_assert(IsPrintable<int>{} == true, "");


template<typename... Args, typename = std::enable_if<IsPrintable<Args>{}...>>
void print(Args&&... args){
    (std::cout << ... << args);
}

int main(){
    std::cout << "Hi!";
    return 0;
}