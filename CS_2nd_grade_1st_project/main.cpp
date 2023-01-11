#include <fstream>

#include "libs/command_info.hpp"

using namespace std;

//Bu kısım Mert Irmak tarafından kodlanmıştır.

int main( int argc, char *argv[] )
{
    // her bir kisi icin komutlar ve bilgileri.
    COMMAND_INFO commands[4][4] = {
        {
            COMMAND_INFO( "ac",   1.204, 1.445 ),
            COMMAND_INFO( "kapa", 2.274, 2.723 ),
            COMMAND_INFO( "sag",  3.415, 3.778 ),
            COMMAND_INFO( "sol",  4.437, 4.720 ),
        },
        {
            COMMAND_INFO( "ac",   1.204, 1.445 ),
            COMMAND_INFO( "kapa", 2.274, 2.723 ),
            COMMAND_INFO( "sag",  3.415, 3.778 ),
            COMMAND_INFO( "sol",  4.437, 4.720 ),
        },
        {
            COMMAND_INFO( "ac",   1.204, 1.445 ),
            COMMAND_INFO( "kapa", 2.274, 2.723 ),
            COMMAND_INFO( "sag",  3.415, 3.778 ),
            COMMAND_INFO( "sol",  4.437, 4.720 ),
        },
        {
            COMMAND_INFO( "ac",   1.204, 1.445 ),
            COMMAND_INFO( "kapa", 2.274, 2.723 ),
            COMMAND_INFO( "sag",  3.415, 3.778 ),
            COMMAND_INFO( "sol",  4.437, 4.720 ),
        },
    };

    // kisi ve komut isimleri.
    string names[4] = {"kisi1", "kisi2", "kisi3", "kisi4"};
    string command_names[4] = {"ac", "kapa", "sag", "sol"};

    // her bir kisiden komutlarin ayiklanmasi.
    for ( int i = 0; i < 4; i++ )
    {
        string name = names[i];

        cerr << "\x1b[32m[NAME] : '" << name << "' - [START] -----------------------------------\x1b[0m" << endl;

        // kisi dosyasi acilir.
        fstream audio_file( name + ".txt",  ios::in );

        for ( int j = 0; j < 4; j++ )
        {
            string file_name = "db/seperate/" + name + "_" + command_names[j] + ".txt";

            // cikti dosyasi acilir.
            fstream output_file( file_name, ios::out );

            // komut dosyaya yazdirilir.
            commands[i][j].write_command_to_file( output_file, audio_file );

            // file pointer kisi dosyasinin baslangicina gider.
            audio_file.clear();
            audio_file.seekg(0);

            output_file.close();
        }

        audio_file.close();

        cerr << "\x1b[32m[NAME] : '" << name << "' - [END] ------------------------------------\x1b[0m" << endl << endl;
    }

    // ayrilan komut dosyalari okunup birlestirilir.
    for ( int i = 0; i < 4; i++ )
    {
        string command_name = command_names[i];
        
        // her bir komut icin cikti dosyasi acilir.
        string output_file_name = "db/joined/" + command_name + "_kisi_1_2_3_4.txt";
        fstream output_file( output_file_name, ios::out );

        cerr << "\x1b[32m[OUT] : '" << output_file_name << "' - [START]" << endl;

        for ( int j = 0; j < 4; j++ )
        {
            string name = names[j];
            
            // her bir kisi icin komut dosyalari acilir.
            string input_file_name = "db/seperate/" + name + "_" + command_names[i] + ".txt";
            fstream input_file( input_file_name, ios::in );

            // komut gerekli dosyaya yazdirilir.
            commands[j][i].write_command_to_file( output_file, input_file );

            output_file << "**************************" << endl;

            input_file.close();
        }

        cerr << "\x1b[32m[OUT] : '" << output_file_name << "' - [END]\x1b[0m" << endl << endl;

        output_file.close();
    }

    return 1;
}