Flappy Bird – DSA Project (Queue Implementation)
Project Members

Abdullah Mahmood (CT-24024) – Leader

Abdullah (CT-24025)

Ali Shaikh (CT-24049)

Muhammad Mazan (CT-24034)

Course Information

Course: DSA (CT-159)

Department: BCIT

Section: A

Batch: 2024

1. Introduction

This project is a simple console-based version of Flappy Bird, developed to demonstrate the use of Data Structures in an easy and understandable way.

The primary DSA used in this project is the Queue, which manages the game hurdles. Since a queue follows FIFO (First In First Out), it naturally matches how hurdles appear on the screen (from right) and exit (to the left).

2. Objectives

Demonstrate the usage of the Queue data structure in a real scenario.

Understand FIFO behavior through a visual game.

Implement a simple and clean object-oriented C++ program.

Show how DSAs can be applied practically in games and animations.

3. Why Queue Data Structure?
Queue Feature	Game Usage
FIFO	Hurdles appear first and leave first
Enqueue	New hurdles added from the right side
Dequeue	Old hurdles removed when leaving left side

The natural movement pattern of hurdles makes the queue a perfect choice.

4. Working Principle of the Game

The bird stays at a fixed X-position and only moves up/down.

Hurdles move from right to left across the screen.

Each hurdle’s X-position is stored in a queue.

When hurdles shift left, the old position is removed and the updated one is added back.

If a hurdle crosses off-screen, it is removed and score increases.

The game ends if:

the bird hits a hurdle, or

the bird touches the boundary.

5. Data Structure Used
Queue (STL: queue<int>)

Operations used:

push() – add new hurdle

pop() – remove exited hurdle

front() – access next hurdle

empty() – check if queue is empty

6. Functions Used
Function	Purpose
goToXY()	Move cursor in console
addHurdle()	Add new hurdle to queue
moveHurdles()	Shift all hurdles left
drawHurdles()	Display hurdles
drawBird()	Display the bird
collisionCheck()	Detect hurdle collision
play()	Main game loop

All functions are kept simple and beginner-friendly.

7. Conclusion

This project clearly demonstrates how a Queue works in a real-time scenario. Managing hurdle movement becomes straightforward using FIFO logic. The project provides a practical understanding of how DSAs can be applied beyond theory, especially in game development.
