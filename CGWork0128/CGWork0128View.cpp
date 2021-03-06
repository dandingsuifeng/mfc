
// CGWork0128View.cpp: CCGWork0128View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CGWork0128.h"
#endif

#include "CGWork0128Doc.h"
#include "CGWork0128View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCGWork0128View

IMPLEMENT_DYNCREATE(CCGWork0128View, CView)

BEGIN_MESSAGE_MAP(CCGWork0128View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCGWork0128View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCGWork0128View 构造/析构

CCGWork0128View::CCGWork0128View()
{
	// TODO: 在此处添加构造代码

}

CCGWork0128View::~CCGWork0128View()
{
}

BOOL CCGWork0128View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCGWork0128View 绘图

void CCGWork0128View::OnDraw(CDC* /*pDC*/)
{
	CCGWork0128Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCGWork0128View 打印


void CCGWork0128View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCGWork0128View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCGWork0128View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCGWork0128View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CCGWork0128View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCGWork0128View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCGWork0128View 诊断

#ifdef _DEBUG
void CCGWork0128View::AssertValid() const
{
	CView::AssertValid();
}

void CCGWork0128View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGWork0128Doc* CCGWork0128View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGWork0128Doc)));
	return (CCGWork0128Doc*)m_pDocument;
}
#endif //_DEBUG


// CCGWork0128View 消息处理程序
