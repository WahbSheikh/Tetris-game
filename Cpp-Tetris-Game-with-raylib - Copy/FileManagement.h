#ifndef __FILE_MANAGEMENT__
#define __FILE_MANAGEMENT__

#include "LinkedList.h"
#include <fstream>
#include <string>

class FileManagement {
public:
    // Save high scores to a file
   static void saveHighScores(LinkedList& list) {
        std::ofstream file("highscores.txt");
        if (!file) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }

        for (LinkedList::Node* temp = list.getHead(); temp != nullptr; temp = temp->next) {
            file << temp->name << " " << temp->score << "\n";
        }

        file.close();
    }

    static void loadHighScores(LinkedList& list) {
        std::ifstream file("highscores.txt");
        if (!file) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }

        std::string name;
        int score;
        while (file >> name >> score) {
            list.addNode(name, score);
        }

        file.close();
    }
    // Reset high scores
    static void resetHighScores() {
        std::ofstream outFile("highscores.txt", std::ios::trunc); // Clear the file
        outFile.close();
    }
};

#endif
