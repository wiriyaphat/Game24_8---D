#include <iostream>
using namespace std;

void StreakTrack(bool ans){
    const int base_score = 5;
    const int streak_base = 3;
    static int curstreak=0;
    static int tolscore=0;
    static int max_streak=0;
    int received_score;
    if(ans){
        curstreak++;
        int received_score;
        if(curstreak >= streak_base){
            if(curstreak>= max_streak){
                max_streak = curstreak;
            }
            received_score = base_score * curstreak;
            cout << "Correct! Streak: " << curstreak << endl;
            cout << "Score: +" << received_score << " | Total: " << tolscore + received_score << endl;
            //ให้ HUD Display Streak หลังจากตอบถูก 3 ครั้งติดต่อกัน 
            //ละก็ Display คะแนนทุกๆครั้งด้วย
        }else {
            received_score = base_score;
            cout << "Correct!" << endl;
            cout << "Score: +" << received_score << " | Total: " << tolscore + received_score << endl;
        }
        tolscore += received_score;
    }else{
        curstreak = 0; // Display คะแนนที่มีอยู่ (ไม่รู้ว่าจะแพ้เลยมั้ย ต้องถาม The Gng)
        cout << "Wrong! Streak reset." << endl;
        cout << "Total score: " << tolscore << endl;
    }
}

int main() {

    bool ans = true; 
    for(int i =0;i<8;i++){
    StreakTrack(true);   

    }
    StreakTrack(true);   
    StreakTrack(true);   
    StreakTrack(true);  
    StreakTrack(true);  
    StreakTrack(true);   
    StreakTrack(false);
}