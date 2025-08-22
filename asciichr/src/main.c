/*

    PROJECT: PRINT ASCII CHARACTERSET
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <graph.h>

int main(void)
{
    int i;
    unsigned char ch;

    _outtext("ASCII Characterset\n\n");
    for (i = 0; i < 256; i++)
    {
        ch = (unsigned char)i;
        _outmem(&ch, 1);
    }
    _outtext("\n");

    return 0;
}
