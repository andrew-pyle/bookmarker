#include <regex>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>

using namespace std;

const string APP_NAME = "Bookmark";
const string DATABASE_FILENAME = "bookmarks.tsv";

// Appends list of Bookmarks to file
void append_to_file(const string &filename, string bookmark)
{
    ofstream fileFS;

    fileFS.open(filename, ios::app);

    if (!fileFS.is_open())
    {
        throw "Could not open database file at '" + filename + "'";
    }

    fileFS << bookmark;

    fileFS.close();
}
void append_to_file(const string &filename, vector<string> bookmarks)
{
    ofstream fileFS;

    fileFS.open(filename, ios::app);

    if (!fileFS.is_open())
    {
        throw "Could not open database file at '" + filename + "'";
    }

    for (auto b : bookmarks)
    {
        fileFS << b;
    }

    fileFS.close();
}

void save_bookmark(const vector<string> &bookmark)
{
    ostringstream tsv_row;
    for (auto field : bookmark)
    {
        tsv_row << field << '\t';
    }
    tsv_row << '\n';

    string tsv_row_str = tsv_row.str();
    append_to_file(DATABASE_FILENAME, tsv_row_str);
}
void save_bookmark(const vector<vector<string>> &bookmarks)
{
    vector<string> tsv_rows;
    for (auto bookmark : bookmarks)
    {
        ostringstream tsv_row;
        for (auto field : bookmark)
        {
            tsv_row << field << '\t';
        }
        tsv_row << '\n';

        tsv_rows.push_back(tsv_row.str());
    }
    append_to_file(DATABASE_FILENAME, tsv_rows);
}

string read_file(string filename)
{
    ifstream fileFS;
    string line;
    string out;

    fileFS.open(filename);

    if (!fileFS.is_open())
    {
        throw "Error encountered while opening file.";
    }

    while (getline(fileFS, line))
    {
        out += line;
    }

    if (!fileFS.eof())
    {
        throw "Error encountered while reading file.";
    }

    fileFS.close();
    return out;
}

vector<string> create_bookmark_from_url()
{
    vector<string> out;

    // URL
    string url;
    cout << "URL ↴" << endl;
    cin >> url;

    // Notes
    string notes;
    cout << "Notes ↴" << endl;
    cin.ignore(); // skip hanging newline from `cin` above.
    getline(cin, notes);

    // Date Added
    ostringstream epoch_timestamp;
    epoch_timestamp << std::time(nullptr);

    // Out
    out.push_back(epoch_timestamp.str());
    out.push_back(url);
    out.push_back(notes);

    return out;
}

vector<vector<string>> parse_netscape_bookmark_file_contents(string s)
{
    vector<vector<string>> out;
    smatch m;

    // Notice the `/` in front of the `"` in the HTML attributes. This is necessary,
    // but it is not known why, at this time. The HTML file does not have the `/`
    // character (like normal HTML), but when the file is read, the resulting
    // std::string does appear to have the `/`. Maybe it isescaped automatically?
    const regex e{R"~(<DT><A HREF=\"(\S+?)\" ADD_DATE=\"(\S+?)\".+?>(.+?)<\/A>)~"};

    while (regex_search(s, m, e))
    {

        string url = m[1];
        string date = m[2];
        string notes = m[3];
        vector<string> bookmark;

        // cout << url << " " << date << " " << notes << endl;
        bookmark.push_back(date);
        bookmark.push_back(url);
        bookmark.push_back(notes);
        out.push_back(bookmark);

        s = m.suffix().str();
    }

    return out;
}

vector<vector<string>> import_netscape_bookmark_file()
{
    string filename;
    cout << "Bookmark File ↴" << endl;
    cin >> filename;
    string s = read_file(filename);
    auto data = parse_netscape_bookmark_file_contents(s);
    return data;

    // for (auto d : data)
    // {
    //     cout << get<0>(d) << " " << get<1>(d) << " " << get<2>(d) << endl;
    // }
}

enum MenuItems
{
    ADD_BY_URL,
    IMPORT_NETSCAPE_FILE,
};

MenuItems present_menu()
{
    char user_input;

    cout << APP_NAME << " — Menu" << endl;
    cout << "1) Add Bookmark by URL" << endl;
    cout << "2) Import Netscape Bookmark File" << endl;
    cin >> user_input;
    // user_input = '1';

    switch (user_input)
    {
    case '1':
        return MenuItems::ADD_BY_URL;
    case '2':
        return MenuItems::IMPORT_NETSCAPE_FILE;
    default:
        cout << "Invalid Choice. Choose again." << endl;
        return present_menu();
    }
}

int main()
{
    // Present Menu
    MenuItems choice = present_menu();

    // Do Menu Option
    switch (choice)
    {
    case MenuItems::ADD_BY_URL:
    {
        auto bookmark = create_bookmark_from_url();
        save_bookmark(bookmark);

        cout << "Added 1 bookmark" << endl;
        break;
    }
    case MenuItems::IMPORT_NETSCAPE_FILE:
    {
        auto data = import_netscape_bookmark_file();
        save_bookmark(data);

        cout << "Added " << data.size() << " bookmark(s)" << endl;
        break;
    }
    }
}
