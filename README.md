Sure! Here's the documentation for the provided code and the libraries used:

---

## Pong Game Documentation

### Overview
This code implements a simple Pong game using the **raylib** library for graphics and input handling. The game features a player-controlled paddle, a CPU-controlled paddle, and a ball that bounces around the screen. The objective is to score points by getting the ball past the opponent's paddle.

### Libraries Used
- **raylib**: A simple and easy-to-use library to enjoy videogames programming. It provides functions to manage windows, graphics, input, audio, and more.
- **iostream**: A standard C++ library for input and output stream operations.

### Global Variables
- `int playerScore`: Tracks the player's score.
- `int cpuScore`: Tracks the CPU's score.
- `Color Green, DarkGreen, LightGreen, Yellow`: Color definitions used for drawing.

### Classes

#### Ball
Represents the ball in the game.
- **Attributes**:
  - `float x, y`: Position of the ball.
  - `int speedX, speedY`: Speed of the ball in the X and Y directions.
  - `int radius`: Radius of the ball.
- **Methods**:
  - `void Draw()`: Draws the ball on the screen.
  - `void Update()`: Updates the ball's position and handles collisions with the screen edges.
  - `void ResetBall()`: Resets the ball to the center of the screen and randomizes its direction.

#### Puddle
Represents a paddle in the game.
- **Attributes**:
  - `float x, y`: Position of the paddle.
  - `float width, height`: Dimensions of the paddle.
  - `int speed`: Speed of the paddle.
- **Methods**:
  - `void Draw()`: Draws the paddle on the screen.
  - `void Update()`: Updates the paddle's position based on user input.
  - `bool CheckCollision(Ball ball)`: Checks for collisions with the ball.
  - `void LimitMovement()`: Ensures the paddle stays within the screen bounds.

#### CpuPaddle (inherits from Puddle)
Represents the CPU-controlled paddle.
- **Methods**:
  - `void Update(Ball ball)`: Updates the paddle's position based on the ball's position.

### Main Function
- Initializes the game window and sets the target FPS.
- Creates instances of `Ball`, `Puddle` (player), and `CpuPaddle`.
- Main game loop:
  - Updates the positions of the ball and paddles.
  - Checks for collisions between the ball and paddles.
  - Draws the game elements on the screen.
- Closes the game window upon exit.

### Example Usage
To compile and run this code, you need to have the **raylib** library installed. You can compile the code using a C++ compiler with the following command:
```sh
g++ -o pong_game pong_game.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./pong_game
```

---