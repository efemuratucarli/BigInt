#include "BigInt.h"
#include <iostream>

int main()
{
    BigInt number1 {"+3141592653589793238462643383279502884197169399375105820974944592"};
    BigInt number2 {"+2718281828459045235360287471352662497757247093699959574966967627"};
    BigInt number3 = number1.add(number2);
    std::cout << number3.get_sign() << number3.get_value() << std::endl; 
    BigInt number4 = number1.multiply(number2);
    std::cout << number4.get_sign() << number4.get_value() << std::endl;
    number4.display_value("-p"); //prints out 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184 which is correct answer.

    BigInt number5 {"-7050"};
    BigInt number6 {"+102"};
    BigInt number7 = number5.add(number6);
    BigInt number8 = number5.multiply(number6);
    number7.display_value("-p");
    number8.display_value("-p");
    return 0;
}