#pragma once
#include "afxdialogex.h"


// Okno dialogowe CGraphWindDlg

class CGraphWindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphWindDlg)

public:
	CGraphWindDlg(CWnd* pParent = nullptr);   // konstruktor standardowy
	virtual ~CGraphWindDlg();

	COLORREF m_Color;
	int m_Radius;
	bool m_LineType;

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GraphWindDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // obsługa DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CComboBox ColorCombo;
	CButton LineTypeButton;
	CSliderCtrl RadiusSlider;
	afx_msg void OnCbnEditchangeColorCombo();
	afx_msg void OnNMCustomdrawRadiusSlider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedLineTypeButton();
};
