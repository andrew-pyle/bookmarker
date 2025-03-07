/* Bookmarker — Module 2: C Strings & C++ String functions

Description:
  A looping CLI which adds Bookmarks to an in-memory data store first from an
  input string, then from CLI input.

Design:
  Each Bookmark contains three fields
    1. URL
    2. Notes

  The Data store will be two parallel vectors
    1. vector<string> urls
    2. vector<string> notes

  (New)
  The CLI will initialize its data store from an existing "database", a
    TSV-format string

Curriculum Connection:
  Using string functions to parse a string (TSV row)
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ==== DO NOT EDIT BELOW ====================

const vector<string> database = {
    "https://wikipedia.org	This one is an encyclopedia",
    "https://openstreetmap.org	This one is a map",
    "http://neverssl.com	This one doesn't use SSL",
    "https://example.com	Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec neque ligula, rhoncus vitae felis non, ultricies elementum felis. Aliquam viverra fringilla arcu, et fringilla lectus aliquam ut. Curabitur tincidunt vestibulum ante sit amet ornare. Morbi ultrices orci ligula, at luctus nisl cursus sed. Pellentesque arcu leo, condimentum in purus eget, molestie rutrum orci. Sed eleifend quis mi at sollicitudin. Integer tempor mattis mi, non mollis ex vulputate eget. Pellentesque non scelerisque nibh, non faucibus est.",
};
// ==== DO NOT EDIT ABOVE=====================

// Convert the string input into a vector<string> with two elements: URL & Notes
vector<string> parse_tsv_row(string input)
{
    // To Do
}

int main()
{
    vector<string> urls;
    vector<string> notes;

    // 1. Initialize parallel vectors
    // 2. Then Prior code to read from CLI

    return 0;
}