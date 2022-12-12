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
9.string型
reverse(str.begin(), str.end()); 
指针（地址）
1，*解引用运算
2，+-运算（指针之间可以减，不能加，减去可以得到间距）
3，比大小运算（看指针相对位置）
4，分配内存 malloc函数，int *p=（int *）malloc（100*sizeof（int））；
			Free函数，free（p）；（若不还空间会存在内存泄漏问题）
Java C#会有垃圾回收（但会占用资源）而rust可以减少内存泄漏
函数的机制：
int swap(int *a,int *b)传指针
int swap(int &a,int &b)传引用（C++）
返回地址：
每次调用函数时，会创建一个地址，运用堆栈原理储存地址，cpu存在
stackpoint（sp）其实也是在内存里，运用堆栈的pop和push，以保证执行顺序。
swap函数中的int x......的空间同样放在堆栈中，在完成函数后pop出去
return 也同样储存在堆栈中，故return只能返回一个参数
函数中的参数也储存在堆栈中
全局变量：{extern，static}
作用域：整个文件
生命周期：从头到尾
静态局部变量：程序一启动就存在
多个文件的问题（）{
编译运行过程（）{
mian.c
#include
#define
main.c
进行编译（compile）
main.obj目标文件（不同系统不一样）
Link↓（链接都以.c文件联系）（每个.c文件拥有不同的功能）
stdio.lib库文件↓（将所以文件链接）
main.exe}
定义和声明的问题（）{
定义 define{extern int x=10；}（内存在定义时分配）
声明 declare{int x=10；}（定义只能一次，声明可以无数次）


















