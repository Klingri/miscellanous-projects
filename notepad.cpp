#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // To store lines of text
#include <string>   // To handle strings
#include <fstream>  // For file input/output operations (ifstream, ofstream)
#include <limits>   // For numeric_limits

void displayMenu() {
    std::cout << "\n--- Simple C++ Notepad ---" << std::endl;
    std::cout << "1. Type/Edit Text" << std::endl;
    std::cout << "2. View Current Content" << std::endl;
    std::cout << "3. Save to File" << std::endl;
    std::cout << "4. Load from File" << std::endl;
    std::cout << "5. Clear Content" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<std::string> lines; // Stores each line of text
    std::string filename;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        // Clear the input buffer after reading an integer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: { // Type/Edit Text
                std::cout << "Enter text. Type 'END' on a new line to finish editing.\n";
                std::string line;
                lines.clear(); // Clear existing content before typing new
                while (true) {
                    std::getline(std::cin, line);
                    if (line == "END") {
                        break;
                    }
                    lines.push_back(line);
                }
                std::cout << "Text entered.\n";
                break;
            }
            case 2: { // View Current Content
                if (lines.empty()) {
                    std::cout << "No content to display.\n";
                } else {
                    std::cout << "\n--- Current Content ---\n";
                    for (const std::string& l : lines) {
                        std::cout << l << std::endl;
                    }
                    std::cout << "-----------------------\n";
                }
                break;
            }
            case 3: { // Save to File
                std::cout << "Enter filename to save (e.g., my_notes.txt): ";
                std::getline(std::cin, filename);

                std::ofstream outFile(filename); // Open file for writing

                if (outFile.is_open()) {
                    for (const std::string& l : lines) {
                        outFile << l << std::endl;
                    }
                    outFile.close();
                    std::cout << "Content saved to " << filename << std::endl;
                } else {
                    std::cerr << "Error: Could not open file " << filename << " for writing.\n";
                }
                break;
            }
            case 4: { // Load from File
                std::cout << "Enter filename to load from (e.g., existing_file.txt): ";
                std::getline(std::cin, filename);

                std::ifstream inFile(filename); // Open file for reading

                if (inFile.is_open()) {
                    lines.clear(); // Clear current content before loading new
                    std::string line;
                    while (std::getline(inFile, line)) {
                        lines.push_back(line);
                    }
                    inFile.close();
                    std::cout << "Content loaded from " << filename << std::endl;
                } else {
                    std::cerr << "Error: Could not open file " << filename << " for reading. File might not exist.\n";
                }
                break;
            }
            case 5: { // Clear Content
                lines.clear();
                std::cout << "Content cleared.\n";
                break;
            }
            case 6: { // Exit
                std::cout << "Exiting Notepad. Goodbye!\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
