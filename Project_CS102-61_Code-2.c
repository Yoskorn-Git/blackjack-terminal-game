#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void screenBJ(); //print screen start
float wait(float sec); //timer
int select(); //to select between start or how to play
void screenSTARTname(); 
void screenSTARTloading();
int screenSTARTplayerLOAD(int Num);
void screen(int player,int num1,int num2,int score1,int score2,int a,int b,int c);
char randomSTART();
char convert(char card);
int HIT(int round,int player);
void CAL(); // to calculate point to win
void CalculateSUM();
void reset(); //reset for new round
int perfectDraw(int round,int player);
void screenNOcard();
void screenMAXcard();
void screenMAXscore();
void screenWINNER();

char deck[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
char cardA[13],cardB[13];
int valueA[13],valueB[13];
char Name1[30] = {"JENNIE"},Name2[30]= {"ROSE"};
int point=21,roundg=0;
int score1=0,score2=0;
int sumA=0,sumB=0;
int exA1=0,exB1=0,exC1=0;
int exA2=0,exB2=0,exC2=0;
int extraA=0,extraB=0,extraC=0;
int	countcardA=0;
int	countcardB=0;

main(){
	int choice,i,player,a1,a2,b1,b2,c1=2,c2=2;
	
	screenBJ();
	choice=select();
	
	switch(choice){
		case 1 : {
			screenSTARTname();
			screenSTARTloading();
			
			while(score1 < 5 && score2 < 5){
				
			reset();
			randomSTART();
			screenSTARTplayerLOAD(1);
						i = 0;
						player = 1;
						a1 = 2; //cardA up
						a2 = 2; //cardA down
						b1 = 2; //cardB up					
						b2 = 2; //cardB down
						c1 = 2; 
						c2 = 2;
								
				while(i<2){
					screen(player,c1,c2,score1,score2,extraA,extraB,extraC);						
					scanf(" %c",&choice);
					
					while(choice!='H' && choice!='S' && choice!='A' && choice!='B' && choice!='C' &&
						  choice!='h' && choice!='s' && choice!='a' && choice!='b' && choice!='c'){
						system("cls");
						printf("Unknow choice.\nTry again.");
						wait(1);
						screen(player,c1,c2,score1,score2,extraA,extraB,extraC);
						scanf(" %c",&choice);
					}	
					if(choice > 90)
						choice = choice	- 32;
						switch(choice){
							case 'H' : {
										i=0;
										
										if(player%2!=0){
											if(countcardA<4){
										
												a1 = c2;
												a2++;							
												HIT(a2-2,1);
												countcardA++;
												extraA = exA1;
												extraB = exB1;
												extraC = exC1;
											
												c1 = b2;
												c2 = a2;
											}	
											else
												screenMAXcard();
										}																								
										if(player%2==0){
											if(countcardB<4){
												b1 = c2;
												b2++;							
												HIT(b2-2,2);
												countcardB++;
												extraA = exA2;
												extraB = exB2;
												extraC = exC2;
												
												c1 = a2;
												c2 = b2;
											
											}	
											else
												screenMAXcard();
										}									
								break;
							}
							case 'S' : {player++;
										i++;
										
										if(i==2)
										continue;
										
										if(player%2!=0){
										screenSTARTplayerLOAD(1);	
										c1 = b2;
										c2 = a2;
										extraA = exA1;
										extraB = exB1;
										extraC = exC1;	
									}
										else if(player%2==0){
										screenSTARTplayerLOAD(2);
										c1 = a2;
										c2 = b2;
										extraA = exA2;
										extraB = exB2;
										extraC = exC2;											
									}
								break;
							}
							case 'A' : {						
								i=0;
								int n;
								char tmp[13];
								char tmpc[13];
								int tmpa;
								
									if(player%2!=0){
										if(player%2!=0){
											if(exA1>0){														
												for(n=0;n<13;n++){
													tmpc[n] = cardA[n];
													cardA[n] = cardB[n];
												}
												for(n=0;n<13;n++){
													cardB[n] = tmpc[n];
														}
															
														c1 = a2;
														c2 = b2;
														tmpa = a2 ;
														a2 = b2;
														b2 = tmpa;
														countcardA = countcardB;																											
													
												exA1 = exA1 - 1;
												extraA = exA1;
											}
											else
											screenNOcard();
										}
									}
											
									else if(player%2==0){	
											if(exA2>0){														
												for(n=0;n<13;n++){
													tmpc[n] = cardA[n];
													cardA[n] = cardB[n];
												}
												for(n=0;n<13;n++){
													cardB[n] = tmpc[n];
														}														

														c1 = b2;
														c2 = a2;
														tmpa = b2 ;
														b2 = a2;
														a2 = tmpa;	
														countcardB = countcardA;
													
												exA2 = exA2 - 1;
												extraA = exA2;
											}
											else
											screenNOcard();
										}
									
															
									
								break;
							}
							case 'B' : {
										i=0;
										
										CalculateSUM();							
										
										if(player%2!=0){
											
											if(exB1 > 0 && sumA < 21){	
													
												a1 = c2;
												a2++;							
												perfectDraw(a2-2,1);
												countcardA++;
										
												c1 = b2;
												c2 = a2;
												exB1 = exB1 - 1;
												extraB = exB1;
											}
											else
											screenNOcard();
										
									}
										else if(player%2==0){
											if(exB2 > 0 && sumB <21){	
												
												b1 = c2;
												b2++;							
												perfectDraw(b2-2,2);
												countcardB++;
										
												c1 = a2;
												c2 = b2;
												exB2 = exB2 - 1;
												extraB = exB2;	
											}
											else
											screenNOcard();
										
								   }
							
								break;
							}
							case 'C' : {
								
										if(player%2!=0){
											
											if(exC1>0){		
											point = 17;
											exC1--;
											extraC = exC1;
											}
											else
											screenNOcard();
											
									}
										else if(player%2==0){
											
											if(exC2>0){		
											point = 17;
											exC2--;
											extraC = exC2;
											}
											else
											screenNOcard();
											
								   }
								
								break;
							}
						}
					
				}
				CAL();
			}
			
 			screenWINNER();
			
			break;
		}
		case 2 : {
			system("cls");
			
			char key;
			
			while (key != '\r' && key != '\n') {
			printf("Make sure your card has the closest 21 value and do not exceed.\n");
			printf("\tBy A have value 1\n");
			printf("\tLetter (X,K,Q) have value 10\n");
			printf("\tNumber have value by itself\n\n");
			
			printf("IF YOU WANT TO HIT CARD PRESS 'H' AND ENTER\n");
			printf("IF YOU WANT TO STAND CARD PRESS 'S' AND ENTER\n\n");
			printf(" EXTRA CRAD\n");
			printf(" It is a wizard for you to win.\n");
			printf(" it will be random when you hit the card >> 10 percent CHANCE TO GET<<\n");	
			printf("\tA = switch card : to switch your own card to antagonist and antagonist'card to you\n");
			printf("\tB = Perfect : to HIT card with the number closest to your number nearest to 21\n");
			printf("\tC = Point to 17 : to replace 21 point to win with 17 to win\n");
			printf("\t\tIF YOU HAVE IT AND WANT TO USE JUST TPYE IT (A,B or C)\n\n\n");
			printf("\t\tENJOY !!! press ENTER TO PLAY!!!!");
			scanf("%c",&key);
		}
			
			screenSTARTname();
			screenSTARTloading();
			
			while(score1 < 5 && score2 < 5){
				
			reset();
			randomSTART();
			screenSTARTplayerLOAD(1);
						i = 0;
						player = 1;
						a1 = 2; //cardA up
						a2 = 2; //cardA down
						b1 = 2; //cardB up					
						b2 = 2; //cardB down
						c1 = 2; 
						c2 = 2;
								
				while(i<2){
					screen(player,c1,c2,score1,score2,extraA,extraB,extraC);						
					scanf(" %c",&choice);
					
					while(choice!='H' && choice!='S' && choice!='A' && choice!='B' && choice!='C' &&
						  choice!='h' && choice!='s' && choice!='a' && choice!='b' && choice!='c'){
						system("cls");
						printf("Unknow choice.\nTry again.");
						wait(1);
						screen(player,c1,c2,score1,score2,extraA,extraB,extraC);
						scanf(" %c",&choice);
					}	
					if(choice > 90)
						choice = choice	- 32;
						switch(choice){
							case 'H' : {
										i=0;
										
										if(player%2!=0){
											if(countcardA<4){
										
												a1 = c2;
												a2++;							
												HIT(a2-2,1);
												countcardA++;
												extraA = exA1;
												extraB = exB1;
												extraC = exC1;
											
												c1 = b2;
												c2 = a2;
											}	
											else
												screenMAXcard();
										}																								
										if(player%2==0){
											if(countcardB<4){
												b1 = c2;
												b2++;							
												HIT(b2-2,2);
												countcardB++;
												extraA = exA2;
												extraB = exB2;
												extraC = exC2;
												
												c1 = a2;
												c2 = b2;
											
											}	
											else
												screenMAXcard();
										}									
								break;
							}
							case 'S' : {player++;
										i++;
										
										if(i==2)
										continue;
										
										if(player%2!=0){
										screenSTARTplayerLOAD(1);	
										c1 = b2;
										c2 = a2;
										extraA = exA1;
										extraB = exB1;
										extraC = exC1;	
									}
										else if(player%2==0){
										screenSTARTplayerLOAD(2);
										c1 = a2;
										c2 = b2;
										extraA = exA2;
										extraB = exB2;
										extraC = exC2;											
									}
								break;
							}
							case 'A' : {						
								i=0;
								int n;
								char tmp[13];
								char tmpc[13];
								
									if(player%2!=0){
										if(player%2!=0){
											if(exA1>0){														
												for(n=0;n<13;n++){
													tmpc[n] = cardA[n];
													cardA[n] = cardB[n];
												}
												for(n=0;n<13;n++){
													cardB[n] = tmpc[n];
														}
													if(player%2!=0){	
														c1 = a2;
														c2 = b2;	
													}
													else if(player%2==0){
														c1 = b2;
														c2 = a2;	
													}
												exA1 = exA1 - 1;
												extraA = exA1;
											}
											else
											screenNOcard();
										}
									}
											
									else if(player%2==0){	
											if(exA2>0){														
												for(n=0;n<13;n++){
													tmpc[n] = cardA[n];
													cardA[n] = cardB[n];
												}
												for(n=0;n<13;n++){
													cardB[n] = tmpc[n];
														}
														
													if(player%2!=0){
														
														c1 = a2;
														c2 = b2;	
													}
													else if(player%2==0){
														c1 = b2;
														c2 = a2;	
													}
												exA2 = exA2 - 1;
												extraA = exA2;
											}
											else
											screenNOcard();
										}
									
															
									
								break;
							}
							case 'B' : {
										i=0;
										
										CalculateSUM();							
										
										if(player%2!=0){
											
											if(exB1 > 0 && sumA < 21){	
													
												a1 = c2;
												a2++;							
												perfectDraw(a2-2,1);
												countcardA++;
										
												c1 = b2;
												c2 = a2;
												exB1 = exB1 - 1;
												extraB = exB1;
											}
											else
											screenNOcard();
										
									}
										else if(player%2==0){
											if(exB2 > 0 && sumB <21){	
												
												b1 = c2;
												b2++;							
												perfectDraw(b2-2,2);
												countcardB++;
										
												c1 = a2;
												c2 = b2;
												exB2 = exB2 - 1;
												extraB = exB2;	
											}
											else
											screenNOcard();
										
								   }
							
								break;
							}
							case 'C' : {
								
										if(player%2!=0){
											
											if(exC1>0){		
											point = 17;
											exC1--;
											extraC = exC1;
											}
											else
											screenNOcard();
											
									}
										else if(player%2==0){
											
											if(exC2>0){		
											point = 17;
											exC2--;
											extraC = exC2;
											}
											else
											screenNOcard();											
								   }								
								break;
							}
						}		
				}
				CAL();
			}	
 			screenWINNER();	
			break;
		}							
	break;
	}	
}

void screenBJ(){
	int i,t,c;
	
	while(c<35){
		system("cls");
		printf("=====================================================================================\n");
	
		for(i=0;i<5;i++)
			printf("\n");


		for(t=0;t<c;t++)
			printf(" ");
		printf("B L A C K J A C K");
	
	
		for(i=0;i<18;i++)
			printf("\n");
	 
		printf("=======================================================================================\n");
		wait(0.05);
		c++;
	}
		
		system("cls");
		printf("=====================================================================================\n");
	
		for(i=0;i<1;i++)
			printf("\n");
		printf("   W\n A S D to move\n");
		printf(" ENTER to select\n");
		for(i=0;i<1;i++)
			printf("\n");

		for(t=0;t<c;t++)
			printf(" ");
		printf(" B L A C K J A C K");
		
		for(i=0;i<7;i++)
			printf("\n");
	
		printf("                                      >>> START <<<\n");
		printf("                                       HOW TO PLAY");
		for(i=0;i<10;i++)
			printf("\n");
	 
		printf("=======================================================================================\n");
}

int select(){
	int choice = 1,i,t,c;
	char key;

	while (key != '\r' && key != '\n')
	{
		key = getch();
		if (key == 'w')
		{
			system("cls");
			
				printf("=====================================================================================\n");
	
				for(i=0;i<1;i++)
					printf("\n");
				printf("   W\n A S D to move\n");
				printf(" ENTER to select\n");
				for(i=0;i<1;i++)
					printf("\n");

				for(t=0;t<35;t++)
					printf(" ");
				printf(" B L A C K J A C K");
				
				for(i=0;i<7;i++)
					printf("\n");
			
				printf("                                      >>> START <<<\n");
				printf("                                       HOW TO PLAY");
				for(i=0;i<10;i++)
					printf("\n");
			 
				printf("=======================================================================================\n");
				
			choice = 1;
			}
		
		if (key == 's')
		{
			system("cls");
			
				printf("=====================================================================================\n");
	
				for(i=0;i<1;i++)
					printf("\n");
				printf("   W\n A S D to move\n");
				printf(" ENTER to select\n");
				for(i=0;i<1;i++)
					printf("\n");

				for(t=0;t<35;t++)
					printf(" ");
				printf(" B L A C K J A C K");
				
				for(i=0;i<7;i++)
					printf("\n");
			
				printf("                                          START    \n");
				printf("                                   >>> HOW TO PLAY <<<");
				for(i=0;i<10;i++)
					printf("\n");
			 
				printf("=======================================================================================\n");
				
			choice = 2;
			}
		}
		return choice;
	}
	
float wait(float sec){
		clock_t endwait;
		endwait = clock() + sec * CLK_TCK;

		while (clock() < endwait) {}
	}
	
void screenSTARTname(){
	int len1,len2;
	
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf(" Only less than 6 characters.");
	printf("\n");
	printf("\n");
	printf(" Enter Name Player 1 : ");
	scanf("%s",Name1);
	len1 = strlen(Name1);
	
	while(len1 > 6){
		system("cls");
		printf("Name must be no longer than 6 letter");
		wait(1.5);
		system("cls");
		printf("___________________________________________________________________________________________\n");
		printf(" Only less than 6 characters.");
		printf("\n");
		printf("\n");
		printf(" Enter Name Player 1 : ");
		scanf("%s",Name1);
		len1 = strlen(Name1);
	}
	
	printf(" Enter Name Player 2 : ");
	scanf("%s",Name2);
	len2 = strlen(Name2);
	
	while(len2 > 6){
		system("cls");
		printf("Name must be no longer than 6 letter");
		wait(1.5);
		system("cls");
		printf("___________________________________________________________________________________________\n");
		printf(" Recommended for no more than 4 - 6 characters.");
		printf("\n");
		printf("\n");
		printf(" Enter Name Player 1 : %s\n",Name1);
		printf(" Enter Name Player 2 : ");
		scanf("%s",Name2);	
		len2 = strlen(Name2);
	}
}	
	
void screenSTARTloading(){
	int k;
	while(k<7){
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t   LOADING.\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(0.1);
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t   LOADING..\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(0.1);
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t   LOADING...\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(0.1);
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t   LOADING....\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(0.1);

	k++;
	}
}		
	
int screenSTARTplayerLOAD(int Num){
	
	if(Num==1){
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t   %s's\n",Name1);	
	printf("\n");
	printf("\t\t\t\t\t    TURN");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(1.5);
	system("cls");
	}
	
	else{
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t   %s's\n",Name2);	
	printf("\n");
	printf("\t\t\t\t\t    TURN");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(1.5);
	system("cls");
	}
	
}	

void screen(int player,int num1,int num2,int score1,int score2,int a,int b,int c){
	
	int i,j,k,m;
	int cardrival,card[10];
	
	if(player%2!=0){
		cardrival = cardB[0];
		for(i=0;i<10;i++)
		card[i] = cardA[i];
	}
	
	else if(player%2==0){
		cardrival = cardA[0];
		for(i=0;i<10;i++)
		card[i] = cardB[i];
	}
	
	system("cls");
	printf("___________________________________________________________________________________________\n");
	for(k=0;k<40;k++)
	printf(" ");
	for(j=0;j<num1;j++){
	for(i=0;i<5;i++)
	printf("_");
	for(i=0;i<4;i++)
	printf(" ");
}
	printf("\n");
	
	for(k=0;k<39;k++)
	printf(" ");
	
	for(j=0;j<num1;j++)
	printf("|     |  ");
	printf("\n");
	
	printf("                      OPPONENT'CARD");
	
	for(k=0;k<4;k++)
	printf(" ");
	
	for(j=0;j<1;j++)
	printf("|  %c  |  ",cardrival);
	
	for(j=0;j<num1-1;j++)
	printf("|  ?  |  ",cardrival);
	printf("\n");
	
	printf("             ");
	
	for(k=0;k<26;k++)
	printf(" ");
	
	for(j=0;j<num1;j++)
	printf("|     |  ");
	printf("\n");
	
	for(k=0;k<39;k++)
	printf(" ");
	
	for(j=0;j<num1;j++)
	printf("l_____l  ");

	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                                  POINT : %d\n",point);
	printf("			                  	  ROUND : %d\n",roundg);
	printf("\n");
	

	for(k=0;k<40;k++)
	printf(" ");
	for(j=0;j<num2;j++){
	for(i=0;i<5;i++)
	printf("_");
	for(i=0;i<4;i++)
	printf(" ");
}
	printf("\n");
	
	for(k=0;k<39;k++)
	printf(" ");
	
	
	for(j=0;j<num2;j++)
	printf("|     |  ");
	printf("\n");
	
	printf("                      YOU'RE CARD");
	
	for(k=0;k<6;k++)
	printf(" ");
	
	for(m=0;m<num2;m++)
	printf("|  %c  |  ",card[m]);
	printf("\n");
	
	printf("             ");
	
	for(k=0;k<26;k++)
	printf(" ");
	
	for(j=0;j<num2;j++)
	printf("|     |  ");
	printf("\n");
	
	for(k=0;k<39;k++)
	printf(" ");
	
	for(j=0;j<num2;j++)
	printf("l_____l  ");
	
	printf("\n");
	printf("\n");
	printf("                                     %s'score                    %s'score \n",Name1,Name2);
	printf("                                        %d                                %d \n",score1,score2);
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("  CHOOSE                                          EXTRA CARD                   HAVE\n");
	printf("            H > HIT            OR                 A > switch card               %d\n",a);
	printf("            S > STAND                             B > perfect draw              %d\n",b);
	printf("                                                  C > change POINT to 17        %d\n",c);
	printf("              ENTER CHOICE : ");
}
	
char randomSTART(){
	int i,j;
	for(j=0;j<13;j++){
	}
  	srand(time(NULL));
 
   		cardA[0] = deck[rand()%13];
   		cardA[1] = deck[rand()%13];	
   		
   		while(cardA[0] == cardA[1] )
   			cardA[1] = deck[rand()%13];
   		
   		for(i=0;i<13;i++)
		    {
   			if(cardA[0] == deck[i])
   				deck[i] = -99;
   			if(cardA[1] == deck[i])
   				deck[i] = -99;
   				}
   				
   			cardB[0] = deck[rand()%13];
   			cardB[1] = deck[rand()%13];			
   		
   		while(cardB[0] == -99 || cardB[1] == -99)
		   {
		   	cardB[0] = deck[rand()%13];
   			cardB[1] = deck[rand()%13];	
				   }		
   	
   		while(cardB[0] == cardB[1])
   			cardB[1] = deck[rand()%13];
   		
   		for(i=0;i<13;i++)
		    {
   			if(cardB[0] == deck[i])
   				deck[i] = -99;
   			if(cardB[1] == deck[i])
   				deck[i] = -99;
   				}
}	
	
char convert(char card){
	
	if(card==' ')
	card = 0;
	
	else{
		
	switch(card){
	 case 'A': card = 1;break;
	 case 'X': card = 10;break;
	 case 'K': card = 10;break;
	 case 'Q': card = 10;break;
	 case 'J': card = 10;break;
	 case '2': card = 2;break;
	 case '3': card = 3;break;
	 case '4': card = 4;break;
	 case '5': card = 5;break;
	 case '6': card = 6;break;
	 case '7': card = 7;break;
	 case '8': card = 8;break;
	 case '9': card = 9;break;
	}
  }
	 return card;
}	

int HIT(int round,int player){
	int i;
	int extracard;
	srand(time(NULL));
	
	
	
	if(player == 1){
	cardA[round+1] = deck[rand()%13];
	
	while(cardA[round+1] == -99)
		   	cardA[round+1] = deck[rand()%13];
	
	for(i=0;i<13;i++)  
   		if(cardA[round+1] == deck[i])
   			deck[i] = -99;
   		}
   		
   		
   		
   		
   	else if(player == 2){
   		cardB[round+1] = deck[rand()%13];
	
	while(cardB[round+1] == -99)
		   	cardB[round+1] = deck[rand()%13];
	
	for(i=0;i<13;i++)  
   		if(cardB[round+1] == deck[i])
   			deck[i] = -99;
   		}
   			
   			
int extra[10] = {1,2,3,0,0,0,0,0,0,0};
   			
   	extracard = extra[rand()%10]; //random extra card

   	
   		if(player == 1){

   			if(extracard == 1)
				exA1++;
   			else if(extracard == 2)
   				exB1++;
   			else if(extracard == 3)
   				exC1++;
		   }
		
		if(player == 2){

   			if(extracard == 1)
   				exA2++;
   			else if(extracard == 2)
   				exB2++;
   			else if(extracard == 3)
   				exC2++;
		   }
   	
	   		
	   }
	   
void CalculateSUM(){
	
	int i,j;
	
	for(i=0;i<13;i++){
		valueA[i] = convert(cardA[i]);
	//	printf("A %d %d\n",valueA[i],i);
		valueB[i] = convert(cardB[i]);
	//	printf("B %d %d\n",valueB[i],i);
	}
		
	for(j=0;j<13;j++){
		sumA = sumA + valueA[j];
		sumB = sumB + valueB[j];
	}
	
}	   

void CAL(){
	int i,j,k;
	int result;
	system("cls");
	
	sumA=0;
	sumB=0;
	
	CalculateSUM();
	
	if(point-sumA<0 && point-sumB<0)
		result = 0;
	else if(point-sumA<0)
		result = 2;
	else if(point-sumB<0)
		result = 1;
	else if((point-sumA)<(point-sumB))
		result = 1;
	else if((point-sumB)<(point-sumA))
		result = 2;
	
	
//	printf("%d\n",sumA);
//	printf("%d\n",sumB);	
	 
	if(result==1){
		printf("___________________________________________________________________________________________\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t\t\t\t%s WIN!!!!\n",Name1);
		printf("\n");
		printf("\n");
		printf("\t\t\t\t     %s\t   %s\n",Name1,Name2);	
		printf("\t\t\t\t       %d\t     %d\n",sumA,sumB);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("___________________________________________________________________________________________\n");
		wait(3);
		score1++;
	}
	
	else if(result==2){
		printf("___________________________________________________________________________________________\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t\t\t\t%s WIN!!!!\n",Name2);
		printf("\n");
		printf("\n");
		printf("\t\t\t\t     %s\t   %s\n",Name1,Name2);	
		printf("\t\t\t\t       %d\t     %d\n",sumA,sumB);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("___________________________________________________________________________________________\n");
		wait(3);
		score2++;
	}
	
	else if(result==0){
		printf("___________________________________________________________________________________________\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t\t\t\tDRAW!!!!\n",Name2);
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("___________________________________________________________________________________________\n");
		wait(3);
	}
}
	
void reset(){

	int i,j;

	deck[0] = 'A';
	deck[1] = '2';
	deck[2] = '3';
	deck[3] = '4';
	deck[4] = '5';
	deck[5] = '6';
	deck[6] = '7';
	deck[7] = '8';
	deck[8] = '9';
	deck[9] = 'X';
	deck[10] = 'J';
	deck[11] = 'Q';
	deck[12] = 'K';
	
	for(i=0;i<13;i++){
		
		cardA[i] = ' ';
		cardB[i] = ' ';
		valueA[i] = 0;
		valueB[i] = 0;
	}
	
	countcardA=0;
	countcardB=0;
	point=21;
	roundg++;
	
}	
	
int perfectDraw(int round,int player){
	
	int i,sumA=0,sumB=0,j;
	int min;
	int dif,p,q,e;
	int deckvalue[13];
	int result[13];
	
	srand(time(NULL));
	
	for(i=0;i<13;i++){
		valueA[i] = convert(cardA[i]);
		valueB[i] = convert(cardB[i]);
	}
		
	for(j=0;j<13;j++){
		sumA = sumA + valueA[j];
		sumB = sumB + valueB[j];
	}
	
	if(player == 1){
		
		dif = point - sumA;
	//	printf("%d ",dif);
		
		for(p=0;p<13;p++){
			if(deck[p] != -99)
			deckvalue[p] = convert(deck[p]);
			else
			deckvalue[p] = -99;
	//		printf("%d/",deckvalue[p]);
		}
			
		for(q=0;q<13;q++){
			result[q] = dif - deckvalue[q];
	//		printf(" =%d=",result[q]);
		}
		
		
				min = 0;
				
		for(e=0;e<12;e++){
			if(result[min] > result[e] && result[e] >=0)
				min = e;			
			printf(" %d ",result[min]);	
		}
		
				
		cardA[round+1] = deck[rand()%13];
	
			while(cardA[round+1] == -99 || convert(cardA[round+1]) != deckvalue[min])
		   		cardA[round+1] = deck[rand()%13];
	
			for(i=0;i<13;i++)  
   				if(cardA[round+1] == deck[i])
   					deck[i] = -99;
   		
 	}
	
	
	
	
		if(player == 2){
		
		dif = point - sumB;
	//	printf("%d ",dif);
		
		for(p=0;p<13;p++){
			if(deck[p] != -99)
			deckvalue[p] = convert(deck[p]);
			else
			deckvalue[p] = -99;
	//		printf("%d/",deckvalue[p]);
		}
			
		for(q=0;q<13;q++){
			result[q] = dif - deckvalue[q];
	//		printf(" =%d=",result[q]);
		}
		
		
				min = 0;
				
		for(e=0;e<12;e++){
			if(result[min] > result[e] && result[e] >=0)
				min = e;			
	//		printf(" %d ",result[min]);	
		}
		
				
		cardB[round+1] = deck[rand()%13];
	
			while(cardB[round+1] == -99 || convert(cardB[round+1]) != deckvalue[min])
		   		cardB[round+1] = deck[rand()%13];
	
			for(i=0;i<13;i++)  
   				if(cardB[round+1] == deck[i])
   					deck[i] = -99;
   		
	}
}	
	
void screenNOcard(){
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t        You can not use it. \n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(2);	
}
	
void screenMAXcard(){
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t You can not HIT. Maximum card\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(2);	
}	
	
void screenMAXscore(){
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t You can not USE. Maximum score\n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(2);	
}		
	
void screenWINNER(){
	
	char winner[10];
	
	if(score1 > score2)
		strcpy(winner , Name1); 
	else
		strcpy(winner , Name2);
	
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t           WINNER !!! \n");	
	printf("\t\t\t\t\t     %s\n",winner);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
	wait(4);
	
	system("cls");
	printf("___________________________________________________________________________________________\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	
	printf("\t\t\t\t       B L A C K J A C K\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t       THANK FOR PLAYING \n");	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("___________________________________________________________________________________________\n");
		
	
	
	
}
	
