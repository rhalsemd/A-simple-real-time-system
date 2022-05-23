#include <stdio.h>
#include <tchar.h>
#include <windows.h>


int _tmain(int argc, TCHAR* argv[])
{
	DWORD val1, val2;
	val1=_ttoi(argv[1]);
	val2=_ttoi(argv[2]);
	if(val2<=0){
		printf("분모가 0이하입니다. 다시계산하세요!\n");
	}
	else{
			_tprintf("int형으로 계산되므로 소수점은 생략됩니다!\n");
			_tprintf(_T("%d / %d = %d \n"), val1, val2, val1/val2);
	}


	_gettchar(); //프로그램의 실행을 잠시 멈추기 위해. 
	return 0;
}

