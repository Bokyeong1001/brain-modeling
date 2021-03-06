
// DesimView.h: CDesimView 클래스의 인터페이스
//

#pragma once


class CDesimView : public CEditView
{
protected: // serialization에서만 만들어집니다.
	CDesimView() noexcept;
	DECLARE_DYNCREATE(CDesimView)

// 특성입니다.
public:
	CDesimDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CDesimView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSimulationStart();
};

#ifndef _DEBUG  // DesimView.cpp의 디버그 버전
inline CDesimDoc* CDesimView::GetDocument() const
   { return reinterpret_cast<CDesimDoc*>(m_pDocument); }
#endif

