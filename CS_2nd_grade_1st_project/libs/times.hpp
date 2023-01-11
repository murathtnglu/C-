#ifndef _TIMES_
#define _TIMES_

#include <string>
#include <queue>

#include "time_section.hpp"

using namespace std;

//Bu kısım Fatma Azra Gürdal tarafından kodlanmıştır.
class TIMES 
{
private:
    queue<TIME_SECTION> _time_sections; // time section degerlerinin tutuldugu queue.
    string _task_name; // komut adi.

public:
    TIMES( fstream& input_file, string task_name, double start_time, double end_time );

    // TIME_SECTION queue'sunu dosyaya yazdirma.
    void write_to_file( fstream& output_file ); 

    // hata, uyari yardimcilari.
    string get_time_section_empty_warning();
    string get_file_not_open_exception( string file_type );
    void out_writing_to_file_message( ostream &out, const string end );
};

#endif