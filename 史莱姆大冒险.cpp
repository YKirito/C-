//��Ŀ���ƣ�c��������ð����Ϸ
//�޸����ڣ�2018.11.28
//�޸�����v2��2021.5.24���޸��̵��ظ����������Դ����Ż�������Ϣ��ս��ģ�飩
//�޸�����v3��2022.3.2�����ð���Ѷ�ϵͳ������boss�չ��˺������Ż�ս����;�������ڸ���������⣬������Ϣϵͳ���ܴ���ӣ�½����ӹ��ܣ� 
//���ߣ�Y-kirito & Z-lee
//�������������֣�ת���������� 
#include<stdio.h>
#define DECISION "����ȥ�ģ�\n1    ��ׯ\n2    Զ��\n3    �鿴������Ϣ\n4    �浵���״���Ϸ���ȴ洢һ������Ϸ��\n5    ������Ϸ���Զ��浵��"//����� 
#define DECISION2 "������ս���Ѷ��ǣ�1.��  2.ð��  3.����  4.����"//����� 
#define DECISION3 "������ս�ĸ����ǣ�1.ʷ��ķɭ��  2.�粼�ֲ���  3.���˹ű�  4.���ش�ׯ"//�����  
void fjshop(void);//���ߵ�
void wqshop(void);//������
void vill(void);//��ׯ
void zdmk(void);//����
void lvup(void);//����
void slm(void);//ʷ��ķ
void slm1(void);
void slm2(void);//���
void gbl(void);//�粼��
void gbl1(void);
void gbl2(void);//end
void gr(void);//����
void gr1(void);//
void gr2(void);//end//�Ұ���Щ�����������£��Ե����� 
void maoxian(void);
void pi(void);//personal information�������rw(����)�������º��ڼ������� 
void cd(void);//�浵 
void dq(void);//��ȡ 
void cc(void);//�洢 
int sp,ex=0,i=1,dj=1,cj=1,bj=1,szj=1,gd=0,viz=0,sh,tybosshp,x,hpboss,fb,n=0,xx=0;
int bosshp[]={100,300,800};
int ndxs[]={1,3,5,8};
int pi1,lv=1,hp=220,mp=22,p=5,q=20,eak=0,eak1=0,eak2=0,edf=0,atk=5;//������Ϣ��ı���,eak1Ϊװ����������eak2Ϊbuff������ 
int a[8]={lv,hp,mp,ex,gd,edf,p,q};
void ch(void);//�ƺ� 
void sx(void);//���� 
void bb(void);//���� 
void jn(void);//���� 
int main(void)//������ʼ
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
}//�����򵽴˴����
 void cd(void)//�浵ģ�� 
 {
 	 int du;
 	 printf("����Ҫ��ȡ���Ǵ洢?\n1  ��ȡ\n2  �洢\n3  ȡ��\n");
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
void dq(void)//��ȡ 
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
void cc(void)//�洢
{
	 FILE *fpWrite=fopen("data.txt","w");
	for(int i=0;i<8;i++)
	{
	fprintf(fpWrite,"%d ",a[i]);
    }
    fclose(fpWrite);
  }
void pi(void)//������Ϣģ��
 {
 printf("                  ������Ϣ                \n") ;
 printf("�ƺţ���δ���� \n");//����
 printf("�ȼ�:%d    hp:%d     mp:%d     ����:%d     ���:%d     ����:%d\n",lv,hp,mp,ex,gd,edf); 
 //printf("����:%s    ����:%s     ����:%s     Ь��:%s     �����:%s     ���:%s\n");
 printf("�����˺���1.�ػ�:%d   2.��Ѫ:bossԽǿ���˺�Խ��,��Ѫ�ظ�����    3.�Ǳ�����ն:%d  \n",atk,q);
 printf("�����Ƿ����������棺1.�ƺ�   2.����   3.����    4.����   5.����������\n");//�����
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
 
void ch(void)//�ƺ�ϵͳ����ӻ�ȡ�������������� 
{
	printf("����\n"); 
 } 
void sx(void)//����ϵͳ�����rpg��Ϸ���������﹥�����ˣ����ܣ������ʵ� 
{
	printf("����\n"); 
 }
 void bb(void)//����ϵͳ�����װ���������̵꣩��ʵ�ҩˮbuff�����غ����������ԣ��� 
{
	printf("����\n"); 
 }
 void jn(void)//����ϵͳ����Ӽ��ܵ㣬��Ϊ�������������ͼ���ϵͳ 
{
	printf("����\n"); 
 }
 
void lvup(void)//����ģ��
{
	while(ex>100*lv)//�Ѿ��������������Ϊÿ�����ﾭ�鲻ͬ 

{

printf("�����ˣ���ĵȼ�Ϊ%d\n",lv+1);	

p=p+3;

q=q+10;

ex=ex-100*lv;

lv=lv+1;

hp=200+20*lv;

mp=20+2*lv;



}
} 
void vill(void)//��ׯ
{
	while(viz==0)
{
	printf("��ӭ�ص���ׯ��ʿ\n��ѡ��Ŀ��\n1    ������\n2    ���ߵ�\n3    �˳���ׯ\n");
	scanf("%d",&viz);
	while(viz>=3)
	{
		printf("�˳���ׯ\n");
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
}//��ׯģ��
void wqshop(void)//������ 
{
		while(viz==1)
		{   int wq=0;
			printf("�����ʿ����ӭ����������\n��������Ҫʲô��\n1   �̽�(�˺���10)  500���\n2   ����(�˺���30)  2000���\n3   �˳�������\n");
			scanf("%d",&wq);
			if(wq>2)
			{
				while(wq>3)
				{
					printf("δ���ţ������ڴ�\n");
					wq=0;
				}
				while(wq==3)
				{
					printf("��ѡ���˳�\n;");
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
						printf("�㹺���˶̽����˺���ʮ���ظ�������Ч\n");
						eak1=10;
						eak=eak1+eak2;//����ȫ�ֱ�����װ���ӳɹ�����
						atk=p+eak;
						q=q+eak;
						gd=gd-500;
						dj=0;
						wq=0;
					}
					else
					{
						printf("���Ѿ��������\n");
					}
				}
				else
				{
					printf("��Ҳ���\n");	
				}
				 wq=0;
				}
				while(wq==2)
				{
				if(gd>=2000)
				{
					if(cj==1)
					{
						printf("�㹺���˳������˺�����ʮ���ظ�������Ч\n");
						eak1=30;
						eak=eak1+eak2;//����ȫ�ֱ�����װ���ӳɹ�����
						atk=p+eak;
						q=q+eak;
						gd=gd-2000;
						cj=0;
					}
					else
					{
						printf("���Ѿ��������\n");
					}
				}
				else
				{
					printf("��Ҳ���\n");
				}
				wq=0;
				}
			}
		}
}
 void fjshop(void)//���ߵ�
{
		while(viz==2)
		{   int fj=0;
			printf("�����ʿ����ӭ�������ߵ�\n��������Ҫʲô��\n1   ����(�˺�����4)  500���\n2   ���Ӽ�(�˺�����7)  1000���\n3   �˳����ߵ�\n");
			scanf("%d",&fj);
			if(fj>2)
			{
				while(fj>3)
				{
					printf("δ���ţ������ڴ�\n");
					fj=0;
					
				}
				while(fj==3)
				{
					printf("��ѡ���˳�\n;");
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
						printf("�㹺���˲��ף��˺�����4���ظ�������Ч\n");
						edf=edf+4;//����ȫ�ֱ�����װ���ӳɹ�����
						gd=gd-500;
						bj=0;
					}
					else
					{
						printf("���Ѿ��������\n");
					}
				}
				else
				{
					printf("��Ҳ���\n");
				}
				fj=0;
				}
				while(fj==2)
				{
				if(gd>1000)
				{
					if(szj==1)
					{
						printf("�㹺�������Ӽף��˺�����7���ظ�������Ч\n");
						edf=edf+7;//����ȫ�ֱ�����װ���ӳɹ�����
						gd=gd-1000;
						szj=0;
					}
					else
					{
						printf("���Ѿ��������\n");
					}
				}
				else
				{
					printf("��Ҳ���\n");
				}
				fj=0;
				}
				
			}
		}
}
void maoxian(void)//ð��ģ�� 
{
printf("%s\n",DECISION2);
scanf("%d",&n);
if(n<0||n>4)
{printf("�������������ѡ��\n");
scanf("%d",&n);
}
printf("%s\n",DECISION3);
scanf("%d",&fb);
if(fb>4)
	{
		printf("δ����������ѡ��\n");
	}
else
	{

 switch (fb)//��������������࣬�����ڼӵ�����Ʒʱ�ܷ��� 

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
    slm();if(i!=2)break;slm();if(i!=2)break;//ͬ�� 
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
void slm(void)//����ģ�� 
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
void zdmk(void)//ս��ģ�� 
{
   while(hp>0&&tybosshp>0)
	{
    	i=1; 
    	printf("����״̬����������%d  Ѫ����%d  ħ��ֵ��%d  \n",p,hp,mp);
        printf("��ѡ����\n1.�ػ�     (���%d���˺���mp+1)\n2.��Ѫ     (���boss��ǰ����ֵ�ٷ�֮�˵��˺�����Ѫ�˺���3%��mp-3)\n3.�Ǳ�����ն     (���%d���˺���mp-5)\n",atk,q);//����� 
        scanf("%d",&sp);

        while(4<sp)
    	{
           printf("����ѡ�����������ѡ��\n");
           sp=-1;
    	}
        while(sp==1)
    	{
 
         tybosshp=tybosshp-atk;
         mp++;
         printf("��ʹ�ü����ػ���boss���%d���˺�,�ָ�һ��mp,boss����%dѪ��\n",p,tybosshp);
         sp=0;

        }

        while(sp==2)
    	{

        while(mp>=3&&sp==2)
    	{
    	sh=tybosshp*0.08;
        tybosshp=tybosshp*0.92;
        xx=xx+0.3*sh;//��Ѫ 
        hp=hp+xx;
    	mp=mp-3;
        printf("��ʹ�ü�����Ѫ��boss���%d���˺�����Ѫ%d��boss����%dѪ��\n",sh,xx,tybosshp);
        sp=0;
		}
     
	    while(mp<3&&sp==2)
		{
        printf("mp����3��,�޷��ͷż�����Ѫ\n");
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
        printf("��ʹ�ü����Ǳ�����ն��boss���%d���˺���boss����%dѪ��\n",q,tybosshp);//���� 
		}
		while(mp<5&&sp==3)
			{
				printf("mp����5��,�޷��ͷż����Ǳ�����ն \n");
				sp=-1;
			}
		}
    	while(tybosshp>0&&sp==0)
    	{
          if(tybosshp>hpboss*0.15)//bossѪ���½���15%���±�ŭ 
	    	{
			sh=15+hpboss*0.1-edf;
			sh=(sh>0)?sh:0;
			hp=hp-sh;
			printf("bossײ����һ�£����hp������%d��\n",sh);
			sp=-1;
			}
        else
        {
           printf("boss��Ϊ��״̬");
		   sh=15+hpboss*0.3-edf;//�˺����� 
		   sh=(sh>0)?sh:0;
		   hp=hp-sh;
		   printf("bossʹ�÷���Ҵ����hp������%d��\n",sh); 
		   sp=-1; 
		}
		}
	}
	while(tybosshp<=0&&i==1)
	{
		printf("���ѻ�ɱBOSS,��ϲͨ�أ�\n");
		i=i+1;
	}
	while(hp<0&&i==1)
	{
		printf("�������������ڼ򵥸�����������������Ŭ����\n");
		i=i+2;
	}

}

//�ָ���ʷ��ķ
void slm1(void)
{
  printf("ʷ��ķ����\n");

  hpboss=bosshp[0]*ndxs[n-1];//BOSS������ֵ

  tybosshp=hpboss;
}
void slm2(void)
{
if(i==2)
  {
	  printf("����20ex,50���\n");//���ﾭ����ȫ������ 

      ex=ex+20;

      gd=gd+50;
      
 	  printf("��ľ���Ϊ%d\n",ex);
  }
}

void gbl1(void)//�粼��
{
  printf("�粼�ֳ���\n");

  hpboss=bosshp[1]*ndxs[n-1];//BOSS������ֵ

  tybosshp=hpboss;
}
void gbl2(void)//end
{
if (i==2)
 {
     printf("����100ex,200���\n");

     ex=ex+100;

     gd=gd+200;
     
     printf("��ľ���Ϊ%d\n",ex);
  }
  }
  void gr1(void)//����
{
  printf("���˳���\n");
  
  hpboss=bosshp[2]*ndxs[n-1];//BOSS������ֵ

  tybosshp=hpboss;
}
void gr2(void)
{
	  if(i==2)
  {
	  printf("����300ex,500���\n");

      ex=ex+300;

      gd=gd+500;
      
      printf("��ľ���Ϊ%d\n",ex);
  }
}

