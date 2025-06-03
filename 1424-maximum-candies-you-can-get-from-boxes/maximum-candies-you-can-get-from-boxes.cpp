class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            unordered_set<int>& visited, unordered_set<int>& foundBoxes) {
        int candie = 0;
        // base cases
        if (visited.count(box)) {
            return 0;
        }
        if (status[box] == 0) {
            // then add it in found box bz later we can open it wit keys found
            // in future
            foundBoxes.insert(box);
            return 0;
        }

        visited.insert(box);
        int candiesCollected = candies[box];

        // now we have got the candies for the curr box
        // now explore the boxes which is inside the curr box
        for (auto& insideBox : containedBoxes[box]) {
            candiesCollected += dfs(insideBox, status, candies, keys,
                                    containedBoxes, visited, foundBoxes);
        }

        // now after above check which keys we found in curr box if we have keys
        // then check is it present in foundBox or not if yes then add candies
        // and call same for dfs
        for (auto& boxKey : keys[box]) {
            status[boxKey] = 1; // mark it open
            if (foundBoxes.count(boxKey)) {
                candiesCollected += dfs(boxKey, status, candies, keys,
                                        containedBoxes, visited, foundBoxes);
            }
        }

        return candiesCollected;
    }
    //using bfs
    int bfs(vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            unordered_set<int>& visited, unordered_set<int>& foundBoxes,vector<int>& initialBoxes) {
                int candie = 0;
        queue<int>
            q; // in this queue insert those which u have and u can open this
        for (auto& box : initialBoxes) {
            foundBoxes.insert(box);
            if (status[box] == 1) {
                q.push(box);
                visited.insert(box);
                candie += candies[box];
            }
        }

        while(!q.empty()){
            int box = q.front();
            q.pop();

            for(auto &insideBox : containedBoxes[box]){
                foundBoxes.insert(insideBox);
                if(status[insideBox] == 1 && !visited.count(insideBox)){
                    q.push(insideBox);
                    visited.insert(insideBox);
                    candie += candies[insideBox];
                }
            }
            // now we have also got the other boxes keys go for it mark it open 
            for(auto &boxKey : keys[box]){
                // mark it open
                status[boxKey] = 1;
                if(foundBoxes.count(boxKey) && !visited.count(boxKey)){
                    q.push(boxKey);
                    visited.insert(boxKey);
                    candie += candies[boxKey];
                }
            }
        }
        return candie;
    }

    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int candie = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;
        // using dfs
        // start dfs from the initialBox
        // Tc - o(n) as we are visiting each box only once and n is box
        // for (auto& box : initialBoxes) {
        //     candie += dfs(box, status, candies, keys, containedBoxes, visited,
        //                   foundBoxes);
        // }

        candie =
            bfs(status, candies, keys, containedBoxes, visited, foundBoxes,initialBoxes);

        return candie;
    }
};