/*

    PROJECT: PRINT ASCII CHARACTERSET TABLE
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <graph.h>

int main(void)
{
    int i, j, character;
    unsigned char ch;
    char buffer[3];

    _outtext("ASCII Characterset Table\n\n");
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
        {
            character = i + (j * 16);
            ch = (unsigned char)character;
            sprintf(buffer, "%02X", character);
            _outtext(buffer);
            _outtext(" ");
            _outmem(&ch, 1);
            if (j < 15) _outtext(" ");
        }
        _outtext("\n");
    }
    _outtext("\n");

    return 0;
}
