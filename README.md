# Canteen Management System

This project is a simple Canteen Management System written in C++. It allows users to manage a list of beverages and foods, save the product list to a file, and select products for purchase.

## Features

- **Product Management:** Add beverages and foods to the canteen.
- **List Products:** Display a list of available beverages and foods.
- **Select Products:** Allow users to select products for purchase.
- **Save to File:** Save the list of products to a text file.
- **Calculate Total:** Calculate the total price of selected products.

## Files

- **Product.h:** Header file containing class declarations and function prototypes.
- **Product.cpp:** Implementation of the classes and functions declared in `Product.h`.
- **main.cpp:** Main program file containing the user interface and interaction logic.

## Classes

- **Product:** Base class for all products with basic attributes and methods.
- **Beverage:** Derived class from `Product` representing beverages with additional volume attribute.
- **Food:** Derived class from `Product` representing foods with an additional type attribute.
- **Canteen:** Class for managing a collection of `Product` objects.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Makefile (optional, for easier compilation)

### Compiling the Code

To compile the code, you can use the following commands:

```sh
g++ -c Product.cpp
g++ -c main.cpp
g++ -o canteen_management Product.o main.o
