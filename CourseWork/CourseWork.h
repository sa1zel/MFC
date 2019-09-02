
// CourseWork.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCourseWorkApp:
// О реализации данного класса см. CourseWork.cpp
//

class CCourseWorkApp : public CWinApp
{
public:
	CCourseWorkApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCourseWorkApp theApp;