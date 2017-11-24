#include<string.h>
#include<stdio.h>
void main()
{
	char opcode[10],operand[10],label[10];
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("in.txt","r");
	fp2=fopen("ntab.txt","w+");
	fp3=fopen("dtab.txt","w+");
	fscanf(fp1,"%s%s%s",label,opcode,operand);
	while(strcmp(opcode,"MEND")!=0)
	{
		if(strcmp(opcode,"MACRO")==0)
		{
			
			fprintf(fp2,"%s\n",label);
			fprintf(fp3,"%s %s\n",label,operand);
		}	
		else
		{
			fprintf(fp3,"%s %s\n",opcode,operand);
		}
		fscanf(fp1,"%s%s%s\n",label,opcode,operand);
	}
	fprintf(fp3,"%s\n",opcode);

fclose(fp1);
fclose(fp2);
fclose(fp3);


}
