#include <Windows.h>
#include "stdio.h"

HANDLE g_CmdHandle;
DWORD g_ProcessId;

BOOL KillProcess(DWORD ProcessId)
{
	HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,ProcessId);
	if(hProcess==NULL)
	{
		printf("OpenProcess error: %d\n", GetLastError());
		return FALSE;
	}
	if(!TerminateProcess(hProcess,0))
	{
		printf("TerminateProcess error: %d\n", GetLastError());
		return FALSE;
	}
	return TRUE;
}

int main(int argc, char * argv[]) 
{
	STARTUPINFO StartUpInfo = { sizeof(StartUpInfo) };
	PROCESS_INFORMATION ProcessInfo;
	StartUpInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartUpInfo.wShowWindow = TRUE;
	if (CreateProcess(NULL, "python.exe", \
		NULL, NULL, FALSE, NULL, NULL, NULL, 
		&StartUpInfo, &ProcessInfo))
		// TODO: pi.dwProcessId is same with MyGetProcesId.
		//g_CmdProcessId = MyGetProcessId(pi.hProcess);
		{
			g_ProcessId = ProcessInfo.dwProcessId;
			g_CmdHandle = ProcessInfo.hProcess;
		}
		
	else
	{
		printf("ExecCmdline \"%s\" failed!\n", "python.exe");
		MessageBox(NULL, "python.exe", "Error: ÷¥––√¸¡Ó ß∞‹!", MB_OK);
		ExitProcess(0);
	}

	CloseHandle(ProcessInfo.hThread);
	CloseHandle(ProcessInfo.hProcess);

	Sleep(10000);
	if(!TerminateProcess(g_CmdHandle, 0))
		printf("Terminate error: %d\n", GetLastError());
	//KillProcess(g_ProcessId);

	system("pause");
}