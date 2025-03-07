/* Bookmarker — Module 1: Warm-Up Lab

Description:
    A looping CLI which will add Bookmarks to an in-memory data store

Design:
  Each Bookmark contains fields
    1. URL
    2. Notes

  The Data store will be two parallel vectors
    1. vector<string> urls
    2. vector<string> notes

Curriculum Connection:
  Prior semester covered parallel vectors, loops, and terminal IO
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  vector<string> urls;
  vector<string> notes;

  string url_input;
  string notes_input;
  string add_another = "Y";

  while (add_another != "n" && add_another != "N")
  {
    // Accept input
    cout << "  URL> ";
    getline(cin, url_input);
    cout << "Notes> ";
    getline(cin, notes_input);

    urls.push_back(url_input);
    notes.push_back(notes_input);

    // Add another?
    cout << "Add another? [Yn] ";
    getline(cin, add_another);
  }

  // Output
  cout << endl;
  cout << "Bookmarks:" << endl;
  for (int i = 0; i < urls.size(); ++i)
  {
    cout << i + 1 << ") "
         << urls.at(i) << '\n'
         << "   " << notes.at(i)
         << endl
         << endl;
  }
  return 0;
}