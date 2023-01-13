import murach_movie;
import <string>;    // this should match the murach_movie module
#include <iostream> // import directive not implemented by compiler yet
#include <vector>   // import directive not implemented by compiler yet

using namespace std;

int main() {
    cout << "The Movie List program\n\n"
        << "Enter a movie...\n\n";

    // get movies from user
    vector<Movie> movies;
    char another = 'y';
    while (tolower(another) == 'y') {
        Movie movie;

        string title;
        cout << "Title: ";
        getline(cin, title);
        movie.set_title(title);

        int year;
        cout << "Year: ";
        cin >> year;
        try {
            movie.set_year(year);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << "\n";
            cout << "Exiting program...\n\n";
            return 0;
        }

        movies.push_back(movie);

        cout << "\nEnter another movie? (y/n): ";
        cin >> another;
        cin.ignore();
        cout << endl;
    }

}
