
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "mat.hpp"

int main(int argc, char const *argv[])
{
    int row;
    int coll;
    char pattern;
    char pattern2;
    bool flag = true;
    
    while (flag)
        {   
            char yorn = 0;
            cout << "Please enter the number of rows" << endl;
            cin >> row;
            cout << "Please enter the number of colls" << endl;
            cin >> coll;
            cout << "Please enter the first pattern" << endl;
            cin >> pattern;
            cout << "Please enter the second pattern" << endl;
            cin >> pattern2;
            try {
                cout << ariel::mat(coll, row, pattern, pattern2) << endl;
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;
	        }


            while(yorn != 'Y' and yorn != 'N') {
                cout << "Would you like to create another mat? enter Y/N" << endl;
                cin >> yorn;
            }
            if (yorn == 'N') {
                flag = false;
            }
            
        }

    return 0;
}
