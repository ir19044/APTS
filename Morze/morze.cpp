#include <iostream>
#include <fstream>
using namespace std;
struct Morze {
    char mas[7]; ///Max varda garums==6 beigu 0
    char burts;
};
Morze M[43];

void fill_Dictionary() { ///Vardnica morzei
    M[0].mas[0] = '.'; M[0].mas[1] = '\0'; M[0].burts = 'E';
    M[1].mas[0] = '.'; M[1].mas[1] = '.'; M[1].mas[2] = '\0'; M[1].burts = 'I';
    M[2].mas[0] = '.'; M[2].mas[1] = '.'; M[2].mas[2] = '.'; M[2].mas[3] = '\0'; M[2].burts = 'S';
    M[3].mas[0] = '.'; M[3].mas[1] = '.'; M[3].mas[2] = '.'; M[3].mas[3] = '.'; M[3].mas[4] = '\0'; M[3].burts = 'H';
    M[4].mas[0] = '.'; M[4].mas[1] = '.'; M[4].mas[2] = '.'; M[4].mas[3] = '.'; M[4].mas[4] = '.'; M[4].mas[5] = '\0'; M[4].burts = '5';
    M[5].mas[0] = '.'; M[5].mas[1] = '.'; M[5].mas[2] = '.'; M[5].mas[3] = '.'; M[5].mas[4] = '-'; M[5].mas[5] = '\0'; M[5].burts = '4';
    M[6].mas[0] = '.'; M[6].mas[1] = '.'; M[6].mas[2] = '.'; M[6].mas[3] = '-'; M[6].mas[4] = '\0'; M[6].burts = 'V';
    M[7].mas[0] = '.'; M[7].mas[1] = '.'; M[7].mas[2] = '.'; M[7].mas[3] = '-'; M[7].mas[4] = '-'; M[7].mas[5] = '\0'; M[7].burts = '3';
    M[8].mas[0] = '.'; M[8].mas[1] = '.'; M[8].mas[2] = '-'; M[8].mas[3] = '\0'; M[8].burts = 'U';
    M[9].mas[0] = '.'; M[9].mas[1] = '.'; M[9].mas[2] = '-'; M[9].mas[3] = '.'; M[9].mas[4] = '\0'; M[9].burts = 'F';
    M[10].mas[0] = '.'; M[10].mas[1] = '.'; M[10].mas[2] = '-'; M[10].mas[3] = '-'; M[10].mas[4] = '.'; M[10].mas[5] = '.'; M[10].mas[6] = '\0'; M[10].burts = '?';
    M[11].mas[0] = '.'; M[11].mas[1] = '.'; M[11].mas[2] = '-'; M[11].mas[3] = '-'; M[11].mas[4] = '-'; M[11].mas[5] = '\0'; M[11].burts = '2';
    M[12].mas[0] = '.'; M[12].mas[1] = '-'; M[12].mas[2] = '\0'; M[12].burts = 'A';
    M[13].mas[0] = '.'; M[13].mas[1] = '-'; M[13].mas[2] = '.'; M[13].mas[3] = '\0'; M[13].burts = 'R';
    M[14].mas[0] = '.'; M[14].mas[1] = '-'; M[14].mas[2] = '.'; M[14].mas[3] = '.'; M[14].mas[4] = '\0'; M[14].burts = 'L';
    M[15].mas[0] = '.'; M[15].mas[1] = '-'; M[15].mas[2] = '.'; M[15].mas[3] = '-'; M[15].mas[4] = '.'; M[15].mas[5] = '-'; M[15].mas[6] = '\0'; M[15].burts = '.';
    M[16].mas[0] = '.'; M[16].mas[1] = '-'; M[16].mas[2] = '-'; M[16].mas[3] = '\0'; M[16].burts = 'W';
    M[17].mas[0] = '.'; M[17].mas[1] = '-'; M[17].mas[2] = '-'; M[17].mas[3] = '.'; M[17].mas[4] = '\0'; M[17].burts = 'P';
    M[18].mas[0] = '.'; M[18].mas[1] = '-'; M[18].mas[2] = '-'; M[18].mas[3] = '-'; M[18].mas[4] = '\0'; M[18].burts = 'J';
    M[19].mas[0] = '.'; M[19].mas[1] = '-'; M[19].mas[2] = '-'; M[19].mas[3] = '-'; M[19].mas[4] = '-'; M[19].mas[5] = '\0'; M[19].burts = '1';
    M[20].mas[0] = '.'; M[20].mas[1] = '-'; M[20].mas[2] = '-'; M[20].mas[3] = '-'; M[20].mas[4] = '-'; M[20].mas[5] = '.'; M[20].mas[6] = '\0'; M[20].burts = '+'; ///tuksums
    M[21].mas[0] = '-'; M[21].mas[1] = '\0'; M[21].burts = 'T';
    M[22].mas[0] = '-'; M[22].mas[1] = '.'; M[22].mas[2] = '\0'; M[22].burts = 'N';
    M[23].mas[0] = '-'; M[23].mas[1] = '.'; M[23].mas[2] = '.'; M[23].mas[3] = '\0'; M[23].burts = 'D';
    M[24].mas[0] = '-'; M[24].mas[1] = '.'; M[24].mas[2] = '.'; M[24].mas[3] = '.'; M[24].mas[4] = '\0'; M[24].burts = 'B';
    M[25].mas[0] = '-'; M[25].mas[1] = '.'; M[25].mas[2] = '.'; M[25].mas[3] = '.'; M[25].mas[4] = '.'; M[25].mas[5] = '\0'; M[25].burts = '6';
    M[26].mas[0] = '-'; M[26].mas[1] = '.'; M[26].mas[2] = '.'; M[26].mas[3] = '.'; M[26].mas[4] = '.'; M[26].mas[5] = '-'; M[26].mas[6] = '\0'; M[26].burts = '-';
    M[27].mas[0] = '-'; M[27].mas[1] = '.'; M[27].mas[2] = '.'; M[27].mas[3] = '-'; M[27].mas[4] = '\0'; M[27].burts = 'X';
    M[28].mas[0] = '-'; M[28].mas[1] = '.'; M[28].mas[2] = '.'; M[28].mas[3] = '-'; M[28].mas[4] = '.'; M[28].mas[5] = '\0'; M[28].burts = '/';
    M[29].mas[0] = '-'; M[29].mas[1] = '.'; M[29].mas[2] = '-'; M[29].mas[3] = '\0'; M[29].burts = 'K';
    M[30].mas[0] = '-'; M[30].mas[1] = '.'; M[30].mas[2] = '-'; M[30].mas[3] = '.'; M[30].mas[4] = '\0'; M[30].burts = 'C';
    M[31].mas[0] = '-'; M[31].mas[1] = '.'; M[31].mas[2] = '-'; M[31].mas[3] = '-'; M[31].mas[4] = '\0'; M[31].burts = 'Y';
    M[32].mas[0] = '-'; M[32].mas[1] = '-'; M[32].mas[2] = '\0'; M[32].burts = 'M';
    M[33].mas[0] = '-'; M[33].mas[1] = '-'; M[33].mas[2] = '.'; M[33].mas[3] = '\0'; M[33].burts = 'G';
    M[34].mas[0] = '-'; M[34].mas[1] = '-'; M[34].mas[2] = '.'; M[34].mas[3] = '.'; M[34].mas[4] = '\0'; M[34].burts = 'Z';
    M[35].mas[0] = '-'; M[35].mas[1] = '-'; M[35].mas[2] = '.'; M[35].mas[3] = '.'; M[35].mas[4] = '.'; M[35].mas[5] = '\0'; M[35].burts = '7';
    M[36].mas[0] = '-'; M[36].mas[1] = '-'; M[36].mas[2] = '.'; M[36].mas[3] = '.'; M[36].mas[4] = '-'; M[36].mas[5] = '-'; M[36].mas[6] = '\0'; M[36].burts = ',';
    M[37].mas[0] = '-'; M[37].mas[1] = '-'; M[37].mas[2] = '.'; M[37].mas[3] = '-'; M[37].mas[4] = '\0'; M[37].burts = 'Q';
    M[38].mas[0] = '-'; M[38].mas[1] = '-'; M[38].mas[2] = '-'; M[38].mas[3] = '\0'; M[38].burts = 'O';
    M[39].mas[0] = '-'; M[39].mas[1] = '-'; M[39].mas[2] = '-'; M[39].mas[3] = '.'; M[39].mas[4] = '.'; M[39].mas[5] = '\0'; M[39].burts = '8';
    M[40].mas[0] = '-'; M[40].mas[1] = '-'; M[40].mas[2] = '-'; M[40].mas[3] = '.'; M[40].mas[4] = '.'; M[40].mas[5] = '.'; M[40].mas[6] = '\0'; M[40].burts = ':';
    M[41].mas[0] = '-'; M[41].mas[1] = '-'; M[41].mas[2] = '-'; M[41].mas[3] = '-'; M[41].mas[4] = '.'; M[41].mas[5] = '\0'; M[41].burts = '9';
    M[42].mas[0] = '-'; M[42].mas[1] = '-'; M[42].mas[2] = '-'; M[42].mas[3] = '-'; M[42].mas[4] = '-'; M[42].mas[5] = '\0'; M[42].burts = '0';
}

bool equal_words(char a[], char b[]) {
    bool flag = false;
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] == b[i] && a[i + 1] == b[i + 1]) {
            flag = true;
        }
        else {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}

char compare_me(char a[], char b[]) { ///Japadod uzreiz char[]
    char answer = '=';
    int i = 1;
    char s1 = a[0], s2 = b[0];
    while (s1 != '\0' && s2 != '\0') {
        if (s1 > s2) { ///Salidzina punktu ar svitrinu
            answer = '<';
            break;
        }
        else if (s1 < s2) {
            answer = '>';
            break;
        }
        s1 = a[i];
        s2 = b[i];
        i++;
    }
    if (s1 == '\0' && s2 != '\0') answer = '<';
    else if (s1 != '\0' && s2 == '\0') answer = '>';
    return answer;
}

char find_letter(char simbols[]) { ///Binara meklesana
    int left = 0, right = 42, Middle;
    while (true) {
        if (right < left) {
            return 'f'; ///Tada ieraksta nav!
        }
        else {
            Middle = (left + right) / 2; /// Laiks = log(n)
            if (equal_words(simbols, M[Middle].mas)) {
                return M[Middle].burts;
            }
            else {
                if (compare_me(simbols, M[Middle].mas) == '<') {
                    right = Middle - 1;
                }
                else {
                    left = Middle + 1;
                }
            }
        }
    }
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("morse.in", ios::in);
    fout.open("morse.out", ios::out);
    fill_Dictionary();
    char c, simbols[8], atbilde, pos;
    bool flag = false, is =false;
    int left = 0, right = 42, i = 0; ///Vardnicas sakums un beigas (0;42)!
    fin >> c;
    while (!fin.eof()) {
        i = 0;
        while (c != '|' && !fin.eof()) { ///Lasam burtu!
            if(i==6){ ///Svess simbols, jo garums >6
                flag = true;
                break;
            }
            simbols[i] = c;
            i++; ///Seit ari vajag parbaudi!
            fin >> c;
            is = true; ///starp pauzem ir vismaz viens simbols
        }
        if(is){
            if(!flag && c=='|'){
                simbols[i] = '\0';
                pos = find_letter(simbols);
                if (pos != 'f') { ///Ja tads simbols ir vardnicaa
                    if (pos == '+') fout << ' '; ///tuksums
                    else fout << pos;
                }
                else {
                    fout << '!';
                }
            }
            else{
                fout << '!';
                while(c!='|' && !fin.eof()){ ///Ignore liekus simbolus, ja ir svess
                    fin >> c;
                }
            }
        }
        flag = false;
        is = false;
        fin >> c;
    }
    fin.close();
    fout.close();
}
