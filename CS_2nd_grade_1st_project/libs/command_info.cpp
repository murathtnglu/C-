#include <fstream>
#include <string>

#include "command_info.hpp"

// Bu kısım Tolunay Gümüş tarafından kodlanmıştır.

// constructor.
COMMAND_INFO::COMMAND_INFO( string name, double start_time, double end_time ) 
: 
_name(name), _start_time(start_time), _end_time(end_time) {}

// komut dosyaya yazdirilir.
void COMMAND_INFO::write_command_to_file( fstream &output_file, fstream &audio_file )
{
    log_command_info( cerr, "\n" );

    try
    {
        // baslangic ve bitis zamanlarindan zaman araligi cikartilir.
        TIMES times( audio_file, _name, _start_time, _end_time );
        
        // zaman araligi dosyaya yazdirilir.
        times.write_to_file( output_file );

        out_succesful_message( cerr, "\n" );
    }
    catch( const string &e )
    {
        // olasi hatalar yakalanir.
        cerr << e << endl;
        out_unsuccesful_message( cerr, "\n" );
    }
}

// komut bilgisi yazdirma.
void COMMAND_INFO::log_command_info( ostream &out, const string end )
{
    out << "\x1b[34m"
    << "[TASK] : '" << _name << "' "
    << "[START TIME] : '" << _start_time << "' " 
    << "[END TIME] : '" << _end_time << "' " 
    << "\x1b[0m"
    << end;
}

// basarili oldu bilgisi yazdirma.
void COMMAND_INFO::out_succesful_message( ostream &out, const string end )
{
    out << "\x1b[32m"
    << "[TASK] : '" << _name << "' - [SUCCESSFUL]" 
    << "\x1b[0m"
    << end;
}

// basarisiz oldu bilgisi yazdirma.
void COMMAND_INFO::out_unsuccesful_message( ostream &out, const string end )
{
    out << "\x1b[31m"
    << "[TASK] : '" << _name << "' - [UNSUCCESSFUL]" 
    << "\x1b[0m"
    << end;
}