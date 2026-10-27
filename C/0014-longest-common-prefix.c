char* longestCommonPrefix(char** strs, int strsSize) {
    
    char *prefix = strs[0];

    for(int i = 0; i < strsSize; i++){
        // strstr returns a pointer to the occurrence of prefix, 
        // or NULL if it doesn't exist anywhere in strs[i]
        while(strstr(strs[i], prefix) != strs[i]){
            
            prefix[strlen(prefix) - 1] = '\0'; // we shorten the prefix by one character

            if(!*prefix){ // if prefix is now empty (""), no common prefix exists
                return "";
            }
        }
    }
    return prefix;
}

