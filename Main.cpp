#include <bits/stdc++.h>
using namespace std;
struct TeamNode{
    string name;
    int PointsEarned;
    int lastFiveMatchResult[5];
};

unordered_map<string,TeamNode*> TeamsList;
set<string> MaxConsecutiveLostOrWinTeams;

//Two Consecutive Lossed Teams 
void TwoConseCutiveLosses(){
    
    for(auto& x: TeamsList){
        for(int i=1;i<5;i++){
            if(x.second->lastFiveMatchResult[i] == 0 && x.second->lastFiveMatchResult[i-1]==0)
            cout<<x.first<<"\n";
            
        }
    }
}

//NConseCutiveLossed Teams
void NConseCutiveLosses(int n){
    for(auto& x: TeamsList){
        int count = 0;
        int maxCount = 0;
        for(int i=0;i<5;i++){
            if(x.second->lastFiveMatchResult[i]==0){
                count++;
                maxCount = max(maxCount, count);
            }
            else count = 0;
            
            
        }
        if(maxCount==n) cout<<x.first<<"\n";
    }
}


//NConseCutiveLossesOrWin Teams
void NConseCutiveLossesOrWins(int n){
    for(auto& x: TeamsList){
        int countWin = 0, countLoss=0;
        int maxCountLoss = 0, maxCountWin=0;
        for(int i=0;i<5;i++){
            if(x.second->lastFiveMatchResult[i]==0){
                countLoss++;
                maxCountLoss = max(maxCountLoss, countLoss);
                countWin = 0;
            }
            else{
                countLoss = 0;
                countWin++;
                maxCountWin = max(maxCountWin, countWin);
            } 
        }
        if(maxCountLoss==n || maxCountWin==n){
            MaxConsecutiveLostOrWinTeams.insert(x.first);
            cout<<x.first<<"\n";
        } 
    }
}

//Average points of lossed/winned Teams
double AveragePoints(){
    int sum = 0;
    for(auto &x : MaxConsecutiveLostOrWinTeams){
        sum += TeamsList[x]->PointsEarned;
    }
    return sum / MaxConsecutiveLostOrWinTeams.size();
}




int main()
{
    
    //std::cin >> Enter Team Details;   
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        TeamNode* newNode = new TeamNode();
        string name;
        int point;
        cin>>name;
        cin>>point;
        newNode->name = name;
        newNode->PointsEarned = point;
        for(int i=0;i<5;i++){
            int c;
            cin>>c;
            newNode->lastFiveMatchResult[i] = c;
        }
        TeamsList[name] = newNode;
        
    }
    
    //cout<<"N Cosecutive Lossed Teams are : \n";
    //TwoConseCutiveLosses();
    int nCon;
    cin>>nCon;
    //NConseCutiveLosses(nCon);
    NConseCutiveLossesOrWins(nCon);
    
    cout<<AveragePoints()<<" ";
    
    return 0;
}
