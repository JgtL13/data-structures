//A program that calculates weight of molecular that consists of elements C, H and O.

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    bool finish = false;
    while(!finish)
    {
        string input;
        int j = 0, k = 0, multiplier = 1, temp;
        int store[1001] = {};
        cin >> input;
        if(input[0] == '0' && input.length() == 1)
        {
            finish = true;
            break;
        }
        else
        {
            for(int i = 0; i < input.length(); ++i)
            {
                if(input[i] == '(')
                {
                    //add to store
                    store[j] = 0;
                    ++j;
                }
                else if(input[i] == ')')
                {
                    //find interval of () and add these together
                    //put sum into store replacing ( and start from here
                    k = j - 1;
                    while(store[k] != 0)
                    {
                        --k;
                    }
                    int tempTotal = 0;
                    for(int a = k ; a < j; ++a)
                    {
                        tempTotal += store[a];
                    }
                    if(isdigit(input[i + 1]))
                    {
                        ++i;
                        multiplier = input[i] - 48;
                        //check if has anymore digits
                        while(isdigit(input[i + 1]))
                        {
                            ++i;
                            multiplier = multiplier * 10 + input[i] - 48;
                        }
                        store[k] = tempTotal * multiplier;
                        j = k + 1;
                        multiplier = 1;
                    }
                    else
                    {
                        store[k] = tempTotal;
                        j = k + 1;
                    }
                }
                else if(input[i] == 'C' || input[i] == 'H' || input[i] == 'O')
                {
                    //add number to store
                    if(input[i] == 'C')
                    {
                        store[j] = 12;
                        ++j;
                    }
                    else if(input[i] == 'H')
                    {
                        store[j] = 1;
                        ++j;
                    }
                    else if(input[i] == 'O')
                    {
                        store[j] = 16;
                        ++j;
                    }
                }
                else if(isdigit(input[i]))
                {
                    multiplier = input[i] - 48;
                    //check if has anymore digits
                    while(isdigit(input[i + 1]))
                    {
                        ++i;
                        multiplier = multiplier * 10 + input[i] - 48;
                    }
                    //multiply the number before this digit and re-add to store
                    store[j - 1] *= multiplier;
                    multiplier = 1;
                }
            }
            int total = 0;
            for(int a = 0; a < j; ++a)
            {
                total += store[a];
            }
            cout << total << endl;
        }
    }
    return 0;
}
