/* ************************************************************************
 *
 * num2word.cpp - Convert integer numbers (up to unsigned long long max)
 *                to english words.
 *
 * Created by and copyright: Ryan Antkowiak (antkowiak@gmail.com)
 *
 * Created on: 2016-06-22
 *
 * Free for educational and non-commercial use.
 *
 * For questions about a commercial license, contact antkowiak@gmail.com
 *
 * ********************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

typedef unsigned long long int TNumber;

static const std::string EMPTY  = "";

static const std::string ZERO   = "zero";

static const std::string ONES[] = { "one",     "two",       "three",    "four",     "five",
                                    "six",     "seven",     "eight",    "nine",     "ten",
                                    "eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                                    "sixteen", "seventeen", "eighteen", "nineteen" };

static const std::string TENS[] = { "twenty", "thirty",  "forty",  "fifty",
                                    "sixty",  "seventy", "eighty", "ninety" };

static const std::string HUNDRED     = "hundred";
static const std::string THOUSAND    = "thousand";
static const std::string MILLION     = "million";
static const std::string BILLION     = "billion";
static const std::string TRILLION    = "trillion";
static const std::string QUADRILLION = "quadrillion";
static const std::string QUINTILLION = "quintillion";

static std::string ONES_toString(TNumber n)
{
    if (n > 0 && n < 20)
        return ONES[n-1];

    return EMPTY;
}

static std::string TENS_toString(TNumber n)
{
    if (n > 1 && n < 10)
        return TENS[n-2];

    return EMPTY;
}

static std::string numberToString(TNumber n)
{
    if (n == 0)
        return ZERO;

    std::string result = EMPTY;

    TNumber quintillions = (n / 1000000000000000000);
    TNumber quadrillions = (n % 1000000000000000000) / 1000000000000000;
    TNumber trillions    = (n % 1000000000000000) / 1000000000000;
    TNumber billions     = (n % 1000000000000) / 1000000000;
    TNumber millions     = (n % 1000000000) / 1000000;
    TNumber thousands    = (n % 1000000) / 1000;
    TNumber hundreds     = (n % 1000) / 100;
    TNumber tens         = (n % 100) / 10;
    TNumber ones         = (n % 10);

    if (tens == 1)
        ones += 10;

    if (quintillions > 0)
        result += numberToString(quintillions) + QUINTILLION;

    if (quadrillions > 0)
        result += numberToString(quadrillions) + QUADRILLION;

    if (trillions > 0)
        result += numberToString(trillions) + TRILLION;

    if (billions > 0)
        result += numberToString(billions) + BILLION;

    if (millions > 0)
        result += numberToString(millions) + MILLION;

    if (thousands > 0)
        result += numberToString(thousands) + THOUSAND;

    if (hundreds > 0)
        result += numberToString(hundreds) + HUNDRED;

    if (tens > 1)
        result += TENS_toString(tens);

    result += ONES_toString(ones);

    return result;
}

int main(int argc, char * argv[])
{
    TNumber n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                    19, 20, 21, 22, 29, 30, 31, 32, 99, 100, 101, 102,
                    119, 120, 121, 129, 130, 131, 199, 200, 201, 202,
                    99,
                    999,
                    9999,
                    99999,
                    999999,
                    9999999,
                    99999999,
                    999999999,
                    9999999999,
                    99999999999,
                    999999999999,
                    9999999999999,
                    99999999999999,
                    999999999999999,
                    9999999999999999,
                    99999999999999999,
                    999999999999999999,
                    1799999999999999999,
                    0 };

    for (TNumber i = 0 ; i < 57 ; ++i)
    {
        std::cout << n[i] << " " << numberToString(n[i]) << std::endl;
    }

    return 0;
}

