//#include <iostream>
//
//// Templated function for floating-point types
//template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
//T half(T value) {
//    return value / 2.0;
//}
//
//// Overloaded function for integer types
//int half(int value) {
//    return value / 2;
//}
//
//int main() {
//    // Test with floating-point types
//    std::cout << "Half of 5.0 (float): " << half(5.0f) << std::endl;
//    std::cout << "Half of 7.0 (double): " << half(7.0) << std::endl;
//
//    // Test with integer types
//    std::cout << "Half of 8 (int): " << half(8) << std::endl;
//    std::cout << "Half of 9 (int): " << half(9) << std::endl;
//    std::cout << "Half of 10 (int): " << half(10) << std::endl;
//
//    return 0;
//}
