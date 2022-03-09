//项目名称：c语言文字冒险游戏
//修改日期：2018.11.28
//修改日期v2：2021.5.24（修复商店重复购买导致属性错误，优化个人信息及战斗模块）
//修改日期v3：2022.3.2（添加冒险难度系统，修正boss普攻伤害错误，优化战斗中途死亡仍在副本里的问题，个人信息系统功能大添加，陆续添加功能） 
//作者：Y-kirito & Z-lee
//声明：仅供娱乐，转载声明出处 
#include<stdio.h>
#define DECISION "你想去哪？\n1    村庄\n2    远征\n3    查看个人信息\n4    存档（首次游戏请先存储一次再游戏）\n5    结束游戏（自动存档）"//待添加 
#define DECISION2 "你想挑战的难度是：1.简单  2.冒险  3.困难  4.地狱"//待添加 
#define DECISION3 "你想挑战的副本是：1.史莱姆森林  2.哥布林部落  3.鬼人古堡  4.返回村庄"//待添加  
void fjshop(void);//防具店
void wqshop(void);//武器店
void vill(void);//村庄
void zdmk(void);//攻击
void lvup(void);//升级
void slm(void);//史莱姆
void slm1(void);
void slm2(void);//完毕
void gbl(void);//哥布林
void gbl1(void);
void gbl2(void);//end
void gr(void);//鬼人
void gr1(void);//
void gr2(void);//end//我把这些函数整理了下，显得整洁 
void maoxian(void);
void pi(void);//personal information本来想叫rw(人物)，但害怕后期加任务栏 
void cd(void);//存档 
void dq(void);//读取 
void cc(void);//存储 
int sp,ex=0,i=1,dj=1,cj=1,bj=1,szj=1,gd=0,viz=0,sh,tybosshp,x,hpboss,fb,n=0,xx=0;
int bosshp[]={100,300,800};
int ndxs[]={1,3,5,8};
int pi1,lv=1,hp=220,mp=22,p=5,q=20,eak=0,eak1=0,eak2=0,edf=0,atk=5;//个人信息里的变量,eak1为装备攻击力，eak2为buff攻击力 
int a[8]={lv,hp,mp,ex,gd,edf,p,q};
void ch(void);//称号 
void sx(void);//属性 
void bb(void);//背包 
void jn(void);//技能 
int main(void)//主程序开始
{
while(2>1)
{
	
	while(x==0)
	{
		printf("%s\n",DECISION);
		scanf("%d",&x);
		while(x==1)
		{
			vill();
			viz=0;
			x=0;
		}
		while(x==2)
		{
			maoxian();
			x=0;
		}
		while(x==3)
		{
			pi();
			x=0;
		}
		while(x==4)
		{
			cd();
			x=0;
		}
		while(x==5)
		{
			cc();
			x=-1;
		}
	}
	break; 
}
return 0;
}//主程序到此处完结
 void cd(void)//存档模块 
 {
 	 int du;
 	 printf("你想要读取还是存储?\n1  读取\n2  存储\n3  取消\n");
	 scanf("%d",&du); 
	 if(du==1)
  {
     dq();
     du=-1;
  }	
	 else if(du==2)
  {
	 cc();
	 du=-1;
  }
  	 else if(du==3)
  {
    du=-1;
  }
}
void dq(void)//读取 
{
     FILE *fpRead=fopen("data.txt","r");
     int b[7];
	for(int i=0;i<8;i++)
	{
		fscanf(fpRead,"%d ",&b[i]);
		a[i]=b[i];
	}
	lv=a[0],hp=a[1],mp=a[2],ex=a[3],gd=a[4],edf=a[5],p=a[6],q=a[7];
  }	
void cc(void)//存储
{
	 FILE *fpWrite=fopen("data.txt","w");
	for(int i=0;i<8;i++)
	{
	fprintf(fpWrite,"%d ",a[i]);
    }
    fclose(fpWrite);
  }
void pi(void)//个人信息模块
 {
 printf("                  个人信息                \n") ;
 printf("称号：暂未开放 \n");//暂无
 printf("等级:%d    hp:%d     mp:%d     经验:%d     金币:%d     减伤:%d\n",lv,hp,mp,ex,gd,edf); 
 //printf("武器:%s    上衣:%s     裤子:%s     鞋子:%s     护身符:%s     翅膀:%s\n");
 printf("技能伤害：1.重击:%d   2.嗜血:boss越强，伤害越高,吸血回复生命    3.星爆气流斩:%d  \n",atk,q);
 printf("请问是否进入详情界面：1.称号   2.属性   3.背包    4.技能   5.返回主界面\n");//待添加
 scanf("%d",&pi1);
 while(pi1==1)
 {
 ch();break;
 }
 while(pi1==2)
 {
 sx();break;
 }
 while(pi1==3)
 {
 bb();break;
 }
 while(pi1==4)
 {
 jn();break;
 }
 while(pi1==5)
 {
 pi1=-1;
 }
 }
 
void ch(void)//称号系统，添加获取条件，附加属性 
{
	printf("暂无\n"); 
 } 
void sx(void)//属性系统，添加rpg游戏常见属性物攻，法伤，闪避，掉宝率等 
{
	printf("暂无\n"); 
 }
 void bb(void)//背包系统，添加装备（重做商店）、实物，药水buff（几回合内增加属性）等 
{
	printf("暂无\n"); 
 }
 void jn(void)//技能系统，添加技能点，改为可升级及进阶型技能系统 
{
	printf("暂无\n"); 
 }
 
void lvup(void)//升级模块
{
	while(ex>100*lv)//把经验栏提出来，因为每个怪物经验不同 

{

printf("升级了，你的等级为%d\n",lv+1);	

p=p+3;

q=q+10;

ex=ex-100*lv;

lv=lv+1;

hp=200+20*lv;

mp=20+2*lv;



}
} 
void vill(void)//村庄
{
	while(viz==0)
{
	printf("欢迎回到村庄勇士\n请选择目的\n1    武器店\n2    防具店\n3    退出村庄\n");
	scanf("%d",&viz);
	while(viz>=3)
	{
		printf("退出村庄\n");
		viz=-1;
	}
		while(viz==1)
	{	
  		wqshop();
  	}
  	    while(viz==2)
	{
		fjshop();
	}
}
}//村庄模块
void wqshop(void)//武器店 
{
		while(viz==1)
		{   int wq=0;
			printf("你好勇士，欢迎来到武器店\n请问你需要什么？\n1   短剑(伤害加10)  500金币\n2   长剑(伤害加30)  2000金币\n3   退出武器店\n");
			scanf("%d",&wq);
			if(wq>2)
			{
				while(wq>3)
				{
					printf("未开放，敬请期待\n");
					wq=0;
				}
				while(wq==3)
				{
					printf("你选择退出\n;");
					viz=0;
					wq=0;
				}
			}
			else
			{
				while(wq==1)
				{
				if(gd>=500)
				{
					if(dj==1)
					{
						printf("你购买了短剑，伤害加十，重复购买无效\n");
						eak1=10;
						eak=eak1+eak2;//声明全局变量，装备加成攻击力
						atk=p+eak;
						q=q+eak;
						gd=gd-500;
						dj=0;
						wq=0;
					}
					else
					{
						printf("你已经购买过了\n");
					}
				}
				else
				{
					printf("金币不足\n");	
				}
				 wq=0;
				}
				while(wq==2)
				{
				if(gd>=2000)
				{
					if(cj==1)
					{
						printf("你购买了长剑，伤害加三十，重复购买无效\n");
						eak1=30;
						eak=eak1+eak2;//声明全局变量，装备加成攻击力
						atk=p+eak;
						q=q+eak;
						gd=gd-2000;
						cj=0;
					}
					else
					{
						printf("你已经购买过了\n");
					}
				}
				else
				{
					printf("金币不足\n");
				}
				wq=0;
				}
			}
		}
}
 void fjshop(void)//防具店
{
		while(viz==2)
		{   int fj=0;
			printf("你好勇士，欢迎来到防具店\n请问你需要什么？\n1   布甲(伤害抵消4)  500金币\n2   锁子甲(伤害抵消7)  1000金币\n3   退出防具店\n");
			scanf("%d",&fj);
			if(fj>2)
			{
				while(fj>3)
				{
					printf("未开放，敬请期待\n");
					fj=0;
					
				}
				while(fj==3)
				{
					printf("你选择退出\n;");
					viz=0;
					fj=0;
				}
			}
			else
			{
				while(fj==1)
				{
				if(gd>500)
				{
					if(bj==1)
					{
						printf("你购买了布甲，伤害抵消4，重复购买无效\n");
						edf=edf+4;//声明全局变量，装备加成攻击力
						gd=gd-500;
						bj=0;
					}
					else
					{
						printf("你已经购买过了\n");
					}
				}
				else
				{
					printf("金币不足\n");
				}
				fj=0;
				}
				while(fj==2)
				{
				if(gd>1000)
				{
					if(szj==1)
					{
						printf("你购买了锁子甲，伤害抵消7，重复购买无效\n");
						edf=edf+7;//声明全局变量，装备加成攻击力
						gd=gd-1000;
						szj=0;
					}
					else
					{
						printf("你已经购买过了\n");
					}
				}
				else
				{
					printf("金币不足\n");
				}
				fj=0;
				}
				
			}
		}
}
void maoxian(void)//冒险模块 
{
printf("%s\n",DECISION2);
scanf("%d",&n);
if(n<0||n>4)
{printf("输入错误，请重新选择\n");
scanf("%d",&n);
}
printf("%s\n",DECISION3);
scanf("%d",&fb);
if(fb>4)
	{
		printf("未开放请重新选择\n");
	}
else
	{

 switch (fb)//这样看起来不简洁，但后期加掉落物品时很方便 

	{

      case 1:
    slm();
	  break;
      
	  case 2:
    slm();
    if(i!=2)break;
    gbl();
      break;
      
	  case 3:
    slm();if(i!=2)break;slm();if(i!=2)break;//同上 
	gbl();if(i!=2)break; 	
    gr();
      break;
      
      
      case 4:
	vill();
	  break; 
}
}
lvup();
hp=200+20*lv;
mp=20+2*lv;
}
void slm(void)//怪物模块 
{
  slm1();
  zdmk();
  slm2();
}
void gbl(void)
{
  gbl1();
  zdmk();
  gbl2();
}
void gr(void)
{
  gr1();
  zdmk();
  gr2();
}
void zdmk(void)//战斗模块 
{
   while(hp>0&&tybosshp>0)
	{
    	i=1; 
    	printf("人物状态：攻击力：%d  血量：%d  魔力值：%d  \n",p,hp,mp);
        printf("请选择技能\n1.重击     (造成%d点伤害，mp+1)\n2.嗜血     (造成boss当前生命值百分之八的伤害，吸血伤害的3%，mp-3)\n3.星爆气流斩     (造成%d点伤害，mp-5)\n",atk,q);//待添加 
        scanf("%d",&sp);

        while(4<sp)
    	{
           printf("技能选择错误，请重新选择\n");
           sp=-1;
    	}
        while(sp==1)
    	{
 
         tybosshp=tybosshp-atk;
         mp++;
         printf("你使用技能重击对boss造成%d点伤害,恢复一点mp,boss还有%d血量\n",p,tybosshp);
         sp=0;

        }

        while(sp==2)
    	{

        while(mp>=3&&sp==2)
    	{
    	sh=tybosshp*0.08;
        tybosshp=tybosshp*0.92;
        xx=xx+0.3*sh;//吸血 
        hp=hp+xx;
    	mp=mp-3;
        printf("你使用技能嗜血对boss造成%d点伤害，吸血%d，boss还有%d血量\n",sh,xx,tybosshp);
        sp=0;
		}
     
	    while(mp<3&&sp==2)
		{
        printf("mp不足3点,无法释放技能嗜血\n");
        sp=-1;
    	}
        }

    	while(sp==3)
    	{

    	while(mp>=5&&sp==3)
        {
        tybosshp=tybosshp-q;
        mp=mp-5;
	    sp=0;
        printf("你使用技能星爆气流斩对boss造成%d点伤害，boss还有%d血量\n",q,tybosshp);//待定 
		}
		while(mp<5&&sp==3)
			{
				printf("mp不足5点,无法释放技能星爆气流斩 \n");
				sp=-1;
			}
		}
    	while(tybosshp>0&&sp==0)
    	{
          if(tybosshp>hpboss*0.15)//boss血量下降到15%以下暴怒 
	    	{
			sh=15+hpboss*0.1-edf;
			sh=(sh>0)?sh:0;
			hp=hp-sh;
			printf("boss撞了你一下，你的hp减少了%d点\n",sh);
			sp=-1;
			}
        else
        {
           printf("boss变为狂暴状态");
		   sh=15+hpboss*0.3-edf;//伤害提升 
		   sh=(sh>0)?sh:0;
		   hp=hp-sh;
		   printf("boss使用疯狂乱打，你的hp减少了%d点\n",sh); 
		   sp=-1; 
		}
		}
	}
	while(tybosshp<=0&&i==1)
	{
		printf("你已击杀BOSS,恭喜通关！\n");
		i=i+1;
	}
	while(hp<0&&i==1)
	{
		printf("你已阵亡，请在简单副本提升能力，继续努力吧\n");
		i=i+2;
	}

}

//分割线史莱姆
void slm1(void)
{
  printf("史莱姆出现\n");

  hpboss=bosshp[0]*ndxs[n-1];//BOSS的生命值

  tybosshp=hpboss;
}
void slm2(void)
{
if(i==2)
  {
	  printf("你获得20ex,50金币\n");//怪物经验已全部调整 

      ex=ex+20;

      gd=gd+50;
      
 	  printf("你的经验为%d\n",ex);
  }
}

void gbl1(void)//哥布林
{
  printf("哥布林出现\n");

  hpboss=bosshp[1]*ndxs[n-1];//BOSS的生命值

  tybosshp=hpboss;
}
void gbl2(void)//end
{
if (i==2)
 {
     printf("你获得100ex,200金币\n");

     ex=ex+100;

     gd=gd+200;
     
     printf("你的经验为%d\n",ex);
  }
  }
  void gr1(void)//鬼人
{
  printf("鬼人出现\n");
  
  hpboss=bosshp[2]*ndxs[n-1];//BOSS的生命值

  tybosshp=hpboss;
}
void gr2(void)
{
	  if(i==2)
  {
	  printf("你获得300ex,500金币\n");

      ex=ex+300;

      gd=gd+500;
      
      printf("你的经验为%d\n",ex);
  }
}

