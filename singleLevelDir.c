#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct directo{
	char dname[10],fname[10][10];
	int fcnt;
}dir;
void main()
{
	int choice=0,i,j;
	char f[20];
	dir.fcnt=0;
	printf("Enter directory name");
	scanf("%s",dir.dname);
	printf("\n1)Create file\n2)Delete File\n3)Search file\n4)Display File\n5)Exit\nEnter Option : ");
	scanf("%d",&choice);
	while(choice!=5)
	{
		
		if(choice==1)
		{
			
			printf("Enter name of file : ");
			scanf("%s",dir.fname[dir.fcnt]);
			dir.fcnt++;
		}
		else if(choice==2)
		{
			printf("Enter name of file :");
			scanf("%s",f);
			for(i=0;i<dir.fcnt;i++)
			{
				if(strcmp(f,dir.fname[i])==0)
				{
					printf("File Deleted");
					for(j=i;j<dir.fcnt;j++)
						{
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						}
				}
			}
			dir.fcnt--;
		}
		else if(choice==3)
		{
			printf("Enter name of file");
			scanf("%s",f);
			for(i=0;i<dir.fcnt;i++)
			{
			
				if(strcmp(f,dir.fname[i])==0)
				{				
				printf("File found");
				break;
				}				
				else if(i==dir.fcnt-1)
				{
				printf("File not found");
				}
					
			}
			
		}
		else if(choice==4)
		{
			printf("Displaying directories %d number",dir.fcnt);
			for(i=0;i<dir.fcnt;i++)
			{
			printf("%s",dir.fname[i]);
			}
		}
		else
		{
			printf("WrongChoice");
		}
		printf("\n1)Create file\n2)Delete File\n3)Search file\n4)Display File\n5)Exit\nEnter Option : ");
		scanf("%d",&choice);
	}
}
