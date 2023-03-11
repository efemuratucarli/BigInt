#ifndef BIGINT
#define BIGINT
#include <string>

class BigInt
{
    public:
        BigInt(std::string value);
        std::string get_value();
        void display_value(std::string disp_option);
        void set_value(std::string value);
        int get_size();
        BigInt add(BigInt& num);
        void makeThemEqualLength(BigInt& num);
        BigInt multiply(BigInt& num);
        bool isSmaller(BigInt& num1);
        char get_sign();
        void set_sign(char);
        void pad();
        void reverse_sign();
        int get_real_size();
    
    private:
        char sign;
        std::string value;
};

#endif