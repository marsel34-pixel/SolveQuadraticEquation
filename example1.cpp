#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    printf("kruto%s\n", argv[1]);
    char bufferTe[] = {};
    sprintf(bufferTe , "example%s.cpp", argv[1]);

    
    FILE *fileThis = fopen(bufferTe, "r");
    char code[] = {};
    
    fseek(fileThis, 0, SEEK_END);
    long size = ftell(fileThis);

    fread(code, size, 1, fileThis);

    fclose(fileThis);

    char bufferText2[] = {};
    sprintf(bufferText2 , "example%s.cpp", argv[1]+1);
    printf(bufferText2);
    FILE *file = fopen(bufferText2, "w");
    fprintf(file, "%s", code);
    fclose(file);

    char bufferText3[] = {};
    sprintf(bufferText3 , "g++ -O2 example%s.cpp -o program%s.exe ", argv[1]+1, argv[1]+1, argv[1]+1);

    system(bufferText3);

    char bufferText4[] = {};
    sprintf(bufferText4 , "program%s.exe", argv[1]+1);
    system(bufferText4);
    system("pause");
}