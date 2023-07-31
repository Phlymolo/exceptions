// Nathan Rapp
// CIS 1202-5T1
// July 30, 2023

#include <iostream>
#include <stdexcept>
#include <cctype>

using namespace std;

// Custom exception for invalid character
class InvalidCharacterException : public exception
{
public:
    const char *what() const throw()
    {
        return "Invalid Character Exception!";
    }
};

// Custom exception for invalid range
class InvalidRangeException : public exception
{
public:
    const char *what() const throw()
    {
        return "Invalid Range Exception!";
    }
};

char character(char start, int offset)
{
    // Check if start is a letter
    if (!isalpha(start))
    {
        throw InvalidCharacterException();
    }

    char target = start + offset;

    // Check if target is a letter
    if (!isalpha(target))
    {
        throw InvalidRangeException();
    }

    return target;
}

int main()
{

    // driver to test character function

    // test cases
    char start[] = {'a', 'a', 'Z', '?', 'A'};
    int offset[] = {1, -1, -1, 5, 32};

    // loop through test cases
    for (int i = 0; i < 5; i++)
    {

        // try to call character function
        try
        {
            char result = character(start[i], offset[i]);
            cout << "character('" << start[i] << "', " << offset[i] << ") returns '" << result << "'." << endl;
        }
        catch (const exception &e)
        {
            cout << "character('" << start[i] << "', " << offset[i] << ") throws an exception: " << e.what() << endl;
        }
    }

    return 0;
}
