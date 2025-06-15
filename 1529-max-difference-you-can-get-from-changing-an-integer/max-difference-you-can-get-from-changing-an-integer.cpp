class Solution {
public:
    int maxDiff(int num) {
        string numStr = to_string(num);
        //to get the greatest number possible we will try to make the first number 9. 
        //but if it is already 9 then we will have to search for the first number that is not 9 
        //then we will repace all the occurences of that number by 9
        bool containCharOtherThan9 = false;
        int l = numStr.length();
        int i = 0;
        char tbr = 'a';
        if(numStr[0] == '9'){
            while(i < l){
                if(numStr[i] != '9'){
                    containCharOtherThan9 = true;
                    tbr = numStr[i];
                    break;
                }
                i++;
            }
        }

        string greatestString = numStr;
        
        if(containCharOtherThan9){
            for(int j = 0; j<l; j++){
                if(greatestString[j] == tbr){
                    greatestString[j] = '9';
                }
            }
        }else{
            if(numStr[0] != '9'){
                tbr = numStr[0];
                for(int j = 0; j<l; j++){
                    if(greatestString[j] == tbr){
                        greatestString[j] = '9';
                    }
                }
            }
        }

        //now we will check whether all the characters in the string are same or not
        bool allCharSame = true;

        for(int j = 1; j < l; j++){
            if(numStr[j] != numStr[j-1]){
                allCharSame = false;
                break;
            }
        }

        tbr = numStr[0];

        if(allCharSame){
            for(int j = 0; j<l; j++){
                numStr[j] = '1';
            }
        }else{
            //if the first character is 1 then we will try to make all the occurences of next character to be 0
            //otherwise all the occurences of the first character to be 1

            if(numStr[0] == '1'){
                bool contNonOne = false;
                for(int j = 0; j<l; j++){
                    if(!contNonOne){
                        if(numStr[j] != '1' and numStr[j] != '0'){
                            contNonOne = true;
                            tbr = numStr[j];
                            numStr[j] = '0';
                        }
                    }else{
                        if(numStr[j] == tbr){
                            numStr[j] = '0';
                        }
                    }
                }
            }else{
                for(int j = 0; j<l; j++){
                    if(numStr[j] == tbr){
                        numStr[j] = '1';
                    }
                }
            }
        }

        int minInt = stoi(numStr);
        int maxINt = stoi(greatestString);
        cout<<minInt<<" "<<maxINt<<endl;
        return maxINt - minInt;
    }
};