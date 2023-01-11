#ifndef _TIME_SECTIONS_
#define _TIME_SECTIONS_

#include <fstream>
#include <string>
// Bu kısım Ali Efe Karagül tarafından kodlanmıştır.

using namespace std;

class TIME_SECTION 
{
public:
    double time_stamp; //zaman icin degisken
    string left_channel, right_channel; //sag ve sol kanallarin genlik degerleri

    TIME_SECTION( const string& line, const char& delimeter );
    
    // time section'i dosyaya yazdirmak icin left bit shift operatoru overload edildi
    friend ostream& operator<<( ostream& out, const TIME_SECTION& ts )
    {
        out << ts.time_stamp    << '\t';
        out << ts.left_channel  << '\t';
        out << ts.right_channel << endl;

        return out;
    }
};

#endif