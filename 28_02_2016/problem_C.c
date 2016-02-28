//
//  main.c
//  c
//
//  Created by Nikita Makarov on 28/02/16.
//  Copyright © 2016 Nikita Makarov. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main()
{
    long x;
    scanf("%ld", &x);
    
    long count = 0;
    
    long d;
    for (d = 1; d < x; d++) {
        if (x % d == 0) {
            count++;
        }
    }
    
    long b1, q, n;
    for (b1 = 1; b1 <= (x/3 + 1); b1++)
    {
        long q_max = ceil((double)x / b1) - 1;
        
        for (q = 2; q <= q_max; q++)
        {
            for (n = 2; n <= 100000; n++)
            {
                long s = (b1 * ((long)pow((double)q, (double)n) - 1)) / (q - 1);
                if (s == x) {
                    count++;
                } else if (s > x) {
                    break;
                }
            }
        }
    }
    
    printf("%ld\n", count);
    
    return 0;
}