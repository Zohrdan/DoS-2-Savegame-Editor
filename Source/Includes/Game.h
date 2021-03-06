
//<<>-<>>---------------------------------------------------------------------()
/*
	Structures du jeu
									      */
//()-------------------------------------------------------------------<<>-<>>//

#ifndef _GAME_DEFINITIONS
#define _GAME_DEFINITIONS


// いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい //
// い�									  い� //
// い� D�finitions							  い� //
// い�									  い� //
// いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい //

#include "XML.h"

#define GAME_ICON_SIZE			48
#define GAME_EQUIPPED_SLOT_MAX		10

#define GAME_LEVEL_MIN			1
#define GAME_LEVEL_MAX			35
#define GAME_ATTRIBUTE_MIN		1
#define GAME_ATTRIBUTE_MAX		40
#define GAME_ATTRIBUTE_OVERRIDE		999
#define GAME_POINTS_MIN			0
#define GAME_POINTS_MAX			99
#define GAME_ABILITIES_OVERRIDE		99

#define GAME_DISPLAY_BARHEIGHT		20
#define GAME_DISPLAY_BARVPADDING	4
#define GAME_DISPLAY_BARHPADDING	4

#define GAME_LOCK_DISABLED		0x00000000 // default
#define GAME_LOCK_ENABLED		0x00000001
#define GAME_LOCK_APP			0x00000002
#define GAME_LOCK_FILE			0x00000004
#define GAME_LOCK_TREE			0x00000008
#define GAME_LOCK_SETUP			0x00000010
#define GAME_LOCK_ALL			GAME_LOCK_APP|GAME_LOCK_FILE|GAME_LOCK_TREE|GAME_LOCK_SETUP

enum {
	ITEM_TYPE_REAL = 1,
	ITEM_TYPE_ROOT,
	ITEM_TYPE_PARENT,
};

enum {
	DATA_TYPE_ITEMS = 1,
	DATA_TYPE_BOOSTERS,
	DATA_TYPE_RUNES,
	DATA_TYPE_TAGS,
};

enum {
	DATA_TYPE_IS_ITEM = 0,
	DATA_TYPE_IS_ARMOR,
	DATA_TYPE_IS_WEAPON,
	DATA_TYPE_IS_ACCESSORY,
};

enum {
	CMP_TYPE_FULL = 1,
	CMP_TYPE_BEGIN,
	CMP_TYPE_END,
	CMP_TYPE_CONTENT,
};


// いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい //
// い�									  い� //
// い� Structures							  い� //
// い�									  い� //
// いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい //

//--- Structures g�n�rales ---

typedef struct DOS2INVENTORY {
	NODE		node;
	NODE		nodeItems;
	WCHAR*		pszNameRef;
	WCHAR*		pszDisplayName;
	int		iTopIndex;
	int		iSelected;
} DOS2INVENTORY;

typedef struct DOS2CHARACTER {
	NODE		node;
	NODE		nodeInventories;
	UINT		uInventoryDepth;
	//--- References
	XML_NODE*	pxnRoot;
	XML_ATTR*	pxaInventoryId;
	XML_ATTR*	pxaArmor;
	XML_ATTR*	pxaMagicArmor;
	XML_ATTR*	pxaVitality;
	XML_ATTR*	pxaDamageCount;
	XML_ATTR*	pxaHealCount;
	XML_ATTR*	pxaKillCount;
	XML_ATTR*	pxaName;
	XML_ATTR*	pxaOriginName;
	XML_ATTR*	pxaIsMale;
	XML_ATTR*	pxaRace;
	XML_ATTR*	pxaExp;
	XML_ATTR*	pxaPoints[4];
	XML_ATTR*	pxaAttributes[6];
	XML_ATTR*	pxaAbilities[40];
	XML_ATTR*	pxaTalents[4];
	XML_NODE*	pxaTags;
	DOS2INVENTORY*	pdiInventory;
} DOS2CHARACTER;

typedef struct DOS2ITEM {
	NODE		node;
	BOOL		bIsBackPack;
	UINT		uNumItems;
	//--- References
	XML_NODE*	pxnRoot;
	XML_ATTR*	pxaName;
	XML_ATTR*	pxaDisplayName;
	XML_ATTR*	pxaDescription;
	XML_ATTR*	pxaAmount;
	XML_ATTR*	pxaIsGenerated;
	XML_ATTR*	pxaHasCustomBase;
	XML_ATTR*	pxaSlot;
	XML_ATTR*	pxaInventory;
	XML_ATTR*	pxaType;
	XML_ATTR*	pxaLevel;
	XML_ATTR*	pxaRunes[3];
	XML_NODE*	pxnGeneration;
	XML_NODE*	pxnPermanentBoost;
	XML_NODE*	pxnBase;
} DOS2ITEM;

//--- Affichage ---

typedef struct DOS2ICON {
	NODE		node;
	HICON		hIcon;
	WCHAR*		pszName;
} DOS2ICON;

typedef struct GAMEQUALITY {
	WCHAR*		xmlName;
	UINT		uNameId;
	COLORREF	crColor;
} GAMEQUALITY;

typedef struct GAMEPORTRAIT {
	WCHAR*		pszName;
	UINT		uIconId;
} GAMEPORTRAIT;

typedef struct GAMEORIGIN {
	WCHAR*		pszName;
	UINT		uLocaleId;
} GAMEORIGIN;

typedef struct GAMEDRAWCONTEXT {
	//--- GDI
	HFONT		hFont;
	RECT		rcArea;
	RECT		rcWork;
	RECT		rcText;
	COLORREF	crColor;
	int		iBack;
	//--- Game
	UINT		uPortraitIcon;
	BOOL		bIsMale;
	WCHAR*		pszExp;
	WCHAR*		pszLevel;
	WCHAR		szLevel[4];
	WCHAR*		pszDamages;
	WCHAR*		pszHeal;
	WCHAR*		pszKills;
	WCHAR*		pszArmor;
	WCHAR*		pszMagicArmor;
	WCHAR*		pszVitality;
} GAMEDRAWCONTEXT;

//--- Donn�es ---

typedef struct GAMEDATABOOSTER {
	WCHAR*		pszType;
	WCHAR*		pszSlot;
} GAMEDATABOOSTER;

typedef struct GAMEDATARUNE {
	WCHAR*		pszBonus1;
	WCHAR*		pszBonus2;
	WCHAR*		pszBonus3;
} GAMEDATARUNE;

typedef struct GAMEDATATAG {
	BOOL		bProtected;
	BOOL		bHidden;
	WCHAR*		pszDescription;
} GAMEDATATAG;

typedef struct GAMEDATA {
	NODE		node;
	WCHAR*		pszId;
	WCHAR*		pszText;
	union {
		GAMEDATABOOSTER	booster;
		GAMEDATARUNE	rune;
		GAMEDATATAG	tag;
	};
} GAMEDATA;

typedef struct GAMEDATAFLAG {
	char*		pszFlagName;
	UINT		uType;
	UINT64		uFlags;
} GAMEDATAFLAG;

typedef struct GAMEDATAITEM {
	NODE		node;
	UINT		uType;
	UINT64		uFlags;
	WCHAR*		pszIconName;
	struct {
	WCHAR*		pszFull;
	WCHAR*		pszBegin;
	WCHAR*		pszContent;
	WCHAR*		pszEnd;
	} filter;
} GAMEDATAITEM;

typedef struct GAMEDATAPARSER {
	BOOL		bSuccess;
	HANDLE		hFile;
	DWORD		dwFileSize;
	BYTE*		pFileBuffer;
	BYTE*		pFilePtr;
	BYTE*		pLinePtr;
	BYTE*		pLineBegin;
	BYTE*		pLineEnd;
	LOCALE_MISC*	pLocale;
	WCHAR*		pszResults[4];
	union {
		GAMEDATAITEM*	pItem;
		GAMEDATA*	pData;
	};
} GAMEDATAPARSER;


// いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい //
// い�									  い� //
// い� Prototypes							  い� //
// い�									  い� //
// いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい //

// �算� Gestion ����������������������������������������������������������

int			Game_CreateLayout(void);
int			Game_CreateButton(int,int,int,int,WCHAR *,UINT,HWND *,UINT);

void			Game_InventoryMenu(HWND,UINT);
int CALLBACK		Game_ItemsListSort(LPARAM,LPARAM,LPARAM);

void			Game_Setup(DOS2CHARACTER *,BOOL,BOOL);
int			Game_BuildPlayers(void);
void			Game_ReleasePlayers(void);
DOS2INVENTORY*		Game_BuildInventory(XML_ATTR *,XML_ATTR *,XML_ATTR *,NODE *);
UINT			Game_GetInventoryItemsCount(XML_NODE *,WCHAR *);
void			Game_ReleaseInventory(DOS2INVENTORY *);
void			Game_CharacterChanged(BOOL);
void			Game_UpdateButtons(void);
void			Game_SaveTopIndex(void);

void			Game_Lock(DWORD);
UINT			Game_GetLevelFromExp(UINT);
BOOL			Game_IsItemEquipped(DOS2ITEM *);
WCHAR*			Game_CopyDisplayName(WCHAR *);

// �算� Affichage ��������������������������������������������������������

void			Game_MeasureList(MEASUREITEMSTRUCT *);
void			Game_DrawList(DRAWITEMSTRUCT *);

void			Game_MeasureInventory(MEASUREITEMSTRUCT *);
void			Game_DrawInventory(DRAWITEMSTRUCT *);

void			Game_Paint(HWND,HDC,RECT *);
void			Game_PaintInfos(HDC,GAMEDRAWCONTEXT *);
void			Game_PaintInfosPart(HDC,WCHAR *,COLORREF,COLORREF,COLORREF,RECT *);
void			Game_PaintText(HDC,WCHAR *,WCHAR *,RECT *);
void			Game_PaintValue(HDC,LONG,HWND,WCHAR *,WCHAR *);
void			Game_PaintButton(DRAWITEMSTRUCT *);
void			Game_PaintBag(DRAWITEMSTRUCT *);
void			Game_PaintIcon(HDC,WCHAR *,UINT,RECT *,int,BOOL,BOOL);

// �算� Fichiers de donn�es ����������������������������������������������

BOOL			Game_LoadDataFile(HWND,WCHAR *,UINT,NODE *);
BYTE*			Game_LoadSplitWord(BYTE *);
BYTE*			Game_LoadLeadingSpaces(BYTE *,BYTE *,DWORD);
BYTE*			Game_LoadNextLine(BYTE *,BYTE *,DWORD,BOOL);
void			Game_LoadGetItemInfos(char *,GAMEDATAITEM *);
void			Game_LoadGetItemInfo(char *,GAMEDATAITEM *);

void			Game_UnloadDataFile(UINT,NODE *);

WCHAR*			Game_GetItemIconName(WCHAR *);
WCHAR*			Game_GetItemTypeName(WCHAR *);
UINT			Game_GetItemType(WCHAR *);
UINT64			Game_GetItemFlags(WCHAR *);
GAMEDATAITEM*		Game_GetItemData(WCHAR *);
BOOL			Game_CompareStrings(WCHAR *,WCHAR *,UINT,UINT);

#endif
