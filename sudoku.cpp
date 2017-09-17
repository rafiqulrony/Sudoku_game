//This program have to be compiled in TC compiler,which supports clrscr()


#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

int sudoku[9][9];  //global declaration of variable

class project    //definition of class
{

  void show(int sudoku[][9]); //declaration of non-inline show()
  void validplace()
   {
    cout<<endl<<"The following places are valid to insert number(r=row,c=column):";
    cout<<endl<<"(r1 & c5),(r2 & c1),(r2 & c9),(r5 & c2),(r5 & c5),(r5 & c8)";
    cout<<endl<<"(r8 & c1),(r8 & c9),(r9 & c5)";
   }

public:
 void original(int sudoku[][9]); //declaration of non-inline original()
 void backbone(int sudoku[][9]); //declaration of non-inline backbone()

};   // The class ends here

  void project::original(int sudoku[][9]) //definition of non-inline & public original()
  {

	int str[][9]={ 9,6,5,4,0,1,7,3,8,
		       0,3,8,5,7,9,1,2,0,
		       1,2,7,6,3,8,9,4,5,
		       8,9,6,7,4,3,5,1,2,
		       7,0,4,2,0,6,3,0,9,
		       2,1,3,9,8,5,6,7,4,
		       6,8,1,3,5,4,2,9,7,
		       0,7,9,8,6,2,4,5,0,
		       5,4,2,1,0,7,8,6,3 };

	     for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			sudoku[i][j]=str[i][j];

		 show(sudoku);

  }//original() ends here

  void project::show(int sudoku[][9]) //definition of non-inline & private show()
  {
    cout<<"................................";
    cout<<endl;

    for(int i=0;i<9;i++)
       {
	 cout<<endl;
	 cout<<"\t\t";
	 for(int j=0;j<9;j++)
	    {
	      if(sudoku[i][j]==0)
	       {
		 cout<<" *";
		 goto next;
	       }
	      cout<<" "<< sudoku[i][j];
	      next:
	      if(j==2||j==5)
		 cout<<" .";
	    }
	 if(i==2||i==5)
	    {
	       cout<<endl;
	       cout<<"               .........................";
	    }
       }
     cout<<endl;

  }//show() ends here

  void project::backbone(int sudoku[][9]) //definition of non-inline & public backbone()
  {
    int a,k,l,u,v,i,j,x,s1,s2,s3,s4,s5,s6,s7,s8,s9;
    char menu;

    label:
      for(;;)
	{
	  cout<<endl;
	  cout<<"\t1.INSERT NUMBER/PLAY THE GAME (Press 1 & Enter)"<<endl;
	  cout<<"\t2.CHECK (Press 2 & Enter)"<<endl;
	  cout<<"\t3.RESET (Press 3 & Enter)"<<endl;
	  cout<<"\t4.SEE THE CORRECT SOLUTION (Press 4 & Enter)"<<endl;
	  cout<<"\t5.HELP/INSTRUCTIONS (Press 5 & Enter)"<<endl;
	  cout<<"\t6.QUIT GAME (Press 6 & Enter)"<<endl;
	  cout<<endl<<"Choice the menu........";
	  cin>>menu;
	  a=menu;

	  if(a<49||a>54)
	    {
	      clrscr();
	      cout<<endl<<"The SUDOKU you're playing now...";
	      show(sudoku);
	      cout<<endl<<"ERROR! You have to input a number between 1 & 6 for choosing the menu"<<endl;
	      cout<<"Press any key to continue";
	      
              getch();
	      clrscr();
	      cout<<endl<<"The SUDOKU you're playing now...";
	      show(sudoku);
	    }

	  else
	    {

	      switch(menu)
		{

		  case '1':
		    clrscr();
		    cout<<endl<<"The SUDOKU you're playing now...";
		    show(sudoku);
		    validplace();
		    cout<<endl<<endl<<"Enter the ROW no.";
		    cin>>i;
		    cout<<"Enter the COLUMN no.";
		    cin>>j;

		    if((i==1&&j==5)||(i==2&&j==1)||(i==2&&j==9)||(i==5&&j==2)||(i==5&&j==5)||(i==5&&j==8)||(i==8&&j==1)||(i==8&&j==9)||(i==9&&j==5))
		      {
			clrscr();
			cout<<endl<<"The SUDOKU you're playing now...";
			show(sudoku);
			cout<<endl<<" Row="<<i<<" & Column="<<j;
			cout<<endl<<"Insert an integer number for this row & column";
			cout<<endl<<"Inserted number should be greater than 0 & less than 10";
			cout<<"...";
			cin>>x;

			if(x<1||x>10)
			  {
			    clrscr();
			    cout<<endl<<"The SUDOKU you're playing now...";
			    show(sudoku);
			    cout<<"ERROR! It should be greater than 0 & less than 10";
			    cout<<endl<<"Press any key to continue.......";

			    getch();
			    clrscr();
			    cout<<endl<<"The SUDOKU you're playing now...";
			    show(sudoku);
			  }

			 else
			  {
			    sudoku[i-1][j-1]=x;
			    clrscr();
			    cout<<endl<<"The SUDOKU you're playing now...";
			    show(sudoku);
			  }
		      }

		    else
		      {
			clrscr();
			cout<<endl<<"The SUDOKU you're playing now...";
			show(sudoku);
			cout<<endl<<"ERROR! Selected position isn't valid for insert number";
			cout<<endl<<"Press any key to continue.......";

			getch();
			clrscr();
			cout<<endl<<"The SUDOKU you're playing now...";
			show(sudoku);
		      }
		    break;

		  case '2':
		    clrscr();
		    cout<<endl<<"The SUDOKU you're playing now...";
		    show(sudoku);
		    goto loop;
		    //break;

		  case '3':
		    clrscr();
		    original(sudoku);
		    break;

		  case '4':
		    s1=sudoku[1][0];s2=sudoku[7][0];s3=sudoku[4][1];s4=sudoku[0][4];
		    s5=sudoku[4][4];s6=sudoku[8][4];s7=sudoku[4][7];s8=sudoku[1][8];
		    s9=sudoku[7][8];
		    clrscr();
		    cout<<endl<<"The original sudoku is...";
		    original(sudoku);
		    cout<<endl<<"The right solution for this sudoku is given below";
		    cout<<"(r=row & c=column)";
		    cout<<endl<<"(r1 & c5)=2,(r2 & c1)=4,(r2 & c9)=6,(r5 & c2)=5,(r5 & c5)=1,";
		    cout<<endl<<"(r5 & c8)=8,(r8 & c1)=3,(r8 & c9)=1,(r9 & c5)=9";
		    cout<<endl<<"Press any key to continue";

		    getch();
		    clrscr();
		    sudoku[1][0]=s1;sudoku[7][0]=s2;sudoku[4][1]=s3;sudoku[0][4]=s4;
		    sudoku[4][4]=s5;sudoku[8][4]=s6;sudoku[4][7]=s7;sudoku[1][8]=s8;
		    sudoku[7][8]=s9;
		    cout<<endl<<"The SUDOKU you're playing now...";
		    show(sudoku);
		    break;

		  case '5':
		    clrscr();
		    cout<<endl<<endl<<"  The rules:"<<endl<<endl;
		    cout<<"  1. You have to fill up only the positions that contain *"<<endl;
		    cout<<"     with integers not less than 1 or not greater than 9."<<endl;
		    cout<<"  2. such that, no row or no column contains a same number twice or more."<<endl;
		    cout<<"     It means, every row & every column should contain 9 different numbers."<<endl;
		    cout<<"  3. & no 3x3 box contains a same number twice or more."<<endl;
		    cout<<"     It means, every 3x3 box should contain 9 different numbers."<<endl;
		    cout<<"  4. All the * should be filled to check the solution."<<endl<<endl<<endl;
		    cout<<"        Press any key to continue......";

		    getch();
		    clrscr();
		    show(sudoku);
		    break;

		  case '6':
		    exit(0);
		    break;
	       }//switch-case ends
	    }//else ends for choosing the menu between 1 & 6.
	   }//infinite for loop ends


    loop:

      //0 CHECK
    for(i=0;i<9;i++)
       for(j=0;j<9;j++)
	  {
	    if(sudoku[i][j]==0)
	      {
		clrscr();
		cout<<endl<<"The SUDOKU you're playing now...";
		show(sudoku);
		cout<<endl<<"The SUDOKU you're playing isn't totally filled"<<endl;
		cout<<"You have to fill up the whole sudoku";
		cout<<" so that it doesn't contain any *"<<endl;
		cout<<"Press any key to continue.......";

		getch();
		clrscr();
		cout<<endl<<"The SUDOKU you're playing now...";
		show(sudoku);
		goto label;
	      }
	  }

    if(i==9)  //1st if
      {
	   //ROW CHECK
	for(i=0;i<9;i++)
	   for(j=0;j<8;j++)
	      for(k=j+1;k<9;k++)
		 {

		   if(sudoku[i][j]==sudoku[i][k])
		     {
		       clrscr();
		       cout<<endl<<endl<<"Your solution is WRONG!!!";
		       cout<<endl<<"Press any key to continue.......";
		       
                       getch();
		       clrscr();
		       cout<<endl<<"The SUDOKU you're playing now...";
		       show(sudoku);
		       goto label;
		     }
		 }

	if(i==9) //2nd internal if
	  {
	     //COLUMN CHECK
	     for(i=0;i<9;i++)
		for(j=0;j<8;j++)
		   for(k=j+1;k<9;k++)
		      {

			if(sudoku[j][i]==sudoku[k][i])
			  {
			     clrscr();
			     cout<<endl<<endl<<"Your solution is WRONG!!!";
			     cout<<endl<<"Press any key to continue.......";

			     getch();
			     clrscr();
			     cout<<endl<<"The SUDOKU you're playing now...";
			     show(sudoku);
			     goto label;
			  }
		      }

	     if(i==9)  //3rd internal if
	       {
		    //9 BOX CHECK
		 i=0;j=0;k=0;l=0;u=3;v=3;

		 again:
		   for(i=i;i<u;i++)
		     for(j=j;j<v;j++)
		       for(k=k;k<u;k++)
			 for(l=l;l<v;l++)
			   {

			      if(i==k && j==l)
				  continue;

			      else if(sudoku[i][j]==sudoku[k][l])
				{
				  clrscr();
				  cout<<endl<<endl<<"Your solution is WRONG!!!";
				  cout<<endl<<"Press any key to continue.......";

				  getch();
				  clrscr();
				  cout<<endl<<"The SUDOKU you're playing now...";
				  show(sudoku);
				  goto label;
			       }
			   }

		 if(i==9)
		   {
		      clrscr();
		      cout<<endl<<endl<<"You are successful! Solution is RIGHT!!!";
		      cout<<endl<<"Press any key to continue.......";

		      getch();
		      clrscr();
		      cout<<endl<<"The SUDOKU you're playing now...";
		      show(sudoku);
		      goto label;
		   }

		 if(i==3 && j==9)
		   {
		     j=0;l=0;u=6;v=3;
		     goto again;
		   }
		 else if(i==3)
		   {
		     i=0;k=0;v=v+3;
		     goto again;
		   }
		 else if(i==6 && j==9)
		   {
		     j=0;l=0;u=9;v=3;
		     goto again;
		   }
		 else if(i==6)
		   {
		     i=3;k=3;v=v+3;
		     goto again;
		   }
		 else if(i==9)
		   {
		     i=6;k=6;v=v+3;
		     goto again;
		   }

	       }//close of 3rd internal if
	  }//close of 2nd internal if
      }//close of 1st if
  }//close of backbone()



void main()
{
  project obj;   //declaration of an object
  clrscr();
  obj.original(sudoku);
  obj.backbone(sudoku);
}
