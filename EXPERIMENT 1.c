#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Print current (parent) process ID
    printf("Parent Process:\n");
    printf("  Parent PID : %lu\n", GetCurrentProcessId());

    // Create a child process (example: Notepad)
    if (!CreateProcess(
        NULL,               // Application name
        "notepad.exe",      // Command to execute (child process)
        NULL,               // Process security
        NULL,               // Thread security
        FALSE,              // Handle inheritance
        0,                  // Creation flags
        NULL,               // Environment
        NULL,               // Current directory
        &si,                // Startup info
        &pi                 // Process information
    )) {
        printf("Process creation failed! Error: %lu\n", GetLastError());
        return 1;
    }

    // Print child PID
    printf("Child Process:\n");
    printf("  Child PID : %lu\n", pi.dwProcessId);

    // Close the handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

