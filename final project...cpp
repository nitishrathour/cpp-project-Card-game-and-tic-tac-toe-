#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<fstream>
using namespace std;
void start();
void comp();
void twoplayer();
void tictac();
void grid();
int check();
void wscore();
void delay(int n)
{
	for(int j=0; j<n; j++)
	for(int i=0; i<n; i++)
	{
	}
}
struct card
{
	int data,flag=0;
	card*next;
}*head=NULL,*tmp,*p;

struct t
{
	int data1;
	t*next1;
}*p1,*tmp1,*head1=NULL;

struct score
{
	char plyr[20];
	int score;
}sc1,sc2;

card* insert(card*head,int data);
card* delete_cards(card*head,int data);
t* openedcards(t*head1,int data);
void displaycards();
int match(int);
void scores(int );
int count=20,p1_score=0,p2_score=0,vs;
char mark='X',s[9]={'1','2','3','4','5','6','7','8','9'},player1[20],player2[20];

int main()
{
	system("color B4");
	cout<<"\t1. CARD GAME ";
	cout<<"\n\n\t2. TIC TAC TOE";
	cout<<"\n\n\tENTER YOUR CHOICE : ";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
			start();
			wscore();
			break;
		case 2:
			tictac();
			break;
		default:
			cout<<"\n Enter any valid number form above ";
	}
	return 0;
}

void start()
{
	int i,j,k=0,ch=0,player=1,input,cpyinput;
	
	//INSERTION
	srand(time(0));
	int arr[][10]={{1,5,8,2,6,9,3,10,4,7},{7,2,8,10,3,1,4,5,9,6},{10,8,1,5,2,7,4,9,3,6},{4,2,8,1,10,3,7,5,6,9},{8,1,10,3,5,9,2,4,6,7},{5,1,9,10,2,8,3,7,4,6}};
	j=rand()%6;
	for(i=1; i<=20; i++)
	{
		head=insert(head,arr[j][k++]);
		if(i==10)
		{	j=rand()%6;
			k=0;
		}
	}
	// GAME START
	delay(5000);
	system("cls");
	printf("\n\t1. Vs comp. ");
	printf("\n\n\t2. Two players ");
	printf("\n\n Enter your choice : ");
	scanf("%d",&vs);
	system("cls");
	displaycards();
	if(vs==1)
	{
		cout<<"\n Enter your Name : ";
		scanf("%s",player1);
		for(i=1; i<=20; i++)
		{
		if(player==-1)
		{	cout<<"\nCOMPUTER";
			a:
			srand(time(0));
			input=rand()%(count+1);
			if(input==0)
			goto a;
		}
		else
		{
			cout<<"\n"<<player1;
			cout<<" Select any number within "<<count<<"  ";
			cin>>input;
			if(input==0)
				exit(0);
		}
		cpyinput=input;
		if(input>count)
			{
				system("color C");
				cout<<"\n INVALID INPUT ";
				i--;
			}
		else
		{
			p=head;
			while(--cpyinput)
				p=p->next;
			if(p->flag==1)
			{
				system("color C");
				if(player==1)
				{i--;   cout<<"\n INVALID INPUT ";ch=0;delay(100);goto b;}
				else
				goto a;
			}
				system("cls");
				p->flag=1;
				ch=match(p->data);
				if(ch==0)
				head1=openedcards(head1,p->data);
				else
				{
					displaycards();
					count-=2;
					if(player==1)
					p1_score++;
					else p2_score++;
					int m=p->data;
					cout<<endl<<"Match found of number : "<<p->data<<"\n\n";
					head=delete_cards(head,m);
					head=delete_cards(head,m);
				}
				displaycards();
				scores(vs);
			b:
			if(ch==0)
			player*=-1;	
		}
		}
		if(p1_score==p2_score)
		cout<<"\n\n\t\tMATCH DRAW...\n";
		else
		(p1_score>p2_score)?cout<<"\n\n\t\tYOU WON!!! :-)\n":cout<<"\n\n\t\tBETTER LUCK NEXT TIME :-(\n";
		getch();
	}
	else 
	{
		cout<<"\n Enter the PLAYER 1 Name : ";
		scanf("%s",player1);
		cout<<"\n Enter the PLAYER 2 Name : ";
		scanf("%s",player2);
		for(i=1; i<=20; i++)
	{	
	cout<<"\n\n";
	(player==1)?cout<<player1:cout<<player2;
	cout<<" Select any number within "<<count<<"  ";
		cin>>input;
		if(input==0)
			exit(0);
		cpyinput=input;
		if(input>count)
		{
			system("color C");
			cout<<"\n INVALID INPUT ";
			i--;
		}
		else
		{
			p=head;
			while(--cpyinput)
				p=p->next;
			if(p->flag==1)
			{
				system("color C");
				cout<<"\n INVALID INPUT ";
				i--;
			}
			else
			{
			system("cls");
			p->flag=1;
			ch=match(p->data);
			if(ch==0)
			head1=openedcards(head1,p->data);
			else
			{
				displaycards();
				count-=2;
				if(player==1)
					p1_score++;
				else p2_score++;
				int m=p->data;
				cout<<endl<<"Match found of number : "<<p->data<<"\n\n";
				head=delete_cards(head,m);
				head=delete_cards(head,m);
			}
			displaycards();
			scores(vs);
			}
			if(ch==0)
		    player*=-1;	
		}
		
	}
	if(p1_score==p2_score)
		cout<<"\n\n\t\tMATCH DRAW...\n";
	else
	(p1_score>p2_score)?cout<<"\n\n\t\t"<<player1<<" WON!!! :-) \n\n\t\t"<<player2<<" BETTER LUCK NEXT TIME :-(\n":cout<<"\n\n\t\t"<<player2<<" WON!!! :-) \n\n\t\t"<<player1<<" BETTER LUCK NEXT TIME :-(\n";
	getch();
	}
}
card* insert(card *head,int num)
{
	if(head==NULL)
	{
		tmp=new card;
		tmp->data=num;
		tmp->next=head;
		head=tmp;
	}
	else
	{
		p=head;
		tmp=new card;
		tmp->data=num;
		while(p->next!=NULL)
			p=p->next;
		p->next=tmp;
		tmp->next=NULL;
	}
	return head;
}
t* openedcards(t*head1,int data)
{
			if(head1==NULL)
					{
						tmp1=new t;
						tmp1->data1=data;
						tmp1->next1=head1;
						head1=tmp1;
					}
			else
					{
						p1=head1;
						tmp1=new t;
						tmp1->data1=data;
						while(p1->next1!=NULL)
						p1=p1->next1;
						p1->next1=tmp1;
						tmp1->next1=NULL;
					}
		return head1;
}

int match(int inp)
{
	t *temp;
	temp=new t;
	p1=head1;
	if(head1==NULL)
		return 0;
	if(head1->data1==inp)
	{
		temp=head1;
		head1=head1->next1;
		free(temp);
		return 1;
	}
	p1=head1;
		while(p1->next1!=NULL)
		{
			if(inp==p1->next1->data1)
			{
				temp=p1->next1;
				p1->next1=temp->next1;
				free(temp);
				return 1;
			}
			p1=p1->next1;
		}

	return 0;
}
card* delete_cards(card*head,int inp)
{
	card*tmp;
	p=head;
	if(head==NULL)
		return head;
	if(head->data==inp)
	{
		tmp=head;
		head=head->next;
		free(tmp);
		return head;
	}
	p=head;
		while(p->next!=NULL)
		{
			if(inp==p->next->data)
			{
				tmp=p->next;
				p->next=tmp->next;
				free(tmp);
				return head;
			}
			p=p->next;
		}
		count--;
		return head;
}

void displaycards()
{
			card *p=head;
			while(p!=NULL)
			{
			if(p->flag==1)
			cout<<" [ "<<p->data<<" ]";
			else cout<<" [--] ";
			p=p->next;
			}
			cout<<endl;
}
void scores(int vs)
{ 
	system("color B");
	if(vs==1)	
		cout<<"\n "<<player1<<" score : "<<p1_score<<"\n COMPUTER score :"<<p2_score;
	else
	cout<<"\n Player 1 score : "<<p1_score<<"\n Player 2 score :"<<p2_score;
	
}
void tictac()
{
	system("cls");
	cout<<"\n\t1.Vs Computer ";
	cout<<"\n\n\t2.Two Players";
	cout<<"\n \n\tEnter your choice";
	cin>>vs;
	int input,player=0,y=0;
	if(vs==1)
	{	cout<<"\nEnter the PLAYER Name : ";
		scanf("%s",player1);
	}
	else
	{
		cout<<"\n Enter the PLAYER 1 Name : ";
		scanf("%s",player1);
		cout<<"\n Enter the PLAYER 2 Name : ";
		scanf("%s",player2);
	}
	
	do
	{
		grid();
		player%=2;
		if(player==0)
			mark='X';
		else 
			mark='O';
		if(player==0 && vs==1)
		{
			srand(time(0));
			input=rand()%9;
		}
		else
		{
			cout<<"\n"<<player1<<" ("<<mark<<")";
			cout<<"\nEnter the position : ";
			cin>>input;
		}
		// switch
		if(input>9 || input<1)
		{
			cout<<"\nINVALID INPUT\nENTER VALUE 1 to 9 ";
			player-=1;
			delay(20000);
		}
		else if(s[input-1]==char(input+48))
				s[input-1]=mark;
		else
		{
			cout<<"\nINVALID INPUT\nENTER VALUE 1 to 9 ";
			player-=1;
			delay(200);
		}
		y=check();
		player+=1;				
	}while(y==-1);
	grid();
	if(y==1 && vs==1)
	{
		if(player==2)
			cout<<"\n\n\tYOU WIN!!!\n";
		else
			cout<<"\n\n\tYOU LOSE!!!\n";
	}
	else if(y==1)
		cout<<"\n\n\tPLAYER "<<player<<" WON!!!\n";
	else
		cout<<"\n\n\tDRAW!!!\n";
	getch();
}
void grid()
{
	system("cls");
    cout << "\n\n\tTIC TAC TOE\n\n";
    if(vs==1)
    cout<<player1<<"  (O)  - COMPUTER (X)  \n\n\n";
    else
    cout <<player1<<" (X)  -  "<<player2<<" (O)\n\n\n";
    cout << "     |     |     \n";
    cout << "  " << s[0] << "  |  " << s[1] << "  |  " << s[2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << s[3] << "  |  " << s[4] << "  |  " << s[5] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << s[6] << "  |  " << s[7] << "  |  " << s[8] << endl;
    cout << "     |     |     \n\n";
}
int check()
{
	int i;
	if((s[0]==s[1]&&s[1]==s[2]) || (s[3]==s[4]&&s[4]==s[5]) || (s[6]==s[7]&&s[7]==s[8]))
		return 1;
	else if((s[0]==s[3]&&s[3]==s[6]) || (s[1]==s[4]&&s[4]==s[7]) || (s[2]==s[5]&&s[5]==s[8]))
		return 1;
	else if((s[0]==s[4] && s[4]==s[8]) || (s[2]==s[4] && s[4]==s[6]))
		return 1;
	else
	{
		for(i=0; i<10; i++)
			if(s[i]==char(i+49))
				return -1;
		return 0;
	}
}
void wscore()
{
	ifstream fin("player.dat",ios::in|ios::binary);
	ofstream fout("temp.dat",ios::out|ios::binary);
	while(fin)     
	{
		fin.read((char*)&sc2,sizeof(sc2));
		if(p1_score>sc2.score)
		{
			if(vs==1)
			{
				strcpy(sc1.plyr,player1);
				sc1.score=p1_score;	
				fout.write((char*)&sc1,sizeof(sc1));
				break;
			}	
		}			
		else 
		{
			fout.write((char*)&sc2,sizeof(sc2));
		}
	}
	while(fin)
	{
		fin.read((char*)&sc2,sizeof(sc2));
		fout.write((char*)&sc2,sizeof(sc2));
	}
	if(fin)
	{
		if(vs==1)
			{
				strcpy(sc1.plyr,player1);
				sc1.score=p1_score;	
				fout.write((char*)&sc1,sizeof(sc1));
			}
	}
	fin.close();
	fout.close();
	remove("player.dat");
	rename("temp.dat","player.dat");
	
	ifstream fin1("player.dat",ios::in|ios::binary);
	fin1.seekg(0);
	cout<<"\t\tLEADERBOARD\n";
	cout<<"\nPlayer     scores ";
	while(fin1)
	{
		fin1.read((char*)&sc2,sizeof(sc2));
		cout<<"\n"<<sc2.plyr<<"\t\t"<<sc2.score;
	}
	fin1.close();
}



