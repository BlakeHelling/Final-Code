#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string createPlayer(int goals, int assist, int takeaway, int pass) {
    int points = 0;
    points += goals * 100;
    points += assist * 50;
    points += takeaway * 20;
    points += pass;
    string points2 = to_string(points);
    return points2;
}
int main() {
    int goals, assist, takeaway, pass, x = 0;
    string Players[100][2];
    string ans, name;
    cout << "Welcome to Soccer MVP Calculator" << endl;
    while (true){
        cout << "Would you like to enter a Player: (Yes or No)" << endl;
        cin >> ans;
        if (ans == "Yes"){
            cout << "What is the players name: " << endl;
            cin >> Players[x][0];
            cout << "How many goal did they score: " << endl;
            cin >> goals;
            cout << "How many assists did they have: " << endl;
            cin >> assist;
            cout << "How many takeaways did they have: " << endl;
            cin >> takeaway;
            cout << "How many passes did they have: " << endl;
            cin >> pass;
            Players[x][1] = createPlayer(goals, assist, takeaway, pass);
            x += 1;
        }
        else if (ans == "No"){
            break;
        }
        else {
            cout << "Please enter Yes or No." << endl;
        }
    }
    stringstream container(Players[0][1]);
    int g = 0;
    container >> g;
    string MVP2 = Players[0][0];
    int MVP = g;
    if(x > 0){
        for (int y = 1; y <= x; y++) {
            stringstream container2(Players[y][1]);
            int h = 0;
            container2 >> h;
            if (h > MVP) {
                MVP = h;
                MVP2 = Players[y][0];
            }
        }
    }
    cout << "The MVP is " << MVP2 << endl;
    return 0;
}
