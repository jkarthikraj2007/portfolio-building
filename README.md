# portfolio-building
Here lies all my learnings in building a proper portfolio for my github account, whilst commiting my learnings in it
Project title — e.g. "Hello World in C"
One-line description — e.g. "My first C program, pushed as part of my engineering portfolio."

# Simple Line Editor

A command-line line editor written in C that lets a user create, view, and
modify a small text document one line at a time — entirely from the
terminal, no GUI.

## Team Membees

J KARTHIK RAJ (R25EJ045)
INSHA AHMED (R25EJ043)
KRITHIK D SHETTY (R25EJ056)

*(Fill in your team's names above before submitting.)*

## Features Implemented

**Core features:**
- **Insert a line** — add a new line of text at a given line number, shifting existing lines down
- **Delete a line** — remove the line at a given number, shifting the lines below it up
- **Display the document** — print all current lines with their line numbers
- **Save / load a file** — write the in-memory document to a `.txt` file, and read one back in

**Bonus features:**
- **Search** — find and report which line number(s) contain a given word
- **Line count / word count** — report simple document statistics on request

## Data Structure

The document is stored as a **dynamic (growable) array of strings**
(`char **lines`), with `count` tracking how many lines are in use and
`capacity` tracking the allocated size (doubling when full).

This was chosen because the most frequent operations — displaying the
whole document and jumping to a specific line number for insert/delete/
search — are O(1) to index into with an array. A linked list would make
insert/delete at a known position cheaper, but every operation here
already needs to *locate* a line by number first, which is O(n) in a
linked list versus instant in an array. For a small in-memory document,
the O(n) shift cost of array insert/delete is negligible, so the array
gives simpler code with no real performance downside.

## How to Compile

```bash
gcc -Wall -Wextra -o editor editor.c
```

## How to Run

```bash
./editor
```

Once running, type `help` at the `>` prompt to see the full list of
commands (also documented in `HELP.md` with usage examples).

Example session:

```
> insert 1 Hello world
Inserted at line 1.
> insert 2 This is line two
Inserted at line 2.
> display
   1: Hello world
   2: This is line two
> save mydoc.txt
Saved 2 line(s) to 'mydoc.txt'.
> quit
Goodbye.
```

## Files

| File        | Purpose                                      |
|-------------|-----------------------------------------------|
| `editor.c`  | Source code for the line editor               |
| `HELP.md`   | Command reference with usage examples         |
| `README.md` | This file                                     |
