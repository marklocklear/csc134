export module murach_movie;
import <stdexcept>; // equivalent to #include <stdexcept>
import <string>;    // equivalent to #include <string>

using namespace std;

export class Movie {
private:
    string title;
    int year;
public:
    void set_title(string title_param) { title = title_param; }
    string get_title() const { return title; }

    void set_year(int year_param) {
        if (year_param < 1888) {
            throw invalid_argument("Year must be 1888 or later.");
        }
        year = year_param;
    }
    int get_year() const { return year; }
};
