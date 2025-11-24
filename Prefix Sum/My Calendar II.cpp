#include <iostream>
#include <map>

using namespace std;

class MyCalendarTwo {
private:
    map<int, int> timeline;

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        // Tentatively add the booking
        timeline[startTime]++;
        timeline[endTime]--;

        int activeBookings = 0;

        // Sweep through the timeline to check overlap levels
        for(auto i = timeline.begin() ; i != timeline.end() ; i++){
            activeBookings += i->second;

            // If we find a triple booking
            if(activeBookings >= 3){
                // Revert the changes
                timeline[startTime]--;
                timeline[endTime]++;

                // Clean up map entries if they become zero to keep map size minimal
                if(timeline[startTime] == 0) timeline.erase(startTime);
                if(timeline[endTime] == 0) timeline.erase(endTime);

                return false;
            }
        }
        return true;
    }
};

int main() {
    MyCalendarTwo* obj = new MyCalendarTwo();
    
    cout << boolalpha; // Print "true"/"false" instead of 1/0

    // Test Case 1: book(10, 20) -> OK (1 booking in [10, 20))
    cout << "book(10, 20): " << obj->book(10, 20) << endl; // Expected: true

    // Test Case 2: book(50, 60) -> OK (1 booking in [50, 60))
    cout << "book(50, 60): " << obj->book(50, 60) << endl; // Expected: true

    // Test Case 3: book(10, 40) -> OK (2 bookings in [10, 20), 1 in [20, 40))
    cout << "book(10, 40): " << obj->book(10, 40) << endl; // Expected: true

    // Test Case 4: book(5, 15) -> FAIL
    // Overlaps with [10, 20) and [10, 40).
    // In range [10, 15), we would have [10,20), [10,40), and [5,15). That's 3.
    cout << "book(5, 15):  " << obj->book(5, 15) << endl;  // Expected: false

    // Test Case 5: book(5, 10) -> OK
    // No overlap with the triple booking region (starts at 10).
    cout << "book(5, 10):  " << obj->book(5, 10) << endl;  // Expected: true

    // Test Case 6: book(25, 55) -> OK
    // Overlaps with [10, 40) (count 1->2) and [50, 60) (count 1->2). Max count is 2.
    cout << "book(25, 55): " << obj->book(25, 55) << endl; // Expected: true

    delete obj;
    return 0;
}