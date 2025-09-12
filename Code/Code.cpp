#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)

HICON icons[] = {
    LoadIcon(NULL, IDI_APPLICATION),
    LoadIcon(NULL, IDI_ASTERISK),
    LoadIcon(NULL, IDI_ERROR),
    LoadIcon(NULL, IDI_EXCLAMATION),
    LoadIcon(NULL, IDI_HAND),
    LoadIcon(NULL, IDI_INFORMATION),
    LoadIcon(NULL, IDI_QUESTION),
    LoadIcon(NULL, IDI_WARNING),
    LoadIcon(NULL, IDI_WINLOGO),
    LoadIcon(NULL, IDI_SHIELD)
};

size_t s_icons = sizeof(icons) / sizeof(HICON);

void DrawIcon() {
    HWND hWnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hWnd);

    DrawIcon(hdc, rand() % (SCREEN_WIDTH - 32), rand() % (SCREEN_HEIGHT - 32), icons[rand() % s_icons]);

    ReleaseDC(hWnd, hdc);
}

int main() {
    srand((unsigned int)time(NULL)); // Seed random

    // Show warning first
    int result = MessageBoxW(
        NULL,
        L"Warning!\nThis program will display icons all over your screen.\nDo you want to continue?",
        L"Warning",
        MB_YESNO | MB_ICONWARNING
    );

    if (result == IDYES) {
        // Only run the icon spam if user pressed Yes
        while (1) {
            DrawIcon();
        }
    } else {
        MessageBoxW(NULL, L"Program aborted.", L"Info", MB_OK | MB_ICONINFORMATION);
    }

    return 0;
}
