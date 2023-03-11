#include "BigInt.h"
#include <iostream>
#include <cmath>

BigInt::BigInt(std::string value)
 {
    this->value = value.substr(1);
    this->sign = value[0];
 }

std::string BigInt::get_value()
{
    return this->value;
}

void BigInt::display_value(std::string disp_option)
{
    if(this->get_size() == 1 && this->get_value() == "0")
    {
        std::cout << this->get_value() << std::endl;
    }
    
    else if(disp_option == "-p") //pretty display without 0s at the front of the number
    {
        int i = 0;
        while(this->get_value()[i] == '0')
        {
            i++;
        }

        if(this->get_sign() == '-')
        {
            std::cout << this->get_sign() << " " << this->get_value().substr(i) << std::endl;
        }

        else
        {
             std::cout << this->get_value().substr(i) << std::endl;
        }
    }

    else if (disp_option == "")
    {
        std::cout << this->get_value() << std::endl; //default option
    }
    
    else
    {
        throw std::logic_error("not a valid display option");
    }
}

void BigInt::set_value(std::string value)
{
    this->value = value;
}

int BigInt::get_size()
{
    return this->get_value().size();
}


void BigInt::makeThemEqualLength(BigInt &num)
{
    int difference = num.get_size() - this->get_size();
    if(difference > 0)
    {
        for(int i = 0; i < difference; i++)
        {
            this->set_value("0" + this->get_value());
        }
        return;
    }

    else if(difference < 0)
    {
        for(int i = 0; i < -difference; i++)
        {
            std::string new_val = '0' + num.get_value();
            num.set_value(new_val);
        }
        return;
    }
    
    else
    {
        return;
    }

}


BigInt BigInt::add(BigInt &num)
{
    BigInt result {"++"};
    result.set_value("");
    this->makeThemEqualLength(num);
    
    if((this->get_sign() == '-' && num.get_sign() != '-') || (this->get_sign() != '-' && num.get_sign() == '-'))
    {
        bool flag = this->isSmaller(num);
        
        if(flag && this->get_sign() == '-')
        {
            int kl = this->get_size();
            int carry = 0;
            
            for(int i = kl; i > 0; i--)
            {
                int k = this->get_value()[i-1] - '0';
                int m = num.get_value()[i-1] - '0';
                int sum = m - k - carry;
                
                if(m < k || sum < 0)
                {
                    sum = sum + 10;
                    carry = 1;
                    result.set_value(std::to_string(sum) + result.get_value());
                }
                
                else
                {
                    result.set_value(std::to_string(sum) + result.get_value());
                    carry = 0;
                }

            }
        }
        
        else if(flag && this->get_sign() == '+')
        {
            result.set_sign('-');
            int kl = this->get_size();
            int carry = 0;
            
            for(int i = kl; i > 0; i--)
            {
                int k = this->get_value()[i-1] - '0';
                int m = num.get_value()[i-1] - '0';
                int sum = m - k - carry;
                
                if(m < k || sum < 0)
                {
                    sum = sum + 10;
                    carry = 1;
                    result.set_value(std::to_string(sum) + result.get_value());
                }
                
                else
                {
                    result.set_value(std::to_string(sum) + result.get_value());
                    carry = 0;
                }

            }

        }
        
        else if(!flag && this->get_sign() == '-')
        {
            result.set_sign('-');
            int kl = this->get_size();
            int carry = 0;
            
            for(int i = kl; i > 0; i--)
            {
                int k = this->get_value()[i-1] - '0';
                int m = num.get_value()[i-1] - '0';
                int sum = k - m - carry;
                
                if(k < m || sum < 0)
                {
                    sum = sum + 10;
                    carry = 1;
                    result.set_value(std::to_string(sum) + result.get_value());
                }
                
                else
                {
                    result.set_value(std::to_string(sum) + result.get_value());
                    carry = 0;
                }
            }
            result.set_sign('-');         
        }

        else
        {
            int kl = this->get_size();
            int carry = 0;
            
            for(int i = kl; i > 0; i--)
            {
                int k = this->get_value()[i-1] - '0';
                int m = num.get_value()[i-1] - '0';
                int sum = k - m - carry;
                
                if(k < m || sum < 0)
                {
                    sum = sum + 10;
                    carry = 1;
                    result.set_value(std::to_string(sum) + result.get_value());
                }
                
                else
                {
                    result.set_value(std::to_string(sum) + result.get_value());
                    carry = 0;
                }

            }
            result.set_sign('+');
        }
        return result;
    }
   
    else
    {
        int carry = 0;
        if(this->get_sign() == '-')
        {
            int kl = this->get_size();
            
            for(int i = kl; i > 0; i--)
            {
                int k = this->get_value()[i-1] - '0';
                int m = num.get_value()[i-1] - '0';
                int sum = k + m + carry;
                
                if(sum < 10)
                {
                    result.set_value(std::to_string(sum) + result.get_value());
                    carry = 0;
                }
                
                else
                {
                    result.set_value(std::to_string(sum % 10) + result.get_value());
                    carry = 1;
                }
            }
            
            if(carry == 1)
            {
                result.set_value('1' + result.get_value());
            }
            
            result.set_sign('-');
            return result;
        }

        else
        {
            int kl = this->get_size();
            for(int i = kl; i > 0; i--)
            {
                int k = this->get_value()[i-1] - '0';
                int m = num.get_value()[i-1] - '0';
                int sum = k + m + carry;
                if(sum < 10)
                {
                    result.set_value(std::to_string(sum) + result.get_value());
                    carry = 0;
                }
                else
                {
                    result.set_value(std::to_string(sum % 10) + result.get_value());
                    carry = 1;
                }
            }         
            if(carry == 1)
            {
                result.set_value('1' + result.get_value());
            }
            result.set_sign('+');
            return result;            
        }
    }
}

BigInt BigInt::multiply(BigInt &num)
{
    this->makeThemEqualLength(num);
    BigInt result {"++"};
    result.set_value("");
    
    if(this->get_size() % 2 == 1 && this->get_size() > 1)
    {
        this->pad();
        num.pad();
    }

    if(this->get_sign() == '+') 
    {
        if (this->get_size() == 1)
        {
            int mult = (this->get_value()[0] - '0') * (num.get_value()[0] - '0');
            result.set_value(std::to_string(mult));
        }

        else
        {
            int half = this->get_size() / 2;
            BigInt x1 {"+" + this->get_value().substr(0,half)};
            BigInt y1 {"+" + num.get_value().substr(0,half)};
            BigInt x2 {"+" + this->get_value().substr(half,half)};
            BigInt y2 {"+" + num.get_value().substr(half,half)};
            BigInt a_b = x1.add(x2);
            BigInt c_d = y1.add(y2);
            BigInt a_b_c_d = a_b.multiply(c_d);
            BigInt ac = x1.multiply(y1);
            BigInt bd = x2.multiply(y2);
            ac.reverse_sign();
            bd.reverse_sign();
            BigInt t_t_o = a_b_c_d.add(ac).add(bd);
            ac.reverse_sign();
            bd.reverse_sign();
            BigInt t_n_2b {"+" + ac.get_value()};
            BigInt t_n_b {"+" + t_t_o.get_value()};
            if(t_n_2b.get_size() % 2 == 1 && t_n_b.get_size() > 1)
            {
                t_n_2b.pad();
                t_n_b.pad();
            }          
        
            for(int i = 0; i < this->get_size()/2; i++)
            {
                t_n_b.set_value(t_n_b.get_value() + '0');

            }
        
            for(int i = 0; i < this->get_size(); i++)
            {
                t_n_2b.set_value(t_n_2b.get_value() + '0');

            }

            result = t_n_b.add(t_n_2b).add(bd);
        }
        
        if(num.get_sign() == '+')
        {
            result.set_sign('+');
        }

        else
        {
            result.set_sign('-');
        }       
        return result;
    }

    else
    {
        if(this->get_size() == 1)
        {
            int mult = (this->get_value()[0] - '0') * (num.get_value()[0] - '0');
            result.set_value(std::to_string(mult));
        }

        else
        {
            int half = this->get_size() / 2;
            BigInt x1 {"+" + this->get_value().substr(0,half)};
            BigInt y1 {"+" + num.get_value().substr(0,half)};
            BigInt x2 {"+" + this->get_value().substr(half,half)};
            BigInt y2 {"+" + num.get_value().substr(half,half)};
            BigInt a_b = x1.add(x2);
            BigInt c_d = y1.add(y2);
            BigInt a_b_c_d = a_b.multiply(c_d);
            BigInt ac = x1.multiply(y1);
            BigInt bd = x2.multiply(y2);
            ac.reverse_sign();
            bd.reverse_sign();
            BigInt t_t_o = a_b_c_d.add(ac).add(bd);
            ac.reverse_sign();
            bd.reverse_sign();
            BigInt t_n_2b {"+" + ac.get_value()};
            BigInt t_n_b {"+" + t_t_o.get_value()};   

            if(t_n_2b.get_size() % 2 == 1 && t_n_b.get_size() > 1)
            {
                t_n_2b.pad();
                t_n_b.pad();
            }            
            
            for(int i = 0; i < this->get_size() / 2; i++)
            {
                t_n_b.set_value(t_n_b.get_value() + '0');
            }
            
            for(int i = 0; i < this->get_size(); i++)
            {
                t_n_2b.set_value(t_n_2b.get_value() + '0');
            }
            
            result = t_n_b.add(t_n_2b).add(bd);
        }
        if(num.get_sign() == '+')
        {
            result.set_sign('-');
        }

        else
        {
            result.set_sign('+');
        }
        return result;
    }
}

char BigInt::get_sign()
{
    return this->sign;
}

bool BigInt::isSmaller(BigInt& num1)
{
    for (int i = 0; i < this->get_size(); i++)
    {
        if (num1.get_value()[i] < this->get_value()[i])
        {
            return false;
        }
        
        else if (num1.get_value()[i] > this->get_value()[i])
        {
            return true;  
        }
    }
    return false;
}

void BigInt::set_sign(char new_sign)
{
    this->sign = new_sign;
}

void BigInt::pad()
{
   int i = 1;  
   
   while(pow(2,i) < this->get_size())
   {
    i++;
   }
   int diff = pow(2,i) - this->get_size();

   for(int i = 0; i < diff;i++)
   {
    this->set_value('0' + this->get_value());
   }
}

void BigInt::reverse_sign()
{
    if(this->get_sign() == '-')
    {
        this->set_sign('+');
    }

    else
    {
        this->set_sign('-');
    }
}

int BigInt::get_real_size()
{
    int i = 0;
    if(this->get_size() == 1 && this->get_value() == "0")
    {
        return this->get_size();
    }
    while(this->get_value()[i] == '0')
    {
        i++;
    }
    return this->get_size() - i;
}