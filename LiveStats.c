 #include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
 
 #define edt1_id 1
 #define edt2_id 2
 #define edt3_id 3
 #define edt4_id 4
 #define edt5_id 5
 
 #define cb1_id 6
 
 char playerNum[5][5]={0};
 
  HWND PlayerFirst, PlayerSecond, PlayerThird, PlayerFourth, PlayerFifth, Scored, Foul, Traveling, DoubleDrible, Turnover,
  			 OnePoint, TwoPoints, ThreePoints, PersonalFoul, UnsportableFoul, TechnicalFoul, SaveResult, Zeroing, Close, ShowRes;
  HWND hwnd;
  HWND edt,CB;

  HWND cap1, cap2, cap3, cap4, cap5, cap6, cap7, cap8, cap9, cap10, cap11, cap12;
  char text[25]="please enter the player", text2[20]="", text3[20]="", text4[10]="Play", text5[30]="You select player # ";// text6[10]="Play", text7[10]="Play",text8[10]="Play";
  char num1;
  int num,N, allow=0;
  int *PlayerCount=&num, action, *paction=&action;
  int quantity;
  int *q=&quantity;
  int structSize;
  
  void InputButtonFirst();
  void InputButtonSecond();
  void InputButtonPoints();
  void InputButtonFoul();
  void InputButtonMenu();
  void EraseData();
  void outData();
  void calcEfficiency();
  void ShowResult();
  void SetMem();
  LRESULT WndProc(HWND, UINT, WPARAM,LPARAM);
  
  struct person{
   	int points;
  	int personalFouls;
  	int technicalFouls;
  	int unsportableFouls;
  	int traveling;
  	int DoubleDrible;
  	int turnover;
  	int efficiency;
   };
    struct person* player;
 	struct person players [5];
    struct person* teamMember=players;
   	FILE* myfile;
     
   int main()
 { 	
	WNDCLASSA wcl;
		memset(&wcl, 0, sizeof(WNDCLASSA));
		wcl.lpszClassName = "my Window";
		wcl.lpfnWndProc = WndProc;
	RegisterClassA (&wcl);

 	hwnd = CreateWindow("my Window", "Window Name", WS_OVERLAPPEDWINDOW,
	 			  10, 10, 640, 700, NULL, NULL, NULL, NULL);
 	 	
	ShowWindow (hwnd, SW_SHOWNORMAL);
	HWND CB = CreateWindow("combobox", "", WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST, 510,60,100,150, hwnd, (HMENU) cb1_id, NULL, NULL);
		SendMessage(CB, CB_ADDSTRING, 0, (LPARAM)"2");
		SendMessage(CB, CB_ADDSTRING, 0, (LPARAM)"3");
		SendMessage(CB, CB_ADDSTRING, 0, (LPARAM)"4");
		SendMessage(CB, CB_ADDSTRING, 0, (LPARAM)"5");
		SendMessage(CB, CB_SETCURSEL, 0, 0);	
	HWND edt = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER  | ES_NUMBER, 10,30,100,20, hwnd, (HMENU) edt1_id , NULL, NULL);
	HWND edtsecond = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER  | ES_NUMBER, 110,30,100,20, hwnd, (HMENU) edt2_id , NULL, NULL);
	HWND edtthird = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER  | ES_NUMBER, 210,30,100,20, hwnd, (HMENU) edt3_id , NULL, NULL);
	HWND edtfourth = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER  | ES_NUMBER, 310,30,100,20, hwnd, (HMENU) edt4_id , NULL, NULL);
	HWND edtfifth = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER  | ES_NUMBER, 410,30,100,20, hwnd, (HMENU) edt5_id , NULL, NULL);

	InputButtonFirst();
 	InputButtonSecond();
 	InputButtonPoints();
 	InputButtonFoul();
 	InputButtonMenu();
 	SetMem();
 
  	MSG msg;
 	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);	
	}	
 	return 0;
 }
 
  void InputButtonFirst(){
 	PlayerFirst = CreateWindow("button", "player", WS_VISIBLE | WS_CHILD, 10,60,100,50, hwnd, NULL, NULL, NULL);
 	 
 	PlayerSecond = CreateWindow("button", "player", WS_VISIBLE | WS_CHILD, 110,60,100,50, hwnd, NULL, NULL, NULL);
 	 
 	PlayerThird = CreateWindow("button", "player", WS_VISIBLE | WS_CHILD, 210,60,100,50, hwnd, NULL, NULL, NULL);
 	 
 	PlayerFourth = CreateWindow("button", "player", WS_VISIBLE | WS_CHILD, 310,60,100,50, hwnd, NULL, NULL, NULL);
 	 
 	PlayerFifth = CreateWindow("button", "player", WS_VISIBLE | WS_CHILD, 410,60,100,50, hwnd, NULL, NULL, NULL);
 }
 
void InputButtonSecond(){
	Scored = CreateWindow("button", "Scored", WS_VISIBLE | WS_CHILD, 10,170,100,50, hwnd, NULL, NULL, NULL);
	 	 
	Foul = CreateWindow("button", "Foul", WS_VISIBLE | WS_CHILD, 110,170,100,50, hwnd, NULL, NULL, NULL);
			 	 
	Traveling = CreateWindow("button", "Traveling", WS_VISIBLE | WS_CHILD, 210,170,100,50, hwnd, NULL, NULL, NULL);
			 	 
	DoubleDrible = CreateWindow("button", "Double drible", WS_VISIBLE | WS_CHILD, 310,170,100,50, hwnd, NULL, NULL, NULL);
			 	
	Turnover = CreateWindow("button", "Turnover", WS_VISIBLE | WS_CHILD, 410,170,100,50, hwnd, NULL, NULL, NULL);
}

void InputButtonPoints(){
	OnePoint = CreateWindow("button", "1 point", WS_VISIBLE | WS_CHILD, 10,240,100,50, hwnd, NULL, NULL, NULL);
			 	 
	TwoPoints = CreateWindow("button", "2 points", WS_VISIBLE | WS_CHILD, 10,290,100,50, hwnd, NULL, NULL, NULL);
			 	 
	ThreePoints = CreateWindow("button", "3 points", WS_VISIBLE | WS_CHILD, 10,340,100,50, hwnd, NULL, NULL, NULL);
 		
}

void InputButtonFoul(){
	PersonalFoul = CreateWindow("button", "personal", WS_VISIBLE | WS_CHILD, 110,240,100,50, hwnd, NULL, NULL, NULL);
			 	 
	UnsportableFoul = CreateWindow("button", "unsportable", WS_VISIBLE | WS_CHILD, 110,290,100,50, hwnd, NULL, NULL, NULL);
			 	 
	TechnicalFoul = CreateWindow("button", "technical", WS_VISIBLE | WS_CHILD, 110,340,100,50, hwnd, NULL, NULL, NULL);
			 	
			 
 		
}
void InputButtonMenu(){
	SaveResult = CreateWindow("button", "Save result", WS_VISIBLE | WS_CHILD, 320,300,100,50, hwnd, NULL, NULL, NULL);
				
	Zeroing = CreateWindow("button", "Set to zero", WS_VISIBLE | WS_CHILD, 420,300,100,50, hwnd, NULL, NULL, NULL);
				
	Close = CreateWindow("button", "Quit", WS_VISIBLE | WS_CHILD, 420,360,100,50, hwnd, NULL, NULL, NULL);
				
	ShowRes = CreateWindow("button", "Show result", WS_VISIBLE | WS_CHILD, 320,360,100,50, hwnd, NULL, NULL, NULL);
			
}
void EraseData(){
	int i=0;
	strcpy(text2, "");
	strcpy(text3, "");
 	for (i=0;i<5;i++){
 		teamMember[i].points=0;
	  	teamMember[i].personalFouls=0;			
	  	teamMember[i].DoubleDrible=0;
	  	teamMember[i].traveling=0;
	  	teamMember[i].technicalFouls=0;
	  	teamMember[i].unsportableFouls=0;
	  	teamMember[i].turnover=0;
	}
}

void outData()
{
	int i;
	if ((myfile = fopen("res.txt","w")) == NULL)
   		printf("It is impossible to open or create file \n");
    	fprintf(myfile, "               Points||Personal  Fouls|Unsportable Fouls|Technical Fouls||Vtrata|Traveling|Doubledribble||Efficiency\n");								  //	int personalFouls;
								  
		for (i=0;i<structSize;i++){
   		fprintf(myfile, "Players %s  ||   %i    ||        %i       |        %i       |       %i      ||   %i  |     %i   |      %i       ||     %i\n", playerNum[i],teamMember[i].points, teamMember[i].personalFouls, teamMember[i].unsportableFouls, teamMember[i].technicalFouls, teamMember[i].turnover, teamMember[i].traveling, teamMember[i].DoubleDrible, teamMember[i].efficiency);
   	}	
    fflush(myfile);  
 	fclose(myfile);
}
void calcEfficiency(){
	int i;
	for (i=0;i<structSize;i++){
		teamMember[i].efficiency=teamMember[i].points-0,5*(teamMember[i].personalFouls-teamMember[i].technicalFouls-teamMember[i].unsportableFouls)-teamMember[i].technicalFouls-teamMember[i].unsportableFouls-0.5*teamMember[i].turnover;
	}
}
void ShowResult(){
	int i;
	printf("               Points||Personal  Fouls|Unsportable Fouls|Technical Fouls||Turnover|Traveling|Doubledribble||Efficiency\n");
	for (i=0;i<structSize;i++){
		printf("Player %5s  ||   %i    ||      %i        |         %i       |       %i       ||  %i    |    %i    |     %i      ||     %i\n", playerNum[i], teamMember[i].points, teamMember[i].personalFouls, teamMember[i].unsportableFouls, teamMember[i].technicalFouls, teamMember[i].turnover, teamMember[i].traveling, teamMember[i].DoubleDrible, teamMember[i].efficiency);
	}
}
LRESULT WndProc(HWND hwnd,UINT message, WPARAM wparam,LPARAM lparam) 
	{
 	int i;
 	if (message==WM_DESTROY)  
	 	PostQuitMessage(0);
  		
 	else if (message == WM_COMMAND){
 		
 	if (LOWORD(wparam) == cb1_id){
 		
 		if (HIWORD(wparam) == CBN_SELCHANGE)
		 {quantity = SendMessage((HWND)lparam,CB_GETCURSEL,0,0);}	
 	 switch (*q+2){
 	 	case 2: printf("2");
 	 		cap6 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 10,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap7 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 110,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap8 = CreateWindow ("static", "not play", WS_VISIBLE | WS_CHILD, 210,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap9 = CreateWindow ("static", "not play", WS_VISIBLE | WS_CHILD, 310,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap10 = CreateWindow ("static","not play", WS_VISIBLE | WS_CHILD, 410,10,100,20, hwnd, NULL, NULL, NULL );
 	 		if (allow!=2){
 	 			allow=2;
 	 			SetMem();}
			break;
 	 	case 3: printf("3");
 	 		cap6 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 10,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap7 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 110,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap8 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 210,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap9 = CreateWindow ("static", "not play", WS_VISIBLE | WS_CHILD, 310,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap10 = CreateWindow ("static","not play", WS_VISIBLE | WS_CHILD, 410,10,100,20, hwnd, NULL, NULL, NULL );
 	 		if (allow!=3){
			  	allow=3;
 	 			SetMem();}
 	 		break;
 	 	case 4: printf("4");
 	 		cap6 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 10,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap7 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 110,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap8 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 210,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap9 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 310,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap10 = CreateWindow ("static","not play", WS_VISIBLE | WS_CHILD, 410,10,100,20, hwnd, NULL, NULL, NULL );
 	 		if (allow!=4){
			  	allow=4;
 	 			SetMem();}
 	 		break;
		case 5: printf("5");
			cap6 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 10,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap7 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 110,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap8 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 210,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap9 = CreateWindow ("static", text4, WS_VISIBLE | WS_CHILD, 310,10,100,20, hwnd, NULL, NULL, NULL );
 	 		cap10 = CreateWindow ("static",text4, WS_VISIBLE | WS_CHILD, 410,10,100,20, hwnd, NULL, NULL, NULL );
 	 		if (allow!=5){
			  	allow=5;
 	 			SetMem();}
 	 		break;		  	 	
 		 }
	}

}
if (message==WM_DESTROY)  
	 	PostQuitMessage(0);
  		
 	else if (message == WM_COMMAND){
 	 	char *num=playerNum[5];
 		if (LOWORD(wparam) == edt1_id){
		int nc = HIWORD(wparam);
		GetWindowText((HWND)lparam, playerNum[0], 10);}
	 	 	
		if (LOWORD(wparam) ==edt2_id){
		 	GetWindowText((HWND)lparam, playerNum[1], 10);}
	 	
		if (LOWORD(wparam) ==edt3_id){
		 	GetWindowText((HWND)lparam, playerNum[2], 10);}
	 	
		if (LOWORD(wparam) ==edt4_id){
		 	GetWindowText((HWND)lparam, playerNum[3], 10);}

		if (LOWORD(wparam) ==edt5_id){
		 	GetWindowText((HWND)lparam, playerNum[4], 10);}
 				
 	if (Close == lparam)	{PostQuitMessage(0);}
				
	if (PlayerFirst == lparam) {
		strcpy(text5, "You select player # ");
		strncat (text5, playerNum[0],5);
		strcpy(text, text5); 
		*PlayerCount=1;}
				
	else  if (PlayerSecond == lparam) {
		strcpy(text5, "You select player # ");
		strncat (text5, playerNum[1],5);
		strcpy(text, text5);
		*PlayerCount=2;} 
									 
	else if	 (PlayerThird == lparam) {
		if (allow>2) {
			strcpy(text5, "You select player # ");
			strncat (text5, playerNum[2],5);
			strcpy(text, text5);
			*PlayerCount=3;}
		else { printf("Not=%i\n",allow);
		 	strcpy(text, "This player can't play ");
		 	*PlayerCount=6;
			}
		}
	else if (PlayerFourth == lparam){
		if (allow>3)
	 		{strcpy(text5, "You select player # ");
			strncat (text5, playerNum[3],5);
			strcpy(text, text5);
			*PlayerCount=4;}
		else {	strcpy(text, "This player can't play");
			*PlayerCount=6;
			}
	}
	else if (PlayerFifth == lparam){
		if (allow>4) {
			strcpy(text5, "You select player # ");
			strncat (text5, playerNum[4],5);
			strcpy(text, text5);
			*PlayerCount = 5;}
		else {
			strcpy(text, "This player can't play");
			*PlayerCount=6;
			}
		}
	cap1 = CreateWindow ("static", text, WS_VISIBLE | WS_CHILD,
					 	 60, 120,200,20, hwnd, NULL, NULL, NULL );
	if ((*PlayerCount > 0) && (*PlayerCount < 6)){	
		cap2 = CreateWindow ("static", "please enter the action", WS_VISIBLE | WS_CHILD,
					 	 60, 140,200,20, hwnd, NULL, NULL, NULL );	
		if (message==WM_DESTROY)
		 		PostQuitMessage(0);
		if (message == WM_COMMAND)	{
			if (Scored == lparam)  {strcpy(text2, "how many points?"); 
						 						*paction = 10; }
			else if	 (Foul == lparam) {	strcpy(text2, "which foul?");
						 							*paction=11;}
			else if	 (Traveling == lparam) {strcpy(text2, "traveling");
													*paction=12;}
			else if	 (DoubleDrible == lparam) {strcpy(text2, "double dribling");
													*paction=13;}
			else if	 (Turnover == lparam) {strcpy(text2, "turnover");
													*paction = 14;}
				}
		cap4 = CreateWindow ("static", text2, WS_VISIBLE | WS_CHILD,
							 	 250, 230,200,50, hwnd, NULL, NULL, NULL );	  						
	}
	switch (*paction){
	 	case 10: 	strcpy(text3, "");										
 			if (message==WM_DESTROY)
 					PostQuitMessage(0);
 			if (message == WM_COMMAND)	{		
				if (OnePoint == lparam){strcpy(text3, "1 point");
					teamMember[*PlayerCount-1].points++;
					}
			else if (TwoPoints == lparam) {
						strcpy(text3, " 2 points");
						teamMember[*PlayerCount-1].points+=2; 
					}
			else if (ThreePoints == lparam) {
						strcpy(text3, " 3 points");
						teamMember[*PlayerCount-1].points+=3;
					}					
 				} break;
 		case 11 :	
		 	strcpy(text3, "");										//fault
 			if (message==WM_DESTROY)
 					PostQuitMessage(0);
 			if (message == WM_COMMAND)	{
 				if (PersonalFoul == lparam) {strcpy(text3, "personal foul");
						teamMember[*PlayerCount-1].personalFouls++;
					}
			else if (UnsportableFoul == lparam) {
					strcpy(text3, "unsportable foul");
					teamMember[*PlayerCount-1].unsportableFouls++;
					teamMember[*PlayerCount-1].personalFouls++;
					}
			else if (TechnicalFoul == lparam) {
					strcpy(text3, "technical foul");
					teamMember[*PlayerCount-1].technicalFouls++;
					teamMember[*PlayerCount-1].personalFouls++;
					}
				} break;
		case 12 :
				strcpy(text3, "traveling");
				teamMember[*PlayerCount-1].traveling++;
				teamMember[*PlayerCount-1].turnover++;
				*paction=0;
				break;
 		case 13: 
				strcpy(text3, "double drible");
				teamMember[*PlayerCount-1].DoubleDrible++;
				teamMember[*PlayerCount-1].turnover++;
				*paction=0;
				break;
		case 14 :
				strcpy(text3, "turnover");
				teamMember[*PlayerCount-1].turnover++;
				*paction=0;
				break;
			}
	if (message == WM_COMMAND) 
  		{if (Zeroing == lparam) EraseData();
  	else if (SaveResult == lparam){
		 	calcEfficiency();
		  	outData();
	}
	else if (ShowRes == lparam) {
		calcEfficiency(); 
		ShowResult();
	}
		}
		cap5 = CreateWindow ("static", text3, WS_VISIBLE | WS_CHILD,
			250, 250,200,50, hwnd, NULL, NULL, NULL );
	}
 	else return DefWindowProcA (hwnd, message, wparam, lparam);
 }
 void SetMem(){
 	free (player);
 	player=(struct person*)malloc((*q+2)*sizeof(struct person));
	structSize = _msize(player)/sizeof (struct person);
	printf("test=%i\n",structSize);
 }
