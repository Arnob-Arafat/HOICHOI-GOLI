# Hoichoi Goli

**A Code-Based University Escape Game**

A terminal-based, code-driven adventure game where you play a first-year university student trying to reach the Freshers while navigating campus. Instead of pressing arrow keys, you write and run commands to move your character, and you can build reusable functions through a restricted command system called the **Lexicon**.

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Player Movement System](#player-movement-system)
3. [Game Objective](#game-objective)
4. [Enemy Classification and AI Mechanics](#enemy-classification-and-ai-mechanics)
5. [Token System](#token-system)
6. [Special Map Elements](#special-map-elements)
7. [Obstacles and Map Generation](#obstacles-and-map-generation)
8. [Game Progression](#game-progression)
9. [Core Design Principles](#core-design-principles)
10. [Configurable Game Parameters](#configurable-game-parameters)
11. [Summary](#summary)

---

## Project Overview

The primary objective is to **collect tokens**, **avoid or survive encounters with senior students**, and **reach the exit**.

Unlike conventional movement-based games, the player writes and executes commands to control their character, and can develop reusable functions through the Lexicon.

---

## Player Movement System

The player can move using only four fundamental commands. Each command moves the character by **one grid cell**.

| Command    | Function      |
| ---------- | ------------- |
| `shamne()` | Move forward  |
| `pichone()`| Move backward |
| `upore()`  | Move upward   |
| `niche()`  | Move downward |

### Lexicon: Custom Function Creation

Players can create reusable functions from the four fundamental movement commands. Custom functions may also call other valid custom functions, and loops are allowed.

```c
void escape_route() {
    shamne();
    pichone();
    upore();
    upore();
    upore();
}
```

> **Restriction:** Custom functions must be composed only of the permitted movement commands and other valid custom functions. No alternative movement mechanism is allowed.

---

## Game Objective

The primary objective is to **reach the Freshers**. Doing so requires navigating obstacles, collecting tokens, and dealing with different categories of senior students.

Tokens act as an in-game resource and can be surrendered or lost during enemy encounters. The minimum token requirement for completing a level can be configured separately.

---

## Enemy Classification and AI Mechanics

### Second-Year Students

**Detection mechanism:** 3×3 detection grid.

- Each second-year enemy has a 3×3 detection area centered on its current position.
- When the player enters this area, the enemy detects the player and begins pursuing them.
- Their movement uses the same four directional commands available to the player.
- They can pursue the player through the grid.

**Encounter consequences:** When caught, the player chooses one of the following:

- Surrender a predetermined amount of collected tokens.
- Give a predetermined introduction (Intro).

After resolving the encounter, the player can continue the game.

### Third-Year Students

**Detection mechanism:** row/column line of sight.
**Capture mechanism:** diagonal line of sight.

- Third-year enemies detect the player when the player enters their row or column.
- Detection triggers pursuit.
- They can capture the player only when the player enters a diagonal position in their capture line, following a bishop-like pattern in chess.
- Capture is immediate when the player enters the diagonal capture range; the enemy does not need an additional movement turn.

**Encounter consequences:** When caught, the player chooses one of the following:

- Give an introduction (Intro).
- Lose half of the currently collected tokens.

After resolving the encounter, the player can continue the game.

### Fourth-Year Students

**Detection and capture mechanism:** exit protection zone.

- Fourth-year students are positioned around or within the exit area.
- Each exit has a designated protection zone, configurable as either **3×3** or **4×4**.
- They move **two grid cells per turn** in any of the four permitted directions.
- They can capture the player normally when they reach the player's position.

**Encounter consequence:**

- All collected tokens are reduced to zero.
- There is no introduction system for fourth-year encounters.
- The player continues the game after the punishment.

---

## Token System

Tokens are collectible objects distributed throughout the map. They are a resource the player must manage, and they create strategic trade-offs during enemy encounters.

| Enemy       | Consequence                                              |
| ----------- | -------------------------------------------------------- |
| Second Year | Surrender a predetermined number of tokens **OR** give an intro. |
| Third Year  | Lose half of collected tokens **OR** give an intro.      |
| Fourth Year | Lose all collected tokens. No intro option.              |

---

## Special Map Elements

### Sumon: Safe Zone

A designated safe location on the map.

- When the player enters this location, enemies cannot detect or pursue the player for a predetermined number of turns.
- It provides temporary protection and an opportunity to plan the next movement sequence.
- It rewards the player with stealth for a limited time.

### Shikder: Risk/Reward Tile

A special tile that introduces a risk/reward mechanic.

- Landing on this tile triggers a special encounter.
- If the player moves onto Shikder, the second years start hunting immediately.
- It rewards the first-year player with a substantial amount of tokens.

---

## Obstacles and Map Generation

The game environment is a grid-based map containing:

- Walls and obstacles
- Collectible tokens
- The player's starting position
- Enemy starting positions
- Safe zones
- Risk/reward tiles
- Exit points and their protected areas

Obstacles prevent movement through occupied cells. Maps can be designed with different layouts and increasing difficulty.

---

## Game Progression

1. The player starts at a designated location.
2. The player examines the map and plans a route.
3. The player writes movement commands in the terminal.
4. The player collects tokens while navigating obstacles.
5. Enemies detect and pursue the player according to their individual AI rules.
6. The player resolves encounters using the available interaction mechanics.
7. The player navigates the exit protection zone.
8. The player reaches the exit and completes the level.

---

## Core Design Principles

- **Algorithmic Thinking:** Players plan command sequences to reach destinations.
- **Function Abstraction:** The Lexicon encourages reusable functions and reduces repetitive code.
- **Resource Management:** Tokens introduce strategic decisions during gameplay.
- **Spatial Reasoning:** Players understand detection zones, line of sight, diagonal movement, and grid positioning.
- **Dynamic Enemy AI:** Different enemy classes require different strategies.
- **Risk Assessment:** Special tiles and enemy encounters create meaningful consequences.

---

## Configurable Game Parameters

- Map dimensions
- Number and placement of tokens
- Number and placement of enemies
- Second-year detection radius
- Third-year line-of-sight and diagonal capture rules
- Fourth-year exit protection zone dimensions
- Second-year token penalty
- Safe-zone protection duration
- Shikder step deduction
- Token requirement for completing a level

---

## Summary

Hoichoi Goli combines a programming-based movement system with grid exploration, resource management, enemy AI, and strategic decision-making.

The player does not control a character through conventional keyboard movement. Instead, they think algorithmically, write commands, construct reusable functions, and adapt their strategies to different enemy behaviors.

The aim is to make programming concepts an integral part of the gameplay experience rather than presenting programming as an external educational exercise.