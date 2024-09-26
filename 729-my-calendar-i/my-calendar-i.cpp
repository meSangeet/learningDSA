class MyCalendar {
    vector<pair<int, int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // Check each previously booked event for overlap
        for (int i = 0; i < bookings.size(); i++) {
            int booked_start = bookings[i].first;
            int booked_end = bookings[i].second;
            
            // Check if the current event overlaps with any previously booked event
            if (start < booked_end && booked_start < end) {
                // Overlap detected, return false (cannot book this event)
                return false;
            }
        }
        
        // If no overlap found, add the new event to the list of bookings
        bookings.push_back({start, end});
        return true;  // Successfully booked the event
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */