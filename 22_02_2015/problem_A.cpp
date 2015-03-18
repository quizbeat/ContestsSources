//
//  main.cpp
//  contest
//
//  Created by Nikita Makarov on 21/07/14.
//  Copyright (c) 2014 quiz.corp. All rights reserved.
//

#include <iomanip>
#include <limits>
#include <iostream>
#include <algorithm>

typedef enum {
    BLACK,
    WHITE,
    GREEN,
    YELLOW,
    BLUE,
    RED,
    ORANGE,
    PURPLE
} color;

typedef enum {
    DOT,
    ARABIC,
    ROMAN,
} numberType;

typedef struct {
    color col;
    numberType num;
    int value;
} cubeFace;

color parseColor(char col) {
    if (col == 'B') return BLACK;
    else if (col == 'W') return WHITE;
    else if (col == 'G') return GREEN;
    else if (col == 'Y') return YELLOW;
    else if (col == 'S') return BLUE;
    else if (col == 'R') return RED;
    else if (col == 'O') return ORANGE;
    else return PURPLE;
}

int parseDots() {
    int value;
    string dots;
    in >> dots;
    value = (int)dots.size();
    return value;
}

int parseArabic() {
    int value;
    in >> value;
    return value;
}

int parseRoman() {
    string roman;
    in >> roman;
    if (roman == "I") return 1;
    else if (roman == "II") return 2;
    else if (roman == "III") return 3;
    else if (roman == "IV") return 4;
    else if (roman == "V") return 5;
    else return 6;
}

int parseValue(numberType num) {
    if (num == DOT) return parseDots();
    else if (num == ARABIC) return parseArabic();
    else return parseRoman();
}

numberType recognizeNumberType(char num) {
    if (num == '.') return DOT;
    else if (isdigit(num)) return ARABIC;
    else return ROMAN;
}

bool john(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.num == DOT && f1.num == f2.num && f2.num == f3.num)
        return true;
    return false;
}

bool david(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.num != ROMAN && f2.num != ROMAN && f3.num != ROMAN)
        return true;
    return false;
}

bool peter(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.col == WHITE && f1.col == f2.col && f2.col == f3.col)
        return true;
    return false;
}

bool robert(cubeFace f1, cubeFace f2, cubeFace f3) {
    if ((f1.col == BLACK || f1.col == WHITE) &&
        (f2.col == BLACK || f2.col == WHITE) &&
        (f3.col == BLACK || f3.col == WHITE))
        return true;
    return false;
}

bool mark(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.value % 2 == 0 && f1.col != BLACK) // чет
        return false;
    if (f1.value % 2 == 1 && f1.col != WHITE) // нечет
        return false;
    if (f2.value % 2 == 0 && f2.col != BLACK) // чет
        return false;
    if (f2.value % 2 == 1 && f2.col != WHITE) // нечет
        return false;
    if (f3.value % 2 == 0 && f3.col != BLACK) // чет
        return false;
    if (f3.value % 2 == 1 && f3.col != WHITE) // нечет
        return false;
    return true;
}

bool paul(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.value == 2 || f1.value == 3 || f1.value == 5) {
        if (f1.num != ARABIC)
            return false;
    }
    if (f2.value == 2 || f2.value == 3 || f2.value == 5) {
        if (f2.num != ARABIC)
            return false;
    }
    if (f3.value == 2 || f3.value == 3 || f3.value == 5) {
        if (f3.num != ARABIC)
            return false;
    }
    if (f1.num == ARABIC) {
        if (f1.value == 1 || f1.value == 4 || f1.value == 6) {
            return false;
        }
    }
    if (f2.num == ARABIC) {
        if (f2.value == 1 || f2.value == 4 || f2.value == 6) {
            return false;
        }
    }
    if (f3.num == ARABIC) {
        if (f3.value == 1 || f3.value == 4 || f3.value == 6) {
            return false;
        }
    }
    return true;
}

bool patrick(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.col == f2.col && f2.col == f3.col) {
        if (f1.col != BLACK && f1.col != WHITE)
            return true;
    }
    return false;
}

bool jack(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.num == ROMAN && f1.col != YELLOW)
        return false;
    if (f2.num == ROMAN && f2.col != YELLOW)
        return false;
    if (f3.num == ROMAN && f3.col != YELLOW)
        return false;
    return true;
}

bool maxx(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.col != f2.col && f1.col != f3.col && f2.col != f3.col)
        return true;
    return false;
}

bool alex(cubeFace f1, cubeFace f2, cubeFace f3) {
    if (f1.num == f2.num && f1.col != f2.col)
        return false;
    if (f1.num != f2.num && f1.col == f2.col)
        return false;

    if (f1.num == f3.num && f1.col != f3.col)
        return false;
    if (f1.num != f3.num && f1.col == f3.col)
        return false;

    if (f2.num == f3.num && f2.col != f3.col)
        return false;
    if (f2.num != f3.num && f2.col == f3.col)
        return false;

    return true;
}

int main() {

    char col, num;

    // FACE 1
    cubeFace face1;
    col = in.get();
    in.get();

    num = in.get();
    in.unget();

    face1.col = parseColor(col);
    face1.num = recognizeNumberType(num);
    face1.value = parseValue(face1.num);
    in.get();

    // FACE 2
    cubeFace face2;
    col = in.get();
    in.get();

    num = in.get();
    in.unget();

    face2.col = parseColor(col);
    face2.num = recognizeNumberType(num);
    face2.value = parseValue(face2.num);
    in.get();

    // FACE 3
    cubeFace face3;
    col = in.get();
    in.get();

    num = in.get();
    in.unget();

    face3.col = parseColor(col);
    face3.num = recognizeNumberType(num);
    face3.value = parseValue(face3.num);
    in.get();

    if (john(face1, face2, face3))
        out << "John ";
    if (david(face1, face2, face3))
        out << "David ";
    if (peter(face1, face2, face3))
        out << "Peter ";
    if (robert(face1, face2, face3))
        out << "Robert ";
    if (mark(face1, face2, face3))
        out << "Mark ";
    if (paul(face1, face2, face3))
        out << "Paul ";
    if (patrick(face1, face2, face3))
        out << "Patrick ";
    if (jack(face1, face2, face3))
        out << "Jack ";
    if (maxx(face1, face2, face3))
        out << "Max ";
    if (alex(face1, face2, face3))
        out << "Alex ";

    in.close();
    out.close();

    return 0;
}
