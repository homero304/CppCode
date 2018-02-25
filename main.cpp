//
//  main.cpp
//  Ejercicios
//
//  Created by Homero Marin on 2/24/18.
//  Copyright © 2018 Homero Marin. All rights reserved.
//

#include <iostream>
#include "imagen.cpp"
#include "lista.cpp"
#include "TicTacToe3D.cpp"

void codigoImagen() {
    int screenWidth, screenHeight, imageWidth, imageHeight;
    std::cout << "Please provide imageWidth imageHeight screenWidth screenHeight, in that order: ";
    std::cin >> imageWidth;
    std::cin >> imageHeight;
    std::cin >> screenWidth;
    std::cin >> screenHeight;
    ImageSolution solve(Size(imageWidth, imageHeight), Size(screenWidth, screenHeight));
    Size solution = solve.maxSizeWithinScreen();
    std::cout << solution.width << " " << solution.height << std::endl;
}

void codigoLista() {
    std::cout << "Running with hardcoded code!" << std::endl;
    List list;
    list.add("hola");
    list.add("como");
    list.add("estas");
    list.add("?");
    list.print();
    std::cout << std::endl;
    int f = list.find("como");
    std::cout << f << std::endl;
    list.remove(f);
    list.print();
    std::cout << std::endl;
}

void codigoGato() {
    TicTacToe3D board;
    board.howToPlay();
    char currentPlayer = 'X';
    while (!board.isThereAwinner() && !board.isFull() && !board.isTheGameOver()) {
        std::cout << "Player " << currentPlayer << std::endl;
        std::cout << "Select coordinates: ";
        board.askPlayerToPlay(currentPlayer);
        board.printBoard();
        currentPlayer = (currentPlayer == 'X') ? 'O': 'X';
    }
    if (board.isThereAwinner()) {
        std::cout << "Congratulations " << board.getWinner() << ", you won!" << std::endl;
    }
    else {
        std::cout << "No winner, Game over!" << std::endl;
    }
}


int main(int argc, const char * argv[]) {
    char c = ' ';
    // insert code here...
    while (true) {
        std::cout << "Please select a code to run." << std::endl;
        std::cout << "a - image" << std::endl;
        std::cout << "b - linked list" << std::endl;
        std::cout << "c - Tic tac toe" << std::endl;
        std::cout << "q - to quit" << std::endl;
        std::cin >> c;
        if (c == 'q') break;
        switch(c) {
            case 'a':
                std::cout << "Image code running..." << std::endl;
                codigoImagen();
                break;
            case 'b':
                std::cout << "Linked list code running..." << std::endl;
                codigoLista();
                break;
            case 'c':
                std::cout << "Tic tac toe code running..." << std::endl;
                codigoGato();
                break;
            default:
                break;
        }
        std::cout << "Press n followed by Enter." << std::endl;
        std::cin >> c;
    }
    return 0;
}
