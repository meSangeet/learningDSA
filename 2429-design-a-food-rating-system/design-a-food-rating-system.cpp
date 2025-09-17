class FoodRatings {
private:
    // Map food to its cuisine and rating
    unordered_map<string, pair<string, int>> food_info;
    
    // Map cuisine to a set of {-rating, food} pairs
    // Using negative rating to sort in descending order
    unordered_map<string, set<pair<int, string>>> cuisine_ratings;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        // Initialize both maps
        for(int i = 0; i < n; i++) {
            // Store food's cuisine and rating
            food_info[foods[i]] = {cuisines[i], ratings[i]};
            
            // Store rating and food name under cuisine
            // Using negative rating for descending order
            cuisine_ratings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = food_info[food];
        
        // Remove old rating
        cuisine_ratings[cuisine].erase({-oldRating, food});
        
        // Add new rating
        cuisine_ratings[cuisine].insert({-newRating, food});
        
        // Update food's rating
        food_info[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        // Return food name from the first pair in the set
        // (highest rating due to negative values)
        return cuisine_ratings[cuisine].begin()->second;
    }
};
