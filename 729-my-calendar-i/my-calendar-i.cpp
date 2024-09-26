class MyCalendar {
    vector<pair<int, int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (int i = 0; i < bookings.size(); i++) {
            int booked_start = bookings[i].first;
            int booked_end = bookings[i].second;
            
            if (start < booked_end && booked_start < end) {
                return false;
            }
        }
        
        bookings.push_back({start, end});
        return true; 
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */