////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
#include "time.h"
#define N 30
int levelx=1,JS=1,cjz=1;
float gametime;
struct door{
	char name[N];
	int existence;
}Door_7[] = {{"y1",1},{"y2",1},{"b1",1},{"b2",1},{"b3",1},{"b4",1},{"b5",1},{"r",1},{"t1",1},{"t2",1},{"t3",1},{"t4",1},{" ",2}},
Door_6[] = {{"y1",1},{"y2",1},{"y3",1},{"y4",1},{"y5",1},{"y6",1},{"b1",1},{"b2",1},{"b3",1},{"r",1},{" ",2}},
Door_5[] = {{"y1",1},{"y2",1},{"y3",1},{"y4",1},{"b",1},{" ",2}},
Door_4[] = {{"y1",1},{"y2",1},{"y3",1},{"y4",1},{"y5",1},{"b1",1},{"b2",1},{"r1",1},{"t",1},{" ",2}},
Door_3[] = {{"y1",1},{"y2",1},{"y3",1},{" ",2}},
Door_2[] = {{"y1",1},{"y2",1},{"y3",1},{"y4",1},{"y5",1},{"y6",1},{"b",1},{"t1",1},{"t2",1},{"g",1},{"l",1},{" ",2}},
Door_1[] = {{"y1",1},{"y2",1},{"y3",1},{"y4",1},{"y5",1},{"y6",1},{"r",1},{" ",2}};
//
/////////////////////////��������ʼ������ṹ��////////////////////
struct monsters{
	char Name[N];
	int HP;
	int GongJi;
	int FangYu;
	int JinBi;
	int Jingyan;
	int existence;
}Monsters_7[] = {{"gold_leader_1",900,500,500,77,60,1},{"gold_leader_2",900,500,500,77,60,1},{"gold_leader_3",900,500,500,77,60,1},
{"gold_leader_4",900,500,500,77,60,1},{" ",0,0,0,0,0,2}},
//���߲�
Monsters_6[] = {{"skull_1",110,25,5,5,3,1},{"skull_2",110,25,5,5,3,1},{"wild_heast_1",300,75,45,13,10,1},
{"wild_heast_2",300,75,45,13,10,1},{"red_enchanter_1",100,200,110,30,25,1},{"red_enchanter_2",100,200,110,30,25,1},
{"red_enchanter_3",100,200,110,30,25,1},{"red_enchanter_4",100,200,110,30,25,1},{"blue_enchanter_1",125,50,25,10,7,1},
{"blue_enchanter_2",125,50,25,10,7,1},{"gold_leader",600,650,500,77,60,1},{"superbat_1",150,65,30,10,8,1},
{"superbat_2",150,65,30,10,8,1},{"superbat_3",150,65,30,10,8,1},{"superenchanter",500,400,260,47,35,1},{" ",0,0,0,0,0,2}},
//������
Monsters_5[] = {{"smallbat_1",100,20,5,3,2,1},{"smallbat_2",100,20,5,3,2,1},{"smallbat_3",100,20,5,3,2,1},
{"smallbat_4",100,20,5,3,2,1},{"smallbat_5",100,20,5,3,2,1},{"skull_1",110,25,5,5,3,1},{"skull_2",110,25,5,5,3,1},
{"blue_enchanter_1",125,50,25,10,7,1},{"blue_enchanter_2",125,50,25,10,7,1},{"blue_enchanter_3",125,50,25,10,7,1},
{"blue_enchanter_4",125,50,25,10,7,1},{"blue_enchanter_5",125,50,25,10,7,1},{"blue_enchanter_6",125,50,25,10,7,1},{"blackhead_1",200,35,10,5,3,1},
{"blackhead_2",200,35,10,5,3,1},{"superbat_1",150,65,30,10,8,1},{"superbat_2",150,65,30,10,8,1},{"superbat_3",150,65,30,10,8,1},
{"superbat_4",150,65,30,10,8,1},{"wild_heast_1",300,75,45,13,10,1},{"wild_heast_2",300,75,45,13,10,1},{"stone_man_1",450,150,90,22,19,1},
{"stone_man_2",450,150,90,22,19,1},{"ten_man",400,160,100,25,25,1},{" ",0,0,0,0,0,2}},
//�����
Monsters_4[] = {{"skull_1",110,25,5,5,3,1},{"skull_2",110,25,5,5,3,1},{"blackhead_1",200,35,10,5,3,1},{"blackhead_2",200,35,10,5,3,1},
{"blackhead_3",200,35,10,5,3,1},{"blackhead_4",200,35,10,5,3,1},{"redhead_1",70,15,2,2,1,1},{"redhead_2",70,15,2,2,1,1},
{"smallbat_1",100,20,5,3,2,1},{"smallbat_2",100,20,5,3,2,1},{"smallbat_3",100,20,5,3,2,1},{"smallbat_4",100,20,5,3,2,1},
{"superbat_1",150,65,30,10,8,1},{"superbat_2",150,65,30,10,8,1},{"superbat_3",150,65,30,10,8,1},{"redbat",550,170,100,25,20,1},
{"stone_man",450,150,90,22,19,1},{"wild_heast_1",300,75,45,13,10,1},{"wild_heast_2",300,75,45,13,10,1},
{"wild_heast_3",300,75,45,13,10,1},{"thief",0,0,0,0,0,1},{" ",0,0,0,0,0,2}},
//���Ĳ�
Monsters_3[] = {{"redhead_1",70,15,2,2,1,1},{"redhead_2",70,15,2,2,1,1},{"redhead_3",70,15,2,2,1,1},{"redhead_4",70,15,2,2,1,1},
{"redhead_5",70,15,2,2,1,1},{"redhead_6",70,15,2,2,1,1},{"redhead_7",70,15,2,2,1,1},{"redhead_8",70,15,2,2,1,1},
{"redhead_9",70,15,2,2,1,1},{"smallbat_1",100,20,5,3,2,1},{"smallbat_2",100,20,5,3,2,1},{"smallbat_3",100,20,5,3,2,1},
{"smallbat_4",100,20,5,3,2,1},{"smallbat_5",100,20,5,3,2,1},{"skull_1",110,25,5,5,3,1},{"skull_2",110,25,5,5,3,1},
{"greenhead_1",50,20,1,1,1,1},{"greenhead_2",50,20,1,1,1,1},{" ",0,0,0,0,0,2}},
//������
Monsters_2[] = {{"gold_leader_1",600,350,300,77,60,1},{"gold_leader_2",600,350,300,77,60,1},{"redleader",850,350,200,45,35,1},{" ",0,0,0,0,0,2}},
//�ڶ���
Monsters_1[] = {{"redhead",70,15,2,2,1,1},{"greenhead_1",50,20,1,1,1,1},{"greenhead_2",50,20,1,1,1,1},
{"greenhead_3",50,20,1,1,1,1},{"smallbat_1",100,20,5,3,2,1},{"smallbat_2",100,20,5,3,2,1},{"skull_1",110,25,5,5,3,1},
{"skull_2",110,25,5,5,3,1},{"wild_heast_1",300,75,45,13,10,1},{"wild_heast_2",300,75,45,13,10,1},
{"blue_enchanter",125,50,25,10,7,1},{"blackhead",200,35,10,5,3,1},{"ten_man",400,160,100,25,25,1},{" ",0,0,0,0,0,2}};
//��һ��
//////////////////////////////////////////////////////////////////
//
//
////////////////////�������ǽṹ��////////////////////////////////
struct hero{
	int rank ;
	int HP;
	int GongJi;
	int FangYu;
	int JinBi;
	int JingYan;
	int YellowKey;
	int BlueKey;
	int RedKey;
	int floor;
};
//////////////////////////////////////////////////////////////////
//
//
/////////////////////////������Ʒ/////////////////////////////////
struct things{
	char name[N];
	int rank;
	int HP;
	int GongJi;
	int FangYu;
	int JinBi;
	int YellowKey;
	int BlueKey;
	int RedKey;
	int existence;
}Things_7[] = {{"redgem_1",0,0,3,0,0,0,0,0,1},{"redgem_2",0,0,3,0,0,0,0,0,1},{"redgem_3",0,0,3,0,0,0,0,0,1},  //���߲�
{"redgem_4",0,0,3,0,0,0,0,0,1},{"redgem_5",0,0,3,0,0,0,0,0,1},{"bluegem_1",0,0,0,3,0,0,0,0,1},{"bluegem_2",0,0,0,3,0,0,0,0,1},
{"bluegem_3",0,0,0,3,0,0,0,0,1},{"red_hp_1",0,200,0,0,0,0,0,0,1},{"red_hp_2",0,200,0,0,0,0,0,0,1},{"red_hp_3",0,200,0,0,0,0,0,0,1},
{"red_hp_4",0,200,0,0,0,0,0,0,1},{"blue_hp",0,500,0,0,0,0,0,0,1},{"yellowkey_1",0,0,0,0,0,1,0,0,1},{"yellowkey_2",0,0,0,0,0,1,0,0,1},
{"bluekey_1",0,0,0,0,0,0,1,0,1},{"bluekey_2",0,0,0,0,0,0,1,0,1},{"bluekey_3",0,0,0,0,0,0,1,0,1},{"bluekey_4",0,0,0,0,0,0,1,0,1},
{"sword",0,0,60,0,0,0,0,0,1},{"shield",0,0,0,45,0,0,0,0,1},{" ",0,0,0,0,0,0,0,0,2}},
//���߲�
Things_6[] = {{"redgem",0,0,3,0,0,0,0,0,1},{"bluegem_1",0,0,0,3,0,0,0,0,1},{"bluegem_2",0,0,0,3,0,0,0,0,1},
{"blue_hp_1",0,500,0,0,0,0,0,0,1},{"blue_hp_2",0,500,0,0,0,0,0,0,1},{"blue_hp_3",0,500,0,0,0,0,0,0,1},
{"yellowkey_1",0,0,0,0,0,1,0,0,1},{"yellowkey_2",0,0,0,0,0,1,0,0,1},{"yellowkey_3",0,0,0,0,0,1,0,0,1},
{"yellowkey_4",0,0,0,0,0,1,0,0,1},{"yellowkey_5",0,0,0,0,0,1,0,0,1},{"yellowkey_6",0,0,0,0,0,1,0,0,1},
{"yellowkey_7",0,0,0,0,0,1,0,0,1},{"yellowkey_8",0,0,0,0,0,1,0,0,1},{"redkey_1",0,0,0,0,0,0,0,1,1},{"feather",3,0,0,0,0,0,0,0,1},
{"BAD",0,-200,-3,-3,-5,0,0,0,1},{" ",0,0,0,0,0,0,0,0,2}},
//������
Things_5[] = {{"redgem_1",0,0,3,0,0,0,0,0,1},{"redgem_2",0,0,3,0,0,0,0,0,1},{"redgem_3",0,0,3,0,0,0,0,0,1},
{"bluegem_1",0,0,0,3,0,0,0,0,1},{"bluegem_2",0,0,0,3,0,0,0,0,1},{"red_hp",0,200,0,0,0,0,0,0,1},{"blue_hp",0,500,0,0,0,0,0,0,1},
{"yellowkey_1",0,0,0,0,0,1,0,0,1},{"yellowkey_2",0,0,0,0,0,1,0,0,1},{"bluekey_1",0,0,0,0,0,0,1,0,1},{"superkey",0,0,0,0,0,1,1,1,1},
{"feather",3,500,10,10,0,0,0,0,1},{"green_sword",0,0,80,0,0,0,0,0,1},{"shield",0,0,0,45,0,0,0,0,1},{" ",0,0,0,0,0,0,0,0,2}},
//�����
Things_4[] = {{"redgem_1",0,0,3,0,0,0,0,0,1},{"redgem_2",0,0,3,0,0,0,0,0,1},{"redgem_3",0,0,3,0,0,0,0,0,1},
{"redgem_4",0,0,3,0,0,0,0,0,1},{"redgem_5",0,0,3,0,0,0,0,0,1},{"bluegem_1",0,0,0,3,0,0,0,0,1},{"bluegem_2",0,0,0,3,0,0,0,0,1},
{"bluegem_3",0,0,0,3,0,0,0,0,1},{"bluegem_4",0,0,0,3,0,0,0,0,1},{"bluegem_5",0,0,0,3,0,0,0,0,1},{"red_hp_1",0,200,0,0,0,0,0,0,1},
{"red_hp_2",0,200,0,0,0,0,0,0,1},{"red_hp_3",0,200,0,0,0,0,0,0,1},{"red_hp_4",0,200,0,0,0,0,0,0,1},{"blue_hp",0,500,0,0,0,0,0,0,1},
{"yellowkey_1",0,0,0,0,0,1,0,0,1},{"yellowkey_2",0,0,0,0,0,1,0,0,1},{"yellowkey_3",0,0,0,0,0,1,0,0,1},{"bluekey_1",0,0,0,0,0,0,1,0,1}
,{" ",0,0,0,0,0,0,0,0,2}},
//���Ĳ�
Things_3[] = {{"redgem_1",0,0,3,0,0,0,0,0,1},{"redgem_2",0,0,3,0,0,0,0,0,1},{"bluegem_1",0,0,0,3,0,0,0,0,1},{"bluegem_2",0,0,0,3,0,0,0,0,1},
{"bluegem_3",0,0,0,3,0,0,0,0,1},{"red_hp",0,200,0,0,0,0,0,0,1},{"blue_hp_1",0,500,0,0,0,0,0,0,1},{"blue_hp_2",0,500,0,0,0,0,0,0,1},
{"yellowkey_1",0,0,0,0,0,1,0,0,1},{"yellowkey_2",0,0,0,0,0,1,0,0,1},{"yellowkey_3",0,0,0,0,0,1,0,0,1},
{"yellowkey_4",0,0,0,0,0,1,0,0,1},{"yellowkey_5",0,0,0,0,0,1,0,0,1},{"yellowkey_6",0,0,0,0,0,1,0,0,1},{"yellowkey_7",0,0,0,0,0,1,0,0,1},
{"redkey_1",0,0,0,0,0,0,0,1,1},{"sword",0,0,60,0,0,0,0,0,1},{" ",0,0,0,0,0,0,0,0,2}},
//������
Things_2[] = {{"red_hp_1",0,200,0,0,0,0,0,0,1},{"red_hp_2",0,200,0,0,0,0,0,0,1},{"red_hp_3",0,200,0,0,0,0,0,0,1},
{"blue_hp_1",0,500,0,0,0,0,0,0,1},{"blue_hp_2",0,500,0,0,0,0,0,0,1},{"blue_hp_3",0,500,0,0,0,0,0,0,1},{"blue_hp_4",0,500,0,0,0,0,0,0,1},
{"redgem_1",0,0,3,0,0,0,0,0,1},{"redgem_2",0,0,3,0,0,0,0,0,1},{"redgem_3",0,0,3,0,0,0,0,0,1},
{"redgem_4",0,0,3,0,0,0,0,0,1},{"redgem_5",0,0,3,0,0,0,0,0,1},{"bluegem_1",0,0,0,3,0,0,0,0,1},{"bluegem_2",0,0,0,3,0,0,0,0,1},
{"bluegem_3",0,0,0,3,0,0,0,0,1},{"bluegem_4",0,0,0,3,0,0,0,0,1},{"yellowkey_1",0,0,0,0,0,1,0,0,1},{"yellowkey_2",0,0,0,0,0,1,0,0,1},
{"yellowkey_3",0,0,0,0,0,1,0,0,1},{"yellowkey_4",0,0,0,0,0,1,0,0,1},{"yellowkey_5",0,0,0,0,0,1,0,0,1},
{"yellowkey_6",0,0,0,0,0,1,0,0,1},{"yellowkey_7",0,0,0,0,0,1,0,0,1},{"yellowkey_8",0,0,0,0,0,1,0,0,1},
{"yellowkey_9",0,0,0,0,0,1,0,0,1},{"redkey_1",0,0,0,0,0,0,0,1,1},{"redkey_2",0,0,0,0,0,0,0,1,1},
{"holy_sword",0,0,120,0,0,0,0,0,1},{"holy_shield",0,0,0,100,0,0,0,0,1},{"HOLY",0,500,90,90,0,0,0,0,1},{" ",0,0,0,0,0,0,0,0,2}},
//�ڶ���
Things_1[] = {{"redgem_1",0,0,3,0,0,0,0,0,1},{"redgem_2",0,0,3,0,0,0,0,0,1},{"redgem_3",0,0,3,0,0,0,0,0,1},{"bluegem_1",0,0,0,3,0,0,0,0,1},{"bluegem_2",0,0,0,3,0,0,0,0,1},
{"red_hp_1",0,200,0,0,0,0,0,0,1},{"red_hp_2",0,200,0,0,0,0,0,0,1},{"red_hp_3",0,200,0,0,0,0,0,0,1},{"red_hp_4",0,200,0,0,0,0,0,0,1},
{"red_hp_5",0,200,0,0,0,0,0,0,1},{"red_hp_6",0,200,0,0,0,0,0,0,1},{"red_hp_7",0,200,0,0,0,0,0,0,1},{"blue_hp",0,500,0,0,0,0,0,0,1},
{"yellowkey_1",0,0,0,0,0,1,0,0,1},{"yellowkey_2",0,0,0,0,0,1,0,0,1},{"yellowkey_3",0,0,0,0,0,1,0,0,1},
{"yellowkey_4",0,0,0,0,0,1,0,0,1},{"yellowkey_5",0,0,0,0,0,1,0,0,1},{"yellowkey_6",0,0,0,0,0,1,0,0,1},
{"yellowkey_7",0,0,0,0,0,1,0,0,1},{"yellowkey_8",0,0,0,0,0,1,0,0,1},{"yellowkey_9",0,0,0,0,0,1,0,0,1},
{"redkey_1",0,0,0,0,0,0,0,1,1},{"bluekey_1",0,0,0,0,0,0,1,0,1},{"bluekey_2",0,0,0,0,0,0,1,0,1},{"superkey",0,0,0,0,0,1,1,1,1},
{"supergold",0,0,0,0,300,0,0,0,1},{" ",0,0,0,0,0,0,0,0,2}};
//��һ��
//////////////////////////////////////////////////////////////////
//
//
//////////////////////////////��ʼ������///////////////////////////


///////////////////////////////////////////////////////////////////
//
//
/////////////////////////////��ʼ������////////////////////////////
static struct hero Mr_Wang = {1,1000,20,18,0,0,0,0,0,1};
///////////////////////////////////////////////////////////////////
//
//
////////////////////////////��ʼ����Ʒ/////////////////////////////

///////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////

void Show_hero()
{
	dSetSpritePosition("rank", -27.135, -26.275);
	dSetTextValue( "rank", Mr_Wang.rank );
	//
	dSetSpritePosition("HP", -25.275,-21.745);
	dSetTextValue( "HP", Mr_Wang.HP );
	//
	dSetSpritePosition("Gongji", -25.275,-16.745);
	dSetTextValue( "Gongji", Mr_Wang.GongJi );
	//
	dSetSpritePosition("Fangyu", -25.275,-11.745);
	dSetTextValue( "Fangyu", Mr_Wang.FangYu);
	//
	dSetSpritePosition("Jinbi", -25.275,-6.745);
	dSetTextValue( "Jinbi", Mr_Wang.JinBi );
	//
	dSetSpritePosition("Jingyan", -25.275,-1.745);
	dSetTextValue( "Jingyan", Mr_Wang.JingYan );
	//
	dSetSpritePosition("yellowkey", -30.357,5.255);
	dSetTextValue( "yellowkey",Mr_Wang.YellowKey  );
	//
	dSetSpritePosition("bluekey", -30.357,12.255);
	dSetTextValue( "bluekey", Mr_Wang.BlueKey );
	//
	dSetSpritePosition("redkey", -30.357,19.255);
	dSetTextValue( "redkey", Mr_Wang.RedKey );
	//
	dSetSpritePosition("floor", -30.357,26.255);
	dSetTextValue( "floor", levelx );
}
//ս����ʾ����
void Fight(int k,int s1,int s2,int g2,int f2)
{
	dSetSpritePosition("DZ", 0.000,1.000);
	dSetSpriteVisible("DZ", k);
	dSetSpritePosition("sm1", -7.365,-3.208);
	dSetTextValue( "sm1", s1 );
	dSetSpriteVisible( "sm1", k );
	dSetSpritePosition("sm2", 20.635,-3.208);
	dSetTextValue( "sm2", s2);
	dSetSpriteVisible( "sm2", k );
	dSetSpritePosition("gj1", -7.365,2.792);
	dSetTextValue( "gj1", Mr_Wang.GongJi );
	dSetSpriteVisible( "gj1", k );
	dSetSpritePosition("gj2", 20.635,2.792);
	dSetTextValue( "gj2", g2 );
	dSetSpriteVisible( "gj2", k );
	dSetSpritePosition("fy1", -7.365,7.792);
	dSetTextValue( "fy1", Mr_Wang.FangYu );
	dSetSpriteVisible( "fy1", k );
	dSetSpritePosition("fy2", 20.635,7.792);
	dSetTextValue( "fy2", f2 );
	dSetSpriteVisible( "fy2", k );
}
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState = 0;		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
									//
void		GameInit();
void		GameRun(float fDeltaTime);
void		GameEnd();

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�


//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void GameMainLoop(float	fDeltaTime)
{
	switch (g_iGameState)
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
	{
		GameInit();
		g_iGameState = 2; // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
	}
	break;

	// ��Ϸ�����У����������Ϸ�߼�
	case 2:
	{
		// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
		if (JS)
		{
			GameRun(fDeltaTime);
		}
		else
		{
			// ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			g_iGameState = 0;
			GameEnd();
		}
	}
	break;

	// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}

//==============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void GameInit()
{
	int i;
	//�������
	dShowCursor(1);
	//��ȡʱ������
	//time0 = time(NULL);
	//������ʿ��ʼ״̬
	Mr_Wang.rank=1;
	Mr_Wang.HP=1000;
	Mr_Wang.GongJi=20;
	Mr_Wang.FangYu=18;
	Mr_Wang.JinBi=0;
	Mr_Wang.JingYan=0;
	Mr_Wang.YellowKey=0;
	Mr_Wang.BlueKey=0;
	Mr_Wang.RedKey=0;
	Mr_Wang.floor=1;
	/*i=0;
	while(1)
	{
		if(Monsters_1[i].existence==2) break;
		Monsters_1[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Things_1[i].existence==2) break;
		Things_1[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Door_1[i].existence==2) break;
		Door_1[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Monsters_2[i].existence==2) break;
		Monsters_2[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Things_2[i].existence==2) break;
		Things_2[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Door_2[i].existence==2) break;
		Door_2[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Monsters_3[i].existence==2) break;
		Monsters_3[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Things_3[i].existence==2) break;
		Things_3[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Door_3[i].existence==2) break;
		Door_3[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Monsters_4[i].existence==2) break;
		Monsters_4[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Things_4[i].existence==2) break;
		Things_4[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Door_4[i].existence==2) break;
		Door_4[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Monsters_5[i].existence==2) break;
		Monsters_5[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Things_5[i].existence==2) break;
		Things_5[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Door_5[i].existence==2) break;
		Door_5[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Monsters_6[i].existence==2) break;
		Monsters_6[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Things_6[i].existence==2) break;
		Things_6[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Door_6[i].existence==2) break;
		Door_6[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Monsters_7[i].existence==2) break;
		Monsters_7[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Things_7[i].existence==2) break;
		Things_7[i].existence=1;
	}
	i=0;
	while(1)
	{
		if(Door_7[i].existence==2) break;
		Door_7[i].existence=1;
	}*/
	levelx=1;
	dSetSpriteVisible("man", 1);
	dSetSpriteVisible("dongleft", 0);
	dSetSpriteVisible("dongtop", 0);
	dSetSpriteVisible("dongright", 0);
	dSetSpriteVisible("dongdown", 0);
/*	dSetSpriteVisible("DZ", 0);
	dSetSpriteVisible("wo", 0);
	dSetSpriteVisible("mowan", 0);
	dSetSpriteVisible("BJ", 0);
	dSetSpriteVisible("mowan", 0);
	dSetSpriteVisible("wo", 0);
	dSetSpriteVisible("smy", 0);
	dSetSpriteVisible("smg", 0);
	dSetSpriteVisible("gjy", 0);
	dSetSpriteVisible("gjg", 0);
	dSetSpriteVisible("fyy", 0);
	dSetSpriteVisible("fyg", 0);
	dSetSpriteVisible("yingxiong", 0);
	dSetSpriteVisible("guaiwu", 0);
	dSetSpriteVisible("smy", 0);
	dSetSpriteVisible("smg", 0);
	dSetSpriteVisible("gjy", 0);
	dSetSpriteVisible("gjg", 0);
	dSetSpriteVisible("fyy", 0);
	dSetSpriteVisible("fyg", 0);
	dSetSpriteVisible("yingxiong", 0);
	dSetSpriteVisible("guaiwu", 0);*/
	Show_hero();
}
//==============================================================================
//
// ÿ����Ϸ������
void GameRun(float fDeltaTime)
{
	gametime+=fDeltaTime;
}
//==============================================================================
//
// ������Ϸ����
void GameEnd()
{
	dSetSpriteEnable("man", 1);
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseMove(const float fMouseX, const float fMouseY)
{
	
}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
	switch(levelx)
	{
	case 1:if(iMouseType==1) {dLoadMap("level2.t2d");levelx=2;}break;
	case 2:if(iMouseType==0) {dLoadMap("level1.t2d");levelx=1;}else {dLoadMap("level3.t2d");levelx=3;}break;
	case 3:if(iMouseType==0) {dLoadMap("level2.t2d");levelx=2;}else {dLoadMap("level4.t2d");levelx=4;}break;
	case 4:if(iMouseType==0) {dLoadMap("level3.t2d");levelx=3;}else {dLoadMap("level5.t2d");levelx=5;}break;
	case 5:if(iMouseType==0) {dLoadMap("level4.t2d");levelx=4;}else {dLoadMap("level6.t2d");levelx=6;}break;
	case 6:if(iMouseType==0) {dLoadMap("level5.t2d");levelx=5;}else {dLoadMap("level7.t2d");levelx=7;}break;
	case 7:if(iMouseType==0) {dLoadMap("level6.t2d");levelx=6;}break;
	}
	dSetSpriteVisible("BJ", 0);
	dSetSpriteVisible("wo", 0);
	dSetSpriteVisible("mowan", 0);
	dSetSpriteVisible("BJ", 0);
	dSetSpriteVisible("wo", 0);
	dSetSpriteVisible("mowan", 0);
	dSetSpriteVisible("smy", 0);
	dSetSpriteVisible("smg", 0);
	dSetSpriteVisible("gjy", 0);
	dSetSpriteVisible("gjg", 0);
	dSetSpriteVisible("fyy", 0);
	dSetSpriteVisible("fyg", 0);
	dSetSpriteVisible("yingxiong", 0);
	dSetSpriteVisible("guaiwu", 0);
	dSetSpriteVisible("smy", 0);
	dSetSpriteVisible("smg", 0);
	dSetSpriteVisible("gjy", 0);
	dSetSpriteVisible("gjg", 0);
	dSetSpriteVisible("fyy", 0);
	dSetSpriteVisible("fyg", 0);
	dSetSpriteVisible("yingxiong", 0);
	dSetSpriteVisible("guaiwu", 0);
	dSetSpriteVisible("man", 1);
	dSetSpriteVisible("dongleft", 0);
	dSetSpriteVisible("dongtop", 0);
	dSetSpriteVisible("dongright", 0);
	dSetSpriteVisible("dongdown", 0);
	dSetSpriteVisible("sm", 0);
	dSetSpriteVisible("fm", 0);
	dSetSpriteVisible("js", 0);
	Show_hero();
	int d=0,e=0,f=0;
	switch(levelx)
	{
		case 1:
		
		while (1)
		{
			if (Monsters_1[d].existence == 2) break;
			if (Monsters_1[d].existence==0) dDeleteSprite(Monsters_1[d].Name);
			d++;
		}
	
	
		while (1)
		{
			if (Things_1[e].existence == 2) break;
			if (Things_1[e].existence == 0) dDeleteSprite(Things_1[e].name);
			e++;
		}
		while (1)
		{
			if (Door_1[f].existence == 2) break;
			if (Door_1[f].existence == 0) dDeleteSprite(Door_1[f].name);
			f++;
		}
	
		break;
		case 2:
		while (1)
		{
			if (Monsters_2[d].existence == 2) break;
			if (Monsters_2[d].existence == 0) dDeleteSprite(Monsters_2[d].Name);
			d++;
		}
		while (1)
		{
			if (Things_2[e].existence == 2) break;
			if (Things_2[e].existence == 0) dDeleteSprite(Things_2[e].name);
			e++;
		}
		while (1)
		{
			if (Door_2[f].existence == 2) break;
			if (Door_2[f].existence == 0) dDeleteSprite(Door_2[f].name);
			f++;
		} break;
		case 3:
		while (1)
		{
			if (Monsters_3[d].existence == 2) break;
			if (Monsters_3[d].existence == 0) dDeleteSprite(Monsters_3[d].Name);
			d++;
		}
		while (1)
		{
			if (Things_3[e].existence == 2) break;
			if (Things_3[e].existence == 0) dDeleteSprite(Things_3[e].name);
			e++;
		}
		while (1)
		{
			if (Door_3[f].existence == 2) break;
			if (Door_3[f].existence == 0) dDeleteSprite(Door_3[f].name);
			f++;
		}break;
		case 4:
		while (1)
		{
			if (Monsters_4[d].existence == 2) break;
			if (Monsters_4[d].existence == 0) dDeleteSprite(Monsters_4[d].Name);
			d++;
		}
		while (1)
		{
			if (Things_4[e].existence == 2) break;
			if (Things_4[e].existence == 0) dDeleteSprite(Things_4[e].name);
			e++;
		}
		while (1)
		{
			if (Door_4[f].existence == 2) break;
			if (Door_4[f].existence == 0) dDeleteSprite(Door_4[f].name);
			f++;
		}break;
		case 5:
		while (1)
		{
			if (Monsters_5[d].existence == 2) break;
			if (Monsters_5[d].existence == 0) dDeleteSprite(Monsters_5[d].Name);
			d++;
		}
		while (1)
		{
			if (Things_5[e].existence == 2) break;
			if (Things_5[e].existence == 0) dDeleteSprite(Things_5[e].name);
			e++;
		}
		while (1)
		{
			if (Door_5[f].existence == 2) break;
			if (Door_5[f].existence == 0) dDeleteSprite(Door_5[f].name);
			f++;
		}break;
		case 6:
		while (1)
		{
			if (Monsters_6[d].existence == 2) break;
			if (Monsters_6[d].existence == 0) dDeleteSprite(Monsters_6[d].Name);
			d++;
		}
		while (1)
		{
			if (Things_6[e].existence == 2) break;
			if (Things_6[e].existence == 0) dDeleteSprite(Things_6[e].name);
			e++;
		}
		while (1)
		{
			if (Door_6[f].existence == 2) break;
			if (Door_6[f].existence == 0) dDeleteSprite(Door_6[f].name);
			f++;
		}break;
		case 7:
		while (1)
		{
			if (Monsters_7[d].existence == 2) break;
			if (Monsters_7[d].existence == 0) dDeleteSprite(Monsters_7[d].Name);
			d++;
		}
		while (1)
		{
			if (Things_7[e].existence == 2) break;
			if (Things_7[e].existence == 0) dDeleteSprite(Things_7[e].name);
			e++;
		}
		while (1)
		{
			if (Door_7[f].existence == 2) break;
			if (Door_7[f].existence == 0) dDeleteSprite(Door_7[f].name);
			f++;
		}break;
		
	}
		
}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseUp(const int iMouseType, const float fMouseX, const float fMouseY)
{
	
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void OnKeyDown(const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress)
{
	//��ʿ�ƶ�����
	float speedx = 0.f, speedy = 0.f;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	switch (iKey)
	{
	case KEY_A:speedx = -20.f; a = 1; break;
	case KEY_W:speedy = -20.f; b = 1; break;
	case KEY_D:speedx = 20.f; c = 1; break;
	case KEY_S:speedy = 20.f; d = 1; break;
	case KEY_SPACE:
		if(cjz==1) dSetSpriteVisible("fm", 0);
		if(cjz==2) dSetSpriteVisible("js", 0);
		if(cjz==3)
		{
			dSetSpriteVisible("sm", 0);
			g_iGameState = 1;
		} break;
	default:e = 1;
	}
	dSetSpriteVisible("man", e);
	dSetSpriteVisible("dongleft", a);
	dSetSpriteVisible("dongtop", b);
	dSetSpriteVisible("dongright", c);
	dSetSpriteVisible("dongdown", d);
	dSetSpriteLinearVelocity("man", speedx, speedy);
}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void OnKeyUp(const int iKey)
{
	//��ʿ�ƶ�����
	float speedx = 0.f, speedy = 0.f;//int a=0,b=0,c=0,e=0;
	switch (iKey)
	{
	case KEY_A:speedx = 0.f;/*a=1*/break;
	case KEY_W:speedy = 0.f;/*b=1*/break;
	case KEY_D:speedx = 0.f;/*c=1*/break;
	case KEY_S:speedy = 0.f;/*e=1*/break;
	case KEY_SPACE:
		if(cjz==1) {cjz=2;break;}
		if(cjz==2) {cjz=3;break;}
		if(cjz==3) {cjz=1;break;}
		//default:e=1;
	}
	dSetSpriteVisible("man",/*e*/1);
	/*
	dSetSpriteVisible("manleft",a);
	dSetSpriteVisible("manup",b);
	dSetSpriteVisible("manright",c);
	*/
	dSetSpriteVisible("dongleft", 0);
	dSetSpriteVisible("dongtop", 0);
	dSetSpriteVisible("dongright", 0);
	dSetSpriteVisible("dongdown", 0);
	dSetSpriteLinearVelocity("man", speedx, speedy);
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void OnSpriteColSprite(const char *szSrcName, const char *szTarName)
{
	//������ʿ
	//dSetSpriteEnable("man", 0);
	int a = 0, b = 0, c = 0,CS, start,finish;
	start = Mr_Wang.HP;
	if (levelx == 1)
	{
		a = 0, b = 0, c = 0;
		while (1)
		{
			if (Monsters_1[a].existence == 2) break;//ɨ�赯����
			if (strcmp(Monsters_1[a].Name, szTarName)==NULL)//��λ
			{  //������Ӧ����
				if (Monsters_1[a].FangYu < Mr_Wang.GongJi)
				{	
					CS = Monsters_1[a].HP / (Mr_Wang.GongJi-Monsters_1[a].FangYu) ; 
					if( Monsters_1[a].HP % (Mr_Wang.GongJi-Monsters_1[a].FangYu) !=0 )
						CS++;
					if(Monsters_1[a].GongJi>Mr_Wang.FangYu)
					Mr_Wang.HP -= CS * (Monsters_1[a].GongJi-Mr_Wang.FangYu);
					finish=Mr_Wang.HP;
					if(finish>0)
					{	
					if((Monsters_1[a].GongJi-Mr_Wang.FangYu)>=0)
					Mr_Wang.HP=start-(Monsters_1[a].GongJi-Mr_Wang.FangYu);
					Monsters_1[a].HP-=(Mr_Wang.GongJi-Monsters_1[a].FangYu);
					Fight(1,Mr_Wang.HP,Monsters_1[a].HP,Monsters_1[a].GongJi,Monsters_1[a].FangYu);
					if(Monsters_1[a].HP<=0)
					{
					Fight(0,Mr_Wang.HP,Monsters_1[a].HP,Monsters_1[a].GongJi,Monsters_1[a].FangYu);
					Mr_Wang.JinBi += Monsters_1[a].JinBi;
					Mr_Wang.JingYan += Monsters_1[a].Jingyan;
					Show_hero();
					dDeleteSprite(szTarName);
					Monsters_1[a].existence = 0;
					}
					}
					else Mr_Wang.HP=start;
				}
			}
			a++;
		}
		while(1)
		{
			if (Things_1[b].existence == 2) break;//ɨ�赯����
			if (strcmp(Things_1[b].name, szTarName) == NULL)//��λ
			{//������Ӧ����
				Mr_Wang.rank += Things_1[b].rank;
				Mr_Wang.JinBi += Things_1[b].JinBi;
				Mr_Wang.HP += Things_1[b].HP;
				Mr_Wang.GongJi += Things_1[b].GongJi;
				Mr_Wang.FangYu += Things_1[b].FangYu;
				Mr_Wang.YellowKey += Things_1[b].YellowKey;
				Mr_Wang.RedKey += Things_1[b].RedKey;
				Mr_Wang.BlueKey += Things_1[b].BlueKey;
				dDeleteSprite(szTarName);
				Things_1[b].existence = 0;
			}
		b++;
		}
		while(1)
		{
			if (Door_1[c].existence == 2) break;//ɨ�赯����
			if (strcmp(Door_1[c].name, szTarName) == NULL)//��λ
			{  //������Ӧ����
				if (strstr(szTarName, "y") != NULL)
					if (Mr_Wang.YellowKey >= 1)
					{
						Mr_Wang.YellowKey--;
						dDeleteSprite(szTarName);
						Door_1[c].existence = 0;
					}
				if (strstr(szTarName, "b") != NULL)
					if (Mr_Wang.BlueKey >= 1)
					{
						Mr_Wang.BlueKey--;
						dDeleteSprite(szTarName);
						Door_1[c].existence = 0;
					}
				if (strstr(szTarName, "r") != NULL)
					if (Mr_Wang.RedKey >= 1)
					{
						Mr_Wang.RedKey--;
						dDeleteSprite(szTarName);
						Door_1[c].existence = 0;
					}
			}
		c++;
		}
	}
	if (levelx == 2)
	{
		a = 0, b = 0, c = 0;
		while (1)
		{
			if (Monsters_2[a].existence == 2) break;//ɨ�赯����
			if (strcmp(Monsters_2[a].Name, szTarName)==NULL)//��λ
			{//������Ӧ����
				if (Monsters_2[a].FangYu < Mr_Wang.GongJi)
				{
					CS = Monsters_2[a].HP / (Mr_Wang.GongJi-Monsters_2[a].FangYu) ; 
					if( Monsters_2[a].HP % (Mr_Wang.GongJi-Monsters_2[a].FangYu) !=0 )
						CS++;
					if(Monsters_2[a].GongJi>Mr_Wang.FangYu)
					Mr_Wang.HP -= CS * (Monsters_2[a].GongJi-Mr_Wang.FangYu);
					finish=Mr_Wang.HP;
					if(finish>0)
					{
						if((Monsters_2[a].GongJi-Mr_Wang.FangYu)>=0)
					Mr_Wang.HP=start-(Monsters_2[a].GongJi-Mr_Wang.FangYu);
					Monsters_2[a].HP-=(Mr_Wang.GongJi-Monsters_2[a].FangYu);
					Fight(1,Mr_Wang.HP,Monsters_2[a].HP,Monsters_2[a].GongJi,Monsters_2[a].FangYu);
					if(Monsters_2[a].HP<=0)
					{
					Fight(0,Mr_Wang.HP,Monsters_2[a].HP,Monsters_2[a].GongJi,Monsters_2[a].FangYu);
					Mr_Wang.JinBi += Monsters_2[a].JinBi;
					Mr_Wang.JingYan += Monsters_2[a].Jingyan;
					Show_hero();
					dDeleteSprite(szTarName);
					Monsters_2[a].existence = 0;
					}
					}
					else Mr_Wang.HP=start;
				}
			}
			a++;
		}
		while(1)
		{
			if (Things_2[b].existence == 2) break;//ɨ�赯����
			if (strcmp(Things_2[b].name, szTarName) == NULL)//��λ
			{//������Ӧ����
				Mr_Wang.rank += Things_2[b].rank;
				Mr_Wang.JinBi += Things_2[b].JinBi;
				Mr_Wang.HP += Things_2[b].HP;
				Mr_Wang.GongJi += Things_2[b].GongJi;
				Mr_Wang.FangYu += Things_2[b].FangYu;
				Mr_Wang.YellowKey += Things_2[b].YellowKey;
				Mr_Wang.RedKey += Things_2[b].RedKey;
				Mr_Wang.BlueKey += Things_2[b].BlueKey;
				dDeleteSprite(szTarName);
				Things_2[b].existence = 0;
			}
		b++;
		}
		while(1)
		{
			if (Door_2[c].existence == 2) break;//ɨ�赯����
			if (strcmp(Door_2[c].name, szTarName) == NULL)//��λ
			{  //������Ӧ����
				if (strstr(szTarName, "t") != NULL)
					{
						dDeleteSprite(szTarName);
						Door_2[c].existence = 0;
					}
				if (strstr(szTarName, "g") != NULL)
					if (Monsters_4[20].existence==0)
					{
						dDeleteSprite(szTarName);
						Door_2[c].existence = 0;
					}
				if (strstr(szTarName, "y") != NULL)
					if (Mr_Wang.YellowKey >= 1)
					{
						Mr_Wang.YellowKey--;
						dDeleteSprite(szTarName);
						Door_2[c].existence = 0;
					}
				if (strstr(szTarName, "b") != NULL)
					if (Mr_Wang.BlueKey >= 1)
					{
						Mr_Wang.BlueKey--;
						dDeleteSprite(szTarName);
						Door_2[c].existence = 0;
					}
				if (strstr(szTarName, "r") != NULL)
					if (Mr_Wang.RedKey >= 1)
					{
						Mr_Wang.RedKey--;
						dDeleteSprite(szTarName);
						Door_2[c].existence = 0;
					}
			}
		c++;
		}
	}
	if (levelx == 3)
	{
		a = 0, b = 0, c = 0;
		while (1)
		{
			if (Monsters_3[a].existence == 2) break;//ɨ�赯����
			if (strcmp(Monsters_3[a].Name, szTarName)==NULL)//��λ
			{//������Ӧ����
				if (Monsters_3[a].FangYu < Mr_Wang.GongJi)
				{
					CS = Monsters_3[a].HP / (Mr_Wang.GongJi-Monsters_3[a].FangYu) ; 
					if( Monsters_3[a].HP % (Mr_Wang.GongJi-Monsters_3[a].FangYu) !=0 )
						CS++;
					if(Monsters_3[a].GongJi>Mr_Wang.FangYu)
					Mr_Wang.HP -= CS * (Monsters_3[a].GongJi-Mr_Wang.FangYu);
					finish=Mr_Wang.HP;
					if(finish>0)
					{
						if((Monsters_3[a].GongJi-Mr_Wang.FangYu)>=0)
					Mr_Wang.HP=start-(Monsters_3[a].GongJi-Mr_Wang.FangYu);
					Monsters_3[a].HP-=(Mr_Wang.GongJi-Monsters_3[a].FangYu);
					Fight(1,Mr_Wang.HP,Monsters_3[a].HP,Monsters_3[a].GongJi,Monsters_3[a].FangYu);
					if(Monsters_3[a].HP<=0)
					{
					Fight(0,Mr_Wang.HP,Monsters_3[a].HP,Monsters_3[a].GongJi,Monsters_3[a].FangYu);
					Mr_Wang.JinBi += Monsters_3[a].JinBi;
					Mr_Wang.JingYan += Monsters_3[a].Jingyan;
					Show_hero();
					dDeleteSprite(szTarName);
					Monsters_3[a].existence = 0;
					}
					}
					else Mr_Wang.HP=start;
				}
			}
			a++;
		}
		while(1)
		{
			if (Things_3[b].existence == 2) break;//ɨ�赯����
			if (strcmp(Things_3[b].name, szTarName) == NULL)//��λ
			{//������Ӧ����
				Mr_Wang.rank += Things_3[b].rank;
				Mr_Wang.JinBi += Things_3[b].JinBi;
				Mr_Wang.HP += Things_3[b].HP;
				Mr_Wang.GongJi += Things_3[b].GongJi;
				Mr_Wang.FangYu += Things_3[b].FangYu;
				Mr_Wang.YellowKey += Things_3[b].YellowKey;
				Mr_Wang.RedKey += Things_3[b].RedKey;
				Mr_Wang.BlueKey += Things_3[b].BlueKey;
				dDeleteSprite(szTarName);
				Things_3[b].existence = 0;
			}
		b++;
		}
		while(1)
		{
			if (Door_3[c].existence == 2) break;//ɨ�赯����
			if (strcmp(Door_3[c].name, szTarName) == NULL)//��λ
			{  //������Ӧ����
				if (strstr(szTarName, "y") != NULL)
					if (Mr_Wang.YellowKey >= 1)
					{
						Mr_Wang.YellowKey--;
						dDeleteSprite(szTarName);
						Door_3[c].existence = 0;
					}
				if (strstr(szTarName, "b") != NULL)
					if (Mr_Wang.BlueKey >= 1)
					{
						Mr_Wang.BlueKey--;
						dDeleteSprite(szTarName);
						Door_3[c].existence = 0;
					}
				if (strstr(szTarName, "r") != NULL)
					if (Mr_Wang.RedKey >= 1)
					{
						Mr_Wang.RedKey--;
						dDeleteSprite(szTarName);
						Door_3[c].existence = 0;
					}
			}
		c++;
		}
	}
	if (levelx == 4)
	{
		a = 0, b = 0, c = 0;
		while (1)
		{
			if (Monsters_4[a].existence == 2) break;//ɨ�赯����
			if (strcmp(Monsters_4[a].Name, szTarName)==NULL)//��λ
			{//������Ӧ����
				if (Monsters_4[a].FangYu < Mr_Wang.GongJi)
				{
					CS = Monsters_4[a].HP / (Mr_Wang.GongJi-Monsters_4[a].FangYu) ; 
					if( Monsters_4[a].HP % (Mr_Wang.GongJi-Monsters_4[a].FangYu) !=0 )
						CS++;
					if(Monsters_4[a].GongJi>Mr_Wang.FangYu)
					Mr_Wang.HP -= CS * (Monsters_4[a].GongJi-Mr_Wang.FangYu);
					finish=Mr_Wang.HP;
					if(finish>0)
					{	
						if((Monsters_4[a].GongJi-Mr_Wang.FangYu)>=0)
					Mr_Wang.HP=start-(Monsters_4[a].GongJi-Mr_Wang.FangYu);
					Monsters_4[a].HP-=(Mr_Wang.GongJi-Monsters_4[a].FangYu);
					Fight(1,Mr_Wang.HP,Monsters_4[a].HP,Monsters_4[a].GongJi,Monsters_4[a].FangYu);
					if(Monsters_4[a].HP<=0)
					{
					Fight(0,Mr_Wang.HP,Monsters_4[a].HP,Monsters_4[a].GongJi,Monsters_4[a].FangYu);
					Mr_Wang.JinBi += Monsters_4[a].JinBi;
					Mr_Wang.JingYan += Monsters_4[a].Jingyan;
					Show_hero();
					dDeleteSprite(szTarName);
					Monsters_4[a].existence = 0;
					}
					}
					else Mr_Wang.HP=start;
				}
			}
			a++;
		}
		while(1)
		{
			if (Things_4[b].existence == 2) break;//ɨ�赯����
			if (strcmp(Things_4[b].name, szTarName) == NULL)//��λ
			{//������Ӧ����
				Mr_Wang.rank += Things_4[b].rank;
				Mr_Wang.JinBi += Things_4[b].JinBi;
				Mr_Wang.HP += Things_4[b].HP;
				Mr_Wang.GongJi += Things_4[b].GongJi;
				Mr_Wang.FangYu += Things_4[b].FangYu;
				Mr_Wang.YellowKey += Things_4[b].YellowKey;
				Mr_Wang.RedKey += Things_4[b].RedKey;
				Mr_Wang.BlueKey += Things_4[b].BlueKey;
				dDeleteSprite(szTarName);
				Things_4[b].existence = 0;
			}
		b++;
		}
		while(1)
		{
			if (Door_4[c].existence == 2) break;//ɨ�赯����
			if (strcmp(Door_4[c].name, szTarName) == NULL)//��λ
			{  //������Ӧ����
				if (strstr(szTarName, "t") != NULL)
					{
						dDeleteSprite(szTarName);
						Door_4[c].existence = 0;
					}
				if (strstr(szTarName, "y") != NULL)
					if (Mr_Wang.YellowKey >= 1)
					{
						Mr_Wang.YellowKey--;
						dDeleteSprite(szTarName);
						Door_4[c].existence = 0;
					}
				if (strstr(szTarName, "b") != NULL)
					if (Mr_Wang.BlueKey >= 1)
					{
						Mr_Wang.BlueKey--;
						dDeleteSprite(szTarName);
						Door_4[c].existence = 0;
					}
				if (strstr(szTarName, "r") != NULL)
					if (Mr_Wang.RedKey >= 1)
					{
						Mr_Wang.RedKey--;
						dDeleteSprite(szTarName);
						Door_4[c].existence = 0;
					}
			}
		c++;
		}
	}
	if (levelx == 5)
	{
		a = 0, b = 0, c = 0;
		while (1)
		{
			if (Monsters_5[a].existence == 2) break;//ɨ�赯����
			if (strcmp(Monsters_5[a].Name, szTarName)==NULL)//��λ
			{//������Ӧ����
				if (Monsters_5[a].FangYu < Mr_Wang.GongJi)
				{
					CS = Monsters_5[a].HP / (Mr_Wang.GongJi-Monsters_5[a].FangYu) ; 
					if( Monsters_5[a].HP % (Mr_Wang.GongJi-Monsters_5[a].FangYu) !=0 )
						CS++;
					if(Monsters_5[a].GongJi>Mr_Wang.FangYu)
					Mr_Wang.HP -= CS * (Monsters_5[a].GongJi-Mr_Wang.FangYu);
					finish=Mr_Wang.HP;
					if(finish>0)
					{	
						if((Monsters_5[a].GongJi-Mr_Wang.FangYu)>=0)
					Mr_Wang.HP=start-(Monsters_5[a].GongJi-Mr_Wang.FangYu);
					Monsters_5[a].HP-=(Mr_Wang.GongJi-Monsters_5[a].FangYu);
					Fight(1,Mr_Wang.HP,Monsters_5[a].HP,Monsters_5[a].GongJi,Monsters_5[a].FangYu);
					if(Monsters_5[a].HP<=0)
					{
					Fight(0,Mr_Wang.HP,Monsters_5[a].HP,Monsters_5[a].GongJi,Monsters_5[a].FangYu);
					Mr_Wang.JinBi += Monsters_5[a].JinBi;
					Mr_Wang.JingYan += Monsters_5[a].Jingyan;
					Show_hero();
					dDeleteSprite(szTarName);
					Monsters_5[a].existence = 0;
					}
					}
					else Mr_Wang.HP=start;
				}
			}
			a++;
		}
		while(1)
		{
			if (Things_5[b].existence == 2) break;//ɨ�赯����
			if (strcmp(Things_5[b].name, szTarName) == NULL)//��λ
			{//������Ӧ����
				Mr_Wang.rank += Things_5[b].rank;
				Mr_Wang.JinBi += Things_5[b].JinBi;
				Mr_Wang.HP += Things_5[b].HP;
				Mr_Wang.GongJi += Things_5[b].GongJi;
				Mr_Wang.FangYu += Things_5[b].FangYu;
				Mr_Wang.YellowKey += Things_5[b].YellowKey;
				Mr_Wang.RedKey += Things_5[b].RedKey;
				Mr_Wang.BlueKey += Things_5[b].BlueKey;
				dDeleteSprite(szTarName);
				Things_5[b].existence = 0;
			}
		b++;
		}
		while(1)
		{
			if (Door_5[c].existence == 2) break;//ɨ�赯����
			if (strcmp(Door_5[c].name, szTarName) == NULL)//��λ
			{  //������Ӧ����
				if (strstr(szTarName, "y") != NULL)
					if (Mr_Wang.YellowKey >= 1)
					{
						Mr_Wang.YellowKey--;
						dDeleteSprite(szTarName);
						Door_5[c].existence = 0;
					}
				if (strstr(szTarName, "b") != NULL)
					if (Mr_Wang.BlueKey >= 1)
					{
						Mr_Wang.BlueKey--;
						dDeleteSprite(szTarName);
						Door_5[c].existence = 0;
					}
				if (strstr(szTarName, "r") != NULL)
					if (Mr_Wang.RedKey >= 1)
					{
						Mr_Wang.RedKey--;
						dDeleteSprite(szTarName);
						Door_5[c].existence = 0;
					}
			}
		c++;
		}
	}
	if (levelx == 6)
	{
		a = 0, b = 0, c = 0;
		while (1)
		{
			if (Monsters_6[a].existence == 2) break;//ɨ�赯����
			if (strcmp(Monsters_6[a].Name, szTarName)==NULL)//��λ
			{//������Ӧ����
				if (Monsters_6[a].FangYu < Mr_Wang.GongJi)
				{
					CS = Monsters_6[a].HP / (Mr_Wang.GongJi-Monsters_6[a].FangYu) ; 
					if( Monsters_6[a].HP % (Mr_Wang.GongJi-Monsters_6[a].FangYu) !=0 )
						CS++;
					if(Monsters_6[a].GongJi>Mr_Wang.FangYu)
					Mr_Wang.HP -= CS * (Monsters_6[a].GongJi-Mr_Wang.FangYu);
					finish=Mr_Wang.HP;
					if(finish>0)
					{	
						if((Monsters_6[a].GongJi-Mr_Wang.FangYu)>=0)
					Mr_Wang.HP=start-(Monsters_6[a].GongJi-Mr_Wang.FangYu);
					Monsters_6[a].HP-=(Mr_Wang.GongJi-Monsters_6[a].FangYu);
					Fight(1,Mr_Wang.HP,Monsters_6[a].HP,Monsters_6[a].GongJi,Monsters_6[a].FangYu);
					if(Monsters_6[a].HP<=0)
					{
					Fight(0,Mr_Wang.HP,Monsters_6[a].HP,Monsters_6[a].GongJi,Monsters_6[a].FangYu);
					Mr_Wang.JinBi += Monsters_6[a].JinBi;
					Mr_Wang.JingYan += Monsters_6[a].Jingyan;
					Show_hero();
					dDeleteSprite(szTarName);
					Monsters_6[a].existence = 0;
					}
					}
					else Mr_Wang.HP=start;
				}
			}
			a++;
		}
		while(1)
		{
			if (Things_6[b].existence == 2) break;//ɨ�赯����
			if (strcmp(Things_6[b].name, szTarName) == NULL)//��λ
			{//������Ӧ����
				Mr_Wang.rank += Things_6[b].rank;
				Mr_Wang.JinBi += Things_6[b].JinBi;
				Mr_Wang.HP += Things_6[b].HP;
				Mr_Wang.GongJi += Things_6[b].GongJi;
				Mr_Wang.FangYu += Things_6[b].FangYu;
				Mr_Wang.YellowKey += Things_6[b].YellowKey;
				Mr_Wang.RedKey += Things_6[b].RedKey;
				Mr_Wang.BlueKey += Things_6[b].BlueKey;
				dDeleteSprite(szTarName);
				Things_6[b].existence = 0;
			}
		b++;
		}
		while(1)
		{
			if (Door_6[c].existence == 2) break;//ɨ�赯����
			if (strcmp(Door_6[c].name, szTarName) == NULL)//��λ
			{  //������Ӧ����
				if (strstr(szTarName, "y") != NULL)
					if (Mr_Wang.YellowKey >= 1)
					{
						Mr_Wang.YellowKey--;
						dDeleteSprite(szTarName);
						Door_6[c].existence = 0;
					}
				if (strstr(szTarName, "b") != NULL)
					if (Mr_Wang.BlueKey >= 1)
					{
						Mr_Wang.BlueKey--;
						dDeleteSprite(szTarName);
						Door_6[c].existence = 0;
					}
				if (strstr(szTarName, "r") != NULL)
					if (Mr_Wang.RedKey >= 1)
					{
						Mr_Wang.RedKey--;
						dDeleteSprite(szTarName);
						Door_6[c].existence = 0;
					}
			}
		c++;
		}
	}
	if (levelx == 7)
	{
		a = 0, b = 0, c = 0;
		while (1)
		{
			if (Monsters_7[a].existence == 2) break;//ɨ�赯����
			if (strcmp(Monsters_7[a].Name, szTarName)==NULL)//��λ
			{//������Ӧ����
				if (Monsters_7[a].FangYu < Mr_Wang.GongJi)
				{
					CS = Monsters_7[a].HP / (Mr_Wang.GongJi-Monsters_7[a].FangYu) ; 
					if( Monsters_7[a].HP % (Mr_Wang.GongJi-Monsters_7[a].FangYu) !=0 )
						CS++;
					if(Monsters_7[a].GongJi>Mr_Wang.FangYu)
					Mr_Wang.HP -= CS * (Monsters_7[a].GongJi-Mr_Wang.FangYu);
					finish=Mr_Wang.HP;
					if(finish>0)
					{	
						if((Monsters_7[a].GongJi-Mr_Wang.FangYu)>=0)
					Mr_Wang.HP=start-(Monsters_7[a].GongJi-Mr_Wang.FangYu);
					Monsters_7[a].HP-=(Mr_Wang.GongJi-Monsters_7[a].FangYu);
					Fight(1,Mr_Wang.HP,Monsters_7[a].HP,Monsters_7[a].GongJi,Monsters_7[a].FangYu);
					if(Monsters_7[a].HP<=0)
					{
					Fight(0,Mr_Wang.HP,Monsters_7[a].HP,Monsters_7[a].GongJi,Monsters_7[a].FangYu);
					Mr_Wang.JinBi += Monsters_7[a].JinBi;
					Mr_Wang.JingYan += Monsters_7[a].Jingyan;
					Show_hero();
					dDeleteSprite(szTarName);
					Monsters_7[a].existence = 0;
					}
					}
					else Mr_Wang.HP=start;
				}
			}
			a++;
		}
		while(1)
		{
			if (Things_7[b].existence == 2) break;//ɨ�赯����
			if (strcmp(Things_7[b].name, szTarName) == NULL)//��λ
			{//������Ӧ����
				Mr_Wang.rank += Things_7[b].rank;
				Mr_Wang.JinBi += Things_7[b].JinBi;
				Mr_Wang.HP += Things_7[b].HP;
				Mr_Wang.GongJi += Things_7[b].GongJi;
				Mr_Wang.FangYu += Things_7[b].FangYu;
				Mr_Wang.YellowKey += Things_7[b].YellowKey;
				Mr_Wang.RedKey += Things_7[b].RedKey;
				Mr_Wang.BlueKey += Things_7[b].BlueKey;
				dDeleteSprite(szTarName);
				Things_7[b].existence = 0;
			}
		b++;
		}
		while(1)
		{
			if (Door_7[c].existence == 2) break;//ɨ�赯����
			if (strcmp(Door_7[c].name, szTarName) == NULL)//��λ
			{  //������Ӧ����
				if (strstr(szTarName, "t") != NULL)
					{
						dDeleteSprite(szTarName);
						Door_7[c].existence = 0;
					}
				if (strstr(szTarName, "y") != NULL)
					if (Mr_Wang.YellowKey >= 1)
					{
						Mr_Wang.YellowKey--;
						dDeleteSprite(szTarName);
						Door_7[c].existence = 0;
					}
				if (strstr(szTarName, "b") != NULL)
					if (Mr_Wang.BlueKey >= 1)
					{
						Mr_Wang.BlueKey--;
						dDeleteSprite(szTarName);
						Door_7[c].existence = 0;
					}
				if (strstr(szTarName, "r") != NULL)
					if (Mr_Wang.RedKey >= 1)
					{
						Mr_Wang.RedKey--;
						dDeleteSprite(szTarName);
						Door_7[c].existence = 0;
					}
			}
		c++;
		}
		if(strcmp(szTarName, "GongZhu") == NULL)
		{
			dSetSpriteVisible("MT", 1);
			JS=0;
		}
	}
	while(1)
	{
	if(Mr_Wang.JingYan>=15)
	{
	Mr_Wang.JingYan-=15;
	Mr_Wang.rank++;
	Mr_Wang.HP+=20;
	Mr_Wang.GongJi+=3;
	Mr_Wang.FangYu+=3;
	}
	else break;
	}
	Show_hero();
	//������ʿ
//	dSetSpriteEnable("man", 1);
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void OnSpriteColWorldLimit(const char *szName, const int iColSide)
{

}
