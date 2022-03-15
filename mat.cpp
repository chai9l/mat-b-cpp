#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "mat.hpp"

using namespace std;

const int char_low_limit = 33;
const int char_high_limit = 126;

string ariel::mat(int coll, int row, char pattern, char pattern2)
{

    if (row % 2 == 0 or coll % 2 == 0)
    {
        throw invalid_argument("Row or Coll cannot be even");
    }
    if (row < 0 or coll < 0)
    {
        throw invalid_argument("Row or Coll cannot be negative");
    }
    if (pattern < char_low_limit or pattern > char_high_limit or pattern2 < char_low_limit or pattern2 > char_high_limit)
    {
        throw invalid_argument("Patterns must be between 33 to 126");
    }
    int i = 0;
    int r = 0;
    int c = 0;
    int num_rows = row;
    int num_colls = coll;

    vector<vector<char>> mat_base;

    for (int h = 0; h < row; h++)
    {
        vector<char> tmp;
        tmp.resize(coll);
        mat_base.push_back(tmp);
    }

    char x = pattern;
    string ret;

    while (r < row && c < coll)
    {

        for (i = c; i < coll; ++i)
        {
            mat_base.at(r).at(i) = x;
        }
        r++;

        for (i = r; i < row; ++i)
        {
            mat_base[i][coll - 1] = x;
            mat_base.at(i).at(coll - 1) = x;
        }
        coll--;

        if (r < row)
        {
            for (i = coll - 1; i >= c; --i)
            {
                mat_base[row - 1][i] = x;
            }
            row--;
        }

        if (c < coll)
        {
            for (i = row - 1; i >= r; --i)
            {
                mat_base[i][c] = x;
            }
            c++;
        }

        if (x == pattern)
        {
            x = pattern2;
        }
        else
        {
            x = pattern;
        }
    }
    for (i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_colls; j++)
        {
            ret += mat_base[i][j];
        }
        ret += '\n';
    }
    return ret;
}
