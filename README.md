# Zombie Invasion - 2D Pixel Art Top-Down Shooter

A fast-paced 2D top-down shooter game built in **C++** with **SFML**, featuring a zombie invasion theme with wave-based gameplay.

## Features

- **Wave-based Zombie Combat** - Survive increasing waves of enemies
- **Multiple Weapons** - Various firearms with different characteristics
- **Pixel Art Graphics** - Retro 2D sprite-based visuals
- **Score System** - Track kills and progression
- **Collision Detection** - Accurate hitboxes for gameplay
- **Sound Effects & Music** - Audio feedback and immersive soundtrack

## Technologies

- **Language**: C++17
- **Graphics Library**: SFML (Simple and Fast Multimedia Library)
- **Build System**: CMake
- **Design Pattern**: Object-Oriented Programming

## Project Structure

```
ProiectPOO/
├── src/
│   ├── main.cpp           # Entry point
│   ├── Game.cpp/h         # Main game logic
│   ├── Player.cpp/h       # Player class
│   ├── Zombie.cpp/h       # Zombie class
│   ├── Weapon.cpp/h       # Weapon mechanics
│   └── Collision.cpp/h    # Collision system
├── assets/
│   ├── sprites/           # Player, zombies, bullets
│   └── sounds/            # Effects and music
├── CMakeLists.txt
└── README.md
```

## Installation

### Prerequisites
- C++17 compatible compiler (GCC, Clang, MSVC)
- SFML 2.5+ library
- CMake 3.10+

### Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
./ProiectPOO
```

## Controls

| Action | Key |
|--------|-----|
| Move | WASD / Arrow Keys |
| Shoot | Left Mouse Click |
| Pause | P |
| Quit | ESC |

## Gameplay Mechanics

- **Player**: Controllable character with limited health
- **Zombies**: Spawn in waves, increase in difficulty
- **Weapons**: Pick up weapons to change fire rate and damage
- **Score**: Earn points for each zombie eliminated
- **Game Over**: Triggered when player health reaches 0

## Contributing

Feel free to submit issues and enhancement requests!

## License

This project is part of an educational program (POO - Object-Oriented Programming).
