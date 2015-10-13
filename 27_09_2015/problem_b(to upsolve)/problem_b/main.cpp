//
//  main.cpp
//  problem_b
//
//  Created by Nikita Makarov on 27/09/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define ULL unsigned long long

#define UP '^'
#define DOWN 'v'
#define RIGHT '>'
#define LEFT '<'

using namespace std;

typedef struct {
    ULL x;
    ULL y;
    char dir;
    bool alive;
    int def_num;
} Atom;

bool cmp_atoms_x(Atom *a, Atom *b) {
    if (a->x == b->x) {
        return a->y < b->y;
    } else {
        return a->x < b->x;
    }
}

bool cmp_atoms_y(Atom *a, Atom *b) {
    if (a->y == b->y) {
        return a->x < b->x;
    } else {
        return a->y < b->y;
    }
}

vector<Atom *> atoms_x(3000);
vector<Atom *> atoms_y(3000);

int n;

int bsearch_x(Atom *atom)
{
    int left = 0;
    int right = n - 1;
    while (true) {
        int mid = left + (right - left) / 2;
        if (atoms_x[mid] == atom) {
            return mid;
        }
        if (atoms_x[mid]->x == atom->x) {
            if (atoms_x[mid]->y > atom->y) {
                right = mid;
            } else {
                left = mid + 1;
            }
            right = mid;
        } else if (atoms_x[mid]->x > atom->x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
}

int bsearch_y(Atom *atom)
{
    int left = 0;
    int right = n - 1;
    while (true) {
        int mid = left + (right - left) / 2;
        if (atoms_y[mid] == atom) {
            return mid;
        }
        if (atoms_y[mid]->y == atom->y) {
            if (atoms_y[mid]->x > atom->x) {
                right = mid;
            } else {
                left = mid + 1;
            }
            right = mid;
        } else if (atoms_y[mid]->y > atom->y) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
}

int move_to_next_from(Atom *atom)
{
    char dir = atom->dir;
    bool found = false;
    
    Atom *next_atom = new Atom;
    
    if (dir == DOWN) {
        int pos = bsearch_x(atom);
        pos++;
        for (int i = pos; i < n; i++) {
            if (atoms_x[i]->x == atom->x) {
                if (atoms_x[i]->alive) {
                    next_atom = atoms_x[i];
                    found = true;
                    break;
                }
            } else {
                break;
            }
        }
    } else if (dir == UP) {
        int pos = bsearch_x(atom);
        if (pos != 0) {
            pos--;
            for (int i = pos; i >= 0; i--) {
                if (atoms_x[i]->x == atom->x) {
                    if (atoms_x[i]->alive) {
                        next_atom = atoms_x[i];
                        found = true;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
    } else if (dir == RIGHT) {
        int pos = bsearch_y(atom);
        pos++;
        for (int i = pos; i < n; i++) {
            if (atoms_y[i]->y == atom->y) {
                if (atoms_y[i]->alive) {
                    next_atom = atoms_y[i];
                    found = true;
                    break;
                }
            } else {
                break;
            }
        }
    } else {
        int pos = bsearch_y(atom);
        if (pos != 0) {
            pos--;
            for (int i = pos; i >= 0; i--) {
                if (atoms_y[i]->y == atom->y) {
                    if (atoms_y[i]->alive) {
                        next_atom = atoms_y[i];
                        found = true;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
    }
    
    if (found) {
        next_atom->alive = false;
        return 1 + move_to_next_from(next_atom);
    } else {
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        Atom *atom = new Atom;
        cin >> atom->x >> atom->y >> atom->dir;
        atom->alive = true;
        atom->def_num = i;
        atoms_x[i] = atom;
        atoms_y[i] = atom;
    }
    
    atoms_x.erase(atoms_x.begin() + n, atoms_x.end());
    atoms_y.erase(atoms_y.begin() + n, atoms_y.end());
    
    sort(atoms_x.begin(), atoms_x.end(), cmp_atoms_x);
    sort(atoms_y.begin(), atoms_y.end(), cmp_atoms_y);
    
    int max_res = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        atoms_x[i]->alive = false;
        
        int res = move_to_next_from(atoms_x[i]);
        
        if (res > max_res) {
            max_res = res;
        }
        
        for (int j = 0; j < n; j++) {
            atoms_x[j]->alive = true;
        }
    }
    
    cout << max_res << endl;
    
    return 0;
}
