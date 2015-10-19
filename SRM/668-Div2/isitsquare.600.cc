#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Square 
{
    private:
        int euclidSq(int x1, int y1, int x2, int y2)
        {
            int dx = x2 - x1;
            int dy = y2 - y1;
            return dx*dx + dy*dy;
        }
    public:
        string isSquare(vector<int> x, vector<int> y) {
            int c[4] = {0, 1, 2, 3};

            int dAB = 0, dBC = 0, dCD = 0, dAD = 0;
            int dAC = 0, dBD = 0;
            int i = 1;
            do {
                cout << i << ":\t" << c[0] << "\t" << c[1] << "\t" << c[2] << "\t" << c[3] << endl;
                ++i;
                dAB = euclidSq(x[c[0]], y[c[0]], x[c[1]], y[c[1]]);
                dBC = euclidSq(x[c[1]], y[c[1]], x[c[2]], y[c[2]]);
                dCD = euclidSq(x[c[2]], y[c[2]], x[c[3]], y[c[3]]);
                dAD = euclidSq(x[c[0]], y[c[0]], x[c[3]], y[c[3]]);
                cout << dAB << "\t" << dBC << "\t" << dCD << "\t" << dAD << endl;
                if (dAB == dBC && dBC == dCD && dCD == dAD) {
                    cout << "Looks like a square. ";
                    dAC = euclidSq(x[c[0]], y[c[0]], x[c[2]], y[c[2]]);
                    dBD = euclidSq(x[c[1]], y[c[1]], x[c[3]], y[c[3]]);
                    if (dAC == dBD) {
                        cout << "It's a square.\n";
                        return "It's a square.";
                    }
                }

            }
            while (next_permutation(c, c+4));
            return "It's not a square.";
        }
        
};

void test1()
{
    vector<int> x;
    x.push_back(0);
    x.push_back(0);
    x.push_back(5);
    x.push_back(5);

    vector<int> y;
    y.push_back(0);
    y.push_back(5);
    y.push_back(0);
    y.push_back(5);

    Square s;
    cout << "Finally: " << s.isSquare(x, y);

}

void test2()
{
    vector<int> x;
    x.push_back(6);
    x.push_back(11);
    x.push_back(6);
    x.push_back(1);

    vector<int> y;
    y.push_back(0);
    y.push_back(7);
    y.push_back(14);
    y.push_back(7);

    Square s;
    cout << "Finally: " << s.isSquare(x, y);

}

int main()
{
    test1();
    test2();
    return 0;
}
