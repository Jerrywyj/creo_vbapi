// TkDllEample.h : TkDllEample DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTkDllEampleApp
// �йش���ʵ�ֵ���Ϣ������� TkDllEample.cpp
//

class CTkDllEampleApp : public CWinApp
{
public:
	CTkDllEampleApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern "C" PRO_TK_DLL_EXPORT ProError MyPow(ProArgument* input_args, ProArgument** output_args);