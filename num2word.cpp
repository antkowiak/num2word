/* ************************************************************************
 *
 * num2word.cpp - Convert integer numbers (up to unsigned long long max)
 *                to english words.
 *
 * Created by and copyright: Ryan Antkowiak
 *
 * Created on: 2016-06-22
 *
 * Free for educational and non-commercial use.
 *
 * ********************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

typedef unsigned long long int TNumber;

static const std::string EMPTY  = "";
static const std::string SPACE  = " ";
static const std::string HYPHEN = "-";

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
        result += numberToString(quintillions) + SPACE + QUINTILLION + SPACE;

    if (quadrillions > 0)
        result += numberToString(quadrillions) + SPACE + QUADRILLION + SPACE;

    if (trillions > 0)
        result += numberToString(trillions) + SPACE + TRILLION + SPACE;

    if (billions > 0)
        result += numberToString(billions) + SPACE + BILLION + SPACE;

    if (millions > 0)
        result += numberToString(millions) + SPACE + MILLION + SPACE;

    if (thousands > 0)
        result += numberToString(thousands) + SPACE + THOUSAND + SPACE;

    if (hundreds > 0)
        result += numberToString(hundreds) + SPACE + HUNDRED + SPACE;

    if (tens > 1)
    {
        result += TENS_toString(tens);

        // Hyphenate tens followed by non-zero ones
        if (ones > 0)
            result += HYPHEN;
        else
            result += SPACE;
    }

    result += ONES_toString(ones);

    // Remove any trailing SPACE
    if ( (!result.empty()) && (result.rfind(SPACE) == result.size() - SPACE.size()) )
        result.resize(result.size() - SPACE.size());

    return result;
}

int main(int argc, char * argv[])
{
    if (argc > 1)
    {
        // Convert each of the arguments, separated with a newline
        for (int count = 1 ; count < argc ; ++count)
        {
            std::cout << numberToString(strtoull(argv[count], NULL, 0)) << std::endl;
        }
    }
    else
    {
        std::string line;
        while (std::getline(std::cin, line))
        {
            // Interactively convert the input
            std::cout << numberToString(strtoull(line.c_str(), NULL, 0)) << std::endl;
        }
    }

    return 0;
}
