#include <stdio.h>
#include <windows.h>

void cursorpos(int x, int y) {
    COORD cursorpos;
    cursorpos.X = x;
    cursorpos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorpos);
}
int main() {

    int columns = 80;
    int rows = 24;

    int direction = 0;
    for (int i = 0; i < columns + rows; i++) {
        int jStart = i < columns ? 0 : i - columns + 1;
        int jEnd = i < columns ? i : columns - 1;

        if (direction % 2) {
            for (int j = jStart; j <= jEnd; j++) {
                int x = j;
                int y = i - j;
                if (x < columns && y < rows) {
                    cursorpos(x, y);
                    printf("*");
                    Sleep(10);
                }
            }
        }else {
            for (int j = jStart; j <= jEnd; j++) {//up
                int x = i - j;
                int y = j;
                if (x < columns && y < rows) {
                    cursorpos(x, y);
                        printf("*");
                    Sleep(10);
                }
            }
        }
        direction += 1;
    }

    getchar();

    return 0;
}
