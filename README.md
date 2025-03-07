# Bookmarks Project

## Benefits

Keeping track of bookmarks is hard. You must remember something about the URL. Or maybe you have a folder hierarchy to help. But it's not portable between computers, or even between browsers on the same computer.

We propose a CLI system to keep track of your bookmarks:

1. It will allow searching your bookmarks by URL and metadata that you add.
1. It will be saved in a TSV file. TSVs are easy to write manually, and you can even open it in Excel if you want. The User can control the data, and move it between computers.

## Features

1. Add Bookmarks

   - URL, Date, & Notes

2. Text file serialization

   - TSV format —

3. Search Retrieval

   - Naive, exact search in URL and in notes

## Incremental improvement

### Stages

1. [x] Module 1 — Arrays

- Design
  - Bookmark: URL, Notes
  - Bookmark is Parallel Vectors, URL & Notes `vector<string>`
- New Features
  - Read bookmark inputs from user input with `cin` (loop)
  - Output all bookmarks with `cout`
- Refactor
  - (none)
- Curriculum
  - Not related to Module 1, but the students can do this at this stage

1. [ ] Module 2 — C Strings & C++ String functions

- Design
  - Bookmark: URL, Notes
  - Bookmark is a `vector<string>`
  - Persistent data with hardcoded TSV-format string;
- New Features
  - Parse an existing "database" TSV-format string into Bookmarks
- Refactor
  - (none)
- Curriculum
  - Using string functions to parse a TSV row

1. [ ] Module 3 — Streams & Files

- Design
  - Bookmark: URL, Notes
  - Bookmark is a `vector<string>`
  - Persistent data with TSV file
- New Features
  - Load persistent data from file
  - Append new bookmark to persistent "database" TSV file
- Refactor
  - Read persistent data from file instead of hardcoded string

1. [ ] Module 4? — Structs

- Design
  - Bookmark: URL, Notes, Date Created
  - Bookmark is a `struct`
  - Bookmark Database is a `struct`
  - Persistent data with TSV file
- New Features
  - Add Date Created to Bookmark entity
- Refactor
  - Replace the Bookmark data type `vector<string>` with a `vector<Bookmark>`

1. [ ] Module 4 — Classes & Objects

- Design
  - Bookmark: URL, Notes, Date Created
  - Bookmark is a `struct`
  - Bookmark Database is a class
  - Persistent data with TSV file
- New Features
  - (none)
- Refactor
  - Refactor existing append functionality into the Bookmarks Database class
  - An `add` method to create Bookmark from user input
  - A `persist` method for file-writing

1. [ ] Module 5 — More Classes

- Design
  - Bookmark: URL, Notes, Date Created
  - Bookmark is a `struct`
  - Bookmark Database is a class
  - Persistent data with TSV file
- New Features
  - Implement `search` method on Bookmark Database
- Refactor
  - Split the program into two executables which both read the classes
    - Pull the class into the executable which adds a new bookmark
    - Create new executable which will search on the `cin`, not add a new bookmark

1. [ ] Module 6 — Structs & Pointers

- Design
  - Bookmark: URL, Notes, Date Created
  - Bookmark is a `struct`
  - Bookmark Database is a class
  - Persistent data with TSV file
  - Disallow duplicate URLs
- New Features
  - Extend `add` method to disallow duplicate URLs
  - Give a message to the user indicating that the URL already exists after `cin`
- Refactor
  - (none)

1. [ ] Extra Features

- Design
  - Bookmark: URL, Notes, Date Created
  - Bookmark is a `struct`
  - Bookmark Database is a class
  - Persistent data with TSV file
  - Import existing Browser Bookmarks
- New Features
  - Import Netscape Bookmarks file
    - Regex parser for file format provided
    - Append into persistent storage
- Refactor
  - Create a new executable to do "import" mode

---

- Design
  - Bookmark: URL, Notes, Date Created
  - Bookmark is a `struct`
  - Bookmark Database is a class
  - Persistent data with TSV file
- New Features
  - Add Tags field to Bookmark
- Refactor
  - `search` method should look at tags too.

### Ideas

- Stream formatting
- Deduplicate or prevent duplicates from being added
- Bookmark struct
- Standard Library: vector, tuple, unordered_map, unordered_set (deduplication)
- Validate URL on input
- Add tags to bookmark (better than hierarchical folders, like browsers use)
- Allow user to input file path for "database" file
- Search with stemming. See the [Porter stemmer][porter] or subset of it?
- Test-Driven Development — Provide tests for each module & improvement.

## Unused

- Import from other browsers with a Netscape Bookmarks file.
- Create a Menu with `enum`

[porter]: https://tartarus.org/martin/PorterStemmer/
