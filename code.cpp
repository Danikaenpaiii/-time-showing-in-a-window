#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <string>

// Function to get the current local time as a string
std::string getCurrentTime() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    char buffer[10];
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", localTime);
    return std::string(buffer);
}

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(400, 200), "SFML Clock");
    window.setFramerateLimit(1); // Update once per second

    // Load a font (make sure you have a font file like Arial.ttf in the working directory)
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        return -1; // Exit if the font is not loaded
    }

    // Create a text object to display the time
    sf::Text timeText;
    timeText.setFont(font);
    timeText.setCharacterSize(50); // Character size in pixels
    timeText.setFillColor(sf::Color::Blue);
    timeText.setStyle(sf::Text::Bold);
    timeText.setPosition(50, 60); // Position the text in the window

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update the time display
        timeText.setString(getCurrentTime());

        // Clear the window
        window.clear(sf::Color::White);

        // Draw the text
        window.draw(timeText);

        // Display the window
        window.display();
    }

    return 0;
}
