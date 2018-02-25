//
//  TicTacToe3D.cpp
//  Ejercicios
//
//  Created by Homero Marin on 2/24/18.
//  Copyright © 2018 Homero Marin. All rights reserved.
//

#include <iostream>

class TicTacToe3D {
private:
    char empty;
    char board[27];
    char winner;
    bool isGameOver = false;
    void initBoard() {
        for (int i=0;i<27;i++) {
            board[i]=empty;
        }
    }
    int getCoord(int level, int pos) {
        return (level - 1) * 9 + pos - 1;
    }
    bool isThereAwinnerAtLevel(int level) {
        bool topRow = board[getCoord(level, 1)] == board[getCoord(level, 2)] && board[getCoord(level, 2)] == board[getCoord(level, 3)];
        bool leftColumn = board[getCoord(level, 1)] == board[getCoord(level, 4)] && board[getCoord(level, 4)] == board[getCoord(level, 7)];
        bool rightColumn = board[getCoord(level, 3)] == board[getCoord(level, 6)] && board[getCoord(level, 6)] == board[getCoord(level, 9)];
        bool bottomRow = board[getCoord(level, 7)] == board[getCoord(level, 8)] && board[getCoord(level, 8)] == board[getCoord(level, 9)];
        bool middleRow = board[getCoord(level, 4)] == board[getCoord(level, 5)] && board[getCoord(level, 5)] == board[getCoord(level, 6)];
        bool middleColumn = board[getCoord(level, 2)] == board[getCoord(level, 5)] && board[getCoord(level, 5)] == board[getCoord(level, 8)];
        bool leftDiagonal = board[getCoord(level, 1)] == board[getCoord(level, 5)] && board[getCoord(level, 5)] == board[getCoord(level, 9)];
        bool rightDiagonal = board[getCoord(level, 3)] == board[getCoord(level, 5)] && board[getCoord(level, 5)] == board[getCoord(level, 7)];
        bool haveAwinner = false;
        if (!isPosEmpty(level, 1) && (topRow || leftColumn)) {
            winner = board[getCoord(level,1)];
            haveAwinner = true;
        }
        else if (!isPosEmpty(level, 5) && (middleRow || middleColumn || leftDiagonal || rightDiagonal)) {
            winner = board[getCoord(level,5)];
            haveAwinner = true;
        }
        else if (!isPosEmpty(level, 9) && (rightColumn || bottomRow)) {
            winner = board[getCoord(level,9)];
            haveAwinner = true;
        }
        return haveAwinner;
    }
    bool isThereAwinnerBetweenLevels() {
        bool posOne = board[getCoord(1, 1)] == board[getCoord(2, 1)] && board[getCoord(2, 1)] == board[getCoord(3, 1)];
        bool posTwo = board[getCoord(1, 2)] == board[getCoord(2, 2)] && board[getCoord(2, 2)] == board[getCoord(3, 2)];
        bool posThree = board[getCoord(1, 3)] == board[getCoord(2, 3)] && board[getCoord(2, 3)] == board[getCoord(3, 3)];
        bool posFour = board[getCoord(1, 4)] == board[getCoord(2, 4)] && board[getCoord(2, 4)] == board[getCoord(3, 4)];
        bool posFive = board[getCoord(1, 5)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 5)];
        bool posSix = board[getCoord(1, 6)] == board[getCoord(2, 6)] && board[getCoord(2, 6)] == board[getCoord(3, 6)];
        bool posSeven = board[getCoord(1, 7)] == board[getCoord(2, 7)] && board[getCoord(2, 7)] == board[getCoord(3, 7)];
        bool posEight = board[getCoord(1, 8)] == board[getCoord(2, 8)] && board[getCoord(2, 8)] == board[getCoord(3, 8)];
        bool posNine = board[getCoord(1, 9)] == board[getCoord(2, 9)] && board[getCoord(2, 9)] == board[getCoord(3, 9)];
        
        bool fstTopDiagonal = board[getCoord(1, 1)] == board[getCoord(2, 2)] && board[getCoord(2, 2)] == board[getCoord(3, 3)];
        bool secTopDiagonal = board[getCoord(1, 3)] == board[getCoord(2, 2)] && board[getCoord(2, 2)] == board[getCoord(3, 1)];
        
        bool fstLeftDiagonal = board[getCoord(1, 1)] == board[getCoord(2, 4)] && board[getCoord(2, 4)] == board[getCoord(3, 7)];
        bool secLeftDiagonal = board[getCoord(1, 7)] == board[getCoord(2, 4)] && board[getCoord(2, 4)] == board[getCoord(3, 1)];
        
        bool fstRightDiagonal = board[getCoord(1, 3)] == board[getCoord(2, 6)] && board[getCoord(2, 6)] == board[getCoord(3, 9)];
        bool secRightDiagonal = board[getCoord(1, 9)] == board[getCoord(2, 6)] && board[getCoord(2, 6)] == board[getCoord(3, 3)];
        
        bool fstBottomDiagonal = board[getCoord(1, 7)] == board[getCoord(2, 8)] && board[getCoord(2, 8)] == board[getCoord(3, 9)];
        bool secBottomDiagonal = board[getCoord(1, 9)] == board[getCoord(2, 8)] && board[getCoord(2, 8)] == board[getCoord(3, 7)];
        
        bool fstMiddleDiagonal = board[getCoord(1, 1)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 9)];
        bool secMiddleDiagonal = board[getCoord(1, 9)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 1)];
        bool thirdMiddleDiagonal = board[getCoord(1, 3)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 7)];
        bool fourthMiddleDiagonal = board[getCoord(1, 7)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 3)];
        bool fifMiddleDiagonal = board[getCoord(1, 4)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 6)];
        bool sixMiddleDiagonal = board[getCoord(1, 6)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 4)];
        bool sevenMiddleDiagonal = board[getCoord(1, 2)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 8)];
        bool eightMiddleDiagonal = board[getCoord(1, 8)] == board[getCoord(2, 5)] && board[getCoord(2, 5)] == board[getCoord(3, 2)];
        bool haveAwinner = false;
        if (!isPosEmpty(1, 1) && posOne) {
            winner = board[getCoord(1, 1)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 2) && posTwo) {
            winner = board[getCoord(1, 2)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 3) && posThree) {
            winner = board[getCoord(1, 3)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 4) && posFour) {
            winner = board[getCoord(1, 4)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 5) && posFive) {
            winner = board[getCoord(1, 5)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 6) && posSix) {
            winner = board[getCoord(1, 6)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 7) && posSeven) {
            winner = board[getCoord(1, 7)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 8) && posEight) {
            winner = board[getCoord(1, 8)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(1, 9) && posNine) {
            winner = board[getCoord(1, 9)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(2, 2) && (fstTopDiagonal || secTopDiagonal)) {
            winner = board[getCoord(2, 2)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(2, 4) && (fstLeftDiagonal || secLeftDiagonal)) {
            winner = board[getCoord(2, 4)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(2, 6) && (fstRightDiagonal || secRightDiagonal)) {
            winner = board[getCoord(2, 6)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(2, 8) && (fstBottomDiagonal || secBottomDiagonal)) {
            winner = board[getCoord(2, 8)];
            haveAwinner = true;
        }
        else if(!isPosEmpty(2, 5) && (fstMiddleDiagonal || secMiddleDiagonal || thirdMiddleDiagonal || fourthMiddleDiagonal || fifMiddleDiagonal || sixMiddleDiagonal || sevenMiddleDiagonal || eightMiddleDiagonal)) {
            winner = board[getCoord(2, 5)];
            haveAwinner = true;
        }
        
        return haveAwinner;
    }
    bool playValidation(int level, int pos) {
        return level > 0 && level < 4 && pos > 0 && pos < 10;
    }
    bool shouldExit(int level, int pos) {
        return level == 0 && pos == 0;
    }
public:
    TicTacToe3D() {
        empty = ' ';
        initBoard();
    }
    bool isPosEmpty(int level, int pos) {
        return board[getCoord(level, pos)] == empty;
    }
    bool isFull() {
        bool isFull = true;
        for (int i=0;i<27;i++) {
            isFull = isFull && board[i] != empty;
        }
        return isFull;
    }
    bool isTheGameOver() {
        return isGameOver;
    }
    bool isThereAwinner() {
        return isThereAwinnerAtLevel(1) || isThereAwinnerAtLevel(2) || isThereAwinnerAtLevel(3) || isThereAwinnerBetweenLevels();
    }
    void play(char player, int level, int position) {
        if (shouldExit(level, position)) {
            isGameOver = true;
            return;
        }
        if (board[getCoord(level, position)] == empty)
            board[getCoord(level, position)] = player;
        else {
            std::cout << "Space is already occupied, please select another space" << std::endl;
            askPlayerToPlay(player);
        }
    }
    void askPlayerToPlay(char player) {
        int level = -1, pos = -1;
        while (!playValidation(level, pos) && !shouldExit(level, pos)) {
            std::cin >> level;
            std::cin >> pos;
            if (!playValidation(level, pos)) {
                std::cout << "Please provide a valid 3D level and a valid position" << std::endl;
            }
        }
        play(player, level, pos);
    }
    char getWinner() {
        return winner;
    }
    void howToPlay() {
        std::cout << "Please enter 2 digits: a b" << std::endl;
        std::cout << "where 'a' is (1-3) and 'b' is (1-9)" << std::endl;
        std::cout << "------------" << std::endl;
        std::cout << "'a' represents the board number from the 3D space where to select a position" << std::endl;
        std::cout << "-board 1-" << std::endl;
        std::cout << "-board 2-" << std::endl;
        std::cout << "-board 3-" << std::endl;
        std::cout << "------------" << std::endl;
        std::cout << "and 'b' represents which of the 9 positions to select." << std::endl;
        
        for (int i=1; i<=9; i++) {
            std::cout << "| " << i << " ";
            if (i%3==0 && i != 0) {
                std::cout << "|" << std::endl;
            }
        }
        std::cout << "if you want to end the game, enter 0 0" << std::endl;
    }
    void printBoard() {
        for (int i=1; i<=9; i++) {
            std::cout << "| " << board[i-1] << " ";
            if (i%3==0 && i != 0) {
                std::cout << "|" << std::endl;
            }
        }
        std::cout << "------------" << std::endl;
        for (int i=10; i<=18; i++) {
            std::cout << "| " << board[i-1] << " ";
            if (i%3==0 && i != 0) {
                std::cout << "|" << std::endl;
            }
        }
        std::cout << "------------" << std::endl;
        for (int i=19; i<=27; i++) {
            std::cout << "| " << board[i-1] << " ";
            if (i%3==0 && i != 0) {
                std::cout << "|" << std::endl;
            }
        }
    }
};


