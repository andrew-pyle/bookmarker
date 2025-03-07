/* Bookmarker — Module 1 Assignment (Warm up lab?)

Description:

A looping CLI which will add Bookmarks to an in-memory data store

Design:
Each Bookmark contains three fields
  1. URL
  2. Notes
  3. Date Created

The Data store will be two parallel vectors
  1. vector<string> urls
  2. vector<string> notes

Curriculum Connection:
None
*/

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    vector<string> urls;
    vector<string> notes;

    string url_input;
    string notes_input;
    char add_another = 'Y';

    while (tolower(add_another) != 'n')
    {
        // Accept input
        cout << "  URL> ";
        cin >> url_input;
        cout << "Notes> ";
        cin >> notes_input;

        urls.push_back(url_input);
        notes.push_back(notes_input);

        // Add another?
        cout << "Add another? [Yn] ";
        cin >> add_another;
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