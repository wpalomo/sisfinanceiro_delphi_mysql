// CodeGear C++Builder
// Copyright (c) 1995, 2010 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'acTitleBar.pas' rev: 22.00

#ifndef ActitlebarHPP
#define ActitlebarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <sConst.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Actitlebar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TacTitleBarItem;
typedef void __fastcall (__closure *TacDrawItemEvent)(TacTitleBarItem* Item, const Types::TRect &R, Graphics::TBitmap* Bmp);

class DELPHICLASS TacItemAnimation;
class PASCALIMPLEMENTATION TacItemAnimation : public Extctrls::TTimer
{
	typedef Extctrls::TTimer inherited;
	
public:
	int CurrentLevel;
	int CurrentState;
	int MaxIterations;
	Forms::TForm* AForm;
	Forms::TForm* OldForm;
	HWND FormHandle;
	TacTitleBarItem* Item;
	bool ToShow;
	Graphics::TBitmap* NewBmp;
	__fastcall virtual TacItemAnimation(Classes::TComponent* AOwner);
	__fastcall virtual ~TacItemAnimation(void);
	Types::TRect __fastcall GetFormBounds(void);
	int __fastcall Offset(void);
	int __fastcall Step(void);
	void __fastcall MakeForm(void);
	void __fastcall UpdateForm(int Blend);
	void __fastcall StartAnimation(int NewState, bool Show);
	void __fastcall ChangeState(int NewState, bool Show);
	void __fastcall MakeImg(void);
	void __fastcall CheckMouseLeave(void);
	void __fastcall OnAnimTimer(System::TObject* Sender);
};


class DELPHICLASS TacFontData;
class PASCALIMPLEMENTATION TacFontData : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FUseSysSize;
	bool FUseSysStyle;
	bool FUseSysColor;
	bool FUseSysGlowing;
	bool FUseSysFontName;
	Graphics::TFont* FFont;
	HWND WndHandle;
	int FGlowSize;
	Graphics::TColor FGlowColor;
	bool __fastcall GetBool(const int Index);
	void __fastcall SetBool(const int Index, const bool Value);
	void __fastcall SetFont(const Graphics::TFont* Value);
	void __fastcall SetGlowSize(const int Value);
	void __fastcall SetGlowColor(const Graphics::TColor Value);
	
public:
	Graphics::TFont* UsedFont;
	Graphics::TBitmap* GlowMask;
	__fastcall TacFontData(void);
	__fastcall virtual ~TacFontData(void);
	void __fastcall Invalidate(void);
	
__published:
	__property Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property Graphics::TColor GlowColor = {read=FGlowColor, write=SetGlowColor, default=8421504};
	__property int GlowSize = {read=FGlowSize, write=SetGlowSize, default=0};
	__property bool UseSysColor = {read=GetBool, write=SetBool, index=0, default=1};
	__property bool UseSysFontName = {read=GetBool, write=SetBool, index=1, default=1};
	__property bool UseSysGlowing = {read=GetBool, write=SetBool, index=2, default=1};
	__property bool UseSysSize = {read=GetBool, write=SetBool, index=3, default=1};
	__property bool UseSysStyle = {read=GetBool, write=SetBool, index=4, default=1};
};


#pragma option push -b-
enum TacBtnStyle { bsButton, bsMenu, bsTab, bsSpacing, bsInfo };
#pragma option pop

#pragma option push -b-
enum TacItemAlign { tbaLeft, tbaRight, tbaCenter, tbaCenterInSpace };
#pragma option pop

class PASCALIMPLEMENTATION TacTitleBarItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Graphics::TBitmap* FGlyph;
	Graphics::TBitmap* FDefaultMenuBtn;
	bool FEnabled;
	bool FVisible;
	bool FAutoSize;
	bool FShowHint;
	bool FDroppedDown;
	System::UnicodeString FHint;
	System::UnicodeString FCaption;
	Controls::TMouseEvent FOnMouseUp;
	Controls::TMouseEvent FOnMouseDown;
	Classes::TNotifyEvent FOnClick;
	Classes::TNotifyEvent FOnChanged;
	Classes::TNotifyEvent FOnMouseLeave;
	Classes::TNotifyEvent FOnMouseEnter;
	int FWidth;
	int FHeight;
	int FSpacing;
	int FNumGlyphs;
	int FImageIndex;
	int FGroupIndex;
	System::UnicodeString FName;
	TacBtnStyle FStyle;
	tagSIZE FContentSize;
	TacItemAlign FAlign;
	TacFontData* FFontData;
	Menus::TPopupMenu* FDropdownMenu;
	TacDrawItemEvent FOnDrawItem;
	Classes::TAlignment FAlignment;
	int FHotImageIndex;
	int FPressedImageIndex;
	int FDisabledImageIndex;
	System::UnicodeString FSkinSection;
	void __fastcall SetSkinSection(const System::UnicodeString Value);
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	void __fastcall SetGlyph(const Graphics::TBitmap* Value);
	void __fastcall SetName(const System::UnicodeString Value);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetAlign(const TacItemAlign Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetGroupIndex(const int Value);
	void __fastcall SetNumGlyphs(const int Value);
	void __fastcall SetStyle(const TacBtnStyle Value);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall SetAutoSize(const bool Value);
	void __fastcall SetDown(const bool Value);
	void __fastcall SetSpacing(const int Value);
	void __fastcall SetState(const int Value);
	void __fastcall SetImageIndex(const int AIndex, const int Value);
	int __fastcall GetState(void);
	void __fastcall OnGlyphChange(System::TObject* Sender);
	
protected:
	bool FDown;
	int FState;
	bool FPressed;
	
public:
	Controls::THintWindow* HintWnd;
	Types::TRect Rect;
	System::TObject* *Data;
	TacItemAnimation* Timer;
	Forms::TForm* ExtForm;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	__fastcall virtual TacTitleBarItem(Classes::TCollection* ACollection);
	__fastcall virtual ~TacTitleBarItem(void);
	void __fastcall InitFont(void);
	void __fastcall DoMouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall DoMouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall DoClick(void);
	HIDESBASE void __fastcall Changed(void);
	void __fastcall UpdateSize(bool ContentOnly = false);
	void __fastcall Invalidate(bool RecalcSize = false);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	int __fastcall IntXMargin(void);
	__property Graphics::TBitmap* DefaultMenuBtn = {read=FDefaultMenuBtn};
	__property bool DroppedDown = {read=FDroppedDown, nodefault};
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, nodefault};
	__property tagSIZE ContentSize = {read=FContentSize};
	__property bool Pressed = {read=FPressed, nodefault};
	__property int State = {read=GetState, write=SetState, nodefault};
	__property TacDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property TacItemAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property Menus::TPopupMenu* DropdownMenu = {read=FDropdownMenu, write=FDropdownMenu};
	__property bool Down = {read=FDown, write=SetDown, default=0};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property TacFontData* FontData = {read=FFontData, write=FFontData};
	__property Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property int Height = {read=FHeight, write=SetHeight, default=18};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
	__property int DisabledImageIndex = {read=FDisabledImageIndex, write=SetImageIndex, index=0, default=-1};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, index=1, default=-1};
	__property int HotImageIndex = {read=FHotImageIndex, write=SetImageIndex, index=2, default=-1};
	__property int PressedImageIndex = {read=FPressedImageIndex, write=SetImageIndex, index=3, default=-1};
	__property Index;
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property int NumGlyphs = {read=FNumGlyphs, write=SetNumGlyphs, default=1};
	__property bool ShowHint = {read=FShowHint, write=FShowHint, nodefault};
	__property System::UnicodeString SkinSection = {read=FSkinSection, write=SetSkinSection};
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=4};
	__property TacBtnStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=22};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	__property Controls::TMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property Controls::TMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
};


class DELPHICLASS TacTitleItems;
class DELPHICLASS TsTitleBar;
class PASCALIMPLEMENTATION TacTitleItems : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TacTitleBarItem* operator[](int Index) { return Items[Index]; }
	
private:
	TsTitleBar* FOwner;
	HIDESBASE TacTitleBarItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TacTitleBarItem* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TacTitleItems(Classes::TPersistent* AOwner);
	__fastcall virtual ~TacTitleItems(void);
	HIDESBASE TacTitleBarItem* __fastcall Add(void);
	HIDESBASE TacTitleBarItem* __fastcall Insert(int Index);
	__property TacTitleBarItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


class PASCALIMPLEMENTATION TsTitleBar : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
private:
	int FLeftWidth;
	int FRightWidth;
	int FItemsMargin;
	int FCenterWidth;
	int FCenterWidthS;
	int FItemsSpacing;
	Forms::TForm* Form;
	Types::TRect FCaptionRect;
	TacTitleItems* FItems;
	bool FShowCaption;
	Imglist::TCustomImageList* FImages;
	Imglist::TChangeLink* FImageChangeLink;
	void __fastcall SetItems(const TacTitleItems* Value);
	void __fastcall SetItemsMargin(const int Value);
	void __fastcall SetItemsSpacing(const int Value);
	void __fastcall SetImages(const Imglist::TCustomImageList* Value);
	void __fastcall SetShowCaption(const bool Value);
	
protected:
	int FFullRight;
	int FBarVCenter;
	Types::TRect FBarRect;
	bool FUpdating;
	void __fastcall ImageListChange(System::TObject* Sender);
	
public:
	Graphics::TBitmap* FDefaultMenuBtn;
	void __fastcall CalcSizes(void);
	__fastcall virtual TsTitleBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TsTitleBar(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall Invalidate(void);
	__property Types::TRect BarRect = {read=FBarRect};
	__property Types::TRect CaptionRect = {read=FCaptionRect};
	__property int LeftWidth = {read=FLeftWidth, nodefault};
	__property int RightWidth = {read=FRightWidth, nodefault};
	
__published:
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TacTitleItems* Items = {read=FItems, write=SetItems};
	__property int ItemsMargin = {read=FItemsMargin, write=SetItemsMargin, default=3};
	__property int ItemsSpacing = {read=FItemsSpacing, write=SetItemsSpacing, default=0};
	__property bool ShowCaption = {read=FShowCaption, write=SetShowCaption, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const System::WideChar acDownChar = (System::WideChar)(0x75);
#define acDownFont L"Marlett"
extern PACKAGE void __fastcall StartItemAnimation(const TacTitleBarItem* Item, const int Iterations, const bool Show, Forms::TForm* ExtendedForm = (Forms::TForm*)(0x0));
extern PACKAGE void __fastcall ShowHintWnd(TacTitleBarItem* Item);
extern PACKAGE void __fastcall HideHintWnd(TacTitleBarItem* Item);
extern PACKAGE void __fastcall PaintItemNoAlpha(const Graphics::TBitmap* DstBmp, const Graphics::TBitmap* SrcBmp, const Types::TRect &DstRect, const Types::TRect &SrcRect, const Types::TRect &BorderWidths);

}	/* namespace Actitlebar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE)
using namespace Actitlebar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ActitlebarHPP
