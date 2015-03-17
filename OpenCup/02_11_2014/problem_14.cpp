//
//  main.cpp
//  trash
//
//  Created by Anton Yakimenko on 02.11.14.
//  Copyright (c) 2014 Anton Yakimenko. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define eps 0.0001
struct player
{
    char name[256];
    LL x, y, r;
};
int main(int argc, const char * argv[]) {
    ifstream in("input.txt");
    ofstream out("output.txt");
    ULL T;
    in >> T;
    double pi81 = M_PI/81, pi2 = M_PI*2;
    for(ULL TT = 0; TT<T; ++TT)
    {
        ULL n;
        in >> n;
        vector<player> pl(n);
        for(int i=0; i<n; ++i)
        {
            in >> pl[i].name >> pl[i].x >> pl[i].y >> pl[i].r;
        }
        ULL maxInd = -1, max = 0, forTie = -1;
        for(int i=0; i<n; ++i)
        {
            ULL count = 0;
            LL rr = pl[i].r*pl[i].r;
            for(int j=0; j<n; ++j)
            {
                for(double pi = 0; pi<=pi2; pi += pi81)
                {
                    double x = (pl[j].r-eps)*cos(pi);
                    double y = (pl[j].r-eps)*sin(pi);
                    if((pl[j].x-pl[i].x+x)*(pl[j].x-pl[i].x+x)+(pl[j].y-pl[i].y+y)*(pl[j].y-pl[i].y+y)<=rr)
                    {
                        ++count;
                        break;
                    }
                }
            }
            if(count > max)
            {
                max = count;
                maxInd = i;
                forTie = -1;
            }
            else if(count == max)
            {
                max = count;
                forTie = maxInd;
                maxInd = i;
            }
        }
        if(maxInd == -1 || forTie != -1)
            out << "TIE" << '\n';
        else
            out << pl[maxInd].name << '\n';
    }
    out.close();
    in.close();
    return 0;
}
