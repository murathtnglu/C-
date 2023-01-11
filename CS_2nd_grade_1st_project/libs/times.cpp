#include <fstream>
#include <iostream>
#include <string>
#include <queue>

#include "times.hpp"

using namespace std;
//Bu kısım Murat Hatunoğlu tarafından kodlanmıştır.
// input olarak verilen dosyadan start-end zaman araligini okuma. 
TIMES::TIMES( fstream& input_file, string task_name, double start_time, double end_time ) 
{
    _task_name = task_name;

    // input dosyasinin acilip acilamadiginin kontrolu.
    if ( !input_file.is_open() )
    {
        throw( get_file_not_open_exception( "Input" ) );
        return;
    }

    string line;

    //dosyadan satir okuma.
    while ( getline(input_file, line) )
    {
        //verilen satirdan TIME_SECTION initialize etme.
        TIME_SECTION curr( line, '\t' );

        // eger okunan satir istenen aralikta ise TIME_SECTION queue'suna eklenir.
        if ( (start_time <= curr.time_stamp) && (curr.time_stamp <= end_time) )
        {
            _time_sections.push( curr );
        }
        else if ( curr.time_stamp >= end_time )
        {
            break;
        }
    }
}

//TIME_SECTION queue'sunu dosyaya yazdirma.
void TIMES::write_to_file( fstream& output_file )
{
    //cikti dosyasinin acilip acilmadiginin kontrolu.
    if ( !output_file.is_open() ) 
    {
        throw( get_file_not_open_exception( "Output" ) );
        return;
    }

    out_writing_to_file_message( cerr, "\n" );

    // TIME_SECTION queue'su bossa hata verir.
    if ( _time_sections.empty() ) 
    {
        throw( get_time_section_empty_warning() );
        return;
    }

    // queue bos olana kadar elemanlari dosyaya yazdirir.
    while ( !_time_sections.empty() )
    {
        TIME_SECTION curr = _time_sections.front();

        _time_sections.pop();

        output_file << curr;
    }
}

// Queue bos olma uyari mesaji.
string TIMES::get_time_section_empty_warning()
{
    string message;
    message += "\x1b[33m";
    message += "[TASK] : '" + _task_name + "' - [WARNING] - ";
    message += "Time sections is empty!";
    message += "\x1b[0m";

    return message;
}

// Dosya acik degil mesaji.
string TIMES::get_file_not_open_exception( string file_type )
{
    string message;
    message +=  "\x1b[31m";
    message += "[TASK] : '" + _task_name + "' - [FATAL_ERROR] - ";
    message += file_type + " file should be open!";
    message += "\x1b[0m";

    return message;
}

// Dosyaya yazdiriliyor bildirimi.
void TIMES::out_writing_to_file_message( ostream &out, const string end )
{
    out << "\x1b[34m"
    << "[TASK] : '" << _task_name << "' [STATE] - Writing to file..." 
    << "\x1b[0m"
    << end;
}