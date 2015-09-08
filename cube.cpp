//魔方大作业
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <assert.h>
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#define FRONT 4
#define BACK 5
using namespace std; 
/*
ORANGE 0 <--> RED 1
WHITE 3 <--> YELLOW 2
GREEN 4 <--> BLUE 5
*/

int cube[6][3][3];
int dire[6] = {0,1,2,3,4,5};
int tem1,tem2,tem3; 
void printcube(void)
{
	for(int i = 0;i < 6;i++)
	{
		for(int j = 2;j > -1; j--)
		{
			for(int k = 0;k < 3;k++)
			{
				cout << cube[i][k][j] << ' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
void rotate(int* a,int* b,int* c,int* d)
//rotate旋转函数，把abcd变为dabc，调去时注意取地址再传入 
//顺时针输入abcd，则相当于顺指针转动 
{
	int t = *a;
	*a = *d;
	*d = *c;
	*c = *b;
	*b = t; 
}

void counterrotate(int* a,int* b,int* c,int* d)
//counterrotate旋转函数，把abcd变为bcda，调去时注意取地址再传入 
//顺时针输入abcd，则相当于逆指针转动
{
	int t = *a;
	*a = *b;
	*b = *c;
	*c = *d;
	*d = t; 
}

void f_(void)//转前面 
{
	rotate(&cube[dire[FRONT]][0][0],&cube[dire[FRONT]][0][2],&cube[dire[FRONT]][2][2],&cube[dire[FRONT]][2][0]);
	rotate(&cube[dire[FRONT]][0][1],&cube[dire[FRONT]][1][2],&cube[dire[FRONT]][2][1],&cube[dire[FRONT]][1][0]);
	for(int i = 0;i < 3;i++)
	{
		rotate(&cube[dire[LEFT]][2][i],&cube[dire[UP]][i][0],&cube[dire[RIGHT]][0][2-i],&cube[dire[DOWN]][2-i][2]);
	}
	cout<<"F"<<endl;
}

void fi_(void)//逆时针转前面 
{
	f_();f_();f_();
	cout<<"Fi"<<endl;
}

void b_(void)//转后面 
{
	rotate(&cube[dire[BACK]][0][0],&cube[dire[BACK]][0][2],&cube[dire[BACK]][2][2],&cube[dire[BACK]][2][0]);
	rotate(&cube[dire[BACK]][0][1],&cube[dire[BACK]][1][2],&cube[dire[BACK]][2][1],&cube[dire[BACK]][1][0]);
	for(int i = 0;i < 3;i++)
	{
		counterrotate(&cube[dire[LEFT]][0][i],&cube[dire[UP]][i][2],&cube[dire[RIGHT]][2][2-i],&cube[dire[DOWN]][2-i][0]);
	}
	cout<<"B"<<endl;
}

void bi_(void)//逆时针转后面 
{
	b_();b_();b_();
	cout<<"Bi"<<endl;
}

void l_(void)//转左面 
{
	rotate(&cube[dire[LEFT]][0][0],&cube[dire[LEFT]][0][2],&cube[dire[LEFT]][2][2],&cube[dire[LEFT]][2][0]);
	rotate(&cube[dire[LEFT]][0][1],&cube[dire[LEFT]][1][2],&cube[dire[LEFT]][2][1],&cube[dire[LEFT]][1][0]);
	for(int i = 0;i < 3;i++)
	{
		counterrotate(&cube[dire[FRONT]][0][i],&cube[dire[UP]][0][i],&cube[dire[BACK]][2][2-i],&cube[dire[DOWN]][0][i]);
	}
	cout<<"L"<<endl;
}


void li_(void)//逆时针转左面 
{
	l_();l_();l_();
	cout<<"Li"<<endl;
}

void r_(void)//转右面 
{
	rotate(&cube[dire[RIGHT]][0][0],&cube[dire[RIGHT]][0][2],&cube[dire[RIGHT]][2][2],&cube[dire[RIGHT]][2][0]);
	rotate(&cube[dire[RIGHT]][0][1],&cube[dire[RIGHT]][1][2],&cube[dire[RIGHT]][2][1],&cube[dire[RIGHT]][1][0]);
	for(int i = 0;i < 3;i++)
	{
		rotate(&cube[dire[FRONT]][2][i],&cube[dire[UP]][2][i],&cube[dire[BACK]][0][2-i],&cube[dire[DOWN]][2][i]);
	}
	cout<<"R"<<endl;
}


void ri_(void)//逆时针转右面 
{
	r_();r_();r_();
	cout<<"Ri"<<endl;
}

void u_(void)//转上面 
{
	rotate(&cube[dire[UP]][0][0],&cube[dire[UP]][0][2],&cube[dire[UP]][2][2],&cube[dire[UP]][2][0]);
	rotate(&cube[dire[UP]][0][1],&cube[dire[UP]][1][2],&cube[dire[UP]][2][1],&cube[dire[UP]][1][0]);
	for(int i = 0;i < 3;i++)
	{
		rotate(&cube[dire[FRONT]][i][2],&cube[dire[LEFT]][i][2],&cube[dire[BACK]][i][2],&cube[dire[RIGHT]][i][2]);
	}
	cout<<"U"<<endl;
}

void ui_(void)//逆时针转上面 
{
	u_();u_();u_();
	cout<<"Ui"<<endl;
}

void d_(void)//转下面 
{
	rotate(&cube[dire[DOWN]][0][0],&cube[dire[DOWN]][0][2],&cube[dire[DOWN]][2][2],&cube[dire[DOWN]][2][0]);
	rotate(&cube[dire[DOWN]][0][1],&cube[dire[DOWN]][1][2],&cube[dire[DOWN]][2][1],&cube[dire[DOWN]][1][0]);
	for(int i = 0;i < 3;i++)
	{
		counterrotate(&cube[dire[FRONT]][i][0],&cube[dire[LEFT]][i][0],&cube[dire[BACK]][i][0],&cube[dire[RIGHT]][i][0]);
	}
	cout<<"D"<<endl;
}

void di_(void)//逆时针转下面 
{
	d_();d_();d_();
	cout<<"Di"<<endl;
}

//stage2角块的公式 
void stgiicnr()//stage2角块的公式 
{
	while(
	cube[FRONT][2][2] == cube[DOWN][1][1] || cube[FRONT][0][2] == cube[DOWN][1][1] || 
	cube[RIGHT][2][2] == cube[DOWN][1][1] || cube[RIGHT][0][2] == cube[DOWN][1][1] ||
	cube[LEFT][2][2] == cube[DOWN][1][1] || cube[LEFT][0][2] == cube[DOWN][1][1] ||
	cube[BACK][2][2] == cube[DOWN][1][1] || cube[BACK][0][2] == cube[DOWN][1][1] ||
	cube[UP][2][2] == cube[DOWN][1][1] || cube[UP][0][2] == cube[DOWN][1][1] ||
	cube[UP][0][0] == cube[DOWN][1][1] || cube[UP][2][0] == cube[DOWN][1][1]
	)
	{
		d_();
		for(int i = 0; i < 4; i++)
		{
			u_();
			if(
			   (( cube[dire[FRONT]][2][2] == cube[dire[DOWN]][1][1] )&& ( cube[dire[RIGHT]][0][2]  == cube[dire[RIGHT]][1][0] ) && ( cube[dire[UP]][2][0] == cube[dire[FRONT]][1][0] ) )||
			   (( cube[dire[FRONT]][2][2] == cube[dire[RIGHT]][1][0] )&& ( cube[dire[RIGHT]][0][2]  == cube[dire[FRONT]][1][0] ) && ( cube[dire[UP]][2][0] == cube[dire[DOWN]][1][1] ) )||
			   (( cube[dire[FRONT]][2][2] == cube[dire[FRONT]][1][0] )&& ( cube[dire[RIGHT]][0][2]  == cube[dire[DOWN]][1][1] ) && ( cube[dire[UP]][2][0] == cube[dire[RIGHT]][1][0] ) )	
			  )
			{
				while(cube[dire[DOWN]][2][2] != cube[dire[DOWN]][1][1] || cube[RIGHT][0][0] != cube[RIGHT][1][0] || cube[FRONT][2][0] != cube[FRONT][1][0])
				{
					r_();
					u_();
					ri_();
					ui_();
				}
			}
		}
	}
}
//functions used in stage3
//end
//functions used in stage4
//start
void fr(void)//把顶层的前右块放在正确的位置 
{
	int j1 = 0;
		while(j1 < 4)
		{
			if(cube[dire[FRONT]][1][2]==cube[dire[FRONT]][1][1]&&
			cube[dire[UP]][1][0]==cube[dire[RIGHT]][1][1])
			{
			u_();
			r_();
			ui_();
			ri_();
			ui_();
			fi_();
			u_();
			f_();
			break; 
			} 
			if(cube[dire[UP]][2][1]==cube[dire[FRONT]][1][1]&&
			cube[dire[RIGHT]][1][2]==cube[dire[RIGHT]][1][1])
			{
			ui_();
			fi_();
			u_();
			f_();
			u_();
			r_();
			ui_();
			ri_();	
			break;			
			}
			u_();
			
			j1 = j1 + 1;
		}
}

void rb(void)
{
	int j2 = 0;
		while(j2 < 4)
		{
			if(cube[dire[RIGHT]][1][2]==cube[dire[RIGHT]][1][1]&&
			cube[dire[UP]][2][1]==cube[dire[BACK]][1][1])
			{
			u_();
			b_();
			ui_();
			bi_();
			ui_();
			ri_();
			u_();
			r_();
			break; 
			} 
			if(cube[dire[UP]][1][2]==cube[dire[RIGHT]][1][1]&&
			cube[dire[BACK]][1][2]==cube[dire[BACK]][1][1])
			{
			ui_();
			ri_();
			u_();
			r_();
			u_();
			b_();
			ui_();
			bi_();	
			break;			
			}
			u_();
			
			j2 = j2 + 1;
		}
}

void bl(void)
{
	int j3 = 0;
		while(j3 < 4)
		{
			if(cube[dire[BACK]][1][2]==cube[dire[BACK]][1][1]&&
			cube[dire[UP]][1][2]==cube[dire[LEFT]][1][1])
			{
			u_();
			l_();
			ui_();
			li_();
			ui_();
			bi_();
			u_();
			b_();
			break; 
			} 
			if(cube[dire[UP]][0][1]==cube[dire[BACK]][1][1]&&
			cube[dire[LEFT]][1][2]==cube[dire[LEFT]][1][1])
			{
			ui_();
			bi_();
			u_();
			b_();
			u_();
			l_();
			ui_();
			li_();	
			break;			
			}
			u_();
			
			j3 = j3 + 1;
		}		
}

void lf(void)
{
	int j4 = 0;
		while(j4 < 4)
		{
			if(cube[dire[LEFT]][1][2]==cube[dire[LEFT]][1][1]&&
			cube[dire[UP]][0][1]==cube[dire[FRONT]][1][1])
			{
			u_();
			f_();
			ui_();
			fi_();
			ui_();
			li_();
			u_();
			l_();
			break; 
			} 
			if(cube[dire[UP]][1][0]==cube[dire[LEFT]][1][1]&&
			cube[dire[FRONT]][1][2]==cube[dire[FRONT]][1][1])
			{
			ui_();
			li_();
			u_();
			l_();
			u_();
			f_();
			ui_();
			fi_();	
			break;			
			}
			u_();
			
			j4 = j4 + 1;
		}	
}
void judge(int a,int b)//判断需要以上哪个函数 
{
	if(a+b==4&&a*b==0) fr();
	if(a+b==5&&a*b==0) rb();
	if(a+b==6&&a*b==5) bl();
	if(a+b==5&&a*b==4) lf();
}
void step(void)//把上层四个棱块都做成带黄色的 
{
	for(int i = 0;;i++)
	{
		fr();
		rb();
		bl();
		lf();
		bool fro = (cube[dire[FRONT]][1][2] == cube[dire[UP]][1][1]) || 
		(cube[dire[UP]][1][0] == cube[dire[UP]][1][1]);
		bool rig = (cube[dire[RIGHT]][1][2] == cube[dire[UP]][1][1]) || 
		(cube[dire[UP]][2][1] == cube[dire[UP]][1][1]);
		bool bac = (cube[dire[BACK]][1][2] == cube[dire[UP]][1][1]) || 
		(cube[dire[UP]][1][2] == cube[dire[UP]][1][1]);
		bool lef = (cube[dire[LEFT]][1][2] == cube[dire[UP]][1][1]) || 
		(cube[dire[UP]][0][1] == cube[dire[UP]][1][1]);
		if(fro&&rig&&bac&&lef)
		{
			break;
		}
	}
} 
//functions used in stage4
//end
void checkcube(void)
{
	int g = 0;
	for(int i = 0;i < 6;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			for(int k = 0;k < 3;k++)
			{
				if(cube[dire[i]][j][k]!=cube[dire[i]][1][1])
				g = 1;
				break;
			}
		}
	}
	assert(g==0);
}
int main()
{
//input
	for(int i = 0;i < 6;i++)
	{
		for(int j = 2;j > -1;j--)
		{
			for(int k = 0;k < 3;k++)
			{
				cin>>cube[i][k][j];
			}
		}
	}
//input
//end
//stage1
//start
	while(  
		!(  (cube[RIGHT][1][1] == cube[RIGHT][1][0])&&
		    (cube[LEFT][1][1] == cube[LEFT][1][0])&&
		    (cube[FRONT][1][1] == cube[FRONT][1][0])&&
		    (cube[BACK][1][1] == cube[BACK][1][0])&&
		    (cube[DOWN][1][1] == cube[DOWN][1][0])&&
		    (cube[DOWN][1][1] == cube[DOWN][0][1])&&
		    (cube[DOWN][1][1] == cube[DOWN][1][2])&&
		    (cube[DOWN][1][1] == cube[DOWN][2][1])
	     )
	)
	 { 
		if(  (cube[DOWN][2][1]==cube[DOWN][1][1]) + (cube[RIGHT][1][0]==cube[RIGHT][1][1]) != 2 )//第一步复原一个棱块 
		{
	//	if(cube[DOWN][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][0]==cube[RIGHT][1][1])//1号位正 
		
	//	else
		 if(cube[DOWN][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][0]==cube[DOWN][1][1])//1号位反 
		{
			r_();
			di_();
			f_();
			d_();
			
		
		}
		else if(cube[FRONT][2][1]==cube[DOWN][1][1]&&cube[RIGHT][0][1]==cube[RIGHT][1][1])//8zheng 
		{
			ri_();
			
		}
		else if(cube[FRONT][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][0][1]==cube[DOWN][1][1])//8fan
		{
			di_();
			f_();
			d_();
			
			
		}
		else if(cube[RIGHT][2][1]==cube[RIGHT][1][1]&&cube[BACK][0][1]==cube[DOWN][1][1])//7zheng
		{
			r_();
			
		}
		else if(cube[RIGHT][2][1]==cube[DOWN][1][1]&&cube[BACK][0][1]==cube[RIGHT][1][1])//7fan
		{
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][2]==cube[RIGHT][1][1])//4zheng
		{
			r_();
			r_();
			
		}
		else if(cube[UP][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][2]==cube[DOWN][1][1])//4fan
		{
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][0]==cube[RIGHT][1][1]&&cube[FRONT][1][2]==cube[DOWN][1][1])//初始位正 
		{
			ui_();
			r_();
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][1][0]==cube[DOWN][1][1]&&cube[FRONT][1][2]==cube[RIGHT][1][1])//初始位fan 
		{
			ui_();
			r_();
			r_();
			
		}
		else if(cube[FRONT][1][0]==cube[DOWN][1][1]&&cube[DOWN][1][2]==cube[RIGHT][1][1])//Afan
		{
			fi_();
			fi_();
			ui_();
			r_();
			d_();
			bi_();
			di_(); 
		}
		else if(cube[FRONT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][1][2]==cube[DOWN][1][1])//Azheng
		{
			fi_();
			fi_();
			ui_();
			r_();
			r_();
		}
		else if(cube[UP][1][2]==cube[RIGHT][1][1]&&cube[BACK][1][2]==cube[DOWN][1][1])//3fan
		{
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][2]==cube[DOWN][1][1]&&cube[BACK][1][2]==cube[RIGHT][1][1])//3zheng
		{
			u_();
			r_();
			r_();
		}
		else if(cube[DOWN][1][0]==cube[DOWN][1][1]&&cube[BACK][1][0]==cube[RIGHT][1][1])//0zheng
		{
			b_();
			b_();
			u_();
			r_();
			r_();
			
		}
		else if(cube[DOWN][1][0]==cube[RIGHT][1][1]&&cube[BACK][1][0]==cube[DOWN][1][1])//0fan
		{
			b_();
			b_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[RIGHT][1][1]&&cube[LEFT][1][2]==cube[DOWN][1][1])//2fan
		{
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[DOWN][1][1]&&cube[LEFT][1][2]==cube[RIGHT][1][1])//2zheng
		{
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[RIGHT][1][1]&&cube[FRONT][0][1]==cube[DOWN][1][1])//5zheng
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[DOWN][1][1]&&cube[FRONT][0][1]==cube[RIGHT][1][1])//5fan
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[DOWN][1][1]&&cube[DOWN][0][1]==cube[RIGHT][1][1])//9fan
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][0][1]==cube[DOWN][1][1])//9zheng
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][0][1]==cube[DOWN][1][1]&&cube[BACK][2][1]==cube[RIGHT][1][1])//6fan
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][0][1]==cube[RIGHT][1][1]&&cube[BACK][2][1]==cube[DOWN][1][1])//6zheng
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			r_();
		}
		else
		{
		}
		}

		di_();


		if(  !((cube[DOWN][2][1]==cube[DOWN][1][1]) && (cube[RIGHT][1][0]==cube[BACK][1][1]) ))//第二步复原一个棱块 
		{        tem1 = cube[RIGHT][1][1];
		cube[RIGHT][1][1]=cube[BACK][1][1];//先把后面中心色赋值到右边的 
		
		/*if(cube[DOWN][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][0]==cube[RIGHT][1][1])//1号位正 
		{
	
		}
		else*/ if(cube[DOWN][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][0]==cube[DOWN][1][1])//1号位反 
		{
			r_();
			di_();
			f_();
			d_();
			
		
		}
		else if(cube[FRONT][2][1]==cube[DOWN][1][1]&&cube[RIGHT][0][1]==cube[RIGHT][1][1])//8zheng 
		{
			ri_();
			
		}
		else if(cube[FRONT][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][0][1]==cube[DOWN][1][1])//8fan
		{
			di_();
			f_();
			d_();
			
			
		}
		else if(cube[RIGHT][2][1]==cube[RIGHT][1][1]&&cube[BACK][0][1]==cube[DOWN][1][1])//7zheng
		{
			r_();
			
		}
		else if(cube[RIGHT][2][1]==cube[DOWN][1][1]&&cube[BACK][0][1]==cube[RIGHT][1][1])//7fan
		{
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][2]==cube[RIGHT][1][1])//4zheng
		{
			r_();
			r_();
			
		}
		else if(cube[UP][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][2]==cube[DOWN][1][1])//4fan
		{
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][0]==cube[RIGHT][1][1]&&cube[FRONT][1][2]==cube[DOWN][1][1])//初始位fan 
		{
			ui_();
			r_();
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][1][0]==cube[DOWN][1][1]&&cube[FRONT][1][2]==cube[RIGHT][1][1])//初始位zheng 
		{
			ui_();
			r_();
			r_();
			
		}
		else if(cube[FRONT][1][0]==cube[DOWN][1][1]&&cube[DOWN][1][2]==cube[RIGHT][1][1])//Afan
		{
			fi_();
			fi_();
			ui_();
			r_();
			d_();
			bi_();
			di_(); 
		}
		else if(cube[FRONT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][1][2]==cube[DOWN][1][1])//Azheng
		{
			fi_();
			fi_();
			ui_();
			r_();
			r_();
		}
		else if(cube[UP][1][2]==cube[RIGHT][1][1]&&cube[BACK][1][2]==cube[DOWN][1][1])//3fan
		{
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][2]==cube[DOWN][1][1]&&cube[BACK][1][2]==cube[RIGHT][1][1])//3zheng
		{
			u_();
			r_();
			r_();
		}
		else if(cube[DOWN][1][0]==cube[DOWN][1][1]&&cube[BACK][1][0]==cube[RIGHT][1][1])//0zheng
		{
			b_();
			b_();
			u_();
			r_();
			r_();
			
		}
		else if(cube[DOWN][1][0]==cube[RIGHT][1][1]&&cube[BACK][1][0]==cube[DOWN][1][1])//0fan
		{
			b_();
			b_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[RIGHT][1][1]&&cube[LEFT][1][2]==cube[DOWN][1][1])//2fan
		{
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[DOWN][1][1]&&cube[LEFT][1][2]==cube[RIGHT][1][1])//2zheng
		{
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[RIGHT][1][1]&&cube[FRONT][0][1]==cube[DOWN][1][1])//5zheng
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[DOWN][1][1]&&cube[FRONT][0][1]==cube[RIGHT][1][1])//5fan
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[DOWN][1][1]&&cube[DOWN][0][1]==cube[RIGHT][1][1])//9fan
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][0][1]==cube[DOWN][1][1])//9zheng
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][0][1]==cube[DOWN][1][1]&&cube[BACK][2][1]==cube[RIGHT][1][1])//6fan
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][0][1]==cube[RIGHT][1][1]&&cube[BACK][2][1]==cube[DOWN][1][1])//6zheng
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			r_();
		}
		else
		{
		}
		
		cube[RIGHT][1][1] = tem1;
		}

		di_();


		if(  (cube[DOWN][2][1]==cube[DOWN][1][1]) + (cube[RIGHT][1][0]==cube[LEFT][1][1]) != 2 )//第三步复原一个棱块 
		{       tem2 = cube[RIGHT][1][1];
		cube[RIGHT][1][1]=cube[LEFT][1][1];//先把左面中心色赋值到右边的 
		
		/*if(cube[DOWN][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][0]==cube[RIGHT][1][1])//1号位正 
		{
	
		}
		else */if(cube[DOWN][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][0]==cube[DOWN][1][1])//1号位反 
		{
			r_();
			di_();
			f_();
			d_();
			
		
		}
		else if(cube[FRONT][2][1]==cube[DOWN][1][1]&&cube[RIGHT][0][1]==cube[RIGHT][1][1])//8zheng 
		{
			ri_();
			
		}
		else if(cube[FRONT][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][0][1]==cube[DOWN][1][1])//8fan
		{
			di_();
			f_();
			d_();
			
			
		}
		else if(cube[RIGHT][2][1]==cube[RIGHT][1][1]&&cube[BACK][0][1]==cube[DOWN][1][1])//7zheng
		{
			r_();
			
		}
		else if(cube[RIGHT][2][1]==cube[DOWN][1][1]&&cube[BACK][0][1]==cube[RIGHT][1][1])//7fan
		{
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][2]==cube[RIGHT][1][1])//4zheng
		{
			r_();
			r_();
			
		}
		else if(cube[UP][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][2]==cube[DOWN][1][1])//4fan
		{
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][0]==cube[RIGHT][1][1]&&cube[FRONT][1][2]==cube[DOWN][1][1])//初始位fan 
		{
			ui_();
			r_();
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][1][0]==cube[DOWN][1][1]&&cube[FRONT][1][2]==cube[RIGHT][1][1])//初始位zheng 
		{
			ui_();
			r_();
			r_();
			
		}
		else if(cube[FRONT][1][0]==cube[DOWN][1][1]&&cube[DOWN][1][2]==cube[RIGHT][1][1])//Afan
		{
			fi_();
			fi_();
			ui_();
			r_();
			d_();
			bi_();
			di_(); 
		}
		else if(cube[FRONT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][1][2]==cube[DOWN][1][1])//Azheng
		{
			fi_();
			fi_();
			ui_();
			r_();
			r_();
		}
		else if(cube[UP][1][2]==cube[RIGHT][1][1]&&cube[BACK][1][2]==cube[DOWN][1][1])//3fan
		{
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][2]==cube[DOWN][1][1]&&cube[BACK][1][2]==cube[RIGHT][1][1])//3zheng
		{
			u_();
			r_();
			r_();
		}
		else if(cube[DOWN][1][0]==cube[DOWN][1][1]&&cube[BACK][1][0]==cube[RIGHT][1][1])//0zheng
		{
			b_();
			b_();
			u_();
			r_();
			r_();
			
		}
		else if(cube[DOWN][1][0]==cube[RIGHT][1][1]&&cube[BACK][1][0]==cube[DOWN][1][1])//0fan
		{
			b_();
			b_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[RIGHT][1][1]&&cube[LEFT][1][2]==cube[DOWN][1][1])//2fan
		{
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[DOWN][1][1]&&cube[LEFT][1][2]==cube[RIGHT][1][1])//2zheng
		{
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[RIGHT][1][1]&&cube[FRONT][0][1]==cube[DOWN][1][1])//5zheng
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[DOWN][1][1]&&cube[FRONT][0][1]==cube[RIGHT][1][1])//5fan
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[DOWN][1][1]&&cube[DOWN][0][1]==cube[RIGHT][1][1])//9fan
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][0][1]==cube[DOWN][1][1])//9zheng
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][0][1]==cube[DOWN][1][1]&&cube[BACK][2][1]==cube[RIGHT][1][1])//6fan
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][0][1]==cube[RIGHT][1][1]&&cube[BACK][2][1]==cube[DOWN][1][1])//6zheng
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			r_();
		}
		else
		{
		}
		
		cube[RIGHT][1][1] = tem2;
		}

		di_();

if(  (cube[DOWN][2][1]==cube[DOWN][1][1]) + (cube[RIGHT][1][0]==cube[FRONT][1][1]) != 2 )//第四步复原一个棱块 
{       tem3 = cube[RIGHT][1][1]; 
		cube[RIGHT][1][1]=cube[FRONT][1][1];//先把后面中心色赋值到右边的 
		
		/*if(cube[DOWN][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][0]==cube[RIGHT][1][1])//1号位正 
		{
	
		}
		else */if(cube[DOWN][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][0]==cube[DOWN][1][1])//1号位反 
		{
			r_();
			di_();
			f_();
			d_();
			
		
		}
		else if(cube[FRONT][2][1]==cube[DOWN][1][1]&&cube[RIGHT][0][1]==cube[RIGHT][1][1])//8zheng 
		{
			ri_();
			
		}
		else if(cube[FRONT][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][0][1]==cube[DOWN][1][1])//8fan
		{
			di_();
			f_();
			d_();
			
			
		}
		else if(cube[RIGHT][2][1]==cube[RIGHT][1][1]&&cube[BACK][0][1]==cube[DOWN][1][1])//7zheng
		{
			r_();
			
		}
		else if(cube[RIGHT][2][1]==cube[DOWN][1][1]&&cube[BACK][0][1]==cube[RIGHT][1][1])//7fan
		{
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][2][1]==cube[DOWN][1][1]&&cube[RIGHT][1][2]==cube[RIGHT][1][1])//4zheng
		{
			r_();
			r_();
			
		}
		else if(cube[UP][2][1]==cube[RIGHT][1][1]&&cube[RIGHT][1][2]==cube[DOWN][1][1])//4fan
		{
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][0]==cube[RIGHT][1][1]&&cube[FRONT][1][2]==cube[DOWN][1][1])//初始位fan 
		{
			ui_();
			r_();
			d_();
			bi_();
			di_();
			
		}
		else if(cube[UP][1][0]==cube[DOWN][1][1]&&cube[FRONT][1][2]==cube[RIGHT][1][1])//初始位zheng 
		{
			ui_();
			r_();
			r_();
			
		}
		else if(cube[FRONT][1][0]==cube[DOWN][1][1]&&cube[DOWN][1][2]==cube[RIGHT][1][1])//Afan
		{
			fi_();
			fi_();
			ui_();
			r_();
			d_();
			bi_();
			di_(); 
		}
		else if(cube[FRONT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][1][2]==cube[DOWN][1][1])//Azheng
		{
			fi_();
			fi_();
			ui_();
			r_();
			r_();
		}
		else if(cube[UP][1][2]==cube[RIGHT][1][1]&&cube[BACK][1][2]==cube[DOWN][1][1])//3fan
		{
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][1][2]==cube[DOWN][1][1]&&cube[BACK][1][2]==cube[RIGHT][1][1])//3zheng
		{
			u_();
			r_();
			r_();
		}
		else if(cube[DOWN][1][0]==cube[DOWN][1][1]&&cube[BACK][1][0]==cube[RIGHT][1][1])//0zheng
		{
			b_();
			b_();
			u_();
			r_();
			r_();
			
		}
		else if(cube[DOWN][1][0]==cube[RIGHT][1][1]&&cube[BACK][1][0]==cube[DOWN][1][1])//0fan
		{
			b_();
			b_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[RIGHT][1][1]&&cube[LEFT][1][2]==cube[DOWN][1][1])//2fan
		{
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[UP][0][1]==cube[DOWN][1][1]&&cube[LEFT][1][2]==cube[RIGHT][1][1])//2zheng
		{
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[RIGHT][1][1]&&cube[FRONT][0][1]==cube[DOWN][1][1])//5zheng
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			r_();
		}
		else if(cube[LEFT][2][1]==cube[DOWN][1][1]&&cube[FRONT][0][1]==cube[RIGHT][1][1])//5fan
		{
			li_();
			u_();
			u_();
			l_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[DOWN][1][1]&&cube[DOWN][0][1]==cube[RIGHT][1][1])//9fan
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][1][0]==cube[RIGHT][1][1]&&cube[DOWN][0][1]==cube[DOWN][1][1])//9zheng
		{
			l_();
			l_();
			u_();
			u_();
			r_();
			r_();
		}
		else if(cube[LEFT][0][1]==cube[DOWN][1][1]&&cube[BACK][2][1]==cube[RIGHT][1][1])//6fan
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			d_();
			bi_();
			di_();
		}
		else if(cube[LEFT][0][1]==cube[RIGHT][1][1]&&cube[BACK][2][1]==cube[DOWN][1][1])//6zheng
		{
			l_();
			u_();
			u_();
			li_();
			r_();
			r_();
		}
		else
		{
		}
		
		cube[RIGHT][1][1] = tem3;
}
		di_();
} 
//stage2
//---------------------------------------------
//stage3
	dire[0] = 0;
	dire[1] = 1;
	dire[2] = 2;
	dire[3] = 3;
	dire[4] = 4;
	dire[5] = 5;
	stgiicnr();
	for(int j = 0; j < 4; j++)
	{
		d_();
		if( ( cube[DOWN][2][2] != cube[DOWN][1][1] ) || 
			( cube[FRONT][2][0] != cube[FRONT][1][0] )|| 
			( cube[RIGHT][0][0] != cube[RIGHT][1][0] )
			)
			{
				r_();
				u_();
				ri_();
				ui_();
				stgiicnr();
			}
	}// 至此，底层复原完毕 但可能方向不对，只需将底层转小于4的次数 
	for(int i = 0; i < 4; i++)
	{
		if(cube[dire[FRONT]][1][1] == cube[dire[FRONT]][1][0] ) break;
		else {d_();}
	}	
//	cout << endl << endl;
//	cout<<"stage3"<<endl;
//	printcube();
//stage3
//-----------------------------------------------
//stage4
	for(int i = 0;i < 6;i++)
	{
		dire[i] = i;
	}
	step();
//-------------------------------------------------------------------------
//以下对四个棱块判断，若不对则将其替到顶层，再用之前的步骤将其放对 
    int Count = 0;
	while(Count < 4){
	if((cube[dire[FRONT]][2][1]!=cube[dire[FRONT]][1][1])||
	cube[dire[RIGHT]][0][1]!=cube[dire[RIGHT]][1][1])//判断前右 
	{
		int a = cube[dire[FRONT]][2][1];
		int b = cube[dire[RIGHT]][0][1];
		u_();
		r_();
		ui_();
		ri_();
		ui_();
		fi_();
		u_();
		f_();
		judge(a,b);
		step();
	}
	if((cube[dire[RIGHT]][2][1]!=cube[dire[RIGHT]][1][1])||
	cube[dire[BACK]][0][1]!=cube[dire[BACK]][1][1])//判断右后 
	{
		int a = cube[dire[RIGHT]][2][1];
		int b = cube[dire[BACK]][0][1]; 
		u_();
		b_();
		ui_();
		bi_();
		ui_();
		ri_();
		u_();
		r_();
		judge(a,b);
		step();
	}	
	if((cube[dire[BACK]][2][1]!=cube[dire[BACK]][1][1])||
	(cube[dire[LEFT]][0][1]!=cube[dire[LEFT]][1][1])) //判断后左
	{
		int a = cube[dire[BACK]][2][1];
		int b = cube[dire[LEFT]][0][1];
		u_();
		l_();
		ui_();
		li_();
		ui_();
		bi_();
		u_();
		b_();
		judge(a,b);
		step();
	} 
	if((cube[dire[LEFT]][2][1]!=cube[dire[LEFT]][1][1])||
	(cube[dire[FRONT]][0][1]!=cube[dire[FRONT]][1][1]))//判断左前
	{
		int a = cube[dire[LEFT]][2][1];
		int b = cube[dire[FRONT]][0][1];
		u_();
		f_();
		ui_();
		fi_();
		ui_();
		li_();
		u_();
		l_();
		judge(a,b);
		step();
	} 
	Count++;
	}
//	cout<<endl;
//	cout<<"stage4"<<endl;
//	printcube();
//stage4
//---------------------------------------------------------
//stage5
	if (cube[dire[2]][1][1] != cube[dire[2]][1][0] && 
	cube[dire[2]][1][1] != cube[dire[2]][0][1] && 
	cube[dire[2]][1][1] != cube[dire[2]][1][2] && 
	cube[dire[2]][1][1] != cube[dire[2]][2][1]) 
	{
		ri_();
		ui_();
		fi_();
		u_();
		f_();
		r_();
	}//只有中心块的情况 
if (((cube[dire[2]][1][1] == cube[dire[2]][1][2]) && (cube[dire[2]][1][1] == cube[dire[2]][1][0])) ^ 
	((cube[dire[2]][1][1] == cube[dire[2]][0][1]) && (cube[dire[2]][1][1] == cube[dire[2]][2][1])))
{
	while ( !((cube[dire[2]][1][1] == cube[dire[2]][1][2]) && (cube[dire[2]][1][1] == cube[dire[2]][1][0])))
	{
		u_();
	}
	ri_();
	ui_();
	fi_();
	u_();
	f_();
	r_();
}//“一”字的情况
if	(
   ((cube[dire[2]][1][1] != cube[dire[2]][1][0]) +  
	(cube[dire[2]][1][1] != cube[dire[2]][0][1]) + 
	(cube[dire[2]][1][1] != cube[dire[2]][1][2]) + 
	(cube[dire[2]][1][1] != cube[dire[2]][2][1]) == 2) &&
	! (((cube[dire[2]][1][1] == cube[dire[2]][1][2]) && (cube[dire[2]][1][1] == cube[dire[2]][1][0])) ^ 
	((cube[dire[2]][1][1] == cube[dire[2]][0][1]) && (cube[dire[2]][1][1] == cube[dire[2]][2][1]))) 
	)
{
	while ( ! ((cube[dire[2]][0][1] == cube[dire[2]][1][1]) && (cube[dire[2]][1][2] == cube[dire[2]][1][1]) ) )
	{
		u_();
	}
	ri_();
	ui_();
	fi_();
	u_();
	f_();
	r_();
}//小L的情况

//顶面
if(
   (cube[dire[2]][0][0] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][0][2] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][2][0] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][2][2] == cube[dire[2]][1][1]) == 0
	)
	{
		while( 
		! ((cube[dire[LEFT]][2][2] == cube[dire[2]][1][1]) && (cube[dire[LEFT]][0][2] == cube[dire[2]][1][1])) //|| 
	//	! ((cube[dire[4]][0][2] == cube[dire[4]][2][2]) && (cube[dire[4]][2][2] == cube[dire[1]][0][2]) && (cube[dire[4]][2][2] == cube[dire[2]][1][1]))
		)
		{
			u_();
		}
		ri_();
		ui_();
		r_();
		ui_();
		ri_();
		u_();
		u_();
		r_();
	}//没有在上的块 
if(
   (cube[dire[2]][0][0] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][0][2] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][2][0] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][2][2] == cube[dire[2]][1][1]) == 2
	)
	{
		while( 
		! (cube[dire[BACK]][2][2] == cube[dire[2]][1][1]) //&& (cube[dire[5]][0][2] == cube[dire[2]][1][1])) || 
	//	! ((cube[dire[5]][2][2] == cube[dire[2]][1][1]) && (cube[dire[4]][0][2] == cube[dire[2]][1][1])) ||
	//	! ((cube[dire[5]][2][2] == cube[dire[2]][1][1]) && (cube[dire[0]][0][2] == cube[dire[2]][1][1]))
		)
		{
			u_();
		}
		ri_();
		ui_();
		r_();
		ui_();
		ri_();
		u_();
		u_();
		r_();
	}//两个在上的面 
if(
   (cube[dire[2]][0][0] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][0][2] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][2][0] == cube[dire[2]][1][1]) + 
   (cube[dire[2]][2][2] == cube[dire[2]][1][1]) == 1
)
	{
		while(cube[dire[2]][0][2] != cube[dire[2]][1][1])
		{
			{
				u_();
			}			
		}
		if(cube[dire[0]][0][2] == cube[dire[2]][1][1])
		{
			ri_();
			ui_();
			r_();
			ui_();
			ri_();
			u_();
			u_();
			r_();
		}
		else
		{
			f_();
			u_();
			fi_();
			u_();
			f_();
			u_();
			u_();
			fi_();
		}
	}
//	cout<<"stage5"<<endl;
//	printcube();
//stage5
//-------------------------------
//stage6
if((cube[0][0][2] == cube[0][2][2])&& 
(cube[1][0][2] == cube[1][2][2])&&
(cube[4][0][2] == cube[4][2][2])&&
(cube[5][0][2] == cube[5][2][2])) 
{
}
else{


if (
	!(
(cube[0][0][2] == cube[0][2][2])|| 
(cube[1][0][2] == cube[1][2][2])|| 
(cube[4][0][2] == cube[4][2][2])||
(cube[5][0][2] == cube[5][2][2])
	) 
	)
	{//角块三顺时针循环 
		r_();
		bi_();
		r_();
		f_();
		f_();
		ri_();
		b_();
		r_();
		f_();
		f_();
		r_();
		r_();
	//以左面为前面重复上公式
		f_();
		ri_();
		f_();
		l_();
		l_();
		fi_();
		r_();
		f_();
		l_();
		l_();
		f_();
		f_();
	} 


 
else if(cube[4][0][2] == cube[4][2][2])
	{
		r_();
		bi_();
		r_();
		f_();
		f_();
		ri_();
		b_();
		r_();
		f_();
		f_();
		r_();
		r_();
	} 

else if(cube[0][0][2] == cube[0][2][2])
	{u_();//把右面的转到前面 
		r_();
		bi_();
		r_();
		f_();
		f_();
		ri_();
		b_();
		r_();
		f_();
		f_();
		r_();
		r_();
	ui_();//把前面再转回右面 
	} 
	
else if(cube[5][0][2] == cube[5][2][2])
	{u_();u_();//把后面的转到前面 
		r_();
		bi_();
		r_();
		f_();
		f_();
		ri_();
		b_();
		r_();
		f_();
		f_();
		r_();
		r_();
	ui_();ui_();//把前面再转回后面 
	} 
	
else if(cube[1][0][2] == cube[1][2][2])
	{ui_();//把左面的转到前面 
		r_();
		bi_();
		r_();
		f_();
		f_();
		ri_();
		b_();
		r_();
		f_();
		f_();
		r_();
		r_();
	u_();//把前面再转回左面 
	} 
}
//u_();u_();
	/*while(
	(cube[0][0][2] != cube[0][1][1])||
	(cube[1][0][2] != cube[1][1][1])||
	(cube[4][0][2] != cube[4][1][1])||
	(cube[5][0][2] != cube[5][1][1])
	)
	{u_();}//旋转顶层直到 把角块调整到正确位置	*/
//pll手法调整角块结束 
//pll手法调整棱块开始 
//下面开始用棱块三循环调整棱块 
//情况一：四个面中至少有一个面的棱块已经还原 
//printcube();
//cout<<"以上已经复原完了角块"<<endl; 
//cout<<"kaishi lengkuai sanxunhuan"<<endl;
	if( 
	(cube[0][0][2] == cube[0][1][2]) || 
	(cube[1][0][2] == cube[1][1][2]) ||
	(cube[5][0][2] == cube[5][1][2]) ||
	(cube[4][0][2] == cube[4][1][2]) 
   )
   {

	while( !( (cube[5][0][2] == cube[5][1][2]) &&(cube[5][1][2] == cube[5][2][2] ) ) ) 
	{ui_();}
	//下面开始使用逆时针的棱块三循环公式(R U' R) U (R U R U') (R' U' R2)

	while(
	(cube[4][0][2] != cube[4][1][2])||
	(cube[0][0][2] != cube[0][1][2])||
	(cube[1][0][2] != cube[1][1][2]) 
	)
	{
		r_();
		ui_();
		r_();
		u_();
		r_();
		u_();
		r_();
		ui_();
		ri_();
		ui_();
		r_();
		r_();
	}//做三循环直到复原棱块
	
	while(cube[4][1][1] != cube[4][1][2]){ui_();}//调整顶层使顶层复原 
		 
   }

//情况二 ：四个棱块的位置全是错误的，那就先做一遍棱块三循环，在归结到情况一去 
	else
{
	if(!( 
	(cube[0][0][2] == cube[0][1][2]) || 
	(cube[1][0][2] == cube[1][1][2]) ||
	(cube[5][0][2] == cube[5][1][2]) ||
	(cube[4][0][2] == cube[4][1][2]) 
   ))
   {
   	    r_();
		ui_();
		r_();
		u_();
		r_();
		u_();
		r_();
		ui_();
		ri_();
		ui_();
		r_();
		r_();

	if( 
	(cube[0][0][2] == cube[0][1][2]) || 
	(cube[1][0][2] == cube[1][1][2]) ||
	(cube[5][0][2] == cube[5][1][2]) ||
	(cube[4][0][2] == cube[4][1][2]) 
   )
   {

	while( !( (cube[5][0][2] == cube[5][1][2]) &&(cube[5][1][2] == cube[5][2][2] ) ) ) 
	{ui_();}
	//下面开始使用逆时针的棱块三循环公式(R U' R) U (R U R U') (R' U' R2)

	while(
	(cube[4][0][2] != cube[4][1][2])||
	(cube[0][0][2] != cube[0][1][2])||
	(cube[1][0][2] != cube[1][1][2]) 
	)
	{
		r_();
		ui_();
		r_();
		u_();
		r_();
		u_();
		r_();
		ui_();
		ri_();
		ui_();
		r_();
		r_();
	}//做三循环直到复原棱块
	
	while(cube[4][1][1] != cube[4][1][2]){u_();}//调整顶层使顶层复原 
		 
   }
		 
   }//重复情况一的所有操作结束 
} 
 
//pll手法调整棱块结束
//至此pll手法完全结束
//魔方应该已经复原完毕 
	return 0;	
}
