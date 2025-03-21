class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //okay so every dish will need some ingredients and one dish may need some other dish as ingredient
        //we may be able to create a dish or not.
        //we need to return the list of dishes that could be created. 

        //initially there are no dishes created
        map<string, vector<string>> ingreToDish; //creating this map to store ingredient to dishes in which it is required mapping
        map<string, int> numOfIng;
        int n = recipes.size();
        for(int i = 0; i<n; i++){
            numOfIng[recipes[i]] = ingredients[i].size();
            for(auto x : ingredients[i]){
                ingreToDish[x].push_back(recipes[i]);
            }
        }

        //now that mapping is ready.
        vector<string> ans;
        //now let's iterate over supplies and remove them from dishes
        while(supplies.size() > 0){
            string supply = supplies.back();
            supplies.pop_back();
            //now remove this from all the dishes that require this ingredient
            for(auto dish : ingreToDish[supply]){
                numOfIng[dish]--;
                if(numOfIng[dish] == 0){
                    supplies.push_back(dish);
                    ans.push_back(dish);
                }
            }
        }

        return ans;
    }
};