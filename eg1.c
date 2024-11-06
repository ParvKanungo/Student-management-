#include<stdio.h>
#include<string.h>
#define Data_file "stud.db"
#define Tmp_file "tmp.db"
typedef struct __student
{
int roll;
char name[26];
}student;

void add_student();
void edit_student();
void delete_student();
void displayListOfStudents();
void search_student();

int main()
{
int choice;
do
{
printf("1. Add student\n");
printf("2. Update student\n");
printf("3. Delete student\n");
printf("4. Serach student\n");
printf("5. Display list of student\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
if(choice ==1) add_student();
else if(choice== 2) edit_student();
else if(choice==3) delete_student();
else if(choice ==4) search_student();
else if(choice == 5) displayListOfStudents();

}while(choice!=6);
return 0;
}

void add_student()
{
int rr;
char nn[27];
char m,q;
student s;
FILE *f;
int found;
printf("Add student module\n");
rr=-1;
printf("Enter roll number : ");
scanf("%d",&rr);
while((q=getchar())!='\n' && q!=EOF);
if(rr<=0)
{
printf("Invalid roll number\n");
return ;
}
f=fopen(Data_file,"rb");
if(f!=NULL)
{

found=0;
while(1)
{
fread(&s,sizeof(student),1,f);
if(feof(f)) break;
if(rr==s.roll)
{
found=1;
break;
}
}
fclose(f);
if(found == 1)
{
 printf("roll number already alloted\n");
return ;
}
}
printf("Enter name: ");
fgets(nn,27,stdin);
while((q=getchar()!='\n' && q!=EOF));
nn[strlen(nn)-1]=='\0';
printf("Save data?(Y/N):");
m=getchar();
while((q=getchar()!='\n' && q!=EOF));
if(m!='Y' && m!='y')
{
printf("Data not saved\n");
return;
}
f=fopen(Data_file,"ab");
if(f==NULL)
{
printf("Error loading data\n");
return ;
}
s.roll = rr;
strcpy(s.name,nn);
fwrite(&s,sizeof(student),1,f);
fclose(f);
printf("Student added\n");
}
//Add student finishes here, next functionality starts!!!!!

void edit_student()
{
int rr;
char nn[27];
char m,q;
student s1, s2;
FILE *f1,*f2;
int found;
printf("Student Update module\n");
rr=-1;
printf("Enter roll number: ");
scanf("%d",&rr);
while((q=getchar())!='\n' && q!=EOF);
if(rr<=0)
{
printf("Invalid roll number\n");
return;
}
f1=fopen(Data_file,"rb");
if(f1==NULL) 
{
printf("Error loading data\n");
return;
}
found =0;
while(1)
{
fread(&s1,sizeof(student),1,f1);
if(feof(f1)) break;
if(rr==s1.roll)
{
found=1;
break;
}
}
fclose(f1);
if(found == 0)
{
printf("Invalid roll number\n");
return;
}
printf("Name is :%s",s1.name);
printf("Want to edit?(Y/N):");
m=getchar();
while((q=getchar())!='\n' && q!=EOF);
if(m!='Y' && m!='y')
{
printf("Student not edited\n");
return;
}
printf("Enter new name: ");
fgets(nn,27,stdin);
while((q=getchar())!='\n' && q!=EOF);
nn[strlen(nn)-1]='\0';
printf("Update details?(Y/N): ");
m=getchar();
while((q=getchar())!='\n' && q!=EOF);
if(m!='Y' && m!='y')
{
printf("Student not updated\n");
return;
}
s1.roll=rr;
strcpy(s1.name,nn);
f1=fopen(Data_file,"rb");
f2=fopen(Tmp_file,"wb");
while(1)
{
fread(&s2,sizeof(student),1,f1);
if(feof(f1)) break;
if(s1.roll != s2.roll)
{
fwrite(&s2,sizeof(student),1,f2);
}
else
{
fwrite(&s1,sizeof(student),1,f2);
}

}
fclose(f1);
fclose(f2);
f1=fopen(Tmp_file,"rb");
f2=fopen(Data_file,"wb");
while(1)
{
fread(&s2,sizeof(student),1,f1);
if(feof(f1)) break;
fwrite(&s2,sizeof(student),1,f2);
}
fclose(f1);
fclose(f2);
f1=fopen(Tmp_file,"wb");
fclose(f1);
printf("Student updated\n");
}

void delete_student()
{
int rr;
char nn[27];
char m,q;
student s1, s2;
FILE *f1,*f2;
int found;
printf("Student Delete module\n");
rr=-1;
printf("Enter roll number: ");
scanf("%d",&rr);
while((q=getchar())!='\n' && q!=EOF);
if(rr<=0)
{
printf("Invalid roll number\n");
return;
}
f1=fopen(Data_file,"rb");
if(f1==NULL) 
{
printf("Error loading data\n");
return;
}
found =0;
while(1)
{
fread(&s1,sizeof(student),1,f1);
if(feof(f1)) break;
if(rr==s1.roll)
{
found=1;
break;
}
}
fclose(f1);
if(found == 0)
{
printf("Invalid roll number\n");
return;
}
printf("Name is :%s\n",s1.name);
printf("Want to delete?(Y/N):");
m=getchar();
while((q=getchar())!='\n' && q!=EOF);
if(m!='Y' && m!='y')
{
printf("Student not edited\n");
return;
}
f1=fopen(Data_file,"rb");
f2=fopen(Tmp_file,"wb");
while(1)
{
fread(&s2,sizeof(student),1,f1);
if(feof(f1)) break;
if(s1.roll != s2.roll)
{
fwrite(&s2,sizeof(student),1,f2);
}

}
fclose(f1);
fclose(f2);
f1=fopen(Tmp_file,"rb");
f2=fopen(Data_file,"wb");
while(1)
{
fread(&s2,sizeof(student),1,f1);
if(feof(f1)) break;
fwrite(&s2,sizeof(student),1,f2);
}
fclose(f1);
fclose(f2);
f1=fopen(Tmp_file,"wb");
fclose(f1);
printf("Student deleted\n");

}

void search_student()
{
int rr;
student s;
FILE *f;
int found;
printf("Student Search Module\n");
printf("Enter roll number: ");
scanf("%d",&rr);
if(rr<=0)
{
printf("Invalid roll number\n");
return;
}
f=fopen(Data_file,"rb");
if(f==NULL)
{
printf("error loading data\n");
return;
}
found=0;
while(1)
{
fread(&s,sizeof(student),1,f);
if(feof(f)) break;
if(rr==s.roll)
{
found=1;
break;
}
}
fclose(f);
if(found == 0)
{
printf("Student not found!!\n");
return;
}
printf("Student found\n");
printf("Name is: %5s",s.name);
}

void displayListOfStudents()
{
int sr;
student s;
FILE *f;
f=fopen(Data_file,"rb");
if(f==NULL)
{
printf("No records\n");
return;
}
sr=0;
while(1)
{
fread(&s,sizeof(student),1,f);
if(feof(f)) break;
sr++;
printf("%5d %10d %3s\n",sr,s.roll,s.name);
}
fclose(f);
if(sr==0)
{
printf("No records\n");
return;
}
}




