#include <iostream>
#include <vector>
#include <stack>

class Spacecraft {
public:
    virtual void move(char command) = 0;
    virtual void turn(char command) = 0;
    virtual void rotate(char command) = 0;
    virtual void executeCommands(const std::vector<char>& commands) = 0;
    virtual void printPositionAndDirection() = 0;
};

class AbstractSpacecraft : public Spacecraft {
protected:
    int posX, posY, posZ;
    char currentDirection;
    std::stack<char> directionStack;

public:
    AbstractSpacecraft(int initialX, int initialY, int initialZ, char initialDirection)
        : posX(initialX), posY(initialY), posZ(initialZ), currentDirection(initialDirection) {}

    std::string getCurrentPosition() {
        return "(" + std::to_string(posX) + ", " + std::to_string(posY) + ", " + std::to_string(posZ) + ")";
    }

    char getCurrentDirection() {
        return currentDirection;
    }
};

class Chandrayaan3Spacecraft : public AbstractSpacecraft {
public:
    Chandrayaan3Spacecraft(int initialX, int initialY, int initialZ, char initialDirection)
        : AbstractSpacecraft(initialX, initialY, initialZ, initialDirection) {}

    void move(char command) override {
        switch (command) {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
        }
    }

    void turn(char command) override {
        switch (command) {
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
        }
    }

    void rotate(char command) override {
        switch (command) {
            case 'u':
                rotateUp();
                break;
            case 'd':
                rotateDown();
                break;
        }
    }

    void executeCommands(const std::vector<char>& commands) override {
        for (char command : commands) {
            if (command == 'f' || command == 'b') {
                move(command);
            } else if (command == 'l' || command == 'r') {
                turn(command);
            } else if (command == 'u' || command == 'd') {
                rotate(command);
            }
        }
    }

    void printPositionAndDirection() override {
        std::cout << "Final Position: " << getCurrentPosition() << std::endl;
        std::cout << "Final Direction: " << getCurrentDirection() << std::endl;
    }

private:
    void moveForward() {
        switch (currentDirection) {
            case 'N':
                posY++;
                break;
            case 'S':
                posY--;
                break;
            case 'E':
                posX++;
                break;
            case 'W':
                posX--;
                break;
            case 'U':
                posZ++;
                break;
            case 'D':
                posZ--;
                break;
        }
    }

    void moveBackward() {
        switch (currentDirection) {
            case 'N':
                posY--;
                break;
            case 'S':
                posY++;
                break;
            case 'E':
                posX--;
                break;
            case 'W':
                posX++;
                break;
            case 'U':
                posZ--;
                break;
            case 'D':
                posZ++;
                break;
        }
    }

    void turnLeft() {
        switch (currentDirection) {
            case 'N':
                currentDirection = 'W';
                directionStack.push('W');
                break;
            case 'S':
                currentDirection = 'E';
                directionStack.push('E');
                break;
            case 'E':
                currentDirection = 'N';
                directionStack.push('N');
                break;
            case 'W':
                currentDirection = 'S';
                directionStack.push('S');
                break;
            case 'U':
                while (!directionStack.empty() && (directionStack.top() != 'N' && directionStack.top() != 'S' && directionStack.top() != 'W' && directionStack.top() != 'E')) {
                    directionStack.pop();
                }
                if (!directionStack.empty()) {
                    currentDirection = directionStack.top();
                    directionStack.pop();
                }
                switch (currentDirection) {
                    case 'N':
                        currentDirection = 'W';
                        directionStack.push('W');
                        break;
                    case 'S':
                        currentDirection = 'E';
                        directionStack.push('E');
                        break;
                    case 'E':
                        currentDirection = 'N';
                        directionStack.push('N');
                        break;
                    case 'W':
                        currentDirection = 'S';
                        directionStack.push('S');
                        break;
                }
                break;
            case 'D':
                while (!directionStack.empty() && (directionStack.top() != 'N' && directionStack.top() != 'S' && directionStack.top() != 'W' && directionStack.top() != 'E')) {
                    directionStack.pop();
                }
                if (!directionStack.empty()) {
                    currentDirection = directionStack.top();
                    directionStack.pop();
                }
                switch (currentDirection) {
                    case 'N':
                        currentDirection = 'W';
                        directionStack.push('W');
                        break;
                    case 'S':
                        currentDirection = 'E';
                        directionStack.push('E');
                        break;
                    case 'E':
                        currentDirection = 'N';
                        directionStack.push('N');
                        break;
                    case 'W':
                        currentDirection = 'S';
                        directionStack.push('S');
                        break;
                }
                break;
        }
    }

    void turnRight() {
        switch (currentDirection) {
            case 'N':
                currentDirection = 'E';
                directionStack.push('E');
                break;
            case 'S':
                currentDirection = 'W';
                directionStack.push('W');
                break;
            case 'E':
                currentDirection = 'S';
                directionStack.push('S');
                break;
            case 'W':
                currentDirection = 'N';
                directionStack.push('N');
                break;
            case 'U':
                while (!directionStack.empty() && (directionStack.top() != 'N' && directionStack.top() != 'S' && directionStack.top() != 'W' && directionStack.top() != 'E')) {
                    directionStack.pop();
                }
                if (!directionStack.empty()) {
                    currentDirection = directionStack.top();
                    directionStack.pop();
                }
                switch (currentDirection) {
                    case 'N':
                        currentDirection = 'E';
                        directionStack.push('E');
                        break;
                    case 'S':
                        currentDirection = 'W';
                        directionStack.push('W');
                        break;
                    case 'E':
                        currentDirection = 'S';
                        directionStack.push('S');
                        break;
                    case 'W':
                        currentDirection = 'N';
                        directionStack.push('N');
                        break;
                }
                break;
            case 'D':
                while (!directionStack.empty() && (directionStack.top() != 'N' && directionStack.top() != 'S' && directionStack.top() != 'W' && directionStack.top() != 'E')) {
                    directionStack.pop();
                }
                if (!directionStack.empty()) {
                    currentDirection = directionStack.top();
                    directionStack.pop();
                }
                switch (currentDirection) {
                    case 'N':
                        currentDirection = 'E';
                        directionStack.push('E');
                        break;
                    case 'S':
                        currentDirection = 'W';
                        directionStack.push('W');
                        break;
                    case 'E':
                        currentDirection = 'S';
                        directionStack.push('S');
                        break;
                    case 'W':
                        currentDirection = 'N';
                        directionStack.push('N');
                        break;
                }
                break;
        }
    }

    void rotateUp() {
        if (currentDirection != 'U') {
            currentDirection = 'U';
        }
    }

    void rotateDown() {
        if (currentDirection != 'D') {
            currentDirection = 'D';
        }
    }
};

int main() {
    std::cout << "Welcome to Chandrayaan 3 Lunar Craft Control!" << std::endl;

    int initialX, initialY, initialZ;
    char initialDirection;

    std::cout << "Enter the initial X position: ";
    std::cin >> initialX;
    std::cout << "Enter the initial Y position: ";
    std::cin >> initialY;
    std::cout << "Enter the initial Z position: ";
    std::cin >> initialZ;

    std::cout << "Enter the initial direction (N, S, E, W, U, D): ";
    std::cin >> initialDirection;

    Spacecraft* chandrayaan3 = new Chandrayaan3Spacecraft(initialX, initialY, initialZ, initialDirection);

    std::cout << "Enter the commands (e.g., f, r, u, b, l) as a single string: ";
    std::string inputCommands;
    std::cin >> inputCommands;

    std::vector<char> commands(inputCommands.begin(), inputCommands.end());

    chandrayaan3->executeCommands(commands);

    chandrayaan3->printPositionAndDirection();

    delete chandrayaan3;

    return 0;
}
