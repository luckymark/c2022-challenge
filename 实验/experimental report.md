## 五子棋的实验报告

蔡超凡 2022080903026

### 一、实验目的和要求

用c++实现具有图形化界面的五子棋小游戏

### 二、五子棋的基本规则

 棋盘为大小为15*15，对局双方各执一色棋子，空棋盘开局，黑先、白后，交替下子，每次只能下一子。最先连成五子获胜（横、竖、撇、捺四个方向）。

### 三、类的设计

![类](C:\Users\超凡\Desktop\类.png)

共设计有ChessGame、Chess、Player、Al、ChessBoard、ChessPos、Node

####  1、ChessGame类

  CheesGmae用于控制整个游戏的运行

```
`class ChessGame`
`{`
`public:`
	`ChessGame(Player*, Al*, Chess*, ChessBoard*, Node*);`
	`void play();`

`private:`
	`Player* player;`
	`Al* ai;`
	`Chess* chess;`
	`ChessBoard* board;`
`};`
```

#### 2、Chess类

Chess类用于完成图形化界面，包括棋盘图片的加载、棋子图片的加载、玩家落子位置的判断等，以及基本的棋局逻辑，如棋局结束和胜负的判断

```
class Chess
{
private:
	int boardSize;// 棋盘尺寸（15线）
	float margin_x;//水平边界距离;
	int margin_y;//垂直边界距离;
	float chessSize; //棋子大小（棋盘方格大小）
	int windowWidth = 1400;//窗口宽度
	int windowHigth = 700;//窗口高度

	IMAGE lostImg;
	IMAGE winImg;
	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;

	//标示下棋方, true:黑棋方  false:白棋方
	bool playerFlag;

	//棋盘，用于存储棋局情况
	ChessBoard* board;
public:
	//构造函数
	Chess(int boardSize, int marginX, int marginY, float chessSize);

	//Chess的初始化，创建窗口
	//当棋局开始时会执行一次，且每一局只会执行一次
	bool init(ChessBoard* board);
	//加载棋盘的图片资源，初始化棋盘的相关数据
	void loadChessBoard();
	//判断玩家的先后手选择
	bool chooseHand();

	//判断在指定坐标(x,y)位置，是否是有效点击
	//如果是有效点击，把有效点击的位置(行，列）保存在参数pos中
	bool clickBoard(int x, int y, ChessPos* pos);
	//在棋盘的指定位置落子,true 黑 、false 白
	void chessDown(ChessPos* pos, bool payerFlag/*chess_kind_t kind*/);

	//悔棋函数
	void turnBack(bool black_white);
	//换手函数
	void changeHand(ChessPos* pos);
	// 判断棋局是否结束
	bool checkOver(bool flag);
	bool checkWin();
	bool heqi();

	//用于获取棋盘大小（15线）的接口
	int getBoardSize();
	//用于获取playerFlag的接口
	bool getPlayerFlag();
};
```

#### 3、Player类

Player用于完成玩家的落子

```
class Player
{
private:
	Chess* chess;
	ChessBoard* board;
	bool blck_white = true;//判断玩家先后手，默认为先手
public:
	//玩家初始化
	void init(Chess* chess, ChessBoard* board);
	//玩家落子
	bool go();
	//black_white的set函数
	void setBlack_White(bool flag);
};
```

#### 4、Al类

Al用于完成计算机的落子

```
class Al
{
private:
	bool black_white = false;//判断al先后手 默认为后手
	Chess* chess;
	//棋盘，用于存储棋局情况
	ChessBoard* board;
	Node* node;

	// 存储各个点位的评分情况，作为AI下棋依据
	vector<vector<int>> scoreMap;
public:
	void init(Chess* chess, ChessBoard* board, Node* node);
	void go();
	void setBlack_White(bool flag);
};
```

#### 5、ChessBoard类

ChessBoard储存棋局信息

```
class ChessBoard
{
private:
	//上一步落子位置
	vector<ChessPos> lastPos;
	//存储当前游戏棋盘和棋子的情况,空白为0，黑子1，白子-1
	vector<vector<int>> chessMap;

public:
	//构造函数
	ChessBoard(int boardSize);

	//初始化棋盘——清空棋盘上的棋子
	void clearBoard();
	//落子完更新棋盘上的棋子信息
	void updateGameMap(ChessPos* pos, bool playerFlag);

	//用于获取棋盘某个位置的信息（白、黑、空）的接口  有两个重载函数
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);

	//lastPos的get、set函数
	ChessPos getLastPos();
	vector<ChessPos>* setLastPos();
	//ChessMap的get、set函数
	vector<vector<int>> getChessMap();
	vector<vector<int>>* setChessMap();
};
```

#### 6、ChessPos

ChessPos其实是一个结构变量，但使用较多，而且比较重要，姑且把它当作类

```
struct ChessPos
{
	int row;
	int col;
	//构造函数
	ChessPos(int r = 0, int c = 0);
};
```

#### 7、Node

Node用于实现深度搜索，是计算机实现下棋的核心

```
class Node
{
private:
	int num = 30;//每个节点的子节点个数（树的宽度）
	vector<vector<int>> scoreMap;
	vector<vector<int>> chessBoard;
	int min_x=7;
	int min_y=7;
	int max_x=7;
	int max_y=7;
	int bestRow = 0;
	int bestCol = 0;
	//每一点的权重
	vector<vector<int>> p={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1}, 
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,3,3,3,2,2,2,1,1,1},
							{1,1,1,2,2,2,3,3,3,2,2,2,1,1,1}, 
							{1,1,1,2,2,2,3,3,3,2,2,2,1,1,1}, 
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
public:
	void down(int row, int col, bool type);//false white
	void judgeRange(int i, int j);
	void revokeChess(int row, int col);
	//构造函数
	Node();
	//建立node与chessboard的联系
	void relate(ChessBoard* board);
	//局面估值
	int evaluate(bool black_white);
	//对每个点估值
	void calculateScore();

//选取可能的落子点
vector<ChessPos> think();
//Alpha-beta+minimax
int minimax(int depth, int alpha, int beta, bool black_white);
int getBestRow();
int getBestCol();

};
```



### 四、实现的功能

#### 1、玩家可选择先后手

在游戏开始前玩家可以通过鼠标点击选择先后手

<img src="C:\Users\超凡\Desktop\屏幕截图 2023-02-22 112618.png" alt="屏幕截图 2023-02-22 112618" style="zoom: 33%;" />

#### 2、玩家可以悔棋任意步

#### 3、玩家在游戏过程中可以选择从新开始

<img src="C:\Users\超凡\Desktop\屏幕截图 2023-02-22 112645.png" alt="屏幕截图 2023-02-22 112645" style="zoom:33%;" />

### 五、五子棋的运行逻辑

```
`int main()`
`{`
	`ChessBoard board(15);`
	`Node node;`
	`Chess chess(15, 290, 64, 41);`
	`Player player;`
	`Al ai;`
	`ChessGame game(&player, &ai, &chess, &board, &node);`
	`game.play();`
	`return 0;`
`}`
```



### 六、计算机下棋的核心算法

#### 1、估值函数

刚开始觉得估值函数是最好写的一部分，但深入了解以及动手写了一点后发现，其实并没有那么简单，估值函数可以说是整个实验最难精进的部分，但它又直接决定计算机的下棋速度和实力上限。网上大概有两大种估值方式（这里指对局面估值，不是对某一点估值），一是列举可能的棋形，如活三、眠四、双活三等，然后通过条件语句和棋盘上的棋子匹配，另一种则是遍历棋盘上的所有棋链（棋盘上连续的格子连成的一条链，长度一般有5、6、7不等，如图），针对每条棋链的情况（黑棋、白起、空的个数）进行赋分。前者的优势在于准确，后者的优势在于速度和代码量。最开始时我写了一个小demo，采用第一种方式，计算机对棋局评判的准确度确实高，但要穷尽所有可能实在太费精力，速度也会比较慢，所以后来在正式写的时候选的是后者。

<img src="C:\Users\超凡\Desktop\屏幕截图 2023-02-22 123012.png" alt="屏幕截图 2023-02-22 123012" style="zoom: 33%;" />

#### 2、minimax算法/nagemax算法+alpha-bate剪枝

minimax算法通过深度搜索来找到最优解，但由于存在许多明显无用的落子点需要排除，所以在最开始的时候，我写了一个用于筛选比较合理的落子点的函数，但由于“博弈树”这个词太具迷惑性，因为在实际的算法设计中并不需要真正地建一棵树，而我却误以为却以为要生成一颗树，再对树进行搜索，导致过多地使用new，频繁地调用堆导致速度慢（调试时发现主要耗时都在生成博弈树上，搜索极大值反而不怎么耗时，平均<<1s），影响运行速度（深度为6，宽度为5时，平均每步耗时4s；深度为6，宽度为6时，平均每步耗时12s）。虽然速度慢，但是此时搜索深度也达到6，可计算机的棋力依旧一般，查询资料后发现我选取落子点的原理有点像传统的启发式算法，但搜索的节点个数太少，很容易陷入局部最优解。

之后我重写了minimax函数，这次并没有生成一颗真正的树，所以速度快了很多，为了防止局部最优解，搜索将会搜索棋盘上的所有可落子点，但这会使搜索节点大大增加，速度减慢（2层平均时间为4s，4层跑了几分钟都跑不出来），增加alpha-beta剪枝后，速度虽然有所增加，但由于选取落子点的顺序是从棋盘左上角开始一行一行搜索，导致最优节点都在树的中间分支，剪枝的效果并不是很好（平均每步>10s）。所以，我改变落子点选择的顺序，采用从天元开始，螺旋式向外搜索（如下图）。

<img src="C:\Users\超凡\Desktop\屏幕截图 2023-02-22 121635.png" alt="屏幕截图 2023-02-22 121635" style="zoom: 33%;" />

再加上使用了局部估值（如下图），即不对整个棋盘估值，而是只对有棋子的区域进行估值，速度有了质的飞跃（搜索深度为4时，平均每步5-7s）。

<img src="C:\Users\超凡\Desktop\屏幕截图 2023-02-22 213147.png" alt="屏幕截图 2023-02-22 213147" style="zoom: 50%;" />



#### 3、启发式算法

虽然速度有了提高，但搜索4层需要6s的速度依旧难以接受，所以我采用启发式算法选取num（变量）个最有可能的位置搜索，这num个位置是由估值函数选取出来的，不同于对局面的估值，它是对某一个位子进行估值，选取合适的num可以在保证棋力的同时提高速度，测试得搜索深度为4，num为30时，平均每步<0.5s；搜索深度为4，num为60时，平均每步2s；索深度为6，num为30时，平均每步11s。现在计算机下棋的棋力不变，而速度要远胜以前。

### 七、总结

完成本次实验，我的收获相当丰富，第一次使用c++写一个比较复杂的程序，让我对面向对象有了更加深刻的理解，对一些接口的设计也有了经验。在完成如此大的程序过程中，调试是必不可少的，调试的时间甚至比构思、编写代码所花费的时间还多，在此过程中，我对调试有了新的认知，学会了许多调试的技巧，对VS的使用也更加熟练。

而本实验的核心部分，也是我花费时间最多的部分，最开始是估值算法，其实编写一个普通的估值算法是比较简单的，主要依靠编写者对五子棋的理解，接着是minimax算法，这个算法是理解博弈游戏的本质，也是Al的基础。它的原理比较简单，但要转化为代码却没那么简单，需要对递归有一定的理解，这个当初是废了我不少功夫，但真正理解之后，收获也很多，同时还认识了negamax算法，其原理与minimax一致，但代码量少了将近一半，更加简洁。为了提高搜索的效率，采用α-β剪枝对博弈树进行修剪。对初学者来说，α-β剪枝其实是有点难理解的，α、β代表什么，以及为什么α>β时可以减枝，这都是难点。α-β剪枝的效率十分依赖遍历的顺序，如果极大值位于根节点的最后一棵子树时，那剪枝几乎没有效果，所以有引入启发式算法对落子点进行排序，提高剪枝的效率。还可以采用主要变例搜索pvs（最小窗口搜索）对α-β剪枝进行优化，但由于我的启发式算法对落子点的排序效果一般，pvs反而增加了搜索的时间，所以最后没有使用。

目前，计算机的棋力还比较一般，大概是由于估值函数写的不够好，这是本次实验的一大遗憾。

在本次实验中，我遇到了许多问题，也解决了许多问题，掌握了新的算法，了解了许多经典的算法，拓展了知识面，收获十分丰富。