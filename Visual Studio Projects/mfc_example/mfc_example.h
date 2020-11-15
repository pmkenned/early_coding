// mfc_example.h : main header file for the mfc_example application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// Cmfc_exampleApp:
// See mfc_example.cpp for the implementation of this class
//

class Cmfc_exampleApp : public CWinApp
{
public:
	Cmfc_exampleApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cmfc_exampleApp theApp;