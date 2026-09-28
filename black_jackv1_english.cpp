#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <thread>
#include <chrono>

using namespace std;

int main(){

    setlocale(LC_ALL, ".UTF8");
    srand(time(NULL)); 
    int deck[52]={
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 
    };

    int wallet=1000;
    cout<<"Welcome to our casino! In this game, you'll play blackjack. Get ready to lose!"<<"\n"; 
    this_thread::sleep_for(chrono::milliseconds(4000));
    cout<<"The goal is to get 21 points. When drawing cards, you can't exceed 21 points, otherwise you lose. You start with 1000 USD. Your opponent is the dealer."<<"\n";
    this_thread::sleep_for(chrono::milliseconds(5000));

    while(wallet>0){
        
        for(int i=0;i<52;i++) {
            int random_index=rand()%52;
            swap(deck[i],deck[random_index]);
        }

        int player_points=0;
        int card_index=0;
        bool player_lost=false;
        bool player_won=false;

        player_points+=deck[card_index];
        card_index++;
        player_points+=deck[card_index];
        card_index++;
        if(player_points==21){
            cout<<"Wow! Your first two cards are 21! (lucky fool...)"<<"\n";
            cout<<"Your points: "<<player_points<<"\n";
            wallet+=300;
            cout<<"Added 300 USD !"<<"\n";
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout<<"Your wallet balance: "<<wallet<<" USD"<<"\n";
            continue;
        }

        string a;

        for(int i=0;i<=21;i++){

            cout<<"Your points: "<<player_points<<"\n";
            cout<<"Do you want to draw a card?"<<"\n";
            cin>>a;

            if(a=="yes" or a=="yeS" or a=="yEs" or a=="yES" or a=="Yes" or a=="YeS" or a=="YEs" or a=="YES"){
                player_points+=deck[card_index];
                card_index++;
                if(player_points>21 and deck[card_index-1]==11){
                    player_points-=10;
                    cout<<"The Ace saved you, taking the value of 1 instead of 11! (this is a rule in blackjack)"<<"\n";
                    this_thread::sleep_for(chrono::milliseconds(3000));
                }
                
                if(player_points>21){
                    cout<<"You lost..."<<"\n";
                    cout<<"You exceeded 21 points."<<"\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    cout<<"300 USD deducted from your wallet."<<"\n";
                    wallet-=300;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    cout<<"Your wallet balance: "<<wallet<<" USD"<<"\n";
                    player_lost=true;
                    break;
                }

                if(player_points==21){
                    cout<<"CONGRATULATIONS!!! You won!"<<"\n"; 
                    this_thread::sleep_for(chrono::milliseconds(3000));
                    wallet+=300;
                    cout<<"Added 300 USD"<<"\n";
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    cout<<"Your wallet balance: "<<wallet<<" USD"<<"\n";
                    player_won=true;
                    break;
                }

            }

            if(a=="no" or a=="nO" or a=="No" or a=="NO"){
                cout<<"You don't want to play? Alright... "<<"\n";
                this_thread::sleep_for(chrono::milliseconds(3300));
                break;
            }

        }

        cout<<"Your score is: "<<player_points<<"\n";

        if(player_lost==false and player_won==false){
            
            cout<<"--- DEALER'S TURN!!! ---"<<"\n";
            this_thread::sleep_for(chrono::milliseconds(7000));
            int dealer_points=0;

            while (dealer_points<17) {
                dealer_points+=deck[card_index];
                card_index++;
                if(dealer_points>21 and deck[card_index-1]==11){
                    dealer_points-=10;
                }
            }

            cout<<"Final results..."<<"\n";
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout<<"Player: "<<player_points<<"   Dealer: "<<dealer_points<<"\n";
            this_thread::sleep_for(chrono::milliseconds(3000));

            if(dealer_points>21){
                cout<<"Dealer exceeded 21 points. You win! (unfortunately...)"<<"\n";
                wallet+=300;
                cout<<"Added 300 USD"<<"\n";
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout<<"Your wallet balance: "<<wallet<<" USD"<<"\n";
                this_thread::sleep_for(chrono::milliseconds(3000));
            }

            else if(player_points>dealer_points){
                cout<<"You win! You have more points than the dealer."<<"\n";
                wallet+=300;
                this_thread::sleep_for(chrono::milliseconds(3000));
                cout<<"Added 300 USD"<<"\n";
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout<<"Your wallet balance: "<<wallet<<" USD"<<"\n";
                this_thread::sleep_for(chrono::milliseconds(3000));
            }

            else if(dealer_points>player_points){
                cout<<"You lose! Maybe you'll finally learn that the house always wins..."<<"\n";
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout<<"300 USD deducted from your wallet."<<"\n";
                wallet-=300;
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout<<"Your wallet balance: "<<wallet<<" USD"<<"\n";
                this_thread::sleep_for(chrono::milliseconds(3000));
            }

            else{
                cout<<"Draw! Chips returned (unfortunately...)"<<"\n";
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout<<"Your wallet balance: "<<wallet<<" USD"<<"\n";
                this_thread::sleep_for(chrono::milliseconds(3000));
            }

        }

        if(wallet<=0){
            cout<<"You lost all your money. You can't play anymore."<<"\n";
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout<<"The house always wins!"<<"\n";
            this_thread::sleep_for(chrono::milliseconds(6000));
            break;
        }

        cout<<"Do you want to play again?"<<"\n";
        string b;
        cin>>b;
        this_thread::sleep_for(chrono::milliseconds(3000));

        if(b=="yes" or b=="yeS" or b=="yEs" or b=="yES" or b=="Yes" or b=="YeS" or b=="YEs" or b=="YES"){
            if(wallet>0){
                continue;
            }         
        }

        else if(b=="no" or b=="nO" or b=="No" or b=="NO"){
            cout<<"Ok."<<" You have this much money: "<<wallet<<" USD";
            this_thread::sleep_for(chrono::milliseconds(7000));
            return 0;
        }
        
    }
}