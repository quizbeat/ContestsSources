//
//  main.c
//  diagram
//
//  Created by Nikita Makarov on 13/09/15.
//  Copyright (c) 2015 Nikita Makarov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ULL unsigned long long

int main() {
    
    ULL *array = (ULL *)malloc(15500000 * sizeof(ULL));
    
    ULL p;
    for (p = 0; p < 15000000; p++) {
        array[p] = 0;
    }
    
    ULL N, K;
    
    scanf("%lld %lld", &N, &K);
    
    ULL i;
    int r = 64;
    for (i = 0; i < N; i++) {
        ULL dist;
        scanf("%lld", &dist);
        array[dist/r] |= (1LL << (dist % r));
    }
    
    ULL max_length;
    scanf("%lld", &max_length);
    const ULL part_size = max_length / K;
    
    for (i = 0; i < part_size; i++) {
        ULL index = i / r;
        int shift = i % r;
        
        bool found = true;
        
        if (array[index] & (1LL << shift)) {
            ULL j;
            for (j = i + part_size; j < max_length; j += part_size) {
                ULL j_index = j / r;
                int j_shift = j % r;
                if (!(array[j_index] & (1LL << j_shift))) {
                    found = false;
                    break;
                }
            }
            if (found) {
                printf("1\n");
                return 0;
            }
        }
    }
    
    printf("0\n");
    
    return 0;
}
