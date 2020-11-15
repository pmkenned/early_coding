// mfc_exampleView.h : interface of the Cmfc_exampleView class
//


#pragma once


class Cmfc_exampleView : public CView
{
protected: // create from serialization only
	Cmfc_exampleView();
	DECLARE_DYNCREATE(Cmfc_exampleView)

// Attributes
public:
	Cmfc_exampleDoc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cmfc_exampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mfc_exampleView.cpp
inline Cmfc_exampleDoc* Cmfc_exampleView::GetDocument() const
   { return reinterpret_cast<Cmfc_exampleDoc*>(m_pDocument); }
#endif

