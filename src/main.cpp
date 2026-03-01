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

template<typename T>
concept Printable = requires (T arg) {
    IsPrintable<T>{} == true;
};



template<Printable... T>
void print(T... arg){
    (std::cout << ... << arg);
}

int main(){
    print(1,2,3,4,5,6);

    return 0;
}