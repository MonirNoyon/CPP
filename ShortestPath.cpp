#include<bits/stdc++.h>
// #include<conio.h>
//  #include<dos.h>
//  #include<unistd.h>
// #include<chrono>
// #include<thread>
using namespace std;
#define ll long long
#define yes "YES"
#define no "NO"
#define endl "\n"
int vis[1000][1000];
int n,stX,stY,enX,enY,play=0;
char ar[1000][1000];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int level[1000][1000];
pair<int,int>ParentCell[1000][1000];
//map<pair<int,int> >ParentCell[1000][1000];
bool invalid;
//vector<vector<pair<int,int>>>ParentCell(M,vector<int>(N,0));
void delay(int a);

bool valid(pair<int,int>CurrentCell)
{
    int x=CurrentCell.first;
    int y=CurrentCell.second;
    if(x>=0&&x<n&&y>=0&&y<n&&vis[x][y]==0&&ar[x][y]=='*')
    {
        return true;
    }
    return false;
}
void bfs(int stX,int stY)
{
    queue<pair<int,int> >q;
    q.push({stX,stY});
    level[stX][stY]=0;
    while(!q.empty())
    {

        pair<int,int>CurrentCell;
        CurrentCell=q.front();
        int x=CurrentCell.first;
        int y=CurrentCell.second;

        //cout<<x<<" "<<y;
        if(x==enX&&y==enY)
        {
            //cout<<x<<" "<<y<<endl;
            level[stX][stY]=level[x][y];
            return;
        }
        vis[x][y]='1';
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(valid({x+dx[i],y+dy[i]}))
            {
            q.push({(x+dx[i]),(y+dy[i])});
            level[x+dx[i]][y+dy[i]]=level[x][y]+1;
            ParentCell[x+dx[i]][y+dy[i]]=make_pair(x,y);
            }
        }
        }
        system("cls");
        cout<<"Duh! There is no path..."<<endl;
        invalid=true;
    }
    /////////////////////
    ///////////////
void input()
{
    cout<<"Enter the number for square matrix(Row==Column):: ";
    cin>>n;
    cout<<"\nNow enter the matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }
    }

    cout<<"Enter starting cell co-ordinates(for example::0 0)"<<endl;
    cin>>stX>>stY;
    cout<<"Enter destination cell co-ordinates(for example::1 1)"<<endl;
   cin>>enX>>enY;

}
/////////////////
////////////////
void startEngine()
{
    play++;
    level[stX][stY]=0;
   bfs(stX,stY);
    if(!invalid)
    {
        system("cls");
         cout<<"Yippee...(:Found it:)"<<endl<<endl;
    cout<<"-------------Animating fastest path to your destination-------------                 Play="<<play<<endl;
//path creating here
    vector<pair<int,int> >ans;
    int en=1;
   while(enX!=stX||stY!=enY)
   {
       ans.push_back({enX,enY});
       pair<int,int>cell;
       cell=ParentCell[enX][enY];
       enX=cell.first;
       enY=cell.second;
       en++;
       //these cells with value '1' indicates the path
   }

   ans.push_back({stX,stY});
en--;
   for(;en>=0;en--)
   {
       cout<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<"              ";
       for(int j=0;j<n;j++)
       {
           if(i==ans[en].first&&j==ans[en].second)ar[i][j]='1';
           cout<<ar[i][j];
       }
       cout<<endl;
   }
   delay(1);
  if(en>0)
  {
      system("cls");
      cout<<"-------------Animating Fastest way to your destination-------------                 Play="<<play<<endl;

   }

   }

   cout<<"Shortest distance is "<<level[stX][stY]<<endl;
}
}

////main funcion....
/////////

int main()
{
  while(1)
  {
    input();
    if(valid({stX,stY})){
   startEngine();
   for(int i=0;i<1000;i++)
   {
       for(int j=0;j<1000;j++)
       {
           vis[i][j]=0;
           level[i][j]=0;
           ParentCell[i][j].first=0;
           ParentCell[i][j].second=0;
       }
   }
    }
    else
    {
    cout<<"Ha Ha..You fool. That's a haunted place.\n";
    delay(3);
    cout<<"You're as good as dead.\n";
    delay(3);
    cout<<" See you for not mind..he he :}\n";
    return 0;
 }
   cout<<"\nWanna play again?\nWrite 'Y' as YES or 'N' as NO(Without quotation)\n";
   char c;
   while(1){
   cin>>c;
   if(c=='N')
   {
       cout<<":(\nThank You"<<endl;
       return 0;
   }
   else if(c=='Y')
   {
       break;
   }
   else cout<<"Invalid command..Please type 'Y' or 'N' only\n";
   }
   system("cls");
   continue;

  }
  }

/*testcase
10
**#****#**
**###**###
*##*#****#
*##***##**
****#****#
**#****#**
**###**###
*##*#****#
*##***##**
****#****#
*/

void delay(int a)
{
  int f;
  ll time=a*100000000;
  for(int i=0;i<time;i++)
  {
      f*=i;
      f++;
      f++;
  }
}
