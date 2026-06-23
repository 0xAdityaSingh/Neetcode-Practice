class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int minladderLength = INT_MAX;
        unordered_set<string> wordListSet(wordList.begin(),wordList.end());
        queue<pair<string,int>> wordListQueue;
        wordListQueue.push({beginWord, 1});

        while(!wordListQueue.empty()){
            auto tempIterator = wordListQueue.front();
            wordListQueue.pop();
            string currWord = tempIterator.first;
            wordListSet.erase(currWord);
            int currLength = tempIterator.second;
            if(endWord == currWord){
                minladderLength = min(minladderLength, currLength);
            }
            for(int i = 0 ; i < currWord.size() ; i++){
                char tempChar = currWord[i];
                for(char c = 'a' ; c<='z' ; c++){
                    if(c != tempChar){
                        currWord[i]=c;
                        if(wordListSet.find(currWord)!=wordListSet.end()){
                            wordListQueue.push({currWord, currLength+1});
                        }
                        currWord[i]=tempChar;
                    }
                }

            }
        }
        if(minladderLength == INT_MAX) return 0;
        return minladderLength;
    }
};