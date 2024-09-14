# treee

This project is a simple command-line utility that generates a visual representation of a directory structure, similar to the `tree` command in Unix-based systems. It traverses a given directory path and prints the names of files and directories in a tree-like format.

## Usage

To use the program clone the repo, then `cd` into the project directory. Compile and run it from the command line:

```bash
make
./treee <path>
```

### Command-Line Arguments:

- `<path>`: The path of the directory to traverse.

- `--help` or `-h`: Displays usage instructions.

### Example:

```bash
$ ./build/bin/treee .
./
├── src/
│   └── main.c
│   └── utils.c
├── include/
│   └── utils.h
├── build/
│   ├── obj/
│   │   └── utils.o
│   │   └── main.o
│   ├── bin/
│   │   └── treee
├── .vscode/
│   └── settings.json
└── Makefile
└── .gitignore
└── README.md
```

## License

This project is open-source and available under the MIT License.
