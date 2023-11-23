#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

int dfa = 1;
int increment = 0;
string decimal_dotted_notation = "";

void q1(char c)
{
    if (c == '1')
    {
        dfa = 2;
        increment = increment + 128;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        dfa = 2;
    }

    else
    {
        dfa = -1;
    }
}

void q2(char c)
{
    if (c == '1')
    {
        increment = increment + 64;
        dfa = 3;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        dfa = 3;
    }
    else
    {
        dfa = -1;
    }
}
void q3(char c)
{
    if (c == '1')
    {
        increment = increment + 32;
        dfa = 4;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        dfa = 4;
    }
    else
    {
        dfa = -1;
    }
}
void q4(char c)
{
    if (c == '1')
    {
        increment = increment + 16;
        dfa = 5;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        dfa = 5;
    }
    else
    {
        dfa = -1;
    }
}
void q5(char c)
{
    if (c == '1')
    {
        increment = increment + 8;
        dfa = 6;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        dfa = 6;
    }
    else
    {
        dfa = -1;
    }
}
void q6(char c)
{
    if (c == '1')
    {
        increment = increment + 4;
        dfa = 7;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        dfa = 7;
    }
    else
    {
        dfa = -1;
    }
}
void q7(char c)
{
    if (c == '1')
    {
        increment = increment + 2;
        dfa = 8;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        dfa = 8;
    }

    else
    {
        dfa = -1;
    }
}
void q8(char c)
{
    if (c == '1')
    {
        increment = increment + 1; // 128
        stringstream ss;
        ss << increment;
        string increment_in_string;
        ss >> increment_in_string;
        if (decimal_dotted_notation.length() == 0)
        {
            decimal_dotted_notation = decimal_dotted_notation + increment_in_string;
        }
        else
        {
            decimal_dotted_notation = decimal_dotted_notation + "." + increment_in_string;
        }
        increment = 0;
        dfa = 1;
    }
    else if (c == '0')
    {
        increment = increment + 0;
        stringstream ss;
        ss << increment;
        string increment_in_string;
        ss >> increment_in_string;
        if (decimal_dotted_notation.length() == 0)
        {
            decimal_dotted_notation = decimal_dotted_notation + increment_in_string;
        }
        else
        {
            decimal_dotted_notation = decimal_dotted_notation + "." + increment_in_string;
        }
        increment = 0;
        dfa = 1;
    }

    else
    {
        dfa = -1;
    }
}

int isBitsAccepted(const string &input)
{
    for (char c : input)
    {
        if (dfa == 1)
        {
            q1(c);
        }
        else if (dfa == 2)
        {
            q2(c);
        }
        else if (dfa == 3)
        {
            q3(c);
        }
        else if (dfa == 4)
        {
            q4(c);
        }
        else if (dfa == 5)
        {
            q5(c);
        }
        else if (dfa == 6)
        {
            q6(c);
        }
        else if (dfa == 7)
        {
            q7(c);
        }
        else if (dfa == 8)
        {
            q8(c);
        }
    }
    if (dfa == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

int main()
{
    string binary_data = "10101100000100000000000000000001";

    string oneBit = binary_data.substr(0, 1);
    string twoBit = binary_data.substr(0, 2);
    string threeBit = binary_data.substr(0, 3);
    string fourBit = binary_data.substr(0, 4);
    string fiveBit = binary_data.substr(0, 5);
    if (isBitsAccepted(binary_data))
    {
        cout << "Binary : " << binary_data << endl;
        cout << "The binary_data are correct" << endl;
        cout << "Decimal Dotted Notation : " << decimal_dotted_notation << endl;
        if (oneBit == "0")
        {
            cout << "Address Class A" << endl;
            cout << "Default Subnet Mask: "
                 << "255.0.0.0" << endl;
        }
        else if (twoBit == "10")
        {
            cout << "Address Class B" << endl;
            cout << "Default Subnet Mask: "
                 << "255.255.0.0" << endl;
        }
        else if (threeBit == "110")
        {
            cout << "Address Class C" << endl;
            cout << "Default Subnet Mask: "
                 << "255.255.255.0" << endl;
        }
        else if (fourBit == "1110")
        {
            cout << "Address Class D" << endl;
            cout << "The class does not contain any default subnet mask" << endl;
        }
        else if (fiveBit == "11110")
        {
            cout << "Address Class E" << endl;
            cout << "The class does not contain any default subnet mask" << endl;
        }
        else
        {
            cout << "Belongs to no address class" << endl;
        }
    }
    else
    {
        cout << "The binary_data are incorrect";
    }

    return 0;
}