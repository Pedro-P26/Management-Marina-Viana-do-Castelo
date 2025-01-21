# Marina Management of Viana do Castelo

## Project Description

This project was developed as part of the Computer Engineering course for the subject of Algorithms and Data Structures. The goal is to create a system for the **management of the Marina of Viana do Castelo**, enabling the registration, consultation, and removal of boats, as well as functionalities related to stays and pricing.

## Features

1. **Boat Registration**: Allows adding a new boat to the marina, storing data such as registration number, owner, captain, country of origin, and entry and exit dates.
2. **Boat Listing**: Displays detailed information about all registered boats.
3. **Filtering by Dock Type**: Lists boats based on the type of dock they are moored in.
4. **Query by Exit Date**: Shows boats with the same exit date.
5. **Stay Extension**: Changes the exit date of an already registered boat.
6. **Price Calculation**: Calculates the total cost of a boat’s stay based on the type of dock and duration.
7. **Boat Removal**: Removes boats from the list after their stay ends.
8. **Discount for Long Stays**: Applies a 10% discount for stays longer than 30 days.

## Code Structure

The project is centered around a structure called `struct embarcacao`, which stores all the necessary details about each boat. The main functions of the system include:

- **`registrar_embarcacao()`**: Registers a new boat.
- **`dados()`**: Collects information from the user about the boat.
- **`imprimeEMBAS()`**: Displays information about all registered boats.
- **`Menu()`**: Displays the main menu and captures the user’s choice.
- **`remover_emba()`**: Removes a boat by its index.
- **`listar_t_c()`**: Lists boats by dock type.
- **`embarcacao_saida_mesmo_dia()`**: Lists boats with the same exit date.
- **`prolongar_estadia()`**: Updates the exit date of a boat.

## How to Use

1. Compile the code using a C compiler, such as `gcc`:
   ```bash
   gcc -o marina marina.c
