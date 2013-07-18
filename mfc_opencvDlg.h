
// mfc_opencvDlg.h : ͷ�ļ�
//

#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "facedect.h"
#include "CvvImage.h"
using namespace cv;
using namespace std;

#include "windows.h"
#include "tlhelp32.h"
void CloseProgram(CString strProgram)
{
    HANDLE handle; //����CreateToolhelp32Snapshotϵͳ���վ�� 
    HANDLE handle1; //����Ҫ�������̾�� 
    handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//���ϵͳ���վ�� 
    PROCESSENTRY32 *info; //����PROCESSENTRY32�ṹ��ָ 
    //PROCESSENTRY32 �ṹ�� dwSize ��Ա���ó� sizeof(PROCESSENTRY32) 

    info = new PROCESSENTRY32; 
    info->dwSize = sizeof(PROCESSENTRY32); 
    //����һ�� Process32First �������ӿ����л�ȡ�����б� 
    Process32First(handle, info); 
    //�ظ����� Process32Next��ֱ���������� FALSE Ϊֹ 
    while(Process32Next(handle, info) != FALSE) 
    {   
        CString strTmp = info->szExeFile;     //ָ���������   
        //strcmp�ַ����ȽϺ���ͬҪ������ͬ   
        //if(strcmp(c, info->szExeFile) == 0 )   
        if (strProgram.CompareNoCase(info->szExeFile) == 0 )   
        {   
            //PROCESS_TERMINATE��ʾΪ����������,FALSE=�ɼ̳�,info->th32ProcessID=����ID    
            handle1 = OpenProcess(PROCESS_TERMINATE, FALSE, info->th32ProcessID); 
            //��������    
            TerminateProcess(handle1, 0);    
        }   
    }
    delete info;

    CloseHandle(handle);
}

// Cmfc_opencvDlg �Ի���

class Cmfc_opencvDlg : public CDialogEx
{
// ����

public:
	Cmfc_opencvDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void OnClose()
	{
		
		CloseProgram(_T("mfc_opencv.exe"));
		CDialogEx::OnClose();
	}
// �Ի�������
	enum { IDD = IDD_MFC_OPENCV_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��



 



// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};

static CvHaarClassifierCascade* cascade = 0;
const char* cascade_name = 
"haarcascade_frontalface_alt.xml"; 

 double scale=2; 
    static CvScalar colors[] = { 
        {{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}}, 
        {{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}} 
    };//Just some pretty colors to draw with



 