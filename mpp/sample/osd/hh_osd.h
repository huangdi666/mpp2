/**************************************************************************
 * 	FileName:		osd.h
 *	Description:	OSD Process
 *	Copyright(C):	2006-2008 HHDigital Inc.
 *	Version:		V 1.0
 *	Author:			ChenYG
 *	Created:		2006-08-06
 *	Updated:
 *
 **************************************************************************/
#ifndef   _HH_OSD_H_
#define   _HH_OSD_H_
#include <hi_common.h>
#include <hi_type.h>
#include <hi_comm_region.h>

#define   HH_OSD_TYPE_TIME			1
#define   HH_OSD_TYPE_TITLE			0


#define   HH_OSD_TYPE_CJ			    2
#define   HH_OSD_TYPE_MENU            2
#define   HH_OSD_TYPE_PTZ             3
#define   HH_OSD_TYPE_AT820           4
#define   HH_OSD_TYPE_AGC             4
#define   HH_OSD_TYPE_CLOUD           6

#define   HH_OSD_DEAFULT_POS_X			0
#define   HH_OSD_DEAFULT_TIME_POS_Y		32
#define   HH_OSD_DEAFULT_FRAME_POS_Y	36
#define   HH_OSD_DEAFULT_TITLE_POS_Y	(576 - 32 - 0)

#define   HH_OSD_MAX_BUFF_LENGTH	81920			//80k
/*********************************************************
* Colour              Red      Green      Blue      ֵ
   ��ɫ   Black        0        0          0         0
   ��ɫ   White        255      255        255       16777215
   ��ɫ   Gray         192      192        192       12632256
   ���ɫ Dark Grey    128      128        128       8421504
   ��ɫ   Red          255      0          0         255
   ���ɫ Dark Red     128      0          0         128
   ��ɫ   Green        0        255        0         65280
   ����ɫ Dark Green   0        128        0         32768
   ��ɫ   Blue         0        0          255       16711680
   ����ɫ Dark Blue    0        0          128       8388608
   �Ϻ�ɫ Magenta      255      0          255       16711935
   ���Ϻ� Dark Magenta 128      0          128       8388736
   ��ɫ   Cyan         0        255        255       16776960
   ����   Dark Cyan    0        128        128       8421376
   ��ɫ   Yellow       255      255        0         65535
   ��ɫ   Brown        128      128        0         32896
   ��ɫ   Orange       252		124        0
**************************************************************/
#define   HH_OSD_COLOR_BLACK		0x8000
#define   HH_OSD_COLOR_WHITE		0xFFFF
#define   HH_OSD_COLOR_RED			0xFC00
#define   HH_OSD_COLOR_YELLOW		0xFFE0
#define   HH_OSD_COLOR_CYAN			0x83FF
#define   HH_OSD_COLOR_BLUE			0x801F

#if 0
typedef struct tag_OSD_Logo
{
    HI_U32    width;        /* out */
    HI_U32    height;       /* out */
    HI_U32    stride;       /* in */
    HI_U8 *   pRGBBuffer;   /* in/out */
}OSD_LOGO_T;

#endif
typedef struct _OSD_POS_T
{
    int		x;
	int     y;
}OSD_POS_T;

int HH_OSD_Init();

int HH_Refresh_AllTime();

int HH_OSD_ChnOrg_Refresh(int nCh);

int HH_OSD_ChnAllName_Refresh(int nCh);

int HH_OSD_ChnTime_Refresh(int nCh);

int HH_OSD_AllTime_Refresh();

int HH_OSD_AllName_Refresh();

int HH_OSD_ChnColor_Refresh(int nCh);

int HH_OSD_ChnReBuild(int nCh);

int HH_OSD_Destory_Doom_Menu();
int HH_OSD_Rebuild_Doom_Menu();
int HH_OSD_All_Refresh();
int HH_OSD_Color_Refresh(int nCh, int nEnc, int osdType);
int HH_OSD_Show_Refresh(int nCh, int nMinEnc, int osdType);
int HH_OSD_ChnShow_Refresh(int nCh);

int HH_OSD_Org_Refresh(int nCh, int nEnc, int osdType);

int HH_OSD_ChName_Refresh(int nCh, int nMinEnc, int osdType);
int HH_OSD_Refresh_SelLine(int nCh, int nMin, int nType, int iLine);
int HH_OSD_SetTitle(int nCh, char* title);
int HH_OSD_SetOsdEnabel(int nCh,int osdType,int enabel);
int HH_OSD_SetOsdPos(int nCh,int osdType,int x,int y);
int HH_OSD_SetOsdPosDefault();

#if 1
/* the color format OSD supported */
typedef enum hiOSD_COLOR_FMT_E
{
    OSD_COLOR_FMT_RGB444    = 0,
    OSD_COLOR_FMT_RGB4444   = 1,
    OSD_COLOR_FMT_RGB555    = 2,
    OSD_COLOR_FMT_RGB565    = 3,
    OSD_COLOR_FMT_RGB1555   = 4,
    OSD_COLOR_FMT_RGB888    = 6,
    OSD_COLOR_FMT_RGB8888   = 7,
    OSD_COLOR_FMT_BUTT
}OSD_COLOR_FMT_E;

typedef struct hiOSD_RGB_S
{
    HI_U8   u8B;
    HI_U8   u8G;
    HI_U8   u8R;
    HI_U8   u8Reserved;
}OSD_RGB_S;

typedef struct hiOSD_SURFACE_S
{
    OSD_COLOR_FMT_E enColorFmt;         /* color format */
    HI_U8  *pu8PhyAddr;               /* physical address */
    HI_U16  u16Height;                /* operation height */
    HI_U16  u16Width;                 /* operation width */
    HI_U16  u16Stride;                /* surface stride */
    HI_U16  u16Reserved;
}OSD_SURFACE_S;



typedef struct tag_OSD_BITMAPINFOHEADER{
        HI_U16      biSize;
        HI_U32       biWidth;
        HI_S32       biHeight;
        HI_U16       biPlanes;
        HI_U16       biBitCount;
        HI_U32      biCompression;
        HI_U32      biSizeImage;
        HI_U32       biXPelsPerMeter;
        HI_U32       biYPelsPerMeter;
        HI_U32      biClrUsed;
        HI_U32      biClrImportant;
} OSD_BITMAPINFOHEADER;

typedef struct tag_OSD_BITMAPFILEHEADER {
        HI_U32   bfSize;
        HI_U16    bfReserved1;
        HI_U16    bfReserved2;
        HI_U32   bfOffBits;
} OSD_BITMAPFILEHEADER;

typedef struct tag_OSD_RGBQUAD {
        HI_U8    rgbBlue;
        HI_U8    rgbGreen;
        HI_U8    rgbRed;
        HI_U8    rgbReserved;
} OSD_RGBQUAD;

typedef struct tag_OSD_BITMAPINFO {
    OSD_BITMAPINFOHEADER    bmiHeader;
    OSD_RGBQUAD                 bmiColors[1];
} OSD_BITMAPINFO;

typedef struct hiOSD_COMPONENT_INFO_S{

    int alen;
    int rlen;
    int glen;
    int blen;
}OSD_COMP_INFO;

#define   CAM_TITLE_LEN_NEW     64		//31�����֣�63���ַ�
typedef struct _HH_OSD_CTRL_ST
{
	unsigned int		Show;						//0: ��  1: ��
	unsigned short		X;							//x��y����ʾ��λ�ã���λ�õķ�ΧΪ0-704��0-576����ͼ��ķֱ����޹أ�x����Ϊ4�ı�����
	unsigned short		Y;
}HH_OSD_CTRL_ST ;

typedef struct _VIDEO_OSD_STATUS_
{
	HH_OSD_CTRL_ST	stDateOSD;				// 0:����������,   1:��������
	HH_OSD_CTRL_ST	stTimeOSD;				// 0:������ʱ��,   1:����ʱ��
	HH_OSD_CTRL_ST	stWeekOSD;				// 0:����������,   1:��������
	HH_OSD_CTRL_ST	stTitleOSD; 			// 0:�����ӱ���,   1:���ӱ���
	HH_OSD_CTRL_ST	stBitrateOSD;			// 0:����������,   1:��������
	char		Title[CAM_TITLE_LEN_NEW];	//�����ַ�(64���ַ�  31������)
	unsigned char       nOsdPrefer;   //OSDʱ����ʾ 0 ��Ϊ year-month-day
							  //            1 Ϊ   month-day-year
							  //            2 Ϊ   day-month-year
	unsigned char        nOsdColor;	  //osd ������ɫ
	unsigned char        nScene;       //����ccd �����(0-9)
	unsigned char        nOSDClientNum;// �Ƿ���ʾ�û�������
	unsigned char        Reserved[24];

}VIDEO_OSD_STATUS ;

#endif


#endif













































