#include"pushboxes.h"

int step=0;


int Game() {
	int i=0;
	char ans;
	int your_pos_y = 1, your_pos_x = 1;
	int o_y = 5, o_x = 6;
    FILE* pt1 = fopen("score.txt", "a+");
	
	while (1)
	{	
		system("cls");
		printf("level%d\n",level);
		for (int i = 0; i < COL; i++)
		{
			for (int j = 0; j < ROW-1; j++)
			{
				if(your_pos_y!=1 || your_pos_x!=1){
					arr[1][1]=' ';	
				}
				
			 	if (i == your_pos_y && j == your_pos_x)
				{
					printf("@");
				}
				else
				{
					printf("%c", arr[i][j]);
				}
			}
			printf("\n");
		}
		if (arr[o_y][o_x]=='%')
		{
			
			while(step >= 10){
				int j=step/10;
				step=step%10;
				ans=(char) (j+'0');
			fputc(ans,pt1);
			}
			ans=(char) (step+'0');
			fputc(ans,pt1);
			fputc(' ',pt1);
			
			printf("YOU WIN !!!\n");
			break;
		}
		
		printf("%d",step);
		
		switch (_getch())
		{
		case 72:
			
			if(arr[your_pos_y - 1][your_pos_x] == '%' && arr[your_pos_y - 2][your_pos_x] != '#' )
			{
				arr[your_pos_y ][your_pos_x]=' ';
				arr[your_pos_y - 2][your_pos_x]=arr[your_pos_y - 1][your_pos_x]; 
				your_pos_y--;
				step++;
			}
			else if(arr[your_pos_y - 1][your_pos_x] == '%' && arr[your_pos_y - 2][your_pos_x] == '#'){
				
			}
			else if (arr[your_pos_y - 1][your_pos_x] != '#')
			{
				arr[your_pos_y ][your_pos_x]=' ';
				your_pos_y--;
				step++;
			}
			break;
		case 80:
			
			if(arr[your_pos_y + 1][your_pos_x] == '%' && arr[your_pos_y + 2][your_pos_x] != '#')
			{
				arr[your_pos_y ][your_pos_x]=' ';
				arr[your_pos_y + 2][your_pos_x]=arr[your_pos_y + 1][your_pos_x];
				your_pos_y++;
				step++;
			}
			else if(arr[your_pos_y + 1][your_pos_x] == '%' && arr[your_pos_y + 2][your_pos_x] == '#'){
				
			}
			else if (arr[your_pos_y + 1][your_pos_x] != '#')
			{
				arr[your_pos_y ][your_pos_x]=' ';
				your_pos_y++;
				step++;
			}
			break;
		case 75:
			
			if(arr[your_pos_y][your_pos_x - 1] == '%' && arr[your_pos_y][your_pos_x - 2] != '#')
			{
				arr[your_pos_y ][your_pos_x]=' ';
				arr[your_pos_y][your_pos_x - 2]=arr[your_pos_y][your_pos_x - 1];
				your_pos_x--;
				step++;
			}
			else if(arr[your_pos_y][your_pos_x - 1] == '%' && arr[your_pos_y][your_pos_x - 2] == '#'){
				
			}
			else if (arr[your_pos_y][your_pos_x - 1] != '#')
			{
				arr[your_pos_y ][your_pos_x]=' ';
				your_pos_x--;
				step++;
			}
			break;
		case 77:
			
			if(arr[your_pos_y][your_pos_x + 1] == '%' && arr[your_pos_y][your_pos_x + 2] != '#')
			{
				arr[your_pos_y ][your_pos_x]=' ';
				arr[your_pos_y][your_pos_x + 2]=arr[your_pos_y][your_pos_x + 1];
				your_pos_x++;
				step++;
			}
			else if(arr[your_pos_y][your_pos_x + 1] == '%' && arr[your_pos_y][your_pos_x + 2] == '#'){
				
			}
			else if (arr[your_pos_y][your_pos_x + 1] != '#')
			{
				arr[your_pos_y ][your_pos_x]=' ';
				your_pos_x++;
				step++;
			}
			break;
		default:
			break;	
		}
	}
	printf("next level? Y or N  ");
	scanf("%c",&ans);
	if(ans=='Y'){
		level++;
		step=0;
		FILE* pt = fopen("Level 1.txt", "r");
	
		while(fgets(arr[i],10,pt)!=NULL){
			arr[i][8]='\0';
			i++;
			}
		printf("level%d\n",level);
		for (int i = 0; i < COL; i++)
		{
			for (int j = 0; j < ROW; j++)
			{
				printf("%c", arr[i][j]);	
			}
			printf("\n");
		}
		
		Game();
		fclose(pt);
	}else{
		return 0;
	}
	
}
