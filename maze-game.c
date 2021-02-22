#include <stdio.h>
int main()
{
	int row, column, k, m, a, b;
	static int a1=0, b1=0, a2=0, b2=0, bonus=0;
	char position;
	char x, y, command,slash;
	char maze[50][50];
	int flag = -1;
	
	scanf("%d %d",&row,&column);
	

	for(k=0; k < row; k++)//base maze
	{//first for starts
		for(m = 0; m < column; m++)
		{
			if(k == 0 || k == (row-1))
				maze[k][m] = '*';
				
			else
			{
				if(m==0 || m==(column-1))
					maze[k][m] = '*';
			
				else
					maze[k][m] = ' ';
			
				
			}
			
		}//second for ends
			
	}//first for ends
	
	while(1)//filling the maze
	{
		scanf(" %c", &position);
		
		switch (position)
		{
			case 's':
				scanf("%d %d", &a1, &b1);
				maze[a1][b1]='O';
				break;
				
			case 'f':
				scanf("%d %d", &a2, &b2);
				maze[a2][b2]=' ';
				break;
				
			case 'b':
				scanf("%d %d", &a, &b);
				maze[a][b]='*';
				break;
				
			case '$':
				scanf("%d %d", &a, &b);
				maze[a][b]='$';
				break;
				
			case 'X':
				scanf("%d %d", &a, &b);
				maze[a][b]='X';
				break;
				
			case 'e':
				scanf(" %c %c", &x, &y);
				break;
		}
		
		if(position == 'e' && x == 'n' && y == 'd') 
			break;
	}
	
	slash=getchar();
	
	for(k = 0; k < row; k++)//printing the maze
	{
		for(m = 0; m < column; m++)
			printf("%c", maze[k][m]);
				
		printf("\n");
	}
	
	printf("\n");
	
	while(flag != 0 && (command = getchar()) != EOF)//moving the player
	{
		switch (command) //switch starts
		{
			case 'd'://DOWNMOVE----------------------
				if(maze[a1+1][b1] == ' ')
				{
					
					maze[a1+1][b1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					a1++;
					
					if(a1 == a2 && b1 == b2)
					{
						printf("CONGRATS! YOU GOT %d BONUS:)\n",bonus);
						
						for(k = 0; k < row; k++)//printing the maze
						{
							for(m = 0; m < column; m++)
								printf("%c", maze[k][m]);
									
							printf("\n");
						}
						printf("\n");
						flag++;
						break;
					}
					
				}
				else if(maze[a1+1][b1] == '*')
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
				
				else if(maze[a1+1][b1] == '$')
				{
					printf("YOU GOT 1 $.\n");
					maze[a1+1][b1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					a1++;
					bonus++;
				}
					
				else if(maze[a1+1][b1] == 'X')
				{
				
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					
					for(k = 0; k < row; k++)//printing the maze
					{
						for(m = 0; m < column; m++)
							printf("%c", maze[k][m]);
								
						printf("\n");
					}
				
					printf("\n");
					flag++;
					break;
				}
				
				for(k = 0; k < row; k++)//printing the maze
				{
					for(m = 0; m < column; m++)
						printf("%c", maze[k][m]);
							
					printf("\n");
				}
				
				printf("\n");
				
				break;
			
			case 'r'://RIGHTMOVE----------------------
				
				if(maze[a1][b1+1] == ' ')
				{
				
					maze[a1][b1+1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					b1++;
					
					if(a1 == a2 && b1 == b2)
					{
						printf("CONGRATS! YOU GOT %d BONUS:)\n",bonus);
						
						for(k = 0; k < row; k++)//printing the maze
						{
							for(m = 0; m < column; m++)
								printf("%c", maze[k][m]);
									
							printf("\n");
						}
						
						printf("\n");
						flag++;
						
						break;
					}
					
				}
				
				else if(maze[a1][b1+1] == '*')
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
					
				else if(maze[a1][b1+1] == '$')
				{
					printf("YOU GOT 1 $.\n");
					maze[a1][b1+1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					b1++;
					bonus++;
				}
				
				else if(maze[a1][b1+1] == 'X')
				{
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					
					for(k = 0; k < row; k++)//printing the maze
					{
						for(m = 0; m < column; m++)
							printf("%c", maze[k][m]);
								
						printf("\n");
					}
					printf("\n");
					flag++;
					break;
				}
				
				for(k = 0; k < row; k++)//printing the maze
				{
					for(m = 0; m < column; m++)
						printf("%c", maze[k][m]);
							
					printf("\n");
				}
				
				printf("\n");
				break;
				
			case 'l'://LEFTMOVE----------------------
				
				if(maze[a1][b1-1] == ' ')
				{
				
					maze[a1][b1-1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					b1--;
					
					if(a1 == a2 && b1 == b2)
					{
						printf("CONGRATS! YOU GOT %d BONUS:)\n",bonus);
						
						for(k = 0; k < row; k++)//printing the maze
						{
							for(m = 0; m < column; m++)
								printf("%c", maze[k][m]);
									
							printf("\n");
						}
						
						printf("\n");
						flag++;
						break;
					}
				
				}
				
				else if(maze[a1][b1-1] == '*')
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
					
				else if(maze[a1][b1-1] == '$')
				{
					printf("YOU GOT 1 $.\n");
					maze[a1][b1-1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					b1--;
					bonus++;
				}
				
				else if(maze[a1][b1-1] == 'X')
				{
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					
					for(k = 0; k < row; k++)//printing the maze
					{
						for(m = 0; m < column; m++)
							printf("%c", maze[k][m]);
								
						printf("\n");
					}
					
					printf("\n");
					flag++;
					break;
				}
				
				
				for(k = 0; k < row; k++)//printing the maze
				{
					for(m = 0; m < column; m++)
						printf("%c", maze[k][m]);
							
					printf("\n");
				}
				printf("\n");
				break;
			
			case 'u'://UPMOVE------------------------
				
				if(maze[a1-1][b1] == ' ')
				{
					
					maze[a1-1][b1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					a1--;
					
					if(a1 == a2 && b1 == b2)
					{
						printf("CONGRATS! YOU GOT %d BONUS:)\n",bonus);
						
						for(k = 0; k < row; k++)//printing the maze
						{
							for(m = 0; m < column; m++)
								printf("%c", maze[k][m]);
									
							printf("\n");
						}
						printf("\n");
						flag++;
						break;
					}
					
				}
				else if(maze[a1-1][b1] == '*')
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
				
				else if(maze[a1-1][b1] == '$')
				{
					printf("YOU GOT 1 $.\n");
					maze[a1-1][b1] = maze[a1][b1];
					maze[a1][b1] = ' ';
					a1--;
					bonus++;
				}
					
				else if(maze[a1-1][b1] == 'X')
				{
				
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					
					for(k = 0; k < row; k++)//printing the maze
					{
						for(m = 0; m < column; m++)
							printf("%c", maze[k][m]);
								
						printf("\n");
					}
					
					printf("\n");
					flag++;
					break;
				}
				
				for(k = 0; k < row; k++)//printing the maze
				{
					for(m = 0; m < column; m++)
						printf("%c", maze[k][m]);
							
					printf("\n");
				}
				printf("\n");
				break;
				
				
			case 'q':
				printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
				
				for(k = 0; k < row; k++)//printing the maze
				{
					for(m = 0; m < column; m++)
						printf("%c", maze[k][m]);
							
					printf("\n");
				}
				
				printf("\n");
				flag++;
				break;
			
		}//switch ends
		
	}//while command ends

	if(command == EOF)
	{
		printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
				
				for(k = 0; k < row; k++)//printing the maze

				{
					for(m = 0; m < column; m++)
						printf("%c", maze[k][m]);
							
					printf("\n");
				}
				
	}
	
	return 0;
	

}
