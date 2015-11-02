// CodeGear C++Builder
// Copyright (c) 1995, 2010 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'sSkinManager.pas' rev: 22.00

#ifndef SskinmanagerHPP
#define SskinmanagerHPP

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
#include <Dialogs.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <sConst.hpp>	// Pascal unit
#include <sMaskData.hpp>	// Pascal unit
#include <sSkinMenus.hpp>	// Pascal unit
#include <sStyleSimply.hpp>	// Pascal unit
#include <sDefaults.hpp>	// Pascal unit
#include <acntUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sskinmanager
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TacSkinData
{
	
public:
	int Magic;
	System::StaticArray<char, 128> SkinName;
	System::StaticArray<char, 512> SkinDir;
	System::StaticArray<char, 30001> Data;
};
#pragma pack(pop)


typedef TacSkinData *PacSkinData;

#pragma option push -b-
enum TacSkinTypes { stUnpacked, stPacked, stAllSkins };
#pragma option pop

#pragma option push -b-
enum TacSkinPlaces { spInternal, spExternal, spAllPlaces };
#pragma option pop

typedef void __fastcall (__closure *TacGetExtraLineData)(Menus::TMenuItem* FirstItem, System::UnicodeString &SkinSection, System::UnicodeString &Caption, Graphics::TBitmap* &Glyph, bool &LineVisible);

struct DECLSPEC_DRECORD TacMenuItemData
{
	
public:
	Graphics::TFont* Font;
};


struct DECLSPEC_DRECORD TacSysDlgData
{
	
public:
	unsigned WindowHandle;
};


typedef void __fastcall (__closure *TacSysDlgInit)(TacSysDlgData DlgData, bool &AllowSkinning);

typedef void __fastcall (__closure *TacGetPopupItemData)(Menus::TMenuItem* Item, Windows::TOwnerDrawState State, TacMenuItemData ItemData);

struct DECLSPEC_DRECORD TacExtFileData
{
	
public:
	Graphics::TBitmap* Bmp;
	System::UnicodeString FileName;
	int MaskType;
};


typedef System::DynamicArray<TacExtFileData> TacExtArray;

;

typedef System::UnicodeString TacSkinInfo;

class DELPHICLASS TacSkinEffects;
class DELPHICLASS TsSkinManager;
class PASCALIMPLEMENTATION TacSkinEffects : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FAllowGlowing;
	bool FAllowAnimation;
	bool FAllowAeroBluring;
	bool FDiscoloredGlyphs;
	bool FAllowOuterEffects;
	void __fastcall SetDiscoloredGlyphs(const bool Value);
	void __fastcall SetAllowOuterEffects(const bool Value);
	
public:
	TsSkinManager* Manager;
	__fastcall TacSkinEffects(void);
	
__published:
	__property bool AllowAnimation = {read=FAllowAnimation, write=FAllowAnimation, default=1};
	__property bool AllowAeroBluring = {read=FAllowAeroBluring, write=FAllowAeroBluring, default=1};
	__property bool AllowGlowing = {read=FAllowGlowing, write=FAllowGlowing, default=1};
	__property bool AllowOuterEffects = {read=FAllowOuterEffects, write=SetAllowOuterEffects, default=0};
	__property bool DiscoloredGlyphs = {read=FDiscoloredGlyphs, write=SetDiscoloredGlyphs, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacSkinEffects(void) { }
	
};


class DELPHICLASS TacBtnEffects;
class PASCALIMPLEMENTATION TacBtnEffects : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	Sconst::TacBtnEvents FEvents;
	
public:
	__fastcall TacBtnEffects(void);
	
__published:
	__property Sconst::TacBtnEvents Events = {read=FEvents, write=FEvents, default=15};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacBtnEffects(void) { }
	
};


class DELPHICLASS TacFormAnimation;
class PASCALIMPLEMENTATION TacFormAnimation : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	System::Word FTime;
	bool FActive;
	Sconst::TacAnimType FMode;
	
public:
	__fastcall virtual TacFormAnimation(void);
	__property Sconst::TacAnimType Mode = {read=FMode, write=FMode, default=1};
	
__published:
	__property bool Active = {read=FActive, write=FActive, default=1};
	__property System::Word Time = {read=FTime, write=FTime, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacFormAnimation(void) { }
	
};


class DELPHICLASS TacBlendOnMoving;
class PASCALIMPLEMENTATION TacBlendOnMoving : public TacFormAnimation
{
	typedef TacFormAnimation inherited;
	
private:
	System::Byte FBlendValue;
	
public:
	__fastcall virtual TacBlendOnMoving(void);
	
__published:
	__property Active = {default=0};
	__property System::Byte BlendValue = {read=FBlendValue, write=FBlendValue, default=170};
	__property Time = {default=1000};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacBlendOnMoving(void) { }
	
};


class DELPHICLASS TacMinimizing;
class PASCALIMPLEMENTATION TacMinimizing : public TacFormAnimation
{
	typedef TacFormAnimation inherited;
	
public:
	__fastcall virtual TacMinimizing(void);
	
__published:
	__property Time = {default=120};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacMinimizing(void) { }
	
};


class DELPHICLASS TacFormShow;
class PASCALIMPLEMENTATION TacFormShow : public TacFormAnimation
{
	typedef TacFormAnimation inherited;
	
__published:
	__property Mode = {default=1};
public:
	/* TacFormAnimation.Create */ inline __fastcall virtual TacFormShow(void) : TacFormAnimation() { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacFormShow(void) { }
	
};


class DELPHICLASS TacFormHide;
class PASCALIMPLEMENTATION TacFormHide : public TacFormAnimation
{
	typedef TacFormAnimation inherited;
	
__published:
	__property Mode = {default=1};
public:
	/* TacFormAnimation.Create */ inline __fastcall virtual TacFormHide(void) : TacFormAnimation() { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacFormHide(void) { }
	
};


class DELPHICLASS TacPageChange;
class PASCALIMPLEMENTATION TacPageChange : public TacFormAnimation
{
	typedef TacFormAnimation inherited;
	
public:
	/* TacFormAnimation.Create */ inline __fastcall virtual TacPageChange(void) : TacFormAnimation() { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacPageChange(void) { }
	
};


class DELPHICLASS TacDialogShow;
class PASCALIMPLEMENTATION TacDialogShow : public TacFormAnimation
{
	typedef TacFormAnimation inherited;
	
public:
	__fastcall virtual TacDialogShow(void);
	
__published:
	__property Time = {default=0};
	__property Mode = {default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacDialogShow(void) { }
	
};


class DELPHICLASS TacSkinChanging;
class PASCALIMPLEMENTATION TacSkinChanging : public TacFormAnimation
{
	typedef TacFormAnimation inherited;
	
public:
	__fastcall virtual TacSkinChanging(void);
	
__published:
	__property Time = {default=100};
	__property Mode = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacSkinChanging(void) { }
	
};


class DELPHICLASS TacAnimEffects;
class PASCALIMPLEMENTATION TacAnimEffects : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	TacFormHide* FFormHide;
	TacFormHide* FDialogHide;
	TacBtnEffects* FButtons;
	TacFormShow* FFormShow;
	TacPageChange* FPageChange;
	TacMinimizing* FMinimizing;
	TacDialogShow* FDialogShow;
	TacSkinChanging* FSkinChanging;
	TacBlendOnMoving* FBlendOnMoving;
	
public:
	TsSkinManager* Manager;
	__fastcall TacAnimEffects(void);
	__fastcall virtual ~TacAnimEffects(void);
	
__published:
	__property TacBlendOnMoving* BlendOnMoving = {read=FBlendOnMoving, write=FBlendOnMoving};
	__property TacBtnEffects* Buttons = {read=FButtons, write=FButtons};
	__property TacDialogShow* DialogShow = {read=FDialogShow, write=FDialogShow};
	__property TacFormShow* FormShow = {read=FFormShow, write=FFormShow};
	__property TacFormHide* FormHide = {read=FFormHide, write=FFormHide};
	__property TacFormHide* DialogHide = {read=FDialogHide, write=FDialogHide};
	__property TacMinimizing* Minimizing = {read=FMinimizing, write=FMinimizing};
	__property TacPageChange* PageChange = {read=FPageChange, write=FPageChange};
	__property TacSkinChanging* SkinChanging = {read=FSkinChanging, write=FSkinChanging};
};


class DELPHICLASS TsStoredSkin;
class PASCALIMPLEMENTATION TsStoredSkin : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	System::UnicodeString FAuthor;
	System::UnicodeString FDescription;
	int FShadow1Blur;
	int FShadow1Offset;
	int FShadow1Transparency;
	Graphics::TColor FBorderColor;
	Graphics::TColor FShadow1Color;
	double FVersion;
	Graphics::TBitmap* FMasterBitmap;
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall ReadData(Classes::TStream* Reader);
	void __fastcall WriteData(Classes::TStream* Writer);
	
public:
	Classes::TMemoryStream* PackedData;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__fastcall virtual TsStoredSkin(Classes::TCollection* ACollection);
	__fastcall virtual ~TsStoredSkin(void);
	
__published:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property Graphics::TBitmap* MasterBitmap = {read=FMasterBitmap, write=FMasterBitmap};
	__property Graphics::TColor Shadow1Color = {read=FShadow1Color, write=FShadow1Color, nodefault};
	__property int Shadow1Offset = {read=FShadow1Offset, write=FShadow1Offset, nodefault};
	__property int Shadow1Blur = {read=FShadow1Blur, write=FShadow1Blur, default=-1};
	__property int Shadow1Transparency = {read=FShadow1Transparency, write=FShadow1Transparency, nodefault};
	__property Graphics::TColor BorderColor = {read=FBorderColor, write=FBorderColor, default=16711935};
	__property double Version = {read=FVersion, write=FVersion};
	__property System::UnicodeString Author = {read=FAuthor, write=FAuthor};
	__property System::UnicodeString Description = {read=FDescription, write=FDescription};
};


class DELPHICLASS TsStoredSkins;
class PASCALIMPLEMENTATION TsStoredSkins : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TsStoredSkin* operator[](int Index) { return Items[Index]; }
	
private:
	TsSkinManager* FOwner;
	HIDESBASE TsStoredSkin* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TsStoredSkin* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__fastcall TsStoredSkins(TsSkinManager* AOwner);
	__fastcall virtual ~TsStoredSkins(void);
	__property TsStoredSkin* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	int __fastcall IndexOf(const System::UnicodeString SkinName);
};


class DELPHICLASS ThirdPartyList;
class PASCALIMPLEMENTATION ThirdPartyList : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	System::UnicodeString FThirdEdits;
	System::UnicodeString FThirdButtons;
	System::UnicodeString FThirdBitBtns;
	System::UnicodeString FThirdCheckBoxes;
	System::UnicodeString FThirdGroupBoxes;
	System::UnicodeString FThirdListViews;
	System::UnicodeString FThirdPanels;
	System::UnicodeString FThirdGrids;
	System::UnicodeString FThirdTreeViews;
	System::UnicodeString FThirdComboBoxes;
	System::UnicodeString FThirdWWEdits;
	System::UnicodeString FThirdVirtualTrees;
	System::UnicodeString FThirdGridEh;
	System::UnicodeString FThirdPageControl;
	System::UnicodeString FThirdTabControl;
	System::UnicodeString FThirdToolBar;
	System::UnicodeString FThirdStatusBar;
	System::UnicodeString FThirdSpeedButton;
	System::UnicodeString FThirdScrollControl;
	System::UnicodeString FThirdUpDownBtn;
	System::UnicodeString FThirdScrollBar;
	System::UnicodeString FThirdStaticText;
	System::UnicodeString FThirdNativePaint;
	
public:
	System::UnicodeString __fastcall GetString(const int Index);
	void __fastcall SetString(const int Index, const System::UnicodeString Value);
	
__published:
	__property System::UnicodeString ThirdEdits = {read=GetString, write=SetString, index=0};
	__property System::UnicodeString ThirdButtons = {read=GetString, write=SetString, index=1};
	__property System::UnicodeString ThirdBitBtns = {read=GetString, write=SetString, index=2};
	__property System::UnicodeString ThirdCheckBoxes = {read=GetString, write=SetString, index=3};
	__property System::UnicodeString ThirdGroupBoxes = {read=GetString, write=SetString, index=6};
	__property System::UnicodeString ThirdListViews = {read=GetString, write=SetString, index=7};
	__property System::UnicodeString ThirdPanels = {read=GetString, write=SetString, index=8};
	__property System::UnicodeString ThirdGrids = {read=GetString, write=SetString, index=5};
	__property System::UnicodeString ThirdTreeViews = {read=GetString, write=SetString, index=9};
	__property System::UnicodeString ThirdComboBoxes = {read=GetString, write=SetString, index=4};
	__property System::UnicodeString ThirdWWEdits = {read=GetString, write=SetString, index=10};
	__property System::UnicodeString ThirdVirtualTrees = {read=GetString, write=SetString, index=12};
	__property System::UnicodeString ThirdGridEh = {read=GetString, write=SetString, index=11};
	__property System::UnicodeString ThirdPageControl = {read=GetString, write=SetString, index=13};
	__property System::UnicodeString ThirdTabControl = {read=GetString, write=SetString, index=14};
	__property System::UnicodeString ThirdToolBar = {read=GetString, write=SetString, index=15};
	__property System::UnicodeString ThirdStatusBar = {read=GetString, write=SetString, index=16};
	__property System::UnicodeString ThirdSpeedButton = {read=GetString, write=SetString, index=17};
	__property System::UnicodeString ThirdScrollControl = {read=GetString, write=SetString, index=18};
	__property System::UnicodeString ThirdUpDown = {read=GetString, write=SetString, index=19};
	__property System::UnicodeString ThirdScrollBar = {read=GetString, write=SetString, index=20};
	__property System::UnicodeString ThirdStaticText = {read=GetString, write=SetString, index=21};
	__property System::UnicodeString ThirdNativePaint = {read=GetString, write=SetString, index=22};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~ThirdPartyList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall ThirdPartyList(void) : Classes::TPersistent() { }
	
};


#pragma option push -b-
enum TacSkinningRule { srStdForms, srStdDialogs, srThirdParty };
#pragma option pop

typedef System::Set<TacSkinningRule, TacSkinningRule::srStdForms, TacSkinningRule::srThirdParty>  TacSkinningRules;

#pragma option push -b-
enum TacPaletteColors { pcMainColor, pcLabelText, pcWebText, pcWebTextHot, pcEditText, pcEditBG, pcSelectionBG, pcSelectionText, pcSelectionBG_Focused, pcSelectionText_Focused, pcEditBG_Inverted, pcEditText_Inverted, pcEditBG_OddRow, pcEditBG_EvenRow, pcEditText_Ok, pcEditText_Warning, pcEditText_Alert, pcEditText_Caution, pcEditText_Bypassed, pcEditBG_Ok, pcEditBG_Warning, pcEditBG_Alert, pcEditBG_Caution, pcEditBG_Bypassed, pcEditText_Highlight1, pcEditText_Highlight2, pcEditText_Highlight3, pcBorder };
#pragma option pop

typedef System::StaticArray<Graphics::TColor, 28> TacPaletteArray;

class DELPHICLASS TacScrollBarsSupport;
class PASCALIMPLEMENTATION TacScrollBarsSupport : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	int FScrollSize;
	int FButtonsSize;
	TsSkinManager* FOwner;
	void __fastcall SetScrollSize(const int Value);
	void __fastcall SetButtonsSize(const int Value);
	
public:
	__fastcall TacScrollBarsSupport(TsSkinManager* AOwner);
	
__published:
	__property int ScrollSize = {read=FScrollSize, write=SetScrollSize, default=-1};
	__property int ButtonsSize = {read=FButtonsSize, write=SetButtonsSize, default=-1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacScrollBarsSupport(void) { }
	
};


class DELPHICLASS TacButtonsSupport;
class PASCALIMPLEMENTATION TacButtonsSupport : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FShowFocusRect;
	bool FShiftContentOnClick;
	
public:
	__fastcall TacButtonsSupport(TsSkinManager* AOwner);
	
__published:
	__property bool ShowFocusRect = {read=FShowFocusRect, write=FShowFocusRect, default=1};
	__property bool ShiftContentOnClick = {read=FShiftContentOnClick, write=FShiftContentOnClick, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacButtonsSupport(void) { }
	
};


class DELPHICLASS TacLabelsSupport;
class PASCALIMPLEMENTATION TacLabelsSupport : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FTransparentAlways;
	
public:
	__fastcall TacLabelsSupport(TsSkinManager* AOwner);
	
__published:
	__property bool TransparentAlways = {read=FTransparentAlways, write=FTransparentAlways, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacLabelsSupport(void) { }
	
};


class DELPHICLASS TacOptions;
class PASCALIMPLEMENTATION TacOptions : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FNoMouseHover;
	bool FStdGlyphsOrder;
	bool FCheckEmptyAlpha;
	bool FChangeSysColors;
	bool FNativeBordersMaximized;
	TsSkinManager* FOwner;
	Sconst::TacOptimizingPriority FOptimizingPriority;
	bool __fastcall GetBool(const int Index);
	void __fastcall SetBool(const int Index, const bool Value);
	
public:
	__fastcall TacOptions(TsSkinManager* AOwner);
	
__published:
	__property bool NoMouseHover = {read=GetBool, write=SetBool, index=1, default=0};
	__property bool StdGlyphsOrder = {read=GetBool, write=SetBool, index=3, default=0};
	__property bool ChangeSysColors = {read=GetBool, write=SetBool, index=4, default=0};
	__property bool CheckEmptyAlpha = {read=GetBool, write=SetBool, index=0, default=0};
	__property bool NativeBordersMaximized = {read=GetBool, write=SetBool, index=2, default=0};
	__property Sconst::TacOptimizingPriority OptimizingPriority = {read=FOptimizingPriority, write=FOptimizingPriority, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TacOptions(void) { }
	
};


struct DECLSPEC_DRECORD TacImageItem
{
	
public:
	System::UnicodeString FileName;
	bool IsBitmap;
	Classes::TMemoryStream* FileStream;
};


typedef System::DynamicArray<TacImageItem> TacImageItems;

class DELPHICLASS TacSkinConvertor;
class PASCALIMPLEMENTATION TacSkinConvertor : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
public:
	Classes::TMemoryStream* Options;
	Classes::TMemoryStream* PackedData;
	int ImageCount;
	TacImageItems Files;
	void __fastcall Clear(void);
	__fastcall virtual ~TacSkinConvertor(void);
public:
	/* TObject.Create */ inline __fastcall TacSkinConvertor(void) : Classes::TPersistent() { }
	
};


typedef System::StaticArray<char, 16> TsCharArray;

class PASCALIMPLEMENTATION TsSkinManager : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	bool FSkinnedPopups;
	bool FExtendedBorders;
	bool GlobalHookInstalled;
	Classes::TNotifyEvent FOnActivate;
	Classes::TNotifyEvent FOnDeactivate;
	Classes::TNotifyEvent FOnSkinLoading;
	Classes::TNotifyEvent FOnAfterChange;
	Classes::TNotifyEvent FOnBeforeChange;
	Classes::TNotifyEvent FOnSkinListChanged;
	Classes::TStringList* FKeyList;
	Classes::TStringList* FCommonSections;
	System::UnicodeString FSkinName;
	System::UnicodeString FSkinDirectory;
	TsStoredSkins* FBuiltInSkins;
	TacOptions* FOptions;
	TacExtArray ExtArray;
	int FGroupIndex;
	Sskinmenus::TacMenuSupport* FMenuSupport;
	TacAnimEffects* FAnimEffects;
	HWND FActiveControl;
	TacSkinningRules FSkinningRules;
	ThirdPartyList* FThirdParty;
	TacSkinEffects* FEffects;
	TacScrollBarsSupport* FScrollsOptions;
	TacButtonsSupport* FButtonsSupport;
	TacLabelsSupport* FLabelsSupport;
	TacGetExtraLineData FOnGetPopupLineData;
	TacGetPopupItemData FOnGetPopupItemData;
	TacSysDlgInit FOnSysDlgInit;
	Sskinmenus::TsSkinableMenus* FSkinableMenus;
	void __fastcall ClearExtArray(void);
	Graphics::TBitmap* __fastcall SearchExtFile(System::UnicodeString s);
	void __fastcall SetSkinnedPopups(const bool Value);
	System::UnicodeString __fastcall GetVersion(void);
	TacSkinInfo __fastcall GetSkinInfo(void);
	void __fastcall UpdateCurrentSkin(void);
	bool __fastcall GetIsDefault(void);
	bool __fastcall MainWindowHook(Messages::TMessage &Message);
	bool __fastcall GetExtendedBorders(void);
	void __fastcall SetSkinName(const System::UnicodeString Value);
	void __fastcall SetSkinDirectory(const System::UnicodeString Value);
	void __fastcall SetActive(const bool Value);
	void __fastcall SetBuiltInSkins(const TsStoredSkins* Value);
	void __fastcall SetVersion(const System::UnicodeString Value);
	void __fastcall SetSkinInfo(const TacSkinInfo Value);
	void __fastcall SetHueOffset(const int Value);
	void __fastcall SetBrightness(const int Value);
	void __fastcall SetSaturation(const int Value);
	void __fastcall SetIsDefault(const bool Value);
	void __fastcall SetActiveControl(const HWND Value);
	void __fastcall SetActiveGraphControl(const Controls::TGraphicControl* Value);
	void __fastcall SetFSkinningRules(const TacSkinningRules Value);
	void __fastcall SetExtendedBorders(const bool Value);
	void __fastcall SetKeyList(const Classes::TStringList* Value);
	
protected:
	bool NoAutoUpdate;
	Controls::TGraphicControl* FActiveGraphControl;
	Extctrls::TTimer* TimerCheckHot;
	void __fastcall OnCheckHot(System::TObject* Sender);
	void __fastcall SendNewSkin(bool Repaint = true);
	void __fastcall SendRemoveSkin(void);
	void __fastcall FreeBitmaps(void);
	
public:
	Forms::TShowAction ShowState;
	TacSkinData PreviewBuffer;
	Sstylesimply::TsSkinData* CommonSkinData;
	bool SkinIsPacked;
	bool SkinRemoving;
	Graphics::TBitmap* MasterBitmap;
	Graphics::TBitmap* ShdaTemplate;
	Graphics::TBitmap* ShdiTemplate;
	int FHueOffset;
	int FSaturation;
	int SysFontScale;
	int FBrightness;
	Smaskdata::TsMaskArray ma;
	Smaskdata::TsGeneralDataArray gd;
	Smaskdata::TacOutEffArray oe;
	Sstylesimply::TConstantSkinData ConstData;
	Types::TRect FormShadowSize;
	Sconst::TStringLists ThirdLists;
	TacPaletteArray Palette;
	void __fastcall InitConstantIndexes(void);
	void __fastcall CheckShadows(void);
	void __fastcall LoadAllGeneralData(void);
	void __fastcall LoadAllMasks(void);
	void __fastcall InitMaskIndexes(void);
	int __fastcall MakeNewItem(int SkinIndex, System::UnicodeString PropertyName, System::UnicodeString AClassName, Sconst::TacImgType ImgType, const Types::TRect &R, int Count, int DrawMode, short Masktype);
	void __fastcall SetCommonSections(const Classes::TStringList* Value);
	__fastcall virtual TsSkinManager(Classes::TComponent* AOwner);
	__fastcall virtual ~TsSkinManager(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Loaded(void);
	void __fastcall ReloadSkin(void);
	void __fastcall ReloadPackedSkin(void);
	void __fastcall InstallHook(void);
	void __fastcall UnInstallHook(void);
	void __fastcall CheckVersion(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall UpdateSkinSection(const System::UnicodeString SectionName);
	__property int GroupIndex = {read=FGroupIndex, write=FGroupIndex, nodefault};
	__property Sskinmenus::TsSkinableMenus* SkinableMenus = {read=FSkinableMenus, write=FSkinableMenus};
	__property HWND ActiveControl = {read=FActiveControl, write=SetActiveControl, nodefault};
	__property Controls::TGraphicControl* ActiveGraphControl = {read=FActiveGraphControl, write=SetActiveGraphControl};
	void __fastcall RepaintForms(bool DoLockForms = true);
	int __fastcall GetSkinIndex(const System::UnicodeString SkinSection);
	int __fastcall GetMaskIndex(const System::UnicodeString SkinSection, const System::UnicodeString mask)/* overload */;
	int __fastcall GetMaskIndex(const int SkinIndex, System::UnicodeString mask)/* overload */;
	int __fastcall GetMaskIndex(const int SkinIndex, const System::UnicodeString SkinSection, const System::UnicodeString mask)/* overload */;
	int __fastcall GetTextureIndex(int SkinIndex, const System::UnicodeString SkinSection, const System::UnicodeString PropName)/* overload */;
	int __fastcall GetTextureIndex(int SkinIndex, const System::UnicodeString PropName)/* overload */;
	System::UnicodeString __fastcall GetFullSkinDirectory(void);
	System::UnicodeString __fastcall GetSkinNames(Classes::TStrings* sl, TacSkinTypes SkinType = (TacSkinTypes)(0x2));
	System::UnicodeString __fastcall GetExternalSkinNames(Classes::TStrings* sl, TacSkinTypes SkinType = (TacSkinTypes)(0x2));
	void __fastcall GetSkinSections(Classes::TStrings* sl);
	void __fastcall ExtractInternalSkin(const System::UnicodeString NameOfSkin, const System::UnicodeString DestDir);
	void __fastcall ExtractByIndex(int Index, const System::UnicodeString DestDir);
	void __fastcall UpdateSkin(bool Repaint = true);
	System::UnicodeString __fastcall GetRandomSkin(void);
	Graphics::TColor __fastcall GetGlobalColor(void);
	Graphics::TColor __fastcall GetGlobalFontColor(void);
	Graphics::TColor __fastcall GetActiveEditColor(void);
	Graphics::TColor __fastcall GetActiveEditFontColor(void);
	Graphics::TColor __fastcall GetHighLightColor(bool Focused = true);
	Graphics::TColor __fastcall GetHighLightFontColor(bool Focused = true);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(bool Repaint = false, bool AllowAnimation = true);
	int __fastcall MaskWidthTop(int MaskIndex);
	int __fastcall MaskWidthLeft(int MaskIndex);
	int __fastcall MaskWidthBottom(int MaskIndex);
	int __fastcall MaskWidthRight(int MaskIndex);
	bool __fastcall IsValidSkinIndex(int SkinIndex);
	bool __fastcall IsValidImgIndex(int ImageIndex);
	
__published:
	__property TacSkinEffects* Effects = {read=FEffects, write=FEffects};
	__property bool ExtendedBorders = {read=GetExtendedBorders, write=SetExtendedBorders, default=0};
	__property bool SkinnedPopups = {read=FSkinnedPopups, write=SetSkinnedPopups, default=1};
	__property TacAnimEffects* AnimEffects = {read=FAnimEffects, write=FAnimEffects};
	__property TacButtonsSupport* ButtonsOptions = {read=FButtonsSupport, write=FButtonsSupport};
	__property bool IsDefault = {read=GetIsDefault, write=SetIsDefault, default=1};
	__property bool Active = {read=FActive, write=SetActive, default=1};
	__property Classes::TStringList* CommonSections = {read=FCommonSections, write=SetCommonSections};
	__property int Brightness = {read=FBrightness, write=SetBrightness, default=0};
	__property int Saturation = {read=FSaturation, write=SetSaturation, default=0};
	__property int HueOffset = {read=FHueOffset, write=SetHueOffset, default=0};
	__property TsStoredSkins* InternalSkins = {read=FBuiltInSkins, write=SetBuiltInSkins};
	__property TacLabelsSupport* LabelsOptions = {read=FLabelsSupport, write=FLabelsSupport};
	__property Sskinmenus::TacMenuSupport* MenuSupport = {read=FMenuSupport, write=FMenuSupport};
	__property TacOptions* Options = {read=FOptions, write=FOptions};
	__property TacScrollBarsSupport* ScrollsOptions = {read=FScrollsOptions, write=FScrollsOptions};
	__property System::UnicodeString SkinDirectory = {read=FSkinDirectory, write=SetSkinDirectory};
	__property Classes::TStringList* KeyList = {read=FKeyList, write=SetKeyList};
	__property System::UnicodeString SkinName = {read=FSkinName, write=SetSkinName};
	__property TacSkinInfo SkinInfo = {read=GetSkinInfo, write=SetSkinInfo};
	__property TacSkinningRules SkinningRules = {read=FSkinningRules, write=SetFSkinningRules, default=7};
	__property ThirdPartyList* ThirdParty = {read=FThirdParty, write=FThirdParty};
	__property System::UnicodeString Version = {read=GetVersion, write=SetVersion, stored=false};
	__property TacGetExtraLineData OnGetMenuExtraLineData = {read=FOnGetPopupLineData, write=FOnGetPopupLineData};
	__property TacGetPopupItemData OnGetPopupItemData = {read=FOnGetPopupItemData, write=FOnGetPopupItemData};
	__property TacSysDlgInit OnSysDlgInit = {read=FOnSysDlgInit, write=FOnSysDlgInit};
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property Classes::TNotifyEvent OnAfterChange = {read=FOnAfterChange, write=FOnAfterChange};
	__property Classes::TNotifyEvent OnBeforeChange = {read=FOnBeforeChange, write=FOnBeforeChange};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
	__property Classes::TNotifyEvent OnSkinListChanged = {read=FOnSkinListChanged, write=FOnSkinListChanged};
	__property Classes::TNotifyEvent OnSkinLoading = {read=FOnSkinLoading, write=FOnSkinLoading};
};


//-- var, const, procedure ---------------------------------------------------
#define acCurrentVersion L"10.19"
static const System::Word iMaxFileSize = 0x7530;
extern PACKAGE bool IsNT;
extern PACKAGE Inifiles::TMemIniFile* SkinFile;
extern PACKAGE TsSkinManager* DefaultManager;
extern PACKAGE bool UnPackedFirst;
extern PACKAGE Classes::TStringList* acMemSkinFile;
extern PACKAGE void __fastcall ReceiveData(TsSkinManager* SkinReceiver);
extern PACKAGE void __fastcall UpdatePreview(HWND Handle, bool Enabled);
extern PACKAGE void __fastcall UpdateCommonDlgs(TsSkinManager* sManager);
extern PACKAGE bool __fastcall ChangeImageInSkin(const System::UnicodeString SkinSection, const System::UnicodeString PropName, const System::UnicodeString FileName, TsSkinManager* sm);
extern PACKAGE void __fastcall LoadThirdNames(TsSkinManager* sm, bool Overwrite = false);
extern PACKAGE void __fastcall UpdateThirdNames(TsSkinManager* sm);
extern PACKAGE int __fastcall GetScrollSize(TsSkinManager* sm);
extern PACKAGE int __fastcall GetComboBtnSize(TsSkinManager* sm);
extern PACKAGE bool __fastcall ExtractPackedData(TacSkinConvertor* &Convertor, Classes::TStringList* pwds, Classes::TComponent* SkinManager);
extern PACKAGE int __cdecl acSkinDecode(char *PackedData, __int64 *Keys, const int Keys_Size, const int Length, const int FormSum, /* out */ int &FilesCount, /* out */ int &Offset);

}	/* namespace Sskinmanager */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE)
using namespace Sskinmanager;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SskinmanagerHPP
