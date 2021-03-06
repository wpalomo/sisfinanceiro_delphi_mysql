// CodeGear C++Builder
// Copyright (c) 1995, 2010 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'sPanel.pas' rev: 22.00

#ifndef SpanelHPP
#define SpanelHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <sCommonData.hpp>	// Pascal unit
#include <sConst.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Spanel
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TsPanel;
class PASCALIMPLEMENTATION TsPanel : public Extctrls::TPanel
{
	typedef Extctrls::TPanel inherited;
	
private:
	Scommondata::TsCommonData* FCommonData;
	Controls::TBevelCut FOldBevel;
	Sconst::TPaintEvent FOnPaint;
	
protected:
	virtual void __fastcall CopyCache(HDC DC);
	
public:
	__fastcall virtual TsPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TsPanel(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall OurPaint(HDC DC = (HDC)(0x0), bool SendUpdated = true);
	virtual bool __fastcall PrepareCache(void);
	void __fastcall PaintDragPanel(HDC DC);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall WriteText(const Types::TRect &R, Graphics::TCanvas* aCanvas = (Graphics::TCanvas*)(0x0), HDC aDC = (HDC)(0x0));
	virtual void __fastcall PaintWindow(HDC DC);
	
__published:
	__property Scommondata::TsCommonData* SkinData = {read=FCommonData, write=FCommonData};
	__property Sconst::TPaintEvent OnPaint = {read=FOnPaint, write=FOnPaint};
public:
	/* TWinControl.CreateParented */ inline __fastcall TsPanel(HWND ParentWindow) : Extctrls::TPanel(ParentWindow) { }
	
};


class DELPHICLASS TsDragBar;
class PASCALIMPLEMENTATION TsDragBar : public TsPanel
{
	typedef TsPanel inherited;
	
private:
	Controls::TControl* FDraggedControl;
	MESSAGE void __fastcall WMActivateApp(Messages::TWMActivateApp &Message);
	
protected:
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	
public:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	__fastcall virtual TsDragBar(Classes::TComponent* AOwner);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
__published:
	__property Alignment = {default=2};
	__property Align = {default=1};
	__property Color = {default=-16777214};
	__property Controls::TControl* DraggedControl = {read=FDraggedControl, write=FDraggedControl};
public:
	/* TsPanel.Destroy */ inline __fastcall virtual ~TsDragBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TsDragBar(HWND ParentWindow) : TsPanel(ParentWindow) { }
	
};


class DELPHICLASS TsContainer;
class PASCALIMPLEMENTATION TsContainer : public TsPanel
{
	typedef TsPanel inherited;
	
public:
	/* TsPanel.Create */ inline __fastcall virtual TsContainer(Classes::TComponent* AOwner) : TsPanel(AOwner) { }
	/* TsPanel.Destroy */ inline __fastcall virtual ~TsContainer(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TsContainer(HWND ParentWindow) : TsPanel(ParentWindow) { }
	
};


class DELPHICLASS TsGrip;
class PASCALIMPLEMENTATION TsGrip : public TsPanel
{
	typedef TsPanel inherited;
	
public:
	bool Transparent;
	Controls::TWinControl* LinkedControl;
	__fastcall virtual TsGrip(Classes::TComponent* AOwner);
	virtual void __fastcall Paint(void);
public:
	/* TsPanel.Destroy */ inline __fastcall virtual ~TsGrip(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TsGrip(HWND ParentWindow) : TsPanel(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TsColInfo
{
	
public:
	Graphics::TColor Color;
	Types::TRect R;
};


class DELPHICLASS TsColorsPanel;
class PASCALIMPLEMENTATION TsColorsPanel : public TsPanel
{
	typedef TsPanel inherited;
	
private:
	typedef System::DynamicArray<TsColInfo> _TsColorsPanel__1;
	
	
private:
	int FItemIndex;
	int FItemWidth;
	int FItemHeight;
	int FItemMargin;
	int FColCount;
	int FRowCount;
	Classes::TStrings* FColors;
	Classes::TNotifyEvent FOnChange;
	void __fastcall SetColors(const Classes::TStrings* Value);
	void __fastcall SetInteger(const int Index, const int Value);
	
public:
	int OldSelected;
	_TsColorsPanel__1 ColorsArray;
	__fastcall virtual TsColorsPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TsColorsPanel(void);
	void __fastcall GenerateColors(void);
	virtual void __fastcall AfterConstruction(void);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall OurPaint(HDC DC = (HDC)(0x0), bool SendUpdated = true);
	void __fastcall PaintColors(const HDC DC);
	int __fastcall Count(void);
	int __fastcall GetItemByCoord(const Types::TPoint &p);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	Graphics::TColor __fastcall ColorValue(void);
	
__published:
	__property Classes::TStrings* Colors = {read=FColors, write=SetColors};
	__property int ColCount = {read=FColCount, write=SetInteger, index=0, default=5};
	__property int ItemIndex = {read=FItemIndex, write=SetInteger, index=1, default=-1};
	__property int ItemHeight = {read=FItemHeight, write=SetInteger, index=2, default=21};
	__property int ItemWidth = {read=FItemWidth, write=SetInteger, index=3, default=21};
	__property int ItemMargin = {read=FItemMargin, write=SetInteger, index=4, default=6};
	__property int RowCount = {read=FRowCount, write=SetInteger, index=5, default=2};
	__property Height = {default=60};
	__property Width = {default=140};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TWinControl.CreateParented */ inline __fastcall TsColorsPanel(HWND ParentWindow) : TsPanel(ParentWindow) { }
	
};


class DELPHICLASS TsStdColorsPanel;
class PASCALIMPLEMENTATION TsStdColorsPanel : public TsColorsPanel
{
	typedef TsColorsPanel inherited;
	
public:
	/* TsColorsPanel.Create */ inline __fastcall virtual TsStdColorsPanel(Classes::TComponent* AOwner) : TsColorsPanel(AOwner) { }
	/* TsColorsPanel.Destroy */ inline __fastcall virtual ~TsStdColorsPanel(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TsStdColorsPanel(HWND ParentWindow) : TsColorsPanel(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Spanel */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE)
using namespace Spanel;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SpanelHPP
