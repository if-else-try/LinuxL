#include"my.h"
#define err_exit(MESSAGE) (                \
    perror(MESSAGE),                       \
    exit(1)                                \
)

typedef struct USER{
    int id;
    char name[8];
    char htel[12];
    char tel[12];
};

int MyInput(void)
{
  pt = (recorder *) malloc(sizeof(recorder));
	printf("请输入编号\n");
	scanf("%d",&(pt->id));
	printf("请输入姓名\n");
        scanf("%s",pt->name);
	printf("请输入电话\n");
        scanf("%s",pt->htel);
	printf("请输入手机号\n");
        scanf("%s",pt->tel);

    	MyRanddat(pt);
   	MySave(pt);
	return pt;
}

int MySave(recorder * ptr)
{
    FILE *stream;
    stream=fopen("user.dat","a");
    char str[40]="";
    sprintf(str,"%d",ptr->id);
    //strcat(str,user.id);
    strcat(str,"\t");
    strcat(str,ptr->name);
    strcat(str,"\t");
    strcat(str,ptr->htel);
    strcat(str,"\t");
    strcat(str,ptr->tel);
    strcat(str,"\n");
    
    fputs(str,stream);
    fclose(stream);
    struct user usert;
    sscanf(str,"%d\t%s\t%s\t%s\n",&usert.id,usert.name,usert.htel,usert.tel);
    MyOutput(usert);
    return 0;
}

int MyCompar(const void *a,const void *b)
{
    int i=0;
    char *stra=((struct USER*)a)->name;
    char *strb=((struct USER*)b)->name;
    while(stra[i]!='\0'&&strb[i]!='\0')
    {
        if(stra[i]>strb[i])
        {
            return 1;
        }
        if(stra[i]<strb[i])
        {
            return -1;
        }
        i++;
    }
    if(stra[i]=='\0'&&strb[i]=='\0') return 0;
    if(stra[i]=='\0'&&strb[i]!='\0') return -1;
    if(stra[i]!='\0'&&strb[i]=='\0') return 1;
}

int MySort(int way)
{
    FILE *stream=fopen("user.dat","r");
    //测有多少条数据
    int sum=0;
    char c=fgetc(stream);
    while(!feof(stream))
    {
        if(c=='\n') sum++;
        //printf("now user:%d\n",sum);
        c=fgetc(stream);
    }
    //printf("all user:%d\n",sum);
    rewind(stream);
    
    
    //将数据读到数组中
    struct USER users[sum];
    int i=0;
    for(i=0;i<sum;i++)
    {
        char *str;
        size_t n=40;
        str=(char*)malloc(40);
        getline(&str,&n,stream); 
        //printf("%ld %s\n",n,str);
        sscanf(str,"%d %s %s %s",&users[i].id,users[i].name,users[i].htel,users[i].tel);
    }
    qsort(users,sum,sizeof(struct USER),MyCompar);
    if(way>0)
    {
        for(i=sum-1;i>=0;i--) MyOutput(users[i]);
    }else{
        for(i=0;i<sum;i++) MyOutput(users[i]);
    }

    
    return 0;
}

int MyRanddat(recorder * ptr)
{
    if(ptr->name[0]>'Z'||ptr->name[0]<'A')
        err_exit("The name must begin with a capital letter.");
    int i=0;
    while(ptr->name[i]!='\0')
    {
        i++;
        if(i>8) err_exit("The maximum number of names is 8.");
    }
    if(strchr(ptr->tel,'-') == NULL)
    {
    	err_exit("tel需要包含-");
    }
    if(ptr->id < 0 || ptr->id > 4294967295)
    {
    	err_exit("id区间0--4294967295");
    }
    return 0;
}

int MyOutput(struct USER user)
{
  
    printf("%d\t%s\t%s\t%s\n",user.id,user.name,user.htel,user.tel);
    return 0;
}
