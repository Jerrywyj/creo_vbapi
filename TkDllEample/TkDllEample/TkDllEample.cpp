// TkDllEample.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "TkDllEample.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CTkDllEampleApp

BEGIN_MESSAGE_MAP(CTkDllEampleApp, CWinApp)
END_MESSAGE_MAP()

// CTkDllEampleApp ����

CTkDllEampleApp::CTkDllEampleApp()
{
    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CTkDllEampleApp ����

CTkDllEampleApp theApp;

// CTkDllEampleApp ��ʼ��

BOOL CTkDllEampleApp::InitInstance()
{
    CWinApp::InitInstance();
    return TRUE;
}

ProError ShowDialog(wchar_t *Message)
{
    ProUIMessageButton *buttons;
    ProUIMessageButton user_choice;
    ProArrayAlloc(1, sizeof(ProUIMessageButton), 1, (ProArray *)&buttons);
    buttons[0] = PRO_UI_MESSAGE_OK;
    ProUIMessageDialogDisplay(PROUIMESSAGE_INFO, L"Warning", Message, buttons, PRO_UI_MESSAGE_OK, &user_choice);
    ProArrayFree((ProArray *)&buttons);
    return PRO_TK_NO_ERROR;
}

extern "C" int user_initialize()
{
    ProError status;
    status = ShowDialog(L"����������");
    return PRO_TK_NO_ERROR;
}
extern "C" void user_terminate()
{
    ProError status;
    status = ShowDialog(L"�������˳�");
}

//����һ��Intֵ��������ƽ����
extern "C" PRO_TK_DLL_EXPORT ProError MyPow(ProArgument *input_args, ProArgument **output_args)
{
    ProError status;
    int inputargs = 0;
    ProArgument arg;
	//ȷ��������ȷ�Ĳ�����һ����������������Ϊ����
    status = ProArraySizeGet(input_args, &inputargs);
    if (inputargs != 1)
        return PRO_TK_INVALID_ITEM;
    if (input_args[0].value.type != PRO_VALUE_TYPE_INT)
        return PRO_TK_INVALID_ITEM;
	//���뷵��ֵ�ڴ�ռ䣬ֻ����һ������ֵ
    status = ProArrayAlloc(0, sizeof(ProArgument), 1, (ProArray *)output_args);
    if (status == PRO_TK_NO_ERROR)
    {
        arg.value.type = PRO_VALUE_TYPE_INT;
        arg.value.v.i = input_args[0].value.v.i * input_args[0].value.v.i;
        ProArrayObjectAdd((ProArray *)output_args, -1, 1, &arg);
        return PRO_TK_NO_ERROR;
    }
    else
        return PRO_TK_GENERAL_ERROR;
    return PRO_TK_NO_ERROR;
}
