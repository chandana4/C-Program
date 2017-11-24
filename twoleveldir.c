#include<stdio.h>
#include<string.h>
struct direct
{
	char dname[10];
	char fname[10][10];
	int fcnt;
}dir[10];
void main()
{
	int choice=0,i,j,dcnt=0,e=0,pos,d;
	char f[20],dirname[20],fo[20];
	
	while(choice<6)
	{	
		printf("\n1.Create directory\n2.Create file \n3.Delete \n4.Search\n5.Display \n 6.Exit \nEnter Choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			e=0;
			printf("enter name of directory");
			scanf("%s",dirname);
			for(i=0;i<dcnt;i++)
			{
				if(strcmp(dirname,dir[i].dname)==0)
				{
					printf("directory already exists");
					e=1;
					break;
				}
			}
			if(e==0)
			{
				printf("directory created");
				strcpy(dir[dcnt].dname,dirname);
				dir[dcnt].fcnt=0;
				dcnt++;
				
			}
			choice=0;
		}					
		else if(choice==2)
		{
			e=0;
			printf("enter name of directory");
			scanf("%s",dirname);
			for(i=0;i<dcnt;i++)
			{
				if(strcmp(dirname,dir[i].dname)==0)
				{
					e=1;
					pos=i;
				}
			}
			if(e==0)
			{
				printf("directory doesnt exist");
			}
			else
			{ 
				printf("enter name of file \n");
				scanf("%s",fo);
				strcpy(dir[pos].fname[dir[pos].fcnt],fo);
				dir[pos].fcnt++;
			}	
			choice=0;
		}
		else if(choice==3)
		{
			e=0;
			printf("enter name of directory");
			scanf("%s",dirname);
			for(i=0;i<dcnt;i++)
			{
				if(strcmp(dirname,dir[i].dname)==0)
				{
					e=1;
					pos=i;
				}
			}
			if(e==0)
			{
				printf("directory doesnt exist");
			}
			else
			{
				printf("enter name of file to be deleted\n");
				scanf("%s",f);
				for(i=0;i<dir[pos].fcnt;i++)
				{
					if(strcmp(f,dir[pos].fname[i])==0)
					{
						printf("file is deleted\n");
						for(j=i;j<dir[pos].fcnt;j++)
						{
							strcpy(dir[pos].fname[i],dir[pos].fname[dir[pos].fcnt-1]);
						}
					}
				}
			
			dir[pos].fcnt--;
			}
			choice=0;
		}
		else if(choice==4)
		{
			e=0;
			printf("enter name of directory");
			scanf("%s",dirname);
			for(i=0;i<dcnt;i++)
			{
				if(strcmp(dirname,dir[i].dname)==0)
				{
					e=1;
					pos=i;
				}
			}
			if(e==0)
			{
				printf("directory doesnt exist");
			}
			else
			{     
				d=0;
				printf("enter name of file to be searched\n");
				scanf("%s",f);
				for(i=0;i<dir[pos].fcnt;i++)
				{
					if(strcmp(f,dir[pos].fname[i])==0)
					{	printf("File found\n");
						d=1;
						break;
					}				
				}
				if(d==0)
					printf("File not found\n");			
			}	
					
			choice=0;
		}
						
		else if(choice==5)
		{
			for(i=0;i<dcnt;i++)
			{
				printf("%s\n",dir[i].dname);
				for(j=0;j<dir[i].fcnt;j++)
				{
					printf("%s\n",dir[i].fname[j]);
				}
			}
			choice=0;
		}
		else 
		{
			choice=6;
		}
	}
}
