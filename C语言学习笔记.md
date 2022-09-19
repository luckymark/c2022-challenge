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
6.修改、提交代码：

git status
git add .
git commit -m "完成了running letter"
git push

7.创建本地仓库：

git clone https://github.com/ **YourGithubAccount** /c2022-challenge
cd c2022-challenge
ls

git config user.name "???"
git config user.email "???"

git remote -v
git remote add upstream https://github.com/luckymark/c2022-challenge

8.从 https://github.com/luckymark/c2022-challenge 获取更新

git fetch upstream
git merge upstream/master

8.判断两个字符串相等
strcmp(a,b);
若返回0则相等，否则为1或-1；
