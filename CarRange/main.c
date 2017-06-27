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
    fw=fopen("//Users//a20161104567//Desktop//CarRange//output.csv","w+");
    if(fr==NULL)
    {
        printf("打开文件错误，您打开的文件可能不存在\n");
    }
    else
    {
        fscanf(fr,"%s\n%s",s1,s2);
        printf("%s\n%s\n",s1,s2);
        //fprintf(fw,"%s\n%s\n",s1,s2);
        printf("解读GPS\n");
        fprintf(fw,"解读GPS\n");
        printf("日期,时间,纬度,经度,海拔,地面速率,地面航线\n");
        fprintf(fw,"日期,时间,维度,经度,海拔,地面速率,地面航线\n");
        for(i=0;i<6;i++)
        {
            date[i]=s1[51+i];
        }
        date[6]='\0';
        
        for(i=0;i<6;i++)
        {
            time[i]=s1[7+i];
        }
        time[6]='\0';
        
        for(i=0;i<8;i++)
        {
            lg[i]=s1[16+i];
        }
        lg[8]='\0';
        
        for(i=0;i<8;i++)
        {
            lat[i]=s1[28+i];
        }
        lat[8]='\0';
       
        for(i=0;i<5;i++)
        {
            rate[i]=s1[39+i];
        }
        rate[5]='\0';
        
        for(i=0;i<5;i++)
        {
            heading[i]=s1[45+i];
        }
        heading[5]='\0';
        
        printf("%s,%s,%s,%s,%sm,%sm/s,%s\n",date,time,lg,lat,high,rate,heading);
        fprintf(fw,"%s,%s,%s,%s,%s,%s,%s\n",date,time,lg,lat,high,rate,heading);
        fclose(fr);
        fclose(fw);
    }
    
    return 0;
}
