class MovieRentingSystem {
private:
    // Structure to store price information
    struct PriceInfo {
        int shop;
        int movie;
        int price;
        
        PriceInfo(int s, int m, int p) : shop(s), movie(m), price(p) {}
        
        // Custom comparator for sorting
        bool operator<(const PriceInfo& other) const {
            if (price != other.price) return price < other.price;
            if (shop != other.shop) return shop < other.shop;
            return movie < other.movie;
        }
    };
    
    int n; // number of shops
    
    // Map to store price for each [shop, movie] pair
    map<pair<int, int>, int> prices;
    
    // Set to store available (unrented) movies
    // Key: movie ID, Value: set of PriceInfo
    map<int, set<PriceInfo>> available;
    
    // Set to store rented movies
    set<PriceInfo> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        this->n = n;
        
        // Initialize data structures
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            
            // Store price
            prices[{shop, movie}] = price;
            
            // Add to available movies
            available[movie].insert(PriceInfo(shop, movie, price));
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        
        // Get all available shops for this movie
        if (available.find(movie) != available.end()) {
            for (const auto& info : available[movie]) {
                result.push_back(info.shop);
                if (result.size() == 5) break;
            }
        }
        
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = prices[{shop, movie}];
        
        // Remove from available
        available[movie].erase(PriceInfo(shop, movie, price));
        if (available[movie].empty()) {
            available.erase(movie);
        }
        
        // Add to rented
        rented.insert(PriceInfo(shop, movie, price));
    }
    
    void drop(int shop, int movie) {
        int price = prices[{shop, movie}];
        
        // Remove from rented
        rented.erase(PriceInfo(shop, movie, price));
        
        // Add back to available
        available[movie].insert(PriceInfo(shop, movie, price));
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        
        // Get top 5 cheapest rented movies
        for (const auto& info : rented) {
            result.push_back({info.shop, info.movie});
            if (result.size() == 5) break;
        }
        
        return result;
    }
};
