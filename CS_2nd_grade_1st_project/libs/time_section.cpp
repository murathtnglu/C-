#include <string>

#include "time_section.hpp"
//Bu kısım Ali Efe Karagül tarafından kodlanmıştır


//verilen satir degerinden time section construction.
TIME_SECTION::TIME_SECTION( const string& line, const char& delimeter )
{
    string parts[3];

    //satir degerindeki karakterler okunarak ayrim yapildi.
    int count = 0;
    for ( const char &c : line )
    {
        if ( c == delimeter ) count++;
        else                  parts[count] += c;
    }

    //ayrilan degerler degiskenlere atandi.
    time_stamp    = stod( parts[0] );
    left_channel  =       parts[1];
    right_channel =       parts[2];
}

