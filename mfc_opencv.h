
// mfc_opencv.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cmfc_opencvApp:
// �йش����ʵ�֣������ mfc_opencv.cpp
//

class Cmfc_opencvApp : public CWinApp
{
public:
	Cmfc_opencvApp();

// ��д
public:
	virtual BOOL InitInstance();
	
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cmfc_opencvApp theApp;