class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i=0;
        int j=0;
        while(i<4&&j<4)
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                if(i+2<4&&s1[i+2]==s2[j])
                {
                    swap(s1[i],s1[i+2]);
                    {
                        i++;
                        j++;
                    }
                }
                else if(j+2<4&&s1[i]==s2[j+2])
                {
                    swap(s2[j],s2[j+2]);
                    i++;
                    j++;

                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};