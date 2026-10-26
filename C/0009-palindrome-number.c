bool isPalindrome(int x) {
    if (x < 0) return false;
    
    char buffer[20];
    sprintf(buffer, "%d", x); 
    int length = strlen(buffer);
    
    for(int i = 0; i < length; i++){
        if(buffer[i] != buffer[length - 1 - i]){
            return false;
        }
    }
    return true;
}