// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
#include <windows.h>
#include <SDKDDKVer.h>

//���ﲻ��Ҫ���κθĶ�


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		//"dll is attached"
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		//"dll is detached"
		break;
	}
	return TRUE;
}

