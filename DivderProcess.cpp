#include <stdio.h>
#include <tchar.h>
#include <windows.h>


int _tmain(int argc, TCHAR* argv[])
{
	DWORD val1, val2;
	val1=_ttoi(argv[1]);
	val2=_ttoi(argv[2]);
	if(val2<=0){
		printf("�и� 0�����Դϴ�. �ٽð���ϼ���!\n");
	}
	else{
			_tprintf("int������ ���ǹǷ� �Ҽ����� �����˴ϴ�!\n");
			_tprintf(_T("%d / %d = %d \n"), val1, val2, val1/val2);
	}


	_gettchar(); //���α׷��� ������ ��� ���߱� ����. 
	return 0;
}

