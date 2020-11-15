// mfc_exampleView.cpp : implementation of the Cmfc_exampleView class
//

#include "stdafx.h"
#include "mfc_example.h"

#include "mfc_exampleDoc.h"
#include "mfc_exampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_exampleView

IMPLEMENT_DYNCREATE(Cmfc_exampleView, CView)

BEGIN_MESSAGE_MAP(Cmfc_exampleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cmfc_exampleView construction/destruction

Cmfc_exampleView::Cmfc_exampleView()
{
	// TODO: add construction code here

}

Cmfc_exampleView::~Cmfc_exampleView()
{
}

BOOL Cmfc_exampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cmfc_exampleView drawing

void Cmfc_exampleView::OnDraw(CDC* /*pDC*/)
{
	Cmfc_exampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cmfc_exampleView printing

BOOL Cmfc_exampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cmfc_exampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cmfc_exampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cmfc_exampleView diagnostics

#ifdef _DEBUG
void Cmfc_exampleView::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc_exampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc_exampleDoc* Cmfc_exampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc_exampleDoc)));
	return (Cmfc_exampleDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfc_exampleView message handlers
