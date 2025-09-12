#include <Windows.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);

    srand((unsigned)time(NULL));

    // Initial warning messages
    if (MessageBoxW(NULL,
        L"Attention — you just ran WINTILE 3 which does NOT harm your computer. It will just show a lot of popups.\r\n"
        L"DO YOU WANT TO EXECUTE THIS?",
        L"WINTILE 3", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        ExitProcess(0);

    if (MessageBoxW(NULL,
        L"THIS IS THE LAST WARNING!\r\n\r\n"
        L"DO YOU WANNA EXECUTE IT?\r\n"
        L"STILL EXECUTE IT?",
        L"WINTILE 3", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        ExitProcess(0);

    MessageBoxW(NULL, L"Executing...", L"WINTILE 3", MB_OK | MB_ICONINFORMATION);

    DWORD startTime = GetTickCount();

    // Show random error popups for 5 seconds
    while (GetTickCount() - startTime < 5000) {
        // Random position for the message box (optional)
        int x = rand() % (screenW - 300);
        int y = rand() % (screenH - 150);

        // Spawn the message box
        MessageBoxW(
            NULL,
            L"Still using this PC?",
            L"Error",
            MB_OK | MB_ICONERROR
        );

        Sleep(100 + rand() % 2000000); // random short delay
    }

    return 0;
}
