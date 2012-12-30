/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS Client/Server Runtime SubSystem
 * FILE:            include/reactos/subsys/win/conmsg.h
 * PURPOSE:         Public definitions for communication
 *                  between Console API Clients and Servers
 * PROGRAMMERS:     Hermes Belusca-Maito (hermes.belusca@sfr.fr)
 */

#ifndef _CONMSG_H
#define _CONMSG_H

#pragma once

#define CONSRV_SERVERDLL_INDEX      2
#define CONSRV_FIRST_API_NUMBER     512

// Windows 2k3 tables, adapted from http://j00ru.vexillium.org/csrss_list/api_list.html#Windows_2k3
// plus a little bit of Windows 7. It is for testing purposes. After that I will add stubs.
// Some names are also deduced from the subsystems/win32/csrss/csrsrv/server.c ones.
typedef enum _CONSRV_API_NUMBER
{
    ConsolepOpenConsole = CONSRV_FIRST_API_NUMBER,
    ConsolepGetConsoleInput,
    ConsolepWriteConsoleInput,
    ConsolepReadConsoleOutput,
    ConsolepWriteConsoleOutput,
    ConsolepReadConsoleOutputString,
    ConsolepWriteConsoleOutputString,
    ConsolepFillConsoleOutput,
    ConsolepGetMode,
    // ConsolepGetNumberOfFonts,
    ConsolepGetNumberOfInputEvents,
    ConsolepGetScreenBufferInfo,
    ConsolepGetCursorInfo,
    // ConsolepGetMouseInfo,
    // ConsolepGetFontInfo,
    // ConsolepGetFontSize,
    // ConsolepGetCurrentFont,
    ConsolepSetMode,
    ConsolepSetActiveScreenBuffer,
    ConsolepFlushInputBuffer,
    // ConsolepGetLargestWindowSize,
    ConsolepSetScreenBufferSize,
    ConsolepSetCursorPosition,
    ConsolepSetCursorInfo,
    // ConsolepSetWindowInfo,
    ConsolepScrollScreenBuffer,
    ConsolepSetTextAttribute,
    // ConsolepSetFont,
    ConsolepSetIcon,
    ConsolepReadConsole,
    ConsolepWriteConsole,
    ConsolepDuplicateHandle,
    // ConsolepGetHandleInformation,
    // ConsolepSetHandleInformation,
    ConsolepCloseHandle,
    ConsolepVerifyIoHandle,
    ConsolepAlloc,
    ConsolepFree,
    ConsolepGetTitle,
    ConsolepSetTitle,
    ConsolepCreateScreenBuffer,
    // ConsolepInvalidateBitMapRect,
    // ConsolepVDMOperation,
    // ConsolepSetCursor,
    // ConsolepShowCursor,
    // ConsolepMenuControl,
    // ConsolepSetPalette,
    // ConsolepSetDisplayMode,
    // ConsolepRegisterVDM,
    ConsolepGetHardwareState,
    ConsolepSetHardwareState,
    // ConsolepGetDisplayMode,
    ConsolepAddAlias,
    ConsolepGetAlias,
    ConsolepGetAliasesLength,
    ConsolepGetAliasExesLength,
    ConsolepGetAliases,
    ConsolepGetAliasExes,
    ConsolepExpungeCommandHistory,
    ConsolepSetNumberOfCommands,
    ConsolepGetCommandHistoryLength,
    ConsolepGetCommandHistory,
    // ConsolepSetCommandHistoryMode,
    ConsolepGetCP,
    ConsolepSetCP,
    // ConsolepSetKeyShortcuts,
    // ConsolepSetMenuClose,
    // ConsolepNotifyLastClose,
    ConsolepGenerateCtrlEvent,
    // ConsolepGetKeyboardLayoutName,
    ConsolepGetConsoleWindow,
    // ConsolepCharType,
    // ConsolepSetLocalEUDC,
    // ConsolepSetCursorMode,
    // ConsolepGetCursorMode,
    // ConsolepRegisterOS2,
    // ConsolepSetOS2OemFormat,
    // ConsolepGetNlsMode,
    // ConsolepSetNlsMode,
    // ConsolepRegisterConsoleIME,
    // ConsolepUnregisterConsoleIME,
    // ConsolepGetLangId,
    // ConsolepAttach,
    ConsolepGetSelectionInfo,
    ConsolepGetProcessList,
    ConsolepGetHistory,
    ConsolepSetHistory,

    ConsolepMaxApiNumber
} CONSRV_API_NUMBER, *PCONSRV_API_NUMBER;


typedef struct _CONSOLE_CONNECTION_INFO
{
    ULONG Dummy;
} CONSOLE_CONNECTION_INFO, *PCONSOLE_CONNECTION_INFO;


#define CONSOLE_INPUT_MODE_VALID    0x0f
#define CONSOLE_OUTPUT_MODE_VALID   0x03


typedef struct
{
    USHORT nMaxIds;
    ULONG  nProcessIdsTotal;
    PDWORD pProcessIds;
} CSRSS_GET_PROCESS_LIST, *PCSRSS_GET_PROCESS_LIST;

typedef struct
{
    HANDLE ConsoleHandle;
    BOOL Unicode;
    ULONG NrCharactersToWrite;
    ULONG NrCharactersWritten;

    ULONG BufferSize;
    PVOID Buffer;
} CSRSS_WRITE_CONSOLE, *PCSRSS_WRITE_CONSOLE;

typedef struct
{
    HANDLE ConsoleHandle;
    BOOL Unicode;
    WORD NrCharactersToRead;
    WORD NrCharactersRead;

    UNICODE_STRING ExeName;
    DWORD CtrlWakeupMask;
    DWORD ControlKeyState;

    ULONG BufferSize;
    PVOID Buffer;
} CSRSS_READ_CONSOLE, *PCSRSS_READ_CONSOLE;

typedef struct
{
    LPTHREAD_START_ROUTINE CtrlDispatcher;
    BOOL ConsoleNeeded;
    INT ShowCmd;
    HANDLE Console;
    HANDLE InputHandle;
    HANDLE OutputHandle;
} CSRSS_ALLOC_CONSOLE, *PCSRSS_ALLOC_CONSOLE;

typedef struct
{
    ULONG Dummy;
} CSRSS_FREE_CONSOLE, *PCSRSS_FREE_CONSOLE;

typedef struct
{
    HANDLE ConsoleHandle;
    CONSOLE_SCREEN_BUFFER_INFO Info;
} CSRSS_SCREEN_BUFFER_INFO, *PCSRSS_SCREEN_BUFFER_INFO;

typedef struct
{
    HANDLE ConsoleHandle;
    COORD Position;
} CSRSS_SET_CURSOR_POSITION, *PCSRSS_SET_CURSOR_POSITION;

typedef struct
{
    HANDLE ConsoleHandle;
    CONSOLE_CURSOR_INFO Info;
} CSRSS_CURSOR_INFO, *PCSRSS_CURSOR_INFO;

typedef struct
{
    HANDLE ConsoleHandle;
    WORD Attrib;
} CSRSS_SET_ATTRIB, *PCSRSS_SET_ATTRIB;

typedef struct
{
    HANDLE ConsoleHandle;
    DWORD ConsoleMode;
} CSRSS_CONSOLE_MODE, *PCSRSS_CONSOLE_MODE;

typedef struct
{
    DWORD Access;
    DWORD ShareMode;
    BOOL Inheritable;
    HANDLE OutputHandle;  /* handle to newly created screen buffer */
} CSRSS_CREATE_SCREEN_BUFFER, *PCSRSS_CREATE_SCREEN_BUFFER;

typedef struct
{
    HANDLE OutputHandle;  /* handle to screen buffer to switch to */
} CSRSS_SET_SCREEN_BUFFER, *PCSRSS_SET_SCREEN_BUFFER;

typedef struct
{
    DWORD Length;
    PWCHAR Title;
} CSRSS_CONSOLE_TITLE, *PCSRSS_CONSOLE_TITLE;

typedef struct
{
    HANDLE ConsoleHandle;
    BOOL Unicode;
    COORD BufferSize;
    COORD BufferCoord;
    SMALL_RECT WriteRegion;
    CHAR_INFO* CharInfo;
} CSRSS_WRITE_CONSOLE_OUTPUT, *PCSRSS_WRITE_CONSOLE_OUTPUT;

typedef struct
{
    HANDLE ConsoleInput;
} CSRSS_FLUSH_INPUT_BUFFER, *PCSRSS_FLUSH_INPUT_BUFFER;

typedef struct
{
    HANDLE ConsoleHandle;
    BOOL Unicode;
    SMALL_RECT ScrollRectangle;
    BOOL UseClipRectangle;
    SMALL_RECT ClipRectangle;
    COORD DestinationOrigin;
    CHAR_INFO Fill;
} CSRSS_SCROLL_CONSOLE_SCREEN_BUFFER, *PCSRSS_SCROLL_CONSOLE_SCREEN_BUFFER;


/*
 * An attribute or a character are instances of the same entity, namely
 * a "code" (what would be called an (ANSI) escape sequence). Therefore
 * encode them inside the same structure.
 */
typedef enum _CODE_TYPE
{
    CODE_ASCII      = 0x01,
    CODE_UNICODE    = 0x02,
    CODE_ATTRIBUTE  = 0x03
} CODE_TYPE;

typedef struct
{
    HANDLE ConsoleHandle;

    DWORD NumCodesToRead;
    COORD ReadCoord;
    COORD EndCoord;

    DWORD CodesRead;

    CODE_TYPE CodeType;
    union
    {
        PVOID pCode;
        PCHAR AsciiChar;
        PWCHAR UnicodeChar;
        PWORD Attribute;
    } pCode;    // Either a pointer to a character or to an attribute.
} CSRSS_READ_CONSOLE_OUTPUT_CODE, *PCSRSS_READ_CONSOLE_OUTPUT_CODE;

typedef struct
{
    HANDLE ConsoleHandle;
    USHORT CodeType;

    ULONG BufferSize;
    WORD Length;
    COORD Coord;
    COORD EndCoord;

    ULONG NrCharactersWritten;

    union
    {
        // PVOID String;
        PVOID pCode;
        PCHAR AsciiChar;
        PWCHAR UnicodeChar;
        PWORD Attribute;
    } pCode;    // Either a pointer to a character or to an attribute.
} CSRSS_WRITE_CONSOLE_OUTPUT_CODE, *PCSRSS_WRITE_CONSOLE_OUTPUT_CODE;

typedef struct
{
    HANDLE ConsoleHandle;

    CODE_TYPE CodeType;
    union
    {
        CHAR AsciiChar;
        WCHAR UnicodeChar;
        WORD Attribute;
    } Code; // Either a character or an attribute.

    COORD Coord;
    ULONG Length;

    ULONG NrCharactersWritten; // FIXME: Only for chars, is it removable ?
} CSRSS_FILL_OUTPUT, *PCSRSS_FILL_OUTPUT;

typedef struct
{
    HANDLE ConsoleHandle;
    BOOL Unicode;
    BOOL bRead; // TRUE --> Read ; FALSE --> Peek

    ULONG InputsRead;

    ULONG Length;
    PINPUT_RECORD InputRecord;
} CSRSS_GET_CONSOLE_INPUT, *PCSRSS_GET_CONSOLE_INPUT;

typedef struct
{
    HANDLE ConsoleHandle;
    BOOL Unicode;
    COORD BufferSize;
    COORD BufferCoord;
    SMALL_RECT ReadRegion;
    CHAR_INFO* CharInfo;
} CSRSS_READ_CONSOLE_OUTPUT, *PCSRSS_READ_CONSOLE_OUTPUT;

typedef struct
{
    HANDLE ConsoleHandle;
    BOOL Unicode;
    DWORD Length;
    INPUT_RECORD* InputRecord;
} CSRSS_WRITE_CONSOLE_INPUT, *PCSRSS_WRITE_CONSOLE_INPUT;

typedef struct
{
    HANDLE Handle;
} CSRSS_CLOSE_HANDLE, *PCSRSS_CLOSE_HANDLE;

typedef struct
{
    HANDLE Handle;
} CSRSS_VERIFY_HANDLE, *PCSRSS_VERIFY_HANDLE;

typedef struct
{
    HANDLE Handle;
    DWORD Access;
    BOOL Inheritable;
    DWORD Options;
} CSRSS_DUPLICATE_HANDLE, *PCSRSS_DUPLICATE_HANDLE;

/*
 * Type of handles.
 */
typedef enum _CONSOLE_HANDLE_TYPE
{
    HANDLE_INPUT    = 0x01,
    HANDLE_OUTPUT   = 0x02
} CONSOLE_HANDLE_TYPE;

typedef struct
{
    HANDLE Handle;
    CONSOLE_HANDLE_TYPE HandleType;
    DWORD Access;
    BOOL Inheritable;
    DWORD ShareMode;
} CSRSS_OPEN_CONSOLE, *PCSRSS_OPEN_CONSOLE;

typedef struct
{
    HANDLE InputWaitHandle;
} CSRSS_GET_INPUT_WAIT_HANDLE, *PCSRSS_GET_INPUT_WAIT_HANDLE;


/*
 * Console hardware states.
 */
#define CONSOLE_HARDWARE_STATE_GDI_MANAGED 0
#define CONSOLE_HARDWARE_STATE_DIRECT      1

typedef struct
{
    HANDLE ConsoleHandle;
    DWORD  State;
} CSRSS_CONSOLE_HW_STATE, *PCSRSS_CONSOLE_HW_STATE;

typedef struct
{
    HWND    WindowHandle;
} CSRSS_GET_CONSOLE_WINDOW, *PCSRSS_GET_CONSOLE_WINDOW;

typedef struct
{
    HICON   WindowIcon;
} CSRSS_SET_CONSOLE_ICON, *PCSRSS_SET_CONSOLE_ICON;









typedef struct
{
    ULONG  SourceLength;
    ULONG  TargetLength; // Also used for storing the number of bytes written.
    ULONG  ExeLength;
    LPWSTR Source;
    LPWSTR Target;
    LPWSTR Exe;
} CSRSS_CONSOLE_ALIAS, *PCSRSS_CONSOLE_ALIAS;

typedef struct
{
    DWORD ExeLength;
    DWORD AliasesBufferLength;
    LPWSTR ExeName;
    LPWSTR AliasesBuffer;
} CSRSS_GET_ALL_CONSOLE_ALIASES, *PCSRSS_GET_ALL_CONSOLE_ALIASES;

typedef struct
{
    DWORD Length;
    DWORD ExeLength;
    LPWSTR ExeName;
} CSRSS_GET_ALL_CONSOLE_ALIASES_LENGTH, *PCSRSS_GET_ALL_CONSOLE_ALIASES_LENGTH;

typedef struct
{
    DWORD Length;
    LPWSTR ExeNames;
} CSRSS_GET_CONSOLE_ALIASES_EXES, *PCSRSS_GET_CONSOLE_ALIASES_EXES;

typedef struct
{
    DWORD Length;
} CSRSS_GET_CONSOLE_ALIASES_EXES_LENGTH, *PCSRSS_GET_CONSOLE_ALIASES_EXES_LENGTH;






typedef struct
{
    UNICODE_STRING ExeName;
    PWCHAR History;
    DWORD Length;
} CSRSS_GET_COMMAND_HISTORY, *PCSRSS_GET_COMMAND_HISTORY;

typedef struct
{
    UNICODE_STRING ExeName;
    DWORD Length;
} CSRSS_GET_COMMAND_HISTORY_LENGTH, *PCSRSS_GET_COMMAND_HISTORY_LENGTH;

typedef struct
{
    UNICODE_STRING ExeName;
} CSRSS_EXPUNGE_COMMAND_HISTORY, *PCSRSS_EXPUNGE_COMMAND_HISTORY;

typedef struct
{
    UNICODE_STRING ExeName;
    DWORD NumCommands;
} CSRSS_SET_HISTORY_NUMBER_COMMANDS, *PCSRSS_SET_HISTORY_NUMBER_COMMANDS;

typedef struct
{
    UINT HistoryBufferSize;
    UINT NumberOfHistoryBuffers;
    DWORD dwFlags;
} CSRSS_HISTORY_INFO, *PCSRSS_HISTORY_INFO;










typedef struct
{
    DWORD Event;
    DWORD ProcessGroup;
} CSRSS_GENERATE_CTRL_EVENT, *PCSRSS_GENERATE_CTRL_EVENT;

typedef struct
{
    HANDLE ConsoleHandle;
    DWORD NumInputEvents;
} CSRSS_GET_NUM_INPUT_EVENTS, *PCSRSS_GET_NUM_INPUT_EVENTS;

typedef struct
{
    HANDLE OutputHandle;
    COORD Size;
} CSRSS_SET_SCREEN_BUFFER_SIZE, *PCSRSS_SET_SCREEN_BUFFER_SIZE;

typedef struct
{
    CONSOLE_SELECTION_INFO Info;
} CSRSS_GET_CONSOLE_SELECTION_INFO, *PCSRSS_GET_CONSOLE_SELECTION_INFO;

typedef struct
{
    BOOL InputCP;   // TRUE : Input Code Page ; FALSE : Output Code Page
    UINT CodePage;
} CSRSS_CONSOLE_CP, *PCSRSS_CONSOLE_CP;

typedef struct _CONSOLE_API_MESSAGE
{
    PORT_MESSAGE Header;

    PCSR_CAPTURE_BUFFER CsrCaptureData;
    CSR_API_NUMBER ApiNumber;
    ULONG Status; // ReturnValue; // NTSTATUS Status
    ULONG Reserved;
    union
    {
        CSRSS_ALLOC_CONSOLE AllocConsoleRequest;
        CSRSS_FREE_CONSOLE FreeConsoleRequest;

        /* Handles */
        CSRSS_OPEN_CONSOLE OpenConsoleRequest;
        CSRSS_CLOSE_HANDLE CloseHandleRequest;
        CSRSS_VERIFY_HANDLE VerifyHandleRequest;
        CSRSS_DUPLICATE_HANDLE DuplicateHandleRequest;
        CSRSS_GET_INPUT_WAIT_HANDLE GetConsoleInputWaitHandle;

        /* Cursor */
        CSRSS_CURSOR_INFO CursorInfoRequest;
        CSRSS_SET_CURSOR_POSITION SetCursorPositionRequest;

        /* Screen buffer */
        CSRSS_CREATE_SCREEN_BUFFER CreateScreenBufferRequest;
        CSRSS_SET_SCREEN_BUFFER SetScreenBufferRequest;
        CSRSS_SCREEN_BUFFER_INFO ScreenBufferInfoRequest;
        CSRSS_SET_SCREEN_BUFFER_SIZE SetScreenBufferSize;
        CSRSS_SCROLL_CONSOLE_SCREEN_BUFFER ScrollConsoleScreenBufferRequest;

        CSRSS_GET_CONSOLE_SELECTION_INFO GetConsoleSelectionInfo;
        CSRSS_FLUSH_INPUT_BUFFER FlushInputBufferRequest;

        /* Console mode */
        CSRSS_CONSOLE_MODE ConsoleModeRequest;
        CSRSS_CONSOLE_HW_STATE ConsoleHardwareStateRequest;

        /* Console window */
        CSRSS_CONSOLE_TITLE TitleRequest;
        CSRSS_GET_CONSOLE_WINDOW GetConsoleWindowRequest;
        CSRSS_SET_CONSOLE_ICON SetConsoleIconRequest;

        /* Read */
        CSRSS_READ_CONSOLE ReadConsoleRequest;              // SrvReadConsole / ReadConsole
        CSRSS_GET_CONSOLE_INPUT GetConsoleInputRequest;     // SrvGetConsoleInput / PeekConsoleInput & ReadConsoleInput
        CSRSS_READ_CONSOLE_OUTPUT ReadConsoleOutputRequest; // SrvReadConsoleOutput / ReadConsoleOutput
        CSRSS_READ_CONSOLE_OUTPUT_CODE ReadConsoleOutputCodeRequest;    // SrvReadConsoleOutputString / ReadConsoleOutputAttribute & ReadConsoleOutputCharacter

        /* Write */
        CSRSS_WRITE_CONSOLE WriteConsoleRequest;            // SrvWriteConsole / WriteConsole
        CSRSS_WRITE_CONSOLE_INPUT WriteConsoleInputRequest;
        CSRSS_WRITE_CONSOLE_OUTPUT WriteConsoleOutputRequest;
        CSRSS_WRITE_CONSOLE_OUTPUT_CODE WriteConsoleOutputCodeRequest;

        CSRSS_FILL_OUTPUT FillOutputRequest;
        CSRSS_SET_ATTRIB SetAttribRequest;

        /* Aliases */
        CSRSS_CONSOLE_ALIAS ConsoleAlias;
        CSRSS_GET_ALL_CONSOLE_ALIASES GetAllConsoleAliases;
        CSRSS_GET_ALL_CONSOLE_ALIASES_LENGTH GetAllConsoleAliasesLength;
        CSRSS_GET_CONSOLE_ALIASES_EXES GetConsoleAliasesExes;
        CSRSS_GET_CONSOLE_ALIASES_EXES_LENGTH GetConsoleAliasesExesLength;

        /* History */
        CSRSS_GET_COMMAND_HISTORY GetCommandHistory;
        CSRSS_GET_COMMAND_HISTORY_LENGTH GetCommandHistoryLength;
        CSRSS_EXPUNGE_COMMAND_HISTORY ExpungeCommandHistory;
        CSRSS_SET_HISTORY_NUMBER_COMMANDS SetHistoryNumberCommands;
        CSRSS_HISTORY_INFO HistoryInfoRequest;

        CSRSS_GENERATE_CTRL_EVENT GenerateCtrlEvent;
        CSRSS_GET_NUM_INPUT_EVENTS GetNumInputEventsRequest;

        /* Input and Output Code Pages */
        CSRSS_CONSOLE_CP ConsoleCPRequest;

        CSRSS_GET_PROCESS_LIST GetProcessListRequest;
    } Data;
} CONSOLE_API_MESSAGE, *PCONSOLE_API_MESSAGE;

// Check that a CONSOLE_API_MESSAGE can hold in a CSR_API_MESSAGE.
CHECK_API_MSG_SIZE(CONSOLE_API_MESSAGE);

#endif // _CONMSG_H

/* EOF */
