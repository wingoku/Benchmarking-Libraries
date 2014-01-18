#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <ctime>
#include <conio.h>


using namespace std;


float compressDecompress(char command[]);


int main()
{
    float kakaduCompress=0, kakaduDecompress=0;

    float openJPEGCompress, openJPEGDecompress;

	

    kakaduCompress = compressDecompress("kdu_compress.exe -i input.bmp -o KDUencoded.jp2 -rate 0.25");
    kakaduDecompress = compressDecompress("kdu_expand -i KDUencoded.jp2 -o KDUdecoded.bmp");

    openJPEGCompress = compressDecompress( "opj_compress -i input.bmp -o OpenCompressed.jp2 -r 25 ");
    openJPEGDecompress = compressDecompress( "opj_decompress -i OpenCompressed.jp2 -o OpenDecompresed.jp2 -r 25 ");


    system("cls");

    cout<< "\n\nKakadu compression time: "<< kakaduCompress <<endl<<endl;

    cout<< "\n\nKakadu decompression time: "<< kakaduDecompress <<endl<<endl;


    cout<< "\n\OpenJPEG compression time: "<< openJPEGCompress <<endl<<endl;

    cout<< "\n\OpenJPEG decompression time: "<< openJPEGDecompress <<endl<<endl;


    if(kakaduCompress < openJPEGCompress)
    {
        int compressResult = (openJPEGCompress - kakaduCompress)*100;

        cout << "Kakadu compression is "<< compressResult << "% faster\n\n";
    }
    else
    {
        int compressResult = (kakaduCompress - openJPEGCompress)*100;

        cout << "OpenJPEG compression is "<< compressResult << "% faster\n\n";

    }


    if(kakaduDecompress < openJPEGDecompress)
    {
        int compressResult = (openJPEGDecompress - kakaduDecompress)*100;

        cout << "Kakadu decompression is "<< compressResult << "% faster\n\n";
    }
    else
    {
        int compressResult = (kakaduDecompress - openJPEGDecompress)*100;

        cout << "OpenJPEG decompression is "<< compressResult << "% faster\n\n";

    }

	return 0;
}

float compressDecompress( char command[])
{
    float start=0, end=0;

    float timeTaken;

    start=clock();

    system(command);

    end=clock();

    timeTaken = (end - start) / CLOCKS_PER_SEC;

    return timeTaken;

    //cout<< "\n\n"<< libName<<" compression time: "<< timeTakenCompress <<endl<<endl;
}



