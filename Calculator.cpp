
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <string.h>

#define DIR_LEN MAX_PATH+1
enum{DIV=1, MUL, ADD, MIN, ELSE, EXIT};
DWORD ShowMenu();
int _tmain(int argc, TCHAR* argv[])
{
	BOOL state;
	BOOL num1=0, num2=0;
	TCHAR space[2];
	TCHAR c_num1[10];
	TCHAR c_num2[10];
	space[0]= ' ';
	DWORD sel;
	STARTUPINFO si={0,};
	PROCESS_INFORMATION pi;	
	si.cb=sizeof(si);
	si.dwFlags=STARTF_USEPOSITION|STARTF_USESIZE;
	
	TCHAR command1[]=_T("AdderProcess.exe");
	TCHAR command2[]=_T("MinerProcess.exe");
	TCHAR command3[]=_T("MultiProcess.exe");
	TCHAR command4[]=_T("DivderProcess.exe");
	
	TCHAR copy_command1[]=_T("AdderProcess.exe");
	TCHAR copy_command2[]=_T("MinerProcess.exe");
	TCHAR copy_command3[]=_T("MultiProcess.exe");
	TCHAR copy_command4[]=_T("DivderProcess.exe");
	TCHAR cDir[DIR_LEN];
	
	GetCurrentDirectory(DIR_LEN, cDir);	//현재 디렉토리 확인.
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);
	
	SetCurrentDirectory(_T("C:\\WINDOWS\\system32"));
	
	GetCurrentDirectory(DIR_LEN, cDir);	//현재 디렉토리 확인.
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	while(true)
	{
		sel=ShowMenu();
		if(sel==EXIT){
			_tprintf("프로그램을 종료합니다. \n");
			return 0;
		}	
		if( sel != ELSE)
		{
		    _fputts(_T("Input Num1 Num2: "), stdout);
		    _tscanf(_T("%d %d"), &num1, &num2);
		}
		switch(sel)
		{
		case DIV:
			sprintf(c_num1, "%d", num1);
		    sprintf(c_num2, "%d", num2);
			strcat(command4,space);
			strcat(command4,c_num1);
			strcat(command4,space);
			strcat(command4,c_num2);
			
			state=CreateProcess(NULL, command4,	NULL,	NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
			break;
		case MUL:
			sprintf(c_num1, "%d", num1);
		    sprintf(c_num2, "%d", num2);
			strcat(command3,space);
			strcat(command3,c_num1);
			strcat(command3,space);
			strcat(command3,c_num2);
			
			state=CreateProcess(NULL, command3,	NULL,	NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
			break;
		case ADD:
			sprintf(c_num1, "%d", num1);
		    sprintf(c_num2, "%d", num2);
			strcat(command1,space);
			strcat(command1,c_num1);
			strcat(command1,space);
			strcat(command1,c_num2);
			
			state=CreateProcess(NULL, command1,	NULL,	NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
			break;
		case MIN:
			sprintf(c_num1, "%d", num1);
		    sprintf(c_num2, "%d", num2);
			strcat(command2,space);
			strcat(command2,c_num1);
			strcat(command2,space);
			strcat(command2,c_num2);
			
			state=CreateProcess(NULL, command2,	NULL,	NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
			break;
		case ELSE:
			printf("아무키나 입력하시면 다시 메뉴로 돌아갑니다.\n");
			char a;
			scanf("%c", &a);
			scanf("%c", &a);
			break;
		}
		
		command1[0]='\0';
		command2[0]='\0';
		command3[0]='\0';
		command4[0]='\0';
		c_num1[0]='\0';
		c_num2[0]='\0';

		strcpy(command1, copy_command1);
		strcpy(command2, copy_command2);
		strcpy(command3, copy_command3);
		strcpy(command4, copy_command4);
	}
	return 0;
}

DWORD ShowMenu()
{
	DWORD sel;

	_fputts(_T("-----Menu----- \n"), stdout);
	_fputts(_T("num 1: Divide \n"), stdout);
	_fputts(_T("num 2: Multiple \n"), stdout);
	_fputts(_T("num 3: Add \n"), stdout);
	_fputts(_T("num 4: Minus \n"), stdout);
	_fputts(_T("num 5: Any other operations. \n"), stdout);
	_fputts(_T("num 6: Exit \n"), stdout);
	_fputts(_T("SELECTION >>"), stdout);
	_tscanf(_T("%d"), &sel);
	
	return sel;
}

