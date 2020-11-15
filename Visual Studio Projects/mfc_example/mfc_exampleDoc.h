// mfc_exampleDoc.h : interface of the Cmfc_exampleDoc class
//


#pragma once

class Cmfc_exampleDoc : public CDocument
{
protected: // create from serialization only
	Cmfc_exampleDoc();
	DECLARE_DYNCREATE(Cmfc_exampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~Cmfc_exampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


