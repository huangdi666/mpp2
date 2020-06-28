#ifndef _HH_OSD_API_H
#define _HH_OSD_API_H

//��˼�涨ÿ��������ֻ֧��4 ��osd��������
//���Ҫ����osd �������޸�������������

#include <hi_type.h>
#include <hi_common.h>
#include <hi_comm_region.h>

#define COMM_SYSLOG(value,fmt, args...) do { printf("[%s, %s, %d] "fmt, __FILE__, __FUNCTION__, __LINE__, ##args); } while(0)
#define VIDEO_NUM	1

#define HH_MAX_OSD_NUM	  48   //(4*3*3)

#define HH_MAX_OSD_PER_GROUP    1  //Ŀǰ victa ֻ��2��


#define HH_MAX_TITLE_NUM  256
#define HH_MAX_TITLE_LINE 11

typedef struct _HI_OSD_ORG
{
	HI_U16      nOrgX;       //osd ��������Ͻ�X����
	HI_U16      nOrgY;       //osd ��������Ͻ�Y����
}HI_OSD_ORG, *PHI_OSD_ORG;

typedef struct _HI_OSD_COLOR
{
	HI_U16      bgColor;     //osd ������ɫ
	HI_U16      fgColor;     //osd ǰ����ɫ
	HI_U16		bgAlpha;     //osd ����͸����
	HI_U16		fgAlpha;	 //osd ǰ��͸����
	HI_U16		edgeColor;	 //osd ǰ����Ե��ɫ
	HI_U16      selColor;    //osd �˵�ѡ������ɫ
}HI_OSD_COLOR, *PHI_OSD_COLOR;

typedef struct _HH_OSD_LOGO
{
	VENC_GRP     vencGroup ;   //osd ������ӵ��ı�����
	HI_U8        nStatus   ;   //1 ��ʾ 0 ����
	HI_U8        nOsdLine  ;   //osd ��Ļ������
	HI_U8        nOsdFontH ;
	HI_U8        nOsdFontW ;
	HI_U16		 nWidth    ;      //osd ����Ŀ��
	HI_U16		 nHeight   ;	 //osd ����ĸ߶�
	HI_U16       nImageWidth;
	HI_U16       nImageHeight;
	HI_S16       nFontInt  ;    //osd �ַ����
	HI_U16       nVencFeild;
	HI_U8        nOsdTitleMaxLen; ////������һ���ַ��ĸ���
	HI_U8        nOsdTitleFlag[HH_MAX_TITLE_LINE]; //osd ���֧��8 �� ���ÿһ��osd ��һ���ַ���osdtitle �е�λ��
	HI_U8        nOsdTitleLen[HH_MAX_TITLE_LINE];  //���ÿһ��osd �ĳ���
	char         szOsdTitle[HH_MAX_TITLE_NUM];   //osd ������Ļ��Ϣ
	HI_OSD_ORG   osdPos    ;   //
	HI_OSD_COLOR osdColor  ;   //
	HI_U8          *pBmpBuf;
//#if defined(HI3516_ARCH) || defined(HI3518_ARCH)
	int			  regHdl;		//osd ������

	int          nSelLine  ;    //��ǵ�ǰ��Ϊѡ����
}HH_OSD_LOGO, *PHH_OSD_LOGO;

typedef struct _HH_VIDEO_RESOLUTION
{
	int      width;
	int      height;
}HH_VIDEO_RESOLUTION, *PHH_VIDEO_RESOLUTION;

HH_OSD_LOGO *HI_Create_Osd(int index, HH_OSD_LOGO **ppLog, VENC_GRP vencGroup,
						   HI_OSD_ORG	osdOrg, HI_OSD_COLOR osdColor,
 							char *pSzTitle, HI_S16 nFontInt, HI_U8 nShow);

int  HI_OSD_Parse_OsdTitle(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Get_BmpSize(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Set_Show(HH_OSD_LOGO *pOsdLogo, int show);

int  HI_Create_Osd_Reg(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Create_Bitmap(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Refresh_Color(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Refresh_Title(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Refresh_Org(HH_OSD_LOGO *pOsdLogo);
int HI_OSD_Check_ImaSizeChange(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Destroy(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_Build(HH_OSD_LOGO *pOsdLogo);

int  HI_OSD_GetCharBit(unsigned char *in, short qu, short wei, short fontSize);

int  HI_OSD_DrawBitmapBit(int  x_pos, HI_U8 *bitmap, HI_U16 fColor, HI_U16 bColor,
						  HI_U16 edgeColor, HI_U8 *bmpBuffer, HI_U16 bmpWidth,
						  HI_U16 fontSize);

int  HI_OSD_DrawBitmapBit32(int x_pos, HI_U8 *bitmap, HI_U16 fColor, HI_U16 bColor,
						  HI_U16 edgeColor, HI_U8 *bmpBuffer, HI_U16 bmpWidth,
						  HI_U16 fontSize);

void HI_OSD_CreateBMP(int bTwoFeild,  int nSize, int bmpWidth, int space,
					  char *bmpBuffer, char *string, HI_U16 fColor,
					  HI_U16 bColor, HI_U16 edgeColor);

int  HI_OSD_Refresh_SelLine(HH_OSD_LOGO *pOsdLogo, int nLine);

#endif

