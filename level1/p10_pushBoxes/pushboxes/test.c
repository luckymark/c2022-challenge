#include"pushboxes.h"

char arr[COL][ROW]={'0'};
int level=0;

int main() {
	
	int i=0;
	FILE* pt = fopen("Level 0.txt", "r");
	
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

	return 0;
} 
