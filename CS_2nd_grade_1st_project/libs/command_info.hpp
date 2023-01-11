#ifndef _COMMAND_INFO_
#define _COMMAND_INFO_

#include <iostream>
#include <fstream>
#include <string>

#include "times.hpp"

using namespace std;

// Bu kısım Berkcan İlmez tarafından kodlanmıştır.

class COMMAND_INFO
{
private:
    // baslangic ve bitis zamanlarinin degerlerini tutan degiskenler.
    double _start_time, _end_time;
    // komutun ismi.
    string _name;

public: 
    COMMAND_INFO( string name, double start_time, double end_time );

    // degiskenler icin getter.
    double      get_start_time() { return _start_time; }
    double      get_end_time()   { return _end_time;   }
    std::string get_name()       { return _name;       } 

    
    // komutu dosyaya yazdirir.
    void write_command_to_file( fstream &output_file, fstream &audio_file );

    //uyari yardimcilari.
    void log_command_info( ostream &out, const string end );
    void out_succesful_message( ostream &out, const string end );
    void out_unsuccesful_message( ostream &out, const string end );
};

#endif