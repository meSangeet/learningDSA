class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (auto& [overlap_start, overlap_end] : overlaps) {
            if (start < overlap_end && overlap_start < end)
                return false;
        }
        for (auto& [book_start, book_end] : bookings) {
            if (start < book_end && book_start < end)
                overlaps.push_back({max(start, book_start), min(end, book_end)});
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */