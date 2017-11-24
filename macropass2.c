#include<string.h>
#include<stdio.h>
#include<string.h>
void main()
{
	char opcode[10],operand[10],name[10],label[10],la[10],mn[10],op[10];
	int length,i;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	fp1=fopen("in.txt","r");
	fp2=fopen("ntab.txt","r");
	fp3=fopen("dtab.txt","r");
	fp4=fopen("atab.txt","rw");
	fp5=fopen("exp.txt","w+");
	fscanf(fp1,"%s%s%s",label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		if(strcmp(opcode,"MACRO")==0)
		{
			while(strcmp(opcode,"MEND")!=0)
			{
				fscanf(fp1,"%s%s%s",label,opcode,operand);
			}
		}
		else
		{
			fscanf(fp2,"%s",name);
			if(strcmp(name,opcode)==0)
			{
				for(i=0;i<strlen(operand);i++)
				{
					if(operand[i]==',')
						fprintf(fp4,"\n");
					else
						fprintf(fp4,"%c",operand[i]);
				}
				fprintf(fp5,"%s %s\n",opcode,operand);
				fscanf(fp3,"%s%s",la,mn);
				fscanf(fp3,"%s%s",la,mn);
				while(strcmp(la,"MEND")!=0)
				{
					fprintf(fp5,"%s ",la);
					if(mn[0]=='&')
					{
					fscanf(fp4,"%s",op);
					fprintf(fp5,"%s \n",op);
					}
					fscanf(fp3,"%s%s",la,mn);
				}
			}
			else
			{
				fprintf(fp5,"%s %s %s\n",label,opcode,operand);
			}
			

		}
	fscanf(fp1,"%s%s%s",label,opcode,operand);
	}
	
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
fclose(fp5);

}
