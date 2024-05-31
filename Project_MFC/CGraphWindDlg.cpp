// CGraphWindDlg.cpp: plik implementacji
//

#include "pch.h"
#include "Project_MFC.h"
#include "afxdialogex.h"
#include "CGraphWindDlg.h"


// Okno dialogowe CGraphWindDlg

IMPLEMENT_DYNAMIC(CGraphWindDlg, CDialogEx)

CGraphWindDlg::CGraphWindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GraphWindDlg, pParent)
{

}

CGraphWindDlg::~CGraphWindDlg()
{
}

void CGraphWindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COLOR_COMBO, ColorCombo);
	DDX_Control(pDX, IDC_LINE_TYPE_BUTTON, LineTypeButton);
	DDX_Control(pDX, IDC_RADIUS_SLIDER, RadiusSlider);
}


BEGIN_MESSAGE_MAP(CGraphWindDlg, CDialogEx)
	ON_CBN_EDITCHANGE(IDC_COLOR_COMBO, &CGraphWindDlg::OnCbnEditchangeColorCombo)
    ON_NOTIFY(NM_CUSTOMDRAW, IDC_RADIUS_SLIDER, &CGraphWindDlg::OnNMCustomdrawRadiusSlider)
    ON_BN_CLICKED(IDC_LINE_TYPE_BUTTON, &CGraphWindDlg::OnBnClickedLineTypeButton)
END_MESSAGE_MAP()


// Procedury obsługi komunikatów CGraphWindDlg


void CGraphWindDlg::OnCbnEditchangeColorCombo()
{
	// TODO: Dodaj tutaj swój kod procedury obsługi powiadamiania kontrolki
    int sel = ColorCombo.GetCurSel();
    switch (sel)
    {
    case 0:
        m_Color = RGB(255, 0, 0);
        break;
    case 1:
        m_Color = RGB(0, 255, 0);
        break;
    case 2:
        m_Color = RGB(0, 0, 255);
        break;
    default:
        m_Color = RGB(0, 0, 0);
        break;
    }
}


void CGraphWindDlg::OnNMCustomdrawRadiusSlider(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
    // TODO: Dodaj tutaj swój kod procedury obsługi powiadamiania kontrolki
    CString str;
    str.Format(_T("Radius: %d"), RadiusSlider.GetPos());
    SetWindowText(str);
    *pResult = 0;
}


void CGraphWindDlg::OnBnClickedLineTypeButton()
{
    // TODO: Dodaj tutaj swój kod procedury obsługi powiadamiania kontrolki
    m_LineType = !m_LineType;
    LineTypeButton.SetCheck(m_LineType ? BST_CHECKED : BST_UNCHECKED);
}
