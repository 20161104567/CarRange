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
    char year[10],month[10],date[10],time[10],branch[10],sec[10],lg[10],assign1[10],lat[12],assign2[10],high[10],rate[10],heading[10],moon[10];
    fr=fopen("//Users//a20161104567//Desktop//CarRange//GPS170510.log","r+");
    fw=fopen("//Users//a20161104567//Desktop//CarRange//output.csv","w+");
    if(fr==NULL)
    {
        printf("打开文件错误，您打开的文件可能不存在\n");
    }
    else
    {
        printf("解读GPS\n");
        fprintf(fw,"解读GPS\n");
        printf("日期,时间,纬度,经度,海拔,地面速率,地面航向,卫星数\n");
        fprintf(fw,"日期,时间,纬度,经度,海拔,地面速率,地面航向,卫星数\n");
        while (fscanf(fr,"%s %s",s1,s2)!=EOF)
        {
            
            for(i=0;i<2;i++)
            {
                year[i]=s1[55+i];
            }
            year[2]='\0';
            
            for(i=0;i<2;i++)
            {
                month[i]=s1[53+i];
            }
            month[2]='\0';
            
            for(i=0;i<2;i++)
            {
                date[i]=s1[51+i];
            }
            date[2]='\0';
            
            for(i=0;i<2;i++)
            {
                time[i]=s1[7+i];
            }
            time[2]='\0';
            
            for(i=0;i<2;i++)
            {
                branch[i]=s1[9+i];
            }
            branch[2]='\0';
            
            for(i=0;i<2;i++)
            {
                sec[i]=s1[11+i];
            }
            sec[2]='\0';
            
            for(i=0;i<2;i++)
            {
                lat[i]=s1[16+i];
            }
            lat[2]='\0';
            
            for(i=0;i<4;i++)
            {
                assign1[i]=s1[18+i];
            }
            assign1[4]='\0';
            
            for(i=0;i<3;i++)
            {
                lg[i]=s1[27+i];
            }
            lg[3]='\0';
            
            for(i=0;i<6;i++)
            {
                assign2[i]=s1[30+i];
            }
            assign2[6]='\0';
            
            for(i=0;i<4;i++)
            {
                high[i]=s2[43+i];
            }
            high[4]='\0';
            
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
            
            for(i=0;i<2;i++)
            {
                moon[i]=s2[39+i];
            }
            moon[2]='\0';
            
            printf("%s年%s月%s日,%s时%s分%s秒,%s度%s分,%s度%s分,%sm,%s公里／小时,%s度,%s颗\n",year,month,date,time,branch,sec,lat,assign1,lg,assign2,high,rate,heading,moon);
            fprintf(fw,"%s年%s月%s日,%s时%s分%s秒,%s度%s分,%s度%s分,%sm,%s公里／小时,%s度,%s颗\n",year,month,date,time,branch,sec,lat,assign1,lg,assign2,high,rate,heading,moon);

        }
        fclose(fr);
        fclose(fw);
    }
    
    return 0;
}
