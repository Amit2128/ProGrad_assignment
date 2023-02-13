#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Variables to store player names, choices, and scores
    string player1, player2, player1Choice, player2Choice;
    int player1Score = 0, player2Score = 0, highestScore = 0;
    
    // Get player names
    cout << "Enter player 1 name: ";
    cin >> player1;
    cout << "Enter player 2 name: ";
    cin >> player2;
    
    // Read the highest score from file
    ifstream scoreFile("highscore.txt");
    if (scoreFile.is_open()) {
        scoreFile >> highestScore;
        scoreFile.close();
    }
    
    // Game loop
    while (true) {
        // Get player choices
        cout << player1 << ", choose (rock/paper/scissors): ";
        cin >> player1Choice;
        cout << player2 << ", choose (rock/paper/scissors): ";
        cin >> player2Choice;
        
        // Check for draw
        if (player1Choice == player2Choice) {
            cout << "Draw!" << endl;
        } else if (player1Choice == "rock" && player2Choice == "scissors" ||
                   player1Choice == "scissors" && player2Choice == "paper" ||
                   player1Choice == "paper" && player2Choice == "rock") {
            // Player 1 wins
            cout << player1 << " wins!" << endl;
            player1Score++;
        } else {
            // Player 2 wins
            cout << player2 << " wins!" << endl;
            player2Score++;
        }
        
        // Check if a new highest score has been set
        if (player1Score > highestScore) {
            highestScore = player1Score;
        }
        if (player2Score > highestScore) {
            highestScore = player2Score;
        }
        
        // Ask if player wants to quit
        cout << "Do you want to quit? (yes/no): ";
        string quit;
        cin >> quit;
        if (quit == "yes") {
            break;
        }
    }
    
    // Store the highest score in file
    ofstream scoreFile("highscore.txt");
    if (scoreFile.is_open()) {
        scoreFile << highestScore;
        scoreFile.close();
    }
    
    // Display final scores
    cout << player1 << ": " << player1Score << endl;
    cout << player2 << ": " << player2Score << endl;
    cout << "Highest score: " << highestScore << endl;
    
    return 0;
}