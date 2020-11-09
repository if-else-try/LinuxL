#include "my.h"
int main()
{

        fputs("是否选择更新通讯录(y or n)\n",stdout);
        int c,res;
        c=tolower(fgetc(stdin));
        res=c;
        while(c !='\n' && c!=EOF)
            c=fgetc(stdin);
        if(res =='y')
        {
            MyInput();
            do
            {
                getchar();
                fputs("continue?\n",stdout);
                c=tolower(fgetc(stdin));
                res=c;
                while(c !='\n' && c!=EOF)
                    c=fgetc(stdin);
                if(res =='y') MyInput();
            }while(res =='y');
        }
        //判断是否输出数据
        fputs("Do you want to view telephone book?(y or n)\n",stdout);
        c=tolower(fgetc(stdin));
        res=c;
        while(c !='\n' && c!=EOF)
            c=fgetc(stdin);
        if(res =='y')
        {
            fputs("Sort by letter from a to z?(y or n)\n",stdout);
            c=tolower(fgetc(stdin));
            res=c;
            while(c !='\n' && c!=EOF)
                c=fgetc(stdin);
            if(res=='y'){
                MySort(0);  
            }else{
                MySort(1);
            }
        }
        
    
    return 0;
}
