# Minishell

## Overview

Minishell is a minimalistic yet powerful shell designed to provide an intuitive and efficient command-line interface. The project is crafted in C, emphasizing simplicity and performance while incorporating creative features that enhance the user experience.

## Key Features

- **Custom Command Parsing**: The lexer and parser components have been meticulously designed to handle a variety of command inputs, providing robust error handling and feedback.
- **Built-in Commands**: Includes a set of built-in commands that replicate the functionality of common shell commands, ensuring users have access to essential tools directly within Minishell.
- **Pipeline and Redirection**: Support for command pipelines and I/O redirection allows users to chain commands and manage input/output streams seamlessly.
- **Signal Handling**: Minishell gracefully handles signals, ensuring that processes can be managed effectively without disrupting the user experience.

## Creative Aspects

- **User-Centric Design**: Every aspect of Minishell is tailored to enhance usability. From the intuitive command syntax to the responsive error messages, the user experience is at the forefront.
- **Modular Code Structure**: The project is organized into well-defined modules, making it easy to extend and maintain. This modularity also encourages contributions and experimentation.
- **Educational Value**: Minishell serves as an excellent learning tool for those interested in system programming and shell development. The codebase is well-documented, providing insights into the inner workings of a shell. Also, this project was built using libft as a foundational library, which adds an extra layer of challenge compared to relying on native C library functions. By using libft, we worked within a custom, limited set of functions, requiring careful adaptation and creative problem-solving to implement features typically handled by standard C libraries. You can explore the full libft repository to understand the foundational tools we used to build minishell: [Libft repository](https://github.com/Gillian-Delvigne/libft).
- **Aesthetic Touches**: While functionality is paramount, Minishell also pays attention to aesthetics. The command prompt and output are designed to be visually appealing, making the user interaction pleasant.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Make

### Installation

Clone the repository and compile the source code using Make:

```sh
git clone https://github.com/Gillian-Delvigne/minishell.git
cd minishell
make
```

### Usage

Run the shell:

```sh
./minishell
```

Start experimenting with commands and explore the built-in functionalities.

