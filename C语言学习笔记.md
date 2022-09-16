# C语言学习笔记

# 记录你学习过程中的所见所思！酸甜苦辣！

# 看什么看！ 赶紧填坑啊！ 
1,string型字符串指针编译（存疑）
char* p = const_cast<char*>(a.c_str());📐
2,计算时间
clock_t start，end；
start=clock（）；
end=clock（）；
3,输出ASCII码表（扩充表）
SetConsoleOutputCP(437);//显示大于127的ASCII码
	printf("%c%c", 219,254);
4,char* fptr(文件指针)=FILE *fopen(const char*filename,char*mode)
其中filename是文件的路径和名字，mode是打开的方式
mode=r--仅读
            w--建立或打开一个供写入的文件，若已存在则废弃原内容
            a--建立或打开一个供写入的文件，若已存在则写入到文件尾部
            r+--打开一个已存在的文件，供读取和写入
            w+--建立或打开一个供读写的文件，若已存在则废弃原内容
            a+--建立或打开一个供读写的文件，若已存在则写入到文件尾部
            b--打开一个二进制文件
fprintf(fptr,char*);写入（stdio.h流）
fscanf（fptr，"%s",char *);
fclose(fptr);
5,输入带空格的字符串
scanf("%[^\n]",char *a);
