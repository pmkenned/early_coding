// mfc_exampleDoc.cpp : implementation of the Cmfc_exampleDoc class
//

#include "stdafx.h"
#include "mfc_example.h"

#include "mfc_exampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_exampleDoc

IMPLEMENT_DYNCREATE(Cmfc_exampleDoc, CDocument)

BEGIN_MESSAGE_MAP(Cmfc_exampleDoc, CDocument)
END_MESSAGE_MAP()


// Cmfc_exampleDoc construction/destruction

Cmfc_exampleDoc::Cmfc_exampleDoc()
{
	// TODO: add one-time construction code here

}

Cmfc_exampleDoc::~Cmfc_exampleDoc()
{
}

BOOL Cmfc_exampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Cmfc_exampleDoc serialization

void Cmfc_exampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// Cmfc_exampleDoc diagnostics

#ifdef _DEBUG
void Cmfc_exampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cmfc_exampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cmfc_exampleDoc commands
