#include<bits/stdc++.h>
using namespace std;
bool rowcrossed(char gm[][3],int r)
{
    if((gm[r][0]==gm[r][1]) && (gm[r][1]==gm[r][2]) && (gm[r][2]!='.'))
    {    
        return (true);
    }
    return(false);
}
bool colcrossed(char gm[][3],int c)
{
    if((gm[0][c]==gm[1][c]) && (gm[1][c]==gm[2][c]) && (gm[2][c]!='.'))
    {     
        return (true);
    }
    return (false);
}
bool diacrossed(char gm[][3])
{
    if((gm[0][0]==gm[1][1]) && (gm[1][1]==gm[2][2]) && (gm[2][2]!='.'))
    {    
        return (true);
    }
    if((gm[0][2]==gm[1][1]) && (gm[1][1]==gm[2][0]) && (gm[2][0]!='.'))
    {    
        return (true);
    }
    return (false);
}
bool gameres(char gm[][3],int r,int c)
{
    return (rowcrossed(gm,r)||colcrossed(gm,c)||diacrossed(gm));
}
int play(char p[3][3],char x)
{
    int r,c,f=0,i,j;
    do{
        cout<<"Choose a row number (0 to 2) :"<<endl;cin>>r;
        if(r>-1&&r<3){
            cout<<"Choose a column number (0 to 2) :"<<endl;cin>>c;
            if(c<0||c>2){
                cout<<c<<" is not a valid column."<<endl;
            }
            else
            {
                if(p[r][c]!='.'){
                    cout<<"this is already occupied position"<<endl;
                }
                else
                {
                    f=1;
                }
                
            }
        }
        else{
            cout<<r<<" is not a valid row."<<endl;
        }    
    }while(f!=1);
    p[r][c]=x;
    system("CLS");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    if(gameres(p,r,c)==true)
        return 1;
    return 0;
}
void game(string pl1,string pl2,char x,char o)
{
    int i,j,k,f=0;
    char gm[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            gm[i][j]='.';
            cout<<gm[i][j]<<" ";
        }
        cout<<endl;
    }
    for(k=0;k<9;k++)
    {
        if(k%2==0){
            cout<<"Player of current turn:"<<pl1<<endl;
            f=play(gm,x);
            if(f==1){
                cout<<"Game is over:"<<endl<<pl1<<" wins!"<<endl;
                k=10;
                getchar();
            }
        }
        else{
            cout<<"Player of current turn:"<<pl2<<endl;
            f=play(gm,o);
            if(f==1){
                cout<<"Game is over:"<<endl<<pl2<<" wins!"<<endl;
                k=10;
                getchar();
            }
        }
    }
    if(f==0){
        cout<<"Game is over:"<<endl<<"it is tie!";
    }
}
int main()
{
    string pl1,pl2,fp;
    int f;
    do{
        cout<<"Enter a name for X player:"<<endl;getline(cin,pl1);
        cout<<"Enter a name for O player:"<<endl;getline(cin,pl2);
        do{
            cout<<"Who plays first, "<<pl1<<" or "<<pl2<<"?"<<endl;getline(cin,fp);
            f=0;
            if((pl1.compare(fp)!=0)&&pl2.compare(fp)!=0){
                cout<<fp<<" is not a registered player."<<endl;
                f=1;
            }
        }while(f==1);
        if(fp.compare(pl1)==0){
            game(pl1,pl2,'X','O');
        }
        else if(fp.compare(pl2)==0){
            game(pl2,pl1,'O','X');
        }
        do{
            cout<<"Would you like to play again? (Y/N)"<<endl;getline(cin,fp);
            f=0;
            if((fp.compare("Y")!=0)&&fp.compare("N")!=0){
                cout<<fp<<" is not a valid answer."<<endl;
                f=1;
            }
        }while(f==1);
        f=0;
        if(fp.compare("N")==0){
            cout<<"Bye!"<<endl;
            f=1;
        }
    }while(f!=1);
    return 0;
}
