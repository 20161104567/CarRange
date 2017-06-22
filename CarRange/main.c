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
    char date[10],time[10],lat[10],lg[10],high[10];
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
        fclose(fr);
        fclose(fw);
    }
    
    return 0;
}
