#include <iostream>
#include <fstream>
using namespace std;
const char space(32);
struct Anniversary {
    char name[31]; ///jubilara vards
    char surname[31]; ///jubilara uzvards
    char day[2]; ///dd
    char month[2]; //mm
     //yyyy     /////// year[0] = int(c) - 48;  T.date = year[0] * 10000000 + year[1] * 1000000 + year[2] * 100000 + year[3] * 10000 + day[0] * 1000 + day[1] * 100 + month[0] * 10 + month[1];
    short int dd;
    short int mm;
    short int yyyy;
};

struct Months {
    int Count = 0;
    Anniversary* next;
};

Months Mon[13];
Anniversary jan[10001];
Anniversary feb[10001];
Anniversary mar[10001];
Anniversary apr[10001];
Anniversary may[10001];
Anniversary june[10001];
Anniversary july[10001];
Anniversary aug[10001];
Anniversary sep[10001];
Anniversary octo[10001];
Anniversary nov[10001];
Anniversary dece[10001];

void fill_months() {
    Mon[1].next = jan;
    Mon[2].next = feb;
    Mon[3].next = mar;
    Mon[4].next = apr;
    Mon[5].next = may;
    Mon[6].next = june;
    Mon[7].next = july;
    Mon[8].next = aug;
    Mon[9].next = sep;
    Mon[10].next = octo;
    Mon[11].next = nov;
    Mon[12].next = dece;
}

int datetoint(char a, char T[]) {
    int p = 0;
    if (a == 'm' || a == 'd') { ///date dd
        p = (int)T[0] - 48;
        p *= 10;
        p += (int)T[1] - 48;
    }
    else if (a == 'y') {
        p += (int)T[0] - 48;
        p *= 1000;
        p += ((int)T[1] - 48)*100;
        p += ((int)T[2] - 48)*10;
        p += (int)T[3] - 48;
    }
    return p;
}

Anniversary read_person(ifstream& fin) {
    char c;
    int i = 0;
    char year[4];
    Anniversary T;
    fin >> c;
    while (fin.peek() != space) { ///lasam vardu
        T.name[i] = c;
        i++;
        fin >> c;
    }
    T.name[i] = c;
    T.name[i + 1] = '\0';
    i = 0;
    fin >> c;
    while (fin.peek() != space) { ///lasam uzvardu
        T.surname[i] = c;
        i++;
        fin >> c;
    }
    T.surname[i] = c;
    T.surname[i + 1] = '\0';
    i = 0;
    fin >> c;
    T.day[0] = c;
    fin >> c;
    T.day[1] = c;
    T.dd = datetoint('d', T.day);
    fin >> c;
    fin >> c;
    T.month[0] = c;
    fin >> c;
    T.month[1] = c;
    T.mm = datetoint('m', T.month);
    fin >> c;
    fin >> c;
    year[0] = c;
    fin >> c;
    year[1] = c;
    fin >> c;
    year[2] = c;
    fin >> c;
    year[3] = c;
    T.yyyy = datetoint('y', year);
    return T;
}

char compare_char(char a, char b) {
    int x, y;
    if (a >= 'A' && a <= 'Z') x = (int)a + 32;
    else x = (int)a;
    if (b >= 'A' && b <= 'Z') y = (int)b + 32;
    else y = (int)b;
    if (x > y) return '>';
    else if (x < y) return '<';
    else return '=';
}

char compare_strings(char a[], char b[]) { ///Japadod uzreiz char[]
    char answer = '=';
    int i = 1;
    char s1 = a[0], s2 = b[0], u;
    while (s1 != '\0' && s2 != '\0') {
        u = compare_char(s1,s2);
        if (u == '>') { ///Salidzina charus
            answer = '>';
            break;
        }
        else if (u == '<') {
            answer = '<';
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

char compare_me(Anniversary a, Anniversary b, char aim) {
    char t;
    if (aim == 'D') {
        if (a.dd < b.dd) ///menesi sakrit
            return '<';
        else if (a.dd > b.dd)
            return '>';
        else if (a.yyyy < b.yyyy)
            return '<';
        else if (a.yyyy > b.yyyy)
            return '>';
        else return '=';
    }
    else if (a.dd < b.dd) ///menesi sakrit
        return '<';
    else if (a.dd > b.dd)
        return '>';
    else if (a.yyyy < b.yyyy)
        return '<';
    else if (a.yyyy > b.yyyy)
        return '>';
    else { ///salidzinam uzvardus
        t = compare_strings(a.surname, b.surname);
        if (t == '<')
            return '<';
        else if (t == '>')
            return '>';
        else { ///salidzinam vardus
            t = compare_strings(a.name, b.name);
            if (t == '<')
                return '<';
            else if (t == '>')
                return '>';
            else return '=';
        }
    }
}

int find_person(Anniversary T, int Max, Anniversary* Month, bool& Find, char aim) { ///Binara meklesana
    int l = 0, r = Max, m =0;
    char s;
    Anniversary Middle;
    while (true) {
        if (r < l) {
            Find = false;
            return l-1; ///Tada ieraksta nav!
        }
        else {
            m = (l + r) / 2;
            Middle = Month[m]; /// Laiks = log(n)
            s = compare_me(T, Middle,aim);
            if (s == '=') {
                Find = true;
                return m;
            }
            else {
                if (s == '<') {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
    }
}

bool check_dublicates(int m, Anniversary T, int& pos, char aim) {
    bool answer = false;
    pos = find_person(T, Mon[m].Count, Mon[m].next, answer,aim);
    return answer;
}

void insert_me(int m, Anniversary T) {
    Mon[m].Count++;
    int Max = Mon[m].Count;
    Anniversary tmp;
    Mon[m].next[Max] = T; ///ievieto jaunu cilveku masiiva beigaas
    while (Max>1 && compare_me(Mon[m].next[Max-1], Mon[m].next[Max],'i') == '>') {
        tmp = Mon[m].next[Max-1];
        Mon[m].next[Max-1] = Mon[m].next[Max];
        Mon[m].next[Max] = tmp;
        Max--;
    }
}

void find_me(ifstream& fin, ofstream& fout) {
    Anniversary T,Q;
    char c,y[4];
    bool Find = false, Y=false; ///Y- mainas gads
    int pos, mn, age, year;
    fin >> T.day[0];
    fin >> T.day[1];
    T.dd = datetoint('d', T.day);
    fin >> c;
    fin >> T.month[0];
    fin >> T.month[1];
    T.mm = datetoint('m', T.month);
    fin >> c;
    mn = datetoint('m', T.month);
    fin >> y[0];
    fin >> y[1];
    fin >> y[2];
    fin >> y[3];
    year = datetoint('y', y);
    T.yyyy = 1899;

    pos = find_person(T, Mon[mn].Count, Mon[mn].next, Find, 'D');
    if (!Find) pos++;
    if (pos > Mon[mn].Count) { ///ja saja menesi nav dzimsanas dienu
        do { ///kamer neatradisim menesi ar jubilaru
            if (mn == 12) {
                mn = 1;
                Y = true;
                continue;
            }
            else mn++;
        } while (Mon[mn].Count == 0);
        pos = 1;
    }
    Q = Mon[mn].next[pos];
    fout << Q.day[0] << Q.day[1] << '.' << Q.month[0] << Q.month[1] << '.';
    if (Y) fout << ++year << '\n'; ///kuram datumam meklejam jubilarus
    else fout << year << '\n';
    while (pos<=Mon[mn].Count && Q.dd == Mon[mn].next[pos].dd){

        age = year - Mon[mn].next[pos].yyyy;
        fout << age << ' ' << Mon[mn].next[pos].name << ' ' << Mon[mn].next[pos].surname << '\n'; ///jubilars
        pos++;
    }

}

int main() {
    ifstream fin;
    ofstream fout;
    char c;
    bool first = true, dublicate = false;
    int m,pos;
    Anniversary T;

    fin.open("anniversary.in", ios::in);
    fout.open("anniversary.out", ios::out);
    fill_months();



    fin >> c;
    while (!fin.eof()) {
        if (c == 'P') { ///lasam tikko atnakuso cilveku!
            T = read_person(fin);
            m = T.mm; ///sanemt menesi
            if (first) { ///pirmais cilveks gramataa
                Mon[m].next[1] = T;
                Mon[m].Count = 1;
                first = false;
            }
            else {
                dublicate = check_dublicates(m,T,pos,'i');
                if (!dublicate) { ///ja ir unikals
                    insert_me(m, T);
                }
            }
        }
        else if (c == 'D') {
            find_me(fin,fout);

        }
        fin >> c;
    }





    fin.close();
    fout.close();
    return 0;
}

