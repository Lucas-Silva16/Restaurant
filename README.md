# Restaurant Management Simulation in C++

![Language](https://img.shields.io/badge/Language-C++-00599C)
![Course](https://img.shields.io/badge/Course-Data_Structures_&_Algorithms-lightgrey)
![Paradigm](https://img.shields.io/badge/Paradigm-State_Management-blue)

## Introduction
This project engineers a simulation of restaurant operations and customer flow, developed entirely in **C++**. Built as part of the **Data Structures and Algorithms** course, the system rigorously manages state transitions, capacity constraints, and chronological queues to model a realistic dining environment.

---

## System Architecture & Data Structures
The simulation relies on custom data structure implementations to handle the dynamic lifecycle of restaurant patrons:
* **Entry Queues (FIFO):** Strict First-In-First-Out queue structures manage waiting lines, ensuring chronological handling of incoming customers before they are seated.
* **Spatial Allocation:** Memory and state management for two distinct physical zones: the Counter (Balcão) and the Tables (Mesas), each with strictly enforced maximum capacities.
* **Customer State Machine:** Tracking individual entities as they transition through discrete states: Waiting -> Seated at Counter -> Seated at Table -> Exited.

---

## Core Functionalities
* **Dynamic Entity Routing:** Automated logic that moves customers from the external waiting queue into available slots at the counter or directly to tables based on real-time capacity availability.
* **Capacity Enforcement:** Configurable constraints that prevent memory/spatial overflow in designated restaurant zones.
* **State Visualization:** Real-time CLI monitoring of the restaurant's operational status, detailing the exact occupancy of tables, the counter, and the length of the waiting queue.
* **Rule-Based Servicing:** Processing customer requests and state changes based on predefined operational algorithms.

---

## File Architecture
The project follows a strict modular design, separating entity definitions from simulation logic:
* `main.cpp`: The primary execution loop and entry point of the simulation.
* `restaurante.cpp` / `.h`: Core simulation engine, spatial management, and queue processing.
* `cliente.cpp` / `.h`: Entity definitions, state tracking, and attribute manipulation for individual customers.
* Auxiliary headers for localized data structure management.

---

## Current Limitations
* **State Persistence:** The `ler_ficheiro()` function, intended for initializing the simulation state from external data files, is currently pending implementation. The system currently relies on runtime data generation.

---

## Future Scope
* **File I/O Integration:** Full implementation of persistent data parsing to load complex initial scenarios and log historical session statistics.
* **Advanced Routing:** Implementation of varied table sizes and dynamic group-matching algorithms (e.g., matching a group of 4 to a 4-seater table).
* **Graphical Interface:** Abstracting the CLI backend to support a graphical representation of the physical space.

---

## Conclusion
This project demonstrates applied proficiency in C++ memory management and algorithmic design. By simulating a dynamic physical environment, it showcases the ability to use abstract data types, specifically queues and state trackers, to solve complex flow-control problems
