#include <iostream>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <fstream>
#include <set>
using namespace std;

string gen_random_name(const int len, int y) {

    string tmp_s;
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand((unsigned)time(NULL) * getpid() * y);

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


    return tmp_s;
}

string gen_random_number(const int len, int y) {

    string tmp_s;
    static const char alphanum[] =
        "0123456789";

    srand((unsigned)time(NULL) * getpid() * y);

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


    return tmp_s;
}

int main() {
    ofstream fout;
    int num;
	fout.open("anniversary.in", ios::out);
	set<string>Sets;
	set<string>Sets2;
	int flag = 2;
	string name_d, surname_d, t1,t2;
	int dd,mm,yyyy;
	for (int i = 0; i < 10000; i++) {
            t1 = gen_random_name(15,i+1);
            t2 = gen_random_name(15,i+200);


                //if(i==9990) {name_d = t1; surname_d=t2;}
                fout << "P "<<t1<<" "<<t2<<' ';

                num =  (rand() % 30) + 1 ;

                if(num<10) fout<<"0";
                if(i==9990) dd = num;
                fout << num << ".";

                num =  (rand() % 12) + 1 ;
                 if(i==9990) mm = num;
                if(num<10) fout<<"0";
                fout << num << ".";

                num = (rand() % 200) + 1900;
                 if(i==9990) yyyy= num;
                fout << num << '\n';

	}
	/*for(int i=0; i<1000000; i++){ ///dublicates
        fout<<"P "<<t1<<" "<<t2<<" ";
        if(dd<10) fout<<"0";
        fout<<dd<<".";
        if(mm<10) fout<<"0";
        fout <<mm<<"."<<yyyy<<"\n";
	}
*/
/*

	for(int i=0; i<100; i++){
         fout <<"D ";
         num =  (rand() % 30) + 1 ;
        if(num<10) fout<<"0";
        fout << num << ".";

        num =  (rand() % 12) + 1 ;
        if(num<10) fout<<"0";
        fout << num << ".";

        fout <<  2100 << '\n';
	}

*/
}
