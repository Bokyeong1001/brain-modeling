
// DesimView.cpp: CDesimView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Desim.h"
#endif

#include "DesimDoc.h"
#include "DesimView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDesimView

IMPLEMENT_DYNCREATE(CDesimView, CEditView)

BEGIN_MESSAGE_MAP(CDesimView, CEditView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDesimView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SIMULATION_START, &CDesimView::OnSimulationStart)
END_MESSAGE_MAP()

// CDesimView 생성/소멸

CDesimView::CDesimView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDesimView::~CDesimView()
{
}

BOOL CDesimView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 자동 줄바꿈을 사용합니다.

	return bPreCreated;
}


// CDesimView 인쇄


void CDesimView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDesimView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 CEditView 준비
	return CEditView::OnPreparePrinting(pInfo);
}

void CDesimView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 기본 CEditView 시작 인쇄
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CDesimView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 기본 CEditView 종료 인쇄
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CDesimView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDesimView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDesimView 진단

#ifdef _DEBUG
void CDesimView::AssertValid() const
{
	CEditView::AssertValid();
}

void CDesimView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CDesimDoc* CDesimView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDesimDoc)));
	return (CDesimDoc*)m_pDocument;
}
#endif //_DEBUG


// CDesimView 메시지 처리기

#include "Tglobal.h"
void CDesimView::OnSimulationStart()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	MakeSES();
	StartSimulation();
}
