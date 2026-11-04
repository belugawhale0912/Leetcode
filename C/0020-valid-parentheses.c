bool isLeftparan(char paran) {
    switch (paran) {
    case '{':
        return true;
    case '(':
        return true;
    case '[':
        return true;
    default:
        return false;
    }
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return true;
    // For brackets and braces, the ASCII difference is always 2
    if (close - open == 2)
        return true;
    return false;
}

bool isValid(char* s) {

    // if first bracket is not open return false
    if(!isLeftparan(s[0])){
        return false;
    }

    int len = strlen(s);

    char charStack[len];
    int cursor = 0;

    for (int i = 0; i < len; i++)
        if (isLeftparan(s[i])) {
            charStack[cursor] = s[i];
            cursor++;
        } else {
            if (cursor != 0 && isMatchingPair(charStack[cursor - 1], s[i])) {
                charStack[cursor - 1] = ' ';
                cursor--;
            } else {
                return false;
            }
        }

    // if cursor is not 0 it means there are un matched bracket
    if(cursor == 0){
        return true;
    }
    else{
        return false;
    }
}
