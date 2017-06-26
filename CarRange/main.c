//
//  main.c
//  CarRange
//
//  Created by 20161104567 on 17/6/22.
//  Copyright © 2017年 20161104567. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *fr;
    FILE *fw;
    int i;
    char s1[70],s2[70];
    char date[10],time[10],lat[10],lg[12],high[10],rate[10],heading[10];
    fr=fopen("//Users//a20161104567//Desktop//CarRange//input.txt","r+");
    fw=fopen("//Users//a20161104567//Desktop//CarRange//output.txt","w+");
    if(fr==NULL)
    {
        printf("打开文件错误，您打开的文件可能不存在\n");
    }
    else
    {
        fscanf(fr,"%s\n%s",s1,s2);
        printf("%s\n%s\n",s1,s2);
        fprintf(fw,"%s\n%s\n",s1,s2);
        printf("解读GPS为：\n");
        fprintf(fw,"解读GPS为：\n");
        for(i=0;i<6;i++)
        {
            date[i]=s1[51+i];
        }
        date[6]='\0';
        printf("日期：%s",date);
        fprintf(fw,"日期：%s",date);
        printf("\t");
        for(i=0;i<6;i++)
        {
            time[i]=s1[7+i];
        }
        time[6]='\0';
        printf("时间：%s",time);
        fprintf(fw,"时间：%s",time);
        printf("\t");
        for(i=0;i<10;i++)
        {
            lg[i]=s1[15+i];
        }
        lg[10]='\0';
        printf("纬度：%s",lg);
        fprintf(fw,"纬度：%s",lg);
        switch(s1[25])
        {
            case 'N':
                printf("北纬");
                fprintf(fw,"北纬");
                break;
            case 'S':
                printf("南纬");
                fprintf(fw,"南纬");
                break ;
        }
        printf("\t");
        for(i=0;i<9;i++)
        {
            lat[i]=s1[28+i];
        }
        lat[9]='\0';
        printf("经度：%s",lat);
        fprintf(fw,"经度：%s",lat);
        switch(s1[37])
        {
            case 'E':
                printf("东经");
                fprintf(fw,"东经");
                break;
            case 'W':
                printf("西经");
                fprintf(fw,"西经");
                break ;
        }
        printf("\t");
        for(i=0;i<4;i++)
        {
            high[i]=s2[43+i];
        }
        high[4]='\0';
        printf("海拔：%sm",high);
        fprintf(fw,"海拔：%sm",high);
        printf("\t");
        for(i=0;i<5;i++)
        {
            rate[i]=s1[39+i];
        }
        rate[5]='\0';
        printf("地面速率：%sm/s",rate);
        fprintf(fw,"地面速率：%sm/s",rate);
        printf("\t");
        for(i=0;i<5;i++)
        {
            heading[i]=s1[45+i];
        }
        heading[5]='\0';
        printf("地面航向：%s",heading);
        fprintf(fw,"地面航向：%s",heading);
        printf("\t");
        printf("\n");
        fprintf(fw,"\n");
        fclose(fr);
        fclose(fw);
    }
    
    return 0;
}
