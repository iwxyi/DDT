#include <stdio.h>

int TestOutputJC = 0, TestOutputMax = 5; // ¡¤¨¤?1¦Ì¡¥¡ä¡ã¨¬??¨¤1?2?¦Ì?
void TestOut(HWND hWnd, int x)
{
    if (TestOutputJC > TestOutputMax) return ;
    TestOutputJC++;
    char a[1000];
    sprintf(a, "%d", x);
    MessageBox(hWnd, a, "123", 1);
}
void TestOut(HWND hWnd, int x, int y)
{
    if (TestOutputJC > TestOutputMax) return ;
    TestOutputJC++;
    char a[1000], b[1000];
    sprintf(a, "%d", x);
    sprintf(b, "%d", y);
    MessageBox(hWnd, a, b, 1);
}
void TestOut(HWND hWnd, char *s)
{
    if (TestOutputJC > TestOutputMax) return ;
    TestOutputJC++;
    MessageBox(hWnd, s, "", 1);
}
